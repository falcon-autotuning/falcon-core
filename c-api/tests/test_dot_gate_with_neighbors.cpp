#include <gtest/gtest.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/config/geometries/DotGateWithNeighbors_c_api.h"
#include "falcon_core/physics/device_structures/Connection.hpp"

using namespace falcon_core::physics::device_structures;

class DotGateWithNeighborsTest : public ::testing::Test {
 protected:
  StringHandle               name;
  ConnectionHandle           left;
  ConnectionHandle           right;
  DotGateWithNeighborsHandle handle;

  void SetUp() override {
    name  = String_create("center", 6);
    left  = new Connection(*Connection::PlungerGate("left"));
    right = new Connection(*Connection::PlungerGate("right"));
    handle =
        DotGateWithNeighbors_create_plungergatewithneighbors(name, left, right);
  }

  void TearDown() override {
    DotGateWithNeighbors_destroy(handle);
    delete static_cast<Connection*>(left);
    delete static_cast<Connection*>(right);
    String_destroy(name);
  }
};

TEST_F(DotGateWithNeighborsTest, NameGetter) {
  StringHandle result = DotGateWithNeighbors_name(handle);
  EXPECT_EQ(std::string(result->raw, result->length), "center");
  String_destroy(result);
}

TEST_F(DotGateWithNeighborsTest, TypeGetter) {
  StringHandle result = DotGateWithNeighbors_type(handle);
  EXPECT_FALSE(std::string(result->raw, result->length).empty());
  String_destroy(result);
}

TEST_F(DotGateWithNeighborsTest, LeftNeighborGetter) {
  ConnectionHandle left_result = DotGateWithNeighbors_left_neighbor(handle);
  EXPECT_EQ(static_cast<Connection*>(left_result)->name(), "left");
  delete static_cast<Connection*>(left_result);
}

TEST_F(DotGateWithNeighborsTest, RightNeighborGetter) {
  ConnectionHandle right_result = DotGateWithNeighbors_right_neighbor(handle);
  EXPECT_EQ(static_cast<Connection*>(right_result)->name(), "right");
  delete static_cast<Connection*>(right_result);
}

TEST_F(DotGateWithNeighborsTest, IsPlungerGate) {
  EXPECT_TRUE(DotGateWithNeighbors_is_plunger_gate(handle));
  EXPECT_FALSE(DotGateWithNeighbors_is_barrier_gate(handle));
}

TEST_F(DotGateWithNeighborsTest, Equality) {
  DotGateWithNeighborsHandle handle2 =
      DotGateWithNeighbors_create_plungergatewithneighbors(name, left, right);
  EXPECT_TRUE(DotGateWithNeighbors_equal(handle, handle2));
  EXPECT_FALSE(DotGateWithNeighbors_not_equal(handle, handle2));
  DotGateWithNeighbors_destroy(handle2);
}

TEST_F(DotGateWithNeighborsTest, InequalityDifferentLeft) {
  ConnectionHandle left2 = new Connection(*Connection::PlungerGate("left2"));
  DotGateWithNeighborsHandle handle2 =
      DotGateWithNeighbors_create_plungergatewithneighbors(name, left2, right);
  EXPECT_FALSE(DotGateWithNeighbors_equal(handle, handle2));
  EXPECT_TRUE(DotGateWithNeighbors_not_equal(handle, handle2));
  DotGateWithNeighbors_destroy(handle2);
  delete static_cast<Connection*>(left2);
}

TEST_F(DotGateWithNeighborsTest, InequalityDifferentRight) {
  ConnectionHandle right2 = new Connection(*Connection::PlungerGate("right2"));
  DotGateWithNeighborsHandle handle2 =
      DotGateWithNeighbors_create_plungergatewithneighbors(name, left, right2);
  EXPECT_FALSE(DotGateWithNeighbors_equal(handle, handle2));
  EXPECT_TRUE(DotGateWithNeighbors_not_equal(handle, handle2));
  DotGateWithNeighbors_destroy(handle2);
  delete static_cast<Connection*>(right2);
}

TEST_F(DotGateWithNeighborsTest, SerializationRoundTrip) {
  StringHandle               json = DotGateWithNeighbors_to_json_string(handle);
  DotGateWithNeighborsHandle copy = DotGateWithNeighbors_from_json_string(json);
  EXPECT_TRUE(DotGateWithNeighbors_equal(handle, copy));
  DotGateWithNeighbors_destroy(copy);
  String_destroy(json);
}

TEST_F(DotGateWithNeighborsTest, ThrowsOnNullLeftNeighbor) {
  EXPECT_THROW(DotGateWithNeighbors_create_plungergatewithneighbors(
                   name, nullptr, right),
               std::invalid_argument);
}

TEST_F(DotGateWithNeighborsTest, ThrowsOnNullRightNeighbor) {
  EXPECT_THROW(
      DotGateWithNeighbors_create_plungergatewithneighbors(name, left, nullptr),
      std::invalid_argument);
}

TEST_F(DotGateWithNeighborsTest, BarrierGateVariant) {
  DotGateWithNeighborsHandle barrier_handle =
      DotGateWithNeighbors_create_barriergatewithneighbors(name, left, right);
  EXPECT_TRUE(DotGateWithNeighbors_is_barrier_gate(barrier_handle));
  EXPECT_FALSE(DotGateWithNeighbors_is_plunger_gate(barrier_handle));
  DotGateWithNeighbors_destroy(barrier_handle);
}
