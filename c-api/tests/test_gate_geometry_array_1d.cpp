#include <gtest/gtest.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/config/geometries/DotGateWithNeighbors_c_api.h"
#include "falcon_core/physics/config/geometries/DotGatesWithNeighbors_c_api.h"
#include "falcon_core/physics/config/geometries/GateGeometryArray1D_c_api.h"
#include "falcon_core/physics/config/geometries/LeftReservoirWithImplantedOhmic_c_api.h"
#include "falcon_core/physics/config/geometries/RightReservoirWithImplantedOhmic_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/device_structures/Connections_c_api.h"

class GateGeometryArray1DTest : public ::testing::Test {
 protected:
  ConnectionsHandle         linear;
  ConnectionsHandle         screening;
  GateGeometryArray1DHandle handle;

  void SetUp() override {
    linear = Connections_create_empty();
    Connections_push_back(linear, Connection_create_ohmic(String_wrap("O1")));
    Connections_push_back(linear,
                          Connection_create_reservoir_gate(String_wrap("R1")));
    Connections_push_back(linear,
                          Connection_create_barrier_gate(String_wrap("B1")));
    Connections_push_back(linear,
                          Connection_create_plunger_gate(String_wrap("P1")));
    Connections_push_back(linear,
                          Connection_create_barrier_gate(String_wrap("B2")));
    Connections_push_back(linear,
                          Connection_create_reservoir_gate(String_wrap("R2")));
    Connections_push_back(linear, Connection_create_ohmic(String_wrap("O2")));

    screening = Connections_create_empty();
    Connections_push_back(screening,
                          Connection_create_screening_gate(String_wrap("S1")));
    Connections_push_back(screening,
                          Connection_create_screening_gate(String_wrap("S2")));

    handle = GateGeometryArray1D_create(linear, screening);
  }

  void TearDown() override {
    GateGeometryArray1D_destroy(handle);
    Connections_destroy(linear);
    Connections_destroy(screening);
  }
};

TEST_F(GateGeometryArray1DTest, AllDotGates) {
  DotGatesWithNeighborsHandle dots = GateGeometryArray1D_all_dot_gates(handle);
  EXPECT_EQ(DotGatesWithNeighbors_size(dots), 3);
  DotGatesWithNeighbors_destroy(dots);
}

TEST_F(GateGeometryArray1DTest, QueryNeighbors) {
  ConnectionHandle  gate = Connection_create_plunger_gate(String_wrap("P1"));
  ConnectionsHandle neighbors =
      GateGeometryArray1D_query_neighbors(handle, gate);
  EXPECT_GT(Connections_size(neighbors), 0);
  Connection_destroy(gate);
  Connections_destroy(neighbors);
}

TEST_F(GateGeometryArray1DTest, LeftReservoir) {
  LeftReservoirWithImplantedOhmicHandle left =
      GateGeometryArray1D_left_reservoir(handle);
  EXPECT_FALSE(left == nullptr);
  LeftReservoirWithImplantedOhmic_destroy(left);
}

TEST_F(GateGeometryArray1DTest, RightReservoir) {
  RightReservoirWithImplantedOhmicHandle right =
      GateGeometryArray1D_right_reservoir(handle);
  EXPECT_FALSE(right == nullptr);
  RightReservoirWithImplantedOhmic_destroy(right);
}

TEST_F(GateGeometryArray1DTest, LeftBarrier) {
  DotGateWithNeighborsHandle left_barrier =
      GateGeometryArray1D_left_barrier(handle);
  EXPECT_FALSE(left_barrier == nullptr);
  DotGateWithNeighbors_destroy(left_barrier);
}

TEST_F(GateGeometryArray1DTest, RightBarrier) {
  DotGateWithNeighborsHandle right_barrier =
      GateGeometryArray1D_right_barrier(handle);
  EXPECT_FALSE(right_barrier == nullptr);
  DotGateWithNeighbors_destroy(right_barrier);
}

TEST_F(GateGeometryArray1DTest, LineararrayGetter) {
  ConnectionsHandle result = GateGeometryArray1D_lineararray(handle);
  EXPECT_EQ(Connections_size(result), 7);
  Connections_destroy(result);
}

TEST_F(GateGeometryArray1DTest, ScreeningGatesGetter) {
  ConnectionsHandle result = GateGeometryArray1D_screening_gates(handle);
  EXPECT_EQ(Connections_size(result), 2);
  Connections_destroy(result);
}

TEST_F(GateGeometryArray1DTest, RawCentralGatesGetter) {
  ConnectionsHandle result = GateGeometryArray1D_raw_central_gates(handle);
  EXPECT_EQ(Connections_size(result), 3);
  Connections_destroy(result);
}

TEST_F(GateGeometryArray1DTest, CentralDotGatesGetter) {
  DotGatesWithNeighborsHandle result =
      GateGeometryArray1D_central_dot_gates(handle);
  EXPECT_EQ(DotGatesWithNeighbors_size(result), 1);
  DotGatesWithNeighbors_destroy(result);
}

TEST_F(GateGeometryArray1DTest, OhmicsGetter) {
  ConnectionsHandle result = GateGeometryArray1D_ohmics(handle);
  EXPECT_EQ(DotGatesWithNeighbors_size(result), 2);
  DotGatesWithNeighbors_destroy(result);
}

TEST_F(GateGeometryArray1DTest, EqualityAndInequality) {
  GateGeometryArray1DHandle handle2 =
      GateGeometryArray1D_create(linear, screening);
  EXPECT_TRUE(GateGeometryArray1D_equal(handle, handle2));
  EXPECT_FALSE(GateGeometryArray1D_not_equal(handle, handle2));
  GateGeometryArray1D_destroy(handle2);
}

TEST_F(GateGeometryArray1DTest, SerializationRoundTrip) {
  StringHandle              json   = GateGeometryArray1D_to_json_string(handle);
  GateGeometryArray1DHandle loaded = GateGeometryArray1D_from_json_string(json);
  EXPECT_TRUE(GateGeometryArray1D_equal(handle, loaded));
  GateGeometryArray1D_destroy(loaded);
  String_destroy(json);
}

TEST_F(GateGeometryArray1DTest, AppendCentralGateValid) {
  ConnectionHandle left     = Connection_create_barrier_gate(String_wrap("B1"));
  ConnectionHandle selected = Connection_create_plunger_gate(String_wrap("P1"));
  ConnectionHandle right    = Connection_create_barrier_gate(String_wrap("B2"));
  EXPECT_NO_THROW(
      GateGeometryArray1D_append_central_gate(handle, left, selected, right));
  Connection_destroy(left);
  Connection_destroy(selected);
  Connection_destroy(right);
}
