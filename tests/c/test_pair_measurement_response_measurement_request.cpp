#include <gtest/gtest.h>

#include "falcon-core/generic/ErrorHandling_c_api.h"
#include "falcon-core/generic/PairMeasurementResponseMeasurementRequest_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/instrument_interfaces/names/InstrumentTypes_c_api.h"
#include "falcon-core/physics/units/SymbolUnit_c_api.h"

class PairMeasurementResponseMeasurementRequestTest : public ::testing::Test {
 protected:
  void SetUp() override {
    double             data1[3]     = {1.0, 2.0, 3.0};
    size_t             shape1[1]    = {3};
    FArrayDoubleHandle farray1      = FArrayDouble_from_data(data1, shape1, 1);
    LabelledMeasuredArrayHandle sh1 = LabelledMeasuredArray_from_farray(
        farray1,
        AcquisitionContext_create(
            Connection_create_plunger_gate(String_wrap("A")),
            InstrumentTypes_voltmeter(),
            SymbolUnit_create_volt()));
    ListLabelledMeasuredArrayHandle lch =
        ListLabelledMeasuredArray_create_empty();
    ListLabelledMeasuredArray_push_back(lch, sh1);
    StringHandle         msg          = String_wrap("msg");
    StringHandle         name         = String_wrap("measurement");
    DomainHandle         domain       = Domain_create(0, 1.0, true, true);
    StringHandle         default_name = String_wrap("A");
    InstrumentPortHandle port =
        InstrumentPort_create_knob(default_name,
                                   Connection_create_barrier_gate(default_name),
                                   InstrumentTypes_voltmeter(),
                                   SymbolUnit_create_volt(),
                                   String_wrap(""));
    InstrumentPortHandle getter = InstrumentPort_create_meter(
        String_wrap("ohm1"),
        Connection_create_ohmic(String_wrap("ohm1")),
        InstrumentTypes_amnmeter(),
        SymbolUnit_create_ampere(),
        String_wrap(""));
    ListLabelledDomainHandle domain_list = ListLabelledDomain_create_empty();
    ListLabelledDomain_push_back(
        domain_list, LabelledDomain_create_from_port_and_domain(port, domain));
    CoupledLabelledDomainHandle labelled_domain =
        CoupledLabelledDomain_create(domain_list);
    AxesCoupledLabelledDomainHandle axes =
        AxesCoupledLabelledDomain_create_empty();
    AxesCoupledLabelledDomain_push_back(
        axes, CoupledLabelledDomain_create(labelled_domain));
    AxesMapStringBoolHandle increasing = AxesMapStringBool_create_empty();
    MapStringBoolHandle     map        = MapStringBool_create_empty();
    MapStringBool_insert(map, default_name, true);
    AxesMapStringBool_push_back(increasing, map);
    AxesDiscretizerHandle discretizers = AxesDiscretizer_create_empty();
    AxesDiscretizer_push_back(discretizers,
                              Discretizer_create_cartesian_discretizer(0.1));
    UnitSpaceHandle     unit_space = UnitSpace_create(discretizers, domain);
    DiscreteSpaceHandle space =
        DiscreteSpace_create(unit_space, axes, increasing);
    ListPortTransformHandle transforms = ListPortTransform_create_empty();
    ListStringHandle        labels     = ListString_create_empty();
    ListString_push_back(labels, String_wrap("x"));
    AnalyticFunctionHandle analytic =
        AnalyticFunction_create(labels, String_wrap("2x[0]+1"));
    PortTransformHandle pt = PortTransform_create(port, analytic);
    ListPortTransform_push_back(transforms, pt);

    WaveformHandle     waveform  = Waveform_create(space, transforms);
    ListWaveformHandle waveforms = ListWaveform_create_empty();
    ListWaveform_push_back(waveforms, waveform);

    PortsHandle getters = Ports_create_empty();
    Ports_push_back(getters, getter);

    MapInstrumentPortPortTransformHandle meter_transforms =
        MapInstrumentPortPortTransform_create_empty();
    MapInstrumentPortPortTransform_insert(meter_transforms, port, pt);

    LabelledDomainHandle time_domain = LabelledDomain_create_from_port(
        0.0, 1.0, InstrumentPort_create_execution_clock(), true, true);

    t2 = MeasurementRequest_create(
        msg, name, waveforms, getters, meter_transforms, time_domain);
    t1 = MeasurementResponse_create(
        LabelledArraysLabelledMeasuredArray_create(lch));
    pair1 = PairMeasurementResponseMeasurementRequest_create(t1, t2);
    pair2 = PairMeasurementResponseMeasurementRequest_create(t1, t2);
  }
  void TearDown() override {
    PairMeasurementResponseMeasurementRequest_destroy(pair1);
    PairMeasurementResponseMeasurementRequest_destroy(pair2);
    MeasurementResponse_destroy(t1);
    MeasurementRequest_destroy(t2);
  }
  PairMeasurementResponseMeasurementRequestHandle pair1;
  PairMeasurementResponseMeasurementRequestHandle pair2;
  MeasurementResponseHandle                       t1;
  MeasurementRequestHandle                        t2;
};

TEST_F(PairMeasurementResponseMeasurementRequestTest, CreateDestroy) {
  set_last_error(0, nullptr);
  PairMeasurementResponseMeasurementRequest_create(nullptr, t2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairMeasurementResponseMeasurementRequest_create(t1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairMeasurementResponseMeasurementRequest_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairMeasurementResponseMeasurementRequestTest, Accessors) {
  auto f = PairMeasurementResponseMeasurementRequest_first(pair1);
  auto s = PairMeasurementResponseMeasurementRequest_second(pair1);
  EXPECT_TRUE(MeasurementResponse_equal(f, t1));
  EXPECT_TRUE(MeasurementRequest_equal(s, t2));
  set_last_error(0, nullptr);
  PairMeasurementResponseMeasurementRequest_first(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairMeasurementResponseMeasurementRequest_second(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairMeasurementResponseMeasurementRequestTest, Equality) {
  EXPECT_TRUE(PairMeasurementResponseMeasurementRequest_equal(pair1, pair2));
  EXPECT_FALSE(
      PairMeasurementResponseMeasurementRequest_not_equal(pair1, pair2));
  set_last_error(0, nullptr);
  PairMeasurementResponseMeasurementRequest_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairMeasurementResponseMeasurementRequest_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairMeasurementResponseMeasurementRequest_not_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairMeasurementResponseMeasurementRequest_not_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairMeasurementResponseMeasurementRequestTest, ToJsonFromJson) {
  auto json = PairMeasurementResponseMeasurementRequest_to_json_string(pair1);
  auto p2   = PairMeasurementResponseMeasurementRequest_from_json_string(json);
  EXPECT_TRUE(PairMeasurementResponseMeasurementRequest_equal(pair1, p2));
  PairMeasurementResponseMeasurementRequest_destroy(p2);
  set_last_error(0, nullptr);
  PairMeasurementResponseMeasurementRequest_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairMeasurementResponseMeasurementRequest_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
