#include <falcon_core/generic/ListMeasurementContext_c_api.h>
#include <falcon_core/math/AxesMeasurementContext_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

class AxesMeasurementContextTest : public ::testing::Test {
 protected:
  void destroy_string(MeasurementContextHandle sh) {
    MeasurementContext_destroy(sh);
  }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<MeasurementContextHandle> created_strings;
  MeasurementContextHandle track_quantity(const MeasurementContextHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    sh1 = track_quantity(MeasurementContext_create(
        Connection_create_plunger_gate(String_wrap("Conn1")),
        InstrumentTypes_voltmeter()));
    sh2 = track_quantity(MeasurementContext_create(
        Connection_create_plunger_gate(String_wrap("Conn2")),
        InstrumentTypes_voltmeter()));
  }
  MeasurementContextHandle sh1;
  MeasurementContextHandle sh2;
};

TEST_F(AxesMeasurementContextTest, CreateEmpty) {
  auto handle = AxesMeasurementContext_create_empty();
  EXPECT_TRUE(AxesMeasurementContext_empty(handle));
  EXPECT_EQ(AxesMeasurementContext_size(handle), 0);
  AxesMeasurementContext_destroy(handle);
  EXPECT_THROW(AxesMeasurementContext_destroy(nullptr), std::invalid_argument);
}

TEST_F(AxesMeasurementContextTest, CreateFromArray) {
  MeasurementContextHandle     arr[2] = {sh1, sh2};
  ListMeasurementContextHandle list_handle =
      ListMeasurementContext_create(arr, 2);
  AxesMeasurementContextHandle handle =
      AxesMeasurementContext_create(list_handle);
  EXPECT_EQ(AxesMeasurementContext_size(handle), 2);
  EXPECT_THROW(AxesMeasurementContext_create(nullptr), std::invalid_argument);
  AxesMeasurementContext_destroy(handle);
}

TEST_F(AxesMeasurementContextTest, CreateFromRaw) {
  MeasurementContextHandle arr[2] = {sh1, sh2};
  // ListMeasurementContextHandle list_handle =
  //     ListMeasurementContext_create(arr, 2);
  AxesMeasurementContextHandle handle =
      AxesMeasurementContext_create_raw(arr, 2);
  EXPECT_EQ(AxesMeasurementContext_size(handle), 2);
  EXPECT_THROW(AxesMeasurementContext_create_raw(nullptr, 2),
               std::invalid_argument);
  AxesMeasurementContext_destroy(handle);
}

TEST_F(AxesMeasurementContextTest, SizeEmptyInvalid) {
  auto handle = AxesMeasurementContext_create_empty();
  EXPECT_EQ(AxesMeasurementContext_size(handle), 0);
  AxesMeasurementContext_destroy(handle);
  EXPECT_THROW(AxesMeasurementContext_size(nullptr), std::invalid_argument);
}

TEST_F(AxesMeasurementContextTest, EmptyInvalid) {
  auto handle = AxesMeasurementContext_create_empty();
  EXPECT_TRUE(AxesMeasurementContext_empty(handle));
  AxesMeasurementContext_destroy(handle);
  EXPECT_THROW(AxesMeasurementContext_empty(nullptr), std::invalid_argument);
}

TEST_F(AxesMeasurementContextTest, PushBackContainsIndex) {
  auto handle = AxesMeasurementContext_create_empty();
  AxesMeasurementContext_push_back(handle, sh1);
  EXPECT_TRUE(AxesMeasurementContext_contains(handle, sh1));
  EXPECT_EQ(AxesMeasurementContext_index(handle, sh1), 0);
  AxesMeasurementContext_destroy(handle);
  EXPECT_THROW(AxesMeasurementContext_push_back(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(AxesMeasurementContext_contains(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(AxesMeasurementContext_index(nullptr, sh1),
               std::invalid_argument);
}

TEST_F(AxesMeasurementContextTest, ItemsAt) {
  MeasurementContextHandle     arr[2] = {sh1, sh2};
  ListMeasurementContextHandle list_handle =
      ListMeasurementContext_create(arr, 2);
  AxesMeasurementContextHandle handle =
      AxesMeasurementContext_create(list_handle);
  MeasurementContextHandle out[2];
  EXPECT_EQ(AxesMeasurementContext_items(handle, out, 2), 2);
  AxesMeasurementContext_destroy(handle);
  EXPECT_THROW(AxesMeasurementContext_items(nullptr, out, 2),
               std::invalid_argument);
  EXPECT_THROW(AxesMeasurementContext_items(handle, nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(AxesMeasurementContext_at(nullptr, 0), std::invalid_argument);
}

TEST_F(AxesMeasurementContextTest, EqualNotEqualIntersection) {
  MeasurementContextHandle     arr[2] = {sh1, sh2};
  ListMeasurementContextHandle list_handle =
      ListMeasurementContext_create(arr, 2);
  AxesMeasurementContextHandle h1 = AxesMeasurementContext_create(list_handle);
  AxesMeasurementContextHandle h2 = AxesMeasurementContext_create(list_handle);

  EXPECT_TRUE(AxesMeasurementContext_equal(h1, h2));
  EXPECT_FALSE(AxesMeasurementContext_not_equal(h1, h2));
  auto h3 = AxesMeasurementContext_intersection(h1, h2);
  EXPECT_EQ(AxesMeasurementContext_size(h3), 2);
  AxesMeasurementContext_destroy(h1);
  AxesMeasurementContext_destroy(h2);
  AxesMeasurementContext_destroy(h3);
  EXPECT_THROW(AxesMeasurementContext_equal(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(AxesMeasurementContext_equal(h1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesMeasurementContext_not_equal(h1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesMeasurementContext_not_equal(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(AxesMeasurementContext_intersection(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(AxesMeasurementContext_intersection(h1, nullptr),
               std::invalid_argument);
}

TEST_F(AxesMeasurementContextTest, Clear) {
  MeasurementContextHandle     arr[2] = {sh1, sh2};
  ListMeasurementContextHandle list_handle =
      ListMeasurementContext_create(arr, 2);
  AxesMeasurementContextHandle handle =
      AxesMeasurementContext_create(list_handle);
  EXPECT_EQ(AxesMeasurementContext_size(handle), 2);
  AxesMeasurementContext_clear(handle);
  EXPECT_EQ(AxesMeasurementContext_size(handle), 0);
  EXPECT_THROW(AxesMeasurementContext_clear(nullptr), std::invalid_argument);
}

TEST_F(AxesMeasurementContextTest, EraseAt) {
  MeasurementContextHandle     arr[2] = {sh1, sh2};
  ListMeasurementContextHandle list_handle =
      ListMeasurementContext_create(arr, 2);
  AxesMeasurementContextHandle handle =
      AxesMeasurementContext_create(list_handle);
  EXPECT_EQ(AxesMeasurementContext_size(handle), 2);
  AxesMeasurementContext_erase_at(handle, 0);
  EXPECT_EQ(AxesMeasurementContext_size(handle), 1);
  EXPECT_THROW(AxesMeasurementContext_erase_at(nullptr, 1),
               std::invalid_argument);
}

TEST_F(AxesMeasurementContextTest, ToJsonFromJson) {
  MeasurementContextHandle     arr[2] = {sh1, sh2};
  ListMeasurementContextHandle list_handle =
      ListMeasurementContext_create(arr, 2);
  AxesMeasurementContextHandle handle =
      AxesMeasurementContext_create(list_handle);
  auto json    = AxesMeasurementContext_to_json_string(handle);
  auto handle2 = AxesMeasurementContext_from_json_string(json);
  EXPECT_TRUE(AxesMeasurementContext_equal(handle, handle2));
  AxesMeasurementContext_destroy(handle);
  AxesMeasurementContext_destroy(handle2);
  String_destroy(json);
  EXPECT_THROW(AxesMeasurementContext_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesMeasurementContext_from_json_string(nullptr),
               std::invalid_argument);
}

TEST_F(AxesMeasurementContextTest, PushBackNull) {
  auto handle = AxesMeasurementContext_create_empty();
  EXPECT_THROW(AxesMeasurementContext_push_back(handle, nullptr),
               std::invalid_argument);
  AxesMeasurementContext_destroy(handle);
}

TEST_F(AxesMeasurementContextTest, ContainsNull) {
  auto handle = AxesMeasurementContext_create_empty();
  EXPECT_THROW(AxesMeasurementContext_contains(handle, nullptr),
               std::invalid_argument);
  AxesMeasurementContext_destroy(handle);
}

TEST_F(AxesMeasurementContextTest, IndexNull) {
  auto handle = AxesMeasurementContext_create_empty();
  EXPECT_THROW(AxesMeasurementContext_index(handle, nullptr),
               std::invalid_argument);
  AxesMeasurementContext_destroy(handle);
}

TEST_F(AxesMeasurementContextTest, CreateNullArray) {
  EXPECT_THROW(AxesMeasurementContext_create(nullptr), std::invalid_argument);
}

TEST_F(AxesMeasurementContextTest, At) {
  MeasurementContextHandle     arr[2] = {sh1, sh2};
  ListMeasurementContextHandle list_handle =
      ListMeasurementContext_create(arr, 2);
  AxesMeasurementContextHandle handle =
      AxesMeasurementContext_create(list_handle);
  auto at0 = AxesMeasurementContext_at(handle, 0);
  auto at1 = AxesMeasurementContext_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  AxesMeasurementContext_destroy(handle);
  EXPECT_THROW(AxesMeasurementContext_at(nullptr, 0), std::invalid_argument);
}
