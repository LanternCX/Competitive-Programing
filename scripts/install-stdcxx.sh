#!/usr/bin/env bash
set -euo pipefail

repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
source_header="$repo_root/include/bits/stdc++.h"
dry_run=0
force_user=0
allow_sudo=0

for arg in "$@"; do
  case "$arg" in
    --dry-run)
      dry_run=1
      ;;
    --force-user)
      force_user=1
      ;;
    --sudo)
      allow_sudo=1
      ;;
    *)
      printf 'unknown option: %s\n' "$arg" >&2
      exit 1
      ;;
  esac
done

if [[ ! -f "$source_header" ]]; then
  printf 'missing source: %s\n' "$source_header" >&2
  exit 1
fi

declare -a candidate_roots=()
declare -a attempted_roots=()

add_candidate() {
  local root="$1"
  if [[ -z "$root" || ! -d "$root" ]]; then
    return
  fi
  local existing
  if [[ "${#candidate_roots[@]}" -gt 0 ]]; then
    for existing in "${candidate_roots[@]}"; do
      if [[ "$existing" == "$root" ]]; then
        return
      fi
    done
  fi
  candidate_roots+=("$root")
}

discover_candidates() {
  local override_root

  if [[ -n "${STDCPP_CANDIDATE_ROOTS:-}" ]]; then
    local old_ifs="$IFS"
    IFS=':'
    for override_root in $STDCPP_CANDIDATE_ROOTS; do
      add_candidate "$override_root"
    done
    IFS="$old_ifs"
    return
  fi

  discover_candidates_from_compiler "c++"
  discover_candidates_from_compiler "clang++"
  discover_candidates_from_compiler "g++"
}

discover_candidates_from_compiler() {
  local compiler="$1"
  local line
  local in_search_list=0

  if ! command -v "$compiler" >/dev/null 2>&1; then
    return
  fi

  while IFS= read -r line; do
    if [[ "$line" == "#include <...> search starts here:" ]]; then
      in_search_list=1
      continue
    fi

    if [[ "$line" == "End of search list." ]]; then
      break
    fi

    if [[ "$in_search_list" -eq 1 ]]; then
      line="${line#"${line%%[![:space:]]*}"}"
      if [[ "$line" == *"(framework directory)"* ]]; then
        continue
      fi
      add_candidate "$line"
    fi
  done < <("$compiler" -xc++ -E -v - </dev/null 2>&1)
}

root_is_writable() {
  local root="$1"
  local dest_dir="$root/bits"
  local probe_path

  if [[ -d "$dest_dir" ]]; then
    [[ -w "$dest_dir" ]]
    return
  fi

  probe_path="$root"
  while [[ ! -e "$probe_path" && "$probe_path" != "/" ]]; do
    probe_path="$(dirname "$probe_path")"
  done

  [[ -w "$probe_path" ]]
}

print_result() {
  local mode="$1"
  local destination="$2"
  local used_sudo="$3"

  printf 'source: %s\n' "$source_header"
  printf 'mode: %s\n' "$mode"
  printf 'path: %s\n' "$destination"
  printf 'sudo: %s\n' "$used_sudo"
  if [[ "$mode" == "user-fallback" ]]; then
    printf 'flag: -I$HOME/.local/include\n'
  fi
}

install_into_root() {
  local root="$1"
  local dest_dir="$root/bits"
  local dest_file="$dest_dir/stdc++.h"
  attempted_roots+=("$root")

  if [[ "$dry_run" -eq 1 ]]; then
    if root_is_writable "$root" || ([[ "$allow_sudo" -eq 1 ]] && command -v sudo >/dev/null 2>&1); then
      printf 'would install: %s\n' "$dest_file"
      if [[ "$allow_sudo" -eq 1 ]] && command -v sudo >/dev/null 2>&1 && ! root_is_writable "$root"; then
        INSTALL_USED_SUDO=1
      else
        INSTALL_USED_SUDO=0
      fi
      INSTALL_DEST="$dest_file"
      return 0
    fi
    return 1
  fi

  if mkdir -p "$dest_dir" 2>/dev/null && cp "$source_header" "$dest_file" 2>/dev/null; then
    INSTALL_DEST="$dest_file"
    INSTALL_USED_SUDO=0
    return 0
  fi

  if [[ "$allow_sudo" -eq 1 ]] && command -v sudo >/dev/null 2>&1; then
    if sudo mkdir -p "$dest_dir" && sudo cp "$source_header" "$dest_file"; then
      INSTALL_DEST="$dest_file"
      INSTALL_USED_SUDO=1
      return 0
    fi
  fi

  return 1
}

INSTALL_DEST=""
INSTALL_USED_SUDO=0
user_root="$HOME/.local/include"

if [[ "$force_user" -eq 0 ]]; then
  discover_candidates
  if [[ "${#candidate_roots[@]}" -gt 0 ]]; then
    for root in "${candidate_roots[@]}"; do
      if install_into_root "$root"; then
        print_result "system" "${INSTALL_DEST:-$root/bits/stdc++.h}" "$INSTALL_USED_SUDO"
        exit 0
      fi
    done
  fi
fi

if install_into_root "$user_root"; then
  print_result "user-fallback" "${INSTALL_DEST:-$user_root/bits/stdc++.h}" "$INSTALL_USED_SUDO"
  exit 0
fi

printf 'failed to install %s\n' "$source_header" >&2
if [[ "${#attempted_roots[@]}" -gt 0 ]]; then
  printf 'attempted roots:\n' >&2
  for root in "${attempted_roots[@]}"; do
    printf '  %s\n' "$root" >&2
  done
fi
exit 1
