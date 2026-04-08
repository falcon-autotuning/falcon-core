#include <falcon-core/generic/ListPairConnectionConnections_c_api.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "falcon-core/physics/device_structures/Connection_c_api.h"

class ListPairConnectionConnectionsTest : public ::testing::Test {
 protected:
  void destroy_string(PairConnectionConnectionsHandle sh) {
    PairConnectionConnections_destroy(sh);
  }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<PairConnectionConnectionsHandle> created_strings;
  PairConnectionConnectionsHandle              track_quantity(
                   const PairConnectionConnectionsHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    ConnectionHandle arr[2] = {
        Connection_create_plunger_gate(String_wrap("gate1")),
        Connection_create_barrier_gate(String_wrap("gate2"))};
    ConnectionHandle arr2[2] = {
        Connection_create_reservoir_gate(String_wrap("gate3")),
        Connection_create_screening_gate(String_wrap("gate4"))};
    sh1 = track_quantity(PairConnectionConnections_create(
        Connection_create_plunger_gate(String_wrap("Connection1")),
        Connections_create(ListConnection_create(arr, 2))));
    sh2 = track_quantity(PairConnectionConnections_create(
        Connection_create_plunger_gate(String_wrap("Connection2")),
        Connections_create(ListConnection_create(arr2, 2))));
  }
  PairConnectionConnectionsHandle sh1;
  PairConnectionConnectionsHandle sh2;
};

TEST_F(ListPairConnectionConnectionsTest, CreateEmpty) {
  auto handle = ListPairConnectionConnections_create_empty();
  EXPECT_TRUE(ListPairConnectionConnections_empty(handle));
  EXPECT_EQ(ListPairConnectionConnections_size(handle), 0);
  ListPairConnectionConnections_destroy(handle);
  set_last_error(0, nullptr);
  ListPairConnectionConnections_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionConnectionsTest, FillValue) {
  auto handle = ListPairConnectionConnections_fill_value(3, sh1);
  EXPECT_EQ(ListPairConnectionConnections_size(handle), 3);
  ListPairConnectionConnections_destroy(handle);
}

TEST_F(ListPairConnectionConnectionsTest, CreateFromArray) {
  PairConnectionConnectionsHandle     arr[2] = {sh1, sh2};
  ListPairConnectionConnectionsHandle handle =
      ListPairConnectionConnections_create(arr, 2);
  EXPECT_EQ(ListPairConnectionConnections_size(handle), 2);
  set_last_error(0, nullptr);
  ListPairConnectionConnections_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairConnectionConnections_destroy(handle);
}

TEST_F(ListPairConnectionConnectionsTest, SizeEmptyInvalid) {
  auto handle = ListPairConnectionConnections_create_empty();
  EXPECT_EQ(ListPairConnectionConnections_size(handle), 0);
  ListPairConnectionConnections_destroy(handle);
  set_last_error(0, nullptr);
  ListPairConnectionConnections_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionConnectionsTest, EmptyInvalid) {
  auto handle = ListPairConnectionConnections_create_empty();
  EXPECT_TRUE(ListPairConnectionConnections_empty(handle));
  ListPairConnectionConnections_destroy(handle);
  set_last_error(0, nullptr);
  ListPairConnectionConnections_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionConnectionsTest, EraseAtClear) {
  auto handle = ListPairConnectionConnections_fill_value(2, sh1);
  ListPairConnectionConnections_erase_at(handle, 0);
  EXPECT_EQ(ListPairConnectionConnections_size(handle), 1);
  ListPairConnectionConnections_clear(handle);
  EXPECT_TRUE(ListPairConnectionConnections_empty(handle));
  ListPairConnectionConnections_destroy(handle);
  set_last_error(0, nullptr);
  ListPairConnectionConnections_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionConnections_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionConnectionsTest, PushBackContainsIndex) {
  auto handle = ListPairConnectionConnections_create_empty();
  ListPairConnectionConnections_push_back(handle, sh1);
  EXPECT_TRUE(ListPairConnectionConnections_contains(handle, sh1));
  EXPECT_EQ(ListPairConnectionConnections_index(handle, sh1), 0);
  ListPairConnectionConnections_destroy(handle);
  set_last_error(0, nullptr);
  ListPairConnectionConnections_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionConnections_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionConnections_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionConnectionsTest, ItemsAt) {
  PairConnectionConnectionsHandle arr[2] = {sh1, sh2};
  auto handle = ListPairConnectionConnections_create(arr, 2);
  PairConnectionConnectionsHandle out[2];
  EXPECT_EQ(ListPairConnectionConnections_items(handle, out, 2), 2);
  ListPairConnectionConnections_destroy(handle);
  set_last_error(0, nullptr);
  ListPairConnectionConnections_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionConnections_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionConnections_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionConnectionsTest, EqualNotEqualIntersection) {
  PairConnectionConnectionsHandle arr[2] = {sh1, sh2};
  auto h1 = ListPairConnectionConnections_create(arr, 2);
  auto h2 = ListPairConnectionConnections_create(arr, 2);
  EXPECT_TRUE(ListPairConnectionConnections_equal(h1, h2));
  EXPECT_FALSE(ListPairConnectionConnections_not_equal(h1, h2));
  auto h3 = ListPairConnectionConnections_intersection(h1, h2);
  EXPECT_EQ(ListPairConnectionConnections_size(h3), 2);
  ListPairConnectionConnections_destroy(h1);
  ListPairConnectionConnections_destroy(h2);
  ListPairConnectionConnections_destroy(h3);
  set_last_error(0, nullptr);
  ListPairConnectionConnections_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionConnections_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionConnections_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionConnections_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionConnections_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionConnections_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionConnectionsTest, ToJsonFromJson) {
  PairConnectionConnectionsHandle arr[1] = {sh1};
  auto handle  = ListPairConnectionConnections_create(arr, 1);
  auto json    = ListPairConnectionConnections_to_json_string(handle);
  auto handle2 = ListPairConnectionConnections_from_json_string(json);
  EXPECT_TRUE(ListPairConnectionConnections_equal(handle, handle2));
  ListPairConnectionConnections_destroy(handle);
  ListPairConnectionConnections_destroy(handle2);
  String_destroy(json);
  set_last_error(0, nullptr);
  ListPairConnectionConnections_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairConnectionConnections_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionConnectionsTest, FillValueNull) {
  set_last_error(0, nullptr);
  ListPairConnectionConnections_fill_value(3, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionConnectionsTest, PushBackNull) {
  auto handle = ListPairConnectionConnections_create_empty();
  set_last_error(0, nullptr);
  ListPairConnectionConnections_push_back(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairConnectionConnections_destroy(handle);
}

TEST_F(ListPairConnectionConnectionsTest, ContainsNull) {
  auto handle = ListPairConnectionConnections_create_empty();
  set_last_error(0, nullptr);
  ListPairConnectionConnections_contains(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairConnectionConnections_destroy(handle);
}

TEST_F(ListPairConnectionConnectionsTest, IndexNull) {
  auto handle = ListPairConnectionConnections_create_empty();
  set_last_error(0, nullptr);
  ListPairConnectionConnections_index(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairConnectionConnections_destroy(handle);
}

TEST_F(ListPairConnectionConnectionsTest, CreateNullArray) {
  set_last_error(0, nullptr);
  ListPairConnectionConnections_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairConnectionConnectionsTest, At) {
  PairConnectionConnectionsHandle arr[2] = {sh1, sh2};
  auto handle = ListPairConnectionConnections_create(arr, 2);
  auto at0    = ListPairConnectionConnections_at(handle, 0);
  auto at1    = ListPairConnectionConnections_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListPairConnectionConnections_destroy(handle);
  set_last_error(0, nullptr);
  ListPairConnectionConnections_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
