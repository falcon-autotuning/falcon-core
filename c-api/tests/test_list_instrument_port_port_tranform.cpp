#include <falcon_core/generic/ListPairInstrumentPortPortTransform_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "falcon_core/physics/device_structures/Connection_c_api.h"

class ListPairInstrumentPortPortTransformTest : public ::testing::Test {
 protected:
  void destroy_string(PairInstrumentPortPortTransformHandle sh) {
    PairInstrumentPortPortTransform_destroy(sh);
  }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<PairInstrumentPortPortTransformHandle> created_strings;
  PairInstrumentPortPortTransformHandle              track_quantity(
                   const PairInstrumentPortPortTransformHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    sh1 = track_quantity(PairInstrumentPortPortTransform_create(
        InstrumentPort_create_knob(
            String_wrap("Channel1"),
            Connection_create_plunger_gate(String_wrap("gate1")),
            InstrumentTypes_voltmeter()),
        PortTransform_create(
            InstrumentPort_create_knob(
                String_wrap("Channel1"),
                Connection_create_plunger_gate(String_wrap("gate1")),
                InstrumentTypes_voltmeter()),
            AnalyticFunction_create_identity())));
    sh2 = track_quantity(PairInstrumentPortPortTransform_create(
        InstrumentPort_create_knob(
            String_wrap("Channel2"),
            Connection_create_plunger_gate(String_wrap("gate`")),
            InstrumentTypes_voltmeter()),
        PortTransform_create(
            InstrumentPort_create_knob(
                String_wrap("Channel2"),
                Connection_create_plunger_gate(String_wrap("gate2")),
                InstrumentTypes_voltmeter()),
            AnalyticFunction_create_identity())));
  }
  PairInstrumentPortPortTransformHandle sh1;
  PairInstrumentPortPortTransformHandle sh2;
};

TEST_F(ListPairInstrumentPortPortTransformTest, CreateEmpty) {
  auto handle = ListPairInstrumentPortPortTransform_create_empty();
  EXPECT_TRUE(ListPairInstrumentPortPortTransform_empty(handle));
  EXPECT_EQ(ListPairInstrumentPortPortTransform_size(handle), 0);
  ListPairInstrumentPortPortTransform_destroy(handle);
  EXPECT_THROW(ListPairInstrumentPortPortTransform_destroy(nullptr),
               std::invalid_argument);
}

TEST_F(ListPairInstrumentPortPortTransformTest, FillValue) {
  auto handle = ListPairInstrumentPortPortTransform_fill_value(3, sh1);
  EXPECT_EQ(ListPairInstrumentPortPortTransform_size(handle), 3);
  ListPairInstrumentPortPortTransform_destroy(handle);
}

TEST_F(ListPairInstrumentPortPortTransformTest, CreateFromArray) {
  PairInstrumentPortPortTransformHandle     arr[2] = {sh1, sh2};
  ListPairInstrumentPortPortTransformHandle handle =
      ListPairInstrumentPortPortTransform_create(arr, 2);
  EXPECT_EQ(ListPairInstrumentPortPortTransform_size(handle), 2);
  EXPECT_THROW(ListPairInstrumentPortPortTransform_create(nullptr, 2),
               std::invalid_argument);
  ListPairInstrumentPortPortTransform_destroy(handle);
}

TEST_F(ListPairInstrumentPortPortTransformTest, SizeEmptyInvalid) {
  auto handle = ListPairInstrumentPortPortTransform_create_empty();
  EXPECT_EQ(ListPairInstrumentPortPortTransform_size(handle), 0);
  ListPairInstrumentPortPortTransform_destroy(handle);
  EXPECT_THROW(ListPairInstrumentPortPortTransform_size(nullptr),
               std::invalid_argument);
}

TEST_F(ListPairInstrumentPortPortTransformTest, EmptyInvalid) {
  auto handle = ListPairInstrumentPortPortTransform_create_empty();
  EXPECT_TRUE(ListPairInstrumentPortPortTransform_empty(handle));
  ListPairInstrumentPortPortTransform_destroy(handle);
  EXPECT_THROW(ListPairInstrumentPortPortTransform_empty(nullptr),
               std::invalid_argument);
}

TEST_F(ListPairInstrumentPortPortTransformTest, EraseAtClear) {
  auto handle = ListPairInstrumentPortPortTransform_fill_value(2, sh1);
  ListPairInstrumentPortPortTransform_erase_at(handle, 0);
  EXPECT_EQ(ListPairInstrumentPortPortTransform_size(handle), 1);
  ListPairInstrumentPortPortTransform_clear(handle);
  EXPECT_TRUE(ListPairInstrumentPortPortTransform_empty(handle));
  ListPairInstrumentPortPortTransform_destroy(handle);
  EXPECT_THROW(ListPairInstrumentPortPortTransform_erase_at(nullptr, 0),
               std::invalid_argument);
  EXPECT_THROW(ListPairInstrumentPortPortTransform_clear(nullptr),
               std::invalid_argument);
}

TEST_F(ListPairInstrumentPortPortTransformTest, PushBackContainsIndex) {
  auto handle = ListPairInstrumentPortPortTransform_create_empty();
  ListPairInstrumentPortPortTransform_push_back(handle, sh1);
  EXPECT_TRUE(ListPairInstrumentPortPortTransform_contains(handle, sh1));
  EXPECT_EQ(ListPairInstrumentPortPortTransform_index(handle, sh1), 0);
  ListPairInstrumentPortPortTransform_destroy(handle);
  EXPECT_THROW(ListPairInstrumentPortPortTransform_push_back(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(ListPairInstrumentPortPortTransform_contains(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(ListPairInstrumentPortPortTransform_index(nullptr, sh1),
               std::invalid_argument);
}

TEST_F(ListPairInstrumentPortPortTransformTest, ItemsAt) {
  PairInstrumentPortPortTransformHandle arr[2] = {sh1, sh2};
  auto handle = ListPairInstrumentPortPortTransform_create(arr, 2);
  PairInstrumentPortPortTransformHandle out[2];
  EXPECT_EQ(ListPairInstrumentPortPortTransform_items(handle, out, 2), 2);
  ListPairInstrumentPortPortTransform_destroy(handle);
  EXPECT_THROW(ListPairInstrumentPortPortTransform_items(nullptr, out, 2),
               std::invalid_argument);
  EXPECT_THROW(ListPairInstrumentPortPortTransform_items(handle, nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(ListPairInstrumentPortPortTransform_at(nullptr, 0),
               std::invalid_argument);
}

TEST_F(ListPairInstrumentPortPortTransformTest, EqualNotEqualIntersection) {
  PairInstrumentPortPortTransformHandle arr[2] = {sh1, sh2};
  auto h1 = ListPairInstrumentPortPortTransform_create(arr, 2);
  auto h2 = ListPairInstrumentPortPortTransform_create(arr, 2);
  EXPECT_TRUE(ListPairInstrumentPortPortTransform_equal(h1, h2));
  EXPECT_FALSE(ListPairInstrumentPortPortTransform_not_equal(h1, h2));
  auto h3 = ListPairInstrumentPortPortTransform_intersection(h1, h2);
  EXPECT_EQ(ListPairInstrumentPortPortTransform_size(h3), 2);
  ListPairInstrumentPortPortTransform_destroy(h1);
  ListPairInstrumentPortPortTransform_destroy(h2);
  ListPairInstrumentPortPortTransform_destroy(h3);
  EXPECT_THROW(ListPairInstrumentPortPortTransform_equal(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListPairInstrumentPortPortTransform_equal(h1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListPairInstrumentPortPortTransform_not_equal(h1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListPairInstrumentPortPortTransform_not_equal(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListPairInstrumentPortPortTransform_intersection(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListPairInstrumentPortPortTransform_intersection(h1, nullptr),
               std::invalid_argument);
}

TEST_F(ListPairInstrumentPortPortTransformTest, ToJsonFromJson) {
  PairInstrumentPortPortTransformHandle arr[1] = {sh1};
  auto handle  = ListPairInstrumentPortPortTransform_create(arr, 1);
  auto json    = ListPairInstrumentPortPortTransform_to_json_string(handle);
  auto handle2 = ListPairInstrumentPortPortTransform_from_json_string(json);
  EXPECT_TRUE(ListPairInstrumentPortPortTransform_equal(handle, handle2));
  ListPairInstrumentPortPortTransform_destroy(handle);
  ListPairInstrumentPortPortTransform_destroy(handle2);
  String_destroy(json);
  EXPECT_THROW(ListPairInstrumentPortPortTransform_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListPairInstrumentPortPortTransform_from_json_string(nullptr),
               std::invalid_argument);
}

TEST_F(ListPairInstrumentPortPortTransformTest, FillValueNull) {
  EXPECT_THROW(ListPairInstrumentPortPortTransform_fill_value(3, nullptr),
               std::invalid_argument);
}

TEST_F(ListPairInstrumentPortPortTransformTest, PushBackNull) {
  auto handle = ListPairInstrumentPortPortTransform_create_empty();
  EXPECT_THROW(ListPairInstrumentPortPortTransform_push_back(handle, nullptr),
               std::invalid_argument);
  ListPairInstrumentPortPortTransform_destroy(handle);
}

TEST_F(ListPairInstrumentPortPortTransformTest, ContainsNull) {
  auto handle = ListPairInstrumentPortPortTransform_create_empty();
  EXPECT_THROW(ListPairInstrumentPortPortTransform_contains(handle, nullptr),
               std::invalid_argument);
  ListPairInstrumentPortPortTransform_destroy(handle);
}

TEST_F(ListPairInstrumentPortPortTransformTest, IndexNull) {
  auto handle = ListPairInstrumentPortPortTransform_create_empty();
  EXPECT_THROW(ListPairInstrumentPortPortTransform_index(handle, nullptr),
               std::invalid_argument);
  ListPairInstrumentPortPortTransform_destroy(handle);
}

TEST_F(ListPairInstrumentPortPortTransformTest, CreateNullArray) {
  EXPECT_THROW(ListPairInstrumentPortPortTransform_create(nullptr, 2),
               std::invalid_argument);
}

TEST_F(ListPairInstrumentPortPortTransformTest, At) {
  PairInstrumentPortPortTransformHandle arr[2] = {sh1, sh2};
  auto handle = ListPairInstrumentPortPortTransform_create(arr, 2);
  auto at0    = ListPairInstrumentPortPortTransform_at(handle, 0);
  auto at1    = ListPairInstrumentPortPortTransform_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListPairInstrumentPortPortTransform_destroy(handle);
  EXPECT_THROW(ListPairInstrumentPortPortTransform_at(nullptr, 0),
               std::invalid_argument);
}
