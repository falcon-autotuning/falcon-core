#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/ListString_c_api.h"
#include "falcon_core/generic/MapStringDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/math/AnalyticFunction_c_api.h"
typedef void* PortTransformHandle;

// @category:allocation
PortTransformHandle PortTransform_create(InstrumentPortHandle   port,
                                         AnalyticFunctionHandle transform);
// @category:allocation
PortTransformHandle PortTransform_create_constant_transform(
    InstrumentPortHandle port, double value);
// @category:allocation
PortTransformHandle PortTransform_create_identity_transform(
    InstrumentPortHandle port);
// @category:deallocation
void PortTransform_destroy(PortTransformHandle handle);
// @category:read
/* AUTO-DOC from cpp: PortTransform_port | falcon_core::instrument_interfaces::port_transforms::PortTransform::port */
/**
 * @brief Returns the port associated with the transform.
 */
InstrumentPortHandle PortTransform_port(PortTransformHandle handle);
// @category:read
ListStringHandle PortTransform_labels(PortTransformHandle handle);
// @category:read
double PortTransform_evaluate(PortTransformHandle   handle,
                              MapStringDoubleHandle args,
                              double                time);
// @category:read
FArrayDoubleHandle PortTransform_evaluate_arraywise(PortTransformHandle handle,
                                                    MapStringDoubleHandle args,
                                                    double deltaT,
                                                    double maxTime);
// @category:read
bool PortTransform_equal(PortTransformHandle a, PortTransformHandle b);
// @category:read
bool PortTransform_not_equal(PortTransformHandle a, PortTransformHandle b);
// @category:read
StringHandle PortTransform_to_json_string(PortTransformHandle handle);
// @category:allocation
PortTransformHandle PortTransform_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
