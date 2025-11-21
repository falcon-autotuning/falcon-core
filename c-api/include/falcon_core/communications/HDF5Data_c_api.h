#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

#include "falcon_core/communications/voltage_states/DeviceVoltageStates_c_api.h"
#include "falcon_core/generic/MapStringString_c_api.h"
#include "falcon_core/generic/PairMeasurementResponseMeasurementRequest_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/AxesControlArray_c_api.h"
#include "falcon_core/math/AxesCoupledLabelledDomain_c_api.h"
#include "falcon_core/math/AxesInt_c_api.h"
#include "falcon_core/math/arrays/LabelledArraysLabelledMeasuredArray_c_api.h"

typedef void* HDF5DataHandle;

// Constructors
HDF5DataHandle HDF5Data_create(AxesIntHandle                   shape,
                               AxesControlArrayHandle          unit_domain,
                               AxesCoupledLabelledDomainHandle domain_labels,
                               LabelledArraysLabelledMeasuredArrayHandle ranges,
                               MapStringStringHandle metadata,
                               StringHandle          measurement_title,
                               int                   unique_id,
                               int                   timestamp);
HDF5DataHandle HDF5Data_create_from_file(StringHandle path);
HDF5DataHandle HDF5Data_create_from_communications(
    MeasurementRequestHandle  request,
    MeasurementResponseHandle response,
    DeviceVoltageStatesHandle device_voltage_states,
    int8_t                    session_id[16],
    StringHandle              measurement_title,
    int                       unique_id,
    int                       timestamp);

// Destructor
void HDF5Data_destroy(HDF5DataHandle handle);

// Methods
/* AUTO-DOC from cpp: HDF5Data_to_file | falcon_core::communications::HDF5Data::to_file */
/**
 * @brief (from C++: falcon_core::communications::HDF5Data::to_file)
 * @brief Convert from an HDF5Data object to a file.
 * @param path The path to write the HDF5 file at.
 */
void HDF5Data_to_file(HDF5DataHandle handle, StringHandle path);
/* AUTO-DOC from cpp: HDF5Data_to_communications | falcon_core::communications::HDF5Data::to_communications */
/**
 * @brief (from C++: falcon_core::communications::HDF5Data::to_communications)
 * @brief Convert from an HDF5Data object to a MeasurementResponse and a
 * Metadata.
 * @return A pair of MeasurementResponse and MeasurementRequest.
 */
PairMeasurementResponseMeasurementRequestHandle HDF5Data_to_communications(
    HDF5DataHandle handle);
bool HDF5Data_equal(HDF5DataHandle handle, HDF5DataHandle other);
bool HDF5Data_not_equal(HDF5DataHandle handle, HDF5DataHandle other);

// Serialization (from Song)
StringHandle   HDF5Data_to_json_string(HDF5DataHandle handle);
HDF5DataHandle HDF5Data_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
