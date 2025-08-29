#include <gtest/gtest.h>

#include "falcon_core/physics/device_structures/BarrierGate.hpp"
#include "falcon_core/physics/device_structures/BarrierGates.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/device_structures/Ohmic.hpp"
#include "falcon_core/physics/device_structures/Ohmics.hpp"
#include "falcon_core/physics/device_structures/PlungerGate.hpp"
#include "falcon_core/physics/device_structures/PlungerGates.hpp"
#include "falcon_core/physics/device_structures/ReservoirGate.hpp"
#include "falcon_core/physics/device_structures/ReservoirGates.hpp"
#include "falcon_core/physics/device_structures/ScreeningGate.hpp"
#include "falcon_core/physics/device_structures/ScreeningGates.hpp"
namespace tests {
using namespace falcon_core::physics::device_structures;

// Test BaseConnection serialization
TEST(DeviceStructuresTest, BaseConnectionSerializationRoundTrip) {
  auto conn =
      std::make_shared<BaseConnection>("X1", DeviceFeature::PlungerGate);

  std::string json = conn->to_json_string();
  std::cout << "Serialized BaseConnection JSON:\n" << json << std::endl;

  auto conn2 = BaseConnection::from_json_string<BaseConnection>(json);

  ASSERT_EQ(conn2->name(), "X1");
}

// Test BarrierGate serialization
TEST(DeviceStructuresTest, BarrierGateSerializationRoundTrip) {
  auto gate = std::make_shared<BarrierGate>("B1");

  std::string json = gate->to_json_string();
  std::cout << "Serialized BarrierGate JSON:\n" << json << std::endl;

  auto gate2 = BaseConnection::from_json_string<BarrierGate>(json);

  // Add more property checks if BarrierGate has properties
  ASSERT_TRUE(gate2 != nullptr);
}

// Test construction from vector for plural device structure types
TEST(DeviceStructuresPluralTest, ConstructFromVector_BaseConnections) {
  auto conn1 =
      std::make_shared<BaseConnection>("C1", DeviceFeature::PlungerGate);
  auto conn2 =
      std::make_shared<BaseConnection>("C2", DeviceFeature::PlungerGate);
  std::vector<std::shared_ptr<BaseConnection>> vec{conn1, conn2};

  auto connections = std::make_shared<BaseConnections>(vec);

  ASSERT_EQ(connections->size(), 2);
  ASSERT_EQ(connections->at(0)->name(), "C1");
  ASSERT_EQ(connections->at(1)->name(), "C2");
}

TEST(DeviceStructuresPluralTest, ConstructFromVector_BarrierGates) {
  auto gate1 = std::make_shared<BarrierGate>("B1");
  auto gate2 = std::make_shared<BarrierGate>("B2");
  std::vector<std::shared_ptr<BarrierGate>> vec{gate1, gate2};

  auto gates = std::make_shared<BarrierGates>(vec);

  ASSERT_EQ(gates->size(), 2);
  ASSERT_EQ(gates->at(0)->name(), "B1");
  ASSERT_EQ(gates->at(1)->name(), "B2");
}

// Test BarrierGates serialization
TEST(DeviceStructuresTest, BarrierGatesSerializationRoundTrip) {
  auto gates = std::make_shared<BarrierGates>();
  gates->push_back(std::make_shared<BarrierGate>("B1"));
  gates->push_back(std::make_shared<BarrierGate>("B2"));

  std::string json = gates->to_json_string();
  std::cout << "Serialized BarrierGates JSON:\n" << json << std::endl;

  auto gates2 = BarrierGates::from_json_string<BarrierGates>(json);

  ASSERT_EQ(gates2->size(), 2);
}

// Test BaseConnections serialization
TEST(DeviceStructuresTest, BaseConnectionsSerializationRoundTrip) {
  auto connections = std::make_shared<BaseConnections>();
  connections->push_back(
      std::make_shared<BaseConnection>("C1", DeviceFeature::PlungerGate));
  connections->push_back(
      std::make_shared<BaseConnection>("C2", DeviceFeature::PlungerGate));

  std::string json = connections->to_json_string();
  std::cout << "Serialized BaseConnections JSON:\n" << json << std::endl;

  auto connections2 = BaseConnections::from_json_string<BaseConnections>(json);

  ASSERT_EQ(connections2->size(), 2);
  ASSERT_EQ(connections2->at(0)->name(), "C1");
  ASSERT_EQ(connections2->at(1)->name(), "C2");
  ASSERT_TRUE(connections2->is_plunger_gates());
}
}  // namespace tests
