#include <gtest/gtest.h>

#include "falcon_core/communications/messages/StandardResponse_c_api.h"
#include "falcon_core/generic/String_c_api.h"

class StandardResponseTest : public ::testing::Test {
 protected:
  void SetUp() override {
    msg   = String_wrap("response message");
    resp  = StandardResponse_create(msg);
    resp2 = StandardResponse_create(String_wrap("another response"));
  }
  void TearDown() override {
    StandardResponse_destroy(resp);
    StandardResponse_destroy(resp2);
    String_destroy(msg);
  }
  StringHandle           msg   = nullptr;
  StandardResponseHandle resp  = nullptr;
  StandardResponseHandle resp2 = nullptr;
};

TEST_F(StandardResponseTest, CreateDestroy) {
  auto r = StandardResponse_create(String_wrap("test response"));
  StandardResponse_destroy(r);
  EXPECT_THROW(StandardResponse_create(nullptr), std::invalid_argument);
  EXPECT_THROW(StandardResponse_destroy(nullptr), std::invalid_argument);
}

TEST_F(StandardResponseTest, Accessors) {
  auto m = StandardResponse_message(resp);
  EXPECT_STREQ(m->raw, "response message");
  String_destroy(m);

  EXPECT_THROW(StandardResponse_message(nullptr), std::invalid_argument);
}

TEST_F(StandardResponseTest, Equality) {
  EXPECT_FALSE(StandardResponse_equal(resp, resp2));
  EXPECT_TRUE(StandardResponse_not_equal(resp, resp2));
  EXPECT_TRUE(StandardResponse_equal(resp, resp));
  EXPECT_FALSE(StandardResponse_not_equal(resp, resp));

  EXPECT_THROW(StandardResponse_equal(nullptr, resp2), std::invalid_argument);
  EXPECT_THROW(StandardResponse_equal(resp, nullptr), std::invalid_argument);
  EXPECT_THROW(StandardResponse_not_equal(nullptr, resp2),
               std::invalid_argument);
  EXPECT_THROW(StandardResponse_not_equal(resp, nullptr),
               std::invalid_argument);
}

TEST_F(StandardResponseTest, ToJsonFromJson) {
  auto json = StandardResponse_to_json_string(resp);
  auto r2   = StandardResponse_from_json_string(json);
  EXPECT_TRUE(StandardResponse_equal(resp, r2));
  StandardResponse_destroy(r2);
  String_destroy(json);

  EXPECT_THROW(StandardResponse_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(StandardResponse_from_json_string(nullptr),
               std::invalid_argument);
}
