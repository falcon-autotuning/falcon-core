#include <gtest/gtest.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/config/geometries/RightReservoirWithImplantedOhmic_c_api.h"
#include "falcon_core/physics/device_structures/Connection.hpp"

using namespace falcon_core::physics::device_structures;

class RightReservoirWithImplantedOhmicTest : public ::testing::Test {
 protected:
  StringHandle                           name;
  ConnectionHandle                       left;
  ConnectionHandle                       ohmic;
  RightReservoirWithImplantedOhmicHandle handle;

  void SetUp() override {
    name   = String_create("right", 5);
    left   = new Connection(*Connection::BarrierGate("left"));
    ohmic  = new Connection(*Connection::Ohmic("ohmic"));
    handle = RightReservoirWithImplantedOhmic_create(name, left, ohmic);
  }

  void TearDown() override {
    RightReservoirWithImplantedOhmic_destroy(handle);
    delete static_cast<Connection*>(left);
    delete static_cast<Connection*>(ohmic);
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
  EXPECT_EQ(static_cast<Connection*>(ohmic_result)->name(), "ohmic");
  delete static_cast<Connection*>(ohmic_result);
}

TEST_F(RightReservoirWithImplantedOhmicTest, LeftNeighborGetter) {
  ConnectionHandle left_result =
      RightReservoirWithImplantedOhmic_left_neighbor(handle);
  EXPECT_EQ(static_cast<Connection*>(left_result)->name(), "left");
  delete static_cast<Connection*>(left_result);
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

TEST_F(RightReservoirWithImplantedOhmicTest, ThrowsOnNullLeftNeighbor) {
  EXPECT_THROW(RightReservoirWithImplantedOhmic_create(name, nullptr, ohmic),
               std::invalid_argument);
}

TEST_F(RightReservoirWithImplantedOhmicTest, ThrowsOnNullOhmic) {
  EXPECT_THROW(RightReservoirWithImplantedOhmic_create(name, left, nullptr),
               std::invalid_argument);
}
