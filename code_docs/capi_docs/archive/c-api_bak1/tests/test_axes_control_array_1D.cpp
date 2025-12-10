#include <gtest/gtest.h>

#include <vector>

#include "falcon_core/generic/ErrorHandling_c_api.h"
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
    auto item1 = track_ca1d(ControlArray1D_from_data(data, shape, 1));
    auto item2 = track_ca1d(ControlArray1D_from_data(data, shape, 1));
    AxesControlArray1D_push_back(axes, item1);
    AxesControlArray1D_push_back(axes, item2);

    axes2 = AxesControlArray1D_create_empty();
    AxesControlArray1D_push_back(axes2, item1);
    AxesControlArray1D_push_back(axes2, item2);
  }

  void TearDown() override {
    if (axes) {
      AxesControlArray1D_destroy(axes);
      axes = nullptr;
    }
    if (axes2) {
      AxesControlArray1D_destroy(axes2);
      axes2 = nullptr;
    }
    for (auto h : created_items) {
      ControlArray1D_destroy(h);
    }
    created_items.clear();
  }

  ControlArray1DHandle track_ca1d(ControlArray1DHandle h) {
    created_items.push_back(h);
    return h;
  }

  AxesControlArray1DHandle axes  = nullptr;
  AxesControlArray1DHandle axes2 = nullptr;
  ControlArray1DHandle     rawbuffer[2];
  double                   data[3];
  size_t                   shape[1];
  ControlArray1DHandle     ca;
  ControlArray1DHandle     ca2;
  FArrayDoubleHandle       fa;

  std::vector<ControlArray1DHandle> created_items;
};

TEST_F(AxesControlArray1DTest, CreateDestroy) {
  auto h = AxesControlArray1D_create_empty();
  AxesControlArray1D_destroy(h);
  set_last_error(0, nullptr);
  AxesControlArray1D_create(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray1D_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  EXPECT_NO_THROW(AxesControlArray1D_create(ListControlArray1D_create_empty()));
}

TEST_F(AxesControlArray1DTest, AccessorsAndMutators) {
  EXPECT_EQ(AxesControlArray1D_size(axes), 2u);

  ControlArray1DHandle out[1] = {ControlArray1D_from_data(data, shape, 1)};

  AxesControlArray1D_push_back(axes, ControlArray1D_from_data(data, shape, 1));
  ControlArray1DHandle out2[3];
  EXPECT_EQ(AxesControlArray1D_items(axes, out2, 3), 3u);
  for (size_t i = 0; i < 3; ++i) {
    ControlArray1D_destroy(out2[i]);
  }
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
  set_last_error(0, nullptr);
  AxesControlArray1D_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray1D_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW({
    auto json   = AxesControlArray1D_to_json_string(axes);
    auto loaded = AxesControlArray1D_from_json_string(json);
    AxesControlArray1D_destroy(loaded);
    String_destroy(json);
  });
}

TEST_F(AxesControlArray1DTest, EqualityWorks) {
  set_last_error(0, nullptr);
  AxesControlArray1D_equal(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray1D_not_equal(nullptr, axes2);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW(AxesControlArray1D_equal(axes, axes));
  EXPECT_NO_THROW(AxesControlArray1D_not_equal(axes, axes2));
}

TEST_F(AxesControlArray1DTest, Intersection) {
  set_last_error(0, nullptr);
  AxesControlArray1D_intersection(nullptr, axes2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray1D_intersection(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW(AxesControlArray1D_intersection(axes, axes2));
}

TEST_F(AxesControlArray1DTest, MiscNullChecks) {
  set_last_error(0, nullptr);
  AxesControlArray1D_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray1D_push_back(nullptr, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray1D_push_back(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray1D_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray1D_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray1D_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray1D_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray1D_push_back(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray1D_contains(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray1D_contains(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray1D_index(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray1D_index(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray1D_items(nullptr, rawbuffer, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray1D_items(axes, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesControlArray1D_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
}
