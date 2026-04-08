#include <falcon-core/generic/ListConnections_c_api.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "falcon-core/physics/device_structures/Connection_c_api.h"

class ListConnectionsTest : public ::testing::Test {
 protected:
  void destroy_string(ConnectionsHandle sh) { Connections_destroy(sh); }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<ConnectionsHandle> created_strings;
  ConnectionsHandle              track_quantity(const ConnectionsHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    ConnectionHandle arr1[2] = {
        Connection_create_plunger_gate(String_wrap("gate1")),
        Connection_create_plunger_gate(String_wrap("gate2"))};
    ConnectionHandle arr2[2] = {
        Connection_create_plunger_gate(String_wrap("gate1")),
        Connection_create_plunger_gate(String_wrap("gate2"))};
    ListConnectionHandle lch1 = ListConnection_create(arr1, 2);
    ListConnectionHandle lch2 = ListConnection_create(arr2, 2);
    sh1                       = track_quantity(Connections_create(lch1));
    sh2                       = track_quantity(Connections_create(lch2));
  }
  ConnectionsHandle sh1;
  ConnectionsHandle sh2;
};

TEST_F(ListConnectionsTest, CreateEmpty) {
  auto handle = ListConnections_create_empty();
  EXPECT_TRUE(ListConnections_empty(handle));
  EXPECT_EQ(ListConnections_size(handle), 0);
  ListConnections_destroy(handle);
  set_last_error(0, nullptr);
  ListConnections_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListConnectionsTest, FillValue) {
  auto handle = ListConnections_fill_value(3, sh1);
  EXPECT_EQ(ListConnections_size(handle), 3);
  ListConnections_destroy(handle);
}

TEST_F(ListConnectionsTest, CreateFromArray) {
  ConnectionsHandle     arr[2] = {sh1, sh2};
  ListConnectionsHandle handle = ListConnections_create(arr, 2);
  EXPECT_EQ(ListConnections_size(handle), 2);
  set_last_error(0, nullptr);
  ListConnections_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  ListConnections_destroy(handle);
}

TEST_F(ListConnectionsTest, SizeEmptyInvalid) {
  auto handle = ListConnections_create_empty();
  EXPECT_EQ(ListConnections_size(handle), 0);
  ListConnections_destroy(handle);
  set_last_error(0, nullptr);
  ListConnections_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListConnectionsTest, EmptyInvalid) {
  auto handle = ListConnections_create_empty();
  EXPECT_TRUE(ListConnections_empty(handle));
  ListConnections_destroy(handle);
  set_last_error(0, nullptr);
  ListConnections_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListConnectionsTest, EraseAtClear) {
  auto handle = ListConnections_fill_value(2, sh1);
  ListConnections_erase_at(handle, 0);
  EXPECT_EQ(ListConnections_size(handle), 1);
  ListConnections_clear(handle);
  EXPECT_TRUE(ListConnections_empty(handle));
  ListConnections_destroy(handle);
  set_last_error(0, nullptr);
  ListConnections_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListConnections_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListConnectionsTest, PushBackContainsIndex) {
  auto handle = ListConnections_create_empty();
  ListConnections_push_back(handle, sh1);
  EXPECT_TRUE(ListConnections_contains(handle, sh1));
  EXPECT_EQ(ListConnections_index(handle, sh1), 0);
  ListConnections_destroy(handle);
  set_last_error(0, nullptr);
  ListConnections_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListConnections_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListConnections_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListConnectionsTest, ItemsAt) {
  ConnectionsHandle arr[2] = {sh1, sh2};
  auto              handle = ListConnections_create(arr, 2);
  ConnectionsHandle out[2];
  EXPECT_EQ(ListConnections_items(handle, out, 2), 2);
  ListConnections_destroy(handle);
  set_last_error(0, nullptr);
  ListConnections_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListConnections_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListConnections_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListConnectionsTest, EqualNotEqualIntersection) {
  ConnectionsHandle arr[2] = {sh1, sh2};
  auto              h1     = ListConnections_create(arr, 2);
  auto              h2     = ListConnections_create(arr, 2);
  EXPECT_TRUE(ListConnections_equal(h1, h2));
  EXPECT_FALSE(ListConnections_not_equal(h1, h2));
  auto h3 = ListConnections_intersection(h1, h2);
  EXPECT_EQ(ListConnections_size(h3), 2);
  ListConnections_destroy(h1);
  ListConnections_destroy(h2);
  ListConnections_destroy(h3);
  set_last_error(0, nullptr);
  ListConnections_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListConnections_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListConnections_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListConnections_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListConnections_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListConnections_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListConnectionsTest, ToJsonFromJson) {
  ConnectionsHandle arr[1]  = {sh1};
  auto              handle  = ListConnections_create(arr, 1);
  auto              json    = ListConnections_to_json_string(handle);
  auto              handle2 = ListConnections_from_json_string(json);
  EXPECT_TRUE(ListConnections_equal(handle, handle2));
  ListConnections_destroy(handle);
  ListConnections_destroy(handle2);
  String_destroy(json);
  set_last_error(0, nullptr);
  ListConnections_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListConnections_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListConnectionsTest, FillValueNull) {
  set_last_error(0, nullptr);
  ListConnections_fill_value(3, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListConnectionsTest, PushBackNull) {
  auto handle = ListConnections_create_empty();
  set_last_error(0, nullptr);
  ListConnections_push_back(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListConnections_destroy(handle);
}

TEST_F(ListConnectionsTest, ContainsNull) {
  auto handle = ListConnections_create_empty();
  set_last_error(0, nullptr);
  ListConnections_contains(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListConnections_destroy(handle);
}

TEST_F(ListConnectionsTest, IndexNull) {
  auto handle = ListConnections_create_empty();
  set_last_error(0, nullptr);
  ListConnections_index(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListConnections_destroy(handle);
}

TEST_F(ListConnectionsTest, CreateNullArray) {
  set_last_error(0, nullptr);
  ListConnections_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListConnectionsTest, At) {
  ConnectionsHandle arr[2] = {sh1, sh2};
  auto              handle = ListConnections_create(arr, 2);
  auto              at0    = ListConnections_at(handle, 0);
  auto              at1    = ListConnections_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListConnections_destroy(handle);
  set_last_error(0, nullptr);
  ListConnections_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
