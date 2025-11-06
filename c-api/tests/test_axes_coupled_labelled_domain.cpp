#include <gtest/gtest.h>

#include <vector>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/AxesCoupledLabelledDomain_c_api.h"
#include "falcon_core/math/domains/CoupledLabelledDomain_c_api.h"

class AxesCoupledLabelledDomainTest : public ::testing::Test {
 protected:
  void SetUp() override {
    axes = AxesCoupledLabelledDomain_create_empty();
    auto item1 = track_item(CoupledLabelledDomain_create_empty());
    auto item2 = track_item(CoupledLabelledDomain_create_empty());
    AxesCoupledLabelledDomain_push_back(axes, item1);
    AxesCoupledLabelledDomain_push_back(axes, item2);

    axes2 = AxesCoupledLabelledDomain_create_empty();
    AxesCoupledLabelledDomain_push_back(axes2, item1);
    AxesCoupledLabelledDomain_push_back(axes2, item2);
  }

  void TearDown() override {
    if (axes) {
      AxesCoupledLabelledDomain_destroy(axes);
      axes = nullptr;
    }
    if (axes2) {
      AxesCoupledLabelledDomain_destroy(axes2);
      axes2 = nullptr;
    }
    for (auto h : created_items) {
      CoupledLabelledDomain_destroy(h);
    }
    created_items.clear();
  }

  CoupledLabelledDomainHandle track_item(CoupledLabelledDomainHandle h) {
    created_items.push_back(h);
    return h;
  }

  AxesCoupledLabelledDomainHandle axes  = nullptr;
  AxesCoupledLabelledDomainHandle axes2 = nullptr;
  CoupledLabelledDomainHandle     rawbuffer[2];

  std::vector<CoupledLabelledDomainHandle> created_items;
};

TEST_F(AxesCoupledLabelledDomainTest, CreateDestroy) {
  auto h = AxesCoupledLabelledDomain_create_empty();
  AxesCoupledLabelledDomain_destroy(h);
  EXPECT_THROW(AxesCoupledLabelledDomain_create(nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesCoupledLabelledDomain_destroy(nullptr),
               std::invalid_argument);
  EXPECT_NO_THROW(
      AxesCoupledLabelledDomain_create(CoupledLabelledDomain_create_empty()));
}

TEST_F(AxesCoupledLabelledDomainTest, AccessorsAndMutators) {
  EXPECT_EQ(AxesCoupledLabelledDomain_size(axes), 2u);

  CoupledLabelledDomainHandle out[1] = {CoupledLabelledDomain_create_empty()};
  auto                        h2 = AxesCoupledLabelledDomain_create_raw(out, 1);
  if (h2) AxesCoupledLabelledDomain_destroy(h2);

  AxesCoupledLabelledDomain_push_back(axes,
                                      CoupledLabelledDomain_create_empty());
  CoupledLabelledDomainHandle out2[3];
  EXPECT_EQ(AxesCoupledLabelledDomain_items(axes, out2, 3), 3u);
  for (size_t i = 0; i < 3; ++i) {
    CoupledLabelledDomain_destroy(out2[i]);
  }

  AxesCoupledLabelledDomain_erase_at(axes, 2);
  AxesCoupledLabelledDomain_clear(axes);
  EXPECT_TRUE(AxesCoupledLabelledDomain_empty(axes));
}

TEST_F(AxesCoupledLabelledDomainTest, ContainsIndexEquality) {
  EXPECT_NO_THROW(AxesCoupledLabelledDomain_contains(
      axes, AxesCoupledLabelledDomain_at(axes, 0)));
  EXPECT_NO_THROW(AxesCoupledLabelledDomain_index(
      axes, AxesCoupledLabelledDomain_at(axes, 0)));
  EXPECT_NO_THROW(AxesCoupledLabelledDomain_equal(axes, axes2));
}

TEST_F(AxesCoupledLabelledDomainTest, SerializationRoundTrip) {
  EXPECT_THROW(AxesCoupledLabelledDomain_from_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesCoupledLabelledDomain_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_NO_THROW({
    auto json   = AxesCoupledLabelledDomain_to_json_string(axes);
    auto loaded = AxesCoupledLabelledDomain_from_json_string(json);
    AxesCoupledLabelledDomain_destroy(loaded);
    String_destroy(json);
  });
}

TEST_F(AxesCoupledLabelledDomainTest, EqualityWorks) {
  EXPECT_THROW(AxesCoupledLabelledDomain_equal(axes, nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesCoupledLabelledDomain_not_equal(nullptr, axes2),
               std::invalid_argument);
  EXPECT_NO_THROW(AxesCoupledLabelledDomain_equal(axes, axes));
  EXPECT_NO_THROW(AxesCoupledLabelledDomain_not_equal(axes, axes2));
}

TEST_F(AxesCoupledLabelledDomainTest, Intersection) {
  EXPECT_THROW(AxesCoupledLabelledDomain_intersection(nullptr, axes2),
               std::invalid_argument);
  EXPECT_THROW(AxesCoupledLabelledDomain_intersection(axes, nullptr),
               std::invalid_argument);
  EXPECT_NO_THROW(AxesCoupledLabelledDomain_intersection(axes, axes2));
}

TEST_F(AxesCoupledLabelledDomainTest, MiscNullChecks) {
  EXPECT_THROW(AxesCoupledLabelledDomain_destroy(nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesCoupledLabelledDomain_push_back(nullptr, nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesCoupledLabelledDomain_push_back(axes, nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesCoupledLabelledDomain_size(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesCoupledLabelledDomain_empty(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesCoupledLabelledDomain_erase_at(nullptr, 0),
               std::invalid_argument);
  EXPECT_THROW(AxesCoupledLabelledDomain_clear(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesCoupledLabelledDomain_push_back(nullptr, 0),
               std::invalid_argument);
  EXPECT_THROW(AxesCoupledLabelledDomain_contains(nullptr, 0),
               std::invalid_argument);
  EXPECT_THROW(AxesCoupledLabelledDomain_contains(axes, nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesCoupledLabelledDomain_index(nullptr, 0),
               std::invalid_argument);
  EXPECT_THROW(AxesCoupledLabelledDomain_index(axes, nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesCoupledLabelledDomain_items(nullptr, rawbuffer, 2),
               std::invalid_argument);
  EXPECT_THROW(AxesCoupledLabelledDomain_items(axes, nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(AxesCoupledLabelledDomain_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesCoupledLabelledDomain_create_raw(nullptr, 2),
               std::invalid_argument);
}
