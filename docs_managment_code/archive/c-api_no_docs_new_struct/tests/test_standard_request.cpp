#include <gtest/gtest.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"

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
  set_last_error(0, nullptr);
  StandardRequest_create(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  StandardRequest_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(StandardRequestTest, Accessors) {
  auto m = StandardRequest_message(req);
  EXPECT_STREQ(m->raw, "hello world");
  String_destroy(m);

  set_last_error(0, nullptr);
  StandardRequest_message(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(StandardRequestTest, Equality) {
  EXPECT_FALSE(StandardRequest_equal(req, req2));
  EXPECT_TRUE(StandardRequest_not_equal(req, req2));
  EXPECT_TRUE(StandardRequest_equal(req, req));
  EXPECT_FALSE(StandardRequest_not_equal(req, req));

  set_last_error(0, nullptr);
  StandardRequest_equal(nullptr, req2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  StandardRequest_equal(req, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  StandardRequest_not_equal(nullptr, req2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  StandardRequest_not_equal(req, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(StandardRequestTest, ToJsonFromJson) {
  auto json = StandardRequest_to_json_string(req);
  auto r2   = StandardRequest_from_json_string(json);
  EXPECT_TRUE(StandardRequest_equal(req, r2));
  StandardRequest_destroy(r2);
  String_destroy(json);

  set_last_error(0, nullptr);
  StandardRequest_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  StandardRequest_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
