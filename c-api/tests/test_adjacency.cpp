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

TEST_F(AdjacencyTest, CreateThrowsOnNullIndexes) {
  int    data[1]  = {0};
  size_t shape[1] = {1};
  EXPECT_THROW(Adjacency_create(data, shape, 1, nullptr),
               std::invalid_argument);
}

TEST_F(AdjacencyTest, DestroyThrowsOnNullHandle) {
  EXPECT_THROW(Adjacency_destroy(nullptr), std::invalid_argument);
}

TEST_F(AdjacencyTest, IndexesThrowsOnNullHandle) {
  EXPECT_THROW(Adjacency_indexes(nullptr), std::invalid_argument);
}

TEST_F(AdjacencyTest, GetTruePairsThrowsOnNullHandle) {
  EXPECT_THROW(Adjacency_get_true_pairs(nullptr), std::invalid_argument);
}

TEST_F(AdjacencyTest, SizeThrowsOnNullHandle) {
  EXPECT_THROW(Adjacency_size(nullptr), std::invalid_argument);
}

TEST_F(AdjacencyTest, DimensionThrowsOnNullHandle) {
  EXPECT_THROW(Adjacency_dimension(nullptr), std::invalid_argument);
}

TEST_F(AdjacencyTest, ShapeThrowsOnNullHandle) {
  size_t buf[1];
  EXPECT_THROW(Adjacency_shape(nullptr, buf, 1), std::invalid_argument);
}

TEST_F(AdjacencyTest, DataThrowsOnNullHandle) {
  int buf[1];
  EXPECT_THROW(Adjacency_data(nullptr, buf, 1), std::invalid_argument);
}

TEST_F(AdjacencyTest, TimesequalsFarrayThrowsOnNullHandle) {
  EXPECT_THROW(Adjacency_timesequals_farray(nullptr, nullptr),
               std::invalid_argument);
}

TEST_F(AdjacencyTest, TimesequalsFarrayThrowsOnNullOther) {
  // Use a dummy valid handle for the first argument
  int               data[1]  = {0};
  size_t            shape[1] = {1};
  ConnectionsHandle idx      = Connections_create_empty();
  AdjacencyHandle   h        = Adjacency_create(data, shape, 1, idx);
  EXPECT_THROW(Adjacency_create(nullptr, shape, 1, idx), std::invalid_argument);
  EXPECT_THROW(Adjacency_create(data, nullptr, 1, idx), std::invalid_argument);
  EXPECT_THROW(Adjacency_timesequals_farray(h, nullptr), std::invalid_argument);
  Adjacency_destroy(h);
  Connection_destroy(idx);
}

TEST_F(AdjacencyTest, TimesFarrayThrowsOnNullHandle) {
  EXPECT_THROW(Adjacency_times_farray(nullptr, nullptr), std::invalid_argument);
}

TEST_F(AdjacencyTest, TimesFarrayThrowsOnNullOther) {
  int               data[1]  = {0};
  size_t            shape[1] = {1};
  ConnectionsHandle idx      = Connections_create_empty();
  AdjacencyHandle   h        = Adjacency_create(data, shape, 1, idx);
  EXPECT_THROW(Adjacency_times_farray(h, nullptr), std::invalid_argument);
  Adjacency_destroy(h);
  Connection_destroy(idx);
}

TEST_F(AdjacencyTest, EqualityThrowsOnNullHandle) {
  EXPECT_THROW(Adjacency_equality(nullptr, nullptr), std::invalid_argument);
}

TEST_F(AdjacencyTest, EqualityThrowsOnNullOther) {
  int               data[1]  = {0};
  size_t            shape[1] = {1};
  ConnectionsHandle idx      = Connections_create_empty();
  AdjacencyHandle   h        = Adjacency_create(data, shape, 1, idx);
  EXPECT_THROW(Adjacency_equality(h, nullptr), std::invalid_argument);
  Adjacency_destroy(h);
  Connection_destroy(idx);
}

TEST_F(AdjacencyTest, NotequalityThrowsOnNullHandle) {
  EXPECT_THROW(Adjacency_notequality(nullptr, nullptr), std::invalid_argument);
}

TEST_F(AdjacencyTest, NotequalityThrowsOnNullOther) {
  int               data[1]  = {0};
  size_t            shape[1] = {1};
  ConnectionsHandle idx      = Connections_create_empty();
  AdjacencyHandle   h        = Adjacency_create(data, shape, 1, idx);
  EXPECT_THROW(Adjacency_notequality(h, nullptr), std::invalid_argument);
  Adjacency_destroy(h);
  Connection_destroy(idx);
}

TEST_F(AdjacencyTest, SumThrowsOnNullHandle) {
  EXPECT_THROW(Adjacency_sum(nullptr), std::invalid_argument);
}

TEST_F(AdjacencyTest, WhereThrowsOnNullHandle) {
  EXPECT_THROW(Adjacency_where(nullptr, 1), std::invalid_argument);
}

TEST_F(AdjacencyTest, FlipThrowsOnNullHandle) {
  EXPECT_THROW(Adjacency_flip(nullptr, 0), std::invalid_argument);
}

TEST_F(AdjacencyTest, ToJsonStringThrowsOnNullHandle) {
  EXPECT_THROW(Adjacency_to_json_string(nullptr), std::invalid_argument);
}

TEST_F(AdjacencyTest, FromJsonStringThrowsOnNullJson) {
  EXPECT_THROW(Adjacency_from_json_string(nullptr), std::invalid_argument);
}

TEST_F(AdjacencyTest, DataReturnsExpected) {
  int    buf[9];
  size_t n = Adjacency_data(handle, buf, 9);
  EXPECT_THROW(Adjacency_data(handle, nullptr, 8), std::invalid_argument);
  EXPECT_EQ(n, 9);
  for (int i = 0; i < 9; ++i) {
    EXPECT_EQ(buf[i], matrix_data[i]);
  }
}

TEST_F(AdjacencyTest, DataThrowsIfBufferTooSmall) {
  int buf[3] = {0};
  EXPECT_THROW(Adjacency_data(handle, buf, 3), std::runtime_error);
}

TEST_F(AdjacencyTest, TimesequalsFarrayWorks) {
  // Make a FArray<int> of the right size, all ones (so multiplication is
  // identity)
  int             arr[9]   = {1, 1, 1, 1, 1, 1, 1, 1, 1};
  size_t          shape[2] = {3, 3};
  FArrayIntHandle farray   = FArrayInt_from_data(arr, shape, 2);
  // Should not throw
  EXPECT_NO_THROW(Adjacency_timesequals_farray(handle, farray));
  FArrayInt_destroy(farray);
}

TEST_F(AdjacencyTest, TimesFarrayWorks) {
  int             arr[9]   = {1, 1, 1, 1, 1, 1, 1, 1, 1};
  size_t          shape[2] = {3, 3};
  FArrayIntHandle farray   = FArrayInt_from_data(arr, shape, 2);
  AdjacencyHandle result   = nullptr;
  EXPECT_NO_THROW(result = Adjacency_times_farray(handle, farray));
  EXPECT_NE(result, nullptr);
  if (result) {
    int buf[9] = {0};
    Adjacency_data(result, buf, 9);
    for (int i = 0; i < 9; ++i) {
      EXPECT_EQ(buf[i], matrix_data[i]);
    }
    Adjacency_destroy(result);
  }
  FArrayInt_destroy(farray);
}
