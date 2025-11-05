#include <gtest/gtest.h>

#include "falcon_core/generic/FArrayInt_c_api.h"
#include "falcon_core/generic/String_c_api.h"

class FArrayIntTest : public ::testing::Test {
 protected:
  void SetUp() override {
    shape[0]    = 2;
    shape[1]    = 2;
    arr1        = FArrayInt_create_zeros(shape, 2);
    arr2        = FArrayInt_from_shape(shape, 2);
    int data[4] = {1, 2, 3, 4};
    arr3        = FArrayInt_from_data(data, shape, 2);
  }
  void TearDown() override {
    FArrayInt_destroy(arr1);
    FArrayInt_destroy(arr2);
    FArrayInt_destroy(arr3);
  }
  size_t          shape[2];
  FArrayIntHandle arr1 = nullptr, arr2 = nullptr, arr3 = nullptr;
};

TEST_F(FArrayIntTest, CreateDestroy) {
  FArrayIntHandle empty = FArrayInt_create_empty();
  FArrayInt_destroy(empty);

  FArrayIntHandle zeros = FArrayInt_create_zeros(shape, 2);
  FArrayInt_destroy(zeros);

  FArrayIntHandle from_shape = FArrayInt_from_shape(shape, 2);
  FArrayInt_destroy(from_shape);

  int             data[4]   = {1, 2, 3, 4};
  FArrayIntHandle from_data = FArrayInt_from_data(data, shape, 2);
  FArrayInt_destroy(from_data);

  EXPECT_THROW(FArrayInt_destroy(nullptr), std::invalid_argument);
}

TEST_F(FArrayIntTest, NullptrCoverage) {
  int data[4] = {1, 2, 3, 4};
  EXPECT_THROW(FArrayInt_create_zeros(nullptr, 2), std::exception);
  EXPECT_THROW(FArrayInt_from_shape(nullptr, 2), std::exception);
  EXPECT_THROW(FArrayInt_from_data(nullptr, shape, 2), std::exception);
  EXPECT_THROW(FArrayInt_from_data(data, nullptr, 2), std::exception);
  EXPECT_THROW(FArrayInt_size(nullptr), std::invalid_argument);
  EXPECT_THROW(FArrayInt_dimension(nullptr), std::invalid_argument);
  EXPECT_THROW(FArrayInt_shape(nullptr, shape, 2), std::invalid_argument);
  EXPECT_THROW(FArrayInt_shape(arr1, nullptr, 2), std::invalid_argument);
  EXPECT_THROW(FArrayInt_data(nullptr, data, 4), std::invalid_argument);
  EXPECT_THROW(FArrayInt_plusequals_farray(nullptr, arr1),
               std::invalid_argument);
  EXPECT_THROW(FArrayInt_plusequals_farray(arr1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(FArrayInt_plusequals_double(nullptr, 1.0),
               std::invalid_argument);
  EXPECT_THROW(FArrayInt_plusequals_int(nullptr, 1), std::invalid_argument);
  EXPECT_THROW(FArrayInt_plus_farray(nullptr, arr1), std::invalid_argument);
  EXPECT_THROW(FArrayInt_plus_farray(arr1, nullptr), std::invalid_argument);
  EXPECT_THROW(FArrayInt_plus_double(nullptr, 1.0), std::invalid_argument);
  EXPECT_THROW(FArrayInt_plus_int(nullptr, 1), std::invalid_argument);
  EXPECT_THROW(FArrayInt_minusequals_farray(nullptr, arr1),
               std::invalid_argument);
  EXPECT_THROW(FArrayInt_minusequals_farray(arr1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(FArrayInt_minusequals_double(nullptr, 1.0),
               std::invalid_argument);
  EXPECT_THROW(FArrayInt_minusequals_int(nullptr, 1), std::invalid_argument);
  EXPECT_THROW(FArrayInt_minus_farray(nullptr, arr1), std::invalid_argument);
  EXPECT_THROW(FArrayInt_minus_farray(arr1, nullptr), std::invalid_argument);
  EXPECT_THROW(FArrayInt_minus_double(nullptr, 1.0), std::invalid_argument);
  EXPECT_THROW(FArrayInt_minus_int(nullptr, 1), std::invalid_argument);
  EXPECT_THROW(FArrayInt_negation(nullptr), std::invalid_argument);
  EXPECT_THROW(FArrayInt_timesequals_farray(nullptr, arr1),
               std::invalid_argument);
  EXPECT_THROW(FArrayInt_timesequals_farray(arr1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(FArrayInt_timesequals_double(nullptr, 1.0),
               std::invalid_argument);
  EXPECT_THROW(FArrayInt_timesequals_int(nullptr, 1), std::invalid_argument);
  EXPECT_THROW(FArrayInt_times_farray(nullptr, arr1), std::invalid_argument);
  EXPECT_THROW(FArrayInt_times_farray(arr1, nullptr), std::invalid_argument);
  EXPECT_THROW(FArrayInt_times_double(nullptr, 1.0), std::invalid_argument);
  EXPECT_THROW(FArrayInt_times_int(nullptr, 1), std::invalid_argument);
  EXPECT_THROW(FArrayInt_dividesequals_farray(nullptr, arr1),
               std::invalid_argument);
  EXPECT_THROW(FArrayInt_dividesequals_farray(arr1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(FArrayInt_dividesequals_double(nullptr, 1.0),
               std::invalid_argument);
  EXPECT_THROW(FArrayInt_dividesequals_int(nullptr, 1), std::invalid_argument);
  EXPECT_THROW(FArrayInt_divides_farray(nullptr, arr1), std::invalid_argument);
  EXPECT_THROW(FArrayInt_divides_farray(arr1, nullptr), std::invalid_argument);
  EXPECT_THROW(FArrayInt_divides_double(nullptr, 1.0), std::invalid_argument);
  EXPECT_THROW(FArrayInt_divides_int(nullptr, 1), std::invalid_argument);
  EXPECT_THROW(FArrayInt_pow(nullptr, 2.0), std::invalid_argument);
  EXPECT_THROW(FArrayInt_abs(nullptr), std::invalid_argument);
  EXPECT_THROW(FArrayInt_min(nullptr), std::invalid_argument);
  EXPECT_THROW(FArrayInt_min_arraywise(nullptr, arr1), std::invalid_argument);
  EXPECT_THROW(FArrayInt_min_arraywise(arr1, nullptr), std::invalid_argument);
  EXPECT_THROW(FArrayInt_max(nullptr), std::invalid_argument);
  EXPECT_THROW(FArrayInt_max_arraywise(nullptr, arr1), std::invalid_argument);
  EXPECT_THROW(FArrayInt_max_arraywise(arr1, nullptr), std::invalid_argument);
  EXPECT_THROW(FArrayInt_equality(nullptr, arr1), std::invalid_argument);
  EXPECT_THROW(FArrayInt_equality(arr1, nullptr), std::invalid_argument);
  EXPECT_THROW(FArrayInt_notequality(nullptr, arr1), std::invalid_argument);
  EXPECT_THROW(FArrayInt_notequality(arr1, nullptr), std::invalid_argument);
  EXPECT_THROW(FArrayInt_greaterthan(nullptr, 1.0), std::invalid_argument);
  EXPECT_THROW(FArrayInt_lessthan(nullptr, 1.0), std::invalid_argument);
  EXPECT_THROW(FArrayInt_remove_offset(nullptr, 1.0), std::invalid_argument);
  EXPECT_THROW(FArrayInt_sum(nullptr), std::invalid_argument);
  EXPECT_THROW(FArrayInt_reshape(nullptr, shape, 2), std::invalid_argument);
  EXPECT_THROW(FArrayInt_where(nullptr, 1), std::invalid_argument);
  EXPECT_THROW(FArrayInt_flip(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(FArrayInt_full_gradient(nullptr, nullptr, 0),
               std::invalid_argument);
  EXPECT_THROW(FArrayInt_full_gradient(arr1, nullptr, 0),
               std::invalid_argument);
  EXPECT_THROW(FArrayInt_gradient(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(FArrayInt_get_sum_of_squares(nullptr), std::invalid_argument);
  EXPECT_THROW(FArrayInt_get_summed_diff_int_of_squares(nullptr, 1),
               std::invalid_argument);
  EXPECT_THROW(FArrayInt_get_summed_diff_double_of_squares(nullptr, 1.0),
               std::invalid_argument);
  EXPECT_THROW(FArrayInt_get_summed_diff_array_of_squares(nullptr, arr1),
               std::invalid_argument);
  EXPECT_THROW(FArrayInt_get_summed_diff_array_of_squares(arr1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(FArrayInt_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(FArrayInt_from_json_string(nullptr), std::invalid_argument);
}

TEST_F(FArrayIntTest, BasicProperties) {
  EXPECT_EQ(FArrayInt_size(arr1), 4);
  EXPECT_EQ(FArrayInt_dimension(arr1), 2);
  size_t out_shape[2] = {0, 0};
  EXPECT_EQ(FArrayInt_shape(arr1, out_shape, 2), 2);
  EXPECT_EQ(out_shape[0], 2);
  EXPECT_EQ(out_shape[1], 2);

  int out_data[4] = {0};
  EXPECT_EQ(FArrayInt_data(arr1, out_data, 4), 4);
}

TEST_F(FArrayIntTest, ArithmeticAndComparison) {
  FArrayIntHandle arr4 = FArrayInt_create_zeros(shape, 2);
  EXPECT_TRUE(FArrayInt_equality(arr1, arr1));
  EXPECT_FALSE(FArrayInt_notequality(arr1, arr4));
  EXPECT_TRUE(FArrayInt_greaterthan(arr1, -1000.0));
  EXPECT_FALSE(FArrayInt_lessthan(arr1, -1000.0));
  FArrayInt_plusequals_farray(arr1, arr4);
  FArrayInt_plusequals_double(arr1, 1.0);
  FArrayInt_plusequals_int(arr1, 1);
  FArrayInt_minusequals_farray(arr1, arr4);
  FArrayInt_minusequals_double(arr1, 1.0);
  FArrayInt_minusequals_int(arr1, 1);
  FArrayInt_timesequals_farray(arr1, arr4);
  FArrayInt_timesequals_double(arr1, 2.0);
  FArrayInt_timesequals_int(arr1, 2);
  FArrayInt_dividesequals_farray(arr1, arr3);
  FArrayInt_dividesequals_double(arr1, 2.0);
  FArrayInt_dividesequals_int(arr1, 2);

  FArrayIntHandle arr5  = FArrayInt_plus_farray(arr1, arr4);
  FArrayIntHandle arr6  = FArrayInt_plus_double(arr1, 1.0);
  FArrayIntHandle arr7  = FArrayInt_plus_int(arr1, 1);
  FArrayIntHandle arr8  = FArrayInt_minus_farray(arr1, arr4);
  FArrayIntHandle arr9  = FArrayInt_minus_double(arr1, 1.0);
  FArrayIntHandle arr10 = FArrayInt_minus_int(arr1, 1);
  FArrayIntHandle arr11 = FArrayInt_times_farray(arr1, arr4);
  FArrayIntHandle arr12 = FArrayInt_times_double(arr1, 2.0);
  FArrayIntHandle arr13 = FArrayInt_times_int(arr1, 2);
  FArrayIntHandle arr14 = FArrayInt_divides_farray(arr1, arr3);
  FArrayIntHandle arr15 = FArrayInt_divides_double(arr1, 2.0);
  FArrayIntHandle arr16 = FArrayInt_divides_int(arr1, 2);
  FArrayIntHandle arr17 = FArrayInt_pow(arr1, 2.0);
  FArrayIntHandle arr18 = FArrayInt_abs(arr1);
  int             num1  = FArrayInt_min(arr1);
  FArrayIntHandle arr19 = FArrayInt_min_arraywise(arr1, arr4);
  int             num2  = FArrayInt_max(arr1);
  FArrayIntHandle arr20 = FArrayInt_max_arraywise(arr1, arr4);
  FArrayIntHandle arr21 = FArrayInt_negation(arr1);
  FArrayIntHandle arr22 = FArrayInt_reshape(arr1, shape, 2);
  FArrayIntHandle arr23 = FArrayInt_gradient(arr1, 0);
  FArrayIntHandle arr24 = FArrayInt_flip(arr1, 0);

  FArrayInt_destroy(arr4);
  FArrayInt_destroy(arr5);
  FArrayInt_destroy(arr6);
  FArrayInt_destroy(arr7);
  FArrayInt_destroy(arr8);
  FArrayInt_destroy(arr9);
  FArrayInt_destroy(arr10);
  FArrayInt_destroy(arr11);
  FArrayInt_destroy(arr12);
  FArrayInt_destroy(arr13);
  FArrayInt_destroy(arr14);
  FArrayInt_destroy(arr15);
  FArrayInt_destroy(arr16);
  FArrayInt_destroy(arr17);
  FArrayInt_destroy(arr18);
  FArrayInt_destroy(arr20);
  FArrayInt_destroy(arr21);
  FArrayInt_destroy(arr22);
  FArrayInt_destroy(arr23);
  FArrayInt_destroy(arr24);
}

TEST_F(FArrayIntTest, Miscellaneous) {
  FArrayInt_remove_offset(arr3, 1.0);
  EXPECT_GE(FArrayInt_sum(arr3), 0.0);
  int sumsq = FArrayInt_get_sum_of_squares(arr3);
  EXPECT_GE(sumsq, 0.0);
  EXPECT_NO_THROW(FArrayInt_get_summed_diff_int_of_squares(arr3, 1));
  EXPECT_NO_THROW(FArrayInt_get_summed_diff_double_of_squares(arr3, 1.0));
  EXPECT_NO_THROW(FArrayInt_get_summed_diff_array_of_squares(arr3, arr2));
  ListListSizeTHandle where = FArrayInt_where(arr3, 0.0);
  EXPECT_NO_THROW({
    FArrayIntHandle grads[2];
    size_t          n = FArrayInt_full_gradient(arr3, grads, 2);
    for (size_t i = 0; i < n; ++i) FArrayInt_destroy(grads[i]);
  });
  StringHandle    json          = FArrayInt_to_json_string(arr3);
  FArrayIntHandle arr_from_json = FArrayInt_from_json_string(json);
  FArrayInt_destroy(arr_from_json);
  String_destroy(json);
}

TEST_F(FArrayIntTest, ShapeBufferTooSmall) {
  size_t out_shape[1] = {0};  // buffer smaller than needed (should be 2)
  // Should only fill one element, return 1
  EXPECT_EQ(FArrayInt_shape(arr1, out_shape, 1), 1);
  EXPECT_EQ(out_shape[0], 2);
}

TEST_F(FArrayIntTest, FullGradientBufferTooSmall) {
  FArrayIntHandle grads[1];  // buffer smaller than needed
  // Should throw or error if more gradients than buffer
  EXPECT_THROW(FArrayInt_full_gradient(arr1, grads, 1), std::runtime_error);
}

TEST_F(FArrayIntTest, DataBufferTooSmall) {
  int out_data[2] = {0, 0};  // buffer smaller than needed (should be 4)
  EXPECT_THROW(FArrayInt_data(arr1, out_data, 2), std::runtime_error);
}

TEST_F(FArrayIntTest, DataNullBuffer) {
  EXPECT_THROW(FArrayInt_data(arr1, nullptr, 4), std::invalid_argument);
}
