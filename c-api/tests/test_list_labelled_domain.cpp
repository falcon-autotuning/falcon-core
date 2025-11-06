#include <falcon_core/generic/ListLabelledDomain_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "falcon_core/math/domains/LabelledDomain_c_api.h"

class ListLabelledDomainTest : public ::testing::Test {
 protected:
  void destroy_string(LabelledDomainHandle sh) { LabelledDomain_destroy(sh); }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<LabelledDomainHandle> created_strings;
  LabelledDomainHandle track_quantity(const LabelledDomainHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    sh1 = track_quantity(LabelledDomain_create_primitive_knob(
        String_wrap("knob1"),
        0.0,
        1.0,
        Connection_create_plunger_gate(String_wrap("A")),
        InstrumentTypes_voltmeter(),
        true,
        true,
        SymbolUnit_create_volt()));
    sh2 = track_quantity(LabelledDomain_create_primitive_knob(
        String_wrap("knob1"),
        0.0,
        1.0,
        Connection_create_plunger_gate(String_wrap("B")),
        InstrumentTypes_voltmeter(),
        true,
        true,
        SymbolUnit_create_volt()));
  }
  LabelledDomainHandle sh1;
  LabelledDomainHandle sh2;
};

TEST_F(ListLabelledDomainTest, CreateEmpty) {
  auto handle = ListLabelledDomain_create_empty();
  EXPECT_TRUE(ListLabelledDomain_empty(handle));
  EXPECT_EQ(ListLabelledDomain_size(handle), 0);
  ListLabelledDomain_destroy(handle);
  EXPECT_THROW(ListLabelledDomain_destroy(nullptr), std::invalid_argument);
}

TEST_F(ListLabelledDomainTest, FillValue) {
  auto handle = ListLabelledDomain_fill_value(3, sh1);
  EXPECT_EQ(ListLabelledDomain_size(handle), 3);
  ListLabelledDomain_destroy(handle);
}

TEST_F(ListLabelledDomainTest, CreateFromArray) {
  LabelledDomainHandle     arr[2] = {sh1, sh2};
  ListLabelledDomainHandle handle = ListLabelledDomain_create(arr, 2);
  EXPECT_EQ(ListLabelledDomain_size(handle), 2);
  EXPECT_THROW(ListLabelledDomain_create(nullptr, 2), std::invalid_argument);
  ListLabelledDomain_destroy(handle);
}

TEST_F(ListLabelledDomainTest, SizeEmptyInvalid) {
  auto handle = ListLabelledDomain_create_empty();
  EXPECT_EQ(ListLabelledDomain_size(handle), 0);
  ListLabelledDomain_destroy(handle);
  EXPECT_THROW(ListLabelledDomain_size(nullptr), std::invalid_argument);
}

TEST_F(ListLabelledDomainTest, EmptyInvalid) {
  auto handle = ListLabelledDomain_create_empty();
  EXPECT_TRUE(ListLabelledDomain_empty(handle));
  ListLabelledDomain_destroy(handle);
  EXPECT_THROW(ListLabelledDomain_empty(nullptr), std::invalid_argument);
}

TEST_F(ListLabelledDomainTest, EraseAtClear) {
  auto handle = ListLabelledDomain_fill_value(2, sh1);
  ListLabelledDomain_erase_at(handle, 0);
  EXPECT_EQ(ListLabelledDomain_size(handle), 1);
  ListLabelledDomain_clear(handle);
  EXPECT_TRUE(ListLabelledDomain_empty(handle));
  ListLabelledDomain_destroy(handle);
  EXPECT_THROW(ListLabelledDomain_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(ListLabelledDomain_clear(nullptr), std::invalid_argument);
}

TEST_F(ListLabelledDomainTest, PushBackContainsIndex) {
  auto handle = ListLabelledDomain_create_empty();
  ListLabelledDomain_push_back(handle, sh1);
  EXPECT_TRUE(ListLabelledDomain_contains(handle, sh1));
  EXPECT_EQ(ListLabelledDomain_index(handle, sh1), 0);
  ListLabelledDomain_destroy(handle);
  EXPECT_THROW(ListLabelledDomain_push_back(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledDomain_contains(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledDomain_index(nullptr, sh1), std::invalid_argument);
}

TEST_F(ListLabelledDomainTest, ItemsAt) {
  LabelledDomainHandle arr[2] = {sh1, sh2};
  auto                 handle = ListLabelledDomain_create(arr, 2);
  LabelledDomainHandle out[2];
  EXPECT_EQ(ListLabelledDomain_items(handle, out, 2), 2);
  ListLabelledDomain_destroy(handle);
  EXPECT_THROW(ListLabelledDomain_items(nullptr, out, 2),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledDomain_items(handle, nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledDomain_at(nullptr, 0), std::invalid_argument);
}

TEST_F(ListLabelledDomainTest, EqualNotEqualIntersection) {
  LabelledDomainHandle arr[2] = {sh1, sh2};
  auto                 h1     = ListLabelledDomain_create(arr, 2);
  auto                 h2     = ListLabelledDomain_create(arr, 2);
  EXPECT_TRUE(ListLabelledDomain_equal(h1, h2));
  EXPECT_FALSE(ListLabelledDomain_not_equal(h1, h2));
  auto h3 = ListLabelledDomain_intersection(h1, h2);
  EXPECT_EQ(ListLabelledDomain_size(h3), 2);
  ListLabelledDomain_destroy(h1);
  ListLabelledDomain_destroy(h2);
  ListLabelledDomain_destroy(h3);
  EXPECT_THROW(ListLabelledDomain_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListLabelledDomain_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListLabelledDomain_not_equal(h1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledDomain_not_equal(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledDomain_intersection(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledDomain_intersection(h1, nullptr),
               std::invalid_argument);
}

TEST_F(ListLabelledDomainTest, ToJsonFromJson) {
  LabelledDomainHandle arr[1]  = {sh1};
  auto                 handle  = ListLabelledDomain_create(arr, 1);
  auto                 json    = ListLabelledDomain_to_json_string(handle);
  auto                 handle2 = ListLabelledDomain_from_json_string(json);
  EXPECT_TRUE(ListLabelledDomain_equal(handle, handle2));
  ListLabelledDomain_destroy(handle);
  ListLabelledDomain_destroy(handle2);
  String_destroy(json);
  EXPECT_THROW(ListLabelledDomain_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledDomain_from_json_string(nullptr),
               std::invalid_argument);
}

TEST_F(ListLabelledDomainTest, FillValueNull) {
  EXPECT_THROW(ListLabelledDomain_fill_value(3, nullptr),
               std::invalid_argument);
}

TEST_F(ListLabelledDomainTest, PushBackNull) {
  auto handle = ListLabelledDomain_create_empty();
  EXPECT_THROW(ListLabelledDomain_push_back(handle, nullptr),
               std::invalid_argument);
  ListLabelledDomain_destroy(handle);
}

TEST_F(ListLabelledDomainTest, ContainsNull) {
  auto handle = ListLabelledDomain_create_empty();
  EXPECT_THROW(ListLabelledDomain_contains(handle, nullptr),
               std::invalid_argument);
  ListLabelledDomain_destroy(handle);
}

TEST_F(ListLabelledDomainTest, IndexNull) {
  auto handle = ListLabelledDomain_create_empty();
  EXPECT_THROW(ListLabelledDomain_index(handle, nullptr),
               std::invalid_argument);
  ListLabelledDomain_destroy(handle);
}

TEST_F(ListLabelledDomainTest, CreateNullArray) {
  EXPECT_THROW(ListLabelledDomain_create(nullptr, 2), std::invalid_argument);
}

TEST_F(ListLabelledDomainTest, At) {
  LabelledDomainHandle arr[2] = {sh1, sh2};
  auto                 handle = ListLabelledDomain_create(arr, 2);
  auto                 at0    = ListLabelledDomain_at(handle, 0);
  auto                 at1    = ListLabelledDomain_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListLabelledDomain_destroy(handle);
  EXPECT_THROW(ListLabelledDomain_at(nullptr, 0), std::invalid_argument);
}
