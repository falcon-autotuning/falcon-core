#pragma once
#ifdef __cplusplus
    extern "C" {
#endif

// Forward declarations for opaque handles
typedef void* PairIntIntHandle;
// Function declarations

PairIntIntHandle PairIntInt_create(int first, int second);
void PairIntInt_destroy(PairIntIntHandle handle);
int PairIntInt_first(PairIntIntHandle handle);
int PairIntInt_second(PairIntIntHandle handle);
bool PairIntInt_equal(PairIntIntHandle a, PairIntIntHandle b);
#ifdef __cplusplus
}
#endif