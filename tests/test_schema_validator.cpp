#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#ifdef _WIN32
#include <io.h>
#include <windows.h>
#else
#include <sys/wait.h>
#include <unistd.h>
#endif

namespace fs = std::filesystem;

namespace {
/**
 * @brief Debug helper to log paths and commands
 */
void debug_log(const std::string &prefix, const std::string &message) {
  std::cerr << "[DEBUG] " << prefix << ": " << message << '\n';
}

/**
 * @brief Get the directory containing the executables (one level up from test
 * dir)
 */
fs::path get_executables_dir() {
#ifdef _WIN32
  char path[MAX_PATH];
  GetModuleFileNameA(NULL, path, MAX_PATH);
  fs::path self_path(path);
#else
  char path[1024];
  ssize_t len = readlink("/proc/self/exe", path, sizeof(path) - 1);
  if (len == -1) {
    return fs::current_path().parent_path();
  }
  path[len] = '\0';
  fs::path self_path(path);
#endif
  fs::path exe_dir = self_path.parent_path().parent_path();
  debug_log("get_executables_dir",
            "Executables directory: " + exe_dir.string());
  return exe_dir;
}

/**
 * @brief Find an executable in the build/release directory
 */
fs::path find_executable(const std::string &exe_name) {
  fs::path exe_dir = get_executables_dir();
  fs::path exe_path = exe_dir / exe_name;

#ifdef _WIN32
  if (!exe_path.has_extension()) {
    exe_path += ".exe";
  }
#endif

  debug_log("find_executable", "Looking for: " + exe_path.string());
  debug_log("find_executable",
            "Exists: " + std::string(fs::exists(exe_path) ? "YES" : "NO"));

  if (!fs::exists(exe_path)) {
    throw std::runtime_error("Could not find executable: " + exe_path.string());
  }

  debug_log("find_executable", "Found executable: " + exe_path.string());
  return exe_path;
}

/**
 * @brief Get the repository root directory
 */
fs::path get_test_root() {
  fs::path test_file = fs::absolute(__FILE__);
  debug_log("get_test_root", "Test file: " + test_file.string());

  fs::path repo_root = test_file.parent_path().parent_path();
  debug_log("get_test_root", "Calculated repo root: " + repo_root.string());
  debug_log("get_test_root",
            "Repo root exists: " +
                std::string(fs::exists(repo_root) ? "YES" : "NO"));

  return repo_root;
}

/**
 * @brief Get the build output directory for temporary test files
 */
fs::path get_build_output_dir() {
  fs::path build_dir = get_executables_dir();
  debug_log("get_build_output_dir",
            "Build output directory: " + build_dir.string());
  return build_dir;
}

/**
 * @brief Execute a command with arguments using native platform APIs
 * @return Exit code of the executed process
 */
int execute_process(const fs::path &exe_path,
                    const std::vector<std::string> &args) {
  debug_log("execute_process", "Executable: " + exe_path.string());

  for (size_t i = 0; i < args.size(); ++i) {
    debug_log("execute_process",
              "  Arg[" + std::to_string(i) + "]: " + args[i]);
  }

#ifdef _WIN32
  // Windows: Use CreateProcessA
  std::string exe_str = exe_path.string();

  // Build command line: "exe" "arg1" "arg2" ...
  std::string cmd_line = "\"" + exe_str + "\"";
  for (const auto &arg : args) {
    cmd_line += " \"" + arg + "\"";
  }

  debug_log("execute_process", "Full command line: " + cmd_line);

  STARTUPINFOA si = {};
  PROCESS_INFORMATION pi = {};
  si.cb = sizeof(si);

  BOOL success =
      CreateProcessA(NULL,                                 // lpApplicationName
                     const_cast<char *>(cmd_line.c_str()), // lpCommandLine
                     NULL,  // lpProcessAttributes
                     NULL,  // lpThreadAttributes
                     FALSE, // bInheritHandles
                     0,     // dwCreationFlags
                     NULL,  // lpEnvironment
                     NULL,  // lpCurrentDirectory
                     &si,   // lpStartupInfo
                     &pi    // lpProcessInformation
      );

  if (!success) {
    DWORD error = GetLastError();
    throw std::runtime_error("CreateProcessA failed with error code: " +
                             std::to_string(error));
  }

  // Wait for process to complete
  WaitForSingleObject(pi.hProcess, INFINITE);

  DWORD exit_code = 0;
  GetExitCodeProcess(pi.hProcess, &exit_code);

  CloseHandle(pi.hProcess);
  CloseHandle(pi.hThread);

  debug_log("execute_process",
            "Process exit code: " + std::to_string(exit_code));
  return exit_code;

#else
  // Linux/Mac: Use fork/execvp
  pid_t pid = fork();

  if (pid == -1) {
    throw std::runtime_error("fork() failed");
  }

  if (pid == 0) {
    // Child process
    std::vector<char *> argv;
    argv.push_back(const_cast<char *>(exe_path.filename().string().c_str()));
    for (const auto &arg : args) {
      argv.push_back(const_cast<char *>(arg.c_str()));
    }
    argv.push_back(nullptr);

    execvp(exe_path.string().c_str(), argv.data());
    // If execvp returns, there was an error
    std::cerr << "execvp failed for: " << exe_path.string() << '\n';
    exit(1);
  } else {
    // Parent process: wait for child
    int status = 0;
    waitpid(pid, &status, 0);

    if (WIFEXITED(status)) {
      int exit_code = WEXITSTATUS(status);
      debug_log("execute_process",
                "Process exit code: " + std::to_string(exit_code));
      return exit_code;
    }
    throw std::runtime_error("Child process did not exit normally");
  }
#endif
}

/**
 * @brief Helper to run a CLI validator tool
 */
int run_validator(const std::string &tool, const std::string &yaml_path) {
  debug_log("run_validator", "Tool: " + tool);
  debug_log("run_validator", "YAML path: " + yaml_path);
  debug_log("run_validator",
            "File exists: " +
                std::string(fs::exists(yaml_path) ? "YES" : "NO"));

  fs::path validator_exe = find_executable(tool);
  std::vector<std::string> args = {yaml_path};

  return execute_process(validator_exe, args);
}

/**
 * @brief Clean up temporary test files
 */
void cleanup_temp_files() {
  fs::path output_dir = get_build_output_dir();

  try {
    fs::path config_file = output_dir / "test_config.yaml";
    if (fs::exists(config_file)) {
      debug_log("cleanup", "Removing: " + config_file.string());
      fs::remove(config_file);
    }
  } catch (const std::exception &e) {
    debug_log("cleanup",
              "Failed to remove test_config.yaml: " + std::string(e.what()));
  }
}
} // namespace

TEST(SchemaValidatorTest, ValidateQuantumDotConfig) {
  const char *yaml_content = R"yaml(
ScreeningGates: "S1;S2;S3"
PlungerGates: "P1;P2;P3"
Ohmics: "O1;O2;O3;O4"
BarrierGates: "B1;B2;B3;B4;B5"
ReservoirGates: "R1;R2;R3;R4"
num-unique-channels: 2

groups:
  group1:
    Name: "I_O1"
    NumDots: 2
    ScreeningGates: "S1;S2"
    ReservoirGates: "R1;R2"
    PlungerGates: "P1;P2"
    BarrierGates: "B1;B2;B3"
    Order: "O1;R1;B1;P1;B2;P2;B3;R2;O2"

  group2:
    Name: "I_O3"
    NumDots: 1
    ScreeningGates: "S2;S3"
    ReservoirGates: "R3;R4"
    PlungerGates: "P3"
    BarrierGates: "B4;B5"
    Order: "O3;R3;B4;P3;B5;R4;O4"

adjacency:
  S2: "P1;P2;P3;R1;R2;R3;R4;B1;B2;B3;B4;B5"
  S1: "P1;P2;R1;R2;B1;B2;B3"
  S3: "P3;B4;B5;R3;R4"
  B1: "R1;P1"
  B2: "P1;P2"
  B3: "P2;R2"
  B4: "P3;R3"
  B5: "R4;P3"
  O3: "R3"
  O4: "R4"
  O1: "R1"
  O2: "R2"

max_safe_diff: 1.0
safe_voltage_bounds: [-1.0, 1.0]

wiringDC:
  S1: {resistance: 1000.0, capacitance: 1e-12}
  S2: {resistance: 1000.0, capacitance: 1e-12}
  S3: {resistance: 1000.0, capacitance: 1e-12}
  P1: {resistance: 1000.0, capacitance: 1e-12}
  P2: {resistance: 1000.0, capacitance: 1e-12}
  P3: {resistance: 1000.0, capacitance: 1e-12}
  O1: {resistance: 1000.0, capacitance: 1e-12}
  O2: {resistance: 1000.0, capacitance: 1e-12}
  O3: {resistance: 1000.0, capacitance: 1e-12}
  O4: {resistance: 1000.0, capacitance: 1e-12}
  R1: {resistance: 1000.0, capacitance: 1e-12}
  R2: {resistance: 1000.0, capacitance: 1e-12}
  R3: {resistance: 1000.0, capacitance: 1e-12}
  R4: {resistance: 1000.0, capacitance: 1e-12}
  B1: {resistance: 1000.0, capacitance: 1e-12}
  B2: {resistance: 1000.0, capacitance: 1e-12}
  B3: {resistance: 1000.0, capacitance: 1e-12}
  B4: {resistance: 1000.0, capacitance: 1e-12}
  B5: {resistance: 1000.0, capacitance: 1e-12}
)yaml";

  const fs::path repo_root = get_build_output_dir();
  const fs::path yaml_path = repo_root / "test_config.yaml";

  debug_log("TEST", "Full YAML path: " + yaml_path.string());

  // Ensure the output directory exists before creating the test file.
  std::error_code ec;
  fs::create_directories(yaml_path.parent_path(), ec);

  ASSERT_FALSE(ec) << "Failed to create test output directory: "
                   << yaml_path.parent_path().string() << ": " << ec.message();

  {
    std::ofstream yaml_file(yaml_path, std::ios::out | std::ios::trunc);

    ASSERT_TRUE(yaml_file.is_open())
        << "Failed to open temporary YAML file: " << yaml_path.string();

    yaml_file << yaml_content;

    ASSERT_TRUE(yaml_file.good())
        << "Failed while writing temporary YAML file: " << yaml_path.string();

    yaml_file.close();

    ASSERT_FALSE(yaml_file.fail())
        << "Failed to close temporary YAML file: " << yaml_path.string();
  }

  ASSERT_TRUE(fs::exists(yaml_path))
      << "Temporary YAML file was not created: " << yaml_path.string();

  debug_log("TEST", "File exists: YES");

  const int ret =
      run_validator("validate-quantum-dot-config", yaml_path.string());

  EXPECT_EQ(ret, 0) << "Validation failed for quantum dot config: "
                    << yaml_path.string();

  std::cerr << "========\n\n";

  // Keep cleanup from obscuring the validator assertion.
  ec.clear();
  fs::remove(yaml_path, ec);

  if (ec) {
    debug_log("TEST", "Warning: failed to remove temporary YAML file: " +
                          yaml_path.string() + ": " + ec.message());
  }
}
TEST(SchemaValidatorTest, VerifyBadQuantumDotConfig) {
  const char *yaml_content = R"yaml(
ScreeningGates: "S1;S2;S3"
PlungerGates: "P1;P2;P3"
Ohmics: "O1;O2;O3;O4"
BarrierGates: "B1;B2;B3;B4;B5"
num-unique-channels: 2

groups:
  group1:
    Name: "I_O1"
    NumDots: 2
    ScreeningGates: "S1;S2"
    ReservoirGates: "R1;R2"
    PlungerGates: "P1;P2"
    BarrierGates: "B1;B2;B3"
    Order: "O1;R1;B1;P1;B2;P2;B3;R2;O2"

  group2:
    Name: "I_O3"
    NumDots: 1
    ScreeningGates: "S2;S3"
    ReservoirGates: "R3;R4"
    PlungerGates: "P3"
    BarrierGates: "B4;B5"
    Order: "O3;R3;B4;P3;B5;R4;O4"

adjacency:
  S2: "P1;P2;P3;R1;R2;R3;R4;B1;B2;B3;B4;B5"
  S1: "P1;P2;R1;R2;B1;B2;B3"
  S3: "P3;B4;B5;R3;R4"
  B1: "R1;P1"
  B2: "P1;P2"
  B3: "P2;R2"
  B4: "P3;R3"
  B5: "R4;P3"
  O3: "R3"
  O4: "R4"
  O1: "R1"
  O2: "R2"

max_safe_diff: 1.0
safe_voltage_bounds: [-1.0, 1.0]

wiringDC:
  S1: {resistance: 1000.0, capacitance: 1e-12}
  S2: {resistance: 1000.0, capacitance: 1e-12}
  S3: {resistance: 1000.0, capacitance: 1e-12}
  P1: {resistance: 1000.0, capacitance: 1e-12}
  P2: {resistance: 1000.0, capacitance: 1e-12}
  P3: {resistance: 1000.0, capacitance: 1e-12}
  O1: {resistance: 1000.0, capacitance: 1e-12}
  O2: {resistance: 1000.0, capacitance: 1e-12}
  O3: {resistance: 1000.0, capacitance: 1e-12}
  O4: {resistance: 1000.0, capacitance: 1e-12}
  R1: {resistance: 1000.0, capacitance: 1e-12}
  R2: {resistance: 1000.0, capacitance: 1e-12}
  R3: {resistance: 1000.0, capacitance: 1e-12}
  R4: {resistance: 1000.0, capacitance: 1e-12}
  B1: {resistance: 1000.0, capacitance: 1e-12}
  B2: {resistance: 1000.0, capacitance: 1e-12}
  B3: {resistance: 1000.0, capacitance: 1e-12}
  B4: {resistance: 1000.0, capacitance: 1e-12}
  B5: {resistance: 1000.0, capacitance: 1e-12}
)yaml";

  const fs::path repo_root = get_build_output_dir();
  const fs::path yaml_path = repo_root / "test_config.yaml";

  debug_log("TEST", "Full YAML path: " + yaml_path.string());

  // Ensure the output directory exists before creating the test file.
  std::error_code ec;
  fs::create_directories(yaml_path.parent_path(), ec);

  ASSERT_FALSE(ec) << "Failed to create test output directory: "
                   << yaml_path.parent_path().string() << ": " << ec.message();

  {
    std::ofstream yaml_file(yaml_path, std::ios::out | std::ios::trunc);

    ASSERT_TRUE(yaml_file.is_open())
        << "Failed to open temporary YAML file: " << yaml_path.string();

    yaml_file << yaml_content;

    ASSERT_TRUE(yaml_file.good())
        << "Failed while writing temporary YAML file: " << yaml_path.string();

    yaml_file.close();

    ASSERT_FALSE(yaml_file.fail())
        << "Failed to close temporary YAML file: " << yaml_path.string();
  }

  ASSERT_TRUE(fs::exists(yaml_path))
      << "Temporary YAML file was not created: " << yaml_path.string();

  debug_log("TEST", "File exists: YES");

  const int ret =
      run_validator("validate-quantum-dot-config", yaml_path.string());

  EXPECT_NE(ret, 0) << "Validation did not fail for quantum dot config: "
                    << yaml_path.string();

  std::cerr << "========\n\n";

  // Keep cleanup from obscuring the validator assertion.
  ec.clear();
  fs::remove(yaml_path, ec);

  if (ec) {
    debug_log("TEST", "Warning: failed to remove temporary YAML file: " +
                          yaml_path.string() + ": " + ec.message());
  }
}
