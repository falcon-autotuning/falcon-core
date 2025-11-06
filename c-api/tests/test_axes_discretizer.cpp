#include <gtest/gtest.h>

#include <vector>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/AxesDiscretizer_c_api.h"
#include "falcon_core/math/discrete_spaces/Discretizer_c_api.h"

class AxesDiscretizerTest : public ::testing::Test {
 protected:
  void SetUp() override {
    axes = AxesDiscretizer_create_empty();
    auto item1 = track_discretizer(Discretizer_create_cartesian_discretizer(0.5));
    auto item2 = track_discretizer(Discretizer_create_cartesian_discretizer(0.5));
    AxesDiscretizer_push_back(axes, item1);
    AxesDiscretizer_push_back(axes, item2);

    axes2 = AxesDiscretizer_create_empty();
    AxesDiscretizer_push_back(axes2, item1);
    AxesDiscretizer_push_back(axes2, item2);
  }

  void TearDown() override {
    if (axes) {
      AxesDiscretizer_destroy(axes);
      axes = nullptr;
    }
    if (axes2) {
      AxesDiscretizer_destroy(axes2);
      axes2 = nullptr;
    }
    for (auto h : created_items) {
      Discretizer_destroy(h);
    }
    created_items.clear();
  }

  DiscretizerHandle track_discretizer(DiscretizerHandle h) {
    created_items.push_back(h);
    return h;
  }

  AxesDiscretizerHandle axes  = nullptr;
  AxesDiscretizerHandle axes2 = nullptr;
  DiscretizerHandle     rawbuffer[2];
  std::vector<DiscretizerHandle> created_items;
};

TEST_F(AxesDiscretizerTest, CreateDestroy) {
  auto h = AxesDiscretizer_create_empty();
  AxesDiscretizer_destroy(h);
  EXPECT_THROW(AxesDiscretizer_create(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesDiscretizer_destroy(nullptr), std::invalid_argument);
  EXPECT_NO_THROW(AxesDiscretizer_create(AxesDiscretizer_create_empty()));
}

TEST_F(AxesDiscretizerTest, AccessorsAndMutators) {
  EXPECT_EQ(AxesDiscretizer_size(axes), 2u);

  DiscretizerHandle out[1] = {AxesDiscretizer_create_empty()};
  auto              h2     = AxesDiscretizer_create_raw(out, 1);
  if (h2) AxesDiscretizer_destroy(h2);

  AxesDiscretizer_push_back(axes,
                            track_discretizer(Discretizer_create_cartesian_discretizer(0.5)));
  DiscretizerHandle out2[3];
  EXPECT_EQ(AxesDiscretizer_items(axes, out2, 3), 3u);
  for (size_t i = 0; i < 3; ++i) {
    Discretizer_destroy(out2[i]);
  }

  AxesDiscretizer_erase_at(axes, 2);
  AxesDiscretizer_clear(axes);
  EXPECT_TRUE(AxesDiscretizer_empty(axes));
}

TEST_F(AxesDiscretizerTest, ContainsIndexEquality) {
  EXPECT_NO_THROW(AxesDiscretizer_contains(axes, AxesDiscretizer_at(axes, 0)));
  EXPECT_NO_THROW(AxesDiscretizer_index(axes, AxesDiscretizer_at(axes, 0)));
  EXPECT_NO_THROW(AxesDiscretizer_equal(axes, axes2));
}

TEST_F(AxesDiscretizerTest, SerializationRoundTrip) {
  EXPECT_THROW(AxesDiscretizer_from_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesDiscretizer_to_json_string(nullptr), std::invalid_argument);
  EXPECT_NO_THROW({
    auto json   = AxesDiscretizer_to_json_string(axes);
    auto loaded = AxesDiscretizer_from_json_string(json);
    AxesDiscretizer_destroy(loaded);
    String_destroy(json);
  });
}

TEST_F(AxesDiscretizerTest, EqualityWorks) {
  EXPECT_THROW(AxesDiscretizer_equal(axes, nullptr), std::invalid_argument);
  EXPECT_THROW(AxesDiscretizer_not_equal(nullptr, axes2),
               std::invalid_argument);
  EXPECT_NO_THROW(AxesDiscretizer_equal(axes, axes));
  EXPECT_NO_THROW(AxesDiscretizer_not_equal(axes, axes2));
}

TEST_F(AxesDiscretizerTest, Intersection) {
  EXPECT_THROW(AxesDiscretizer_intersection(nullptr, axes2),
               std::invalid_argument);
  EXPECT_THROW(AxesDiscretizer_intersection(axes, nullptr),
               std::invalid_argument);
  EXPECT_NO_THROW(AxesDiscretizer_intersection(axes, axes2));
}

TEST_F(AxesDiscretizerTest, MiscNullChecks) {
  EXPECT_THROW(AxesDiscretizer_destroy(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesDiscretizer_push_back(nullptr, nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesDiscretizer_push_back(axes, nullptr), std::invalid_argument);
  EXPECT_THROW(AxesDiscretizer_size(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesDiscretizer_empty(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesDiscretizer_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesDiscretizer_clear(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesDiscretizer_push_back(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesDiscretizer_contains(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesDiscretizer_contains(axes, nullptr), std::invalid_argument);
  EXPECT_THROW(AxesDiscretizer_index(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesDiscretizer_index(axes, nullptr), std::invalid_argument);
  EXPECT_THROW(AxesDiscretizer_items(nullptr, rawbuffer, 2),
               std::invalid_argument);
  EXPECT_THROW(AxesDiscretizer_items(axes, nullptr, 2), std::invalid_argument);
  EXPECT_THROW(AxesDiscretizer_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesDiscretizer_create_raw(nullptr, 2), std::invalid_argument);
}
