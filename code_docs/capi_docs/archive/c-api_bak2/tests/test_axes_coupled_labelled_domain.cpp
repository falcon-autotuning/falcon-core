#include <gtest/gtest.h>

#include <vector>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/AxesCoupledLabelledDomain_c_api.h"
#include "falcon_core/math/domains/CoupledLabelledDomain_c_api.h"

class AxesCoupledLabelledDomainTest : public ::testing::Test {
 protected:
  void SetUp() override {
    axes       = AxesCoupledLabelledDomain_create_empty();
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
  set_last_error(0, nullptr);
  AxesCoupledLabelledDomain_create(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesCoupledLabelledDomain_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW(
      AxesCoupledLabelledDomain_create(CoupledLabelledDomain_create_empty()));
}

TEST_F(AxesCoupledLabelledDomainTest, AccessorsAndMutators) {
  EXPECT_EQ(AxesCoupledLabelledDomain_size(axes), 2u);

  CoupledLabelledDomainHandle out[1] = {CoupledLabelledDomain_create_empty()};

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
  set_last_error(0, nullptr);
  AxesCoupledLabelledDomain_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesCoupledLabelledDomain_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW({
    auto json   = AxesCoupledLabelledDomain_to_json_string(axes);
    auto loaded = AxesCoupledLabelledDomain_from_json_string(json);
    AxesCoupledLabelledDomain_destroy(loaded);
    String_destroy(json);
  });
}

TEST_F(AxesCoupledLabelledDomainTest, EqualityWorks) {
  set_last_error(0, nullptr);
  AxesCoupledLabelledDomain_equal(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesCoupledLabelledDomain_not_equal(nullptr, axes2);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW(AxesCoupledLabelledDomain_equal(axes, axes));
  EXPECT_NO_THROW(AxesCoupledLabelledDomain_not_equal(axes, axes2));
}

TEST_F(AxesCoupledLabelledDomainTest, Intersection) {
  set_last_error(0, nullptr);
  AxesCoupledLabelledDomain_intersection(nullptr, axes2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesCoupledLabelledDomain_intersection(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW(AxesCoupledLabelledDomain_intersection(axes, axes2));
}

TEST_F(AxesCoupledLabelledDomainTest, MiscNullChecks) {
  set_last_error(0, nullptr);
  AxesCoupledLabelledDomain_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesCoupledLabelledDomain_push_back(nullptr, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesCoupledLabelledDomain_push_back(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesCoupledLabelledDomain_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesCoupledLabelledDomain_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesCoupledLabelledDomain_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesCoupledLabelledDomain_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesCoupledLabelledDomain_push_back(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesCoupledLabelledDomain_contains(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesCoupledLabelledDomain_contains(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesCoupledLabelledDomain_index(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesCoupledLabelledDomain_index(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesCoupledLabelledDomain_items(nullptr, rawbuffer, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesCoupledLabelledDomain_items(axes, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesCoupledLabelledDomain_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
}
