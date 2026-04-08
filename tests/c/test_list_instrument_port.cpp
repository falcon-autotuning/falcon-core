#include <falcon-core/generic/ListInstrumentPort_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "falcon-core/generic/ErrorHandling_c_api.h"
#include "falcon-core/physics/units/SymbolUnit_c_api.h"

class ListInstrumentPortTest : public ::testing::Test {
 protected:
  void destroy_string(InstrumentPortHandle sh) { InstrumentPort_destroy(sh); }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<InstrumentPortHandle> created_strings;
  InstrumentPortHandle track_quantity(const InstrumentPortHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    sh1 = track_quantity(InstrumentPort_create_knob(
        String_wrap("knob1"),
        Connection_create_barrier_gate(String_wrap("gate1")),
        InstrumentTypes_voltmeter(),
        SymbolUnit_create_volt(),
        String_wrap("")));
    sh2 = track_quantity(InstrumentPort_create_knob(
        String_wrap("knob2"),
        Connection_create_barrier_gate(String_wrap("gate2")),
        InstrumentTypes_voltmeter(),
        SymbolUnit_create_volt(),
        String_wrap("")));
  }
  InstrumentPortHandle sh1;
  InstrumentPortHandle sh2;
};

TEST_F(ListInstrumentPortTest, CreateEmpty) {
  auto handle = ListInstrumentPort_create_empty();
  EXPECT_TRUE(ListInstrumentPort_empty(handle));
  EXPECT_EQ(ListInstrumentPort_size(handle), 0);
  ListInstrumentPort_destroy(handle);
  set_last_error(0, nullptr);
  ListInstrumentPort_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListInstrumentPortTest, FillValue) {
  auto handle = ListInstrumentPort_fill_value(3, sh1);
  EXPECT_EQ(ListInstrumentPort_size(handle), 3);
  ListInstrumentPort_destroy(handle);
}

TEST_F(ListInstrumentPortTest, CreateFromArray) {
  InstrumentPortHandle     arr[2] = {sh1, sh2};
  ListInstrumentPortHandle handle = ListInstrumentPort_create(arr, 2);
  EXPECT_EQ(ListInstrumentPort_size(handle), 2);
  set_last_error(0, nullptr);
  ListInstrumentPort_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  ListInstrumentPort_destroy(handle);
}

TEST_F(ListInstrumentPortTest, SizeEmptyInvalid) {
  auto handle = ListInstrumentPort_create_empty();
  EXPECT_EQ(ListInstrumentPort_size(handle), 0);
  ListInstrumentPort_destroy(handle);
  set_last_error(0, nullptr);
  ListInstrumentPort_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListInstrumentPortTest, EmptyInvalid) {
  auto handle = ListInstrumentPort_create_empty();
  EXPECT_TRUE(ListInstrumentPort_empty(handle));
  ListInstrumentPort_destroy(handle);
  set_last_error(0, nullptr);
  ListInstrumentPort_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListInstrumentPortTest, EraseAtClear) {
  auto handle = ListInstrumentPort_fill_value(2, sh1);
  ListInstrumentPort_erase_at(handle, 0);
  EXPECT_EQ(ListInstrumentPort_size(handle), 1);
  ListInstrumentPort_clear(handle);
  EXPECT_TRUE(ListInstrumentPort_empty(handle));
  ListInstrumentPort_destroy(handle);
  set_last_error(0, nullptr);
  ListInstrumentPort_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListInstrumentPort_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListInstrumentPortTest, PushBackContainsIndex) {
  auto handle = ListInstrumentPort_create_empty();
  ListInstrumentPort_push_back(handle, sh1);
  EXPECT_TRUE(ListInstrumentPort_contains(handle, sh1));
  EXPECT_EQ(ListInstrumentPort_index(handle, sh1), 0);
  ListInstrumentPort_destroy(handle);
  set_last_error(0, nullptr);
  ListInstrumentPort_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListInstrumentPort_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListInstrumentPort_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListInstrumentPortTest, ItemsAt) {
  InstrumentPortHandle arr[2] = {sh1, sh2};
  auto                 handle = ListInstrumentPort_create(arr, 2);
  InstrumentPortHandle out[2];
  EXPECT_EQ(ListInstrumentPort_items(handle, out, 2), 2);
  ListInstrumentPort_destroy(handle);
  set_last_error(0, nullptr);
  ListInstrumentPort_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListInstrumentPort_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListInstrumentPort_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListInstrumentPortTest, EqualNotEqualIntersection) {
  InstrumentPortHandle arr[2] = {sh1, sh2};
  auto                 h1     = ListInstrumentPort_create(arr, 2);
  auto                 h2     = ListInstrumentPort_create(arr, 2);
  EXPECT_TRUE(ListInstrumentPort_equal(h1, h2));
  EXPECT_FALSE(ListInstrumentPort_not_equal(h1, h2));
  auto h3 = ListInstrumentPort_intersection(h1, h2);
  EXPECT_EQ(ListInstrumentPort_size(h3), 2);
  ListInstrumentPort_destroy(h1);
  ListInstrumentPort_destroy(h2);
  ListInstrumentPort_destroy(h3);
  set_last_error(0, nullptr);
  ListInstrumentPort_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListInstrumentPort_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListInstrumentPort_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListInstrumentPort_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListInstrumentPort_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListInstrumentPort_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListInstrumentPortTest, ToJsonFromJson) {
  InstrumentPortHandle arr[1]  = {sh1};
  auto                 handle  = ListInstrumentPort_create(arr, 1);
  auto                 json    = ListInstrumentPort_to_json_string(handle);
  auto                 handle2 = ListInstrumentPort_from_json_string(json);
  EXPECT_TRUE(ListInstrumentPort_equal(handle, handle2));
  ListInstrumentPort_destroy(handle);
  ListInstrumentPort_destroy(handle2);
  String_destroy(json);
  set_last_error(0, nullptr);
  ListInstrumentPort_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListInstrumentPort_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListInstrumentPortTest, FillValueNull) {
  set_last_error(0, nullptr);
  ListInstrumentPort_fill_value(3, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListInstrumentPortTest, PushBackNull) {
  auto handle = ListInstrumentPort_create_empty();
  set_last_error(0, nullptr);
  ListInstrumentPort_push_back(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListInstrumentPort_destroy(handle);
}

TEST_F(ListInstrumentPortTest, ContainsNull) {
  auto handle = ListInstrumentPort_create_empty();
  set_last_error(0, nullptr);
  ListInstrumentPort_contains(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListInstrumentPort_destroy(handle);
}

TEST_F(ListInstrumentPortTest, IndexNull) {
  auto handle = ListInstrumentPort_create_empty();
  set_last_error(0, nullptr);
  ListInstrumentPort_index(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListInstrumentPort_destroy(handle);
}

TEST_F(ListInstrumentPortTest, CreateNullArray) {
  set_last_error(0, nullptr);
  ListInstrumentPort_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListInstrumentPortTest, At) {
  InstrumentPortHandle arr[2] = {sh1, sh2};
  auto                 handle = ListInstrumentPort_create(arr, 2);
  auto                 at0    = ListInstrumentPort_at(handle, 0);
  auto                 at1    = ListInstrumentPort_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListInstrumentPort_destroy(handle);
  set_last_error(0, nullptr);
  ListInstrumentPort_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
