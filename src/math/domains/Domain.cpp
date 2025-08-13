#include "falcon_core/math/domains/Domain.hpp"
#include "falcon_core/constants.hpp"
#include <functional>

namespace falcon_core {

nlohmann::json Domain::to_json() const {
    nlohmann::json j;
    add_metadata(j, "falcon_core.math.domains.domain", "Domain");
    j["_min"] = _min;
    j["_max"] = _max;
    return j;
}

size_t Domain::hash() const {
    size_t h1 = std::hash<double>{}(_min);
    size_t h2 = std::hash<double>{}(_max);
    return h1 ^ (h2 << 1);
}

} // namespace falcon_core
