#include <gtest/gtest.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"

#include "falcon_core/autotuner_interfaces/names/Channel_c_api.h"
#include "falcon_core/autotuner_interfaces/names/Channels_c_api.h"
#include "falcon_core/generic/ListChannel_c_api.h"
#include "falcon_core/generic/ListString_c_api.h"
#include "falcon_core/generic/String_c_api.h"

class ChannelsTest : public ::testing::Test {
 protected:
  void SetUp() override {
    name1 = String_create("a", 1);
    name2 = String_create("b", 1);
    ch1   = Channel_create(name1);
    ch2   = Channel_create(name2);
    list  = ListChannel_create_empty();
    ListChannel_push_back(list, ch1);
    ListChannel_push_back(list, ch2);
    channels = Channels_create(list);
  }
  void TearDown() override {
    Channels_destroy(channels);
    Channel_destroy(ch1);
    Channel_destroy(ch2);
    ListChannel_destroy(list);
    String_destroy(name1);
    String_destroy(name2);
  }
  StringHandle      name1    = nullptr;
  StringHandle      name2    = nullptr;
  ChannelHandle     ch1      = nullptr;
  ChannelHandle     ch2      = nullptr;
  ListChannelHandle list     = nullptr;
  ChannelsHandle    channels = nullptr;
};

TEST_F(ChannelsTest, CreateDestroy) {
  ChannelsHandle empty = Channels_create_empty();
  Channels_destroy(empty);

  ChannelsHandle c = Channels_create(list);
  Channels_destroy(c);

  set_last_error(0, nullptr);
  Channels_create(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Channels_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ChannelsTest, SizeAndEmpty) {
  EXPECT_EQ(Channels_size(channels), 2);
  EXPECT_FALSE(Channels_empty(channels));
  ChannelsHandle empty = Channels_create_empty();
  EXPECT_TRUE(Channels_empty(empty));
  Channels_destroy(empty);
  set_last_error(0, nullptr);
  Channels_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Channels_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ChannelsTest, AtAndItems) {
  ChannelHandle c1 = Channels_at(channels, 0);
  ChannelHandle c2 = Channels_at(channels, 1);
  StringHandle  s1 = Channel_name(c1);
  StringHandle  s2 = Channel_name(c2);
  EXPECT_EQ(std::string(s1->raw, s1->length), "a");
  EXPECT_EQ(std::string(s2->raw, s2->length), "b");
  Channel_destroy(c1);
  Channel_destroy(c2);
  String_destroy(s1);
  String_destroy(s2);

  ListStringHandle items = Channels_items(channels);
  EXPECT_EQ(ListString_size(items), 2);
  String_destroy(ListString_at(items, 0));
  String_destroy(ListString_at(items, 1));
  ListString_destroy(items);

  set_last_error(0, nullptr);
  Channels_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Channels_items(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ChannelsTest, PushBackAndEraseAt) {
  ChannelHandle ch3 = Channel_create(String_create("c", 1));
  Channels_push_back(channels, ch3);
  EXPECT_EQ(Channels_size(channels), 3);
  Channels_erase_at(channels, 2);
  EXPECT_EQ(Channels_size(channels), 2);
  Channel_destroy(ch3);

  set_last_error(0, nullptr);
  Channels_push_back(nullptr, ch1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Channels_push_back(channels, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Channels_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ChannelsTest, Clear) {
  Channels_clear(channels);
  EXPECT_EQ(Channels_size(channels), 0);
  EXPECT_TRUE(Channels_empty(channels));
  set_last_error(0, nullptr);
  Channels_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ChannelsTest, ContainsAndIndex) {
  EXPECT_TRUE(Channels_contains(channels, ch1));
  EXPECT_EQ(Channels_index(channels, ch2), 1);

  set_last_error(0, nullptr);
  Channels_contains(nullptr, ch1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Channels_contains(channels, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Channels_index(nullptr, ch2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Channels_index(channels, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ChannelsTest, EqualityAndInequality) {
  ChannelsHandle channels2 = Channels_create(list);
  EXPECT_TRUE(Channels_equal(channels, channels2));
  EXPECT_FALSE(Channels_not_equal(channels, channels2));
  Channels_destroy(channels2);

  set_last_error(0, nullptr);
  Channels_equal(nullptr, channels);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Channels_equal(channels, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Channels_not_equal(nullptr, channels);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Channels_not_equal(channels, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ChannelsTest, Intersection) {
  ChannelsHandle channels2 = Channels_create(list);
  ChannelsHandle inter     = Channels_intersection(channels, channels2);
  EXPECT_EQ(Channels_size(inter), 2);
  Channels_destroy(channels2);
  Channels_destroy(inter);

  set_last_error(0, nullptr);
  Channels_intersection(nullptr, channels);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Channels_intersection(channels, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ChannelsTest, SerializationRoundTrip) {
  StringHandle   json   = Channels_to_json_string(channels);
  ChannelsHandle loaded = Channels_from_json_string(json);
  EXPECT_TRUE(Channels_equal(channels, loaded));
  Channels_destroy(loaded);
  String_destroy(json);

  set_last_error(0, nullptr);
  Channels_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Channels_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
