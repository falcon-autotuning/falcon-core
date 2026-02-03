#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"

typedef struct {
  const char* input_file;
  const char* expected_name;
  const char* expected_type;
  bool        verbose;
} Args;

void print_usage(const char* program_name) {
  printf("Usage: %s [options]\n", program_name);
  printf("Options:\n");
  printf(
      "  --input <file>     Input JSON file (default: "
      "connection_serialized.json)\n");
  printf(
      "  --name <name>      Expected gate name (default: "
      "CrossPlatformTestGate)\n");
  printf("  --type <type>      Expected gate type (default: PlungerGate)\n");
  printf("  --verbose          Print JSON content\n");
  printf("  --help             Show this help message\n");
}

Args parse_args(int argc, char* argv[]) {
  Args args;
  args.input_file    = "connection_serialized.json";
  args.expected_name = "CrossPlatformTestGate";
  args.expected_type = "PlungerGate";
  args.verbose       = false;

  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "--input") == 0 && i + 1 < argc) {
      args.input_file = argv[++i];
    } else if (strcmp(argv[i], "--name") == 0 && i + 1 < argc) {
      args.expected_name = argv[++i];
    } else if (strcmp(argv[i], "--type") == 0 && i + 1 < argc) {
      args.expected_type = argv[++i];
    } else if (strcmp(argv[i], "--verbose") == 0) {
      args.verbose = true;
    } else if (strcmp(argv[i], "--help") == 0) {
      print_usage(argv[0]);
      exit(0);
    }
  }

  return args;
}

char* read_file(const char* filename, size_t* out_size) {
#ifdef _WIN32
  FILE* file;
  fopen_s(&file, filename, "rb");
#else
  FILE* file = fopen(filename, "rb");
#endif
  if (!file) {
    return NULL;
  }

  // Get file size
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  fseek(file, 0, SEEK_SET);

  if (file_size < 0) {
    fclose(file);
    return NULL;
  }

  // Allocate buffer
  char* buffer = (char*)malloc(file_size + 1);
  if (!buffer) {
    fclose(file);
    return NULL;
  }

  // Read file
  size_t read_size = fread(buffer, 1, file_size, file);
  fclose(file);

  if (read_size != (size_t)file_size) {
    free(buffer);
    return NULL;
  }

  buffer[file_size] = '\0';
  *out_size         = file_size;
  return buffer;
}

int main(int argc, char* argv[]) {
  Args args = parse_args(argc, argv);

  printf("=== Cross-Platform Deserialization Integration Test (C-API) ===\n");
  printf("Mode: DESERIALIZE\n");
  printf("Input file: %s\n", args.input_file);
  printf("Expected name: %s\n", args.expected_name);
  printf("Expected type: %s\n", args.expected_type);
  printf(
      "================================================================\n\n");

  // Read JSON from file
  size_t json_size = 0;
  char*  json_data = read_file(args.input_file, &json_size);
  if (!json_data) {
    fprintf(stderr, "ERROR: Could not open input file '%s'\n", args.input_file);
    return 1;
  }

  printf("Read JSON file (%zu bytes)\n", json_size);

  if (args.verbose) {
    printf("\nJSON Content:\n%s\n\n", json_data);
  }

  // Create StringHandle for JSON
  StringHandle json_handle = String_create(json_data, json_size);
  if (!json_handle) {
    fprintf(stderr, "ERROR: Failed to create JSON string handle\n");
    free(json_data);
    return 1;
  }

  // Deserialize using from_json_string
  ConnectionHandle deserialized_connection =
      Connection_from_json_string(json_handle);
  if (!deserialized_connection) {
    fprintf(stderr, "ERROR: Deserialization failed\n");
    String_destroy(json_handle);
    free(json_data);
    return 1;
  }

  printf("Successfully deserialized Connection\n");

  // Get deserialized properties
  StringHandle deser_name = Connection_name(deserialized_connection);
  StringHandle deser_type = Connection_type(deserialized_connection);

  if (!deser_name || !deser_type) {
    fprintf(stderr, "ERROR: Failed to get connection properties\n");
    Connection_destroy(deserialized_connection);
    String_destroy(json_handle);
    free(json_data);
    return 1;
  }

  // Validate the deserialized object
  printf("\nValidation:\n");
  printf(
      "  Deserialized name: %.*s\n", (int)deser_name->length, deser_name->raw);
  printf(
      "  Deserialized type: %.*s\n", (int)deser_type->length, deser_type->raw);

  bool validation_passed = true;

  // Check name
  if (strncmp(deser_name->raw, args.expected_name, deser_name->length) != 0 ||
      strlen(args.expected_name) != deser_name->length) {
    fprintf(stderr,
            "  [FAIL] Name mismatch! Expected '%s', got '%.*s'\n",
            args.expected_name,
            (int)deser_name->length,
            deser_name->raw);
    validation_passed = false;
  } else {
    printf("  [PASS] Name matches\n");
  }

  // Check type
  if (strncmp(deser_type->raw, args.expected_type, deser_type->length) != 0 ||
      strlen(args.expected_type) != deser_type->length) {
    fprintf(stderr,
            "  [FAIL] Type mismatch! Expected '%s', got '%.*s'\n",
            args.expected_type,
            (int)deser_type->length,
            deser_type->raw);
    validation_passed = false;
  } else {
    printf("  [PASS] Type matches\n");
  }

  // Verify type-specific methods work
  if (strcmp(args.expected_type, "PlungerGate") == 0) {
    if (!Connection_is_plunger_gate(deserialized_connection)) {
      fprintf(stderr, "  [FAIL] is_plunger_gate() returned false!\n");
      validation_passed = false;
    } else {
      printf("  [PASS] is_plunger_gate() confirmed\n");
    }
  } else if (strcmp(args.expected_type, "BarrierGate") == 0) {
    if (!Connection_is_barrier_gate(deserialized_connection)) {
      fprintf(stderr, "  [FAIL] is_barrier_gate() returned false!\n");
      validation_passed = false;
    } else {
      printf("  [PASS] is_barrier_gate() confirmed\n");
    }
  } else if (strcmp(args.expected_type, "ReservoirGate") == 0) {
    if (!Connection_is_reservoir_gate(deserialized_connection)) {
      fprintf(stderr, "  [FAIL] is_reservoir_gate() returned false!\n");
      validation_passed = false;
    } else {
      printf("  [PASS] is_reservoir_gate() confirmed\n");
    }
  } else if (strcmp(args.expected_type, "ScreeningGate") == 0) {
    if (!Connection_is_screening_gate(deserialized_connection)) {
      fprintf(stderr, "  [FAIL] is_screening_gate() returned false!\n");
      validation_passed = false;
    } else {
      printf("  [PASS] is_screening_gate() confirmed\n");
    }
  } else if (strcmp(args.expected_type, "Ohmic") == 0) {
    if (!Connection_is_ohmic(deserialized_connection)) {
      fprintf(stderr, "  [FAIL] is_ohmic() returned false!\n");
      validation_passed = false;
    } else {
      printf("  [PASS] is_ohmic() confirmed\n");
    }
  }

  // Cleanup
  String_destroy(deser_name);
  String_destroy(deser_type);
  Connection_destroy(deserialized_connection);
  String_destroy(json_handle);
  free(json_data);

  printf("\nPlatform: ");
#ifdef _WIN32
  printf("Windows\n");
#elif __linux__
  printf("Linux\n");
#elif __APPLE__
  printf("macOS\n");
#else
  printf("Unknown\n");
#endif

  if (validation_passed) {
    printf("\n[SUCCESS] Cross-platform deserialization test PASSED\n");
    return 0;
  } else {
    fprintf(stderr, "\n[FAILED] Cross-platform deserialization test FAILED\n");
    return 1;
  }
}
