#include <falcon_core/generic/ListPortTransform_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"

class ListPortTransformTest : public ::testing::Test {
 protected:
  void destroy_string(PortTransformHandle sh) { PortTransform_destroy(sh); }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<PortTransformHandle> created_strings;
  PortTransformHandle track_quantity(const PortTransformHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    sh1 = track_quantity(PortTransform_create(
        InstrumentPort_create_knob(
            String_wrap("name1"),
            Connection_create_barrier_gate(String_wrap("gate1")),
            InstrumentTypes_voltmeter()),
        AnalyticFunction_create_identity()));
    sh2 = track_quantity(PortTransform_create(
        InstrumentPort_create_knob(
            String_wrap("name2"),
            Connection_create_barrier_gate(String_wrap("gate2")),
            InstrumentTypes_voltmeter()),
        AnalyticFunction_create_identity()));
  }
  PortTransformHandle sh1;
  PortTransformHandle sh2;
};

TEST_F(ListPortTransformTest, CreateEmpty) {
  auto handle = ListPortTransform_create_empty();
  EXPECT_TRUE(ListPortTransform_empty(handle));
  EXPECT_EQ(ListPortTransform_size(handle), 0);
  ListPortTransform_destroy(handle);
  EXPECT_THROW(ListPortTransform_destroy(nullptr), std::invalid_argument);
}

TEST_F(ListPortTransformTest, FillValue) {
  auto handle = ListPortTransform_fill_value(3, sh1);
  EXPECT_EQ(ListPortTransform_size(handle), 3);
  ListPortTransform_destroy(handle);
}

TEST_F(ListPortTransformTest, CreateFromArray) {
  PortTransformHandle     arr[2] = {sh1, sh2};
  ListPortTransformHandle handle = ListPortTransform_create(arr, 2);
  EXPECT_EQ(ListPortTransform_size(handle), 2);
  EXPECT_THROW(ListPortTransform_create(nullptr, 2), std::invalid_argument);
  ListPortTransform_destroy(handle);
}

TEST_F(ListPortTransformTest, SizeEmptyInvalid) {
  auto handle = ListPortTransform_create_empty();
  EXPECT_EQ(ListPortTransform_size(handle), 0);
  ListPortTransform_destroy(handle);
  EXPECT_THROW(ListPortTransform_size(nullptr), std::invalid_argument);
}

TEST_F(ListPortTransformTest, EmptyInvalid) {
  auto handle = ListPortTransform_create_empty();
  EXPECT_TRUE(ListPortTransform_empty(handle));
  ListPortTransform_destroy(handle);
  EXPECT_THROW(ListPortTransform_empty(nullptr), std::invalid_argument);
}

TEST_F(ListPortTransformTest, EraseAtClear) {
  auto handle = ListPortTransform_fill_value(2, sh1);
  ListPortTransform_erase_at(handle, 0);
  EXPECT_EQ(ListPortTransform_size(handle), 1);
  ListPortTransform_clear(handle);
  EXPECT_TRUE(ListPortTransform_empty(handle));
  ListPortTransform_destroy(handle);
  EXPECT_THROW(ListPortTransform_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(ListPortTransform_clear(nullptr), std::invalid_argument);
}

TEST_F(ListPortTransformTest, PushBackContainsIndex) {
  auto handle = ListPortTransform_create_empty();
  ListPortTransform_push_back(handle, sh1);
  EXPECT_TRUE(ListPortTransform_contains(handle, sh1));
  EXPECT_EQ(ListPortTransform_index(handle, sh1), 0);
  ListPortTransform_destroy(handle);
  EXPECT_THROW(ListPortTransform_push_back(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(ListPortTransform_contains(nullptr, sh1), std::invalid_argument);
  EXPECT_THROW(ListPortTransform_index(nullptr, sh1), std::invalid_argument);
}

TEST_F(ListPortTransformTest, ItemsAt) {
  PortTransformHandle arr[2] = {sh1, sh2};
  auto                handle = ListPortTransform_create(arr, 2);
  PortTransformHandle out[2];
  EXPECT_EQ(ListPortTransform_items(handle, out, 2), 2);
  ListPortTransform_destroy(handle);
  EXPECT_THROW(ListPortTransform_items(nullptr, out, 2), std::invalid_argument);
  EXPECT_THROW(ListPortTransform_items(handle, nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(ListPortTransform_at(nullptr, 0), std::invalid_argument);
}

TEST_F(ListPortTransformTest, EqualNotEqualIntersection) {
  PortTransformHandle arr[2] = {sh1, sh2};
  auto                h1     = ListPortTransform_create(arr, 2);
  auto                h2     = ListPortTransform_create(arr, 2);
  EXPECT_TRUE(ListPortTransform_equal(h1, h2));
  EXPECT_FALSE(ListPortTransform_not_equal(h1, h2));
  auto h3 = ListPortTransform_intersection(h1, h2);
  EXPECT_EQ(ListPortTransform_size(h3), 2);
  ListPortTransform_destroy(h1);
  ListPortTransform_destroy(h2);
  ListPortTransform_destroy(h3);
  EXPECT_THROW(ListPortTransform_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListPortTransform_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListPortTransform_not_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListPortTransform_not_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListPortTransform_intersection(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListPortTransform_intersection(h1, nullptr),
               std::invalid_argument);
}

TEST_F(ListPortTransformTest, ToJsonFromJson) {
  PortTransformHandle arr[1]  = {sh1};
  auto                handle  = ListPortTransform_create(arr, 1);
  auto                json    = ListPortTransform_to_json_string(handle);
  auto                handle2 = ListPortTransform_from_json_string(json);
  EXPECT_TRUE(ListPortTransform_equal(handle, handle2));
  ListPortTransform_destroy(handle);
  ListPortTransform_destroy(handle2);
  String_destroy(json);
  EXPECT_THROW(ListPortTransform_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListPortTransform_from_json_string(nullptr),
               std::invalid_argument);
}

TEST_F(ListPortTransformTest, FillValueNull) {
  EXPECT_THROW(ListPortTransform_fill_value(3, nullptr), std::invalid_argument);
}

TEST_F(ListPortTransformTest, PushBackNull) {
  auto handle = ListPortTransform_create_empty();
  EXPECT_THROW(ListPortTransform_push_back(handle, nullptr),
               std::invalid_argument);
  ListPortTransform_destroy(handle);
}

TEST_F(ListPortTransformTest, ContainsNull) {
  auto handle = ListPortTransform_create_empty();
  EXPECT_THROW(ListPortTransform_contains(handle, nullptr),
               std::invalid_argument);
  ListPortTransform_destroy(handle);
}

TEST_F(ListPortTransformTest, IndexNull) {
  auto handle = ListPortTransform_create_empty();
  EXPECT_THROW(ListPortTransform_index(handle, nullptr), std::invalid_argument);
  ListPortTransform_destroy(handle);
}

TEST_F(ListPortTransformTest, CreateNullArray) {
  EXPECT_THROW(ListPortTransform_create(nullptr, 2), std::invalid_argument);
}

TEST_F(ListPortTransformTest, At) {
  PortTransformHandle arr[2] = {sh1, sh2};
  auto                handle = ListPortTransform_create(arr, 2);
  auto                at0    = ListPortTransform_at(handle, 0);
  auto                at1    = ListPortTransform_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListPortTransform_destroy(handle);
  EXPECT_THROW(ListPortTransform_at(nullptr, 0), std::invalid_argument);
}
