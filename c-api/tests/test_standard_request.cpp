#include <gtest/gtest.h>

#include "falcon_core/communications/messages/StandardRequest_c_api.h"
#include "falcon_core/generic/String_c_api.h"

class StandardRequestTest : public ::testing::Test {
 protected:
  void SetUp() override {
    msg  = String_wrap("hello world");
    req  = StandardRequest_create(msg);
    req2 = StandardRequest_create(String_wrap("goodbye world"));
  }
  void TearDown() override {
    StandardRequest_destroy(req);
    StandardRequest_destroy(req2);
    String_destroy(msg);
  }
  StringHandle          msg  = nullptr;
  StandardRequestHandle req  = nullptr;
  StandardRequestHandle req2 = nullptr;
};

TEST_F(StandardRequestTest, CreateDestroy) {
  auto r = StandardRequest_create(String_wrap("test"));
  StandardRequest_destroy(r);
  EXPECT_THROW(StandardRequest_create(nullptr), std::invalid_argument);
  EXPECT_THROW(StandardRequest_destroy(nullptr), std::invalid_argument);
}

TEST_F(StandardRequestTest, Accessors) {
  auto m = StandardRequest_message(req);
  EXPECT_STREQ(m->raw, "hello world");
  String_destroy(m);

  EXPECT_THROW(StandardRequest_message(nullptr), std::invalid_argument);
}

TEST_F(StandardRequestTest, Equality) {
  EXPECT_FALSE(StandardRequest_equal(req, req2));
  EXPECT_TRUE(StandardRequest_not_equal(req, req2));
  EXPECT_TRUE(StandardRequest_equal(req, req));
  EXPECT_FALSE(StandardRequest_not_equal(req, req));

  EXPECT_THROW(StandardRequest_equal(nullptr, req2), std::invalid_argument);
  EXPECT_THROW(StandardRequest_equal(req, nullptr), std::invalid_argument);
  EXPECT_THROW(StandardRequest_not_equal(nullptr, req2), std::invalid_argument);
  EXPECT_THROW(StandardRequest_not_equal(req, nullptr), std::invalid_argument);
}

TEST_F(StandardRequestTest, ToJsonFromJson) {
  auto json = StandardRequest_to_json_string(req);
  auto r2   = StandardRequest_from_json_string(json);
  EXPECT_TRUE(StandardRequest_equal(req, r2));
  StandardRequest_destroy(r2);
  String_destroy(json);

  EXPECT_THROW(StandardRequest_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(StandardRequest_from_json_string(nullptr),
               std::invalid_argument);
}
