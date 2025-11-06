#include <falcon_core/generic/ListLabelledMeasuredArray_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

class ListLabelledMeasuredArrayTest : public ::testing::Test {
 protected:
  void destroy_string(LabelledMeasuredArrayHandle sh) {
    LabelledMeasuredArray_destroy(sh);
  }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<LabelledMeasuredArrayHandle> created_strings;
  LabelledMeasuredArrayHandle              track_quantity(
                   const LabelledMeasuredArrayHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    double             data1[3] = {1.0, 2.0, 3.0};
    double             data2[3] = {4.0, 5.0, 6.0};
    FArrayDoubleHandle farray1 =
        FArrayDouble_from_data(data1, (size_t[]){3}, 1);
    FArrayDoubleHandle farray2 =
        FArrayDouble_from_data(data2, (size_t[]){3}, 1);
    sh1 = track_quantity(LabelledMeasuredArray_from_farray(
        farray1,
        AcquisitionContext_create(
            Connection_create_plunger_gate(String_wrap("A")),
            InstrumentTypes_voltmeter(),
            SymbolUnit_create_volt())));
    sh2 = track_quantity(LabelledMeasuredArray_from_farray(
        farray2,
        AcquisitionContext_create(
            Connection_create_plunger_gate(String_wrap("A")),
            InstrumentTypes_voltmeter(),
            SymbolUnit_create_volt())));
  }
  LabelledMeasuredArrayHandle sh1;
  LabelledMeasuredArrayHandle sh2;
};

TEST_F(ListLabelledMeasuredArrayTest, CreateEmpty) {
  auto handle = ListLabelledMeasuredArray_create_empty();
  EXPECT_TRUE(ListLabelledMeasuredArray_empty(handle));
  EXPECT_EQ(ListLabelledMeasuredArray_size(handle), 0);
  ListLabelledMeasuredArray_destroy(handle);
  EXPECT_THROW(ListLabelledMeasuredArray_destroy(nullptr),
               std::invalid_argument);
}

TEST_F(ListLabelledMeasuredArrayTest, FillValue) {
  auto handle = ListLabelledMeasuredArray_fill_value(3, sh1);
  EXPECT_EQ(ListLabelledMeasuredArray_size(handle), 3);
  ListLabelledMeasuredArray_destroy(handle);
}

TEST_F(ListLabelledMeasuredArrayTest, CreateFromArray) {
  LabelledMeasuredArrayHandle     arr[2] = {sh1, sh2};
  ListLabelledMeasuredArrayHandle handle =
      ListLabelledMeasuredArray_create(arr, 2);
  EXPECT_EQ(ListLabelledMeasuredArray_size(handle), 2);
  EXPECT_THROW(ListLabelledMeasuredArray_create(nullptr, 2),
               std::invalid_argument);
  ListLabelledMeasuredArray_destroy(handle);
}

TEST_F(ListLabelledMeasuredArrayTest, SizeEmptyInvalid) {
  auto handle = ListLabelledMeasuredArray_create_empty();
  EXPECT_EQ(ListLabelledMeasuredArray_size(handle), 0);
  ListLabelledMeasuredArray_destroy(handle);
  EXPECT_THROW(ListLabelledMeasuredArray_size(nullptr), std::invalid_argument);
}

TEST_F(ListLabelledMeasuredArrayTest, EmptyInvalid) {
  auto handle = ListLabelledMeasuredArray_create_empty();
  EXPECT_TRUE(ListLabelledMeasuredArray_empty(handle));
  ListLabelledMeasuredArray_destroy(handle);
  EXPECT_THROW(ListLabelledMeasuredArray_empty(nullptr), std::invalid_argument);
}

TEST_F(ListLabelledMeasuredArrayTest, EraseAtClear) {
  auto handle = ListLabelledMeasuredArray_fill_value(2, sh1);
  ListLabelledMeasuredArray_erase_at(handle, 0);
  EXPECT_EQ(ListLabelledMeasuredArray_size(handle), 1);
  ListLabelledMeasuredArray_clear(handle);
  EXPECT_TRUE(ListLabelledMeasuredArray_empty(handle));
  ListLabelledMeasuredArray_destroy(handle);
  EXPECT_THROW(ListLabelledMeasuredArray_erase_at(nullptr, 0),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledMeasuredArray_clear(nullptr), std::invalid_argument);
}

TEST_F(ListLabelledMeasuredArrayTest, PushBackContainsIndex) {
  auto handle = ListLabelledMeasuredArray_create_empty();
  ListLabelledMeasuredArray_push_back(handle, sh1);
  EXPECT_TRUE(ListLabelledMeasuredArray_contains(handle, sh1));
  EXPECT_EQ(ListLabelledMeasuredArray_index(handle, sh1), 0);
  ListLabelledMeasuredArray_destroy(handle);
  EXPECT_THROW(ListLabelledMeasuredArray_push_back(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledMeasuredArray_contains(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledMeasuredArray_index(nullptr, sh1),
               std::invalid_argument);
}

TEST_F(ListLabelledMeasuredArrayTest, ItemsAt) {
  LabelledMeasuredArrayHandle arr[2] = {sh1, sh2};
  auto                        handle = ListLabelledMeasuredArray_create(arr, 2);
  LabelledMeasuredArrayHandle out[2];
  EXPECT_EQ(ListLabelledMeasuredArray_items(handle, out, 2), 2);
  ListLabelledMeasuredArray_destroy(handle);
  EXPECT_THROW(ListLabelledMeasuredArray_items(nullptr, out, 2),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledMeasuredArray_items(handle, nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledMeasuredArray_at(nullptr, 0), std::invalid_argument);
}

TEST_F(ListLabelledMeasuredArrayTest, EqualNotEqualIntersection) {
  LabelledMeasuredArrayHandle arr[2] = {sh1, sh2};
  auto                        h1     = ListLabelledMeasuredArray_create(arr, 2);
  auto                        h2     = ListLabelledMeasuredArray_create(arr, 2);
  EXPECT_TRUE(ListLabelledMeasuredArray_equal(h1, h2));
  EXPECT_FALSE(ListLabelledMeasuredArray_not_equal(h1, h2));
  auto h3 = ListLabelledMeasuredArray_intersection(h1, h2);
  EXPECT_EQ(ListLabelledMeasuredArray_size(h3), 2);
  ListLabelledMeasuredArray_destroy(h1);
  ListLabelledMeasuredArray_destroy(h2);
  ListLabelledMeasuredArray_destroy(h3);
  EXPECT_THROW(ListLabelledMeasuredArray_equal(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledMeasuredArray_equal(h1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledMeasuredArray_not_equal(h1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledMeasuredArray_not_equal(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledMeasuredArray_intersection(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledMeasuredArray_intersection(h1, nullptr),
               std::invalid_argument);
}

TEST_F(ListLabelledMeasuredArrayTest, ToJsonFromJson) {
  LabelledMeasuredArrayHandle arr[1] = {sh1};
  auto                        handle = ListLabelledMeasuredArray_create(arr, 1);
  auto json    = ListLabelledMeasuredArray_to_json_string(handle);
  auto handle2 = ListLabelledMeasuredArray_from_json_string(json);
  EXPECT_TRUE(ListLabelledMeasuredArray_equal(handle, handle2));
  ListLabelledMeasuredArray_destroy(handle);
  ListLabelledMeasuredArray_destroy(handle2);
  String_destroy(json);
  EXPECT_THROW(ListLabelledMeasuredArray_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledMeasuredArray_from_json_string(nullptr),
               std::invalid_argument);
}

TEST_F(ListLabelledMeasuredArrayTest, FillValueNull) {
  EXPECT_THROW(ListLabelledMeasuredArray_fill_value(3, nullptr),
               std::invalid_argument);
}

TEST_F(ListLabelledMeasuredArrayTest, PushBackNull) {
  auto handle = ListLabelledMeasuredArray_create_empty();
  EXPECT_THROW(ListLabelledMeasuredArray_push_back(handle, nullptr),
               std::invalid_argument);
  ListLabelledMeasuredArray_destroy(handle);
}

TEST_F(ListLabelledMeasuredArrayTest, ContainsNull) {
  auto handle = ListLabelledMeasuredArray_create_empty();
  EXPECT_THROW(ListLabelledMeasuredArray_contains(handle, nullptr),
               std::invalid_argument);
  ListLabelledMeasuredArray_destroy(handle);
}

TEST_F(ListLabelledMeasuredArrayTest, IndexNull) {
  auto handle = ListLabelledMeasuredArray_create_empty();
  EXPECT_THROW(ListLabelledMeasuredArray_index(handle, nullptr),
               std::invalid_argument);
  ListLabelledMeasuredArray_destroy(handle);
}

TEST_F(ListLabelledMeasuredArrayTest, CreateNullArray) {
  EXPECT_THROW(ListLabelledMeasuredArray_create(nullptr, 2),
               std::invalid_argument);
}

TEST_F(ListLabelledMeasuredArrayTest, At) {
  LabelledMeasuredArrayHandle arr[2] = {sh1, sh2};
  auto                        handle = ListLabelledMeasuredArray_create(arr, 2);
  auto                        at0    = ListLabelledMeasuredArray_at(handle, 0);
  auto                        at1    = ListLabelledMeasuredArray_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListLabelledMeasuredArray_destroy(handle);
  EXPECT_THROW(ListLabelledMeasuredArray_at(nullptr, 0), std::invalid_argument);
}
