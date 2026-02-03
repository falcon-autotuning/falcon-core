#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"

typedef struct {
  const char* output_file;
  const char* gate_name;
  const char* gate_type;
} Args;

void print_usage(const char* program_name) {
  printf("Usage: %s [options]\n", program_name);
  printf("Options:\n");
  printf(
      "  --output <file>    Output JSON file (default: "
      "connection_serialized.json)\n");
  printf("  --name <name>      Gate name (default: CrossPlatformTestGate)\n");
  printf(
      "  --type <type>      Gate type: "
      "PlungerGate|BarrierGate|ReservoirGate|ScreeningGate|Ohmic (default: "
      "PlungerGate)\n");
  printf("  --help             Show this help message\n");
}

Args parse_args(int argc, char* argv[]) {
  Args args;
  args.output_file = "connection_serialized.json";
  args.gate_name   = "CrossPlatformTestGate";
  args.gate_type   = "PlungerGate";

  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "--output") == 0 && i + 1 < argc) {
      args.output_file = argv[++i];
    } else if (strcmp(argv[i], "--name") == 0 && i + 1 < argc) {
      args.gate_name = argv[++i];
    } else if (strcmp(argv[i], "--type") == 0 && i + 1 < argc) {
      args.gate_type = argv[++i];
    } else if (strcmp(argv[i], "--help") == 0) {
      print_usage(argv[0]);
      exit(0);
    }
  }

  return args;
}

int main(int argc, char* argv[]) {
  Args args = parse_args(argc, argv);

  printf("=== Cross-Platform Serialization Integration Test (C-API) ===\n");
  printf("Mode: SERIALIZE\n");
  printf("Output file: %s\n", args.output_file);
  printf("Gate name: %s\n", args.gate_name);
  printf("Gate type: %s\n", args.gate_type);
  printf("==============================================================\n\n");

  // Create string handle for gate name
  StringHandle name_handle = String_wrap(args.gate_name);
  if (!name_handle) {
    fprintf(stderr, "ERROR: Failed to create string handle\n");
    return 1;
  }

  // Create Connection based on type
  ConnectionHandle connection = NULL;
  if (strcmp(args.gate_type, "PlungerGate") == 0) {
    connection = Connection_create_plunger_gate(name_handle);
  } else if (strcmp(args.gate_type, "BarrierGate") == 0) {
    connection = Connection_create_barrier_gate(name_handle);
  } else if (strcmp(args.gate_type, "ReservoirGate") == 0) {
    connection = Connection_create_reservoir_gate(name_handle);
  } else if (strcmp(args.gate_type, "ScreeningGate") == 0) {
    connection = Connection_create_screening_gate(name_handle);
  } else if (strcmp(args.gate_type, "Ohmic") == 0) {
    connection = Connection_create_ohmic(name_handle);
  } else {
    fprintf(stderr, "ERROR: Unknown gate type '%s'\n", args.gate_type);
    fprintf(stderr,
            "Valid types: PlungerGate, BarrierGate, ReservoirGate, "
            "ScreeningGate, Ohmic\n");
    String_destroy(name_handle);
    return 1;
  }

  if (!connection) {
    fprintf(stderr, "ERROR: Failed to create connection\n");
    String_destroy(name_handle);
    return 1;
  }

  // Get connection info
  StringHandle type_handle = Connection_type(connection);
  StringHandle conn_name   = Connection_name(connection);

  if (type_handle && conn_name) {
    printf("Created %.*s with name '%.*s'\n",
           (int)type_handle->length,
           type_handle->raw,
           (int)conn_name->length,
           conn_name->raw);
  }

  // Serialize using to_json_string
  StringHandle json_handle = Connection_to_json_string(connection);
  if (!json_handle) {
    fprintf(stderr, "ERROR: Serialization failed\n");
    Connection_destroy(connection);
    String_destroy(name_handle);
    if (type_handle) String_destroy(type_handle);
    if (conn_name) String_destroy(conn_name);
    return 1;
  }

  printf("Serialized to JSON (%zu bytes)\n", json_handle->length);

  // Write to file
  FILE* file = fopen(args.output_file, "w");
  if (!file) {
    fprintf(
        stderr, "ERROR: Could not open output file '%s'\n", args.output_file);
    String_destroy(json_handle);
    Connection_destroy(connection);
    String_destroy(name_handle);
    if (type_handle) String_destroy(type_handle);
    if (conn_name) String_destroy(conn_name);
    return 1;
  }

  size_t written = fwrite(json_handle->raw, 1, json_handle->length, file);
  fclose(file);

  if (written != json_handle->length) {
    fprintf(stderr, "ERROR: Failed to write complete file\n");
    String_destroy(json_handle);
    Connection_destroy(connection);
    String_destroy(name_handle);
    if (type_handle) String_destroy(type_handle);
    if (conn_name) String_destroy(conn_name);
    return 1;
  }

  printf("Successfully wrote JSON to '%s'\n", args.output_file);

  // Cleanup
  String_destroy(json_handle);
  Connection_destroy(connection);
  String_destroy(name_handle);
  if (type_handle) String_destroy(type_handle);
  if (conn_name) String_destroy(conn_name);

  printf("\n✓ Serialization completed successfully\n");
  printf("Platform: ");
#ifdef _WIN32
  printf("Windows\n");
#elif __linux__
  printf("Linux\n");
#elif __APPLE__
  printf("macOS\n");
#else
  printf("Unknown\n");
#endif

  return 0;
}
