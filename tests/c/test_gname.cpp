#include <gtest/gtest.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"

#include "falcon-core/autotuner_interfaces/names/Gname_c_api.h"
#include "falcon-core/generic/String_c_api.h"

class GnameTest : public ::testing::Test {
 protected:
  StringHandle name1;
  StringHandle name2;
  GnameHandle  handle1;
  GnameHandle  handle2;
  GnameHandle  handle_num;
  void         SetUp() override {
    name1      = String_create("group1", 6);
    name2      = String_create("group2", 6);
    handle1    = Gname_create(name1);
    handle2    = Gname_create(name2);
    handle_num = Gname_create_from_num(42);
  }
  void TearDown() override {
    Gname_destroy(handle1);
    Gname_destroy(handle2);
    Gname_destroy(handle_num);
    String_destroy(name1);
    String_destroy(name2);
  }
};

TEST_F(GnameTest, ConstructFromString) {
  StringHandle gname = Gname_gname(handle1);
  EXPECT_EQ(std::string(gname->raw, gname->length), "group1");
  String_destroy(gname);
  set_last_error(0, nullptr);
  Gname_gname(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(GnameTest, ConstructFromInt) {
  StringHandle gname = Gname_gname(handle_num);
  EXPECT_EQ(std::string(gname->raw, gname->length), "group42");
  String_destroy(gname);
}

TEST_F(GnameTest, CreateDestroyNull) {
  set_last_error(0, nullptr);
  Gname_create(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Gname_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(GnameTest, EqualityAndInEqual) {
  EXPECT_TRUE(Gname_equal(handle1, handle1));
  EXPECT_FALSE(Gname_not_equal(handle1, handle1));
  EXPECT_FALSE(Gname_equal(handle1, handle2));
  EXPECT_TRUE(Gname_not_equal(handle1, handle2));
  set_last_error(0, nullptr);
  Gname_equal(nullptr, handle2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Gname_equal(handle1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Gname_not_equal(nullptr, handle2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Gname_not_equal(handle1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(GnameTest, SerializationRoundTrip) {
  StringHandle json   = Gname_to_json_string(handle1);
  GnameHandle  loaded = Gname_from_json_string(json);
  EXPECT_TRUE(Gname_equal(handle1, loaded));
  Gname_destroy(loaded);
  String_destroy(json);
  set_last_error(0, nullptr);
  Gname_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Gname_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
