#include <gtest/gtest.h>

#include <falcon_core/communications/messages/BaseMessage.hpp>
namespace {
using namespace falcon_core::communications::messages;

class BaseMessageTest : public ::testing::Test {};

TEST_F(BaseMessageTest, ConstructorAndMessageGetter) {
  BaseMessage msg("hello world");
  EXPECT_EQ(msg.message(), "hello world");
}

TEST_F(BaseMessageTest, EqualityOperator) {
  BaseMessage msg1("foo");
  BaseMessage msg2("foo");
  BaseMessage msg3("bar");
  EXPECT_TRUE(msg1 == msg2);
  EXPECT_FALSE(msg1 == msg3);
}

TEST_F(BaseMessageTest, InEqualOperator) {
  BaseMessage msg1("foo");
  BaseMessage msg2("bar");
  EXPECT_TRUE(msg1 != msg2);
  EXPECT_FALSE(msg1 != msg1);
}

TEST_F(BaseMessageTest, SerializationRoundTrip) {
  BaseMessage msg("serialize me");
  auto        json = msg.to_json_string();
  auto        msg2 = BaseMessage::from_json_string<BaseMessage>(json);
  EXPECT_EQ(msg.message(), msg2->message());
  EXPECT_TRUE(msg == *msg2);
}
}  // namespace
