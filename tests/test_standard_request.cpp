#include <gtest/gtest.h>

#include <falcon_core/communications/messages/StandardRequest.hpp>
namespace {
using namespace falcon_core::communications::messages;

class StandardReqestTest : public ::testing::Test {};

TEST_F(StandardReqestTest, ConstructorAndMessageGetter) {
  StandardRequest req("hello world");
  EXPECT_EQ(req.message(), "hello world");
}

TEST_F(StandardReqestTest, EqualityOperator) {
  StandardRequest req1("foo");
  StandardRequest req2("foo");
  StandardRequest req3("bar");
  EXPECT_TRUE(req1 == req2);
  EXPECT_FALSE(req1 == req3);
}

TEST_F(StandardReqestTest, InequalityOperator) {
  StandardRequest req1("foo");
  StandardRequest req2("bar");
  EXPECT_TRUE(req1 != req2);
  EXPECT_FALSE(req1 != req1);
}

TEST_F(StandardReqestTest, SerializationRoundTrip) {
  StandardRequest req("serialize me");
  auto            json = req.to_json_string();
  auto req2 = StandardRequest::from_json_string<StandardRequest>(json);
  EXPECT_EQ(req, *req2);
}
}  // namespace
