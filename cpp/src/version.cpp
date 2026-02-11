#include <falcon_core/version.hpp>

namespace falcon_core {

// These values will be replaced by CMake during build
#ifndef FALCON_CORE_VERSION
#define FALCON_CORE_VERSION "unknown"
#endif

#ifndef FALCON_CORE_GIT_COMMIT
#define FALCON_CORE_GIT_COMMIT "unknown"
#endif

#ifndef FALCON_CORE_GIT_TAG
#define FALCON_CORE_GIT_TAG ""
#endif

FALCON_CORE_CPP_API std::string get_version() {
    std::string version = FALCON_CORE_VERSION;
    std::string tag = FALCON_CORE_GIT_TAG;
    
    // If we have a git tag and it's different from the version, append it
    if (!tag.empty() && tag != version && tag != std::string("v") + version) {
        version += "-" + tag;
    }
    
    return version;
}

FALCON_CORE_CPP_API std::string get_git_commit() {
    return FALCON_CORE_GIT_COMMIT;
}

FALCON_CORE_CPP_API std::string get_git_tag() {
    return FALCON_CORE_GIT_TAG;
}

FALCON_CORE_CPP_API std::string get_full_version() {
    std::string version = get_version();
    std::string commit = get_git_commit();
    
    if (commit != "unknown" && !commit.empty()) {
        version += " (commit " + commit.substr(0, 7) + ")";
    }
    
    return version;
}

} // namespace falcon_core