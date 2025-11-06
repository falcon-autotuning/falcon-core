#include <falcon_core/generic/ListDeviceVoltageState_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "falcon_core/generic/String_c_api.h"

class ListDeviceVoltageStateTest : public ::testing::Test {
 protected:
  void destroy_string(DeviceVoltageStateHandle sh) {
    DeviceVoltageState_destroy(sh);
  }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<DeviceVoltageStateHandle> created_strings;
  DeviceVoltageStateHandle track_quantity(const DeviceVoltageStateHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    sh1 = track_quantity(DeviceVoltageState_create(
        Connection_create_plunger_gate(String_wrap("plung")),
        1.0,
        SymbolUnit_create_volt()));
    sh2 = track_quantity(DeviceVoltageState_create(
        Connection_create_plunger_gate(String_wrap("plung2")),
        2.0,
        SymbolUnit_create_volt()));
  }
  DeviceVoltageStateHandle sh1;
  DeviceVoltageStateHandle sh2;
};

TEST_F(ListDeviceVoltageStateTest, CreateEmpty) {
  auto handle = ListDeviceVoltageState_create_empty();
  EXPECT_TRUE(ListDeviceVoltageState_empty(handle));
  EXPECT_EQ(ListDeviceVoltageState_size(handle), 0);
  ListDeviceVoltageState_destroy(handle);
  EXPECT_THROW(ListDeviceVoltageState_destroy(nullptr), std::invalid_argument);
}

TEST_F(ListDeviceVoltageStateTest, FillValue) {
  auto handle = ListDeviceVoltageState_fill_value(3, sh1);
  EXPECT_EQ(ListDeviceVoltageState_size(handle), 3);
  ListDeviceVoltageState_destroy(handle);
}

TEST_F(ListDeviceVoltageStateTest, CreateFromArray) {
  DeviceVoltageStateHandle     arr[2] = {sh1, sh2};
  ListDeviceVoltageStateHandle handle = ListDeviceVoltageState_create(arr, 2);
  EXPECT_EQ(ListDeviceVoltageState_size(handle), 2);
  EXPECT_THROW(ListDeviceVoltageState_create(nullptr, 2),
               std::invalid_argument);
  ListDeviceVoltageState_destroy(handle);
}

TEST_F(ListDeviceVoltageStateTest, SizeEmptyInvalid) {
  auto handle = ListDeviceVoltageState_create_empty();
  EXPECT_EQ(ListDeviceVoltageState_size(handle), 0);
  ListDeviceVoltageState_destroy(handle);
  EXPECT_THROW(ListDeviceVoltageState_size(nullptr), std::invalid_argument);
}

TEST_F(ListDeviceVoltageStateTest, EmptyInvalid) {
  auto handle = ListDeviceVoltageState_create_empty();
  EXPECT_TRUE(ListDeviceVoltageState_empty(handle));
  ListDeviceVoltageState_destroy(handle);
  EXPECT_THROW(ListDeviceVoltageState_empty(nullptr), std::invalid_argument);
}

TEST_F(ListDeviceVoltageStateTest, EraseAtClear) {
  auto handle = ListDeviceVoltageState_fill_value(2, sh1);
  ListDeviceVoltageState_erase_at(handle, 0);
  EXPECT_EQ(ListDeviceVoltageState_size(handle), 1);
  ListDeviceVoltageState_clear(handle);
  EXPECT_TRUE(ListDeviceVoltageState_empty(handle));
  ListDeviceVoltageState_destroy(handle);
  EXPECT_THROW(ListDeviceVoltageState_erase_at(nullptr, 0),
               std::invalid_argument);
  EXPECT_THROW(ListDeviceVoltageState_clear(nullptr), std::invalid_argument);
}

TEST_F(ListDeviceVoltageStateTest, PushBackContainsIndex) {
  auto handle = ListDeviceVoltageState_create_empty();
  ListDeviceVoltageState_push_back(handle, sh1);
  EXPECT_TRUE(ListDeviceVoltageState_contains(handle, sh1));
  EXPECT_EQ(ListDeviceVoltageState_index(handle, sh1), 0);
  ListDeviceVoltageState_destroy(handle);
  EXPECT_THROW(ListDeviceVoltageState_push_back(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(ListDeviceVoltageState_contains(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(ListDeviceVoltageState_index(nullptr, sh1),
               std::invalid_argument);
}

TEST_F(ListDeviceVoltageStateTest, ItemsAt) {
  DeviceVoltageStateHandle arr[2] = {sh1, sh2};
  auto                     handle = ListDeviceVoltageState_create(arr, 2);
  DeviceVoltageStateHandle out[2];
  EXPECT_EQ(ListDeviceVoltageState_items(handle, out, 2), 2);
  ListDeviceVoltageState_destroy(handle);
  EXPECT_THROW(ListDeviceVoltageState_items(nullptr, out, 2),
               std::invalid_argument);
  EXPECT_THROW(ListDeviceVoltageState_items(handle, nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(ListDeviceVoltageState_at(nullptr, 0), std::invalid_argument);
}

TEST_F(ListDeviceVoltageStateTest, EqualNotEqualIntersection) {
  DeviceVoltageStateHandle arr[2] = {sh1, sh2};
  auto                     h1     = ListDeviceVoltageState_create(arr, 2);
  auto                     h2     = ListDeviceVoltageState_create(arr, 2);
  EXPECT_TRUE(ListDeviceVoltageState_equal(h1, h2));
  EXPECT_FALSE(ListDeviceVoltageState_not_equal(h1, h2));
  auto h3 = ListDeviceVoltageState_intersection(h1, h2);
  EXPECT_EQ(ListDeviceVoltageState_size(h3), 2);
  ListDeviceVoltageState_destroy(h1);
  ListDeviceVoltageState_destroy(h2);
  ListDeviceVoltageState_destroy(h3);
  EXPECT_THROW(ListDeviceVoltageState_equal(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListDeviceVoltageState_equal(h1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListDeviceVoltageState_not_equal(h1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListDeviceVoltageState_not_equal(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListDeviceVoltageState_intersection(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListDeviceVoltageState_intersection(h1, nullptr),
               std::invalid_argument);
}

TEST_F(ListDeviceVoltageStateTest, ToJsonFromJson) {
  DeviceVoltageStateHandle arr[1] = {sh1};
  auto                     handle = ListDeviceVoltageState_create(arr, 1);
  auto                     json = ListDeviceVoltageState_to_json_string(handle);
  auto handle2                  = ListDeviceVoltageState_from_json_string(json);
  EXPECT_TRUE(ListDeviceVoltageState_equal(handle, handle2));
  ListDeviceVoltageState_destroy(handle);
  ListDeviceVoltageState_destroy(handle2);
  String_destroy(json);
  EXPECT_THROW(ListDeviceVoltageState_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListDeviceVoltageState_from_json_string(nullptr),
               std::invalid_argument);
}

TEST_F(ListDeviceVoltageStateTest, FillValueNull) {
  EXPECT_THROW(ListDeviceVoltageState_fill_value(3, nullptr),
               std::invalid_argument);
}

TEST_F(ListDeviceVoltageStateTest, PushBackNull) {
  auto handle = ListDeviceVoltageState_create_empty();
  EXPECT_THROW(ListDeviceVoltageState_push_back(handle, nullptr),
               std::invalid_argument);
  ListDeviceVoltageState_destroy(handle);
}

TEST_F(ListDeviceVoltageStateTest, ContainsNull) {
  auto handle = ListDeviceVoltageState_create_empty();
  EXPECT_THROW(ListDeviceVoltageState_contains(handle, nullptr),
               std::invalid_argument);
  ListDeviceVoltageState_destroy(handle);
}

TEST_F(ListDeviceVoltageStateTest, IndexNull) {
  auto handle = ListDeviceVoltageState_create_empty();
  EXPECT_THROW(ListDeviceVoltageState_index(handle, nullptr),
               std::invalid_argument);
  ListDeviceVoltageState_destroy(handle);
}

TEST_F(ListDeviceVoltageStateTest, CreateNullArray) {
  EXPECT_THROW(ListDeviceVoltageState_create(nullptr, 2),
               std::invalid_argument);
}

TEST_F(ListDeviceVoltageStateTest, At) {
  DeviceVoltageStateHandle arr[2] = {sh1, sh2};
  auto                     handle = ListDeviceVoltageState_create(arr, 2);
  auto                     at0    = ListDeviceVoltageState_at(handle, 0);
  auto                     at1    = ListDeviceVoltageState_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListDeviceVoltageState_destroy(handle);
  EXPECT_THROW(ListDeviceVoltageState_at(nullptr, 0), std::invalid_argument);
}
