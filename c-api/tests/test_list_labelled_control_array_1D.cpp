#include <falcon_core/generic/ListLabelledControlArray1D_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

class ListLabelledControlArray1DTest : public ::testing::Test {
 protected:
  void destroy_string(LabelledControlArray1DHandle sh) {
    LabelledControlArray1D_destroy(sh);
  }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<LabelledControlArray1DHandle> created_strings;
  LabelledControlArray1DHandle              track_quantity(
                   const LabelledControlArray1DHandle& s) {
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
    sh1 = track_quantity(LabelledControlArray1D_from_farray(
        farray1,
        AcquisitionContext_create(
            Connection_create_plunger_gate(String_wrap("A")),
            InstrumentTypes_voltmeter(),
            SymbolUnit_create_volt())));
    sh2 = track_quantity(LabelledControlArray1D_from_farray(
        farray2,
        AcquisitionContext_create(
            Connection_create_plunger_gate(String_wrap("A")),
            InstrumentTypes_voltmeter(),
            SymbolUnit_create_volt())));
  }
  LabelledControlArray1DHandle sh1;
  LabelledControlArray1DHandle sh2;
};

TEST_F(ListLabelledControlArray1DTest, CreateEmpty) {
  auto handle = ListLabelledControlArray1D_create_empty();
  EXPECT_TRUE(ListLabelledControlArray1D_empty(handle));
  EXPECT_EQ(ListLabelledControlArray1D_size(handle), 0);
  ListLabelledControlArray1D_destroy(handle);
  EXPECT_THROW(ListLabelledControlArray1D_destroy(nullptr),
               std::invalid_argument);
}

TEST_F(ListLabelledControlArray1DTest, FillValue) {
  auto handle = ListLabelledControlArray1D_fill_value(3, sh1);
  EXPECT_EQ(ListLabelledControlArray1D_size(handle), 3);
  ListLabelledControlArray1D_destroy(handle);
}

TEST_F(ListLabelledControlArray1DTest, CreateFromArray) {
  LabelledControlArray1DHandle     arr[2] = {sh1, sh2};
  ListLabelledControlArray1DHandle handle =
      ListLabelledControlArray1D_create(arr, 2);
  EXPECT_EQ(ListLabelledControlArray1D_size(handle), 2);
  EXPECT_THROW(ListLabelledControlArray1D_create(nullptr, 2),
               std::invalid_argument);
  ListLabelledControlArray1D_destroy(handle);
}

TEST_F(ListLabelledControlArray1DTest, SizeEmptyInvalid) {
  auto handle = ListLabelledControlArray1D_create_empty();
  EXPECT_EQ(ListLabelledControlArray1D_size(handle), 0);
  ListLabelledControlArray1D_destroy(handle);
  EXPECT_THROW(ListLabelledControlArray1D_size(nullptr), std::invalid_argument);
}

TEST_F(ListLabelledControlArray1DTest, EmptyInvalid) {
  auto handle = ListLabelledControlArray1D_create_empty();
  EXPECT_TRUE(ListLabelledControlArray1D_empty(handle));
  ListLabelledControlArray1D_destroy(handle);
  EXPECT_THROW(ListLabelledControlArray1D_empty(nullptr),
               std::invalid_argument);
}

TEST_F(ListLabelledControlArray1DTest, EraseAtClear) {
  auto handle = ListLabelledControlArray1D_fill_value(2, sh1);
  ListLabelledControlArray1D_erase_at(handle, 0);
  EXPECT_EQ(ListLabelledControlArray1D_size(handle), 1);
  ListLabelledControlArray1D_clear(handle);
  EXPECT_TRUE(ListLabelledControlArray1D_empty(handle));
  ListLabelledControlArray1D_destroy(handle);
  EXPECT_THROW(ListLabelledControlArray1D_erase_at(nullptr, 0),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledControlArray1D_clear(nullptr),
               std::invalid_argument);
}

TEST_F(ListLabelledControlArray1DTest, PushBackContainsIndex) {
  auto handle = ListLabelledControlArray1D_create_empty();
  ListLabelledControlArray1D_push_back(handle, sh1);
  EXPECT_TRUE(ListLabelledControlArray1D_contains(handle, sh1));
  EXPECT_EQ(ListLabelledControlArray1D_index(handle, sh1), 0);
  ListLabelledControlArray1D_destroy(handle);
  EXPECT_THROW(ListLabelledControlArray1D_push_back(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledControlArray1D_contains(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledControlArray1D_index(nullptr, sh1),
               std::invalid_argument);
}

TEST_F(ListLabelledControlArray1DTest, ItemsAt) {
  LabelledControlArray1DHandle arr[2] = {sh1, sh2};
  auto handle = ListLabelledControlArray1D_create(arr, 2);
  LabelledControlArray1DHandle out[2];
  EXPECT_EQ(ListLabelledControlArray1D_items(handle, out, 2), 2);
  ListLabelledControlArray1D_destroy(handle);
  EXPECT_THROW(ListLabelledControlArray1D_items(nullptr, out, 2),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledControlArray1D_items(handle, nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledControlArray1D_at(nullptr, 0),
               std::invalid_argument);
}

TEST_F(ListLabelledControlArray1DTest, EqualNotEqualIntersection) {
  LabelledControlArray1DHandle arr[2] = {sh1, sh2};
  auto                         h1 = ListLabelledControlArray1D_create(arr, 2);
  auto                         h2 = ListLabelledControlArray1D_create(arr, 2);
  EXPECT_TRUE(ListLabelledControlArray1D_equal(h1, h2));
  EXPECT_FALSE(ListLabelledControlArray1D_not_equal(h1, h2));
  auto h3 = ListLabelledControlArray1D_intersection(h1, h2);
  EXPECT_EQ(ListLabelledControlArray1D_size(h3), 2);
  ListLabelledControlArray1D_destroy(h1);
  ListLabelledControlArray1D_destroy(h2);
  ListLabelledControlArray1D_destroy(h3);
  EXPECT_THROW(ListLabelledControlArray1D_equal(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledControlArray1D_equal(h1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledControlArray1D_not_equal(h1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledControlArray1D_not_equal(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledControlArray1D_intersection(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledControlArray1D_intersection(h1, nullptr),
               std::invalid_argument);
}

TEST_F(ListLabelledControlArray1DTest, ToJsonFromJson) {
  LabelledControlArray1DHandle arr[1] = {sh1};
  auto handle  = ListLabelledControlArray1D_create(arr, 1);
  auto json    = ListLabelledControlArray1D_to_json_string(handle);
  auto handle2 = ListLabelledControlArray1D_from_json_string(json);
  EXPECT_TRUE(ListLabelledControlArray1D_equal(handle, handle2));
  ListLabelledControlArray1D_destroy(handle);
  ListLabelledControlArray1D_destroy(handle2);
  String_destroy(json);
  EXPECT_THROW(ListLabelledControlArray1D_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListLabelledControlArray1D_from_json_string(nullptr),
               std::invalid_argument);
}

TEST_F(ListLabelledControlArray1DTest, FillValueNull) {
  EXPECT_THROW(ListLabelledControlArray1D_fill_value(3, nullptr),
               std::invalid_argument);
}

TEST_F(ListLabelledControlArray1DTest, PushBackNull) {
  auto handle = ListLabelledControlArray1D_create_empty();
  EXPECT_THROW(ListLabelledControlArray1D_push_back(handle, nullptr),
               std::invalid_argument);
  ListLabelledControlArray1D_destroy(handle);
}

TEST_F(ListLabelledControlArray1DTest, ContainsNull) {
  auto handle = ListLabelledControlArray1D_create_empty();
  EXPECT_THROW(ListLabelledControlArray1D_contains(handle, nullptr),
               std::invalid_argument);
  ListLabelledControlArray1D_destroy(handle);
}

TEST_F(ListLabelledControlArray1DTest, IndexNull) {
  auto handle = ListLabelledControlArray1D_create_empty();
  EXPECT_THROW(ListLabelledControlArray1D_index(handle, nullptr),
               std::invalid_argument);
  ListLabelledControlArray1D_destroy(handle);
}

TEST_F(ListLabelledControlArray1DTest, CreateNullArray) {
  EXPECT_THROW(ListLabelledControlArray1D_create(nullptr, 2),
               std::invalid_argument);
}

TEST_F(ListLabelledControlArray1DTest, At) {
  LabelledControlArray1DHandle arr[2] = {sh1, sh2};
  auto handle = ListLabelledControlArray1D_create(arr, 2);
  auto at0    = ListLabelledControlArray1D_at(handle, 0);
  auto at1    = ListLabelledControlArray1D_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListLabelledControlArray1D_destroy(handle);
  EXPECT_THROW(ListLabelledControlArray1D_at(nullptr, 0),
               std::invalid_argument);
}
