#pragma once

#include "falcon_core/BaseDiscretizer.hpp"

namespace falcon_core {

class CartesianDiscretizer : public BaseDiscretizer {
public:
    using BaseDiscretizer::BaseDiscretizer;

    nlohmann::json to_json() const override {
        nlohmann::json j = BaseDiscretizer::to_json();
        add_metadata(j, "falcon_core.math.discretizers.cartesian_discretizer", "CartesianDiscretizer");
        return j;
    }
};

} // namespace falcon_core
