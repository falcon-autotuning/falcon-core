#pragma once

#include "falcon_core/Jsonable.hpp"

namespace falcon_core {

class IncreasingAlignment : public Jsonable {
public:
    IncreasingAlignment() = default;

    nlohmann::json to_json() const override {
        nlohmann::json j;
        add_metadata(j, "falcon_core.math.arrays.increasing_alignment", "IncreasingAlignment");
        return j;
    }

    size_t hash() const override {
        // A class with no data members can return a constant hash.
        return 1;
    }
};

} // namespace falcon_core
