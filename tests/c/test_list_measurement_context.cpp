#include <falcon-core/generic/ListMeasurementContext_c_api.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

class ListMeasurementContextTest : public ::testing::Test {
 protected:
  void destroy_string(MeasurementContextHandle sh) {
    MeasurementContext_destroy(sh);
  }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<MeasurementContextHandle> created_strings;
  MeasurementContextHandle track_quantity(const MeasurementContextHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    sh1 = track_quantity(MeasurementContext_create(
        Connection_create_plunger_gate(String_wrap("Conn1")),
        InstrumentTypes_voltmeter()));
    sh2 = track_quantity(MeasurementContext_create(
        Connection_create_plunger_gate(String_wrap("Conn2")),
        InstrumentTypes_voltmeter()));
  }
  MeasurementContextHandle sh1;
  MeasurementContextHandle sh2;
};

TEST_F(ListMeasurementContextTest, CreateEmpty) {
  auto handle = ListMeasurementContext_create_empty();
  EXPECT_TRUE(ListMeasurementContext_empty(handle));
  EXPECT_EQ(ListMeasurementContext_size(handle), 0);
  ListMeasurementContext_destroy(handle);
  set_last_error(0, nullptr);
  ListMeasurementContext_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListMeasurementContextTest, FillValue) {
  auto handle = ListMeasurementContext_fill_value(3, sh1);
  EXPECT_EQ(ListMeasurementContext_size(handle), 3);
  ListMeasurementContext_destroy(handle);
}

TEST_F(ListMeasurementContextTest, CreateFromArray) {
  MeasurementContextHandle     arr[2] = {sh1, sh2};
  ListMeasurementContextHandle handle = ListMeasurementContext_create(arr, 2);
  EXPECT_EQ(ListMeasurementContext_size(handle), 2);
  set_last_error(0, nullptr);
  ListMeasurementContext_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  ListMeasurementContext_destroy(handle);
}

TEST_F(ListMeasurementContextTest, SizeEmptyInvalid) {
  auto handle = ListMeasurementContext_create_empty();
  EXPECT_EQ(ListMeasurementContext_size(handle), 0);
  ListMeasurementContext_destroy(handle);
  set_last_error(0, nullptr);
  ListMeasurementContext_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListMeasurementContextTest, EmptyInvalid) {
  auto handle = ListMeasurementContext_create_empty();
  EXPECT_TRUE(ListMeasurementContext_empty(handle));
  ListMeasurementContext_destroy(handle);
  set_last_error(0, nullptr);
  ListMeasurementContext_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListMeasurementContextTest, EraseAtClear) {
  auto handle = ListMeasurementContext_fill_value(2, sh1);
  ListMeasurementContext_erase_at(handle, 0);
  EXPECT_EQ(ListMeasurementContext_size(handle), 1);
  ListMeasurementContext_clear(handle);
  EXPECT_TRUE(ListMeasurementContext_empty(handle));
  ListMeasurementContext_destroy(handle);
  set_last_error(0, nullptr);
  ListMeasurementContext_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListMeasurementContext_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListMeasurementContextTest, PushBackContainsIndex) {
  auto handle = ListMeasurementContext_create_empty();
  ListMeasurementContext_push_back(handle, sh1);
  EXPECT_TRUE(ListMeasurementContext_contains(handle, sh1));
  EXPECT_EQ(ListMeasurementContext_index(handle, sh1), 0);
  ListMeasurementContext_destroy(handle);
  set_last_error(0, nullptr);
  ListMeasurementContext_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListMeasurementContext_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListMeasurementContext_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListMeasurementContextTest, ItemsAt) {
  MeasurementContextHandle arr[2] = {sh1, sh2};
  auto                     handle = ListMeasurementContext_create(arr, 2);
  MeasurementContextHandle out[2];
  EXPECT_EQ(ListMeasurementContext_items(handle, out, 2), 2);
  ListMeasurementContext_destroy(handle);
  set_last_error(0, nullptr);
  ListMeasurementContext_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListMeasurementContext_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListMeasurementContext_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListMeasurementContextTest, EqualNotEqualIntersection) {
  MeasurementContextHandle arr[2] = {sh1, sh2};
  auto                     h1     = ListMeasurementContext_create(arr, 2);
  auto                     h2     = ListMeasurementContext_create(arr, 2);
  EXPECT_TRUE(ListMeasurementContext_equal(h1, h2));
  EXPECT_FALSE(ListMeasurementContext_not_equal(h1, h2));
  auto h3 = ListMeasurementContext_intersection(h1, h2);
  EXPECT_EQ(ListMeasurementContext_size(h3), 2);
  ListMeasurementContext_destroy(h1);
  ListMeasurementContext_destroy(h2);
  ListMeasurementContext_destroy(h3);
  set_last_error(0, nullptr);
  ListMeasurementContext_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListMeasurementContext_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListMeasurementContext_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListMeasurementContext_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListMeasurementContext_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListMeasurementContext_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListMeasurementContextTest, ToJsonFromJson) {
  MeasurementContextHandle arr[1] = {sh1};
  auto                     handle = ListMeasurementContext_create(arr, 1);
  auto                     json = ListMeasurementContext_to_json_string(handle);
  auto handle2                  = ListMeasurementContext_from_json_string(json);
  EXPECT_TRUE(ListMeasurementContext_equal(handle, handle2));
  ListMeasurementContext_destroy(handle);
  ListMeasurementContext_destroy(handle2);
  String_destroy(json);
  set_last_error(0, nullptr);
  ListMeasurementContext_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListMeasurementContext_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListMeasurementContextTest, FillValueNull) {
  set_last_error(0, nullptr);
  ListMeasurementContext_fill_value(3, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListMeasurementContextTest, PushBackNull) {
  auto handle = ListMeasurementContext_create_empty();
  set_last_error(0, nullptr);
  ListMeasurementContext_push_back(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListMeasurementContext_destroy(handle);
}

TEST_F(ListMeasurementContextTest, ContainsNull) {
  auto handle = ListMeasurementContext_create_empty();
  set_last_error(0, nullptr);
  ListMeasurementContext_contains(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListMeasurementContext_destroy(handle);
}

TEST_F(ListMeasurementContextTest, IndexNull) {
  auto handle = ListMeasurementContext_create_empty();
  set_last_error(0, nullptr);
  ListMeasurementContext_index(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListMeasurementContext_destroy(handle);
}

TEST_F(ListMeasurementContextTest, CreateNullArray) {
  set_last_error(0, nullptr);
  ListMeasurementContext_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListMeasurementContextTest, At) {
  MeasurementContextHandle arr[2] = {sh1, sh2};
  auto                     handle = ListMeasurementContext_create(arr, 2);
  auto                     at0    = ListMeasurementContext_at(handle, 0);
  auto                     at1    = ListMeasurementContext_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListMeasurementContext_destroy(handle);
  set_last_error(0, nullptr);
  ListMeasurementContext_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
