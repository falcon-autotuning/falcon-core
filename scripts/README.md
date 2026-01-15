# Local CI Scripts

This directory contains scripts for running CI-like builds and tests locally, mirroring the GitHub Actions workflows.

## Arch Linux - `local_arch_ci.sh`

Builds and tests falcon-core C++ and C-API on Arch Linux using Docker.

### Prerequisites

- Docker installed and running
- Bash shell

### Setup

1. Build the Docker image:
   ```bash
   docker build -t falcon-arch-ci -f docker/arch-all.Dockerfile .
   ```

2. Run the script from the repository root:
   ```bash
   ./scripts/local_arch_ci.sh
   ```

### What it does

- Creates an Arch Linux container with all dependencies
- Installs AUR packages (highfive, exprtk)
- Builds and installs xtensor stack (xtl, xsimd, xtensor, xtensor-io)
- Builds falcon-core-cpp with coverage (~91%)
- Builds falcon-core-c-api with coverage (~99%)
- Generates coverage reports in `cpp/coverage/` and `c-api/coverage/`

### Caching

The script caches pacman packages and ccache in `.cache/` to speed up subsequent runs.

## Windows - `local_windows_ci.ps1`

Builds and tests falcon-core C++ and C-API on Windows natively (without Docker).

### Prerequisites

- Windows 10/11 or Windows Server
- PowerShell 5.1 or PowerShell Core 7+
- Administrator privileges (for installing dependencies)

### Setup

1. Install Chocolatey if not already installed:
   ```powershell
   # Run in Administrator PowerShell
   Set-ExecutionPolicy Bypass -Scope Process -Force
   [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072
   iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
   ```

2. Run the script from the repository root:
   ```powershell
   .\scripts\local_windows_ci.ps1
   ```

### What it does

- Checks and installs prerequisites (CMake, Ninja, ccache, Python, LLVM)
- Clones and bootstraps vcpkg if not present
- Installs vcpkg dependencies for C++ and C-API
- Builds falcon-core-cpp with coverage (≥85% required)
- Builds falcon-core-c-api with coverage (≥90% required)
- Generates coverage reports in `cpp\coverage\` and `c-api\coverage\`

### Notes

- First run will take longer as it installs dependencies and builds vcpkg packages
- vcpkg packages are cached in `vcpkg/` directory
- The script uses Clang for compilation (matches CI environment)

## Why No Windows Docker?

Windows containers require a Windows host (Windows Server or Windows 10/11 with container support). They cannot run on Linux/macOS Docker hosts, which is why we use a native PowerShell script instead of Docker for Windows builds.

## Coverage Reports

Both scripts generate coverage reports:

### Arch Linux
- C++ report: `cpp/coverage/falcon-core-cpp.txt` (~91% coverage)
- C-API report: `c-api/coverage/falcon-core-c-api.txt` (~99% coverage)

### Windows
- C++ report: `cpp\coverage\falcon-core-cpp.txt` (≥85% required)
- C-API report: `c-api\coverage\falcon-core-c-api.txt` (≥90% required)

## Troubleshooting

### Arch Linux Script

**Issue**: Docker permission denied
```bash
sudo usermod -aG docker $USER
# Log out and back in
```

**Issue**: Image build fails
```bash
docker system prune -a  # Clean up old images
docker build --no-cache -t falcon-arch-ci -f docker/arch-all.Dockerfile .
```

### Windows Script

**Issue**: Execution policy error
```powershell
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser
```

**Issue**: vcpkg fails to install packages
```powershell
# Clean vcpkg and retry
Remove-Item -Recurse -Force vcpkg
.\scripts\local_windows_ci.ps1
```

**Issue**: CMake cannot find packages
```powershell
# Ensure vcpkg integration is installed
.\vcpkg\vcpkg.exe integrate install
```

**Issue**: Tests fail with "DLL not found"
- Ensure the C++ build completed successfully before C-API tests
- Check that LLVM is in PATH: `where clang`

## Comparison with CI Workflows

These scripts mirror the GitHub Actions workflows:

| Script | Workflow | Platform | Coverage |
|--------|----------|----------|----------|
| `local_arch_ci.sh` | `.github/workflows/arch-ci.yaml` | Arch Linux | C++: ~91%, C-API: ~99% |
| `local_windows_ci.ps1` | `.github/workflows/windows-ci.yaml` | Windows | C++: ≥85%, C-API: ≥90% |

## Contributing

When modifying these scripts, ensure they stay in sync with the corresponding CI workflows. Any changes to build steps or dependencies should be reflected in both the scripts and the workflows.
