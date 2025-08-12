#pragma once

#include "falcon_core/PortTransform.hpp"
#include "falcon_core/Identity.hpp"
#include <memory>

namespace falcon_core {

class IdentityTransform : public PortTransform {
public:
    IdentityTransform() : PortTransform(std::make_shared<Identity>()) {}

    nlohmann::json to_json() const override {
        nlohmann::json j = PortTransform::to_json();
        add_metadata(j, "falcon_core.physics.transforms.identity_transform", "IdentityTransform");
        return j;
    }
};

} // namespace falcon_core
