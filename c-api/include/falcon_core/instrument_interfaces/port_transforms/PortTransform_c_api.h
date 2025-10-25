#pragma once
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/math/AnalyticFunction_c_api.h"
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/ListString_c_api.h"
#include "falcon_core/generic/MapStringDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"
typedef void* PortTransformHandle;

// Constructors
PortTransformHandle PortTransform_create(InstrumentPortHandle   port,
                                         AnalyticFunctionHandle transform);
PortTransformHandle PortTransform_create_constant_transform(
    InstrumentPortHandle port, double value);
PortTransformHandle PortTransform_create_identity_transform(
    InstrumentPortHandle port);

// Destructor
void PortTransform_destroy(PortTransformHandle handle);

// Methods
InstrumentPortHandle PortTransform_port(PortTransformHandle handle);
ListStringHandle     PortTransform_labels(PortTransformHandle handle);
double               PortTransform_evaluate(PortTransformHandle   handle,
                                            MapStringDoubleHandle args,
                                            double                time);
FArrayDoubleHandle PortTransform_evaluate_arraywise(PortTransformHandle handle,
                                                    MapStringDoubleHandle args,
                                                    double deltaT,
                                                    double maxTime);
bool PortTransform_equal(PortTransformHandle a, PortTransformHandle b);
bool PortTransform_not_equal(PortTransformHandle a, PortTransformHandle b);

// Serialization (from Song)
StringHandle        PortTransform_to_json_string(PortTransformHandle handle);
PortTransformHandle PortTransform_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
