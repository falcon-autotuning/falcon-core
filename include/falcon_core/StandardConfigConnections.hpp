#pragma once

#include "falcon_core/Jsonable.hpp"
#include "falcon_core/BaseConnections.hpp"
#include "falcon_core/Ohmic.hpp"
#include "falcon_core/Gate.hpp"
#include <memory>

namespace falcon_core {

class StandardConfigConnections : public Jsonable {
public:
    StandardConfigConnections(
        std::shared_ptr<BaseConnections<Ohmic>> ohmics,
        std::shared_ptr<BaseConnections<Gate>> gates
    ) : _ohmics(std::move(ohmics)), _gates(std::move(gates)) {}

    const std::shared_ptr<BaseConnections<Ohmic>>& get_ohmics() const { return _ohmics; }
    const std::shared_ptr<BaseConnections<Gate>>& get_gates() const { return _gates; }

    nlohmann::json to_json() const override {
        nlohmann::json j;
        add_metadata(j, "falcon_core.physics.config.core.standard_config_connections", "StandardConfigConnections");
        j["_ohmics"] = _ohmics->to_json();
        j["_gates"] = _gates->to_json();
        return j;
    }

    size_t hash() const override {
        size_t h1 = _ohmics ? _ohmics->hash() : 0;
        size_t h2 = _gates ? _gates->hash() : 0;
        return h1 ^ (h2 << 1);
    }

private:
    std::shared_ptr<BaseConnections<Ohmic>> _ohmics;
    std::shared_ptr<BaseConnections<Gate>> _gates;
};

} // namespace falcon_core
