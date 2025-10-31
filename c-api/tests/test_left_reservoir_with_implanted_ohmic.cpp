#include <gtest/gtest.h>

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
  EXPECT_EQ(Connection_name(ohmic_result), "ohmic");
  Connection_destroy(ohmic_result);
}

TEST_F(LeftReservoirWithImplantedOhmicTest, RightNeighborGetter) {
  ConnectionHandle right_result =
      LeftReservoirWithImplantedOhmic_right_neighbor(handle);
  EXPECT_EQ(Connection_name(right_result), "right");
  Connection_destroy(right_result);
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
  EXPECT_THROW(LeftReservoirWithImplantedOhmic_create(name, nullptr, ohmic),
               std::invalid_argument);
}

TEST_F(LeftReservoirWithImplantedOhmicTest, ThrowsOnNullOhmic) {
  EXPECT_THROW(LeftReservoirWithImplantedOhmic_create(name, right, nullptr),
               std::invalid_argument);
}
