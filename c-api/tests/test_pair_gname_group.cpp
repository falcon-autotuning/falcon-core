#include <gtest/gtest.h>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/PairGnameGroup_c_api.h"
#include "falcon_core/generic/String_c_api.h"

class PairGnameGroupTest : public ::testing::Test {
 protected:
  void SetUp() override {
    ConnectionHandle s1raw[2] = {
        Connection_create_screening_gate(String_wrap("S1")),
        Connection_create_screening_gate(String_wrap("S2"))};
    ConnectionHandle s2raw[2] = {
        Connection_create_screening_gate(String_wrap("S3")),
        Connection_create_screening_gate(String_wrap("S4"))};
    ListConnectionHandle s2       = ListConnection_create(s2raw, 2);
    ConnectionHandle     r1raw[2] = {
        Connection_create_reservoir_gate(String_wrap("R1")),
        Connection_create_reservoir_gate(String_wrap("R2"))};
    ConnectionHandle r2raw[2] = {
        Connection_create_reservoir_gate(String_wrap("R3")),
        Connection_create_reservoir_gate(String_wrap("R4"))};
    ListConnectionHandle r2       = ListConnection_create(r2raw, 2);
    ConnectionHandle     b1raw[2] = {
        Connection_create_barrier_gate(String_wrap("B1")),
        Connection_create_barrier_gate(String_wrap("B2"))};
    ConnectionHandle b2raw[2] = {
        Connection_create_barrier_gate(String_wrap("B3")),
        Connection_create_barrier_gate(String_wrap("B4"))};
    ListConnectionHandle b2       = ListConnection_create(b2raw, 2);
    ConnectionHandle     p1raw[1] = {
        Connection_create_plunger_gate(String_wrap("P1"))};
    ConnectionHandle p2raw[1] = {
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
    ConnectionHandle o2raw[7] = {
        Connection_create_ohmic(String_wrap("O3")),
        Connection_create_reservoir_gate(String_wrap("R3")),
        Connection_create_barrier_gate(String_wrap("B3")),
        Connection_create_plunger_gate(String_wrap("P2")),
        Connection_create_barrier_gate(String_wrap("B4")),
        Connection_create_reservoir_gate(String_wrap("R4")),
        Connection_create_ohmic(String_wrap("O4"))};
    ListConnectionHandle o2 = ListConnection_create(o2raw, 7);
    t1                      = Gname_create(String_wrap("A"));
    t2                      = Group_create(Channel_create(String_wrap("Chan2")),
                      2,
                      Connections_create(s2),
                      Connections_create(r2),
                      Connections_create(p2),
                      Connections_create(b2),
                      Connections_create(o2));
    pair1                   = PairGnameGroup_create(t1, t2);
    pair2                   = PairGnameGroup_create(t1, t2);
  }
  void TearDown() override {
    PairGnameGroup_destroy(pair1);
    PairGnameGroup_destroy(pair2);
    Gname_destroy(t1);
    Group_destroy(t2);
  }
  PairGnameGroupHandle pair1;
  PairGnameGroupHandle pair2;
  GnameHandle          t1;
  GroupHandle          t2;
};

TEST_F(PairGnameGroupTest, CreateDestroy) {
  set_last_error(0, nullptr);
  PairGnameGroup_create(nullptr, t2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairGnameGroup_create(t1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairGnameGroup_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairGnameGroupTest, Accessors) {
  auto f = PairGnameGroup_first(pair1);
  auto s = PairGnameGroup_second(pair1);
  EXPECT_TRUE(Gname_equal(f, t1));
  EXPECT_TRUE(Group_equal(s, t2));
  set_last_error(0, nullptr);
  PairGnameGroup_first(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairGnameGroup_second(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairGnameGroupTest, Equality) {
  EXPECT_TRUE(PairGnameGroup_equal(pair1, pair2));
  EXPECT_FALSE(PairGnameGroup_not_equal(pair1, pair2));
  set_last_error(0, nullptr);
  PairGnameGroup_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairGnameGroup_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairGnameGroup_not_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairGnameGroup_not_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairGnameGroupTest, ToJsonFromJson) {
  auto json = PairGnameGroup_to_json_string(pair1);
  auto p2   = PairGnameGroup_from_json_string(json);
  EXPECT_TRUE(PairGnameGroup_equal(pair1, p2));
  PairGnameGroup_destroy(p2);
  set_last_error(0, nullptr);
  PairGnameGroup_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairGnameGroup_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
