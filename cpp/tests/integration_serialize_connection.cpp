#include <fstream>
#include <iostream>
#include <memory>
#include <string>

#include "falcon_core/physics/device_structures/Connection.hpp"

using namespace falcon_core::physics::device_structures;

struct Args {
  std::string output_file = "connection_serialized.json";
  std::string gate_name   = "CrossPlatformTestGate";
  std::string gate_type   = "PlungerGate";
};

void print_usage(const char* program_name) {
  std::cout
      << "Usage: " << program_name << " [options]\n"
      << "Options:\n"
      << "  --output <file>    Output JSON file (default: "
         "connection_serialized.json)\n"
      << "  --name <name>      Gate name (default: CrossPlatformTestGate)\n"
      << "  --type <type>      Gate type: "
         "PlungerGate|BarrierGate|ReservoirGate|ScreeningGate|Ohmic (default: "
         "PlungerGate)\n"
      << "  --help             Show this help message\n";
}

Args parse_args(int argc, char* argv[]) {
  Args args;
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if (arg == "--output" && i + 1 < argc) {
      args.output_file = argv[++i];
    } else if (arg == "--name" && i + 1 < argc) {
      args.gate_name = argv[++i];
    } else if (arg == "--type" && i + 1 < argc) {
      args.gate_type = argv[++i];
    } else if (arg == "--help") {
      print_usage(argv[0]);
      exit(0);
    }
  }
  return args;
}

int main(int argc, char* argv[]) {
  Args args = parse_args(argc, argv);

  std::cout << "=== Cross-Platform Serialization Integration Test ===\n";
  std::cout << "Mode: SERIALIZE\n";
  std::cout << "Output file: " << args.output_file << "\n";
  std::cout << "Gate name: " << args.gate_name << "\n";
  std::cout << "Gate type: " << args.gate_type << "\n";
  std::cout << "======================================================\n\n";

  // Create Connection based on type
  ConnectionSP connection;
  try {
    if (args.gate_type == "PlungerGate") {
      connection = Connection::PlungerGate(args.gate_name);
    } else if (args.gate_type == "BarrierGate") {
      connection = Connection::BarrierGate(args.gate_name);
    } else if (args.gate_type == "ReservoirGate") {
      connection = Connection::ReservoirGate(args.gate_name);
    } else if (args.gate_type == "ScreeningGate") {
      connection = Connection::ScreeningGate(args.gate_name);
    } else if (args.gate_type == "Ohmic") {
      connection = Connection::Ohmic(args.gate_name);
    } else {
      std::cerr << "ERROR: Unknown gate type '" << args.gate_type << "'\n";
      std::cerr << "Valid types: PlungerGate, BarrierGate, ReservoirGate, "
                   "ScreeningGate, Ohmic\n";
      return 1;
    }
  } catch (const std::exception& e) {
    std::cerr << "ERROR: Failed to create connection: " << e.what() << "\n";
    return 1;
  }

  std::cout << "Created " << connection->type() << " with name '"
            << connection->name() << "'\n";

  // Serialize using Song's to_json_string()
  std::string json_string;
  try {
    json_string = connection->to_json_string();
    std::cout << "Serialized to JSON (" << json_string.size() << " bytes)\n";
  } catch (const std::exception& e) {
    std::cerr << "ERROR: Serialization failed: " << e.what() << "\n";
    return 1;
  }

  // Write to file
  try {
    std::ofstream ofs(args.output_file);
    if (!ofs) {
      std::cerr << "ERROR: Could not open output file '" << args.output_file
                << "'\n";
      return 1;
    }
    ofs << json_string;
    ofs.close();

    std::cout << "Successfully wrote JSON to '" << args.output_file << "'\n";
  } catch (const std::exception& e) {
    std::cerr << "ERROR: Failed to write file: " << e.what() << "\n";
    return 1;
  }

  std::cout << "\n✓ Serialization completed successfully\n";
  std::cout << "Platform: ";
#ifdef _WIN32
  std::cout << "Windows\n";
#elif __linux__
  std::cout << "Linux\n";
#elif __APPLE__
  std::cout << "macOS\n";
#else
  std::cout << "Unknown\n";
#endif

  return 0;
}
