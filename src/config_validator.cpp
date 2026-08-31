#include <iostream>
#include <yaml-config-validator.hpp>

namespace quantum_schema {
extern const char QUANTUM_DOT_DEVICE_SCHEMA[];
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <input.yaml>\n";
    return 1;
  }
  auto result = validator::validate_yaml_file(
      argv[1], quantum_schema::QUANTUM_DOT_DEVICE_SCHEMA,
      "Quantum dot device schema");
  for (const auto &warn : result.warnings) {
    std::cout << "  - " << warn << "\n";
  }
  if (result.valid) {
    std::cout << "Validation succeeded.\n";
    return 0;
  }
  std::cout << "Validation failed:\n";
  for (const auto &err : result.errors) {
    std::cout << "  - " << err.path << ": " << err.message << "\n";
  }
  return 2;
}
