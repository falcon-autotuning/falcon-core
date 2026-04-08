#include <gtest/gtest.h>

#include "falcon-core/communications/messages/MeasurementRequest_c_api.h"
#include "falcon-core/generic/ErrorHandling_c_api.h"
#include "falcon-core/generic/ListPortTransform_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/instrument_interfaces/Waveform_c_api.h"
#include "falcon-core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon-core/instrument_interfaces/names/InstrumentTypes_c_api.h"
#include "falcon-core/instrument_interfaces/names/Ports_c_api.h"
#include "falcon-core/instrument_interfaces/port_transforms/PortTransform_c_api.h"
#include "falcon-core/math/discrete_spaces/DiscreteSpace_c_api.h"
#include "falcon-core/math/domains/LabelledDomain_c_api.h"
#include "falcon-core/physics/units/SymbolUnit_c_api.h"

class MeasurementRequestTest : public ::testing::Test {
 protected:
  void SetUp() override {
    msg          = String_wrap("msg");
    name         = String_wrap("measurement");
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

    waveform  = Waveform_create(space, transforms);
    waveforms = ListWaveform_create_empty();
    ListWaveform_push_back(waveforms, waveform);

    getters = Ports_create_empty();
    Ports_push_back(getters, getter);

    meter_transforms = MapInstrumentPortPortTransform_create_empty();
    MapInstrumentPortPortTransform_insert(meter_transforms, port, pt);

    time_domain = LabelledDomain_create_from_port(
        0.0, 1.0, InstrumentPort_create_execution_clock(), true, true);

    req = MeasurementRequest_create(
        msg, name, waveforms, getters, meter_transforms, time_domain);
    req2 = MeasurementRequest_create(String_wrap("other"),
                                     name,
                                     waveforms,
                                     getters,
                                     meter_transforms,
                                     time_domain);
  }
  void TearDown() override {
    MeasurementRequest_destroy(req);
    MeasurementRequest_destroy(req2);
    String_destroy(msg);
    String_destroy(name);
    Waveform_destroy(waveform);
    ListWaveform_destroy(waveforms);
    InstrumentPort_destroy(port);
    Ports_destroy(getters);
    PortTransform_destroy(pt);
    ListPortTransform_destroy(transforms);
    MapInstrumentPortPortTransform_destroy(meter_transforms);
    LabelledDomain_destroy(time_domain);

    MapStringBool_destroy(map);
    String_destroy(default_name);
    ListLabelledDomain_destroy(domain_list);
    CoupledLabelledDomain_destroy(labelled_domain);
    DiscreteSpace_destroy(space);
    UnitSpace_destroy(unit_space);
    AxesDiscretizer_destroy(discretizers);
    ListString_destroy(labels);
    AnalyticFunction_destroy(analytic);
    AxesCoupledLabelledDomain_destroy(axes);
    AxesMapStringBool_destroy(increasing);
    Domain_destroy(domain);
    InstrumentPort_destroy(getter);
  }
  StringHandle                         msg;
  InstrumentPortHandle                 getter;
  StringHandle                         name;
  WaveformHandle                       waveform;
  ListWaveformHandle                   waveforms;
  InstrumentPortHandle                 port;
  PortsHandle                          getters;
  PortTransformHandle                  pt;
  ListPortTransformHandle              transforms;
  MapInstrumentPortPortTransformHandle meter_transforms;
  LabelledDomainHandle                 time_domain;
  MeasurementRequestHandle             req;
  MeasurementRequestHandle             req2;
  MapStringBoolHandle                  map;
  StringHandle                         default_name;
  ListLabelledDomainHandle             domain_list;
  CoupledLabelledDomainHandle          labelled_domain;
  DiscreteSpaceHandle                  space;
  UnitSpaceHandle                      unit_space;
  AxesDiscretizerHandle                discretizers;
  ListStringHandle                     labels;
  AnalyticFunctionHandle               analytic;
  AxesCoupledLabelledDomainHandle      axes;
  AxesMapStringBoolHandle              increasing;
  DomainHandle                         domain;
};

TEST_F(MeasurementRequestTest, CreateDestroy) {
  auto r = MeasurementRequest_create(
      msg, name, waveforms, getters, meter_transforms, time_domain);
  MeasurementRequest_destroy(r);
  set_last_error(0, nullptr);
  MeasurementRequest_create(
      nullptr, name, waveforms, getters, meter_transforms, time_domain);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasurementRequest_create(
      msg, nullptr, waveforms, getters, meter_transforms, time_domain);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasurementRequest_create(
      msg, name, nullptr, getters, meter_transforms, time_domain);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasurementRequest_create(
      msg, name, waveforms, nullptr, meter_transforms, time_domain);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasurementRequest_create(
      msg, name, waveforms, getters, nullptr, time_domain);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasurementRequest_create(
      msg, name, waveforms, getters, meter_transforms, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasurementRequest_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MeasurementRequestTest, Accessors) {
  auto m = MeasurementRequest_message(req);
  EXPECT_STREQ(m->raw, "msg");
  String_destroy(m);

  auto n = MeasurementRequest_measurement_name(req);
  EXPECT_STREQ(n->raw, "measurement");
  String_destroy(n);

  auto w = MeasurementRequest_waveforms(req);
  EXPECT_EQ(ListWaveform_size(w), 1);
  ListWaveform_destroy(w);

  auto g = MeasurementRequest_getters(req);
  EXPECT_EQ(Ports_size(g), 1);
  Ports_destroy(g);

  auto mt = MeasurementRequest_meter_transforms(req);
  EXPECT_EQ(MapInstrumentPortPortTransform_size(mt), 1);
  MapInstrumentPortPortTransform_destroy(mt);

  auto td = MeasurementRequest_time_domain(req);
  EXPECT_STREQ(InstrumentPort_instrument_type(LabelledDomain_port(td))->raw,
               "clock");
  LabelledDomain_destroy(td);

  set_last_error(0, nullptr);
  MeasurementRequest_message(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasurementRequest_measurement_name(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasurementRequest_waveforms(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasurementRequest_getters(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasurementRequest_meter_transforms(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasurementRequest_time_domain(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MeasurementRequestTest, Equality) {
  EXPECT_FALSE(MeasurementRequest_equal(req, req2));
  EXPECT_TRUE(MeasurementRequest_not_equal(req, req2));
  EXPECT_TRUE(MeasurementRequest_equal(req, req));
  EXPECT_FALSE(MeasurementRequest_not_equal(req, req));

  set_last_error(0, nullptr);
  MeasurementRequest_equal(nullptr, req2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasurementRequest_equal(req, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasurementRequest_not_equal(nullptr, req2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasurementRequest_not_equal(req, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MeasurementRequestTest, ToJsonFromJson) {
  auto json = MeasurementRequest_to_json_string(req);
  auto r2   = MeasurementRequest_from_json_string(json);
  EXPECT_TRUE(MeasurementRequest_equal(req, r2));
  MeasurementRequest_destroy(r2);
  String_destroy(json);

  set_last_error(0, nullptr);
  MeasurementRequest_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasurementRequest_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
