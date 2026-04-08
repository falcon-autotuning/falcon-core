#include <gtest/gtest.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"
#include "falcon-core/generic/ErrorHandling_c_api.h"

#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/physics/config/geometries/RightReservoirWithImplantedOhmic_c_api.h"
#include "falcon-core/physics/device_structures/Connection_c_api.h"

class RightReservoirWithImplantedOhmicTest : public ::testing::Test {
 protected:
  StringHandle                           name;
  ConnectionHandle                       left;
  ConnectionHandle                       ohmic;
  RightReservoirWithImplantedOhmicHandle handle;

  void SetUp() override {
    name   = String_create("right", 5);
    left   = Connection_create_barrier_gate(String_wrap("left"));
    ohmic  = Connection_create_ohmic(String_wrap("ohmic"));
    handle = RightReservoirWithImplantedOhmic_create(name, left, ohmic);
  }

  void TearDown() override {
    RightReservoirWithImplantedOhmic_destroy(handle);
    Connection_destroy(left);
    Connection_destroy(ohmic);
    String_destroy(name);
  }
};

TEST_F(RightReservoirWithImplantedOhmicTest, NameGetter) {
  StringHandle result = RightReservoirWithImplantedOhmic_name(handle);
  EXPECT_EQ(std::string(result->raw, result->length), "right");
  String_destroy(result);
}

TEST_F(RightReservoirWithImplantedOhmicTest, TypeGetter) {
  StringHandle result = RightReservoirWithImplantedOhmic_type(handle);
  EXPECT_FALSE(std::string(result->raw, result->length).empty());
  String_destroy(result);
}

TEST_F(RightReservoirWithImplantedOhmicTest, OhmicGetter) {
  ConnectionHandle ohmic_result =
      RightReservoirWithImplantedOhmic_ohmic(handle);
  StringHandle stringConnection_name = Connection_name(ohmic_result);
  EXPECT_EQ(
      std::string(stringConnection_name->raw, stringConnection_name->length),
      "ohmic");
  Connection_destroy(ohmic_result);
  String_destroy(stringConnection_name);
}

TEST_F(RightReservoirWithImplantedOhmicTest, LeftNeighborGetter) {
  ConnectionHandle left_result =
      RightReservoirWithImplantedOhmic_left_neighbor(handle);
  StringHandle stringConnection_name = Connection_name(left_result);
  EXPECT_EQ(
      std::string(stringConnection_name->raw, stringConnection_name->length),
      "left");
  Connection_destroy(left_result);
  String_destroy(stringConnection_name);
}

TEST_F(RightReservoirWithImplantedOhmicTest, Equality) {
  RightReservoirWithImplantedOhmicHandle handle2 =
      RightReservoirWithImplantedOhmic_create(name, left, ohmic);
  EXPECT_TRUE(RightReservoirWithImplantedOhmic_equal(handle, handle2));
  EXPECT_FALSE(RightReservoirWithImplantedOhmic_not_equal(handle, handle2));
  RightReservoirWithImplantedOhmic_destroy(handle2);
}

TEST_F(RightReservoirWithImplantedOhmicTest, SerializationRoundTrip) {
  StringHandle json = RightReservoirWithImplantedOhmic_to_json_string(handle);
  RightReservoirWithImplantedOhmicHandle copy =
      RightReservoirWithImplantedOhmic_from_json_string(json);
  EXPECT_TRUE(RightReservoirWithImplantedOhmic_equal(handle, copy));
  RightReservoirWithImplantedOhmic_destroy(copy);
  String_destroy(json);
}

TEST_F(RightReservoirWithImplantedOhmicTest, ThrowsOnNullCreate) {
  set_last_error(0, nullptr);
  RightReservoirWithImplantedOhmic_create(name, nullptr, ohmic);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  RightReservoirWithImplantedOhmic_create(name, left, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  RightReservoirWithImplantedOhmic_create(nullptr, left, ohmic);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(RightReservoirWithImplantedOhmicTest, DestructorThrowsOnNull) {
  set_last_error(0, nullptr);
  RightReservoirWithImplantedOhmic_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(RightReservoirWithImplantedOhmicTest, ThrowsOnNullHandleInGetters) {
  set_last_error(0, nullptr);
  RightReservoirWithImplantedOhmic_name(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  RightReservoirWithImplantedOhmic_type(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  RightReservoirWithImplantedOhmic_ohmic(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  RightReservoirWithImplantedOhmic_left_neighbor(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(RightReservoirWithImplantedOhmicTest, ThrowsOnNullHandleInEquality) {
  set_last_error(0, nullptr);
  RightReservoirWithImplantedOhmic_equal(nullptr, handle);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  RightReservoirWithImplantedOhmic_equal(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  RightReservoirWithImplantedOhmic_not_equal(nullptr, handle);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  RightReservoirWithImplantedOhmic_not_equal(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(RightReservoirWithImplantedOhmicTest,
       ThrowsOnNullHandleInSerialization) {
  set_last_error(0, nullptr);
  RightReservoirWithImplantedOhmic_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  RightReservoirWithImplantedOhmic_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
