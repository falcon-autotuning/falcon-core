#include <gtest/gtest.h>

#include "falcon_core/autotuner_interfaces/names/Channel_c_api.h"
#include "falcon_core/generic/String_c_api.h"

class ChannelTest : public ::testing::Test {
 protected:
  StringHandle  name1;
  StringHandle  name2;
  ChannelHandle handle1;
  ChannelHandle handle2;

  void SetUp() override {
    name1   = String_create("test_channel", 12);
    name2   = String_create("other_channel", 13);
    handle1 = Channel_create(name1);
    handle2 = Channel_create(name2);
  }

  void TearDown() override {
    Channel_destroy(handle1);
    Channel_destroy(handle2);
    String_destroy(name1);
    String_destroy(name2);
  }
};

TEST_F(ChannelTest, NameGetter) {
  StringHandle result = Channel_name(handle1);
  EXPECT_EQ(std::string(result->raw, result->length), "test_channel");
  String_destroy(result);
}

TEST_F(ChannelTest, EqualityAndInequality) {
  ChannelHandle handle1_copy = Channel_create(name1);
  EXPECT_TRUE(Channel_equal(handle1, handle1_copy));
  EXPECT_FALSE(Channel_not_equal(handle1, handle1_copy));
  EXPECT_FALSE(Channel_equal(handle1, handle2));
  EXPECT_TRUE(Channel_not_equal(handle1, handle2));
  Channel_destroy(handle1_copy);
}

TEST_F(ChannelTest, SerializationRoundTrip) {
  StringHandle  json   = Channel_to_json_string(handle1);
  ChannelHandle loaded = Channel_from_json_string(json);
  EXPECT_TRUE(Channel_equal(handle1, loaded));
  Channel_destroy(loaded);
  String_destroy(json);
}
