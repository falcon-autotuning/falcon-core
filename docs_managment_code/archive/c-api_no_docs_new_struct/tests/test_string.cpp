
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include <cstring>

#include "falcon_core/generic/String_c_api.h"

TEST(StringCAPI, CreateAndRetrieve) {
  const char*  test_str = "hello world";
  size_t       len      = strlen(test_str);
  StringHandle handle   = String_create(test_str, len);
  ASSERT_NE(handle, nullptr);
  ASSERT_EQ(handle->length, len);
  ASSERT_STREQ(handle->raw, test_str);
  String_destroy(handle);
}

TEST(StringCAPI, WrapAndRetrieve) {
  const char*  test_str = "another test";
  StringHandle handle   = String_wrap(test_str);
  ASSERT_NE(handle, nullptr);
  ASSERT_EQ(handle->length, strlen(test_str));
  ASSERT_STREQ(handle->raw, test_str);
  String_destroy(handle);
}

TEST(StringCAPI, DestroyNull) {
  StringHandle handle = nullptr;
  // Should not crash
  String_destroy(handle);
}
