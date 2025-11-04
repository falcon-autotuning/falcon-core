#include <gtest/gtest.h>

#include "falcon_core/communications/HDF5Data_c_api.h"
#include "falcon_core/generic/MapStringString_c_api.h"
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
