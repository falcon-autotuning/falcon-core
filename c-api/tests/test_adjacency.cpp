#include <gtest/gtest.h>

#include "falcon_core/generic/ErrorHandling_c_api.h"
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
  EXPECT_TRUE(Connections_equal(idx, indexes));
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

TEST_F(AdjacencyTest, EqualityAndInEqual) {
  AdjacencyHandle handle2 =
      Adjacency_create(matrix_data, matrix_shape, 2, indexes);
  EXPECT_TRUE(Adjacency_equal(handle, handle2));
  EXPECT_FALSE(Adjacency_not_equal(handle, handle2));
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
  EXPECT_TRUE(Adjacency_equal(handle, loaded));
  Adjacency_destroy(loaded);
  String_destroy(json);
}

TEST_F(AdjacencyTest, CreateThrowsOnNullIndexes) {
  int    data[1]  = {0};
  size_t shape[1] = {1};
  set_last_error(0, nullptr);
  Adjacency_create(data, shape, 1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AdjacencyTest, DestroyThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Adjacency_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AdjacencyTest, IndexesThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Adjacency_indexes(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AdjacencyTest, GetTruePairsThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Adjacency_get_true_pairs(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AdjacencyTest, SizeThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Adjacency_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AdjacencyTest, DimensionThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Adjacency_dimension(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AdjacencyTest, ShapeThrowsOnNullHandle) {
  size_t buf[1];
  set_last_error(0, nullptr);
  Adjacency_shape(nullptr, buf, 1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AdjacencyTest, DataThrowsOnNullHandle) {
  int buf[1];
  set_last_error(0, nullptr);
  Adjacency_data(nullptr, buf, 1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AdjacencyTest, TimesequalsFarrayThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Adjacency_times_equals_farray(nullptr, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AdjacencyTest, TimesequalsFarrayThrowsOnNullOther) {
  // Use a dummy valid handle for the first argument
  int               data[1]  = {0};
  size_t            shape[1] = {1};
  ConnectionsHandle idx      = Connections_create_empty();
  AdjacencyHandle   h        = Adjacency_create(data, shape, 1, idx);
  set_last_error(0, nullptr);
  Adjacency_create(nullptr, shape, 1, idx);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Adjacency_create(data, nullptr, 1, idx);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Adjacency_times_equals_farray(h, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Adjacency_destroy(h);
  Connection_destroy(idx);
}

TEST_F(AdjacencyTest, TimesFarrayThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Adjacency_times_farray(nullptr, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AdjacencyTest, TimesFarrayThrowsOnNullOther) {
  int               data[1]  = {0};
  size_t            shape[1] = {1};
  ConnectionsHandle idx      = Connections_create_empty();
  AdjacencyHandle   h        = Adjacency_create(data, shape, 1, idx);
  set_last_error(0, nullptr);
  Adjacency_times_farray(h, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Adjacency_destroy(h);
  Connection_destroy(idx);
}

TEST_F(AdjacencyTest, EqualityThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Adjacency_equal(nullptr, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AdjacencyTest, EqualityThrowsOnNullOther) {
  int               data[1]  = {0};
  size_t            shape[1] = {1};
  ConnectionsHandle idx      = Connections_create_empty();
  AdjacencyHandle   h        = Adjacency_create(data, shape, 1, idx);
  set_last_error(0, nullptr);
  Adjacency_equal(h, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Adjacency_destroy(h);
  Connection_destroy(idx);
}

TEST_F(AdjacencyTest, NotEqualThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Adjacency_not_equal(nullptr, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AdjacencyTest, NotEqualThrowsOnNullOther) {
  int               data[1]  = {0};
  size_t            shape[1] = {1};
  ConnectionsHandle idx      = Connections_create_empty();
  AdjacencyHandle   h        = Adjacency_create(data, shape, 1, idx);
  set_last_error(0, nullptr);
  Adjacency_not_equal(h, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Adjacency_destroy(h);
  Connection_destroy(idx);
}

TEST_F(AdjacencyTest, SumThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Adjacency_sum(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AdjacencyTest, WhereThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Adjacency_where(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AdjacencyTest, FlipThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Adjacency_flip(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AdjacencyTest, ToJsonStringThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Adjacency_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AdjacencyTest, FromJsonStringThrowsOnNullJson) {
  set_last_error(0, nullptr);
  Adjacency_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AdjacencyTest, DataReturnsExpected) {
  int    buf[9];
  size_t n = Adjacency_data(handle, buf, 9);
  set_last_error(0, nullptr);
  Adjacency_data(handle, nullptr, 8);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_EQ(n, 9);
  for (int i = 0; i < 9; ++i) {
    EXPECT_EQ(buf[i], matrix_data[i]);
  }
}

TEST_F(AdjacencyTest, DataThrowsIfBufferTooSmall) {
  int buf[3] = {0};
  set_last_error(0, nullptr);
  Adjacency_data(handle, buf, 3);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AdjacencyTest, TimesequalsFarrayWorks) {
  // Make a FArray<int> of the right size, all ones (so multiplication is
  // identity)
  int             arr[9]   = {1, 1, 1, 1, 1, 1, 1, 1, 1};
  size_t          shape[2] = {3, 3};
  FArrayIntHandle farray   = FArrayInt_from_data(arr, shape, 2);
  // Should not throw
  EXPECT_NO_THROW(Adjacency_times_equals_farray(handle, farray));
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

TEST_F(AdjacencyTest, CopyConstructor) {
  AdjacencyHandle copy = Adjacency_copy(handle);
  EXPECT_NE(copy, nullptr);
  EXPECT_TRUE(Adjacency_equal(handle, copy));
  Adjacency_destroy(copy);

  set_last_error(0, nullptr);
  EXPECT_EQ(Adjacency_copy(nullptr), nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
