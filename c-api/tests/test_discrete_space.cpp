#include <gtest/gtest.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/math/UnitSpace_c_api.h"
#include "falcon_core/math/discrete_spaces/DiscreteSpace_c_api.h"
#include "falcon_core/math/discrete_spaces/Discretizer_c_api.h"
#include "falcon_core/math/domains/CoupledLabelledDomain_c_api.h"
#include "falcon_core/math/domains/Domain_c_api.h"
#include "falcon_core/math/domains/LabelledDomain_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"

class DiscreteSpaceTest : public ::testing::Test {
 protected:
  void SetUp() override {
    domain           = Domain_create(0.0, 1.0, true, false);
    discretizer      = Discretizer_create_cartesian_discretizer(0.1);
    axes_discretizer = AxesDiscretizer_create_empty();
    AxesDiscretizer_push_back(axes_discretizer, discretizer);
    unitspace = UnitSpace_create(axes_discretizer, domain);

    name = String_wrap("knob");
    type = String_wrap("type");
    desc = String_wrap("desc");
    unit = SymbolUnit_create_volt();
    conn = Connection_create_plunger_gate(String_wrap("A"));
    port = InstrumentPort_create_knob(name, conn, type, unit, desc);

    ldom = LabelledDomain_create_primitive_knob(
        name, 0.0, 1.0, conn, type, true, false, unit, desc);
    ldom_list = ListLabelledDomain_create_empty();
    ListLabelledDomain_push_back(ldom_list, ldom);
    cldom = CoupledLabelledDomain_create(ldom_list);

    axes_cldom = AxesCoupledLabelledDomain_create_empty();
    AxesCoupledLabelledDomain_push_back(axes_cldom, cldom);

    map_str_bool = MapStringBool_create_empty();
    MapStringBool_insert(map_str_bool, Connection_name(conn), true);

    axes_map_str_bool = AxesMapStringBool_create_empty();
    AxesMapStringBool_push_back(axes_map_str_bool, map_str_bool);

    axes_int = AxesInt_create_empty();
    AxesInt_push_back(axes_int, 1);

    ds = DiscreteSpace_create(unitspace, axes_cldom, axes_map_str_bool);
  }
  void TearDown() override {
    DiscreteSpace_destroy(ds);
    AxesInt_destroy(axes_int);
    AxesMapStringBool_destroy(axes_map_str_bool);
    MapStringBool_destroy(map_str_bool);
    AxesCoupledLabelledDomain_destroy(axes_cldom);
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
    UnitSpace_destroy(unitspace);
    AxesDiscretizer_destroy(axes_discretizer);
    Discretizer_destroy(discretizer);
  }
  DomainHandle                    domain            = nullptr;
  DiscretizerHandle               discretizer       = nullptr;
  AxesDiscretizerHandle           axes_discretizer  = nullptr;
  UnitSpaceHandle                 unitspace         = nullptr;
  StringHandle                    name              = nullptr;
  StringHandle                    type              = nullptr;
  StringHandle                    desc              = nullptr;
  SymbolUnitHandle                unit              = nullptr;
  ConnectionHandle                conn              = nullptr;
  InstrumentPortHandle            port              = nullptr;
  LabelledDomainHandle            ldom              = nullptr;
  ListLabelledDomainHandle        ldom_list         = nullptr;
  CoupledLabelledDomainHandle     cldom             = nullptr;
  AxesCoupledLabelledDomainHandle axes_cldom        = nullptr;
  MapStringBoolHandle             map_str_bool      = nullptr;
  AxesMapStringBoolHandle         axes_map_str_bool = nullptr;
  AxesIntHandle                   axes_int          = nullptr;
  DiscreteSpaceHandle             ds                = nullptr;
};

TEST_F(DiscreteSpaceTest, CreateDestroy) {
  auto d = DiscreteSpace_create(unitspace, axes_cldom, axes_map_str_bool);
  DiscreteSpace_destroy(d);
  EXPECT_THROW(DiscreteSpace_create(nullptr, axes_cldom, axes_map_str_bool),
               std::invalid_argument);
  EXPECT_THROW(DiscreteSpace_create(unitspace, nullptr, axes_map_str_bool),
               std::invalid_argument);
  EXPECT_THROW(DiscreteSpace_create(unitspace, axes_cldom, nullptr),
               std::invalid_argument);
  EXPECT_THROW(DiscreteSpace_destroy(nullptr), std::invalid_argument);
}

TEST_F(DiscreteSpaceTest, CreateCartesian) {
  auto d = DiscreteSpace_create_cartesiandiscretespace(
      axes_int, axes_cldom, axes_map_str_bool, domain);
  DiscreteSpace_destroy(d);
  EXPECT_THROW(DiscreteSpace_create_cartesiandiscretespace(
                   nullptr, axes_cldom, axes_map_str_bool, domain),
               std::invalid_argument);
  EXPECT_THROW(DiscreteSpace_create_cartesiandiscretespace(
                   axes_int, nullptr, axes_map_str_bool, domain),
               std::invalid_argument);
  EXPECT_THROW(DiscreteSpace_create_cartesiandiscretespace(
                   axes_int, axes_cldom, nullptr, domain),
               std::invalid_argument);
}

TEST_F(DiscreteSpaceTest, CreateCartesian1D) {
  auto d = DiscreteSpace_create_cartesiandiscretespace1D(
      1, cldom, map_str_bool, domain);
  DiscreteSpace_destroy(d);
  EXPECT_THROW(DiscreteSpace_create_cartesiandiscretespace1D(
                   1, nullptr, map_str_bool, domain),
               std::invalid_argument);
  EXPECT_THROW(
      DiscreteSpace_create_cartesiandiscretespace1D(1, cldom, nullptr, domain),
      std::invalid_argument);
  EXPECT_THROW(DiscreteSpace_create_cartesiandiscretespace1D(
                   1, cldom, map_str_bool, nullptr),
               std::invalid_argument);
}

TEST_F(DiscreteSpaceTest, Accessors) {
  auto us    = DiscreteSpace_space(ds);
  auto axes  = DiscreteSpace_axes(ds);
  auto inc   = DiscreteSpace_increasing(ds);
  auto knobs = DiscreteSpace_knobs(ds);
  UnitSpace_destroy(us);
  AxesCoupledLabelledDomain_destroy(axes);
  AxesMapStringBool_destroy(inc);
  Ports_destroy(knobs);

  EXPECT_THROW(DiscreteSpace_space(nullptr), std::invalid_argument);
  EXPECT_THROW(DiscreteSpace_axes(nullptr), std::invalid_argument);
  EXPECT_THROW(DiscreteSpace_increasing(nullptr), std::invalid_argument);
  EXPECT_THROW(DiscreteSpace_knobs(nullptr), std::invalid_argument);
}

TEST_F(DiscreteSpaceTest, Validation) {
  DiscreteSpace_validate_unit_space_dimensionality_matches_knobs(ds);
  DiscreteSpace_validate_knob_uniqueness(ds);
  EXPECT_THROW(
      DiscreteSpace_validate_unit_space_dimensionality_matches_knobs(nullptr),
      std::invalid_argument);
  EXPECT_THROW(DiscreteSpace_validate_knob_uniqueness(nullptr),
               std::invalid_argument);
}

TEST_F(DiscreteSpaceTest, GetAxisDomainProjection) {
  EXPECT_GE(DiscreteSpace_get_axis(ds, port), 0);
  auto dom = DiscreteSpace_get_domain(ds, port);
  Domain_destroy(dom);

  AxesInstrumentPortHandle aip = AxesInstrumentPort_create_empty();
  AxesInstrumentPort_push_back(aip, port);
  auto proj = DiscreteSpace_get_projection(ds, aip);
  AxesLabelledControlArray_destroy(proj);
  AxesInstrumentPort_destroy(aip);

  EXPECT_THROW(DiscreteSpace_get_axis(nullptr, port), std::invalid_argument);
  EXPECT_THROW(DiscreteSpace_get_axis(ds, nullptr), std::invalid_argument);
  EXPECT_THROW(DiscreteSpace_get_domain(nullptr, port), std::invalid_argument);
  EXPECT_THROW(DiscreteSpace_get_domain(ds, nullptr), std::invalid_argument);
  EXPECT_THROW(DiscreteSpace_get_projection(nullptr, aip),
               std::invalid_argument);
  EXPECT_THROW(DiscreteSpace_get_projection(ds, nullptr),
               std::invalid_argument);
}

TEST_F(DiscreteSpaceTest, Equality) {
  auto d2 = DiscreteSpace_create(unitspace, axes_cldom, axes_map_str_bool);
  EXPECT_TRUE(DiscreteSpace_equal(ds, d2));
  EXPECT_FALSE(DiscreteSpace_not_equal(ds, d2));
  DiscreteSpace_destroy(d2);
  EXPECT_THROW(DiscreteSpace_equal(nullptr, ds), std::invalid_argument);
  EXPECT_THROW(DiscreteSpace_equal(ds, nullptr), std::invalid_argument);
  EXPECT_THROW(DiscreteSpace_not_equal(nullptr, ds), std::invalid_argument);
  EXPECT_THROW(DiscreteSpace_not_equal(ds, nullptr), std::invalid_argument);
}

TEST_F(DiscreteSpaceTest, ToJsonFromJson) {
  auto json = DiscreteSpace_to_json_string(ds);
  auto d2   = DiscreteSpace_from_json_string(json);
  EXPECT_TRUE(DiscreteSpace_equal(ds, d2));
  DiscreteSpace_destroy(d2);
  String_destroy(json);
  EXPECT_THROW(DiscreteSpace_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(DiscreteSpace_from_json_string(nullptr), std::invalid_argument);
}
