#pragma once
#include <stddef.h>

#include "falcon_core/communications/voltage_states/DeviceVoltageStates_c_api.h"
#include "falcon_core/generic/ListConnection_c_api.h"
#include "falcon_core/generic/ListPairConnectionPairQuantityQuantity_c_api.h"
#include "falcon_core/generic/ListPairQuantityQuantity_c_api.h"
#include "falcon_core/generic/PairQuantityQuantity_c_api.h"
#include "falcon_core/math/Point_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

typedef void* VectorHandle;

// Constructors
VectorHandle Vector_create(PointHandle start, PointHandle end);
VectorHandle Vector_create_from_end(PointHandle end);
VectorHandle Vector_create_from_quantities(MapConnectionQuantityHandle start,
                                           MapConnectionQuantityHandle end);
VectorHandle Vector_create_from_end_quantities(MapConnectionQuantityHandle end);
VectorHandle Vector_create_from_doubles(MapConnectionDoubleHandle start,
                                        MapConnectionDoubleHandle end,
                                        SymbolUnitHandle          unit);
VectorHandle Vector_create_from_end_doubles(MapConnectionDoubleHandle end,
                                            SymbolUnitHandle          unit);

VectorHandle Vector_create_from_parent(MapConnectionQuantityHandle items);

// Destructor
void Vector_destroy(VectorHandle handle);

// Methods
PointHandle                 Vector_endPoint(VectorHandle handle);
PointHandle                 Vector_startPoint(VectorHandle handle);
MapConnectionQuantityHandle Vector_end_quantities(VectorHandle handle);
MapConnectionQuantityHandle Vector_start_quantities(VectorHandle handle);
MapConnectionDoubleHandle   Vector_end_map(VectorHandle handle);
MapConnectionDoubleHandle   Vector_start_map(VectorHandle handle);
ListConnectionHandle        Vector_connections(VectorHandle handle);
SymbolUnitHandle            Vector_unit(VectorHandle handle);
ConnectionHandle            Vector_principle_connection(VectorHandle handle);
double                      Vector_magnitude(VectorHandle handle);
void                        Vector_insert_or_assign(VectorHandle               handle,
                                                    ConnectionHandle           key,
                                                    PairQuantityQuantityHandle value);
void                        Vector_insert(VectorHandle               handle,
                                          ConnectionHandle           key,
                                          PairQuantityQuantityHandle value);
PairQuantityQuantityHandle Vector_at(VectorHandle handle, ConnectionHandle key);
void                 Vector_erase(VectorHandle handle, ConnectionHandle key);
size_t               Vector_size(VectorHandle handle);
bool                 Vector_empty(VectorHandle handle);
void                 Vector_clear(VectorHandle handle);
bool                 Vector_contains(VectorHandle handle, ConnectionHandle key);
ListConnectionHandle Vector_keys(VectorHandle handle);
ListPairQuantityQuantityHandle               Vector_values(VectorHandle handle);
ListPairConnectionPairQuantityQuantityHandle Vector_items(VectorHandle handle);
VectorHandle Vector_addition(VectorHandle handle, VectorHandle other);
VectorHandle Vector_subtraction(VectorHandle handle, VectorHandle other);
VectorHandle Vector_double_multiplication(VectorHandle handle, double scalar);
VectorHandle Vector_int_multiplication(VectorHandle handle, int scalar);
VectorHandle Vector_double_division(VectorHandle handle, double scalar);
VectorHandle Vector_int_division(VectorHandle handle, double scalar);
VectorHandle Vector_negation(VectorHandle handle);
VectorHandle Vector_update_start_from_states(VectorHandle              handle,
                                             DeviceVoltageStatesHandle state);
VectorHandle Vector_translate_doubles(VectorHandle              handle,
                                      MapConnectionDoubleHandle point,
                                      SymbolUnitHandle          unit);
VectorHandle Vector_translate_quantities(VectorHandle                handle,
                                         MapConnectionQuantityHandle point);
VectorHandle Vector_translate(VectorHandle handle, PointHandle point);
VectorHandle Vector_translate_to_origin(VectorHandle handle);
VectorHandle Vector_double_extend(VectorHandle handle, double extension);
VectorHandle Vector_int_extend(VectorHandle handle, int extension);
VectorHandle Vector_double_shrink(VectorHandle handle, double extension);
VectorHandle Vector_int_shrink(VectorHandle handle, int extension);
VectorHandle Vector_unit_vector(VectorHandle handle);
VectorHandle Vector_normalize(VectorHandle handle);
VectorHandle Vector_project(VectorHandle handle, VectorHandle other);
void         Vector_update_unit(VectorHandle handle, SymbolUnitHandle unit);
bool         Vector_equal(VectorHandle a, VectorHandle b);
bool         Vector_not_equal(VectorHandle a, VectorHandle b);

// Serialization (from Song)
StringHandle Vector_to_json_string(VectorHandle handle);
VectorHandle Vector_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
