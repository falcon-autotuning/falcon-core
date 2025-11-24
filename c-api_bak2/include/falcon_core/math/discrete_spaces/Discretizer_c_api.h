#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/domains/Domain_c_api.h"
typedef void* DiscretizerHandle;

// Constructors
DiscretizerHandle Discretizer_create_cartesian_discretizer(double delta);
DiscretizerHandle Discretizer_create_polar_discretizer(double delta);

// Destructor
void Discretizer_destroy(DiscretizerHandle handle);

// Methods
double       Discretizer_delta(DiscretizerHandle handle);
void         Discretizer_set_delta(DiscretizerHandle handle, double delta);
DomainHandle Discretizer_domain(DiscretizerHandle handle);
/* AUTO-DOC from cpp: Discretizer_is_cartesian | falcon_core::math::discrete_spaces::Discretizer::is_cartesian */
/**
 * @brief (from C++: falcon_core::math::discrete_spaces::Discretizer::is_cartesian)
 * @brief Checks if the current Discretizer is Cartesian.
 */
bool         Discretizer_is_cartesian(DiscretizerHandle handle);
/* AUTO-DOC from cpp: Discretizer_is_polar | falcon_core::math::discrete_spaces::Discretizer::is_polar */
/**
 * @brief (from C++: falcon_core::math::discrete_spaces::Discretizer::is_polar)
 * @brief Checks if the current Discretizer is Polar.
 */
bool         Discretizer_is_polar(DiscretizerHandle handle);
bool         Discretizer_equal(DiscretizerHandle a, DiscretizerHandle b);
bool         Discretizer_not_equal(DiscretizerHandle a, DiscretizerHandle b);

// Serialization (from Song)
StringHandle      Discretizer_to_json_string(DiscretizerHandle handle);
DiscretizerHandle Discretizer_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
