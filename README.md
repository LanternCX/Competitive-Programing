## ACM-Code-CX

刷的一些算法题

## stdc++.h installer

Run `bash scripts/install-stdcxx.sh` to install the repository's `include/bits/stdc++.h` into an available include directory.

By default the script tries include roots that your available C++ compiler already searches, then falls back to `~/.local/include` if those locations do not exist or are not writable.

- `--dry-run`: inspect the selected destination without writing files
- `--sudo`: retry system installs with `sudo` when a system path is not writable
- `--force-user`: skip system probing and install to `~/.local/include/bits/stdc++.h`

If the installer falls back to the user directory, compile with `-I$HOME/.local/include`.
