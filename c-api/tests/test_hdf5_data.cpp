#include <gtest/gtest.h>

#include "falcon_core/communications/HDF5Data_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/MapStringString_c_api.h"
#include "falcon_core/generic/PairMeasurementResponseMeasurementRequest_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/AxesControlArray_c_api.h"
#include "falcon_core/math/AxesCoupledLabelledDomain_c_api.h"
#include "falcon_core/math/AxesInt_c_api.h"
#include "falcon_core/math/arrays/LabelledArraysLabelledMeasuredArray_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"

class HDF5DataTest : public ::testing::Test {
 protected:
  void SetUp() override {
    // Minimal valid construction for all required handles
    shape = AxesInt_create_empty();
    AxesInt_push_back(shape, 2);

    unit_domain     = AxesControlArray_create_empty();
    farray          = FArrayDouble_from_data(data, size, 1);
    measured_farray = FArrayDouble_from_data(measured_data, size, 1);
    AxesControlArray_push_back(unit_domain, ControlArray_from_farray(farray));

    domain_labels = AxesCoupledLabelledDomain_create_empty();
    AxesCoupledLabelledDomain_push_back(domain_labels,
                                        CoupledLabelledDomain_create_empty());
    label =
        AcquisitionContext_create(Connection_create_ohmic(String_wrap("In")),
                                  InstrumentTypes_voltage_source(),
                                  SymbolUnit_create_volt());
    measured_arrays = ListLabelledMeasuredArray_create_empty();
    ListLabelledMeasuredArray_push_back(
        measured_arrays,
        LabelledMeasuredArray_from_farray(measured_farray, label));

    ranges   = LabelledArraysLabelledMeasuredArray_create(measured_arrays);
    metadata = MapStringString_create_empty();
    MapStringString_insert(metadata, String_wrap("key"), String_wrap("value"));

    measurement_title = String_wrap("title");
    unique_id         = 42;
    timestamp         = 123456;

    hdf5   = HDF5Data_create(shape,
                           unit_domain,
                           domain_labels,
                           ranges,
                           metadata,
                           measurement_title,
                           unique_id,
                           timestamp);
    hdf5_2 = HDF5Data_create(shape,
                             unit_domain,
                             domain_labels,
                             ranges,
                             metadata,
                             measurement_title,
                             unique_id + 1,
                             timestamp + 1);
  }
  void TearDown() override {
    ListLabelledMeasuredArray_destroy(measured_arrays);
    FArrayDouble_destroy(farray);
    FArrayDouble_destroy(measured_farray);
    AcquisitionContext_destroy(label);
    HDF5Data_destroy(hdf5);
    HDF5Data_destroy(hdf5_2);
    AxesInt_destroy(shape);
    AxesControlArray_destroy(unit_domain);
    AxesCoupledLabelledDomain_destroy(domain_labels);
    LabelledArraysLabelledMeasuredArray_destroy(ranges);
    MapStringString_destroy(metadata);
    String_destroy(measurement_title);
  }
  double                                    data[2]          = {1.0, 2.0};
  double                                    measured_data[2] = {8.2, 4.0};
  size_t                                    size[1]          = {2};
  ListLabelledMeasuredArrayHandle           measured_arrays;
  FArrayDoubleHandle                        farray;
  AcquisitionContextHandle                  label;
  FArrayDoubleHandle                        measured_farray;
  AxesIntHandle                             shape;
  AxesControlArrayHandle                    unit_domain;
  AxesCoupledLabelledDomainHandle           domain_labels;
  LabelledArraysLabelledMeasuredArrayHandle ranges;
  MapStringStringHandle                     metadata;
  StringHandle                              measurement_title;
  int                                       unique_id = 0;
  int                                       timestamp = 0;
  HDF5DataHandle                            hdf5;
  HDF5DataHandle                            hdf5_2;
};

TEST_F(HDF5DataTest, CreateDestroy) {
  auto h = HDF5Data_create(shape,
                           unit_domain,
                           domain_labels,
                           ranges,
                           metadata,
                           measurement_title,
                           unique_id,
                           timestamp);
  HDF5Data_destroy(h);
  set_last_error(0, nullptr);
  HDF5Data_create(nullptr,
                  unit_domain,
                  domain_labels,
                  ranges,
                  metadata,
                  measurement_title,
                  unique_id,
                  timestamp);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  HDF5Data_create(shape,
                  nullptr,
                  domain_labels,
                  ranges,
                  metadata,
                  measurement_title,
                  unique_id,
                  timestamp);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  HDF5Data_create(shape,
                  unit_domain,
                  nullptr,
                  ranges,
                  metadata,
                  measurement_title,
                  unique_id,
                  timestamp);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  HDF5Data_create(shape,
                  unit_domain,
                  domain_labels,
                  nullptr,
                  metadata,
                  measurement_title,
                  unique_id,
                  timestamp);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  HDF5Data_create(shape,
                  unit_domain,
                  domain_labels,
                  ranges,
                  nullptr,
                  measurement_title,
                  unique_id,
                  timestamp);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  HDF5Data_create(shape,
                  unit_domain,
                  domain_labels,
                  ranges,
                  metadata,
                  nullptr,
                  unique_id,
                  timestamp);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  HDF5Data_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(HDF5DataTest, Equality) {
  EXPECT_FALSE(HDF5Data_equal(hdf5, hdf5_2));
  EXPECT_TRUE(HDF5Data_not_equal(hdf5, hdf5_2));
  EXPECT_TRUE(HDF5Data_equal(hdf5, hdf5));
  EXPECT_FALSE(HDF5Data_not_equal(hdf5, hdf5));
  set_last_error(0, nullptr);
  HDF5Data_equal(nullptr, hdf5_2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  HDF5Data_equal(hdf5, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  HDF5Data_not_equal(nullptr, hdf5_2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  HDF5Data_not_equal(hdf5, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(HDF5DataTest, ToJsonFromJson) {
  auto json = HDF5Data_to_json_string(hdf5);
  auto h2   = HDF5Data_from_json_string(json);
  HDF5Data_destroy(h2);
  String_destroy(json);
  set_last_error(0, nullptr);
  HDF5Data_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  HDF5Data_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(HDF5DataTest, ToFileAndCreateFromFile) {
  StringHandle filename = String_wrap("test_hdf5_data.h5");
  HDF5Data_to_file(hdf5, filename);
  auto h2 = HDF5Data_create_from_file(filename);
  EXPECT_TRUE(HDF5Data_equal(hdf5, h2));
  HDF5Data_destroy(h2);
  std::remove("test_hdf5_data.h5");
  String_destroy(filename);

  set_last_error(0, nullptr);
  HDF5Data_to_file(nullptr, String_wrap("file.h5"));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  HDF5Data_to_file(hdf5, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  HDF5Data_create_from_file(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
}

TEST_F(HDF5DataTest, FromCommunicationsAndToCommunications) {
  // Construct a valid MeasurementRequest (copy from MeasurementRequestTest
  // setup)
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
  InstrumentPortHandle getter =
      InstrumentPort_create_meter(String_wrap("ohm1"),
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
  AxesCoupledLabelledDomain_push_back(axes, labelled_domain);
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

  MeasurementRequestHandle request = MeasurementRequest_create(
      msg, name, waveforms, getters, meter_transforms, time_domain);
  MeasurementResponseHandle response = MeasurementResponse_create(
      LabelledArraysLabelledMeasuredArray_create(lch));

  DeviceVoltageStatesHandle voltage_states = DeviceVoltageStates_create_empty();
  int8_t                    session_id[16] = {0};
  StringHandle              title          = String_wrap("title");
  int                       unique_id      = 42;
  int                       timestamp      = 123456;
  EXPECT_EQ(get_last_error_code(), 0);
  if (get_last_error_msg() != 0) {
    std::cerr << "Other Error: " << get_last_error_msg() << std::endl;
  }

  // Create HDF5Data from communications
  auto hdf5 = HDF5Data_create_from_communications(request,
                                                  response,
                                                  voltage_states,
                                                  session_id,
                                                  title,
                                                  unique_id,
                                                  timestamp);
  EXPECT_EQ(get_last_error_code(), 0);
  if (get_last_error_msg() != 0) {
    std::cerr << "From communications Error: " << get_last_error_msg()
              << std::endl;
  }

  // Convert back to communications
  auto comm_pair = HDF5Data_to_communications(hdf5);
  EXPECT_EQ(get_last_error_code(), 0);
  if (get_last_error_msg() != 0) {
    std::cerr << "To communications Error: " << get_last_error_msg()
              << std::endl;
  }
  EXPECT_NE(PairMeasurementResponseMeasurementRequest_first(comm_pair),
            nullptr);
  EXPECT_NE(PairMeasurementResponseMeasurementRequest_second(comm_pair),
            nullptr);

  // Cleanup
  HDF5Data_destroy(hdf5);
  DeviceVoltageStates_destroy(voltage_states);
  MeasurementRequest_destroy(request);
  MeasurementResponse_destroy(response);
  String_destroy(title);
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

  // Error case
  set_last_error(0, nullptr);
  HDF5Data_to_communications(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(HDF5DataTest, FromJsonStringInvalid) {
  StringHandle invalid_json = String_wrap("{not valid json}");
  set_last_error(0, nullptr);
  HDF5Data_from_json_string(invalid_json);
  EXPECT_EQ(get_last_error_code(), 1);
  String_destroy(invalid_json);
}

TEST_F(HDF5DataTest, ComplexDataStructures) {
  // Add more axes, labels, metadata
  AxesInt_push_back(shape, 3);
  AxesControlArray_push_back(unit_domain, ControlArray_from_farray(farray));
  AxesCoupledLabelledDomain_push_back(domain_labels,
                                      CoupledLabelledDomain_create_empty());
  MapStringString_insert(
      metadata, String_wrap("another"), String_wrap("entry"));

  auto h    = HDF5Data_create(shape,
                           unit_domain,
                           domain_labels,
                           ranges,
                           metadata,
                           measurement_title,
                           unique_id,
                           timestamp);
  auto json = HDF5Data_to_json_string(h);
  auto h2   = HDF5Data_from_json_string(json);
  EXPECT_TRUE(HDF5Data_equal(h, h2));
  HDF5Data_destroy(h);
  HDF5Data_destroy(h2);
  String_destroy(json);
}

TEST_F(HDF5DataTest, UniqueIdTimestamp) {
  auto h    = HDF5Data_create(shape,
                           unit_domain,
                           domain_labels,
                           ranges,
                           metadata,
                           measurement_title,
                           999,
                           888);
  auto json = HDF5Data_to_json_string(h);
  auto h2   = HDF5Data_from_json_string(json);
  EXPECT_TRUE(HDF5Data_equal(h, h2));
  HDF5Data_destroy(h);
  HDF5Data_destroy(h2);
  String_destroy(json);
}

TEST_F(HDF5DataTest, GettersReturnValidHandles) {
  auto shape_out = HDF5Data_shape(hdf5);
  EXPECT_NE(shape_out, nullptr);
  AxesInt_destroy(shape_out);

  auto unit_domain_out = HDF5Data_unit_domain(hdf5);
  EXPECT_NE(unit_domain_out, nullptr);
  AxesControlArray_destroy(unit_domain_out);

  auto domain_labels_out = HDF5Data_domain_labels(hdf5);
  EXPECT_NE(domain_labels_out, nullptr);
  AxesCoupledLabelledDomain_destroy(domain_labels_out);

  auto ranges_out = HDF5Data_ranges(hdf5);
  EXPECT_NE(ranges_out, nullptr);
  LabelledArraysLabelledMeasuredArray_destroy(ranges_out);

  auto metadata_out = HDF5Data_metadata(hdf5);
  EXPECT_NE(metadata_out, nullptr);
  MapStringString_destroy(metadata_out);

  auto title_out = HDF5Data_measurement_title(hdf5);
  EXPECT_NE(title_out, nullptr);
  String_destroy(title_out);
}

TEST_F(HDF5DataTest, GettersReturnCorrectValues) {
  EXPECT_EQ(HDF5Data_unique_id(hdf5), unique_id);
  EXPECT_EQ(HDF5Data_timestamp(hdf5), timestamp);
}

TEST_F(HDF5DataTest, GettersNullptrHandle) {
  set_last_error(0, nullptr);
  EXPECT_EQ(HDF5Data_shape(nullptr), nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  EXPECT_EQ(HDF5Data_unit_domain(nullptr), nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  EXPECT_EQ(HDF5Data_domain_labels(nullptr), nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  EXPECT_EQ(HDF5Data_ranges(nullptr), nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  EXPECT_EQ(HDF5Data_metadata(nullptr), nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  EXPECT_EQ(HDF5Data_measurement_title(nullptr), nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  EXPECT_EQ(HDF5Data_unique_id(nullptr), 0);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  EXPECT_EQ(HDF5Data_timestamp(nullptr), 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(HDF5DataTest, CopyConstructor) {
  HDF5DataHandle copy = HDF5Data_copy(hdf5);
  EXPECT_NE(copy, nullptr);
  EXPECT_TRUE(HDF5Data_equal(hdf5, copy));
  HDF5Data_destroy(copy);

  set_last_error(0, nullptr);
  EXPECT_EQ(HDF5Data_copy(nullptr), nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
