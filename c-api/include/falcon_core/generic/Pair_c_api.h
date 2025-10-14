#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include "falcon_core/physics/device_structures/Connection_c_api.h"

// Forward declarations for opaque handles
typedef void* PairIntIntHandle;
typedef void* PairFloatFloatHandle;
typedef void* PairIntFloatHandle;
typedef void* PairConnectionConnectionHandle;
typedef void* PairConnectionFloatHandle;

// Function declarations

PairIntIntHandle PairIntInt_create(int first, int second);
void PairIntInt_destroy(PairIntIntHandle handle);
int PairIntInt_first(PairIntIntHandle handle);
int PairIntInt_second(PairIntIntHandle handle);
bool PairIntInt_equal(PairIntIntHandle a, PairIntIntHandle b);

PairFloatFloatHandle PairFloatFloat_create(float first, float second);
void PairFloatFloat_destroy(PairFloatFloatHandle handle);
float PairFloatFloat_first(PairFloatFloatHandle handle);
float PairFloatFloat_second(PairFloatFloatHandle handle);
bool PairFloatFloat_equal(PairFloatFloatHandle a, PairFloatFloatHandle b);

PairIntFloatHandle PairIntFloat_create(int first, float second);
void PairIntFloat_destroy(PairIntFloatHandle handle);
int PairIntFloat_first(PairIntFloatHandle handle);
float PairIntFloat_second(PairIntFloatHandle handle);
bool PairIntFloat_equal(PairIntFloatHandle a, PairIntFloatHandle b);

PairConnectionConnectionHandle PairConnectionConnection_create(ConnectionHandle first, ConnectionHandle second);
void PairConnectionConnection_destroy(PairConnectionConnectionHandle handle);
ConnectionHandle PairConnectionConnection_first(PairConnectionConnectionHandle handle);
ConnectionHandle PairConnectionConnection_second(PairConnectionConnectionHandle handle);
bool PairConnectionConnection_equal(PairConnectionConnectionHandle a, PairConnectionConnectionHandle b);

PairConnectionFloatHandle PairConnectionFloat_create(ConnectionHandle first, float second);
void PairConnectionFloat_destroy(PairConnectionFloatHandle handle);
ConnectionHandle PairConnectionFloat_first(PairConnectionFloatHandle handle);
float PairConnectionFloat_second(PairConnectionFloatHandle handle);
bool PairConnectionFloat_equal(PairConnectionFloatHandle a, PairConnectionFloatHandle b);

#ifdef __cplusplus
}
#endif
