#include <falcon_core/generic/ListGroup_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

class ListGroupTest : public ::testing::Test {
 protected:
  void destroy_string(GroupHandle sh) { Group_destroy(sh); }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<GroupHandle> created_strings;
  GroupHandle              track_quantity(const GroupHandle& s) {
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
    ListConnectionHandle p2       = ListConnection_create(p2raw, 1);
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
    sh1 = track_quantity(Group_create(Channel_create(String_wrap("Chan1")),
                                      1,
                                      Connections_create(s1),
                                      Connections_create(r1),
                                      Connections_create(p1),
                                      Connections_create(b1),
                                      Connections_create(o1)));
    sh2 = track_quantity(Group_create(Channel_create(String_wrap("Chan2")),
                                      2,
                                      Connections_create(s2),
                                      Connections_create(r2),
                                      Connections_create(p2),
                                      Connections_create(b2),
                                      Connections_create(o2)));
  }
  GroupHandle sh1;
  GroupHandle sh2;
};

TEST_F(ListGroupTest, CreateEmpty) {
  auto handle = ListGroup_create_empty();
  EXPECT_TRUE(ListGroup_empty(handle));
  EXPECT_EQ(ListGroup_size(handle), 0);
  ListGroup_destroy(handle);
  EXPECT_THROW(ListGroup_destroy(nullptr), std::invalid_argument);
}

TEST_F(ListGroupTest, FillValue) {
  auto handle = ListGroup_fill_value(3, sh1);
  EXPECT_EQ(ListGroup_size(handle), 3);
  ListGroup_destroy(handle);
}

TEST_F(ListGroupTest, CreateFromArray) {
  GroupHandle     arr[2] = {sh1, sh2};
  ListGroupHandle handle = ListGroup_create(arr, 2);
  EXPECT_EQ(ListGroup_size(handle), 2);
  EXPECT_THROW(ListGroup_create(nullptr, 2), std::invalid_argument);
  ListGroup_destroy(handle);
}

TEST_F(ListGroupTest, SizeEmptyInvalid) {
  auto handle = ListGroup_create_empty();
  EXPECT_EQ(ListGroup_size(handle), 0);
  ListGroup_destroy(handle);
  EXPECT_THROW(ListGroup_size(nullptr), std::invalid_argument);
}

TEST_F(ListGroupTest, EmptyInvalid) {
  auto handle = ListGroup_create_empty();
  EXPECT_TRUE(ListGroup_empty(handle));
  ListGroup_destroy(handle);
  EXPECT_THROW(ListGroup_empty(nullptr), std::invalid_argument);
}

TEST_F(ListGroupTest, EraseAtClear) {
  auto handle = ListGroup_fill_value(2, sh1);
  ListGroup_erase_at(handle, 0);
  EXPECT_EQ(ListGroup_size(handle), 1);
  ListGroup_clear(handle);
  EXPECT_TRUE(ListGroup_empty(handle));
  ListGroup_destroy(handle);
  EXPECT_THROW(ListGroup_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(ListGroup_clear(nullptr), std::invalid_argument);
}

TEST_F(ListGroupTest, PushBackContainsIndex) {
  auto handle = ListGroup_create_empty();
  ListGroup_push_back(handle, sh1);
  EXPECT_TRUE(ListGroup_contains(handle, sh1));
  EXPECT_EQ(ListGroup_index(handle, sh1), 0);
  ListGroup_destroy(handle);
  EXPECT_THROW(ListGroup_push_back(nullptr, sh1), std::invalid_argument);
  EXPECT_THROW(ListGroup_contains(nullptr, sh1), std::invalid_argument);
  EXPECT_THROW(ListGroup_index(nullptr, sh1), std::invalid_argument);
}

TEST_F(ListGroupTest, ItemsAt) {
  GroupHandle arr[2] = {sh1, sh2};
  auto        handle = ListGroup_create(arr, 2);
  GroupHandle out[2];
  EXPECT_EQ(ListGroup_items(handle, out, 2), 2);
  ListGroup_destroy(handle);
  EXPECT_THROW(ListGroup_items(nullptr, out, 2), std::invalid_argument);
  EXPECT_THROW(ListGroup_items(handle, nullptr, 2), std::invalid_argument);
  EXPECT_THROW(ListGroup_at(nullptr, 0), std::invalid_argument);
}

TEST_F(ListGroupTest, EqualNotEqualIntersection) {
  GroupHandle arr[2] = {sh1, sh2};
  auto        h1     = ListGroup_create(arr, 2);
  auto        h2     = ListGroup_create(arr, 2);
  EXPECT_TRUE(ListGroup_equal(h1, h2));
  EXPECT_FALSE(ListGroup_not_equal(h1, h2));
  auto h3 = ListGroup_intersection(h1, h2);
  EXPECT_EQ(ListGroup_size(h3), 2);
  ListGroup_destroy(h1);
  ListGroup_destroy(h2);
  ListGroup_destroy(h3);
  EXPECT_THROW(ListGroup_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListGroup_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListGroup_not_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListGroup_not_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListGroup_intersection(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListGroup_intersection(h1, nullptr), std::invalid_argument);
}

TEST_F(ListGroupTest, ToJsonFromJson) {
  GroupHandle arr[1]  = {sh1};
  auto        handle  = ListGroup_create(arr, 1);
  auto        json    = ListGroup_to_json_string(handle);
  auto        handle2 = ListGroup_from_json_string(json);
  EXPECT_TRUE(ListGroup_equal(handle, handle2));
  ListGroup_destroy(handle);
  ListGroup_destroy(handle2);
  String_destroy(json);
  EXPECT_THROW(ListGroup_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(ListGroup_from_json_string(nullptr), std::invalid_argument);
}

TEST_F(ListGroupTest, FillValueNull) {
  EXPECT_THROW(ListGroup_fill_value(3, nullptr), std::invalid_argument);
}

TEST_F(ListGroupTest, PushBackNull) {
  auto handle = ListGroup_create_empty();
  EXPECT_THROW(ListGroup_push_back(handle, nullptr), std::invalid_argument);
  ListGroup_destroy(handle);
}

TEST_F(ListGroupTest, ContainsNull) {
  auto handle = ListGroup_create_empty();
  EXPECT_THROW(ListGroup_contains(handle, nullptr), std::invalid_argument);
  ListGroup_destroy(handle);
}

TEST_F(ListGroupTest, IndexNull) {
  auto handle = ListGroup_create_empty();
  EXPECT_THROW(ListGroup_index(handle, nullptr), std::invalid_argument);
  ListGroup_destroy(handle);
}

TEST_F(ListGroupTest, CreateNullArray) {
  EXPECT_THROW(ListGroup_create(nullptr, 2), std::invalid_argument);
}

TEST_F(ListGroupTest, At) {
  GroupHandle arr[2] = {sh1, sh2};
  auto        handle = ListGroup_create(arr, 2);
  auto        at0    = ListGroup_at(handle, 0);
  auto        at1    = ListGroup_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListGroup_destroy(handle);
  EXPECT_THROW(ListGroup_at(nullptr, 0), std::invalid_argument);
}
