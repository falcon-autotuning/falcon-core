#include <gtest/gtest.h>

#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/physics/device_structures/Connections.hpp"
namespace tests {
using namespace falcon_core::physics::device_structures;

// Test Connection serialization
TEST(DeviceStructuresTest, ConnectionSerializationRoundTrip) {
  ConnectionSP conn = Connection::PlungerGate("X1");

  std::string json = conn->to_json_string();
  std::cout << "Serialized Connection JSON:\n" << json << std::endl;

  auto conn2 = Connection::from_json_string<Connection>(json);

  ASSERT_EQ(conn2->name(), "X1");
}

// Test BarrierGate serialization
TEST(DeviceStructuresTest, BarrierGateSerializationRoundTrip) {
  ConnectionSP gate = Connection::BarrierGate("B1");

  std::string json = gate->to_json_string();
  std::cout << "Serialized BarrierGate JSON:\n" << json << std::endl;

  auto gate2 = Connection::from_json_string<Connection>(json);

  // Add more property checks if BarrierGate has properties
  ASSERT_TRUE(gate2 != nullptr);
}

// Test construction from vector for plural device structure types
TEST(DeviceStructuresPluralTest, ConstructFromVector_Connections) {
  auto conn1 = std::make_shared<Connection>("C1", DeviceFeature::PlungerGate);
  auto conn2 = std::make_shared<Connection>("C2", DeviceFeature::PlungerGate);
  std::vector<std::shared_ptr<Connection>> vec{conn1, conn2};

  auto connections = std::make_shared<Connections>(vec);

  ASSERT_EQ(connections->size(), 2);
  ASSERT_EQ(connections->at(0)->name(), "C1");
  ASSERT_EQ(connections->at(1)->name(), "C2");
}

TEST(DeviceStructuresPluralTest, ConstructFromVector_BarrierGates) {
  auto                      gate1 = Connection::BarrierGate("B1");
  auto                      gate2 = Connection::BarrierGate("B2");
  std::vector<ConnectionSP> vec{gate1, gate2};

  auto gates = std::make_shared<Connections>(vec);

  ASSERT_EQ(gates->size(), 2);
  ASSERT_EQ(gates->at(0)->name(), "B1");
  ASSERT_EQ(gates->at(1)->name(), "B2");
  ASSERT_TRUE(gates->is_barrier_gates());
}

// Test BarrierGates serialization
TEST(DeviceStructuresTest, BarrierGatesSerializationRoundTrip) {
  auto gates = std::make_shared<Connections>();
  gates->push_back(Connection::BarrierGate("B1"));
  gates->push_back(Connection::BarrierGate("B2"));

  std::string json = gates->to_json_string();
  std::cout << "Serialized BarrierGates JSON:\n" << json << std::endl;

  auto gates2 = Connections::from_json_string<Connections>(json);

  ASSERT_EQ(gates2->size(), 2);
}

// Test Connections serialization
TEST(DeviceStructuresTest, ConnectionsSerializationRoundTrip) {
  auto connections = std::make_shared<Connections>();
  connections->push_back(
      std::make_shared<Connection>("C1", DeviceFeature::PlungerGate));
  connections->push_back(
      std::make_shared<Connection>("C2", DeviceFeature::PlungerGate));

  std::string json = connections->to_json_string();
  std::cout << "Serialized Connections JSON:\n" << json << std::endl;

  auto connections2 = Connections::from_json_string<Connections>(json);

  ASSERT_EQ(connections2->size(), 2);
  ASSERT_EQ(connections2->at(0)->name(), "C1");
  ASSERT_EQ(connections2->at(1)->name(), "C2");
  ASSERT_TRUE(connections2->is_plunger_gates());
}
}  // namespace tests
