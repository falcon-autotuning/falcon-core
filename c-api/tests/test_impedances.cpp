#include <gtest/gtest.h>

#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/device_structures/Impedance_c_api.h"
#include "falcon_core/physics/device_structures/Impedances_c_api.h"

class ImpedancesTest : public ::testing::Test {
 protected:
  ConnectionHandle conn1, conn2, conn3;
  ImpedanceHandle  imp1, imp2, imp3;
  void             SetUp() override {
    conn1 = Connection_create_barrier_gate(String_wrap("a"));
    conn2 = Connection_create_ohmic(String_wrap("b"));
    conn3 = Connection_create_plunger_gate(String_wrap("c"));
    imp1  = Impedance_create(conn1, 1.1, 2.2);
    imp2  = Impedance_create(conn2, 3.3, 4.4);
    imp3  = Impedance_create(conn3, 5.5, 6.6);
  }
  void TearDown() override {
    Connection_destroy(conn1);
    Connection_destroy(conn2);
    Connection_destroy(conn3);
    Impedance_destroy(imp1);
    Impedance_destroy(imp2);
    Impedance_destroy(imp3);
  }
};

TEST_F(ImpedancesTest, DefaultConstructor) {
  ImpedancesHandle imps = Impedances_create_empty();
  EXPECT_EQ(Impedances_size(imps), 0);
  EXPECT_TRUE(Impedances_empty(imps));
  Impedances_destroy(imps);
}

TEST_F(ImpedancesTest, VectorConstructor) {
  ListImpedanceHandle vec = ListImpedance_create_empty();
  ListImpedance_push_back(vec, imp1);
  ListImpedance_push_back(vec, imp2);
  ImpedancesHandle imps = Impedances_create(vec);
  EXPECT_EQ(Impedances_size(imps), 2);
  EXPECT_TRUE(Impedance_equal(Impedances_const_at(imps, 0), imp1));
  EXPECT_TRUE(Impedance_equal(Impedances_const_at(imps, 1), imp2));
  Impedances_destroy(imps);
  ListImpedance_destroy(vec);
}

TEST_F(ImpedancesTest, PushBackAndAt) {
  ImpedancesHandle imps = Impedances_create_empty();
  Impedances_push_back(imps, imp1);
  Impedances_push_back(imps, imp2);
  EXPECT_EQ(Impedances_size(imps), 2);
  EXPECT_TRUE(Impedance_equal(Impedances_at(imps, 0), imp1));
  EXPECT_TRUE(Impedance_equal(Impedances_at(imps, 1), imp2));
  Impedances_destroy(imps);
}

TEST_F(ImpedancesTest, EraseAtAndClear) {
  ImpedancesHandle imps = Impedances_create_empty();
  Impedances_push_back(imps, imp1);
  Impedances_push_back(imps, imp2);
  Impedances_push_back(imps, imp3);
  EXPECT_EQ(Impedances_size(imps), 3);
  Impedances_erase_at(imps, 1);
  EXPECT_EQ(Impedances_size(imps), 2);
  EXPECT_TRUE(Impedance_equal(Impedances_at(imps, 1), imp3));
  Impedances_clear(imps);
  EXPECT_EQ(Impedances_size(imps), 0);
  EXPECT_TRUE(Impedances_empty(imps));
  Impedances_destroy(imps);
}

TEST_F(ImpedancesTest, ContainsAndIndex) {
  ImpedancesHandle imps = Impedances_create_empty();
  Impedances_push_back(imps, imp1);
  Impedances_push_back(imps, imp2);
  EXPECT_TRUE(Impedances_contains(imps, imp2));
  EXPECT_EQ(Impedances_index(imps, imp2), 1);
  EXPECT_FALSE(Impedances_contains(imps, imp3));
  Impedances_destroy(imps);
}

TEST_F(ImpedancesTest, ItemsBuffer) {
  ImpedancesHandle imps = Impedances_create_empty();
  Impedances_push_back(imps, imp1);
  Impedances_push_back(imps, imp2);
  ImpedanceHandle buffer[2];
  size_t          n = Impedances_items(imps, buffer, 2);
  EXPECT_EQ(n, 2);
  EXPECT_TRUE(Impedance_equal(buffer[0], imp1));
  EXPECT_TRUE(Impedance_equal(buffer[1], imp2));
  Impedances_destroy(imps);
}

TEST_F(ImpedancesTest, EqualityAndInequality) {
  ListImpedanceHandle vec1 = ListImpedance_create_empty();
  ListImpedance_push_back(vec1, imp1);
  ListImpedance_push_back(vec1, imp2);
  ImpedancesHandle imps1 = Impedances_create(vec1);

  ListImpedanceHandle vec2 = ListImpedance_create_empty();
  ListImpedance_push_back(vec2, imp1);
  ListImpedance_push_back(vec2, imp2);
  ImpedancesHandle imps2 = Impedances_create(vec2);

  ListImpedanceHandle vec3 = ListImpedance_create_empty();
  ListImpedance_push_back(vec3, imp3);
  ImpedancesHandle imps3 = Impedances_create(vec3);

  EXPECT_TRUE(Impedances_equal(imps1, imps2));
  EXPECT_TRUE(Impedances_not_equal(imps1, imps3));

  Impedances_destroy(imps1);
  Impedances_destroy(imps2);
  Impedances_destroy(imps3);
  ListImpedance_destroy(vec1);
  ListImpedance_destroy(vec2);
  ListImpedance_destroy(vec3);
}

TEST_F(ImpedancesTest, SerializationRoundTrip) {
  ListImpedanceHandle vec = ListImpedance_create_empty();
  ListImpedance_push_back(vec, imp1);
  ImpedancesHandle imps  = Impedances_create(vec);
  StringHandle     json  = Impedances_to_json_string(imps);
  ImpedancesHandle imps2 = Impedances_from_json_string(json);
  EXPECT_TRUE(Impedances_equal(imps, imps2));
  Impedances_destroy(imps);
  Impedances_destroy(imps2);
  ListImpedance_destroy(vec);
}

TEST_F(ImpedancesTest, EqualityDifferentElements) {
  ListImpedanceHandle vec1 = ListImpedance_create_empty();
  ListImpedance_push_back(vec1, imp1);
  ImpedancesHandle imps1 = Impedances_create(vec1);

  ListImpedanceHandle vec2 = ListImpedance_create_empty();
  ListImpedance_push_back(vec2, imp2);
  ImpedancesHandle imps2 = Impedances_create(vec2);

  EXPECT_FALSE(Impedances_equal(imps1, imps2));

  Impedances_destroy(imps1);
  Impedances_destroy(imps2);
  ListImpedance_destroy(vec1);
  ListImpedance_destroy(vec2);
}

TEST_F(ImpedancesTest, Intersection) {
  ListImpedanceHandle vec1 = ListImpedance_create_empty();
  ListImpedance_push_back(vec1, imp1);
  ListImpedance_push_back(vec1, imp2);
  ImpedancesHandle imps1 = Impedances_create(vec1);

  ListImpedanceHandle vec2 = ListImpedance_create_empty();
  ListImpedance_push_back(vec2, imp2);
  ListImpedance_push_back(vec2, imp3);
  ImpedancesHandle imps2 = Impedances_create(vec2);

  ImpedancesHandle intersection = Impedances_intersection(imps1, imps2);
  EXPECT_EQ(Impedances_size(intersection), 1);
  EXPECT_TRUE(Impedance_equal(Impedances_at(intersection, 0), imp2));

  Impedances_destroy(imps1);
  Impedances_destroy(imps2);
  Impedances_destroy(intersection);
  ListImpedance_destroy(vec1);
  ListImpedance_destroy(vec2);
}

TEST_F(ImpedancesTest, SmallBufferItems) {
  ListImpedanceHandle vec = ListImpedance_create_empty();
  ListImpedance_push_back(vec, imp1);
  ListImpedance_push_back(vec, imp2);
  ImpedancesHandle imps = Impedances_create(vec);

  ImpedanceHandle buffer[1];
  size_t          n = Impedances_items(imps, buffer, 1);
  EXPECT_EQ(n, 1);
  EXPECT_TRUE(Impedance_equal(buffer[0], imp1));

  Impedances_destroy(imps);
  ListImpedance_destroy(vec);
}

TEST_F(ImpedancesTest, NullHandlesThrow) {
  ListImpedanceHandle vec = ListImpedance_create_empty();
  ListImpedance_push_back(vec, imp1);
  ImpedancesHandle imps = Impedances_create(vec);

  EXPECT_THROW(Impedances_destroy(nullptr), std::invalid_argument);
  EXPECT_THROW(Impedances_create(nullptr), std::invalid_argument);
  EXPECT_THROW(Impedances_equal(nullptr, imps), std::invalid_argument);
  EXPECT_THROW(Impedances_equal(imps, nullptr), std::invalid_argument);
  EXPECT_THROW(Impedances_not_equal(nullptr, imps), std::invalid_argument);
  EXPECT_THROW(Impedances_not_equal(imps, nullptr), std::invalid_argument);
  EXPECT_THROW(Impedances_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(Impedances_from_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(Impedances_size(nullptr), std::invalid_argument);
  EXPECT_THROW(Impedances_empty(nullptr), std::invalid_argument);
  EXPECT_THROW(Impedances_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(Impedances_const_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(Impedances_push_back(nullptr, imp1), std::invalid_argument);
  EXPECT_THROW(Impedances_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(Impedances_clear(nullptr), std::invalid_argument);
  EXPECT_THROW(Impedances_contains(nullptr, imp1), std::invalid_argument);
  EXPECT_THROW(Impedances_contains(imps, nullptr), std::invalid_argument);
  EXPECT_THROW(Impedances_index(nullptr, imp1), std::invalid_argument);
  EXPECT_THROW(Impedances_index(imps, nullptr), std::invalid_argument);
  EXPECT_THROW(Impedances_items(imps, nullptr, 0), std::invalid_argument);
  EXPECT_THROW(Impedances_items(nullptr, nullptr, 0), std::invalid_argument);
  EXPECT_THROW(Impedances_push_back(imps, nullptr), std::invalid_argument);
  EXPECT_THROW(Impedances_intersection(nullptr, imps), std::invalid_argument);
  EXPECT_THROW(Impedances_intersection(imps, nullptr), std::invalid_argument);

  Impedances_destroy(imps);
  ListImpedance_destroy(vec);
}
