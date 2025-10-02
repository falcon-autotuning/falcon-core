#include <gtest/gtest.h>

#include <falcon_core/communications/messages/StandardRequest.hpp>
namespace {
using namespace falcon_core::communications::messages;

class StandardRequestTest : public ::testing::Test {};

TEST_F(StandardRequestTest, ConstructorAndMessageGetter) {
  StandardRequest req("hello world");
  EXPECT_EQ(req.message(), "hello world");
}

TEST_F(StandardRequestTest, EqualityOperator) {
  StandardRequest req1("foo");
  StandardRequest req2("foo");
  StandardRequest req3("bar");
  EXPECT_TRUE(req1 == req2);
  EXPECT_FALSE(req1 == req3);
}

TEST_F(StandardRequestTest, InequalityOperator) {
  StandardRequest req1("foo");
  StandardRequest req2("bar");
  EXPECT_TRUE(req1 != req2);
  EXPECT_FALSE(req1 != req1);
}

TEST_F(StandardRequestTest, SerializationRoundTrip) {
  StandardRequest req("serialize me");
  auto            json = req.to_json_string();
  auto req2 = StandardRequest::from_json_string<StandardRequest>(json);
  EXPECT_EQ(req, *req2);
}
}  // namespace
