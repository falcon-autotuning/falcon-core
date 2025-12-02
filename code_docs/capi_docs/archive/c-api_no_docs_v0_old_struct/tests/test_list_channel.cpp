#include <falcon_core/generic/ListChannel_c_api.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

class ListChannelTest : public ::testing::Test {
 protected:
  void destroy_string(ChannelHandle sh) { Channel_destroy(sh); }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<ChannelHandle> created_strings;
  ChannelHandle              track_quantity(const ChannelHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    sh1 = track_quantity(Channel_create(String_wrap("gate1")));
    sh2 = track_quantity(Channel_create(String_wrap("gate2")));
  }
  ChannelHandle sh1;
  ChannelHandle sh2;
};

TEST_F(ListChannelTest, CreateEmpty) {
  auto handle = ListChannel_create_empty();
  EXPECT_TRUE(ListChannel_empty(handle));
  EXPECT_EQ(ListChannel_size(handle), 0);
  ListChannel_destroy(handle);
  set_last_error(0, nullptr);
  ListChannel_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListChannelTest, FillValue) {
  auto handle = ListChannel_fill_value(3, sh1);
  EXPECT_EQ(ListChannel_size(handle), 3);
  ListChannel_destroy(handle);
}

TEST_F(ListChannelTest, CreateFromArray) {
  ChannelHandle     arr[2] = {sh1, sh2};
  ListChannelHandle handle = ListChannel_create(arr, 2);
  EXPECT_EQ(ListChannel_size(handle), 2);
  set_last_error(0, nullptr);
  ListChannel_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  ListChannel_destroy(handle);
}

TEST_F(ListChannelTest, SizeEmptyInvalid) {
  auto handle = ListChannel_create_empty();
  EXPECT_EQ(ListChannel_size(handle), 0);
  ListChannel_destroy(handle);
  set_last_error(0, nullptr);
  ListChannel_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListChannelTest, EmptyInvalid) {
  auto handle = ListChannel_create_empty();
  EXPECT_TRUE(ListChannel_empty(handle));
  ListChannel_destroy(handle);
  set_last_error(0, nullptr);
  ListChannel_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListChannelTest, EraseAtClear) {
  auto handle = ListChannel_fill_value(2, sh1);
  ListChannel_erase_at(handle, 0);
  EXPECT_EQ(ListChannel_size(handle), 1);
  ListChannel_clear(handle);
  EXPECT_TRUE(ListChannel_empty(handle));
  ListChannel_destroy(handle);
  set_last_error(0, nullptr);
  ListChannel_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListChannel_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListChannelTest, PushBackContainsIndex) {
  auto handle = ListChannel_create_empty();
  ListChannel_push_back(handle, sh1);
  EXPECT_TRUE(ListChannel_contains(handle, sh1));
  EXPECT_EQ(ListChannel_index(handle, sh1), 0);
  ListChannel_destroy(handle);
  set_last_error(0, nullptr);
  ListChannel_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListChannel_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListChannel_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListChannelTest, ItemsAt) {
  ChannelHandle arr[2] = {sh1, sh2};
  auto          handle = ListChannel_create(arr, 2);
  ChannelHandle out[2];
  EXPECT_EQ(ListChannel_items(handle, out, 2), 2);
  ListChannel_destroy(handle);
  set_last_error(0, nullptr);
  ListChannel_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListChannel_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListChannel_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListChannelTest, EqualNotEqualIntersection) {
  ChannelHandle arr[2] = {sh1, sh2};
  auto          h1     = ListChannel_create(arr, 2);
  auto          h2     = ListChannel_create(arr, 2);
  EXPECT_TRUE(ListChannel_equal(h1, h2));
  EXPECT_FALSE(ListChannel_not_equal(h1, h2));
  auto h3 = ListChannel_intersection(h1, h2);
  EXPECT_EQ(ListChannel_size(h3), 2);
  ListChannel_destroy(h1);
  ListChannel_destroy(h2);
  ListChannel_destroy(h3);
  set_last_error(0, nullptr);
  ListChannel_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListChannel_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListChannel_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListChannel_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListChannel_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListChannel_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListChannelTest, ToJsonFromJson) {
  ChannelHandle arr[1]  = {sh1};
  auto          handle  = ListChannel_create(arr, 1);
  auto          json    = ListChannel_to_json_string(handle);
  auto          handle2 = ListChannel_from_json_string(json);
  EXPECT_TRUE(ListChannel_equal(handle, handle2));
  ListChannel_destroy(handle);
  ListChannel_destroy(handle2);
  String_destroy(json);
  set_last_error(0, nullptr);
  ListChannel_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListChannel_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListChannelTest, FillValueNull) {
  set_last_error(0, nullptr);
  ListChannel_fill_value(3, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListChannelTest, PushBackNull) {
  auto handle = ListChannel_create_empty();
  set_last_error(0, nullptr);
  ListChannel_push_back(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListChannel_destroy(handle);
}

TEST_F(ListChannelTest, ContainsNull) {
  auto handle = ListChannel_create_empty();
  set_last_error(0, nullptr);
  ListChannel_contains(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListChannel_destroy(handle);
}

TEST_F(ListChannelTest, IndexNull) {
  auto handle = ListChannel_create_empty();
  set_last_error(0, nullptr);
  ListChannel_index(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListChannel_destroy(handle);
}

TEST_F(ListChannelTest, CreateNullArray) {
  set_last_error(0, nullptr);
  ListChannel_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListChannelTest, At) {
  ChannelHandle arr[2] = {sh1, sh2};
  auto          handle = ListChannel_create(arr, 2);
  auto          at0    = ListChannel_at(handle, 0);
  auto          at1    = ListChannel_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListChannel_destroy(handle);
  set_last_error(0, nullptr);
  ListChannel_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
