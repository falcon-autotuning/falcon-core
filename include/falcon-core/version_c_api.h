#ifndef FALCON_CORE_C_API_VERSION_H
#define FALCON_CORE_C_API_VERSION_H

#include "export_c_api.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Get the version string for the falcon core C API
 * @return Version string in format "x.y.z" or "x.y.z-tag"
 */
FALCON_CORE_C_API const char* falcon_core_c_api_get_version(void);

/**
 * Get the Git commit hash if available
 * @return Git commit hash or "unknown" if not available
 */
FALCON_CORE_C_API const char* falcon_core_c_api_get_git_commit(void);

/**
 * Get the Git tag if available
 * @return Git tag or empty string if not available
 */
FALCON_CORE_C_API const char* falcon_core_c_api_get_git_tag(void);

/**
 * Get the full version string including commit info
 * @return Full version string with git info if available
 */
FALCON_CORE_C_API const char* falcon_core_c_api_get_full_version(void);

/**
 * Get the underlying C++ core version
 * @return C++ core version string
 */
FALCON_CORE_C_API const char* falcon_core_cpp_get_version(void);

/**
 * Get the full underlying C++ core version with commit info
 * @return C++ core full version string
 */
FALCON_CORE_C_API const char* falcon_core_cpp_get_full_version(void);

#ifdef __cplusplus
}
#endif

#endif /* FALCON_CORE_C_API_VERSION_H */