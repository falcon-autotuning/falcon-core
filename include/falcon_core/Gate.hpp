#pragma once

#include "falcon_core/BaseConnection.hpp"

namespace falcon_core {

class Gate : public BaseConnection {
public:
    using BaseConnection::BaseConnection;

    nlohmann::json to_json() const override {
        nlohmann::json j = BaseConnection::to_json();
        add_metadata(j, "falcon_core.physics.device_structures.gate", "Gate");
        return j;
    }
};

} // namespace falcon_core
