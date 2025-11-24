#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairSizeTSizeTHandle;
// Function declarations

/* AUTO-DOC from cpp: PairSizeTSizeT_create | falcon_core::generic::Pair::create */
/**
 * @brief (from C++: falcon_core::generic::Pair::create)
 * @brief Store a pair of values.
 * @param first The first value.
 * @param second The second value.
 */
PairSizeTSizeTHandle PairSizeTSizeT_create(size_t first, size_t second);
void PairSizeTSizeT_destroy(PairSizeTSizeTHandle handle);
/* AUTO-DOC from cpp: PairSizeTSizeT_first | falcon_core::generic::Pair::first */
/**
 * @brief (from C++: falcon_core::generic::Pair::first)
 * @brief Get the stored first value.
 */
size_t PairSizeTSizeT_first(PairSizeTSizeTHandle handle);
/* AUTO-DOC from cpp: PairSizeTSizeT_second | falcon_core::generic::Pair::second */
/**
 * @brief (from C++: falcon_core::generic::Pair::second)
 * @brief Get the stored second value.
 */
size_t PairSizeTSizeT_second(PairSizeTSizeTHandle handle);
bool PairSizeTSizeT_equal(PairSizeTSizeTHandle a, PairSizeTSizeTHandle b);
bool PairSizeTSizeT_not_equal(PairSizeTSizeTHandle a, PairSizeTSizeTHandle b);
// Serialization (from Song)
/* AUTO-DOC from cpp: PairSizeTSizeT_to_json_string | falcon_core::generic::Song::to_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::to_json_string)
 * @brief Serialize this object to a JSON string.
 */
StringHandle      PairSizeTSizeT_to_json_string(PairSizeTSizeTHandle handle);
/* AUTO-DOC from cpp: PairSizeTSizeT_from_json_string | falcon_core::generic::Song::from_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::from_json_string)
 * @brief Deserialize an object from a JSON string.
 * @return std::shared_ptr<Song> (actually the derived type)
 */
PairSizeTSizeTHandle PairSizeTSizeT_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif