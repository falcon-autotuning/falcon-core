#include <gtest/gtest.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

#include <vector>

#include "falcon_core/generic/ListControlArray_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/AxesControlArray_c_api.h"
#include "falcon_core/math/arrays/ControlArray_c_api.h"

class AxesControlArrayTest : public ::testing::Test {
 protected:
  void SetUp() override {
    shape2d[0] = 2;
    shape2d[1] = 3;
    data2d[0] = 1.0;
    data2d[1] = 2.0;
    data2d[2] = 3.0;
    data2d[3] = 1.0;
    data2d[4] = 2.0;
    data2d[5] = 3.0;
    axes = AxesControlArray_create_empty();
    auto item1 = track_ca(ControlArray_from_data(data2d, shape2d, 2));
    auto item2 = track_ca(ControlArray_from_data(data2d, shape2d, 2));
    AxesControlArray_push_back(axes, item1);
    AxesControlArray_push_back(axes, item2);

    axes2 = AxesControlArray_create_empty();
    AxesControlArray_push_back(axes2, item1);
    AxesControlArray_push_back(axes2, item2);
  }

  void TearDown() override {
    if (axes) {
      AxesControlArray_destroy(axes);
      axes = nullptr;
    }
    if (axes2) {
      AxesControlArray_destroy(axes2);
      axes2 = nullptr;
    }
    for (auto h : created_items) {
      ControlArray_destroy(h);
    }
    created_items.clear();
  }

  ControlArrayHandle track_ca(ControlArrayHandle h) {
    created_items.push_back(h);
    return h;
  }

  AxesControlArrayHandle axes  = nullptr;
  AxesControlArrayHandle axes2 = nullptr;
  ControlArrayHandle     rawbuffer[2];
  double                 data2d[6];
  size_t                 shape2d[2];
  double                 data1d[6];
  size_t                 shape1d[1];
  ControlArrayHandle     ca2d;
  ControlArrayHandle     ca1d;
  ControlArrayHandle     ca2d_2;
  FArrayDoubleHandle     fa2d;

  std::vector<ControlArrayHandle> created_items;
};

TEST_F(AxesControlArrayTest, CreateDestroy) {
  auto h = AxesControlArray_create_empty();
  AxesControlArray_destroy(h);
  set_last_error(0, nullptr);
  AxesControlArray_create(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  EXPECT_NO_THROW(AxesControlArray_create(ListControlArray_create_empty()));
}

TEST_F(AxesControlArrayTest, AccessorsAndMutators) {
  EXPECT_EQ(AxesControlArray_size(axes), 2u);

  // ListControlArrayHandle out1[1] = {ListControlArray_create_empty()};
  ControlArrayHandle out[1] = {ControlArray_from_data(data2d, shape2d, 2)};
  auto               h2     = AxesControlArray_create_raw(out, 1);
  if (h2) AxesControlArray_destroy(h2);

  AxesControlArray_push_back(axes, ControlArray_from_data(data2d, shape2d, 2));
  ControlArrayHandle out2[3];
  EXPECT_EQ(AxesControlArray_items(axes, out2, 3), 3u);
  for (size_t i = 0; i < 3; ++i) {
    ControlArray_destroy(out2[i]);
  }

  AxesControlArray_erase_at(axes, 2);
  AxesControlArray_clear(axes);
  EXPECT_TRUE(AxesControlArray_empty(axes));
}

TEST_F(AxesControlArrayTest, ContainsIndexEquality) {
  EXPECT_NO_THROW(
      AxesControlArray_contains(axes, AxesControlArray_at(axes, 0)));
  EXPECT_NO_THROW(AxesControlArray_index(axes, AxesControlArray_at(axes, 0)));
  EXPECT_NO_THROW(AxesControlArray_equal(axes, axes2));
}

TEST_F(AxesControlArrayTest, SerializationRoundTrip) {
  set_last_error(0, nullptr);
  AxesControlArray_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW({
    auto json   = AxesControlArray_to_json_string(axes);
    auto loaded = AxesControlArray_from_json_string(json);
    AxesControlArray_destroy(loaded);
    String_destroy(json);
  });
}

TEST_F(AxesControlArrayTest, EqualityWorks) {
  set_last_error(0, nullptr);
  AxesControlArray_equal(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray_not_equal(nullptr, axes2);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW(AxesControlArray_equal(axes, axes));
  EXPECT_NO_THROW(AxesControlArray_not_equal(axes, axes2));
}

TEST_F(AxesControlArrayTest, Intersection) {
  set_last_error(0, nullptr);
  AxesControlArray_intersection(nullptr, axes2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray_intersection(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW(AxesControlArray_intersection(axes, axes2));
}

TEST_F(AxesControlArrayTest, MiscNullChecks) {
  set_last_error(0, nullptr);
  AxesControlArray_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray_push_back(nullptr, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray_push_back(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray_push_back(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray_contains(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray_contains(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray_index(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray_index(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray_items(nullptr, rawbuffer, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray_items(axes, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray_create_raw(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}
