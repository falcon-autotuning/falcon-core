#include <gtest/gtest.h>

#include "falcon-core/autotuner_interfaces/names/Channels.hpp"

using namespace falcon_core::autotuner_interfaces::names;

namespace {

TEST(ChannelsTest, DefaultConstructor) {
  Channels channels;
  EXPECT_EQ(channels.size(), 0);
}

TEST(ChannelsTest, VectorConstructor) {
  auto                   ch1 = std::make_shared<Channel>("a");
  auto                   ch2 = std::make_shared<Channel>("b");
  std::vector<ChannelSP> vec{ch1, ch2};
  Channels               channels(vec);
  EXPECT_EQ(channels.size(), 2);
  EXPECT_EQ(channels[0]->name(), "a");
  EXPECT_EQ(channels[1]->name(), "b");
}

TEST(ChannelsTest, InitializerListConstructor) {
  auto     ch1 = std::make_shared<Channel>("x");
  auto     ch2 = std::make_shared<Channel>("y");
  Channels channels(std::vector<ChannelSP>{ch1, ch2});
  EXPECT_EQ(channels.size(), 2);
  EXPECT_EQ(channels[0]->name(), "x");
  EXPECT_EQ(channels[1]->name(), "y");
}

TEST(ChannelsTest, SerializationRoundTripJson) {
  auto     ch1 = std::make_shared<Channel>("json1");
  auto     ch2 = std::make_shared<Channel>("json2");
  Channels channels(std::vector<ChannelSP>{ch1, ch2});
  auto     json   = channels.to_json_string();
  auto     loaded = Channels::from_json_string<Channels>(json);
  ASSERT_EQ(loaded->size(), 2);
  EXPECT_EQ((*loaded)[0]->name(), "json1");
  EXPECT_EQ((*loaded)[1]->name(), "json2");
}

TEST(ChannelsTest, NullptrInVectorThrows) {
  std::vector<ChannelSP> vec{std::make_shared<Channel>("ok"), nullptr};
  EXPECT_THROW({ Channels channels(vec); }, std::invalid_argument);
}

}  // namespace
