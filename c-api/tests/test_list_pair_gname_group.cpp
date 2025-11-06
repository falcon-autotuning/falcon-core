#include <falcon_core/generic/ListPairGnameGroup_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "falcon_core/generic/ListConnection_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"

class ListPairGnameGroupTest : public ::testing::Test {
 protected:
  void destroy_string(PairGnameGroupHandle sh) { PairGnameGroup_destroy(sh); }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<PairGnameGroupHandle> created_strings;
  PairGnameGroupHandle track_quantity(const PairGnameGroupHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    ConnectionHandle s1raw[2] = {
        Connection_create_screening_gate(String_wrap("S1")),
        Connection_create_screening_gate(String_wrap("S2"))};
    ListConnectionHandle s1       = ListConnection_create(s1raw, 2);
    ConnectionHandle     s2raw[2] = {
        Connection_create_screening_gate(String_wrap("S3")),
        Connection_create_screening_gate(String_wrap("S4"))};
    ListConnectionHandle s2       = ListConnection_create(s2raw, 2);
    ConnectionHandle     r1raw[2] = {
        Connection_create_reservoir_gate(String_wrap("R1")),
        Connection_create_reservoir_gate(String_wrap("R2"))};
    ListConnectionHandle r1       = ListConnection_create(r1raw, 2);
    ConnectionHandle     r2raw[2] = {
        Connection_create_reservoir_gate(String_wrap("R3")),
        Connection_create_reservoir_gate(String_wrap("R4"))};
    ListConnectionHandle r2       = ListConnection_create(r2raw, 2);
    ConnectionHandle     b1raw[2] = {
        Connection_create_barrier_gate(String_wrap("B1")),
        Connection_create_barrier_gate(String_wrap("B2"))};
    ListConnectionHandle b1       = ListConnection_create(b1raw, 2);
    ConnectionHandle     b2raw[2] = {
        Connection_create_barrier_gate(String_wrap("B3")),
        Connection_create_barrier_gate(String_wrap("B4"))};
    ListConnectionHandle b2       = ListConnection_create(b2raw, 2);
    ConnectionHandle     p1raw[1] = {
        Connection_create_plunger_gate(String_wrap("P1"))};
    ListConnectionHandle p1       = ListConnection_create(p1raw, 1);
    ConnectionHandle     p2raw[1] = {
        Connection_create_plunger_gate(String_wrap("P2"))};
    ListConnectionHandle p2       = ListConnection_create(p2raw, 2);
    ConnectionHandle     o1raw[7] = {
        Connection_create_ohmic(String_wrap("O1")),
        Connection_create_reservoir_gate(String_wrap("R1")),
        Connection_create_barrier_gate(String_wrap("B1")),
        Connection_create_plunger_gate(String_wrap("P1")),
        Connection_create_barrier_gate(String_wrap("B2")),
        Connection_create_reservoir_gate(String_wrap("R2")),
        Connection_create_ohmic(String_wrap("O2"))};
    ListConnectionHandle o1       = ListConnection_create(o1raw, 7);
    ConnectionHandle     o2raw[7] = {
        Connection_create_ohmic(String_wrap("O3")),
        Connection_create_reservoir_gate(String_wrap("R3")),
        Connection_create_barrier_gate(String_wrap("B3")),
        Connection_create_plunger_gate(String_wrap("P2")),
        Connection_create_barrier_gate(String_wrap("B4")),
        Connection_create_reservoir_gate(String_wrap("R4")),
        Connection_create_ohmic(String_wrap("O4"))};
    ListConnectionHandle o2 = ListConnection_create(o2raw, 7);
    sh1                     = track_quantity(
        PairGnameGroup_create(Gname_create(String_wrap("Connection1")),
                              Group_create(Channel_create(String_wrap("Chan1")),
                                           1,
                                           Connections_create(s1),
                                           Connections_create(r1),
                                           Connections_create(p1),
                                           Connections_create(b1),
                                           Connections_create(o1))));
    sh2 = track_quantity(
        PairGnameGroup_create(Gname_create(String_wrap("Connection2")),
                              Group_create(Channel_create(String_wrap("Chan1")),
                                           1,
                                           Connections_create(s2),
                                           Connections_create(r2),
                                           Connections_create(p2),
                                           Connections_create(b2),
                                           Connections_create(o2))));
  }
  PairGnameGroupHandle sh1;
  PairGnameGroupHandle sh2;
};

TEST_F(ListPairGnameGroupTest, CreateEmpty) {
  auto handle = ListPairGnameGroup_create_empty();
  EXPECT_TRUE(ListPairGnameGroup_empty(handle));
  EXPECT_EQ(ListPairGnameGroup_size(handle), 0);
  ListPairGnameGroup_destroy(handle);
  EXPECT_THROW(ListPairGnameGroup_destroy(nullptr), std::invalid_argument);
}

TEST_F(ListPairGnameGroupTest, FillValue) {
  auto handle = ListPairGnameGroup_fill_value(3, sh1);
  EXPECT_EQ(ListPairGnameGroup_size(handle), 3);
  ListPairGnameGroup_destroy(handle);
}

TEST_F(ListPairGnameGroupTest, CreateFromArray) {
  PairGnameGroupHandle     arr[2] = {sh1, sh2};
  ListPairGnameGroupHandle handle = ListPairGnameGroup_create(arr, 2);
  EXPECT_EQ(ListPairGnameGroup_size(handle), 2);
  EXPECT_THROW(ListPairGnameGroup_create(nullptr, 2), std::invalid_argument);
  ListPairGnameGroup_destroy(handle);
}

TEST_F(ListPairGnameGroupTest, SizeEmptyInvalid) {
  auto handle = ListPairGnameGroup_create_empty();
  EXPECT_EQ(ListPairGnameGroup_size(handle), 0);
  ListPairGnameGroup_destroy(handle);
  EXPECT_THROW(ListPairGnameGroup_size(nullptr), std::invalid_argument);
}

TEST_F(ListPairGnameGroupTest, EmptyInvalid) {
  auto handle = ListPairGnameGroup_create_empty();
  EXPECT_TRUE(ListPairGnameGroup_empty(handle));
  ListPairGnameGroup_destroy(handle);
  EXPECT_THROW(ListPairGnameGroup_empty(nullptr), std::invalid_argument);
}

TEST_F(ListPairGnameGroupTest, EraseAtClear) {
  auto handle = ListPairGnameGroup_fill_value(2, sh1);
  ListPairGnameGroup_erase_at(handle, 0);
  EXPECT_EQ(ListPairGnameGroup_size(handle), 1);
  ListPairGnameGroup_clear(handle);
  EXPECT_TRUE(ListPairGnameGroup_empty(handle));
  ListPairGnameGroup_destroy(handle);
  EXPECT_THROW(ListPairGnameGroup_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(ListPairGnameGroup_clear(nullptr), std::invalid_argument);
}

TEST_F(ListPairGnameGroupTest, PushBackContainsIndex) {
  auto handle = ListPairGnameGroup_create_empty();
  ListPairGnameGroup_push_back(handle, sh1);
  EXPECT_TRUE(ListPairGnameGroup_contains(handle, sh1));
  EXPECT_EQ(ListPairGnameGroup_index(handle, sh1), 0);
  ListPairGnameGroup_destroy(handle);
  EXPECT_THROW(ListPairGnameGroup_push_back(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(ListPairGnameGroup_contains(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(ListPairGnameGroup_index(nullptr, sh1), std::invalid_argument);
}

TEST_F(ListPairGnameGroupTest, ItemsAt) {
  PairGnameGroupHandle arr[2] = {sh1, sh2};
  auto                 handle = ListPairGnameGroup_create(arr, 2);
  PairGnameGroupHandle out[2];
  EXPECT_EQ(ListPairGnameGroup_items(handle, out, 2), 2);
  EXPECT_THROW(ListPairGnameGroup_items(nullptr, out, 2),
               std::invalid_argument);
  EXPECT_THROW(ListPairGnameGroup_items(handle, nullptr, 2),
               std::invalid_argument);
  ListPairGnameGroup_destroy(handle);
  EXPECT_THROW(ListPairGnameGroup_at(nullptr, 0), std::invalid_argument);
}

TEST_F(ListPairGnameGroupTest, EqualNotEqualIntersection) {
  PairGnameGroupHandle arr[2] = {sh1, sh2};
  auto                 h1     = ListPairGnameGroup_create(arr, 2);
  auto                 h2     = ListPairGnameGroup_create(arr, 2);
  EXPECT_TRUE(ListPairGnameGroup_equal(h1, h2));
  EXPECT_FALSE(ListPairGnameGroup_not_equal(h1, h2));
  auto h3 = ListPairGnameGroup_intersection(h1, h2);
  EXPECT_EQ(ListPairGnameGroup_size(h3), 2);
  ListPairGnameGroup_destroy(h1);
  ListPairGnameGroup_destroy(h2);
  ListPairGnameGroup_destroy(h3);
  EXPECT_THROW(ListPairGnameGroup_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListPairGnameGroup_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListPairGnameGroup_not_equal(h1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListPairGnameGroup_not_equal(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListPairGnameGroup_intersection(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListPairGnameGroup_intersection(h1, nullptr),
               std::invalid_argument);
}

TEST_F(ListPairGnameGroupTest, ToJsonFromJson) {
  PairGnameGroupHandle arr[1]  = {sh1};
  auto                 handle  = ListPairGnameGroup_create(arr, 1);
  auto                 json    = ListPairGnameGroup_to_json_string(handle);
  auto                 handle2 = ListPairGnameGroup_from_json_string(json);
  EXPECT_TRUE(ListPairGnameGroup_equal(handle, handle2));
  ListPairGnameGroup_destroy(handle);
  ListPairGnameGroup_destroy(handle2);
  String_destroy(json);
  EXPECT_THROW(ListPairGnameGroup_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListPairGnameGroup_from_json_string(nullptr),
               std::invalid_argument);
}

TEST_F(ListPairGnameGroupTest, FillValueNull) {
  EXPECT_THROW(ListPairGnameGroup_fill_value(3, nullptr),
               std::invalid_argument);
}

TEST_F(ListPairGnameGroupTest, PushBackNull) {
  auto handle = ListPairGnameGroup_create_empty();
  EXPECT_THROW(ListPairGnameGroup_push_back(handle, nullptr),
               std::invalid_argument);
  ListPairGnameGroup_destroy(handle);
}

TEST_F(ListPairGnameGroupTest, ContainsNull) {
  auto handle = ListPairGnameGroup_create_empty();
  EXPECT_THROW(ListPairGnameGroup_contains(handle, nullptr),
               std::invalid_argument);
  ListPairGnameGroup_destroy(handle);
}

TEST_F(ListPairGnameGroupTest, IndexNull) {
  auto handle = ListPairGnameGroup_create_empty();
  EXPECT_THROW(ListPairGnameGroup_index(handle, nullptr),
               std::invalid_argument);
  ListPairGnameGroup_destroy(handle);
}

TEST_F(ListPairGnameGroupTest, CreateNullArray) {
  EXPECT_THROW(ListPairGnameGroup_create(nullptr, 2), std::invalid_argument);
}

TEST_F(ListPairGnameGroupTest, At) {
  PairGnameGroupHandle arr[2] = {sh1, sh2};
  auto                 handle = ListPairGnameGroup_create(arr, 2);
  auto                 at0    = ListPairGnameGroup_at(handle, 0);
  auto                 at1    = ListPairGnameGroup_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListPairGnameGroup_destroy(handle);
  EXPECT_THROW(ListPairGnameGroup_at(nullptr, 0), std::invalid_argument);
}
