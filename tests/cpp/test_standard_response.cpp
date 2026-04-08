#include <gtest/gtest.h>

#include <falcon-core/communications/messages/StandardResponse.hpp>
namespace {
using namespace falcon_core::communications::messages;

class StandardResponseTest : public ::testing::Test {};

TEST_F(StandardResponseTest, ConstructorAndMessageGetter) {
  StandardResponse resp("hello world");
  EXPECT_EQ(resp.message(), "hello world");
}

TEST_F(StandardResponseTest, EqualityOperator) {
  StandardResponse resp1("foo");
  StandardResponse resp2("foo");
  StandardResponse resp3("bar");
  EXPECT_TRUE(resp1 == resp2);
  EXPECT_FALSE(resp1 == resp3);
}

TEST_F(StandardResponseTest, InEqualOperator) {
  StandardResponse resp1("foo");
  StandardResponse resp2("bar");
  EXPECT_TRUE(resp1 != resp2);
  EXPECT_FALSE(resp1 != resp1);
}

TEST_F(StandardResponseTest, SerializationRoundTrip) {
  StandardResponse resp("serialize me");
  auto             json = resp.to_json_string();
  auto resp2 = StandardResponse::from_json_string<StandardResponse>(json);
  EXPECT_EQ(resp, *resp2);
}
}  // namespace
