#include <gtest/gtest.h>

#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/PairFloatFloat_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/config/core/Adjacency_c_api.h"
#include "falcon_core/physics/config/core/VoltageConstraints_c_api.h"

class VoltageConstraintsTest : public ::testing::Test {
 protected:
  ConnectionsHandle        indexes;
  int                      matrix_data[9]  = {0, 1, 0, 1, 0, 1, 0, 1, 0};
  size_t                   matrix_shape[2] = {3, 3};
  AdjacencyHandle          adjacency;
  double                   max_safe_diff;
  PairDoubleDoubleHandle   bounds;
  VoltageConstraintsHandle handle;

  void SetUp() override {
    indexes = Connections_create_empty();
    Connections_push_back(indexes, Connection_create_ohmic(String_wrap("O1")));
    Connections_push_back(indexes,
                          Connection_create_reservoir_gate(String_wrap("R1")));
    Connections_push_back(indexes,
                          Connection_create_barrier_gate(String_wrap("B1")));
    adjacency     = Adjacency_create(matrix_data, matrix_shape, 2, indexes);
    max_safe_diff = 1.5;
    bounds        = PairDoubleDouble_create(0.0, 5.0);
    handle        = VoltageConstraints_create(adjacency, max_safe_diff, bounds);
  }

  void TearDown() override {
    VoltageConstraints_destroy(handle);
    Adjacency_destroy(adjacency);
    Connections_destroy(indexes);
    PairDoubleDouble_destroy(bounds);
  }
};

TEST_F(VoltageConstraintsTest, MatrixGetter) {
  FArrayDoubleHandle matrix = VoltageConstraints_matrix(handle);
  EXPECT_EQ(FArrayDouble_dimension(matrix), 2);
  FArrayDouble_destroy(matrix);
}

TEST_F(VoltageConstraintsTest, AdjacencyGetter) {
  AdjacencyHandle adj = VoltageConstraints_adjacency(handle);
  EXPECT_TRUE(Adjacency_equality(adjacency, adj));
  Adjacency_destroy(adj);
}

TEST_F(VoltageConstraintsTest, LimitsGetter) {
  FArrayDoubleHandle lim = VoltageConstraints_limits(handle);
  double             data[10];
  FArrayDouble_data(lim, data, 10);
  EXPECT_EQ(data[0], 5.0);
  EXPECT_EQ(data[1], 5.0);
  EXPECT_EQ(data[2], 5.0);
  EXPECT_EQ(data[3], 0.0);
  EXPECT_EQ(data[4], 0.0);
  EXPECT_EQ(data[5], 0.0);
  EXPECT_EQ(data[6], 1.5);
  EXPECT_EQ(data[7], 1.5);
  EXPECT_EQ(data[8], 1.5);
  EXPECT_EQ(data[9], 1.5);
  PairFloatFloat_destroy(lim);
}

TEST_F(VoltageConstraintsTest, EqualityAndInequality) {
  VoltageConstraintsHandle handle2 =
      VoltageConstraints_create(adjacency, max_safe_diff, bounds);
  EXPECT_TRUE(VoltageConstraints_equal(handle, handle2));
  EXPECT_FALSE(VoltageConstraints_not_equal(handle, handle2));
  VoltageConstraints_destroy(handle2);
}

TEST_F(VoltageConstraintsTest, SerializationRoundTrip) {
  StringHandle             json   = VoltageConstraints_to_json_string(handle);
  VoltageConstraintsHandle loaded = VoltageConstraints_from_json_string(json);
  EXPECT_TRUE(VoltageConstraints_equal(handle, loaded));
  VoltageConstraints_destroy(loaded);
  String_destroy(json);
}

TEST_F(VoltageConstraintsTest, InequalityDifferentLimits) {
  PairDoubleDoubleHandle   bounds2 = PairDoubleDouble_create(1.0, 5.0);
  VoltageConstraintsHandle handle2 =
      VoltageConstraints_create(adjacency, max_safe_diff, bounds2);
  EXPECT_FALSE(VoltageConstraints_equal(handle, handle2));
  EXPECT_TRUE(VoltageConstraints_not_equal(handle, handle2));
  VoltageConstraints_destroy(handle2);
  PairDoubleDouble_destroy(bounds2);
}

TEST_F(VoltageConstraintsTest, InequalityDifferentAdjacency) {
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
