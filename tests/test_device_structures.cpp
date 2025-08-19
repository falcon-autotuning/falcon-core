#include <gtest/gtest.h>

#include <cereal/archives/json.hpp>
#include <cereal/types/memory.hpp>
#include <sstream>

#include "falcon_core/physics/device_structures/BarrierGate.hpp"
#include "falcon_core/physics/device_structures/BarrierGates.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/device_structures/DotGate.hpp"
#include "falcon_core/physics/device_structures/DotGates.hpp"

using namespace falcon_core::physics::device_structures;

// Test BaseConnection serialization
TEST(DeviceStructuresTest, BaseConnectionSerializationRoundTrip) {
  auto conn = std::make_shared<BaseConnection>("X1");

  std::string json = conn->to_json_string();
  std::cout << "Serialized BaseConnection JSON:\n" << json << std::endl;

  auto conn2 = BaseConnection::from_json_string<BaseConnection>(json);

  ASSERT_EQ(conn2->name(), "test_connection");
}

// Test DotGate serialization
TEST(DeviceStructuresTest, DotGateSerializationRoundTrip) {
  auto gate = std::make_shared<DotGate>("D1");

  std::string json = gate->to_json_string();
  std::cout << "Serialized DotGate JSON:\n" << json << std::endl;

  auto gate2 = DotGate::from_json_string<DotGate>(json);

  // Add more property checks if DotGate has properties
  ASSERT_TRUE(gate2 != nullptr);
}

// Test BarrierGate serialization
TEST(DeviceStructuresTest, BarrierGateSerializationRoundTrip) {
  auto gate = std::make_shared<BarrierGate>("B1");

  std::string json = gate->to_json_string();
  std::cout << "Serialized BarrierGate JSON:\n" << json << std::endl;

  auto gate2 = BarrierGate::from_json_string<BarrierGate>(json);

  // Add more property checks if BarrierGate has properties
  ASSERT_TRUE(gate2 != nullptr);
}

// Test DotGates serialization
TEST(DeviceStructuresTest, DotGatesSerializationRoundTrip) {
  auto gates = std::make_shared<DotGates<DotGate>>();
  gates->push_back(std::make_shared<DotGate>("D1"));
  gates->push_back(std::make_shared<DotGate>("D2"));

  std::string json = gates->to_json_string();
  std::cout << "Serialized DotGates JSON:\n" << json << std::endl;

  auto gates2 = DotGates<DotGate>::from_json_string<DotGates<DotGate>>(json);

  ASSERT_EQ(gates2->size(), 2);
}

// Test BarrierGates serialization
TEST(DeviceStructuresTest, BarrierGatesSerializationRoundTrip) {
  auto gates = std::make_shared<BarrierGates<BarrierGate>>();
  gates->push_back(std::make_shared<BarrierGate>("B1"));
  gates->push_back(std::make_shared<BarrierGate>("B2"));

  std::string json = gates->to_json_string();
  std::cout << "Serialized BarrierGates JSON:\n" << json << std::endl;

  auto gates2 =
      BarrierGates<BarrierGate>::from_json_string<BarrierGates<BarrierGate>>(
          json);

  ASSERT_EQ(gates2->size(), 2);
}
