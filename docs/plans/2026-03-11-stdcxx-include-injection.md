# stdc++.h Include Injection Implementation Plan

> **For Claude:** REQUIRED SUB-SKILL: Use superpowers:executing-plans to implement this plan task-by-task.

**Goal:** Add a bash installer that injects the repository's `include/bits/stdc++.h` into a usable include directory, preferring system-visible locations and falling back to a user-local include path.

**Architecture:** Implement a single self-contained bash script at `scripts/install-stdcxx.sh` that validates the vendored header, probes a short list of include roots, installs into the first usable system target, and falls back to `~/.local/include` when needed. Keep behavior observable through explicit status output and validate it with a small shell smoke test plus a README usage note.

**Tech Stack:** Bash, standard Unix utilities (`mkdir`, `cp` or `install`, `mktemp`), repository docs in Markdown.

---

### Task 1: Add a shell smoke test for fallback installs

**Files:**
- Create: `scripts/test-install-stdcxx.sh`
- Test: `scripts/test-install-stdcxx.sh`

**Step 1: Write the failing test**

Create `scripts/test-install-stdcxx.sh` as a bash test that:

```bash
#!/usr/bin/env bash
set -euo pipefail

repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
tmp_home="$(mktemp -d)"
trap 'rm -rf "$tmp_home"' EXIT

HOME="$tmp_home" bash "$repo_root/scripts/install-stdcxx.sh" --force-user

test -f "$tmp_home/.local/include/bits/stdc++.h"
cmp "$repo_root/include/bits/stdc++.h" "$tmp_home/.local/include/bits/stdc++.h"
```

**Step 2: Run test to verify it fails**

Run: `bash scripts/test-install-stdcxx.sh`
Expected: FAIL because `scripts/install-stdcxx.sh` does not exist yet.

**Step 3: Write minimal implementation placeholder**

Create a temporary `scripts/install-stdcxx.sh` that exits non-zero with `not implemented` so the test fails for a meaningful reason.

```bash
#!/usr/bin/env bash
set -euo pipefail
echo "not implemented" >&2
exit 1
```

**Step 4: Run test to verify expected failure mode**

Run: `bash scripts/test-install-stdcxx.sh`
Expected: FAIL with `not implemented`.

**Step 5: Commit**

```bash
git add scripts/test-install-stdcxx.sh scripts/install-stdcxx.sh
git commit -m "test: add stdc++ installer fallback smoke test"
```

### Task 2: Implement core installer flow

**Files:**
- Modify: `scripts/install-stdcxx.sh`
- Test: `scripts/test-install-stdcxx.sh`

**Step 1: Write the next failing assertion**

Extend `scripts/test-install-stdcxx.sh` with output assertions:

```bash
output="$(HOME="$tmp_home" bash "$repo_root/scripts/install-stdcxx.sh" --force-user)"
printf '%s' "$output" | grep -q "user-fallback"
printf '%s' "$output" | grep -q -- '-I\$HOME/.local/include\|-I'
```

**Step 2: Run test to verify it fails**

Run: `bash scripts/test-install-stdcxx.sh`
Expected: FAIL because the installer does not yet copy the file or print final status.

**Step 3: Write minimal implementation**

Implement `scripts/install-stdcxx.sh` with:

```bash
#!/usr/bin/env bash
set -euo pipefail

repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
source_header="$repo_root/include/bits/stdc++.h"
mode="auto"
dry_run=0
use_sudo=0

for arg in "$@"; do
  case "$arg" in
    --dry-run) dry_run=1 ;;
    --sudo) use_sudo=1 ;;
    --force-user) mode="user" ;;
    *) echo "unknown option: $arg" >&2; exit 1 ;;
  esac
done

test -f "$source_header" || { echo "missing source: $source_header" >&2; exit 1; }

install_copy() {
  local root="$1"
  local dest_dir="$root/bits"
  local dest_file="$dest_dir/stdc++.h"
  if [[ "$dry_run" -eq 1 ]]; then
    printf 'would install: %s\n' "$dest_file"
    return 0
  fi
  mkdir -p "$dest_dir"
  cp "$source_header" "$dest_file"
}

if [[ "$mode" == "user" ]]; then
  install_copy "$HOME/.local/include"
  printf 'mode: user-fallback\npath: %s\nflag: -I$HOME/.local/include\n' "$HOME/.local/include/bits/stdc++.h"
  exit 0
fi
```

Then add the auto-mode candidate loop with existing-parent checks, plain-write attempts, optional sudo retry, and fallback to `"$HOME/.local/include"`.

**Step 4: Run tests to verify they pass**

Run: `bash scripts/test-install-stdcxx.sh`
Expected: PASS.

**Step 5: Commit**

```bash
git add scripts/install-stdcxx.sh scripts/test-install-stdcxx.sh
git commit -m "feat: add stdc++ include installer"
```

### Task 3: Add dry-run coverage and candidate probing checks

**Files:**
- Modify: `scripts/test-install-stdcxx.sh`
- Modify: `scripts/install-stdcxx.sh`

**Step 1: Write the failing test**

Add a dry-run assertion:

```bash
dry_run_home="$(mktemp -d)"
trap 'rm -rf "$tmp_home" "$dry_run_home"' EXIT

dry_run_output="$(HOME="$dry_run_home" bash "$repo_root/scripts/install-stdcxx.sh" --force-user --dry-run)"
printf '%s' "$dry_run_output" | grep -q 'would install:'
test ! -e "$dry_run_home/.local/include/bits/stdc++.h"
```

**Step 2: Run test to verify it fails**

Run: `bash scripts/test-install-stdcxx.sh`
Expected: FAIL because dry-run still writes or does not print probe output correctly.

**Step 3: Write minimal implementation**

Adjust `scripts/install-stdcxx.sh` so `--dry-run` never writes files and reports the chosen destination. Ensure candidate probing only considers roots whose parent path already exists, for example:

```bash
candidate_roots=(
  "/opt/homebrew/include"
  "/usr/local/include"
)

for root in "${candidate_roots[@]}"; do
  [[ -d "$root" ]] || continue
  if install_copy "$root"; then
    printf 'mode: system\npath: %s\n' "$root/bits/stdc++.h"
    exit 0
  fi
done
```

If compiler discovery is added, keep it additive and skip empty or non-existent paths.

**Step 4: Run tests to verify they pass**

Run: `bash scripts/test-install-stdcxx.sh`
Expected: PASS.

**Step 5: Commit**

```bash
git add scripts/install-stdcxx.sh scripts/test-install-stdcxx.sh
git commit -m "test: cover stdc++ installer dry runs"
```

### Task 4: Document usage in the README

**Files:**
- Modify: `README.md`
- Test: `README.md`

**Step 1: Write the failing docs check**

Add a shell assertion to verify the README mentions the installer:

```bash
grep -q 'install-stdcxx.sh' README.md
grep -q '\-\-force-user' README.md
```

**Step 2: Run docs check to verify it fails**

Run: `grep -q 'install-stdcxx.sh' README.md`
Expected: FAIL because the README currently has no installer usage section.

**Step 3: Write minimal documentation**

Append a short section to `README.md` covering:

```md
## stdc++.h installer

Run `bash scripts/install-stdcxx.sh` to install `include/bits/stdc++.h`.

- Use `--dry-run` to inspect the chosen destination
- Use `--sudo` to retry system installs with elevated permissions
- Use `--force-user` to install to `~/.local/include/bits/stdc++.h`

If the script falls back to the user directory, compile with `-I$HOME/.local/include`.
```

**Step 4: Run docs check to verify it passes**

Run: `grep -n 'install-stdcxx.sh\|--force-user' README.md`
Expected: PASS with matching lines.

**Step 5: Commit**

```bash
git add README.md
git commit -m "docs: add stdc++ installer usage"
```

### Task 5: Run end-to-end verification

**Files:**
- Test: `scripts/test-install-stdcxx.sh`
- Test: `scripts/install-stdcxx.sh`

**Step 1: Run the repository smoke test**

Run: `bash scripts/test-install-stdcxx.sh`
Expected: PASS.

**Step 2: Run installer dry-run in auto mode**

Run: `bash scripts/install-stdcxx.sh --dry-run`
Expected: PASS with a selected candidate or fallback destination shown.

**Step 3: Run a compile smoke test**

Create a temporary file and compile it:

```bash
tmp_cpp="$(mktemp /tmp/stdcxx-test.XXXXXX.cpp)"
cat > "$tmp_cpp" <<'EOF'
#include <bits/stdc++.h>
int main() { return 0; }
EOF
clang++ -std=c++20 -I"$HOME/.local/include" "$tmp_cpp" -o /tmp/stdcxx-test
```

Expected: PASS after a successful user-fallback install, or pass without `-I` if a system install succeeded.

**Step 4: Review changed files**

Run: `git diff -- scripts/install-stdcxx.sh scripts/test-install-stdcxx.sh README.md`
Expected: Only the installer, smoke test, and docs changes appear.

**Step 5: Commit**

```bash
git add scripts/install-stdcxx.sh scripts/test-install-stdcxx.sh README.md
git commit -m "feat: support stdc++ include injection"
```
