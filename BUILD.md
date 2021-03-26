# Building NCX-Core-Lite
## Dependencies
You MUST have these installed before continuing!
### Linux
(Can be installed with apt/pacman)
- libcurl4-nss-dev (libcurl)
- libgtk-3-0 (GTK+ 3 runtime library)
- libgtk-3-dev (GTK+ 3 development library)
### macOS
(Can be installed with Homebrew)
- curl (libcurl)
- gtk+3 (GTK+ 3)
## Building
A makefile is included and is ready-to-use. To compile, use `make` followed by your OS.
Available platforms:
- `make linux` for 64-bit Linux
- `make macX86` for Intel-based Macs
- `make macARM` for ARM-based Macs
<br />
Builds will be placed in the bin/ directory. You can remove it and all builds with `make clean`.
