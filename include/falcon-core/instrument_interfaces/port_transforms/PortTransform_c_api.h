#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon-core/generic/FArrayDouble_c_api.h"
#include "falcon-core/generic/ListString_c_api.h"
#include "falcon-core/generic/MapStringDouble_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon-core/math/AnalyticFunction_c_api.h"
typedef void* PortTransformHandle;

// @category:allocation
FALCON_CORE_C_API PortTransformHandle
PortTransform_copy(PortTransformHandle handle);
// @category:deallocation
FALCON_CORE_C_API void PortTransform_destroy(PortTransformHandle handle);
// @category:read
FALCON_CORE_C_API bool PortTransform_equal(PortTransformHandle handle,
                                           PortTransformHandle other);
// @category:read
FALCON_CORE_C_API bool PortTransform_not_equal(PortTransformHandle handle,
                                               PortTransformHandle other);
// @category:read
FALCON_CORE_C_API StringHandle
PortTransform_to_json_string(PortTransformHandle handle);
// @category:allocation
FALCON_CORE_C_API PortTransformHandle
PortTransform_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API PortTransformHandle PortTransform_create(
    InstrumentPortHandle port, AnalyticFunctionHandle transform);
// @category:allocation
FALCON_CORE_C_API PortTransformHandle PortTransform_create_constant_transform(
    InstrumentPortHandle port, double value);
// @category:allocation
FALCON_CORE_C_API PortTransformHandle
PortTransform_create_identity_transform(InstrumentPortHandle port);
// @category:read
/* AUTO-DOC from cpp: PortTransform_port |
 * falcon_core::instrument_interfaces::port_transforms::PortTransform::port */
/**
 * @brief Returns the port associated with the transform.
 */
FALCON_CORE_C_API InstrumentPortHandle
PortTransform_port(PortTransformHandle handle);
// @category:read
FALCON_CORE_C_API ListStringHandle
PortTransform_labels(PortTransformHandle handle);
// @category:read
FALCON_CORE_C_API double PortTransform_evaluate(PortTransformHandle   handle,
                                                MapStringDoubleHandle args,
                                                double                time);
// @category:read
FALCON_CORE_C_API FArrayDoubleHandle
PortTransform_evaluate_arraywise(PortTransformHandle   handle,
                                 MapStringDoubleHandle args,
                                 double                deltaT,
                                 double                maxTime);

#ifdef __cplusplus
}
#endif
