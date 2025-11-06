#include <falcon_core/generic/ListAcquisitionContext_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "falcon_core/instrument_interfaces/names/InstrumentTypes_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"

class ListAcquisitionContextTest : public ::testing::Test {
 protected:
  void destroy_string(AcquisitionContextHandle sh) {
    AcquisitionContext_destroy(sh);
  }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<AcquisitionContextHandle> created_strings;
  AcquisitionContextHandle track_quantity(const AcquisitionContextHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    sh1 = track_quantity(AcquisitionContext_create(
        Connection_create_plunger_gate(String_wrap("gate1")),
        InstrumentTypes_voltmeter(),
        SymbolUnit_create_volt()));
    sh2 = track_quantity(AcquisitionContext_create(
        Connection_create_plunger_gate(String_wrap("gate2")),
        InstrumentTypes_voltmeter(),
        SymbolUnit_create_volt()));
  }
  AcquisitionContextHandle sh1;
  AcquisitionContextHandle sh2;
};

TEST_F(ListAcquisitionContextTest, CreateEmpty) {
  auto handle = ListAcquisitionContext_create_empty();
  EXPECT_TRUE(ListAcquisitionContext_empty(handle));
  EXPECT_EQ(ListAcquisitionContext_size(handle), 0);
  ListAcquisitionContext_destroy(handle);
  EXPECT_THROW(ListAcquisitionContext_destroy(nullptr), std::invalid_argument);
}

TEST_F(ListAcquisitionContextTest, FillValue) {
  auto handle = ListAcquisitionContext_fill_value(3, sh1);
  EXPECT_EQ(ListAcquisitionContext_size(handle), 3);
  ListAcquisitionContext_destroy(handle);
}

TEST_F(ListAcquisitionContextTest, CreateFromArray) {
  AcquisitionContextHandle     arr[2] = {sh1, sh2};
  ListAcquisitionContextHandle handle = ListAcquisitionContext_create(arr, 2);
  EXPECT_EQ(ListAcquisitionContext_size(handle), 2);
  EXPECT_THROW(ListAcquisitionContext_create(nullptr, 2),
               std::invalid_argument);
  ListAcquisitionContext_destroy(handle);
}

TEST_F(ListAcquisitionContextTest, SizeEmptyInvalid) {
  auto handle = ListAcquisitionContext_create_empty();
  EXPECT_EQ(ListAcquisitionContext_size(handle), 0);
  ListAcquisitionContext_destroy(handle);
  EXPECT_THROW(ListAcquisitionContext_size(nullptr), std::invalid_argument);
}

TEST_F(ListAcquisitionContextTest, EmptyInvalid) {
  auto handle = ListAcquisitionContext_create_empty();
  EXPECT_TRUE(ListAcquisitionContext_empty(handle));
  ListAcquisitionContext_destroy(handle);
  EXPECT_THROW(ListAcquisitionContext_empty(nullptr), std::invalid_argument);
}

TEST_F(ListAcquisitionContextTest, EraseAtClear) {
  auto handle = ListAcquisitionContext_fill_value(2, sh1);
  ListAcquisitionContext_erase_at(handle, 0);
  EXPECT_EQ(ListAcquisitionContext_size(handle), 1);
  ListAcquisitionContext_clear(handle);
  EXPECT_TRUE(ListAcquisitionContext_empty(handle));
  ListAcquisitionContext_destroy(handle);
  EXPECT_THROW(ListAcquisitionContext_erase_at(nullptr, 0),
               std::invalid_argument);
  EXPECT_THROW(ListAcquisitionContext_clear(nullptr), std::invalid_argument);
}

TEST_F(ListAcquisitionContextTest, PushBackContainsIndex) {
  auto handle = ListAcquisitionContext_create_empty();
  ListAcquisitionContext_push_back(handle, sh1);
  EXPECT_TRUE(ListAcquisitionContext_contains(handle, sh1));
  EXPECT_EQ(ListAcquisitionContext_index(handle, sh1), 0);
  ListAcquisitionContext_destroy(handle);
  EXPECT_THROW(ListAcquisitionContext_push_back(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(ListAcquisitionContext_contains(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(ListAcquisitionContext_index(nullptr, sh1),
               std::invalid_argument);
}

TEST_F(ListAcquisitionContextTest, ItemsAt) {
  AcquisitionContextHandle arr[2] = {sh1, sh2};
  auto                     handle = ListAcquisitionContext_create(arr, 2);
  AcquisitionContextHandle out[2];
  EXPECT_EQ(ListAcquisitionContext_items(handle, out, 2), 2);
  ListAcquisitionContext_destroy(handle);
  EXPECT_THROW(ListAcquisitionContext_items(nullptr, out, 2),
               std::invalid_argument);
  EXPECT_THROW(ListAcquisitionContext_items(handle, nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(ListAcquisitionContext_at(nullptr, 0), std::invalid_argument);
}

TEST_F(ListAcquisitionContextTest, EqualNotEqualIntersection) {
  AcquisitionContextHandle arr[2] = {sh1, sh2};
  auto                     h1     = ListAcquisitionContext_create(arr, 2);
  auto                     h2     = ListAcquisitionContext_create(arr, 2);
  EXPECT_TRUE(ListAcquisitionContext_equal(h1, h2));
  EXPECT_FALSE(ListAcquisitionContext_not_equal(h1, h2));
  auto h3 = ListAcquisitionContext_intersection(h1, h2);
  EXPECT_EQ(ListAcquisitionContext_size(h3), 2);
  ListAcquisitionContext_destroy(h1);
  ListAcquisitionContext_destroy(h2);
  ListAcquisitionContext_destroy(h3);
  EXPECT_THROW(ListAcquisitionContext_equal(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListAcquisitionContext_equal(h1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListAcquisitionContext_not_equal(h1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListAcquisitionContext_not_equal(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListAcquisitionContext_intersection(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListAcquisitionContext_intersection(h1, nullptr),
               std::invalid_argument);
}

TEST_F(ListAcquisitionContextTest, ToJsonFromJson) {
  AcquisitionContextHandle arr[1] = {sh1};
  auto                     handle = ListAcquisitionContext_create(arr, 1);
  auto                     json = ListAcquisitionContext_to_json_string(handle);
  auto handle2                  = ListAcquisitionContext_from_json_string(json);
  EXPECT_TRUE(ListAcquisitionContext_equal(handle, handle2));
  ListAcquisitionContext_destroy(handle);
  ListAcquisitionContext_destroy(handle2);
  String_destroy(json);
  EXPECT_THROW(ListAcquisitionContext_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListAcquisitionContext_from_json_string(nullptr),
               std::invalid_argument);
}

TEST_F(ListAcquisitionContextTest, FillValueNull) {
  EXPECT_THROW(ListAcquisitionContext_fill_value(3, nullptr),
               std::invalid_argument);
}

TEST_F(ListAcquisitionContextTest, PushBackNull) {
  auto handle = ListAcquisitionContext_create_empty();
  EXPECT_THROW(ListAcquisitionContext_push_back(handle, nullptr),
               std::invalid_argument);
  ListAcquisitionContext_destroy(handle);
}

TEST_F(ListAcquisitionContextTest, ContainsNull) {
  auto handle = ListAcquisitionContext_create_empty();
  EXPECT_THROW(ListAcquisitionContext_contains(handle, nullptr),
               std::invalid_argument);
  ListAcquisitionContext_destroy(handle);
}

TEST_F(ListAcquisitionContextTest, IndexNull) {
  auto handle = ListAcquisitionContext_create_empty();
  EXPECT_THROW(ListAcquisitionContext_index(handle, nullptr),
               std::invalid_argument);
  ListAcquisitionContext_destroy(handle);
}

TEST_F(ListAcquisitionContextTest, CreateNullArray) {
  EXPECT_THROW(ListAcquisitionContext_create(nullptr, 2),
               std::invalid_argument);
}

TEST_F(ListAcquisitionContextTest, At) {
  AcquisitionContextHandle arr[2] = {sh1, sh2};
  auto                     handle = ListAcquisitionContext_create(arr, 2);
  auto                     at0    = ListAcquisitionContext_at(handle, 0);
  auto                     at1    = ListAcquisitionContext_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListAcquisitionContext_destroy(handle);
  EXPECT_THROW(ListAcquisitionContext_at(nullptr, 0), std::invalid_argument);
}
