#include <gtest/gtest.h>

#include "falcon-core/generic/ErrorHandling_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/physics/config/geometries/DotGateWithNeighbors_c_api.h"
#include "falcon-core/physics/device_structures/Connection_c_api.h"

class DotGateWithNeighborsTest : public ::testing::Test {
 protected:
  StringHandle               name;
  ConnectionHandle           left;
  ConnectionHandle           right;
  DotGateWithNeighborsHandle handle;

  void SetUp() override {
    name   = String_create("center", 6);
    left   = Connection_create_barrier_gate(String_wrap("left"));
    right  = Connection_create_barrier_gate(String_wrap("right"));
    handle = DotGateWithNeighbors_create_plunger_gate_with_neighbors(
        name, left, right);
  }

  void TearDown() override {
    DotGateWithNeighbors_destroy(handle);
    Connection_destroy(left);
    Connection_destroy(right);
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
  StringHandle     stringConnection_name = Connection_name(left_result);
  EXPECT_EQ(
      std::string(stringConnection_name->raw, stringConnection_name->length),
      "left");
  Connection_destroy(left_result);
  String_destroy(stringConnection_name);
}

TEST_F(DotGateWithNeighborsTest, RightNeighborGetter) {
  ConnectionHandle right_result = DotGateWithNeighbors_right_neighbor(handle);
  StringHandle     stringConnection_name = Connection_name(right_result);
  EXPECT_EQ(
      std::string(stringConnection_name->raw, stringConnection_name->length),
      "right");
  Connection_destroy(right_result);
  String_destroy(stringConnection_name);
}

TEST_F(DotGateWithNeighborsTest, IsPlungerGate) {
  EXPECT_TRUE(DotGateWithNeighbors_is_plunger_gate(handle));
  EXPECT_FALSE(DotGateWithNeighbors_is_barrier_gate(handle));
}

TEST_F(DotGateWithNeighborsTest, Equality) {
  DotGateWithNeighborsHandle handle2 =
      DotGateWithNeighbors_create_plunger_gate_with_neighbors(
          name, left, right);
  EXPECT_TRUE(DotGateWithNeighbors_equal(handle, handle2));
  EXPECT_FALSE(DotGateWithNeighbors_not_equal(handle, handle2));
  DotGateWithNeighbors_destroy(handle2);
}

TEST_F(DotGateWithNeighborsTest, InEqualDifferentLeft) {
  ConnectionHandle left2 = Connection_create_barrier_gate(String_wrap("left2"));
  DotGateWithNeighborsHandle handle2 =
      DotGateWithNeighbors_create_plunger_gate_with_neighbors(
          name, left2, right);
  EXPECT_FALSE(DotGateWithNeighbors_equal(handle, handle2));
  EXPECT_TRUE(DotGateWithNeighbors_not_equal(handle, handle2));
  DotGateWithNeighbors_destroy(handle2);
  Connection_destroy(left2);
}

TEST_F(DotGateWithNeighborsTest, InEqualDifferentRight) {
  ConnectionHandle right2 =
      Connection_create_barrier_gate(String_wrap("right2"));
  DotGateWithNeighborsHandle handle2 =
      DotGateWithNeighbors_create_plunger_gate_with_neighbors(
          name, left, right2);
  EXPECT_FALSE(DotGateWithNeighbors_equal(handle, handle2));
  EXPECT_TRUE(DotGateWithNeighbors_not_equal(handle, handle2));
  DotGateWithNeighbors_destroy(handle2);
  Connection_destroy(right2);
}

TEST_F(DotGateWithNeighborsTest, SerializationRoundTrip) {
  StringHandle               json = DotGateWithNeighbors_to_json_string(handle);
  DotGateWithNeighborsHandle copy = DotGateWithNeighbors_from_json_string(json);
  EXPECT_TRUE(DotGateWithNeighbors_equal(handle, copy));
  DotGateWithNeighbors_destroy(copy);
  String_destroy(json);
}

TEST_F(DotGateWithNeighborsTest, ThrowsOnNullLeftNeighbor) {
  set_last_error(0, nullptr);
  DotGateWithNeighbors_create_plunger_gate_with_neighbors(name, nullptr, right);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DotGateWithNeighborsTest, ThrowsOnNullRightNeighbor) {
  set_last_error(0, nullptr);
  DotGateWithNeighbors_create_plunger_gate_with_neighbors(name, left, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DotGateWithNeighborsTest, BarrierGateVariant) {
  ConnectionHandle left  = Connection_create_plunger_gate(String_wrap("left"));
  ConnectionHandle right = Connection_create_plunger_gate(String_wrap("right"));
  DotGateWithNeighborsHandle barrier_handle =
      DotGateWithNeighbors_create_barrier_gate_with_neighbors(
          name, left, right);
  EXPECT_TRUE(DotGateWithNeighbors_is_barrier_gate(barrier_handle));
  EXPECT_FALSE(DotGateWithNeighbors_is_plunger_gate(barrier_handle));
  DotGateWithNeighbors_destroy(barrier_handle);
  Connection_destroy(left);
  Connection_destroy(right);
}

TEST_F(DotGateWithNeighborsTest, DestructorThrowsOnNullptr) {
  set_last_error(0, nullptr);
  DotGateWithNeighbors_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DotGateWithNeighborsTest, NameGetterWorksAfterSerialization) {
  StringHandle               json = DotGateWithNeighbors_to_json_string(handle);
  DotGateWithNeighborsHandle copy = DotGateWithNeighbors_from_json_string(json);
  StringHandle               result = DotGateWithNeighbors_name(copy);
  EXPECT_EQ(std::string(result->raw, result->length), "center");
  DotGateWithNeighbors_destroy(copy);
  String_destroy(result);
  String_destroy(json);
}

TEST_F(DotGateWithNeighborsTest, TypeGetterWorksAfterSerialization) {
  StringHandle               json = DotGateWithNeighbors_to_json_string(handle);
  DotGateWithNeighborsHandle copy = DotGateWithNeighbors_from_json_string(json);
  StringHandle               result = DotGateWithNeighbors_type(copy);
  EXPECT_FALSE(std::string(result->raw, result->length).empty());
  DotGateWithNeighbors_destroy(copy);
  String_destroy(result);
  String_destroy(json);
}

TEST_F(DotGateWithNeighborsTest, NullptrThrows) {
  set_last_error(0, nullptr);
  DotGateWithNeighbors_name(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DotGateWithNeighbors_type(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DotGateWithNeighbors_left_neighbor(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DotGateWithNeighbors_right_neighbor(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DotGateWithNeighbors_is_plunger_gate(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DotGateWithNeighbors_is_barrier_gate(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DotGateWithNeighbors_equal(nullptr, handle);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DotGateWithNeighbors_equal(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DotGateWithNeighbors_not_equal(nullptr, handle);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DotGateWithNeighbors_not_equal(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DotGateWithNeighbors_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DotGateWithNeighbors_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DotGateWithNeighbors_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DotGateWithNeighbors_create_plunger_gate_with_neighbors(nullptr, left, right);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DotGateWithNeighbors_create_plunger_gate_with_neighbors(name, nullptr, right);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DotGateWithNeighbors_create_plunger_gate_with_neighbors(name, left, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DotGateWithNeighbors_create_barrier_gate_with_neighbors(nullptr, left, right);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DotGateWithNeighbors_create_barrier_gate_with_neighbors(name, nullptr, right);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DotGateWithNeighbors_create_barrier_gate_with_neighbors(name, left, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
