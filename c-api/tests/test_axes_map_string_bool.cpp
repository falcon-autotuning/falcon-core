#include <falcon_core/generic/ListMapStringBool_c_api.h>
#include <falcon_core/math/AxesMapStringBool_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "falcon_core/generic/MapStringBool_c_api.h"
#include "falcon_core/generic/PairStringBool_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/AxesMapStringBool_c_api.h"

class AxesMapStringBoolTest : public ::testing::Test {
 protected:
  void TearDown() override {
    String_destroy(str1);
    String_destroy(str2);
    AxesMapStringBool_destroy(sh1);
    AxesMapStringBool_destroy(sh2);
  }

  void SetUp() override {
    str1                          = String_wrap("key");
    str2                          = String_wrap("key2");
    PairStringBoolHandle pair[1]  = {PairStringBool_create(str1, true)};
    PairStringBoolHandle pair2[1] = {PairStringBool_create(str2, false)};

    MapStringBoolHandle map_pair[1]  = {MapStringBool_create(pair, 1)};
    MapStringBoolHandle map_pair2[1] = {MapStringBool_create(pair2, 1)};

    ListMapStringBoolHandle list_map_pair =
        ListMapStringBool_create(map_pair, 1);
    ListMapStringBoolHandle list_map_pair2 =
        ListMapStringBool_create(map_pair2, 1);

    sh1 = AxesMapStringBool_create(list_map_pair);
    sh2 = AxesMapStringBool_create(list_map_pair2);
  }
  AxesMapStringBoolHandle sh1;
  AxesMapStringBoolHandle sh2;
  StringHandle            str1;
  StringHandle            str2;
};

TEST_F(AxesMapStringBoolTest, CreateEmpty) {
  auto handle = AxesMapStringBool_create_empty();
  // EXPECT_TRUE(AxesMapStringBool_empty(handle));
  // EXPECT_EQ(AxesMapStringBool_size(handle), 0);
  // AxesMapStringBool_destroy(handle);
  // EXPECT_THROW(AxesMapStringBool_destroy(nullptr), std::invalid_argument);
}

// TEST_F(AxesMapStringBoolTest, CreateFromArray) {
//   MapStringBoolHandle     arr[2]      = {sh1, sh2};
//   ListMapStringBoolHandle handle      = MapStringBool_create(arr, 2);
//   AxesMapStringBoolHandle real_handle = AxesMapStringBool_create(handle);
//   EXPECT_EQ(ListMapStringBool_size(handle), 2);
//   EXPECT_THROW(ListMapStringBool_create(nullptr, 2), std::invalid_argument);
//   ListMapStringBool_destroy(handle);
// }

// TEST_F(AxesMapStringBoolTest, SizeEmptyInvalid) {
//   auto handle = ListMapStringBool_create_empty();
//   EXPECT_EQ(ListMapStringBool_size(handle), 0);
//   ListMapStringBool_destroy(handle);
//   EXPECT_THROW(ListMapStringBool_size(nullptr), std::invalid_argument);
// }
//
// TEST_F(AxesMapStringBoolTest, EmptyInvalid) {
//   auto handle = ListMapStringBool_create_empty();
//   EXPECT_TRUE(ListMapStringBool_empty(handle));
//   ListMapStringBool_destroy(handle);
//   EXPECT_THROW(ListMapStringBool_empty(nullptr), std::invalid_argument);
// }
//
// TEST_F(AxesMapStringBoolTest, EraseAtClear) {
//   auto handle = ListMapStringBool_fill_value(2, sh1);
//   ListMapStringBool_erase_at(handle, 0);
//   EXPECT_EQ(ListMapStringBool_size(handle), 1);
//   ListMapStringBool_clear(handle);
//   EXPECT_TRUE(ListMapStringBool_empty(handle));
//   ListMapStringBool_destroy(handle);
//   EXPECT_THROW(ListMapStringBool_erase_at(nullptr, 0),
//   std::invalid_argument); EXPECT_THROW(ListMapStringBool_clear(nullptr),
//   std::invalid_argument);
// }

// TEST_F(AxesMapStringBoolTest, PushBackContainsIndex) {
//   auto handle = AxesMapStringBool_create_empty();
//   AxesMapStringBool_push_back(handle, sh1);
//   EXPECT_TRUE(AxesMapStringBool_contains(handle, sh1));
//   EXPECT_EQ(AxesMapStringBool_index(handle, sh1), 0);
//   AxesMapStringBool_destroy(handle);
//   EXPECT_THROW(AxesMapStringBool_push_back(nullptr, sh1),
//                std::invalid_argument);
//   EXPECT_THROW(AxesMapStringBool_contains(nullptr, sh1),
//   std::invalid_argument); EXPECT_THROW(AxesMapStringBool_index(nullptr,
//   sh1), std::invalid_argument);
// }
//
// TEST_F(AxesMapStringBoolTest, ItemsAt) {
//   MapStringBoolHandle arr[2]     = {sh1, sh2};
//   auto                pre_handle = ListMapStringBool_create(arr, 2);
//   auto                handle     = AxesMapStringBool_create(pre_handle);
//
//   MapStringBoolHandle out[2];
//   EXPECT_EQ(ListMapStringBool_items(handle, out, 2), 2);
//   ListMapStringBool_destroy(handle);
//   EXPECT_THROW(ListMapStringBool_items(nullptr, out, 2),
//   std::invalid_argument); EXPECT_THROW(ListMapStringBool_items(handle,
//   nullptr, 2),
//                std::invalid_argument);
//   EXPECT_THROW(ListMapStringBool_at(nullptr, 0), std::invalid_argument);
// }
//
// TEST_F(AxesMapStringBoolTest, EqualNotEqualIntersection) {
//   MapStringBoolHandle arr[2] = {sh1, sh2};
//   auto                ph1    = ListMapStringBool_create(arr, 2);
//   auto                ph2    = ListMapStringBool_create(arr, 2);
//   auto                h1     = AxesMapStringBool_create(ph1);
//   auto                h2     = AxesMapStringBool_create(ph2);
//   EXPECT_TRUE(AxesMapStringBool_equal(h1, h2));
//   EXPECT_FALSE(AxesMapStringBool_not_equal(h1, h2));
//   auto h3 = ListMapStringBool_intersection(h1, h2);
//   EXPECT_EQ(ListMapStringBool_size(h3), 2);
//   AxesMapStringBool_destroy(h1);
//   AxesMapStringBool_destroy(h2);
//   AxesMapStringBool_destroy(h3);
//   EXPECT_THROW(AxesMapStringBool_equal(nullptr, h2),
//   std::invalid_argument); EXPECT_THROW(AxesMapStringBool_equal(h1,
//   nullptr), std::invalid_argument);
//   EXPECT_THROW(AxesMapStringBool_not_equal(h1, nullptr),
//   std::invalid_argument); EXPECT_THROW(AxesMapStringBool_not_equal(nullptr,
//   h2), std::invalid_argument);
//   EXPECT_THROW(AxesMapStringBool_intersection(nullptr, h2),
//                std::invalid_argument);
//   EXPECT_THROW(AxesMapStringBool_intersection(h1, nullptr),
//                std::invalid_argument);
// }
//
// TEST_F(AxesMapStringBoolTest, ToJsonFromJson) {
//   MapStringBoolHandle arr[1]  = {sh1};
//   auto                handle  = ListMapStringBool_create(arr, 1);
//   auto                json    = ListMapStringBool_to_json_string(handle);
//   auto                handle2 = ListMapStringBool_from_json_string(json);
//   EXPECT_TRUE(ListMapStringBool_equal(handle, handle2));
//   ListMapStringBool_destroy(handle);
//   ListMapStringBool_destroy(handle2);
//   String_destroy(json);
//   EXPECT_THROW(ListMapStringBool_to_json_string(nullptr),
//                std::invalid_argument);
//   EXPECT_THROW(ListMapStringBool_from_json_string(nullptr),
//                std::invalid_argument);
// }
//
// TEST_F(AxesMapStringBoolTest, FillValueNull) {
//   EXPECT_THROW(ListMapStringBool_fill_value(3, nullptr),
//   std::invalid_argument);
// }
//
// TEST_F(AxesMapStringBoolTest, PushBackNull) {
//   auto handle = ListMapStringBool_create_empty();
//   EXPECT_THROW(ListMapStringBool_push_back(handle, nullptr),
//                std::invalid_argument);
//   ListMapStringBool_destroy(handle);
// }
//
// TEST_F(AxesMapStringBoolTest, ContainsNull) {
//   auto handle = ListMapStringBool_create_empty();
//   EXPECT_THROW(ListMapStringBool_contains(handle, nullptr),
//                std::invalid_argument);
//   ListMapStringBool_destroy(handle);
// }
//
// TEST_F(AxesMapStringBoolTest, IndexNull) {
//   auto handle = ListMapStringBool_create_empty();
//   EXPECT_THROW(ListMapStringBool_index(handle, nullptr),
//   std::invalid_argument); ListMapStringBool_destroy(handle);
// }
//
// TEST_F(AxesMapStringBoolTest, CreateNullArray) {
//   EXPECT_THROW(ListMapStringBool_create(nullptr, 2),
//   std::invalid_argument);
// }
//
// TEST_F(AxesMapStringBoolTest, At) {
//   MapStringBoolHandle arr[2] = {sh1, sh2};
//   auto                handle = ListMapStringBool_create(arr, 2);
//   auto                at0    = ListMapStringBool_at(handle, 0);
//   auto                at1    = ListMapStringBool_at(handle, 1);
//   destroy_string(at0);
//   destroy_string(at1);
//   ListMapStringBool_destroy(handle);
//   EXPECT_THROW(ListMapStringBool_at(nullptr, 0), std::invalid_argument);
// }
