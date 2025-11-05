#include <gtest/gtest.h>

#include "falcon_core/communications/HDF5Data_c_api.h"
#include "falcon_core/generic/MapStringString_c_api.h"
#include "falcon_core/generic/PairMeasurementResponseMeasurementRequest_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/AxesControlArray_c_api.h"
#include "falcon_core/math/AxesCoupledLabelledDomain_c_api.h"
#include "falcon_core/math/AxesInt_c_api.h"
#include "falcon_core/math/arrays/LabelledArraysLabelledMeasuredArray_c_api.h"

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
  EXPECT_THROW(HDF5Data_create(nullptr,
                               unit_domain,
                               domain_labels,
                               ranges,
                               metadata,
                               measurement_title,
                               unique_id,
                               timestamp),
               std::invalid_argument);
  EXPECT_THROW(HDF5Data_create(shape,
                               nullptr,
                               domain_labels,
                               ranges,
                               metadata,
                               measurement_title,
                               unique_id,
                               timestamp),
               std::invalid_argument);
  EXPECT_THROW(HDF5Data_create(shape,
                               unit_domain,
                               nullptr,
                               ranges,
                               metadata,
                               measurement_title,
                               unique_id,
                               timestamp),
               std::invalid_argument);
  EXPECT_THROW(HDF5Data_create(shape,
                               unit_domain,
                               domain_labels,
                               nullptr,
                               metadata,
                               measurement_title,
                               unique_id,
                               timestamp),
               std::invalid_argument);
  EXPECT_THROW(HDF5Data_create(shape,
                               unit_domain,
                               domain_labels,
                               ranges,
                               nullptr,
                               measurement_title,
                               unique_id,
                               timestamp),
               std::invalid_argument);
  EXPECT_THROW(HDF5Data_create(shape,
                               unit_domain,
                               domain_labels,
                               ranges,
                               metadata,
                               nullptr,
                               unique_id,
                               timestamp),
               std::invalid_argument);
  EXPECT_THROW(HDF5Data_destroy(nullptr), std::invalid_argument);
}

TEST_F(HDF5DataTest, Equality) {
  EXPECT_FALSE(HDF5Data_equal(hdf5, hdf5_2));
  EXPECT_TRUE(HDF5Data_not_equal(hdf5, hdf5_2));
  EXPECT_TRUE(HDF5Data_equal(hdf5, hdf5));
  EXPECT_FALSE(HDF5Data_not_equal(hdf5, hdf5));
  EXPECT_THROW(HDF5Data_equal(nullptr, hdf5_2), std::invalid_argument);
  EXPECT_THROW(HDF5Data_equal(hdf5, nullptr), std::invalid_argument);
  EXPECT_THROW(HDF5Data_not_equal(nullptr, hdf5_2), std::invalid_argument);
  EXPECT_THROW(HDF5Data_not_equal(hdf5, nullptr), std::invalid_argument);
}

TEST_F(HDF5DataTest, ToJsonFromJson) {
  auto json = HDF5Data_to_json_string(hdf5);
  auto h2   = HDF5Data_from_json_string(json);
  EXPECT_TRUE(HDF5Data_equal(hdf5, h2));
  HDF5Data_destroy(h2);
  String_destroy(json);
  EXPECT_THROW(HDF5Data_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(HDF5Data_from_json_string(nullptr), std::invalid_argument);
}

TEST_F(HDF5DataTest, ToFileAndCreateFromFile) {
  StringHandle filename = String_wrap("test_hdf5_data.h5");
  HDF5Data_to_file(hdf5, filename);
  auto h2 = HDF5Data_create_from_file(filename);
  EXPECT_TRUE(HDF5Data_equal(hdf5, h2));
  HDF5Data_destroy(h2);
  std::remove("test_hdf5_data.h5");
  String_destroy(filename);

  EXPECT_THROW(HDF5Data_to_file(nullptr, String_wrap("file.h5")),
               std::invalid_argument);
  EXPECT_THROW(HDF5Data_to_file(hdf5, nullptr), std::invalid_argument);

  EXPECT_THROW(HDF5Data_create_from_file(nullptr), std::invalid_argument);
}

TEST_F(HDF5DataTest, FromCommunicationsAndToCommunications) {
  // Construct a valid MeasurementRequest (copy from MeasurementRequestTest
  // setup)
  StringHandle             msg          = String_wrap("msg");
  StringHandle             name         = String_wrap("measurement");
  DomainHandle             domain       = Domain_create(0, 1.0);
  StringHandle             default_name = String_wrap("A");
  ListLabelledDomainHandle domain_list  = ListLabelledDomain_create_empty();
  ListLabelledDomain_push_back(domain_list,
                               LabelledDomain_create_from_domain(
                                   domain,
                                   default_name,
                                   Connection_create_barrier_gate(default_name),
                                   InstrumentTypes_voltmeter()));
  CoupledLabelledDomainHandle labelled_domain =
      CoupledLabelledDomain_create(domain_list);
  AxesCoupledLabelledDomainHandle axes =
      AxesCoupledLabelledDomain_create_empty();
  AxesCoupledLabelledDomain_push_back(
      axes, CoupledLabelledDomain_create(labelled_domain));
  AxesMapStringBoolHandle increasing = AxesMapStringBool_create_empty();
  MapStringBoolHandle     map        = MapStringBool_create_empty();
  MapStringBool_insert(map, String_wrap("A"), true);
  AxesMapStringBool_push_back(increasing, map);
  AxesDiscretizerHandle discretizers = AxesDiscretizer_create_empty();
  AxesDiscretizer_push_back(discretizers,
                            Discretizer_create_cartesian_discretizer(0.1));
  UnitSpaceHandle         unit_space = UnitSpace_create(discretizers, domain);
  DiscreteSpaceHandle     space = DiscreteSpace_create(unit_space, axes, map);
  ListPortTransformHandle transforms = ListPortTransform_create_empty();
  InstrumentPortHandle    port = InstrumentPort_create_meter(String_wrap("P1"));
  ListStringHandle        labels = ListString_create_empty();
  ListString_push_back(labels, String_wrap("x"));
  AnalyticFunctionHandle analytic =
      AnalyticFunction_create(labels, String_wrap("2x[0]+1"));
  PortTransformHandle pt = PortTransform_create(port, analytic);
  ListPortTransform_push_back(transforms, pt);
  WaveformHandle     waveform  = Waveform_create(space, transforms);
  ListWaveformHandle waveforms = ListWaveform_create_empty();
  ListWaveform_push_back(waveforms, waveform);
  PortsHandle getters = Ports_create_empty();
  Ports_push_back(getters, port);
  MapInstrumentPortPortTransformHandle meter_transforms =
      MapInstrumentPortPortTransform_create_empty();
  MapInstrumentPortPortTransform_insert(meter_transforms, port, pt);
  LabelledDomainHandle time_domain =
      LabelledDomain_create_from_port(0.0,
                                      1.0,
                                      InstrumentTypes_clock(),
                                      InstrumentPort_create_execution_clock());
  MeasurementRequestHandle request = MeasurementRequest_create(
      msg, name, waveforms, getters, meter_transforms, time_domain);

  // Minimal valid MeasurementResponse
  ListLabelledMeasuredArrayHandle measured_arrays =
      ListLabelledMeasuredArray_create_empty();
  LabelledArraysLabelledMeasuredArrayHandle ranges =
      LabelledArraysLabelledMeasuredArray_create(measured_arrays);
  MeasurementResponseHandle response = MeasurementResponse_create(ranges);

  DeviceVoltageStatesHandle voltage_states = DeviceVoltageStates_create_empty();
  int8_t                    session_id[16] = {0};
  StringHandle              title          = String_wrap("title");
  int                       unique_id      = 42;
  int                       timestamp      = 123456;

  // Create HDF5Data from communications
  auto hdf5 = HDF5Data_create_from_communications(request,
                                                  response,
                                                  voltage_states,
                                                  session_id,
                                                  title,
                                                  unique_id,
                                                  timestamp);

  // Convert back to communications
  auto comm_pair = HDF5Data_to_communications(hdf5);
  ASSERT_NE(comm_pair, nullptr);
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
  ListLabelledMeasuredArray_destroy(measured_arrays);
  LabelledArraysLabelledMeasuredArray_destroy(ranges);
  // Destroy all MeasurementRequest construction resources
  MeasurementRequest_destroy(request);
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
  EXPECT_THROW(HDF5Data_to_communications(nullptr), std::invalid_argument);
}

TEST_F(HDF5DataTest, FromJsonStringInvalid) {
  StringHandle invalid_json = String_wrap("{not valid json}");
  EXPECT_THROW(HDF5Data_from_json_string(invalid_json), std::exception);
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
