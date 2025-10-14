#pragma once
#ifdef __cplusplus
    extern "C" {
#endif

// Forward declarations for opaque handles
typedef void* PairIntFloatHandle;
// Function declarations

PairIntFloatHandle PairIntFloat_create(int first, float second);
void PairIntFloat_destroy(PairIntFloatHandle handle);
int PairIntFloat_first(PairIntFloatHandle handle);
float PairIntFloat_second(PairIntFloatHandle handle);
bool PairIntFloat_equal(PairIntFloatHandle a, PairIntFloatHandle b);
#ifdef __cplusplus
}
#endif