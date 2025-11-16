#include <gtest/gtest.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/config/geometries/LeftReservoirWithImplantedOhmic_c_api.h"

class LeftReservoirWithImplantedOhmicTest : public ::testing::Test {
 protected:
  StringHandle                          name;
  ConnectionHandle                      right;
  ConnectionHandle                      ohmic;
  LeftReservoirWithImplantedOhmicHandle handle;

  void SetUp() override {
    name   = String_create("left", 4);
    right  = Connection_create_barrier_gate(String_wrap("right"));
    ohmic  = Connection_create_ohmic(String_wrap("ohmic"));
    handle = LeftReservoirWithImplantedOhmic_create(name, right, ohmic);
  }

  void TearDown() override {
    LeftReservoirWithImplantedOhmic_destroy(handle);
    Connection_destroy(right);
    Connection_destroy(ohmic);
    String_destroy(name);
  }
};

TEST_F(LeftReservoirWithImplantedOhmicTest, NameGetter) {
  StringHandle result = LeftReservoirWithImplantedOhmic_name(handle);
  EXPECT_EQ(std::string(result->raw, result->length), "left");
  String_destroy(result);
}

TEST_F(LeftReservoirWithImplantedOhmicTest, TypeGetter) {
  StringHandle result = LeftReservoirWithImplantedOhmic_type(handle);
  EXPECT_FALSE(std::string(result->raw, result->length).empty());
  String_destroy(result);
}

TEST_F(LeftReservoirWithImplantedOhmicTest, OhmicGetter) {
  ConnectionHandle ohmic_result = LeftReservoirWithImplantedOhmic_ohmic(handle);
  StringHandle     stringConnection_name = Connection_name(ohmic_result);
  EXPECT_EQ(
      std::string(stringConnection_name->raw, stringConnection_name->length),
      "ohmic");
  Connection_destroy(ohmic_result);
  String_destroy(stringConnection_name);
}

TEST_F(LeftReservoirWithImplantedOhmicTest, RightNeighborGetter) {
  ConnectionHandle right_result =
      LeftReservoirWithImplantedOhmic_right_neighbor(handle);
  StringHandle stringConnection_name = Connection_name(right_result);
  EXPECT_EQ(
      std::string(stringConnection_name->raw, stringConnection_name->length),
      "right");
  Connection_destroy(right_result);
  String_destroy(stringConnection_name);
}

TEST_F(LeftReservoirWithImplantedOhmicTest, Equality) {
  LeftReservoirWithImplantedOhmicHandle handle2 =
      LeftReservoirWithImplantedOhmic_create(name, right, ohmic);
  EXPECT_TRUE(LeftReservoirWithImplantedOhmic_equal(handle, handle2));
  EXPECT_FALSE(LeftReservoirWithImplantedOhmic_not_equal(handle, handle2));
  LeftReservoirWithImplantedOhmic_destroy(handle2);
}

TEST_F(LeftReservoirWithImplantedOhmicTest, SerializationRoundTrip) {
  StringHandle json = LeftReservoirWithImplantedOhmic_to_json_string(handle);
  LeftReservoirWithImplantedOhmicHandle copy =
      LeftReservoirWithImplantedOhmic_from_json_string(json);
  EXPECT_TRUE(LeftReservoirWithImplantedOhmic_equal(handle, copy));
  LeftReservoirWithImplantedOhmic_destroy(copy);
  String_destroy(json);
}

TEST_F(LeftReservoirWithImplantedOhmicTest, ThrowsOnNullRightNeighbor) {
  set_last_error(0, nullptr);
  LeftReservoirWithImplantedOhmic_create(name, nullptr, ohmic);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LeftReservoirWithImplantedOhmicTest, ThrowsOnNullOhmic) {
  set_last_error(0, nullptr);
  LeftReservoirWithImplantedOhmic_create(name, right, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LeftReservoirWithImplantedOhmicTest, ThrowsOnNullName) {
  set_last_error(0, nullptr);
  LeftReservoirWithImplantedOhmic_create(nullptr, right, ohmic);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LeftReservoirWithImplantedOhmicTest, DestructorThrowsOnNullptr) {
  set_last_error(0, nullptr);
  LeftReservoirWithImplantedOhmic_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LeftReservoirWithImplantedOhmicTest, NameGetterWorksAfterSerialization) {
  StringHandle json = LeftReservoirWithImplantedOhmic_to_json_string(handle);
  LeftReservoirWithImplantedOhmicHandle copy =
      LeftReservoirWithImplantedOhmic_from_json_string(json);
  StringHandle result = LeftReservoirWithImplantedOhmic_name(copy);
  EXPECT_EQ(std::string(result->raw, result->length), "left");
  String_destroy(result);
  LeftReservoirWithImplantedOhmic_destroy(copy);
  String_destroy(json);
}

TEST_F(LeftReservoirWithImplantedOhmicTest, TypeGetterWorksAfterSerialization) {
  StringHandle json = LeftReservoirWithImplantedOhmic_to_json_string(handle);
  LeftReservoirWithImplantedOhmicHandle copy =
      LeftReservoirWithImplantedOhmic_from_json_string(json);
  StringHandle result = LeftReservoirWithImplantedOhmic_type(copy);
  EXPECT_FALSE(std::string(result->raw, result->length).empty());
  String_destroy(result);
  LeftReservoirWithImplantedOhmic_destroy(copy);
  String_destroy(json);
}

TEST_F(LeftReservoirWithImplantedOhmicTest, NullptrThrows) {
  set_last_error(0, nullptr);
  LeftReservoirWithImplantedOhmic_name(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LeftReservoirWithImplantedOhmic_type(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LeftReservoirWithImplantedOhmic_ohmic(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LeftReservoirWithImplantedOhmic_right_neighbor(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LeftReservoirWithImplantedOhmic_equal(nullptr, handle);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LeftReservoirWithImplantedOhmic_equal(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LeftReservoirWithImplantedOhmic_not_equal(nullptr, handle);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LeftReservoirWithImplantedOhmic_not_equal(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LeftReservoirWithImplantedOhmic_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LeftReservoirWithImplantedOhmic_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
