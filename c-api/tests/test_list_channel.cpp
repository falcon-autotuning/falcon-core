#include <falcon_core/generic/ListChannel_c_api.h>
#include <gtest/gtest.h>

#include <falcon_core/autotuner_interfaces/names/Channel.hpp>
#include <stdexcept>
#include <string>
#include <vector>

class ListChannelTest : public ::testing::Test {
 protected:
  ChannelHandle make_channel(int id = 42) {
    return new falcon_core::autotuner_interfaces::names::Channel(
        std::to_string(id));
  }
  void destroy_channel(ChannelHandle ch) {
    delete static_cast<falcon_core::autotuner_interfaces::names::Channel*>(ch);
  }
  StringHandle make_json(const std::string& s) {
    return String_create(s.c_str(), s.size());
  }
  void destroy_string(StringHandle sh) { String_destroy(sh); }
  void TearDown() override {
    for (auto ch : created_channels) destroy_channel(ch);
    created_channels.clear();
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<ChannelHandle> created_channels;
  std::vector<StringHandle>  created_strings;
  ChannelHandle              track_channel(int id = 42) {
    auto ch = make_channel(id);
    created_channels.push_back(ch);
    return ch;
  }
  StringHandle track_string(const std::string& s) {
    auto sh = make_json(s);
    created_strings.push_back(sh);
    return sh;
  }
};

TEST_F(ListChannelTest, CreateEmpty) {
  auto handle = ListChannel_create_empty();
  EXPECT_TRUE(ListChannel_empty(handle));
  EXPECT_EQ(ListChannel_size(handle), 0);
  ListChannel_destroy(handle);
  EXPECT_THROW(ListChannel_destroy(nullptr), std::invalid_argument);
}

TEST_F(ListChannelTest, FillValue) {
  auto ch     = track_channel();
  auto handle = ListChannel_fill_value(3, ch);
  EXPECT_EQ(ListChannel_size(handle), 3);
  ListChannel_destroy(handle);
  EXPECT_THROW(ListChannel_fill_value(1, nullptr), std::invalid_argument);
}

TEST_F(ListChannelTest, Allocate) {
  auto handle = ListChannel_allocate(5);
  EXPECT_EQ(ListChannel_size(handle), 5);
  ListChannel_destroy(handle);
}

TEST_F(ListChannelTest, CreateFromArray) {
  ChannelHandle arr[2] = {track_channel(1), track_channel(2)};
  auto          handle = ListChannel_create(arr, 2);
  EXPECT_EQ(ListChannel_size(handle), 2);
  ListChannel_destroy(handle);
  EXPECT_THROW(ListChannel_create(nullptr, 2), std::invalid_argument);
}

TEST_F(ListChannelTest, SizeEmptyInvalid) {
  auto handle = ListChannel_create_empty();
  EXPECT_EQ(ListChannel_size(handle), 0);
  ListChannel_destroy(handle);
  EXPECT_THROW(ListChannel_size(nullptr), std::invalid_argument);
}

TEST_F(ListChannelTest, EmptyInvalid) {
  auto handle = ListChannel_create_empty();
  EXPECT_TRUE(ListChannel_empty(handle));
  ListChannel_destroy(handle);
  EXPECT_THROW(ListChannel_empty(nullptr), std::invalid_argument);
}

TEST_F(ListChannelTest, EraseAtClear) {
  auto ch     = track_channel();
  auto handle = ListChannel_fill_value(2, ch);
  ListChannel_erase_at(handle, 0);
  EXPECT_EQ(ListChannel_size(handle), 1);
  ListChannel_clear(handle);
  EXPECT_TRUE(ListChannel_empty(handle));
  ListChannel_destroy(handle);
  EXPECT_THROW(ListChannel_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(ListChannel_clear(nullptr), std::invalid_argument);
}

TEST_F(ListChannelTest, PushBackContainsIndex) {
  auto ch     = track_channel();
  auto handle = ListChannel_create_empty();
  ListChannel_push_back(handle, ch);
  EXPECT_TRUE(ListChannel_contains(handle, ch));
  EXPECT_EQ(ListChannel_index(handle, ch), 0);
  ListChannel_destroy(handle);
  EXPECT_THROW(ListChannel_push_back(nullptr, ch), std::invalid_argument);
  EXPECT_THROW(ListChannel_push_back(handle, nullptr), std::invalid_argument);
  EXPECT_THROW(ListChannel_contains(nullptr, ch), std::invalid_argument);
  EXPECT_THROW(ListChannel_contains(handle, nullptr), std::invalid_argument);
  EXPECT_THROW(ListChannel_index(nullptr, ch), std::invalid_argument);
  EXPECT_THROW(ListChannel_index(handle, nullptr), std::invalid_argument);
}

TEST_F(ListChannelTest, ItemsAt) {
  ChannelHandle arr[2] = {track_channel(1), track_channel(2)};
  auto          handle = ListChannel_create(arr, 2);
  ChannelHandle out[2];
  EXPECT_EQ(ListChannel_items(handle, out, 2), 2);
  auto at0 = ListChannel_at(handle, 0);
  auto at1 = ListChannel_at(handle, 1);
  destroy_channel(at0);
  destroy_channel(at1);
  ListChannel_destroy(handle);
  EXPECT_THROW(ListChannel_items(nullptr, out, 2), std::invalid_argument);
  EXPECT_THROW(ListChannel_items(handle, nullptr, 2), std::invalid_argument);
  EXPECT_THROW(ListChannel_at(nullptr, 0), std::invalid_argument);
}

TEST_F(ListChannelTest, EqualNotEqualIntersection) {
  ChannelHandle arr[2] = {track_channel(1), track_channel(2)};
  auto          h1     = ListChannel_create(arr, 2);
  auto          h2     = ListChannel_create(arr, 2);
  EXPECT_TRUE(ListChannel_equal(h1, h2));
  EXPECT_FALSE(ListChannel_not_equal(h1, h2));
  auto h3 = ListChannel_intersection(h1, h2);
  EXPECT_EQ(ListChannel_size(h3), 2);
  ListChannel_destroy(h1);
  ListChannel_destroy(h2);
  ListChannel_destroy(h3);
  EXPECT_THROW(ListChannel_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListChannel_not_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListChannel_intersection(nullptr, h2), std::invalid_argument);
}

TEST_F(ListChannelTest, ToJsonFromJson) {
  ChannelHandle arr[1]  = {track_channel(99)};
  auto          handle  = ListChannel_create(arr, 1);
  auto          json    = ListChannel_to_json_string(handle);
  auto          handle2 = ListChannel_from_json_string(json);
  EXPECT_TRUE(ListChannel_equal(handle, handle2));
  ListChannel_destroy(handle);
  ListChannel_destroy(handle2);
  destroy_string(json);
  EXPECT_THROW(ListChannel_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(ListChannel_from_json_string(nullptr), std::invalid_argument);
}
