#include "falcon-core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include "falcon-core/generic/FArrayDouble_c_api.h"
#include "falcon-core/generic/PairFloatFloat_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/physics/config/core/Adjacency_c_api.h"
#include "falcon-core/physics/config/core/VoltageConstraints_c_api.h"

class VoltageConstraintsTest : public ::testing::Test {
protected:
  ConnectionsHandle indexes;
  int matrix_data[9] = {0, 1, 0, 1, 0, 1, 0, 1, 0};
  size_t matrix_shape[2] = {3, 3};
  AdjacencyHandle adjacency;
  double max_safe_diff;
  PairDoubleDoubleHandle bounds;
  VoltageConstraintsHandle handle;

  void SetUp() override {
    indexes = Connections_create_empty();
    Connections_push_back(indexes, Connection_create_ohmic(String_wrap("O1")));
    Connections_push_back(indexes,
                          Connection_create_reservoir_gate(String_wrap("R1")));
    Connections_push_back(indexes,
                          Connection_create_barrier_gate(String_wrap("B1")));
    adjacency = Adjacency_create(matrix_data, matrix_shape, 2, indexes);
    max_safe_diff = 1.5;
    bounds = PairDoubleDouble_create(0.0, 5.0);
    handle = VoltageConstraints_create(adjacency, max_safe_diff, bounds);
  }

  void TearDown() override {
    VoltageConstraints_destroy(handle);
    Adjacency_destroy(adjacency);
    Connections_destroy(indexes);
    PairDoubleDouble_destroy(bounds);
  }
};

TEST_F(VoltageConstraintsTest, MaxSafeDiffGetter) {
  double diff = VoltageConstraints_max_safe_diff(handle);
  EXPECT_EQ(diff, max_safe_diff);
}

TEST_F(VoltageConstraintsTest, MinBoundGetter) {
  double min_bound = VoltageConstraints_min_bound(handle);
  EXPECT_EQ(min_bound, 0.0);
}

TEST_F(VoltageConstraintsTest, MaxBoundGetter) {
  double max_bound = VoltageConstraints_max_bound(handle);
  EXPECT_EQ(max_bound, 5.0);
}

TEST_F(VoltageConstraintsTest, AdjacencyGetter) {
  AdjacencyHandle adj = VoltageConstraints_adjacency(handle);
  EXPECT_TRUE(Adjacency_equal(adjacency, adj));
  Adjacency_destroy(adj);
}

TEST_F(VoltageConstraintsTest, ComputeOneNeighborDomainRequest) {
  VoltageConstraintsHandle handle =
      VoltageConstraints_create(adjacency, max_safe_diff, bounds);
  DeviceVoltageStatesHandle current_state = DeviceVoltageStates_create_empty();
  DeviceVoltageStates_add_state(
      current_state,
      DeviceVoltageState_create(Connection_create_ohmic(String_wrap("O1")), 0.0,
                                SymbolUnit_create_volt()));
  DeviceVoltageStates_add_state(
      current_state, DeviceVoltageState_create(
                         Connection_create_reservoir_gate(String_wrap("R1")),
                         1.0, SymbolUnit_create_volt()));
  DeviceVoltageStates_add_state(
      current_state, DeviceVoltageState_create(
                         Connection_create_barrier_gate(String_wrap("B1")), 1.0,
                         SymbolUnit_create_volt()));
  PortsHandle ports = Ports_create_empty();
  Ports_push_back(ports,
                  InstrumentPort_create_meter(
                      String_wrap("ohmicTest"),
                      Connection_create_ohmic(String_wrap("O1")),
                      InstrumentTypes_amnmeter(), SymbolUnit_create_volt(),
                      String_wrap("ohmicTest")));
  auto maximal_domain =
      VoltageConstraints_compute_maximal_domain(handle, ports, current_state);
  EXPECT_NE(maximal_domain, nullptr) << "Maximal domain should not be null";
  int size = CoupledLabelledDomain_size(maximal_domain);
  EXPECT_EQ(size, 1) << "Unexpected number of domains in maximal domain. Got "
                     << std::to_string(size) << ", expected 1.";
  double lesser_bound = Domain_lesser_bound(LabelledDomain_domain(
      CoupledLabelledDomain_get_domain(maximal_domain, Ports_at(ports, 0))));
  EXPECT_DOUBLE_EQ(lesser_bound, 0.0) << "Unexpected lesser bound. Got " +
                                             std::to_string(lesser_bound) +
                                             ", expected 0.0.";
  double greater_bound = Domain_greater_bound(LabelledDomain_domain(
      CoupledLabelledDomain_get_domain(maximal_domain, Ports_at(ports, 0))));
  EXPECT_DOUBLE_EQ(greater_bound, 2.5) << "Unexpected greater bound. Got " +
                                              std::to_string(greater_bound) +
                                              ", expected 2.5.";
}

TEST_F(VoltageConstraintsTest, ValidateVoltageStateValid) {
  VoltageConstraintsHandle handle =
      VoltageConstraints_create(adjacency, max_safe_diff, bounds);
  DeviceVoltageStatesHandle voltage_state = DeviceVoltageStates_create_empty();
  DeviceVoltageStates_add_state(
      voltage_state,
      DeviceVoltageState_create(Connection_create_ohmic(String_wrap("O1")), 0.0,
                                SymbolUnit_create_volt()));
  DeviceVoltageStates_add_state(
      voltage_state, DeviceVoltageState_create(
                         Connection_create_reservoir_gate(String_wrap("R1")),
                         1.0, SymbolUnit_create_volt()));
  DeviceVoltageStates_add_state(
      voltage_state, DeviceVoltageState_create(
                         Connection_create_barrier_gate(String_wrap("B1")), 1.0,
                         SymbolUnit_create_volt()));
  EXPECT_TRUE(VoltageConstraints_validate_voltage_state(
      handle, DeviceVoltageStates_to_point(voltage_state)));
}

TEST_F(VoltageConstraintsTest, EqualityAndInEqual) {
  VoltageConstraintsHandle handle2 =
      VoltageConstraints_create(adjacency, max_safe_diff, bounds);
  EXPECT_TRUE(VoltageConstraints_equal(handle, handle2));
  EXPECT_FALSE(VoltageConstraints_not_equal(handle, handle2));
  VoltageConstraints_destroy(handle2);
}

TEST_F(VoltageConstraintsTest, SerializationRoundTrip) {
  StringHandle json = VoltageConstraints_to_json_string(handle);
  VoltageConstraintsHandle loaded = VoltageConstraints_from_json_string(json);
  EXPECT_TRUE(VoltageConstraints_equal(handle, loaded));
  VoltageConstraints_destroy(loaded);
  String_destroy(json);
}

TEST_F(VoltageConstraintsTest, InEqualDifferentLimits) {
  PairDoubleDoubleHandle bounds2 = PairDoubleDouble_create(1.0, 5.0);
  VoltageConstraintsHandle handle2 =
      VoltageConstraints_create(adjacency, max_safe_diff, bounds2);
  EXPECT_FALSE(VoltageConstraints_equal(handle, handle2));
  EXPECT_TRUE(VoltageConstraints_not_equal(handle, handle2));
  VoltageConstraints_destroy(handle2);
  PairDoubleDouble_destroy(bounds2);
}

TEST_F(VoltageConstraintsTest, InEqualDifferentAdjacency) {
  ConnectionsHandle indexes2 = Connections_create_empty();
  Connections_push_back(indexes2, Connection_create_ohmic(String_wrap("O1")));
  Connections_push_back(indexes2,
                        Connection_create_reservoir_gate(String_wrap("R1")));
  Connections_push_back(indexes2,
                        Connection_create_barrier_gate(String_wrap("B2")));
  AdjacencyHandle adj2 =
      Adjacency_create(matrix_data, matrix_shape, 2, indexes2);
  VoltageConstraintsHandle handle2 =
      VoltageConstraints_create(adj2, max_safe_diff, bounds);
  EXPECT_FALSE(VoltageConstraints_equal(handle, handle2));
  EXPECT_TRUE(VoltageConstraints_not_equal(handle, handle2));
  VoltageConstraints_destroy(handle2);
  Adjacency_destroy(adj2);
  Connections_destroy(indexes2);
}

TEST_F(VoltageConstraintsTest, CreateThrowsOnNullArguments) {
  set_last_error(0, nullptr);
  VoltageConstraints_create(nullptr, max_safe_diff, bounds);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  VoltageConstraints_create(adjacency, max_safe_diff, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(VoltageConstraintsTest, DestroyThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  VoltageConstraints_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(VoltageConstraintsTest, AdjacencyThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  VoltageConstraints_adjacency(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(VoltageConstraintsTest, EqualityThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  VoltageConstraints_equal(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  VoltageConstraints_equal(nullptr, handle);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(VoltageConstraintsTest, InEqualThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  VoltageConstraints_not_equal(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  VoltageConstraints_not_equal(nullptr, handle);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(VoltageConstraintsTest, ToJsonStringThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  VoltageConstraints_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(VoltageConstraintsTest, FromJsonStringThrowsOnNullJson) {
  set_last_error(0, nullptr);
  VoltageConstraints_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
