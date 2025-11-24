#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairDoubleDoubleHandle;
// Function declarations

/* AUTO-DOC from cpp: PairDoubleDouble_create | falcon_core::generic::Pair::create */
/**
 * @brief (from C++: falcon_core::generic::Pair::create)
 * @brief Store a pair of values.
 * @param first The first value.
 * @param second The second value.
 */
PairDoubleDoubleHandle PairDoubleDouble_create(double first, double second);
void PairDoubleDouble_destroy(PairDoubleDoubleHandle handle);
/* AUTO-DOC from cpp: PairDoubleDouble_first | falcon_core::generic::Pair::first */
/**
 * @brief (from C++: falcon_core::generic::Pair::first)
 * @brief Get the stored first value.
 */
double PairDoubleDouble_first(PairDoubleDoubleHandle handle);
/* AUTO-DOC from cpp: PairDoubleDouble_second | falcon_core::generic::Pair::second */
/**
 * @brief (from C++: falcon_core::generic::Pair::second)
 * @brief Get the stored second value.
 */
double PairDoubleDouble_second(PairDoubleDoubleHandle handle);
bool PairDoubleDouble_equal(PairDoubleDoubleHandle a, PairDoubleDoubleHandle b);
bool PairDoubleDouble_not_equal(PairDoubleDoubleHandle a, PairDoubleDoubleHandle b);
// Serialization (from Song)
/* AUTO-DOC from cpp: PairDoubleDouble_to_json_string | falcon_core::generic::Song::to_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::to_json_string)
 * @brief Serialize this object to a JSON string.
 */
StringHandle      PairDoubleDouble_to_json_string(PairDoubleDoubleHandle handle);
/* AUTO-DOC from cpp: PairDoubleDouble_from_json_string | falcon_core::generic::Song::from_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::from_json_string)
 * @brief Deserialize an object from a JSON string.
 * @return std::shared_ptr<Song> (actually the derived type)
 */
PairDoubleDoubleHandle PairDoubleDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif