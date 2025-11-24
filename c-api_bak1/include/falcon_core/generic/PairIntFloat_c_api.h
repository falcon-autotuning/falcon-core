#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairIntFloatHandle;
// Function declarations

/* AUTO-DOC from cpp: PairIntFloat_create | falcon_core::generic::Pair::create */
/**
 * @brief (from C++: falcon_core::generic::Pair::create)
 * @brief Store a pair of values.
 * @param first The first value.
 * @param second The second value.
 */
PairIntFloatHandle PairIntFloat_create(int first, float second);
void PairIntFloat_destroy(PairIntFloatHandle handle);
/* AUTO-DOC from cpp: PairIntFloat_first | falcon_core::generic::Pair::first */
/**
 * @brief (from C++: falcon_core::generic::Pair::first)
 * @brief Get the stored first value.
 */
int PairIntFloat_first(PairIntFloatHandle handle);
/* AUTO-DOC from cpp: PairIntFloat_second | falcon_core::generic::Pair::second */
/**
 * @brief (from C++: falcon_core::generic::Pair::second)
 * @brief Get the stored second value.
 */
float PairIntFloat_second(PairIntFloatHandle handle);
bool PairIntFloat_equal(PairIntFloatHandle a, PairIntFloatHandle b);
bool PairIntFloat_not_equal(PairIntFloatHandle a, PairIntFloatHandle b);
// Serialization (from Song)
/* AUTO-DOC from cpp: PairIntFloat_to_json_string | falcon_core::generic::Song::to_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::to_json_string)
 * @brief Serialize this object to a JSON string.
 */
StringHandle      PairIntFloat_to_json_string(PairIntFloatHandle handle);
/* AUTO-DOC from cpp: PairIntFloat_from_json_string | falcon_core::generic::Song::from_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::from_json_string)
 * @brief Deserialize an object from a JSON string.
 * @return std::shared_ptr<Song> (actually the derived type)
 */
PairIntFloatHandle PairIntFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif