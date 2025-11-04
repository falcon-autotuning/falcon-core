#include <gtest/gtest.h>

#include "falcon_core/communications/messages/MeasurementRequest_c_api.h"
#include "falcon_core/generic/ListPortTransform_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/Waveform_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/instrument_interfaces/names/Ports_c_api.h"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform_c_api.h"
#include "falcon_core/math/discrete_spaces/DiscreteSpace_c_api.h"
#include "falcon_core/math/domains/LabelledDomain_c_api.h"

class MeasurementRequestTest : public ::testing::Test {
 protected:
  void SetUp() override {
    msg  = String_wrap("msg");
    name = String_wrap("measurement");

    // --- Waveform construction pattern ---
    domain       = Domain_create(0, 1.0);
    default_name = String_wrap("A");
    domain_list  = ListLabelledDomain_create_empty();
    ListLabelledDomain_push_back(
        domain_list,
        LabelledDomain_create_from_domain(
            domain,
            default_name,
            Connection_create_barrier_gate(default_name),
            InstrumentTypes_voltmeter()));
    labelled_domain = CoupledLabelledDomain_create(domain_list);
    axes            = AxesCoupledLabelledDomain_create_empty();
    AxesCoupledLabelledDomain_push_back(
        axes, CoupledLabelledDomain_create(labelled_domain));
    increasing = AxesMapStringBool_create_empty();
    map        = MapStringBool_create_empty();
    MapStringBool_insert(map, String_wrap("A"), true);
    AxesMapStringBool_push_back(increasing, map);
    discretizers = AxesDiscretizer_create_empty();
    AxesDiscretizer_push_back(discretizers,
                              Discretizer_create_cartesian_discretizer(0.1));
    unit_space = UnitSpace_create(discretizers, domain);
    space      = DiscreteSpace_create(unit_space, axes, map);
    transforms = ListPortTransform_create_empty();
    port       = InstrumentPort_create_meter(String_wrap("P1"));
    labels     = ListString_create_empty();
    ListString_push_back(labels, String_wrap("x"));
    analytic = AnalyticFunction_create(labels, String_wrap("2x[0]+1"));
    pt       = PortTransform_create(port, analytic);
    ListPortTransform_push_back(transforms, pt);

    waveform  = Waveform_create(space, transforms);
    waveforms = ListWaveform_create_empty();
    ListWaveform_push_back(waveforms, waveform);

    getters = Ports_create_empty();
    Ports_push_back(getters, port);

    meter_transforms = MapInstrumentPortPortTransform_create_empty();
    MapInstrumentPortPortTransform_insert(meter_transforms, port, pt);

    time_domain = LabelledDomain_create_from_port(
        0.0,
        1.0,
        InstrumentTypes_clock(),
        InstrumentPort_create_execution_clock());

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
    AxesInt_destroy(divisions);
    AxesCoupledLabelledDomain_destroy(axes);
    AxesMapStringBool_destroy(increasing);
    Domain_destroy(domain);
  }
  StringHandle                         msg              = nullptr;
  StringHandle                         name             = nullptr;
  WaveformHandle                       waveform         = nullptr;
  ListWaveformHandle                   waveforms        = nullptr;
  InstrumentPortHandle                 port             = nullptr;
  PortsHandle                          getters          = nullptr;
  PortTransformHandle                  pt               = nullptr;
  ListPortTransformHandle              transforms       = nullptr;
  MapInstrumentPortPortTransformHandle meter_transforms = nullptr;
  LabelledDomainHandle                 time_domain      = nullptr;
  MeasurementRequestHandle             req              = nullptr;
  MeasurementRequestHandle             req2             = nullptr;
  // Waveform construction handles
  MapStringBoolHandle             map             = nullptr;
  StringHandle                    default_name    = nullptr;
  ListLabelledDomainHandle        domain_list     = nullptr;
  CoupledLabelledDomainHandle     labelled_domain = nullptr;
  DiscreteSpaceHandle             space           = nullptr;
  UnitSpaceHandle                 unit_space      = nullptr;
  AxesDiscretizerHandle           discretizers    = nullptr;
  ListStringHandle                labels          = nullptr;
  AnalyticFunctionHandle          analytic        = nullptr;
  AxesIntHandle                   divisions       = nullptr;
  AxesCoupledLabelledDomainHandle axes            = nullptr;
  AxesMapStringBoolHandle         increasing      = nullptr;
  DomainHandle                    domain          = nullptr;
};

TEST_F(MeasurementRequestTest, CreateDestroy) {
  auto r = MeasurementRequest_create(
      msg, name, waveforms, getters, meter_transforms, time_domain);
  MeasurementRequest_destroy(r);
  EXPECT_THROW(
      MeasurementRequest_create(
          nullptr, name, waveforms, getters, meter_transforms, time_domain),
      std::invalid_argument);
  EXPECT_THROW(
      MeasurementRequest_create(
          msg, nullptr, waveforms, getters, meter_transforms, time_domain),
      std::invalid_argument);
  EXPECT_THROW(MeasurementRequest_create(
                   msg, name, nullptr, getters, meter_transforms, time_domain),
               std::invalid_argument);
  EXPECT_THROW(
      MeasurementRequest_create(
          msg, name, waveforms, nullptr, meter_transforms, time_domain),
      std::invalid_argument);
  EXPECT_THROW(MeasurementRequest_create(
                   msg, name, waveforms, getters, nullptr, time_domain),
               std::invalid_argument);
  EXPECT_THROW(MeasurementRequest_create(
                   msg, name, waveforms, getters, meter_transforms, nullptr),
               std::invalid_argument);
  EXPECT_THROW(MeasurementRequest_destroy(nullptr), std::invalid_argument);
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

  EXPECT_THROW(MeasurementRequest_message(nullptr), std::invalid_argument);
  EXPECT_THROW(MeasurementRequest_measurement_name(nullptr),
               std::invalid_argument);
  EXPECT_THROW(MeasurementRequest_waveforms(nullptr), std::invalid_argument);
  EXPECT_THROW(MeasurementRequest_getters(nullptr), std::invalid_argument);
  EXPECT_THROW(MeasurementRequest_meter_transforms(nullptr),
               std::invalid_argument);
  EXPECT_THROW(MeasurementRequest_time_domain(nullptr), std::invalid_argument);
}

TEST_F(MeasurementRequestTest, Equality) {
  EXPECT_FALSE(MeasurementRequest_equal(req, req2));
  EXPECT_TRUE(MeasurementRequest_not_equal(req, req2));
  EXPECT_TRUE(MeasurementRequest_equal(req, req));
  EXPECT_FALSE(MeasurementRequest_not_equal(req, req));

  EXPECT_THROW(MeasurementRequest_equal(nullptr, req2), std::invalid_argument);
  EXPECT_THROW(MeasurementRequest_equal(req, nullptr), std::invalid_argument);
  EXPECT_THROW(MeasurementRequest_not_equal(nullptr, req2),
               std::invalid_argument);
  EXPECT_THROW(MeasurementRequest_not_equal(req, nullptr),
               std::invalid_argument);
}

TEST_F(MeasurementRequestTest, ToJsonFromJson) {
  auto json = MeasurementRequest_to_json_string(req);
  auto r2   = MeasurementRequest_from_json_string(json);
  EXPECT_TRUE(MeasurementRequest_equal(req, r2));
  MeasurementRequest_destroy(r2);
  String_destroy(json);

  EXPECT_THROW(MeasurementRequest_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(MeasurementRequest_from_json_string(nullptr),
               std::invalid_argument);
}
