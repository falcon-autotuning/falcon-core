#pragma once
#include <string>
#include "export.h"

namespace falcon_core {

// Legacy constants for backward compatibility
constexpr const char *VERSION = "1.0.0";

/**
 * Get the version string for the falcon core C++ library
 * @return Version string in format "x.y.z" or "x.y.z-tag"
 */
FALCON_CORE_CPP_API std::string get_version();

/**
 * Get the Git commit hash if available
 * @return Git commit hash or "unknown" if not available
 */
FALCON_CORE_CPP_API std::string get_git_commit();

/**
 * Get the Git tag if available
 * @return Git tag or empty string if not available
 */
FALCON_CORE_CPP_API std::string get_git_tag();

/**
 * Get the full version string including commit info
 * @return Full version string with git info if available
 */
FALCON_CORE_CPP_API std::string get_full_version();

} // namespace falcon_core