#!/usr/bin/env pwsh
# Run from repo root on Windows.
# This script mirrors the windows-ci.yaml workflow for local testing.

$ErrorActionPreference = "Stop"

# Check we're at repo root
if (-not (Test-Path "cpp") -or -not (Test-Path "c-api")) {
    Write-Error "Run this from the repo root (where cpp/ and c-api/ exist)."
    exit 1
}

Write-Host "=== Checking Prerequisites ===" -ForegroundColor Cyan

# Check if chocolatey is available
if (-not (Get-Command choco -ErrorAction SilentlyContinue)) {
    Write-Error "Chocolatey not found. Install from https://chocolatey.org/install"
    exit 1
}

# Check if CMake is available
if (-not (Get-Command cmake -ErrorAction SilentlyContinue)) {
    Write-Host "Installing CMake..." -ForegroundColor Yellow
    choco install cmake -y
}

# Check if required tools are available, install if missing
$requiredTools = @("ninja", "ccache", "python", "llvm")
foreach ($tool in $requiredTools) {
    if (-not (Get-Command $tool -ErrorAction SilentlyContinue)) {
        Write-Host "Installing $tool..." -ForegroundColor Yellow
        choco install $tool -y
    }
}

# Ensure LLVM is in PATH
$llvmPath = "C:\Program Files\LLVM\bin"
if (Test-Path $llvmPath) {
    if ($env:PATH -notlike "*$llvmPath*") {
        $env:PATH = "$llvmPath;$env:PATH"
        Write-Host "Added LLVM to PATH" -ForegroundColor Green
    }
}

Write-Host "`n=== Setting up vcpkg ===" -ForegroundColor Cyan

# Check if vcpkg exists, clone if not
if (-not (Test-Path "vcpkg")) {
    Write-Host "Cloning vcpkg..." -ForegroundColor Yellow
    git clone https://github.com/microsoft/vcpkg.git
    .\vcpkg\bootstrap-vcpkg.bat
} else {
    Write-Host "vcpkg already exists, skipping clone." -ForegroundColor Green
}

# Make vcpkg path absolute
$vcpkgRoot = (Resolve-Path "vcpkg").Path

Write-Host "`n=== Building C++ Core ===" -ForegroundColor Cyan

# Install vcpkg dependencies for cpp
Write-Host "Installing vcpkg dependencies for cpp..." -ForegroundColor Yellow
Push-Location cpp
& "$vcpkgRoot\vcpkg.exe" install --triplet x64-windows

# Generate CMakePresets.json for cpp
Write-Host "Generating CMakePresets.json for cpp..." -ForegroundColor Yellow
@"
{
  "version": 3,
  "configurePresets": [
    {
      "name": "DEV",
      "displayName": "Development build with coverage (Clang, vcpkg, Debug)",
      "generator": "Ninja",
      "binaryDir": "build",
      "cacheVariables": {
        "CMAKE_TOOLCHAIN_FILE": "$($vcpkgRoot -replace '\\', '/')/scripts/buildsystems/vcpkg.cmake",
        "VCPKG_TARGET_TRIPLET": "x64-windows",
        "CMAKE_BUILD_TYPE": "Debug",
        "CMAKE_C_COMPILER": "clang",
        "CMAKE_CXX_COMPILER": "clang++",
        "USE_VCPKG": "1",
        "FALCON_CORE_DEV": "ON"
      }
    }
  ]
}
"@ | Out-File -Encoding utf8 CMakePresets.json

# Configure and build cpp
Write-Host "Configuring CMake for cpp..." -ForegroundColor Yellow
cmake --preset DEV

Write-Host "Building cpp..." -ForegroundColor Yellow
cmake --build build

# Test cpp
Write-Host "`n=== Testing C++ Core ===" -ForegroundColor Cyan
$buildDir = "build"
$coverageDir = "coverage"
$minRequired = 85.0

New-Item -ItemType Directory -Force -Path $coverageDir | Out-Null

# Locate the test executable
$exe = Get-ChildItem -Path $buildDir -Filter "falcon_core_cpp_run_tests*.exe" -Recurse -ErrorAction SilentlyContinue | Select-Object -First 1
if (-not $exe) {
    Write-Error "❌ Could not find 'falcon_core_cpp_run_tests.exe'"
    exit 1
}
Write-Host "Found test executable: $($exe.FullName)" -ForegroundColor Green

# Set profile file
$profRaw = Join-Path $exe.DirectoryName "falcon_core_cpp_run_tests.profraw"
$env:LLVM_PROFILE_FILE = $profRaw
Write-Host "LLVM_PROFILE_FILE: $env:LLVM_PROFILE_FILE" -ForegroundColor Gray

# Run tests
Write-Host "Running cpp tests..." -ForegroundColor Yellow
& $exe.FullName
$testExit = $LASTEXITCODE
if ($testExit -ne 0) {
    Write-Error "❌ C++ tests failed with exit code $testExit"
    exit 1
}
Write-Host "✅ C++ tests passed" -ForegroundColor Green

# Generate coverage report
if (Test-Path $profRaw) {
    $profData = Join-Path $exe.DirectoryName "falcon_core_cpp_run_tests.profdata"
    $reportFile = Join-Path $coverageDir "falcon-core-cpp.txt"
    
    Write-Host "Merging coverage data..." -ForegroundColor Yellow
    llvm-profdata merge -sparse $profRaw -o $profData
    
    Write-Host "Generating coverage report..." -ForegroundColor Yellow
    llvm-cov report $exe.FullName -instr-profile=$profData | Tee-Object -FilePath $reportFile
    
    # Check coverage threshold
    $totalLine = Select-String -Path $reportFile -Pattern '^TOTAL' | Select-Object -First 1
    if ($totalLine) {
        $matches = [regex]::Matches($totalLine.Line, '([0-9]+(?:\.[0-9]+)?)%')
        $allGood = $true
        foreach ($m in $matches) {
            $val = [double]$m.Groups[1].Value
            if ($val -lt $minRequired) {
                Write-Host "❌ Coverage $val% is below required $minRequired%" -ForegroundColor Red
                $allGood = $false
            }
        }
        if ($allGood) {
            Write-Host "✅ C++ coverage OK (all ≥ $minRequired%)" -ForegroundColor Green
        }
    }
} else {
    Write-Warning "⚠️  No coverage data found at $profRaw"
}

Pop-Location

Write-Host "`n=== Building C-API ===" -ForegroundColor Cyan

# Install vcpkg dependencies for c-api
Write-Host "Installing vcpkg dependencies for c-api..." -ForegroundColor Yellow
Push-Location c-api
& "$vcpkgRoot\vcpkg.exe" install --triplet x64-windows

# Generate CMakePresets.json for c-api
Write-Host "Generating CMakePresets.json for c-api..." -ForegroundColor Yellow
$cppRoot = (Resolve-Path "..\cpp").Path
@"
{
  "version": 3,
  "configurePresets": [
    {
      "name": "DEV",
      "displayName": "Development build with coverage (Clang, vcpkg, Debug)",
      "generator": "Ninja",
      "binaryDir": "build",
      "cacheVariables": {
        "CMAKE_TOOLCHAIN_FILE": "$($vcpkgRoot -replace '\\', '/')/scripts/buildsystems/vcpkg.cmake",
        "VCPKG_TARGET_TRIPLET": "x64-windows",
        "CMAKE_BUILD_TYPE": "Debug",
        "CMAKE_C_COMPILER": "clang",
        "CMAKE_CXX_COMPILER": "clang++",
        "USE_VCPKG": "1",
        "FALCON_CORE_DEV": "ON",
        "CORE_ROOT": "$($cppRoot -replace '\\', '/')"
      }
    }
  ]
}
"@ | Out-File -Encoding utf8 CMakePresets.json

# Configure and build c-api
Write-Host "Configuring CMake for c-api..." -ForegroundColor Yellow
cmake --preset DEV

Write-Host "Building c-api..." -ForegroundColor Yellow
cmake --build build

# Test c-api
Write-Host "`n=== Testing C-API ===" -ForegroundColor Cyan
$buildDir = "build"
$coverageDir = "coverage"
$minRequired = 90.0

New-Item -ItemType Directory -Force -Path $coverageDir | Out-Null

# Locate test executable
$exe = Get-ChildItem -Path $buildDir -Filter "falcon_core_c_api_run_tests*.exe" -Recurse -ErrorAction SilentlyContinue | Select-Object -First 1
if (-not $exe) {
    Write-Error "❌ Could not find 'falcon_core_c_api_run_tests.exe'"
    exit 1
}
Write-Host "Found test executable: $($exe.FullName)" -ForegroundColor Green

# Update PATH to find C++ library
$cppBuildDir = (Resolve-Path "..\cpp\build").Path
$env:PATH = "$($exe.DirectoryName);$cppBuildDir;$env:PATH"

# Set profile file
$profRaw = Join-Path $exe.DirectoryName "falcon_core_c_api_run_tests.profraw"
$env:LLVM_PROFILE_FILE = $profRaw
Write-Host "LLVM_PROFILE_FILE: $env:LLVM_PROFILE_FILE" -ForegroundColor Gray

# Run tests
Write-Host "Running c-api tests..." -ForegroundColor Yellow
& $exe.FullName
$testExit = $LASTEXITCODE
if ($testExit -ne 0) {
    Write-Error "❌ C-API tests failed with exit code $testExit"
    exit 1
}
Write-Host "✅ C-API tests passed" -ForegroundColor Green

# Generate coverage report
if (Test-Path $profRaw) {
    $profData = Join-Path $exe.DirectoryName "falcon_core_c_api_run_tests.profdata"
    $reportFile = Join-Path $coverageDir "falcon-core-c-api.txt"
    
    Write-Host "Merging coverage data..." -ForegroundColor Yellow
    llvm-profdata merge -sparse $profRaw -o $profData
    
    Write-Host "Generating coverage report..." -ForegroundColor Yellow
    llvm-cov report $exe.FullName -instr-profile=$profData | Tee-Object -FilePath $reportFile
    
    # Check coverage threshold
    $totalLine = Select-String -Path $reportFile -Pattern '^TOTAL' | Select-Object -First 1
    if ($totalLine) {
        $matches = [regex]::Matches($totalLine.Line, '([0-9]+(?:\.[0-9]+)?)%')
        $allGood = $true
        foreach ($m in $matches) {
            $val = [double]$m.Groups[1].Value
            if ($val -lt $minRequired) {
                Write-Host "❌ Coverage $val% is below required $minRequired%" -ForegroundColor Red
                $allGood = $false
            }
        }
        if ($allGood) {
            Write-Host "✅ C-API coverage OK (all ≥ $minRequired%)" -ForegroundColor Green
        }
    }
} else {
    Write-Warning "⚠️  No coverage data found at $profRaw"
}

Pop-Location

Write-Host "`n=== DONE ===" -ForegroundColor Green
Write-Host "CPP coverage report:   cpp\coverage\falcon-core-cpp.txt" -ForegroundColor Cyan
Write-Host "C-API coverage report: c-api\coverage\falcon-core-c-api.txt" -ForegroundColor Cyan
