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
// Serialization (from Song)
const char*      PairIntInt_to_json_string(PairIntIntHandle handle);
PairIntIntHandle PairIntInt_from_json_string(const char* json);

#ifdef __cplusplus
}
#endif