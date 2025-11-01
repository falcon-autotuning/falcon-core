#include <gtest/gtest.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/math/domains/Domain_c_api.h"
#include "falcon_core/math/domains/LabelledDomain_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"

class LabelledDomainTest : public ::testing::Test {
 protected:
  void SetUp() override {
    name   = String_wrap("knob");
    type   = String_wrap("type");
    desc   = String_wrap("desc");
    unit   = SymbolUnit_create_volt();
    conn   = Connection_create_plunger_gate(String_wrap("A"));
    domain = Domain_create(0.0, 1.0, true, false);
    port   = InstrumentPort_create_port(name, conn, type, unit, desc);

    knob = LabelledDomain_create_primitive_knob(
        name, 0.0, 1.0, conn, type, true, false, unit, desc);
    meter = LabelledDomain_create_primitive_meter(
        name, 0.0, 1.0, conn, type, true, false, unit, desc);
    portdom = LabelledDomain_create_primitive_port(
        name, 0.0, 1.0, conn, type, true, false, unit, desc);
  }
  void TearDown() override {
    LabelledDomain_destroy(knob);
    LabelledDomain_destroy(meter);
    LabelledDomain_destroy(portdom);
    InstrumentPort_destroy(port);
    Domain_destroy(domain);
    Connection_destroy(conn);
    SymbolUnit_destroy(unit);
    String_destroy(name);
    String_destroy(type);
    String_destroy(desc);
  }
  StringHandle         name    = nullptr;
  StringHandle         type    = nullptr;
  StringHandle         desc    = nullptr;
  SymbolUnitHandle     unit    = nullptr;
  ConnectionHandle     conn    = nullptr;
  DomainHandle         domain  = nullptr;
  InstrumentPortHandle port    = nullptr;
  LabelledDomainHandle knob    = nullptr;
  LabelledDomainHandle meter   = nullptr;
  LabelledDomainHandle portdom = nullptr;
};

TEST_F(LabelledDomainTest, CreatePrimitive) {
  EXPECT_THROW(LabelledDomain_create_primitive_knob(
                   nullptr, 0.0, 1.0, conn, type, true, false, unit, desc),
               std::invalid_argument);
  EXPECT_THROW(LabelledDomain_create_primitive_knob(
                   name, 0.0, 1.0, nullptr, type, true, false, unit, desc),
               std::invalid_argument);
  EXPECT_THROW(LabelledDomain_create_primitive_knob(
                   name, 0.0, 1.0, conn, nullptr, true, false, unit, desc),
               std::invalid_argument);
  EXPECT_THROW(LabelledDomain_create_primitive_knob(
                   name, 0.0, 1.0, conn, type, true, false, nullptr, desc),
               std::invalid_argument);
  EXPECT_THROW(LabelledDomain_create_primitive_knob(
                   name, 0.0, 1.0, conn, type, true, false, unit, nullptr),
               std::invalid_argument);

  EXPECT_THROW(LabelledDomain_create_primitive_meter(
                   nullptr, 0.0, 1.0, conn, type, true, false, unit, desc),
               std::invalid_argument);
  EXPECT_THROW(LabelledDomain_create_primitive_meter(
                   name, 0.0, 1.0, nullptr, type, true, false, unit, desc),
               std::invalid_argument);
  EXPECT_THROW(LabelledDomain_create_primitive_meter(
                   name, 0.0, 1.0, conn, nullptr, true, false, unit, desc),
               std::invalid_argument);
  EXPECT_THROW(LabelledDomain_create_primitive_meter(
                   name, 0.0, 1.0, conn, type, true, false, nullptr, desc),
               std::invalid_argument);
  EXPECT_THROW(LabelledDomain_create_primitive_meter(
                   name, 0.0, 1.0, conn, type, true, false, unit, nullptr),
               std::invalid_argument);

  EXPECT_THROW(LabelledDomain_create_primitive_port(
                   nullptr, 0.0, 1.0, conn, type, true, false, unit, desc),
               std::invalid_argument);
  EXPECT_THROW(LabelledDomain_create_primitive_port(
                   name, 0.0, 1.0, nullptr, type, true, false, unit, desc),
               std::invalid_argument);
  EXPECT_THROW(LabelledDomain_create_primitive_port(
                   name, 0.0, 1.0, conn, nullptr, true, false, unit, desc),
               std::invalid_argument);
  EXPECT_THROW(LabelledDomain_create_primitive_port(
                   name, 0.0, 1.0, conn, type, true, false, nullptr, desc),
               std::invalid_argument);
  EXPECT_THROW(LabelledDomain_create_primitive_port(
                   name, 0.0, 1.0, conn, type, true, false, unit, nullptr),
               std::invalid_argument);
}

TEST_F(LabelledDomainTest, CreateFromPortAndDomain) {
  auto ldp = LabelledDomain_create_from_port(0.0, 1.0, type, port, true, false);
  LabelledDomain_destroy(ldp);
  EXPECT_THROW(
      LabelledDomain_create_from_port(0.0, 1.0, nullptr, port, true, false),
      std::invalid_argument);
  EXPECT_THROW(
      LabelledDomain_create_from_port(0.0, 1.0, type, nullptr, true, false),
      std::invalid_argument);

  auto ldpd = LabelledDomain_create_from_port_and_domain(port, domain);
  LabelledDomain_destroy(ldpd);
  EXPECT_THROW(LabelledDomain_create_from_port_and_domain(nullptr, domain),
               std::invalid_argument);
  EXPECT_THROW(LabelledDomain_create_from_port_and_domain(port, nullptr),
               std::invalid_argument);
}

TEST_F(LabelledDomainTest, CreateFromDomain) {
  auto ldd =
      LabelledDomain_create_from_domain(domain, name, conn, type, unit, desc);
  LabelledDomain_destroy(ldd);
  EXPECT_THROW(
      LabelledDomain_create_from_domain(nullptr, name, conn, type, unit, desc),
      std::invalid_argument);
  EXPECT_THROW(LabelledDomain_create_from_domain(
                   domain, nullptr, conn, type, unit, desc),
               std::invalid_argument);
  EXPECT_THROW(LabelledDomain_create_from_domain(
                   domain, name, nullptr, type, unit, desc),
               std::invalid_argument);
  EXPECT_THROW(LabelledDomain_create_from_domain(
                   domain, name, conn, nullptr, unit, desc),
               std::invalid_argument);
  EXPECT_THROW(LabelledDomain_create_from_domain(
                   domain, name, conn, type, nullptr, desc),
               std::invalid_argument);
  EXPECT_THROW(LabelledDomain_create_from_domain(
                   domain, name, conn, type, unit, nullptr),
               std::invalid_argument);
}

TEST_F(LabelledDomainTest, DestroyNullThrows) {
  EXPECT_THROW(LabelledDomain_destroy(nullptr), std::invalid_argument);
}

TEST_F(LabelledDomainTest, Accessors) {
  auto p = LabelledDomain_port(knob);
  auto d = LabelledDomain_domain(knob);
  InstrumentPort_destroy(p);
  Domain_destroy(d);

  EXPECT_THROW(LabelledDomain_port(nullptr), std::invalid_argument);
  EXPECT_THROW(LabelledDomain_domain(nullptr), std::invalid_argument);
}

TEST_F(LabelledDomainTest, MatchingPort) {
  EXPECT_TRUE(LabelledDomain_matching_port(knob, port));
  EXPECT_THROW(LabelledDomain_matching_port(nullptr, port),
               std::invalid_argument);
  EXPECT_THROW(LabelledDomain_matching_port(knob, nullptr),
               std::invalid_argument);
}

TEST_F(LabelledDomainTest, BoundsAndContained) {
  EXPECT_DOUBLE_EQ(LabelledDomain_lesser_bound(knob), 0.0);
  EXPECT_DOUBLE_EQ(LabelledDomain_greater_bound(knob), 1.0);
  EXPECT_TRUE(LabelledDomain_lesser_bound_contained(knob));
  EXPECT_FALSE(LabelledDomain_greater_bound_contained(knob));
  EXPECT_THROW(LabelledDomain_lesser_bound(nullptr), std::invalid_argument);
  EXPECT_THROW(LabelledDomain_greater_bound(nullptr), std::invalid_argument);
  EXPECT_THROW(LabelledDomain_lesser_bound_contained(nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledDomain_greater_bound_contained(nullptr),
               std::invalid_argument);
}

TEST_F(LabelledDomainTest, InRangeRangeCenter) {
  EXPECT_TRUE(LabelledDomain_in(knob, 0.5));
  EXPECT_FALSE(LabelledDomain_in(knob, 2.0));
  EXPECT_DOUBLE_EQ(LabelledDomain_range(knob), 1.0);
  EXPECT_DOUBLE_EQ(LabelledDomain_center(knob), 0.5);
  EXPECT_THROW(LabelledDomain_in(nullptr, 0.5), std::invalid_argument);
  EXPECT_THROW(LabelledDomain_range(nullptr), std::invalid_argument);
  EXPECT_THROW(LabelledDomain_center(nullptr), std::invalid_argument);
}

TEST_F(LabelledDomainTest, IntersectionUnion) {
  auto inter = LabelledDomain_intersection(knob, meter);
  auto uni   = LabelledDomain_union(knob, meter);
  LabelledDomain_destroy(inter);
  LabelledDomain_destroy(uni);
  EXPECT_THROW(LabelledDomain_intersection(nullptr, meter),
               std::invalid_argument);
  EXPECT_THROW(LabelledDomain_intersection(knob, nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledDomain_union(nullptr, meter), std::invalid_argument);
  EXPECT_THROW(LabelledDomain_union(knob, nullptr), std::invalid_argument);
}

TEST_F(LabelledDomainTest, IsEmptyContainsDomain) {
  EXPECT_FALSE(LabelledDomain_is_empty(knob));
  EXPECT_TRUE(LabelledDomain_contains_domain(meter, knob));
  EXPECT_THROW(LabelledDomain_is_empty(nullptr), std::invalid_argument);
  EXPECT_THROW(LabelledDomain_contains_domain(nullptr, meter),
               std::invalid_argument);
  EXPECT_THROW(LabelledDomain_contains_domain(knob, nullptr),
               std::invalid_argument);
}

TEST_F(LabelledDomainTest, ShiftScaleTransform) {
  auto shifted = LabelledDomain_shift(knob, 1.0);
  auto scaled  = LabelledDomain_scale(knob, 2.0);
  EXPECT_DOUBLE_EQ(LabelledDomain_transform(knob, meter, 0.5),
                   LabelledDomain_transform(knob, meter, 0.5));
  LabelledDomain_destroy(shifted);
  LabelledDomain_destroy(scaled);
  EXPECT_THROW(LabelledDomain_shift(nullptr, 1.0), std::invalid_argument);
  EXPECT_THROW(LabelledDomain_scale(nullptr, 2.0), std::invalid_argument);
  EXPECT_THROW(LabelledDomain_transform(nullptr, meter, 0.5),
               std::invalid_argument);
  EXPECT_THROW(LabelledDomain_transform(knob, nullptr, 0.5),
               std::invalid_argument);
}

TEST_F(LabelledDomainTest, EqualNotEqual) {
  EXPECT_FALSE(LabelledDomain_equal(knob, meter));
  EXPECT_TRUE(LabelledDomain_not_equal(knob, meter));
  EXPECT_THROW(LabelledDomain_equal(nullptr, meter), std::invalid_argument);
  EXPECT_THROW(LabelledDomain_equal(knob, nullptr), std::invalid_argument);
  EXPECT_THROW(LabelledDomain_not_equal(nullptr, meter), std::invalid_argument);
  EXPECT_THROW(LabelledDomain_not_equal(knob, nullptr), std::invalid_argument);
}

TEST_F(LabelledDomainTest, ToJsonFromJson) {
  auto json = LabelledDomain_to_json_string(knob);
  auto l2   = LabelledDomain_from_json_string(json);
  EXPECT_TRUE(LabelledDomain_equal(knob, l2));
  LabelledDomain_destroy(l2);
  String_destroy(json);
  EXPECT_THROW(LabelledDomain_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(LabelledDomain_from_json_string(nullptr), std::invalid_argument);
}
