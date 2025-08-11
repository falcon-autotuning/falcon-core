#include "falcon_core/Time.hpp"
#include <chrono>

namespace falcon_core {

Time::Time() {}

// Returns seconds since unix epoch.
int Time::time() const {
    auto now = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();
}

} // namespace falcon_core
