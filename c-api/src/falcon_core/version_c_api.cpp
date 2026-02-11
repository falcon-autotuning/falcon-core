#include <falcon_core/version_c_api.h>
#include <falcon_core/version.hpp>
#include <string>
#include <cstring>

// These values will be replaced by CMake during build
#ifndef FALCON_CORE_C_API_VERSION
#define FALCON_CORE_C_API_VERSION "unknown"
#endif

#ifndef FALCON_CORE_C_API_GIT_COMMIT
#define FALCON_CORE_C_API_GIT_COMMIT "unknown"
#endif

#ifndef FALCON_CORE_C_API_GIT_TAG
#define FALCON_CORE_C_API_GIT_TAG ""
#endif

extern "C" {

// Static buffers for C string returns (thread-safe approach would use thread-local)
static char version_buffer[256];
static char git_commit_buffer[256];
static char git_tag_buffer[256];
static char full_version_buffer[512];
static char cpp_version_buffer[256];
static char cpp_full_version_buffer[512];

FALCON_CORE_C_API const char* falcon_core_c_api_get_version(void) {
    std::string version = FALCON_CORE_C_API_VERSION;
    std::string tag = FALCON_CORE_C_API_GIT_TAG;
    
    // If we have a git tag and it's different from the version, append it
    if (!tag.empty() && tag != version && tag != std::string("v") + version) {
        version += "-" + tag;
    }
    
    strncpy(version_buffer, version.c_str(), sizeof(version_buffer) - 1);
    version_buffer[sizeof(version_buffer) - 1] = '\0';
    return version_buffer;
}

FALCON_CORE_C_API const char* falcon_core_c_api_get_git_commit(void) {
    strncpy(git_commit_buffer, FALCON_CORE_C_API_GIT_COMMIT, sizeof(git_commit_buffer) - 1);
    git_commit_buffer[sizeof(git_commit_buffer) - 1] = '\0';
    return git_commit_buffer;
}

FALCON_CORE_C_API const char* falcon_core_c_api_get_git_tag(void) {
    strncpy(git_tag_buffer, FALCON_CORE_C_API_GIT_TAG, sizeof(git_tag_buffer) - 1);
    git_tag_buffer[sizeof(git_tag_buffer) - 1] = '\0';
    return git_tag_buffer;
}

FALCON_CORE_C_API const char* falcon_core_c_api_get_full_version(void) {
    std::string version = falcon_core_c_api_get_version();
    std::string commit = FALCON_CORE_C_API_GIT_COMMIT;
    
    if (commit != "unknown" && !commit.empty()) {
        version += " (commit " + commit.substr(0, 7) + ")";
    }
    
    strncpy(full_version_buffer, version.c_str(), sizeof(full_version_buffer) - 1);
    full_version_buffer[sizeof(full_version_buffer) - 1] = '\0';
    return full_version_buffer;
}

FALCON_CORE_C_API const char* falcon_core_cpp_get_version(void) {
    std::string version = falcon_core::get_version();
    strncpy(cpp_version_buffer, version.c_str(), sizeof(cpp_version_buffer) - 1);
    cpp_version_buffer[sizeof(cpp_version_buffer) - 1] = '\0';
    return cpp_version_buffer;
}

FALCON_CORE_C_API const char* falcon_core_cpp_get_full_version(void) {
    std::string version = falcon_core::get_full_version();
    strncpy(cpp_full_version_buffer, version.c_str(), sizeof(cpp_full_version_buffer) - 1);
    cpp_full_version_buffer[sizeof(cpp_full_version_buffer) - 1] = '\0';
    return cpp_full_version_buffer;
}

} // extern "C"