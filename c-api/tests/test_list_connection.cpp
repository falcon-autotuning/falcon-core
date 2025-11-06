#include <falcon_core/generic/ListConnection_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

class ListConnectionTest : public ::testing::Test {
 protected:
  void destroy_string(ConnectionHandle sh) { Connection_destroy(sh); }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<ConnectionHandle> created_strings;
  ConnectionHandle              track_quantity(const ConnectionHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    sh1 = track_quantity(Connection_create_plunger_gate(String_wrap("gate1")));
    sh2 = track_quantity(Connection_create_plunger_gate(String_wrap("gate2")));
  }
  ConnectionHandle sh1;
  ConnectionHandle sh2;
};

TEST_F(ListConnectionTest, CreateEmpty) {
  auto handle = ListConnection_create_empty();
  EXPECT_TRUE(ListConnection_empty(handle));
  EXPECT_EQ(ListConnection_size(handle), 0);
  ListConnection_destroy(handle);
  EXPECT_THROW(ListConnection_destroy(nullptr), std::invalid_argument);
}

TEST_F(ListConnectionTest, FillValue) {
  auto handle = ListConnection_fill_value(3, sh1);
  EXPECT_EQ(ListConnection_size(handle), 3);
  ListConnection_destroy(handle);
}

TEST_F(ListConnectionTest, CreateFromArray) {
  ConnectionHandle     arr[2] = {sh1, sh2};
  ListConnectionHandle handle = ListConnection_create(arr, 2);
  EXPECT_EQ(ListConnection_size(handle), 2);
  EXPECT_THROW(ListConnection_create(nullptr, 2), std::invalid_argument);
  ListConnection_destroy(handle);
}

TEST_F(ListConnectionTest, SizeEmptyInvalid) {
  auto handle = ListConnection_create_empty();
  EXPECT_EQ(ListConnection_size(handle), 0);
  ListConnection_destroy(handle);
  EXPECT_THROW(ListConnection_size(nullptr), std::invalid_argument);
}

TEST_F(ListConnectionTest, EmptyInvalid) {
  auto handle = ListConnection_create_empty();
  EXPECT_TRUE(ListConnection_empty(handle));
  ListConnection_destroy(handle);
  EXPECT_THROW(ListConnection_empty(nullptr), std::invalid_argument);
}

TEST_F(ListConnectionTest, EraseAtClear) {
  auto handle = ListConnection_fill_value(2, sh1);
  ListConnection_erase_at(handle, 0);
  EXPECT_EQ(ListConnection_size(handle), 1);
  ListConnection_clear(handle);
  EXPECT_TRUE(ListConnection_empty(handle));
  ListConnection_destroy(handle);
  EXPECT_THROW(ListConnection_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(ListConnection_clear(nullptr), std::invalid_argument);
}

TEST_F(ListConnectionTest, PushBackContainsIndex) {
  auto handle = ListConnection_create_empty();
  ListConnection_push_back(handle, sh1);
  EXPECT_TRUE(ListConnection_contains(handle, sh1));
  EXPECT_EQ(ListConnection_index(handle, sh1), 0);
  ListConnection_destroy(handle);
  EXPECT_THROW(ListConnection_push_back(nullptr, sh1), std::invalid_argument);
  EXPECT_THROW(ListConnection_contains(nullptr, sh1), std::invalid_argument);
  EXPECT_THROW(ListConnection_index(nullptr, sh1), std::invalid_argument);
}

TEST_F(ListConnectionTest, ItemsAt) {
  ConnectionHandle arr[2] = {sh1, sh2};
  auto             handle = ListConnection_create(arr, 2);
  ConnectionHandle out[2];
  EXPECT_EQ(ListConnection_items(handle, out, 2), 2);
  ListConnection_destroy(handle);
  EXPECT_THROW(ListConnection_items(nullptr, out, 2), std::invalid_argument);
  EXPECT_THROW(ListConnection_items(handle, nullptr, 2), std::invalid_argument);
  EXPECT_THROW(ListConnection_at(nullptr, 0), std::invalid_argument);
}

TEST_F(ListConnectionTest, EqualNotEqualIntersection) {
  ConnectionHandle arr[2] = {sh1, sh2};
  auto             h1     = ListConnection_create(arr, 2);
  auto             h2     = ListConnection_create(arr, 2);
  EXPECT_TRUE(ListConnection_equal(h1, h2));
  EXPECT_FALSE(ListConnection_not_equal(h1, h2));
  auto h3 = ListConnection_intersection(h1, h2);
  EXPECT_EQ(ListConnection_size(h3), 2);
  ListConnection_destroy(h1);
  ListConnection_destroy(h2);
  ListConnection_destroy(h3);
  EXPECT_THROW(ListConnection_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListConnection_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListConnection_not_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListConnection_not_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListConnection_intersection(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListConnection_intersection(h1, nullptr), std::invalid_argument);
}

TEST_F(ListConnectionTest, ToJsonFromJson) {
  ConnectionHandle arr[1]  = {sh1};
  auto             handle  = ListConnection_create(arr, 1);
  auto             json    = ListConnection_to_json_string(handle);
  auto             handle2 = ListConnection_from_json_string(json);
  EXPECT_TRUE(ListConnection_equal(handle, handle2));
  ListConnection_destroy(handle);
  ListConnection_destroy(handle2);
  String_destroy(json);
  EXPECT_THROW(ListConnection_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(ListConnection_from_json_string(nullptr), std::invalid_argument);
}

TEST_F(ListConnectionTest, FillValueNull) {
  EXPECT_THROW(ListConnection_fill_value(3, nullptr), std::invalid_argument);
}

TEST_F(ListConnectionTest, PushBackNull) {
  auto handle = ListConnection_create_empty();
  EXPECT_THROW(ListConnection_push_back(handle, nullptr),
               std::invalid_argument);
  ListConnection_destroy(handle);
}

TEST_F(ListConnectionTest, ContainsNull) {
  auto handle = ListConnection_create_empty();
  EXPECT_THROW(ListConnection_contains(handle, nullptr), std::invalid_argument);
  ListConnection_destroy(handle);
}

TEST_F(ListConnectionTest, IndexNull) {
  auto handle = ListConnection_create_empty();
  EXPECT_THROW(ListConnection_index(handle, nullptr), std::invalid_argument);
  ListConnection_destroy(handle);
}

TEST_F(ListConnectionTest, CreateNullArray) {
  EXPECT_THROW(ListConnection_create(nullptr, 2), std::invalid_argument);
}

TEST_F(ListConnectionTest, At) {
  ConnectionHandle arr[2] = {sh1, sh2};
  auto             handle = ListConnection_create(arr, 2);
  auto             at0    = ListConnection_at(handle, 0);
  auto             at1    = ListConnection_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListConnection_destroy(handle);
  EXPECT_THROW(ListConnection_at(nullptr, 0), std::invalid_argument);
}
