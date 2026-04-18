# stdc++.h Include Injection Design

## Goal

Add a repository-local bash script that installs the existing `include/bits/stdc++.h` into a usable include location for competitive programming. The script should prefer a real system-visible include directory and fall back to a user-local include directory when system installation is not possible.

## Context

This repository already stores a vendored `bits/stdc++.h` at `include/bits/stdc++.h`, and many source files include it with `#include <bits/stdc++.h>`. The repository currently does not provide a helper to install that header onto machines where the compiler toolchain does not already ship it.

## Requirements

- Source file is fixed at `include/bits/stdc++.h`
- Script is bash-based and lives in the repository
- Default mode auto-detects candidate install targets
- Script prefers system-visible include targets when possible
- Script falls back to a user-local include directory when system install fails
- Script prints clear results, including the final install path and any required `-I` flag for fallback installs
- Script does not create fake compiler directory trees; it only writes into existing candidate parents plus a user-local fallback

## Chosen Approach

Use a single repository script, `scripts/install-stdcxx.sh`, with a deterministic install pipeline:

1. Validate that `include/bits/stdc++.h` exists
2. Build a list of likely include destinations for the current machine
3. For each destination, check whether the parent directory already exists
4. Try to create a `bits/` subdirectory if needed and install `stdc++.h`
5. If no system-visible location succeeds, install to `~/.local/include/bits/stdc++.h`
6. Print a final status block that explains whether the header is globally visible or requires `-I$HOME/.local/include`

## Candidate Destination Strategy

The script should not guess one hard-coded compiler path. Instead, it should probe the actual include search paths reported by available C++ compilers and only attempt installs into parents that already exist.

Initial candidate classes:

- include roots parsed from `c++ -xc++ -E -v -`
- include roots parsed from `clang++ -xc++ -E -v -`
- include roots parsed from `g++ -xc++ -E -v -`

Each candidate is treated as an include root. The script installs to `<root>/bits/stdc++.h`.

## CLI Interface

The script should support these flags:

- `--dry-run`: show candidate evaluation and intended destination without modifying files
- `--sudo`: retry system installs with `sudo` when plain writes fail
- `--force-user`: skip system probing and install directly to `~/.local/include/bits/stdc++.h`

No mandatory positional arguments are needed.

## Error Handling

- Missing source header: exit non-zero with a direct error message
- Candidate parent missing: skip silently or with trace output in `--dry-run`
- Candidate not writable: record why it failed and continue
- `sudo` unavailable or rejected: continue to next candidate or fallback
- User-local fallback failure: exit non-zero with the last relevant error

## Output Design

The script should produce concise, competition-friendly output:

- source header path
- selected destination path
- install mode: `system` or `user-fallback`
- whether `sudo` was used
- when fallback happens, print a ready-to-copy compile flag: `-I$HOME/.local/include`

## Testing Strategy

Testing should be shell-based and lightweight:

- dry-run execution to validate discovery logic
- fallback execution into a temporary HOME to validate user-local install behavior
- optional real compile smoke test using a trivial program with `#include <bits/stdc++.h>`

The tests should avoid requiring destructive writes into real system directories.

## Documentation Impact

Update `README.md` with a short section that explains:

- why the script exists
- how to run it
- what happens on fallback
- which compile flag to use after fallback installs

## Non-Goals

- managing package managers or compiler installation
- editing shell rc files automatically
- installing a full GCC compatibility layer
- maintaining multiple header variants
