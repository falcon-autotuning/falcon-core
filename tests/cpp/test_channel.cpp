#include <gtest/gtest.h>

#include "falcon-core/autotuner_interfaces/names/Channel.hpp"

using namespace falcon_core::autotuner_interfaces::names;

namespace {

TEST(ChannelTest, ConstructorAndName) {
  std::string test_name = "test_channel";
  Channel     channel(test_name);
  EXPECT_EQ(channel.name(), test_name);
}

TEST(ChannelTest, SerializationRoundTripJson) {
  std::string test_name = "json_channel";
  Channel     channel(test_name);
  auto        string = channel.to_json_string();
  auto        out    = Channel::from_json_string<Channel>(string);

  EXPECT_EQ(out->name(), test_name);
}

TEST(ChannelTest, NotEqualOperator) {
  Channel channel1("chan1");
  Channel channel2("chan2");
  EXPECT_TRUE(channel1 != channel2);
  EXPECT_FALSE(channel1 != channel1);
}

}  // namespace
