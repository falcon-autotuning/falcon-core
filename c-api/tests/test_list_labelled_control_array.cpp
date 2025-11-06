#include <falcon_core/generic/ListLabelledControlArray_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

class ListLabelledControlArrayTest : public ::testing::Test {
 protected:
  void destroy_string(LabelledControlArrayHandle sh) {
    LabelledControlArray_destroy(sh);
  }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<LabelledControlArrayHandle> created_strings;
  LabelledControlArrayHandle              track_quantity(
                   const LabelledControlArrayHandle& s) {
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
    sh1 = track_quantity(LabelledControlArray_from_farray(
        farray1,
        AcquisitionContext_create(
            Connection_create_plunger_gate(String_wrap("A")),
            InstrumentTypes_voltmeter(),
            SymbolUnit_create_volt())));
    sh2 = track_quantity(LabelledControlArray_from_farray(
        farray2,
        AcquisitionContext_create(
            Connection_create_plunger_gate(String_wrap("A")),
            InstrumentTypes_voltmeter(),
            SymbolUnit_create_volt())));
  }
  LabelledControlArrayHandle sh1;
  LabelledControlArrayHandle sh2;
};

TEST_F(ListLabelledControlArrayTest, CreateEmpty) {
  auto handle = ListLabelledControlArray_create_empty();
  EXPECT_TRUE(ListLabelledControlArray_empty(handle));
  EXPECT_EQ(ListLabelledControlArray_size(handle), 0);
  ListLabelledControlArray_destroy(handle);
  EXPECT_THROW(ListLabelledControlArray_destroy(nullptr),
               std::invalid_argument);
}

TEST_F(ListLabelledControlArrayTest, FillValue) {
  auto handle = ListLabelledControlArray_fill_value(3, sh1);
  EXPECT_EQ(ListLabelledControlArray_size(handle), 3);
  ListLabelledControlArray_destroy(handle);
}

TEST_F(ListLabelledControlArrayTest, CreateFromArray) {
  LabelledControlArrayHandle     arr[2] = {sh1, sh2};
  ListLabelledControlArrayHandle handle =
      ListLabelledControlArray_create(arr, 2);
  EXPECT_EQ(ListLabelledControlArray_size(handle), 2);
  EXPECT_THROW(ListLabelledControlArray_create(nullptr, 2),
               std::invalid_argument);
  ListLabelledControlArray_destroy(handle);
}

TEST_F(ListLabelledControlArrayTest, SizeEmptyInvalid) {
  auto handle = ListLabelledControlArray_create_empty();
  EXPECT_EQ(ListLabelledControlArray_size(handle), 0);
  ListLabelledControlArray_destroy(handle);
  EXPECT_THROW(ListLabelledControlArray_size(nullptr), std::invalid_argument);
}

TEST_F(ListLabelledControlArrayTest, EmptyInvalid) {
  auto handle = ListLabelledControlArray_create_empty();
  EXPECT_TRUE(ListLabelledControlArray_empty(handle));
  ListLabelledControlArray_destroy(handle);
  EXPECT_THROW(ListLabelledControlArray_empty(nullptr), std::invalid_argument);
}

TEST_F(ListLabelledControlArrayTest, EraseAtClear) {
  auto handle = ListLabelledControlArray_fill_value(2, sh1);
  ListLabelledControlArray_erase_at(handle, 0);
  EXPECT_EQ(ListLabelledControlArray_size(handle), 1);
  ListLabelledControlArray_clear(handle);
  EXPECT_TRUE(ListLabelledControlArray_empty(handle));
  ListLabelledControlArray_destroy(handle);
  EXPECT_THROW(ListLabelledControlArray_erase_at(nullptr, 0),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledControlArray_clear(nullptr), std::invalid_argument);
}

TEST_F(ListLabelledControlArrayTest, PushBackContainsIndex) {
  auto handle = ListLabelledControlArray_create_empty();
  ListLabelledControlArray_push_back(handle, sh1);
  EXPECT_TRUE(ListLabelledControlArray_contains(handle, sh1));
  EXPECT_EQ(ListLabelledControlArray_index(handle, sh1), 0);
  ListLabelledControlArray_destroy(handle);
  EXPECT_THROW(ListLabelledControlArray_push_back(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledControlArray_contains(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledControlArray_index(nullptr, sh1),
               std::invalid_argument);
}

TEST_F(ListLabelledControlArrayTest, ItemsAt) {
  LabelledControlArrayHandle arr[2] = {sh1, sh2};
  auto                       handle = ListLabelledControlArray_create(arr, 2);
  LabelledControlArrayHandle out[2];
  EXPECT_EQ(ListLabelledControlArray_items(handle, out, 2), 2);
  ListLabelledControlArray_destroy(handle);
  EXPECT_THROW(ListLabelledControlArray_items(nullptr, out, 2),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledControlArray_items(handle, nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledControlArray_at(nullptr, 0), std::invalid_argument);
}

TEST_F(ListLabelledControlArrayTest, EqualNotEqualIntersection) {
  LabelledControlArrayHandle arr[2] = {sh1, sh2};
  auto                       h1     = ListLabelledControlArray_create(arr, 2);
  auto                       h2     = ListLabelledControlArray_create(arr, 2);
  EXPECT_TRUE(ListLabelledControlArray_equal(h1, h2));
  EXPECT_FALSE(ListLabelledControlArray_not_equal(h1, h2));
  auto h3 = ListLabelledControlArray_intersection(h1, h2);
  EXPECT_EQ(ListLabelledControlArray_size(h3), 2);
  ListLabelledControlArray_destroy(h1);
  ListLabelledControlArray_destroy(h2);
  ListLabelledControlArray_destroy(h3);
  EXPECT_THROW(ListLabelledControlArray_equal(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledControlArray_equal(h1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledControlArray_not_equal(h1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledControlArray_not_equal(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledControlArray_intersection(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledControlArray_intersection(h1, nullptr),
               std::invalid_argument);
}

TEST_F(ListLabelledControlArrayTest, ToJsonFromJson) {
  LabelledControlArrayHandle arr[1] = {sh1};
  auto                       handle = ListLabelledControlArray_create(arr, 1);
  auto json    = ListLabelledControlArray_to_json_string(handle);
  auto handle2 = ListLabelledControlArray_from_json_string(json);
  EXPECT_TRUE(ListLabelledControlArray_equal(handle, handle2));
  ListLabelledControlArray_destroy(handle);
  ListLabelledControlArray_destroy(handle2);
  String_destroy(json);
  EXPECT_THROW(ListLabelledControlArray_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledControlArray_from_json_string(nullptr),
               std::invalid_argument);
}

TEST_F(ListLabelledControlArrayTest, FillValueNull) {
  EXPECT_THROW(ListLabelledControlArray_fill_value(3, nullptr),
               std::invalid_argument);
}

TEST_F(ListLabelledControlArrayTest, PushBackNull) {
  auto handle = ListLabelledControlArray_create_empty();
  EXPECT_THROW(ListLabelledControlArray_push_back(handle, nullptr),
               std::invalid_argument);
  ListLabelledControlArray_destroy(handle);
}

TEST_F(ListLabelledControlArrayTest, ContainsNull) {
  auto handle = ListLabelledControlArray_create_empty();
  EXPECT_THROW(ListLabelledControlArray_contains(handle, nullptr),
               std::invalid_argument);
  ListLabelledControlArray_destroy(handle);
}

TEST_F(ListLabelledControlArrayTest, IndexNull) {
  auto handle = ListLabelledControlArray_create_empty();
  EXPECT_THROW(ListLabelledControlArray_index(handle, nullptr),
               std::invalid_argument);
  ListLabelledControlArray_destroy(handle);
}

TEST_F(ListLabelledControlArrayTest, CreateNullArray) {
  EXPECT_THROW(ListLabelledControlArray_create(nullptr, 2),
               std::invalid_argument);
}

TEST_F(ListLabelledControlArrayTest, At) {
  LabelledControlArrayHandle arr[2] = {sh1, sh2};
  auto                       handle = ListLabelledControlArray_create(arr, 2);
  auto                       at0    = ListLabelledControlArray_at(handle, 0);
  auto                       at1    = ListLabelledControlArray_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListLabelledControlArray_destroy(handle);
  EXPECT_THROW(ListLabelledControlArray_at(nullptr, 0), std::invalid_argument);
}
