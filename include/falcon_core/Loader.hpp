#pragma once

#include "falcon_core/Jsonable.hpp"
#include "falcon_core/StandardConfigConnections.hpp"
#include <nlohmann/json.hpp>
#include <memory>

namespace falcon_core {

// This is a placeholder for the Loader. A full implementation would require
// a factory pattern to deserialize from JSON into the correct C++ types.
class Loader : public Jsonable {
public:
    Loader(std::shared_ptr<StandardConfigConnections> config) : _config(std::move(config)) {}

    nlohmann::json to_json() const override {
        nlohmann::json j;
        add_metadata(j, "falcon_core.physics.config.loader", "Loader");
        j["_config"] = _config->to_json();
        return j;
    }

    size_t hash() const override {
        return _config ? _config->hash() : 0;
    }

private:
    std::shared_ptr<StandardConfigConnections> _config;
};

} // namespace falcon_core
