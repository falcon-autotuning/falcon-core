#include <gtest/gtest.h>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/ListPortTransform_c_api.h"
#include "falcon_core/instrument_interfaces/Waveform_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentTypes_c_api.h"
#include "falcon_core/math/discrete_spaces/Discretizer_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"
class WaveformTest : public ::testing::Test {
 protected:
  void SetUp() override {
    domain       = Domain_create(0, 1.0, true, true);
    default_name = String_wrap("A");
    port =
        InstrumentPort_create_knob(default_name,
                                   Connection_create_barrier_gate(default_name),
                                   InstrumentTypes_voltmeter(),
                                   SymbolUnit_create_volt(),
                                   String_wrap(""));
    getter = InstrumentPort_create_meter(
        String_wrap("ohm1"),
        Connection_create_ohmic(String_wrap("ohm1")),
        InstrumentTypes_amnmeter(),
        SymbolUnit_create_ampere(),
        String_wrap(""));
    domain_list = ListLabelledDomain_create_empty();
    ListLabelledDomain_push_back(
        domain_list, LabelledDomain_create_from_port_and_domain(port, domain));
    labelled_domain = CoupledLabelledDomain_create(domain_list);
    axes            = AxesCoupledLabelledDomain_create_empty();
    AxesCoupledLabelledDomain_push_back(
        axes, CoupledLabelledDomain_create(labelled_domain));
    increasing = AxesMapStringBool_create_empty();
    map        = MapStringBool_create_empty();
    MapStringBool_insert(map, default_name, true);
    AxesMapStringBool_push_back(increasing, map);
    discretizers = AxesDiscretizer_create_empty();
    AxesDiscretizer_push_back(discretizers,
                              Discretizer_create_cartesian_discretizer(0.1));
    unit_space = UnitSpace_create(discretizers, domain);
    space      = DiscreteSpace_create(unit_space, axes, increasing);
    transforms = ListPortTransform_create_empty();
    labels     = ListString_create_empty();
    ListString_push_back(labels, String_wrap("x"));
    analytic = AnalyticFunction_create(labels, String_wrap("2x[0]+1"));
    pt       = PortTransform_create(port, analytic);
    ListPortTransform_push_back(transforms, pt);

    // For cartesianwaveform
    divisions = AxesInt_create_empty();
    AxesInt_push_back(divisions, 2);
  }
  void TearDown() override {
    MapStringBool_destroy(map);
    String_destroy(default_name);
    ListLabelledDomain_destroy(domain_list);
    CoupledLabelledDomain_destroy(labelled_domain);
    DiscreteSpace_destroy(space);
    UnitSpace_destroy(unit_space);
    AxesDiscretizer_destroy(discretizers);
    ListPortTransform_destroy(transforms);
    PortTransform_destroy(pt);
    InstrumentPort_destroy(port);
    ListString_destroy(labels);
    AnalyticFunction_destroy(analytic);
    AxesInt_destroy(divisions);
    AxesCoupledLabelledDomain_destroy(axes);
    AxesMapStringBool_destroy(increasing);
    Domain_destroy(domain);
    InstrumentPort_destroy(getter);
  }
  MapStringBoolHandle             map;
  InstrumentPortHandle            getter;
  StringHandle                    default_name;
  ListLabelledDomainHandle        domain_list;
  CoupledLabelledDomainHandle     labelled_domain;
  DiscreteSpaceHandle             space;
  UnitSpaceHandle                 unit_space;
  AxesDiscretizerHandle           discretizers;
  ListPortTransformHandle         transforms;
  PortTransformHandle             pt;
  InstrumentPortHandle            port;
  ListStringHandle                labels;
  AnalyticFunctionHandle          analytic;
  AxesIntHandle                   divisions;
  AxesCoupledLabelledDomainHandle axes;
  AxesMapStringBoolHandle         increasing;
  DomainHandle                    domain;
};

TEST_F(WaveformTest, CreateDestroy) {
  auto w = Waveform_create(space, transforms);
  Waveform_destroy(w);

  set_last_error(0, nullptr);
  Waveform_create(nullptr, transforms);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_create(space, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  auto w2 = Waveform_create_cartesian_waveform(
      divisions, axes, increasing, transforms, domain);
  Waveform_destroy(w2);

  set_last_error(0, nullptr);
  Waveform_create_cartesian_waveform(
      nullptr, axes, increasing, transforms, domain);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_create_cartesian_waveform(
      divisions, nullptr, increasing, transforms, domain);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_create_cartesian_waveform(
      divisions, axes, nullptr, transforms, domain);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_create_cartesian_waveform(
      divisions, axes, increasing, nullptr, domain);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_create_cartesian_waveform(
      divisions, axes, increasing, transforms, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  auto w3 = Waveform_create_cartesian_identity_waveform(
      divisions, axes, increasing, domain);
  Waveform_destroy(w3);

  set_last_error(0, nullptr);
  Waveform_create_cartesian_identity_waveform(
      nullptr, axes, increasing, domain);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_create_cartesian_identity_waveform(
      divisions, nullptr, increasing, domain);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_create_cartesian_identity_waveform(divisions, axes, nullptr, domain);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(WaveformTest, Accessors) {
  auto w = Waveform_create(space, transforms);

  auto s = Waveform_space(w);
  EXPECT_NE(s, nullptr);

  auto t = Waveform_transforms(w);
  EXPECT_NE(t, nullptr);
  ListPortTransform_destroy(t);

  EXPECT_EQ(Waveform_size(w), 1);
  EXPECT_FALSE(Waveform_empty(w));

  auto item = Waveform_at(w, 0);
  EXPECT_NE(item, nullptr);
  PortTransform_destroy(item);

  auto items = Waveform_items(w);
  EXPECT_NE(items, nullptr);
  ListPortTransform_destroy(items);

  set_last_error(0, nullptr);
  Waveform_space(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_transforms(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_items(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  Waveform_destroy(w);
}

TEST_F(WaveformTest, Mutators) {
  auto w = Waveform_create(space, transforms);

  auto pt2 = PortTransform_create_constant_transform(port, 5.0);
  Waveform_push_back(w, pt2);
  EXPECT_EQ(Waveform_size(w), 2);

  Waveform_erase_at(w, 0);
  EXPECT_EQ(Waveform_size(w), 1);

  Waveform_clear(w);
  EXPECT_EQ(Waveform_size(w), 0);

  set_last_error(0, nullptr);
  Waveform_push_back(nullptr, pt2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_push_back(w, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  PortTransform_destroy(pt2);
  Waveform_destroy(w);
}

TEST_F(WaveformTest, ContainsIndex) {
  auto w = Waveform_create(space, transforms);

  EXPECT_TRUE(Waveform_contains(w, pt));
  EXPECT_EQ(Waveform_index(w, pt), 0);

  set_last_error(0, nullptr);
  Waveform_contains(nullptr, pt);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_contains(w, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_contains(nullptr, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  Waveform_index(nullptr, pt);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_index(w, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_index(nullptr, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  Waveform_destroy(w);
}

TEST_F(WaveformTest, EqualityIntersection) {
  auto w1 = Waveform_create(space, transforms);
  auto w2 = Waveform_create(space, transforms);

  EXPECT_TRUE(Waveform_equal(w1, w2));
  EXPECT_FALSE(Waveform_not_equal(w1, w2));

  auto inter = Waveform_intersection(w1, w2);
  EXPECT_NE(inter, nullptr);
  Waveform_destroy(inter);

  set_last_error(0, nullptr);
  Waveform_equal(nullptr, w2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_equal(w1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_equal(nullptr, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  Waveform_not_equal(nullptr, w2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_not_equal(w1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_not_equal(nullptr, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  Waveform_intersection(nullptr, w2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_intersection(w1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_intersection(nullptr, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  Waveform_destroy(w1);
  Waveform_destroy(w2);
}

TEST_F(WaveformTest, ToJsonFromJson) {
  auto w    = Waveform_create(space, transforms);
  auto json = Waveform_to_json_string(w);
  EXPECT_NE(json, nullptr);

  auto w2 = Waveform_from_json_string(json);
  EXPECT_TRUE(Waveform_equal(w, w2));

  set_last_error(0, nullptr);
  Waveform_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  Waveform_destroy(w2);
  String_destroy(json);
  Waveform_destroy(w);
}

TEST_F(WaveformTest, CartesianWaveformVariants) {
  AxesIntHandle divisions2D = AxesInt_create_empty();
  AxesInt_push_back(divisions2D, 2);
  AxesInt_push_back(divisions2D, 2);
  AxesCoupledLabelledDomainHandle axes2D =
      AxesCoupledLabelledDomain_create_empty();
  AxesCoupledLabelledDomain_push_back(
      axes2D, CoupledLabelledDomain_create(labelled_domain));
  StringHandle         other_name = String_wrap("B");
  InstrumentPortHandle other_port =
      InstrumentPort_create_knob(other_name,
                                 Connection_create_barrier_gate(default_name),
                                 InstrumentTypes_voltmeter(),
                                 SymbolUnit_create_volt(),
                                 String_wrap(""));
  ListLabelledDomainHandle other_domain_list =
      ListLabelledDomain_create_empty();
  ListLabelledDomain_push_back(
      other_domain_list,
      LabelledDomain_create_from_port_and_domain(other_port, domain));
  CoupledLabelledDomainHandle other_labelled_domain =
      CoupledLabelledDomain_create(other_domain_list);
  AxesCoupledLabelledDomain_push_back(
      axes2D, CoupledLabelledDomain_create(other_labelled_domain));
  AxesMapStringBoolHandle increasing2D = AxesMapStringBool_create_empty();
  AxesMapStringBool_push_back(increasing2D, map);
  MapStringBoolHandle other_map = MapStringBool_create_empty();
  MapStringBool_insert(other_map, other_name, true);
  AxesMapStringBool_push_back(increasing2D, other_map);
  // 2D waveform creation/destruction
  auto w2d = Waveform_create_cartesian_waveform_2D(
      divisions2D, axes2D, increasing2D, transforms, domain);
  Waveform_destroy(w2d);

  set_last_error(0, nullptr);
  Waveform_create_cartesian_waveform_2D(
      nullptr, axes2D, increasing2D, transforms, domain);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_create_cartesian_waveform_2D(
      divisions2D, nullptr, increasing2D, transforms, domain);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_create_cartesian_waveform_2D(
      divisions2D, axes2D, nullptr, transforms, domain);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_create_cartesian_waveform_2D(
      divisions2D, axes2D, increasing2D, nullptr, domain);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_create_cartesian_waveform_2D(
      divisions2D, axes2D, increasing2D, transforms, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  // 2D identity waveform creation/destruction
  auto w2d_id = Waveform_create_cartesian_identity_waveform_2D(
      divisions2D, axes2D, increasing2D, domain);
  Waveform_destroy(w2d_id);

  set_last_error(0, nullptr);
  Waveform_create_cartesian_identity_waveform_2D(
      nullptr, axes2D, increasing2D, domain);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_create_cartesian_identity_waveform_2D(
      divisions2D, nullptr, increasing2D, domain);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_create_cartesian_identity_waveform_2D(
      divisions2D, axes2D, nullptr, domain);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_create_cartesian_identity_waveform_2D(
      divisions2D, axes2D, increasing2D, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  // 1D waveform creation/destruction
  auto w1d = Waveform_create_cartesian_waveform_1D(
      2, labelled_domain, map, transforms, domain);
  Waveform_destroy(w1d);

  set_last_error(0, nullptr);
  Waveform_create_cartesian_waveform_1D(2, nullptr, map, transforms, domain);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_create_cartesian_waveform_1D(
      2, labelled_domain, nullptr, transforms, domain);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_create_cartesian_waveform_1D(
      2, labelled_domain, map, nullptr, domain);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_create_cartesian_waveform_1D(
      2, labelled_domain, map, transforms, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  // 1D identity waveform creation/destruction
  auto w1d_id = Waveform_create_cartesian_identity_waveform_1D(
      2, labelled_domain, map, domain);
  Waveform_destroy(w1d_id);

  set_last_error(0, nullptr);
  Waveform_create_cartesian_identity_waveform_1D(2, nullptr, map, domain);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_create_cartesian_identity_waveform_1D(
      2, labelled_domain, nullptr, domain);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Waveform_create_cartesian_identity_waveform_1D(
      2, labelled_domain, map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
