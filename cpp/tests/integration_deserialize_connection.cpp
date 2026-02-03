#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

#include "falcon_core/CerealRegistry.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"

using namespace falcon_core::physics::device_structures;

struct Args {
  std::string input_file    = "connection_serialized.json";
  std::string expected_name = "CrossPlatformTestGate";
  std::string expected_type = "PlungerGate";
  bool        verbose       = false;
};

void print_usage(const char* program_name) {
  std::cout
      << "Usage: " << program_name << " [options]\n"
      << "Options:\n"
      << "  --input <file>     Input JSON file (default: "
         "connection_serialized.json)\n"
      << "  --name <name>      Expected gate name (default: "
         "CrossPlatformTestGate)\n"
      << "  --type <type>      Expected gate type (default: PlungerGate)\n"
      << "  --verbose          Print JSON content\n"
      << "  --help             Show this help message\n";
}

Args parse_args(int argc, char* argv[]) {
  Args args;
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if (arg == "--input" && i + 1 < argc) {
      args.input_file = argv[++i];
    } else if (arg == "--name" && i + 1 < argc) {
      args.expected_name = argv[++i];
    } else if (arg == "--type" && i + 1 < argc) {
      args.expected_type = argv[++i];
    } else if (arg == "--verbose") {
      args.verbose = true;
    } else if (arg == "--help") {
      print_usage(argv[0]);
      exit(0);
    }
  }
  return args;
}

int main(int argc, char* argv[]) {
  Args args = parse_args(argc, argv);

  std::cout << "=== Cross-Platform Deserialization Integration Test ===\n";
  std::cout << "Mode: DESERIALIZE\n";
  std::cout << "Input file: " << args.input_file << "\n";
  std::cout << "Expected name: " << args.expected_name << "\n";
  std::cout << "Expected type: " << args.expected_type << "\n";
  std::cout << "========================================================\n\n";

  // Read JSON from file
  std::string json_string;
  try {
    std::ifstream ifs(args.input_file);
    if (!ifs) {
      std::cerr << "ERROR: Could not open input file '" << args.input_file
                << "'\n";
      return 1;
    }

    std::stringstream buffer;
    buffer << ifs.rdbuf();
    json_string = buffer.str();
    ifs.close();

    std::cout << "Read JSON file (" << json_string.size() << " bytes)\n";

    if (args.verbose) {
      std::cout << "\nJSON Content:\n" << json_string << "\n\n";
    }
  } catch (const std::exception& e) {
    std::cerr << "ERROR: Failed to read file: " << e.what() << "\n";
    return 1;
  }

  // Deserialize using Song's from_json_string()
  ConnectionSP deserialized_connection;
  try {
    deserialized_connection =
        Connection::from_json_string<Connection>(json_string);

    if (!deserialized_connection) {
      std::cerr << "ERROR: Deserialization returned null pointer\n";
      return 1;
    }

    std::cout << "Successfully deserialized Connection\n";
  } catch (const std::exception& e) {
    std::cerr << "ERROR: Deserialization failed: " << e.what() << "\n";
    return 1;
  }

  // Validate the deserialized object
  std::cout << "\nValidation:\n";
  std::cout << "  Deserialized name: " << deserialized_connection->name()
            << "\n";
  std::cout << "  Deserialized type: " << deserialized_connection->type()
            << "\n";

  bool validation_passed = true;

  // Check name
  if (deserialized_connection->name() != args.expected_name) {
    std::cerr << "  [FAIL] Name mismatch! Expected '" << args.expected_name
              << "', got '" << deserialized_connection->name() << "'\n";
    validation_passed = false;
  } else {
    std::cout << "  [PASS] Name matches\n";
  }

  // Check type
  if (deserialized_connection->type() != args.expected_type) {
    std::cerr << "  [FAIL] Type mismatch! Expected '" << args.expected_type
              << "', got '" << deserialized_connection->type() << "'\n";
    validation_passed = false;
  } else {
    std::cout << "  [PASS] Type matches\n";
  }

  // Verify type-specific methods work
  if (args.expected_type == "PlungerGate") {
    if (!deserialized_connection->is_plunger_gate()) {
      std::cerr << "  [FAIL] is_plunger_gate() returned false!\n";
      validation_passed = false;
    } else {
      std::cout << "  [PASS] is_plunger_gate() confirmed\n";
    }
  } else if (args.expected_type == "BarrierGate") {
    if (!deserialized_connection->is_barrier_gate()) {
      std::cerr << "  [FAIL] is_barrier_gate() returned false!\n";
      validation_passed = false;
    } else {
      std::cout << "  [PASS] is_barrier_gate() confirmed\n";
    }
  } else if (args.expected_type == "ReservoirGate") {
    if (!deserialized_connection->is_reservoir_gate()) {
      std::cerr << "  [FAIL] is_reservoir_gate() returned false!\n";
      validation_passed = false;
    } else {
      std::cout << "  [PASS] is_reservoir_gate() confirmed\n";
    }
  } else if (args.expected_type == "ScreeningGate") {
    if (!deserialized_connection->is_screening_gate()) {
      std::cerr << "  [FAIL] is_screening_gate() returned false!\n";
      validation_passed = false;
    } else {
      std::cout << "  [PASS] is_screening_gate() confirmed\n";
    }
  } else if (args.expected_type == "Ohmic") {
    if (!deserialized_connection->is_ohmic()) {
      std::cerr << "  [FAIL] is_ohmic() returned false!\n";
      validation_passed = false;
    } else {
      std::cout << "  [PASS] is_ohmic() confirmed\n";
    }
  }

  std::cout << "\nPlatform: ";
#ifdef _WIN32
  std::cout << "Windows\n";
#elif __linux__
  std::cout << "Linux\n";
#elif __APPLE__
  std::cout << "macOS\n";
#else
  std::cout << "Unknown\n";
#endif

  if (validation_passed) {
    std::cout << "\n[SUCCESS] Cross-platform deserialization test PASSED\n";
    return 0;
  } else {
    std::cerr << "\n[FAILED] Cross-platform deserialization test FAILED\n";
    return 1;
  }
}
