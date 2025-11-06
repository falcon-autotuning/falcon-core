#include <gtest/gtest.h>

#include "falcon_core/generic/ListControlArray1D_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/AxesControlArray1D_c_api.h"
#include "falcon_core/math/arrays/ControlArray1D_c_api.h"
class AxesControlArray1DTest : public ::testing::Test {
 protected:
  void SetUp() override {
    shape[0]   = 3;
    data[0]    = 1.0;
    data[1]    = 2.0;
    data[2]    = 3.0;
    shape[0]   = 3;
    axes       = AxesControlArray1D_create_empty();
    auto item1 = ControlArray1D_from_data(data, shape, 1);
    auto item2 = ControlArray1D_from_data(data, shape, 1);
    AxesControlArray1D_push_back(axes, item1);
    AxesControlArray1D_push_back(axes, item2);

    axes2 = AxesControlArray1D_create_empty();
    AxesControlArray1D_push_back(axes2, item1);
    AxesControlArray1D_push_back(axes2, item2);
  }
  void TearDown() override { AxesControlArray1D_destroy(axes); }

  AxesControlArray1DHandle axes  = nullptr;
  AxesControlArray1DHandle axes2 = nullptr;
  ControlArray1DHandle     rawbuffer[2];
  double                   data[3];
  size_t                   shape[1];
  ControlArray1DHandle     ca;
  ControlArray1DHandle     ca2;
  FArrayDoubleHandle       fa;
};

TEST_F(AxesControlArray1DTest, CreateDestroy) {
  auto h = AxesControlArray1D_create_empty();
  AxesControlArray1D_destroy(h);
  EXPECT_THROW(AxesControlArray1D_create(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesControlArray1D_destroy(nullptr), std::invalid_argument);

  EXPECT_NO_THROW(AxesControlArray1D_create(ListControlArray1D_create_empty()));
}

TEST_F(AxesControlArray1DTest, AccessorsAndMutators) {
  EXPECT_EQ(AxesControlArray1D_size(axes), 2u);

  // ListControlArray1DHandle out1[1] = {ListControlArray_create_empty()};
  ControlArray1DHandle out[1] = {ControlArray1D_from_data(data, shape, 1)};
  auto                 h2     = AxesControlArray1D_create_raw(out, 1);

  AxesControlArray1D_push_back(axes, ControlArray1D_from_data(data, shape, 1));
  ControlArray1DHandle out2[3];
  AxesControlArray1D_items(axes, out2, 3);
  AxesControlArray1D_erase_at(axes, 2);
  AxesControlArray1D_clear(axes);
  EXPECT_TRUE(AxesControlArray1D_empty(axes));
}

TEST_F(AxesControlArray1DTest, ContainsIndexEquality) {
  EXPECT_NO_THROW(
      AxesControlArray1D_contains(axes, AxesControlArray1D_at(axes, 0)));
  EXPECT_NO_THROW(
      AxesControlArray1D_index(axes, AxesControlArray1D_at(axes, 0)));
  EXPECT_NO_THROW(AxesControlArray1D_equal(axes, axes2));
}

TEST_F(AxesControlArray1DTest, SerializationRoundTrip) {
  EXPECT_THROW(AxesControlArray1D_from_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesControlArray1D_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_NO_THROW({
    auto json   = AxesControlArray1D_to_json_string(axes);
    auto loaded = AxesControlArray1D_from_json_string(json);
    AxesControlArray1D_destroy(loaded);
    String_destroy(json);
  });
}

TEST_F(AxesControlArray1DTest, EqualityWorks) {
  EXPECT_THROW(AxesControlArray1D_equal(axes, nullptr), std::invalid_argument);
  EXPECT_THROW(AxesControlArray1D_not_equal(nullptr, axes2),
               std::invalid_argument);
  EXPECT_NO_THROW(AxesControlArray1D_equal(axes, axes));
  EXPECT_NO_THROW(AxesControlArray1D_not_equal(axes, axes2));
}

TEST_F(AxesControlArray1DTest, Intersection) {
  EXPECT_THROW(AxesControlArray1D_intersection(nullptr, axes2),
               std::invalid_argument);
  EXPECT_THROW(AxesControlArray1D_intersection(axes, nullptr),
               std::invalid_argument);
  EXPECT_NO_THROW(AxesControlArray1D_intersection(axes, axes2));
}

TEST_F(AxesControlArray1DTest, MiscNullChecks) {
  EXPECT_THROW(AxesControlArray1D_destroy(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesControlArray1D_push_back(nullptr, nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesControlArray1D_push_back(axes, nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesControlArray1D_size(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesControlArray1D_empty(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesControlArray1D_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesControlArray1D_clear(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesControlArray1D_push_back(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesControlArray1D_contains(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesControlArray1D_contains(axes, nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesControlArray1D_index(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesControlArray1D_index(axes, nullptr), std::invalid_argument);
  EXPECT_THROW(AxesControlArray1D_items(nullptr, rawbuffer, 2),
               std::invalid_argument);
  EXPECT_THROW(AxesControlArray1D_items(axes, nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(AxesControlArray1D_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesControlArray1D_create_raw(nullptr, 2),
               std::invalid_argument);
}
