#include <gtest/gtest.h>

#include "falcon_core/instrument_interfaces/Waveform_c_api.h"
#include "falcon_core/math/discrete_spaces/Discretizer_c_api.h"
class WaveformTest : public ::testing::Test {
 protected:
  void SetUp() override {
    default_name = String_wrap("voltage_meter1");
    expression   = String_wrap("2x[0]+1");

    domain      = Domain_create(0.0, 1.0);
    domain_list = ListLabelledDomain_create_empty();
    ListLabelledDomain_push_back(
        domain_list,
        LabelledDomain_create_from_domain(
            domain,
            default_name,
            Connection_create_barrier_gate(default_name),
            InstrumentTypes_voltmeter()));
    labelled_domain = CoupledLabelledDomain_create(domain_list);
    axes            = AxesCoupledLabelledDomain_create_empty();
    AxesCoupledLabelledDomain_push_back(axes, labelled_domain);
    map = MapStringBool_create_empty();
    MapStringBool_insert(map, default_name, true);
    increasing = AxesMapStringBool_create_empty();
    AxesMapStringBool_push_back(increasing, map);
    discretizers = AxesDiscretizer_create_empty();
    AxesDiscretizer_push_back(discretizers,
                              Discretizer_create_cartesian_discretizer(0.1));
    unit_space = UnitSpace_create(discretizers, domain);
    space      = DiscreteSpace_create(unit_space, axes, increasing);
    labels     = ListString_create_empty();
    ListString_push_back(labels, default_name);
    analytic = AnalyticFunction_create(labels, expression);
    port =
        InstrumentPort_create_knob(default_name,
                                   Connection_create_barrier_gate(default_name),
                                   InstrumentTypes_voltmeter());
    pt         = PortTransform_create(port, analytic);
    transforms = ListPortTransform_create_empty();
    ListPortTransform_push_back(transforms, pt);

    // For cartesianwaveform
    divisions = AxesInt_create_empty();
    AxesInt_push_back(divisions, 2);
  }
  void TearDown() override {
    MapStringBool_destroy(map);
    String_destroy(expression);
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
  }
  MapStringBoolHandle             map;
  StringHandle                    expression;
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

  EXPECT_THROW(Waveform_create(nullptr, transforms), std::invalid_argument);
  EXPECT_THROW(Waveform_create(space, nullptr), std::invalid_argument);
  EXPECT_THROW(Waveform_destroy(nullptr), std::invalid_argument);

  auto w2 = Waveform_create_cartesianwaveform(
      divisions, axes, increasing, transforms, domain);
  Waveform_destroy(w2);

  EXPECT_THROW(Waveform_create_cartesianwaveform(
                   nullptr, axes, increasing, transforms, domain),
               std::invalid_argument);
  EXPECT_THROW(Waveform_create_cartesianwaveform(
                   divisions, nullptr, increasing, transforms, domain),
               std::invalid_argument);
  EXPECT_THROW(Waveform_create_cartesianwaveform(
                   divisions, axes, nullptr, transforms, domain),
               std::invalid_argument);
  EXPECT_THROW(Waveform_create_cartesianwaveform(
                   divisions, axes, increasing, nullptr, domain),
               std::invalid_argument);

  auto w3 = Waveform_create_cartesianidentitywaveform(
      divisions, axes, increasing, domain);
  Waveform_destroy(w3);

  EXPECT_THROW(Waveform_create_cartesianidentitywaveform(
                   nullptr, axes, increasing, domain),
               std::invalid_argument);
  EXPECT_THROW(Waveform_create_cartesianidentitywaveform(
                   divisions, nullptr, increasing, domain),
               std::invalid_argument);
  EXPECT_THROW(Waveform_create_cartesianidentitywaveform(
                   divisions, axes, nullptr, domain),
               std::invalid_argument);
}

TEST_F(WaveformTest, Accessors) {
  auto w = Waveform_create(space, transforms);

  auto s = Waveform_space(w);
  EXPECT_NE(s, nullptr);
  DiscreteSpace_destroy(s);

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

  EXPECT_THROW(Waveform_space(nullptr), std::invalid_argument);
  EXPECT_THROW(Waveform_transforms(nullptr), std::invalid_argument);
  EXPECT_THROW(Waveform_size(nullptr), std::invalid_argument);
  EXPECT_THROW(Waveform_empty(nullptr), std::invalid_argument);
  EXPECT_THROW(Waveform_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(Waveform_items(nullptr), std::invalid_argument);

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

  EXPECT_THROW(Waveform_push_back(nullptr, pt2), std::invalid_argument);
  EXPECT_THROW(Waveform_push_back(w, nullptr), std::invalid_argument);
  EXPECT_THROW(Waveform_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(Waveform_clear(nullptr), std::invalid_argument);

  PortTransform_destroy(pt2);
  Waveform_destroy(w);
}

TEST_F(WaveformTest, ContainsIndex) {
  auto w = Waveform_create(space, transforms);

  EXPECT_TRUE(Waveform_contains(w, pt));
  EXPECT_EQ(Waveform_index(w, pt), 0);

  EXPECT_THROW(Waveform_contains(nullptr, pt), std::invalid_argument);
  EXPECT_THROW(Waveform_contains(w, nullptr), std::invalid_argument);
  EXPECT_THROW(Waveform_contains(nullptr, nullptr), std::invalid_argument);

  EXPECT_THROW(Waveform_index(nullptr, pt), std::invalid_argument);
  EXPECT_THROW(Waveform_index(w, nullptr), std::invalid_argument);
  EXPECT_THROW(Waveform_index(nullptr, nullptr), std::invalid_argument);

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

  EXPECT_THROW(Waveform_equal(nullptr, w2), std::invalid_argument);
  EXPECT_THROW(Waveform_equal(w1, nullptr), std::invalid_argument);
  EXPECT_THROW(Waveform_equal(nullptr, nullptr), std::invalid_argument);

  EXPECT_THROW(Waveform_not_equal(nullptr, w2), std::invalid_argument);
  EXPECT_THROW(Waveform_not_equal(w1, nullptr), std::invalid_argument);
  EXPECT_THROW(Waveform_not_equal(nullptr, nullptr), std::invalid_argument);

  EXPECT_THROW(Waveform_intersection(nullptr, w2), std::invalid_argument);
  EXPECT_THROW(Waveform_intersection(w1, nullptr), std::invalid_argument);
  EXPECT_THROW(Waveform_intersection(nullptr, nullptr), std::invalid_argument);

  Waveform_destroy(w1);
  Waveform_destroy(w2);
}

TEST_F(WaveformTest, ToJsonFromJson) {
  auto w    = Waveform_create(space, transforms);
  auto json = Waveform_to_json_string(w);
  EXPECT_NE(json, nullptr);

  auto w2 = Waveform_from_json_string(json);
  EXPECT_TRUE(Waveform_equal(w, w2));

  EXPECT_THROW(Waveform_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(Waveform_from_json_string(nullptr), std::invalid_argument);

  Waveform_destroy(w2);
  String_destroy(json);
  Waveform_destroy(w);
}
