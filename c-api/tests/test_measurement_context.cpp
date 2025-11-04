#include <gtest/gtest.h>

#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"

class MeasurementContextTest : public ::testing::Test {
 protected:
  void SetUp() override {
    conn = Connection_create_barrier_gate(String_wrap("A"));
    port = InstrumentPort_create_port(String_wrap("P1"));
    mc   = MeasurementContext_create(conn, "oscilloscope");
    mc2  = MeasurementContext_create_from_port(port);
  }
  void TearDown() override {
    MeasurementContext_destroy(mc);
    MeasurementContext_destroy(mc2);
    Connection_destroy(conn);
    InstrumentPort_destroy(port);
  }
  ConnectionHandle         conn = nullptr;
  InstrumentPortHandle     port = nullptr;
  MeasurementContextHandle mc   = nullptr;
  MeasurementContextHandle mc2  = nullptr;
};

TEST_F(MeasurementContextTest, CreateDestroy) {
  auto m = MeasurementContext_create(conn, "multimeter");
  MeasurementContext_destroy(m);
  auto m2 = MeasurementContext_create_from_port(port);
  MeasurementContext_destroy(m2);
  EXPECT_THROW(MeasurementContext_create(nullptr, "oscilloscope"),
               std::invalid_argument);
  EXPECT_THROW(MeasurementContext_create(conn, nullptr), std::invalid_argument);
  EXPECT_THROW(MeasurementContext_create_from_port(nullptr),
               std::invalid_argument);
  EXPECT_THROW(MeasurementContext_destroy(nullptr), std::invalid_argument);
}

TEST_F(MeasurementContextTest, Accessors) {
  auto c = MeasurementContext_connection(mc);
  auto t = MeasurementContext_instrument_type(mc);
  Connection_destroy(c);
  String_destroy(t);
  EXPECT_THROW(MeasurementContext_connection(nullptr), std::invalid_argument);
  EXPECT_THROW(MeasurementContext_instrument_type(nullptr),
               std::invalid_argument);
}

TEST_F(MeasurementContextTest, EqualityOperators) {
  EXPECT_FALSE(MeasurementContext_equal(mc, mc2));
  EXPECT_TRUE(MeasurementContext_not_equal(mc, mc2));
  EXPECT_THROW(MeasurementContext_equal(nullptr, mc2), std::invalid_argument);
  EXPECT_THROW(MeasurementContext_equal(mc, nullptr), std::invalid_argument);
  EXPECT_THROW(MeasurementContext_not_equal(nullptr, mc2),
               std::invalid_argument);
  EXPECT_THROW(MeasurementContext_not_equal(mc, nullptr),
               std::invalid_argument);
}

TEST_F(MeasurementContextTest, ToJsonFromJson) {
  auto json = MeasurementContext_to_json_string(mc);
  auto mc3  = MeasurementContext_from_json_string(json);
  EXPECT_TRUE(MeasurementContext_equal(mc, mc3));
  MeasurementContext_destroy(mc3);
  String_destroy(json);
  EXPECT_THROW(MeasurementContext_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(MeasurementContext_from_json_string(nullptr),
               std::invalid_argument);
}
