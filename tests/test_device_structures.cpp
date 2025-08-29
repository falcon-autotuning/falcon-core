#include <gtest/gtest.h>

#include "falcon_core/physics/device_structures/BarrierGates.hpp"
namespace tests {
using namespace falcon_core::physics::device_structures;

// Test BaseConnection serialization
TEST(DeviceStructuresTest, BaseConnectionSerializationRoundTrip) {
  auto conn = std::make_shared<BaseConnection>("X1");

  std::string json = conn->to_json_string();
  std::cout << "Serialized BaseConnection JSON:\n" << json << std::endl;

  auto conn2 = BaseConnection::from_json_string<BaseConnection>(json);

  ASSERT_EQ(conn2->name(), "X1");
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

// Test construction from vector for plural device structure types
TEST(DeviceStructuresPluralTest, ConstructFromVector_BaseConnections) {
  auto conn1 = std::make_shared<BaseConnection>("C1");
  auto conn2 = std::make_shared<BaseConnection>("C2");
  std::vector<std::shared_ptr<BaseConnection>> vec{conn1, conn2};

  auto connections = std::make_shared<BaseConnections<BaseConnection>>(vec);

  ASSERT_EQ(connections->size(), 2);
  ASSERT_EQ(connections->at(0)->name(), "C1");
  ASSERT_EQ(connections->at(1)->name(), "C2");
}

TEST(DeviceStructuresPluralTest, ConstructFromVector_Gates) {
  auto                               dot1 = std::make_shared<Gate>("D1");
  auto                               dot2 = std::make_shared<Gate>("D2");
  std::vector<std::shared_ptr<Gate>> vec{dot1, dot2};

  auto        dots = std::make_shared<Gates<Gate>>(vec);
  std::string json = dots->to_json_string();
  std::cout << "Serialized DotGates JSON:\n" << json << std::endl;

  ASSERT_EQ(dots->size(), 2);
  ASSERT_EQ(dots->at(0)->name(), "D1");
  ASSERT_EQ(dots->at(1)->name(), "D2");
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

TEST(DeviceStructuresPluralTest, ConstructFromVector_DotGates) {
  auto                                  dot1 = std::make_shared<DotGate>("D1");
  auto                                  dot2 = std::make_shared<DotGate>("D2");
  std::vector<std::shared_ptr<DotGate>> vec{dot1, dot2};

  auto dots = std::make_shared<DotGates<DotGate>>(vec);

  ASSERT_EQ(dots->size(), 2);
  ASSERT_EQ(dots->at(0)->name(), "D1");
  ASSERT_EQ(dots->at(1)->name(), "D2");
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
  auto connections = std::make_shared<BaseConnections<BaseConnection>>();
  connections->push_back(std::make_shared<BaseConnection>("C1"));
  connections->push_back(std::make_shared<BaseConnection>("C2"));

  std::string json = connections->to_json_string();
  std::cout << "Serialized BaseConnections JSON:\n" << json << std::endl;

  auto connections2 = BaseConnections<BaseConnection>::from_json_string<
      BaseConnections<BaseConnection>>(json);

  ASSERT_EQ(connections2->size(), 2);
  ASSERT_EQ(connections2->at(0)->name(), "C1");
  ASSERT_EQ(connections2->at(1)->name(), "C2");
}
}  // namespace tests
