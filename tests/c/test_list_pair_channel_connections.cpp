#include <falcon-core/generic/ListPairChannelConnections_c_api.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "falcon-core/physics/device_structures/Connection_c_api.h"

class ListPairChannelConnectionsTest : public ::testing::Test {
 protected:
  void destroy_string(PairChannelConnectionsHandle sh) {
    PairChannelConnections_destroy(sh);
  }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<PairChannelConnectionsHandle> created_strings;
  PairChannelConnectionsHandle              track_quantity(
                   const PairChannelConnectionsHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    ChannelHandle arr[2] = {
        Connection_create_plunger_gate(String_wrap("gate1")),
        Connection_create_barrier_gate(String_wrap("gate2"))};
    ChannelHandle arr2[2] = {
        Connection_create_reservoir_gate(String_wrap("gate3")),
        Connection_create_screening_gate(String_wrap("gate4"))};
    sh1 = track_quantity(PairChannelConnections_create(
        Channel_create(String_wrap("Channel1")),
        Connections_create(ListConnection_create(arr, 2))));
    sh2 = track_quantity(PairChannelConnections_create(
        Channel_create(String_wrap("Channel2")),
        Connections_create(ListConnection_create(arr2, 2))));
  }
  PairChannelConnectionsHandle sh1;
  PairChannelConnectionsHandle sh2;
};

TEST_F(ListPairChannelConnectionsTest, CreateEmpty) {
  auto handle = ListPairChannelConnections_create_empty();
  EXPECT_TRUE(ListPairChannelConnections_empty(handle));
  EXPECT_EQ(ListPairChannelConnections_size(handle), 0);
  ListPairChannelConnections_destroy(handle);
  set_last_error(0, nullptr);
  ListPairChannelConnections_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairChannelConnectionsTest, FillValue) {
  auto handle = ListPairChannelConnections_fill_value(3, sh1);
  EXPECT_EQ(ListPairChannelConnections_size(handle), 3);
  ListPairChannelConnections_destroy(handle);
}

TEST_F(ListPairChannelConnectionsTest, CreateFromArray) {
  PairChannelConnectionsHandle     arr[2] = {sh1, sh2};
  ListPairChannelConnectionsHandle handle =
      ListPairChannelConnections_create(arr, 2);
  EXPECT_EQ(ListPairChannelConnections_size(handle), 2);
  set_last_error(0, nullptr);
  ListPairChannelConnections_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairChannelConnections_destroy(handle);
}

TEST_F(ListPairChannelConnectionsTest, SizeEmptyInvalid) {
  auto handle = ListPairChannelConnections_create_empty();
  EXPECT_EQ(ListPairChannelConnections_size(handle), 0);
  ListPairChannelConnections_destroy(handle);
  set_last_error(0, nullptr);
  ListPairChannelConnections_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairChannelConnectionsTest, EmptyInvalid) {
  auto handle = ListPairChannelConnections_create_empty();
  EXPECT_TRUE(ListPairChannelConnections_empty(handle));
  ListPairChannelConnections_destroy(handle);
  set_last_error(0, nullptr);
  ListPairChannelConnections_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairChannelConnectionsTest, EraseAtClear) {
  auto handle = ListPairChannelConnections_fill_value(2, sh1);
  ListPairChannelConnections_erase_at(handle, 0);
  EXPECT_EQ(ListPairChannelConnections_size(handle), 1);
  ListPairChannelConnections_clear(handle);
  EXPECT_TRUE(ListPairChannelConnections_empty(handle));
  ListPairChannelConnections_destroy(handle);
  set_last_error(0, nullptr);
  ListPairChannelConnections_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairChannelConnections_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairChannelConnectionsTest, PushBackContainsIndex) {
  auto handle = ListPairChannelConnections_create_empty();
  ListPairChannelConnections_push_back(handle, sh1);
  EXPECT_TRUE(ListPairChannelConnections_contains(handle, sh1));
  EXPECT_EQ(ListPairChannelConnections_index(handle, sh1), 0);
  ListPairChannelConnections_destroy(handle);
  set_last_error(0, nullptr);
  ListPairChannelConnections_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairChannelConnections_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairChannelConnections_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairChannelConnectionsTest, ItemsAt) {
  PairChannelConnectionsHandle arr[2] = {sh1, sh2};
  auto handle = ListPairChannelConnections_create(arr, 2);
  PairChannelConnectionsHandle out[2];
  EXPECT_EQ(ListPairChannelConnections_items(handle, out, 2), 2);
  ListPairChannelConnections_destroy(handle);
  set_last_error(0, nullptr);
  ListPairChannelConnections_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairChannelConnections_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairChannelConnections_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairChannelConnectionsTest, EqualNotEqualIntersection) {
  PairChannelConnectionsHandle arr[2] = {sh1, sh2};
  auto                         h1 = ListPairChannelConnections_create(arr, 2);
  auto                         h2 = ListPairChannelConnections_create(arr, 2);
  EXPECT_TRUE(ListPairChannelConnections_equal(h1, h2));
  EXPECT_FALSE(ListPairChannelConnections_not_equal(h1, h2));
  auto h3 = ListPairChannelConnections_intersection(h1, h2);
  EXPECT_EQ(ListPairChannelConnections_size(h3), 2);
  ListPairChannelConnections_destroy(h1);
  ListPairChannelConnections_destroy(h2);
  ListPairChannelConnections_destroy(h3);
  set_last_error(0, nullptr);
  ListPairChannelConnections_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairChannelConnections_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairChannelConnections_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairChannelConnections_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairChannelConnections_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairChannelConnections_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairChannelConnectionsTest, ToJsonFromJson) {
  PairChannelConnectionsHandle arr[1] = {sh1};
  auto handle  = ListPairChannelConnections_create(arr, 1);
  auto json    = ListPairChannelConnections_to_json_string(handle);
  auto handle2 = ListPairChannelConnections_from_json_string(json);
  EXPECT_TRUE(ListPairChannelConnections_equal(handle, handle2));
  ListPairChannelConnections_destroy(handle);
  ListPairChannelConnections_destroy(handle2);
  String_destroy(json);
  set_last_error(0, nullptr);
  ListPairChannelConnections_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairChannelConnections_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairChannelConnectionsTest, FillValueNull) {
  set_last_error(0, nullptr);
  ListPairChannelConnections_fill_value(3, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairChannelConnectionsTest, PushBackNull) {
  auto handle = ListPairChannelConnections_create_empty();
  set_last_error(0, nullptr);
  ListPairChannelConnections_push_back(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairChannelConnections_destroy(handle);
}

TEST_F(ListPairChannelConnectionsTest, ContainsNull) {
  auto handle = ListPairChannelConnections_create_empty();
  set_last_error(0, nullptr);
  ListPairChannelConnections_contains(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairChannelConnections_destroy(handle);
}

TEST_F(ListPairChannelConnectionsTest, IndexNull) {
  auto handle = ListPairChannelConnections_create_empty();
  set_last_error(0, nullptr);
  ListPairChannelConnections_index(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairChannelConnections_destroy(handle);
}

TEST_F(ListPairChannelConnectionsTest, CreateNullArray) {
  set_last_error(0, nullptr);
  ListPairChannelConnections_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairChannelConnectionsTest, At) {
  PairChannelConnectionsHandle arr[2] = {sh1, sh2};
  auto handle = ListPairChannelConnections_create(arr, 2);
  auto at0    = ListPairChannelConnections_at(handle, 0);
  auto at1    = ListPairChannelConnections_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListPairChannelConnections_destroy(handle);
  set_last_error(0, nullptr);
  ListPairChannelConnections_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
