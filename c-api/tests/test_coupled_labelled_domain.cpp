#include <gtest/gtest.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/math/domains/CoupledLabelledDomain_c_api.h"
#include "falcon_core/math/domains/Domain_c_api.h"
#include "falcon_core/math/domains/LabelledDomain_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"

class CoupledLabelledDomainTest : public ::testing::Test {
 protected:
  void SetUp() override {
    name   = String_wrap("knob");
    type   = String_wrap("type");
    desc   = String_wrap("desc");
    unit   = SymbolUnit_create_volt();
    conn   = Connection_create_plunger_gate(String_wrap("A"));
    domain = Domain_create(0.0, 1.0, true, false);
    port   = InstrumentPort_create_port(name, conn, type, unit, desc);

    ldom = LabelledDomain_create_primitive_knob(
        name, 0.0, 1.0, conn, type, true, false, unit, desc);

    ldom_list = ListLabelledDomain_create_empty();
    ListLabelledDomain_push_back(ldom_list, ldom);

    cldom = CoupledLabelledDomain_create(ldom_list);
  }
  void TearDown() override {
    CoupledLabelledDomain_destroy(cldom);
    ListLabelledDomain_destroy(ldom_list);
    LabelledDomain_destroy(ldom);
    InstrumentPort_destroy(port);
    Domain_destroy(domain);
    Connection_destroy(conn);
    SymbolUnit_destroy(unit);
    String_destroy(name);
    String_destroy(type);
    String_destroy(desc);
  }
  StringHandle                name      = nullptr;
  StringHandle                type      = nullptr;
  StringHandle                desc      = nullptr;
  SymbolUnitHandle            unit      = nullptr;
  ConnectionHandle            conn      = nullptr;
  DomainHandle                domain    = nullptr;
  InstrumentPortHandle        port      = nullptr;
  LabelledDomainHandle        ldom      = nullptr;
  ListLabelledDomainHandle    ldom_list = nullptr;
  CoupledLabelledDomainHandle cldom     = nullptr;
};

TEST_F(CoupledLabelledDomainTest, CreateDestroy) {
  auto c = CoupledLabelledDomain_create(ldom_list);
  CoupledLabelledDomain_destroy(c);
  auto e = CoupledLabelledDomain_create_empty();
  CoupledLabelledDomain_destroy(e);
  EXPECT_THROW(CoupledLabelledDomain_create(nullptr), std::invalid_argument);
  EXPECT_THROW(CoupledLabelledDomain_destroy(nullptr), std::invalid_argument);
}

TEST_F(CoupledLabelledDomainTest, DomainsLabels) {
  auto domains = CoupledLabelledDomain_domains(cldom);
  EXPECT_EQ(ListLabelledDomain_size(domains), 1);
  ListLabelledDomain_destroy(domains);

  auto labels = CoupledLabelledDomain_labels(cldom);
  ListInstrumentPort_destroy(labels);

  EXPECT_THROW(CoupledLabelledDomain_domains(nullptr), std::invalid_argument);
  EXPECT_THROW(CoupledLabelledDomain_labels(nullptr), std::invalid_argument);
}

TEST_F(CoupledLabelledDomainTest, GetDomain) {
  auto d = CoupledLabelledDomain_get_domain(cldom, port);
  EXPECT_NE(d, nullptr);
  EXPECT_THROW(CoupledLabelledDomain_get_domain(nullptr, port),
               std::invalid_argument);
  EXPECT_THROW(CoupledLabelledDomain_get_domain(cldom, nullptr),
               std::invalid_argument);
}

TEST_F(CoupledLabelledDomainTest, Intersection) {
  auto c2    = CoupledLabelledDomain_create(ldom_list);
  auto inter = CoupledLabelledDomain_intersection(cldom, c2);
  CoupledLabelledDomain_destroy(inter);
  CoupledLabelledDomain_destroy(c2);
  EXPECT_THROW(CoupledLabelledDomain_intersection(nullptr, cldom),
               std::invalid_argument);
  EXPECT_THROW(CoupledLabelledDomain_intersection(cldom, nullptr),
               std::invalid_argument);
}

TEST_F(CoupledLabelledDomainTest, PushBackSizeEmptyEraseClear) {
  auto e = CoupledLabelledDomain_create_empty();
  CoupledLabelledDomain_push_back(e, ldom_list);
  EXPECT_EQ(CoupledLabelledDomain_size(e), 1);
  EXPECT_FALSE(CoupledLabelledDomain_empty(e));
  CoupledLabelledDomain_erase_at(e, 0);
  EXPECT_TRUE(CoupledLabelledDomain_empty(e));
  CoupledLabelledDomain_push_back(e, ldom_list);
  CoupledLabelledDomain_clear(e);
  EXPECT_TRUE(CoupledLabelledDomain_empty(e));
  CoupledLabelledDomain_destroy(e);

  EXPECT_THROW(CoupledLabelledDomain_push_back(nullptr, ldom_list),
               std::invalid_argument);
  EXPECT_THROW(CoupledLabelledDomain_push_back(cldom, nullptr),
               std::invalid_argument);
  EXPECT_THROW(CoupledLabelledDomain_size(nullptr), std::invalid_argument);
  EXPECT_THROW(CoupledLabelledDomain_empty(nullptr), std::invalid_argument);
  EXPECT_THROW(CoupledLabelledDomain_erase_at(nullptr, 0),
               std::invalid_argument);
  EXPECT_THROW(CoupledLabelledDomain_clear(nullptr), std::invalid_argument);
}

TEST_F(CoupledLabelledDomainTest, AtConstAtItems) {
  auto at  = CoupledLabelledDomain_at(cldom, 0);
  auto cat = CoupledLabelledDomain_const_at(cldom, 0);
  EXPECT_NE(at, nullptr);
  EXPECT_NE(cat, nullptr);
  auto items = CoupledLabelledDomain_items(cldom);
  EXPECT_EQ(ListLabelledDomain_size(items), 1);
  ListLabelledDomain_destroy(items);

  EXPECT_THROW(CoupledLabelledDomain_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(CoupledLabelledDomain_const_at(nullptr, 0),
               std::invalid_argument);
  EXPECT_THROW(CoupledLabelledDomain_items(nullptr), std::invalid_argument);
}

TEST_F(CoupledLabelledDomainTest, ContainsIndex) {
  auto e = CoupledLabelledDomain_create_empty();
  CoupledLabelledDomain_push_back(e, ldom_list);
  EXPECT_TRUE(CoupledLabelledDomain_contains(e, ldom_list));
  EXPECT_EQ(CoupledLabelledDomain_index(e, ldom_list), 0);
  CoupledLabelledDomain_destroy(e);

  EXPECT_THROW(CoupledLabelledDomain_contains(nullptr, ldom_list),
               std::invalid_argument);
  EXPECT_THROW(CoupledLabelledDomain_contains(cldom, nullptr),
               std::invalid_argument);
  EXPECT_THROW(CoupledLabelledDomain_index(nullptr, ldom_list),
               std::invalid_argument);
  EXPECT_THROW(CoupledLabelledDomain_index(cldom, nullptr),
               std::invalid_argument);
}

TEST_F(CoupledLabelledDomainTest, Equality) {
  auto c2 = CoupledLabelledDomain_create(ldom_list);
  EXPECT_TRUE(CoupledLabelledDomain_equal(cldom, c2));
  EXPECT_FALSE(CoupledLabelledDomain_not_equal(cldom, c2));
  CoupledLabelledDomain_destroy(c2);
  EXPECT_THROW(CoupledLabelledDomain_equal(nullptr, cldom),
               std::invalid_argument);
  EXPECT_THROW(CoupledLabelledDomain_equal(cldom, nullptr),
               std::invalid_argument);
  EXPECT_THROW(CoupledLabelledDomain_not_equal(nullptr, cldom),
               std::invalid_argument);
  EXPECT_THROW(CoupledLabelledDomain_not_equal(cldom, nullptr),
               std::invalid_argument);
}

TEST_F(CoupledLabelledDomainTest, ToJsonFromJson) {
  auto json = CoupledLabelledDomain_to_json_string(cldom);
  auto c2   = CoupledLabelledDomain_from_json_string(json);
  EXPECT_TRUE(CoupledLabelledDomain_equal(cldom, c2));
  CoupledLabelledDomain_destroy(c2);
  String_destroy(json);
  EXPECT_THROW(CoupledLabelledDomain_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(CoupledLabelledDomain_from_json_string(nullptr),
               std::invalid_argument);
}
