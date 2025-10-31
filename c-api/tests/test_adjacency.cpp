#include <gtest/gtest.h>

#include "falcon_core/generic/ListListSizeT_c_api.h"
#include "falcon_core/generic/ListPairSizeTSizeT_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/config/core/Adjacency_c_api.h"

class AdjacencyTest : public ::testing::Test {
 protected:
  ConnectionsHandle indexes;
  int               matrix_data[9]  = {0, 1, 0, 1, 0, 1, 0, 1, 0};
  size_t            matrix_shape[2] = {3, 3};
  AdjacencyHandle   handle;

  void SetUp() override {
    indexes = Connections_create_empty();
    Connections_push_back(indexes,
                          Connection_create_plunger_gate(String_wrap("P1")));
    Connections_push_back(indexes, Connection_create_ohmic(String_wrap("O1")));
    Connections_push_back(indexes,
                          Connection_create_reservoir_gate(String_wrap("R1")));
    Connections_push_back(indexes,
                          Connection_create_barrier_gate(String_wrap("B1")));
    handle = Adjacency_create(matrix_data, matrix_shape, 2, indexes);
  }

  void TearDown() override {
    Adjacency_destroy(handle);
    Connection_destroy(indexes);
  }
};

TEST_F(AdjacencyTest, IndexesReturnsExpected) {
  ConnectionsHandle idx = Adjacency_indexes(handle);
  EXPECT_EQ(Connections_size(idx), 4);
  Connections_destroy(idx);
}

TEST_F(AdjacencyTest, GetTruePairsReturnsCorrectPairs) {
  ListPairSizeTSizeTHandle pairs = Adjacency_get_true_pairs(handle);
  EXPECT_EQ(ListPairSizeTSizeT_size(pairs), 2);
  ListPairSizeTSizeT_destroy(pairs);
}

TEST_F(AdjacencyTest, SizeAndDimension) {
  EXPECT_EQ(Adjacency_size(handle), 9);
  EXPECT_EQ(Adjacency_dimension(handle), 2);
}

TEST_F(AdjacencyTest, ShapeReturnsExpected) {
  size_t out_shape[2] = {0, 0};
  size_t copied       = Adjacency_shape(handle, out_shape, 2);
  EXPECT_EQ(copied, 2);
  EXPECT_EQ(out_shape[0], 3);
  EXPECT_EQ(out_shape[1], 3);
}

TEST_F(AdjacencyTest, EqualityAndInequality) {
  AdjacencyHandle handle2 =
      Adjacency_create(matrix_data, matrix_shape, 2, indexes);
  EXPECT_TRUE(Adjacency_equality(handle, handle2));
  EXPECT_FALSE(Adjacency_notequality(handle, handle2));
  Adjacency_destroy(handle2);
}

TEST_F(AdjacencyTest, SumReturnsExpected) {
  EXPECT_EQ(Adjacency_sum(handle), 4);
}

TEST_F(AdjacencyTest, WhereReturnsExpected) {
  ListListSizeTHandle where = Adjacency_where(handle, 1);
  EXPECT_GT(ListListSizeT_size(where), 0);
  ListListSizeT_destroy(where);
}

TEST_F(AdjacencyTest, FlipReturnsExpected) {
  AdjacencyHandle flipped = Adjacency_flip(handle, 0);
  EXPECT_EQ(Adjacency_size(flipped), 9);
  Adjacency_destroy(flipped);
}

TEST_F(AdjacencyTest, SerializationRoundTrip) {
  StringHandle    json   = Adjacency_to_json_string(handle);
  AdjacencyHandle loaded = Adjacency_from_json_string(json);
  EXPECT_TRUE(Adjacency_equality(handle, loaded));
  Adjacency_destroy(loaded);
  String_destroy(json);
}
