#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/names/Gname_c_api.h"
#include "falcon_core/physics/config/core/Group_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairGnameGroupHandle;
// Function declarations

/* AUTO-DOC from cpp: PairGnameGroup_create | falcon_core::generic::Pair::create */
/**
 * @brief (from C++: falcon_core::generic::Pair::create)
 * @brief Store a pair of values.
 * @param first The first value.
 * @param second The second value.
 */
PairGnameGroupHandle PairGnameGroup_create(GnameHandle first, GroupHandle second);
void PairGnameGroup_destroy(PairGnameGroupHandle handle);
/* AUTO-DOC from cpp: PairGnameGroup_first | falcon_core::generic::Pair::first */
/**
 * @brief (from C++: falcon_core::generic::Pair::first)
 * @brief Get the stored first value.
 */
GnameHandle PairGnameGroup_first(PairGnameGroupHandle handle);
/* AUTO-DOC from cpp: PairGnameGroup_second | falcon_core::generic::Pair::second */
/**
 * @brief (from C++: falcon_core::generic::Pair::second)
 * @brief Get the stored second value.
 */
GroupHandle PairGnameGroup_second(PairGnameGroupHandle handle);
bool PairGnameGroup_equal(PairGnameGroupHandle a, PairGnameGroupHandle b);
bool PairGnameGroup_not_equal(PairGnameGroupHandle a, PairGnameGroupHandle b);
// Serialization (from Song)
/* AUTO-DOC from cpp: PairGnameGroup_to_json_string | falcon_core::generic::Song::to_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::to_json_string)
 * @brief Serialize this object to a JSON string.
 */
StringHandle      PairGnameGroup_to_json_string(PairGnameGroupHandle handle);
/* AUTO-DOC from cpp: PairGnameGroup_from_json_string | falcon_core::generic::Song::from_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::from_json_string)
 * @brief Deserialize an object from a JSON string.
 * @return std::shared_ptr<Song> (actually the derived type)
 */
PairGnameGroupHandle PairGnameGroup_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif