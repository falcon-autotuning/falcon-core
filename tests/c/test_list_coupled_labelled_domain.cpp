#include <falcon-core/generic/ListCoupledLabelledDomain_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "falcon-core/generic/ErrorHandling_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/math/domains/LabelledDomain_c_api.h"
#include "falcon-core/physics/units/SymbolUnit_c_api.h"

class ListCoupledLabelledDomainTest : public ::testing::Test {
 protected:
  void destroy_string(CoupledLabelledDomainHandle sh) {
    CoupledLabelledDomain_destroy(sh);
  }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<CoupledLabelledDomainHandle> created_strings;
  CoupledLabelledDomainHandle              track_quantity(
                   const CoupledLabelledDomainHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    ListLabelledDomainHandle list1 = ListLabelledDomain_create_empty();
    ListLabelledDomain_push_back(
        list1,
        LabelledDomain_create_primitive_knob(
            String_wrap("plung"),
            0.0,
            1.0,
            Connection_create_plunger_gate(String_wrap("plung")),
            InstrumentTypes_voltage_source(),
            true,
            true,
            SymbolUnit_create_volt(),
            String_wrap("")));
    ListLabelledDomainHandle list2 = ListLabelledDomain_create_empty();
    ListLabelledDomain_push_back(
        list2,
        LabelledDomain_create_primitive_knob(
            String_wrap("plung2"),
            0.0,
            1.0,
            Connection_create_plunger_gate(String_wrap("plung2")),
            InstrumentTypes_voltage_source(),
            true,
            true,
            SymbolUnit_create_volt(),
            String_wrap("")));

    sh1 = track_quantity(CoupledLabelledDomain_create(list1));
    sh2 = track_quantity(CoupledLabelledDomain_create(list2));
  }
  CoupledLabelledDomainHandle sh1;
  CoupledLabelledDomainHandle sh2;
};

TEST_F(ListCoupledLabelledDomainTest, CreateEmpty) {
  auto handle = ListCoupledLabelledDomain_create_empty();
  EXPECT_TRUE(ListCoupledLabelledDomain_empty(handle));
  EXPECT_EQ(ListCoupledLabelledDomain_size(handle), 0);
  ListCoupledLabelledDomain_destroy(handle);
  set_last_error(0, nullptr);
  ListCoupledLabelledDomain_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListCoupledLabelledDomainTest, FillValue) {
  auto handle = ListCoupledLabelledDomain_fill_value(3, sh1);
  EXPECT_EQ(ListCoupledLabelledDomain_size(handle), 3);
  ListCoupledLabelledDomain_destroy(handle);
}

TEST_F(ListCoupledLabelledDomainTest, CreateFromArray) {
  CoupledLabelledDomainHandle     arr[2] = {sh1, sh2};
  ListCoupledLabelledDomainHandle handle =
      ListCoupledLabelledDomain_create(arr, 2);
  EXPECT_EQ(ListCoupledLabelledDomain_size(handle), 2);
  set_last_error(0, nullptr);
  ListCoupledLabelledDomain_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  ListCoupledLabelledDomain_destroy(handle);
}

TEST_F(ListCoupledLabelledDomainTest, SizeEmptyInvalid) {
  auto handle = ListCoupledLabelledDomain_create_empty();
  EXPECT_EQ(ListCoupledLabelledDomain_size(handle), 0);
  ListCoupledLabelledDomain_destroy(handle);
  set_last_error(0, nullptr);
  ListCoupledLabelledDomain_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListCoupledLabelledDomainTest, EmptyInvalid) {
  auto handle = ListCoupledLabelledDomain_create_empty();
  EXPECT_TRUE(ListCoupledLabelledDomain_empty(handle));
  ListCoupledLabelledDomain_destroy(handle);
  set_last_error(0, nullptr);
  ListCoupledLabelledDomain_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListCoupledLabelledDomainTest, EraseAtClear) {
  auto handle = ListCoupledLabelledDomain_fill_value(2, sh1);
  ListCoupledLabelledDomain_erase_at(handle, 0);
  EXPECT_EQ(ListCoupledLabelledDomain_size(handle), 1);
  ListCoupledLabelledDomain_clear(handle);
  EXPECT_TRUE(ListCoupledLabelledDomain_empty(handle));
  ListCoupledLabelledDomain_destroy(handle);
  set_last_error(0, nullptr);
  ListCoupledLabelledDomain_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListCoupledLabelledDomain_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListCoupledLabelledDomainTest, PushBackContainsIndex) {
  auto handle = ListCoupledLabelledDomain_create_empty();
  ListCoupledLabelledDomain_push_back(handle, sh1);
  EXPECT_TRUE(ListCoupledLabelledDomain_contains(handle, sh1));
  EXPECT_EQ(ListCoupledLabelledDomain_index(handle, sh1), 0);
  ListCoupledLabelledDomain_destroy(handle);
  set_last_error(0, nullptr);
  ListCoupledLabelledDomain_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListCoupledLabelledDomain_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListCoupledLabelledDomain_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListCoupledLabelledDomainTest, ItemsAt) {
  CoupledLabelledDomainHandle arr[2] = {sh1, sh2};
  auto                        handle = ListCoupledLabelledDomain_create(arr, 2);
  CoupledLabelledDomainHandle out[2];
  EXPECT_EQ(ListCoupledLabelledDomain_items(handle, out, 2), 2);
  ListCoupledLabelledDomain_destroy(handle);
  set_last_error(0, nullptr);
  ListCoupledLabelledDomain_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListCoupledLabelledDomain_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListCoupledLabelledDomain_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListCoupledLabelledDomainTest, EqualNotEqualIntersection) {
  CoupledLabelledDomainHandle arr[2] = {sh1, sh2};
  auto                        h1     = ListCoupledLabelledDomain_create(arr, 2);
  auto                        h2     = ListCoupledLabelledDomain_create(arr, 2);
  EXPECT_TRUE(ListCoupledLabelledDomain_equal(h1, h2));
  EXPECT_FALSE(ListCoupledLabelledDomain_not_equal(h1, h2));
  auto h3 = ListCoupledLabelledDomain_intersection(h1, h2);
  EXPECT_EQ(ListCoupledLabelledDomain_size(h3), 2);
  ListCoupledLabelledDomain_destroy(h1);
  ListCoupledLabelledDomain_destroy(h2);
  ListCoupledLabelledDomain_destroy(h3);
  set_last_error(0, nullptr);
  ListCoupledLabelledDomain_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListCoupledLabelledDomain_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListCoupledLabelledDomain_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListCoupledLabelledDomain_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListCoupledLabelledDomain_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListCoupledLabelledDomain_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListCoupledLabelledDomainTest, ToJsonFromJson) {
  CoupledLabelledDomainHandle arr[1] = {sh1};
  auto                        handle = ListCoupledLabelledDomain_create(arr, 1);
  auto json    = ListCoupledLabelledDomain_to_json_string(handle);
  auto handle2 = ListCoupledLabelledDomain_from_json_string(json);
  EXPECT_TRUE(ListCoupledLabelledDomain_equal(handle, handle2));
  ListCoupledLabelledDomain_destroy(handle);
  ListCoupledLabelledDomain_destroy(handle2);
  String_destroy(json);
  set_last_error(0, nullptr);
  ListCoupledLabelledDomain_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListCoupledLabelledDomain_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListCoupledLabelledDomainTest, FillValueNull) {
  set_last_error(0, nullptr);
  ListCoupledLabelledDomain_fill_value(3, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListCoupledLabelledDomainTest, PushBackNull) {
  auto handle = ListCoupledLabelledDomain_create_empty();
  set_last_error(0, nullptr);
  ListCoupledLabelledDomain_push_back(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListCoupledLabelledDomain_destroy(handle);
}

TEST_F(ListCoupledLabelledDomainTest, ContainsNull) {
  auto handle = ListCoupledLabelledDomain_create_empty();
  set_last_error(0, nullptr);
  ListCoupledLabelledDomain_contains(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListCoupledLabelledDomain_destroy(handle);
}

TEST_F(ListCoupledLabelledDomainTest, IndexNull) {
  auto handle = ListCoupledLabelledDomain_create_empty();
  set_last_error(0, nullptr);
  ListCoupledLabelledDomain_index(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListCoupledLabelledDomain_destroy(handle);
}

TEST_F(ListCoupledLabelledDomainTest, CreateNullArray) {
  set_last_error(0, nullptr);
  ListCoupledLabelledDomain_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListCoupledLabelledDomainTest, At) {
  CoupledLabelledDomainHandle arr[2] = {sh1, sh2};
  auto                        handle = ListCoupledLabelledDomain_create(arr, 2);
  auto                        at0    = ListCoupledLabelledDomain_at(handle, 0);
  auto                        at1    = ListCoupledLabelledDomain_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListCoupledLabelledDomain_destroy(handle);
  set_last_error(0, nullptr);
  ListCoupledLabelledDomain_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
