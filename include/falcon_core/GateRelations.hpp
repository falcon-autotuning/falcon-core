#pragma once

#include "falcon_core/Jsonable.hpp"
#include "falcon_core/Gate.hpp"
#include "falcon_core/BaseConnections.hpp"
#include <map>
#include <memory>

namespace falcon_core {

// Using BaseConnections<Gate> as a placeholder for the value type 'Gates'
using Gates = BaseConnections<Gate>;

// Using BaseConnections<Gate> as a placeholder for the value type 'Gates'
using Gates = BaseConnections<Gate>;

struct GatePtrCompare {
    bool operator()(const std::shared_ptr<Gate>& lhs, const std::shared_ptr<Gate>& rhs) const {
        if (!lhs || !rhs) return !lhs && rhs; // nulls sort first
        return lhs->name() < rhs->name();
    }
};

class GateRelations : public Jsonable {
public:
    using key_type = std::shared_ptr<Gate>;
    using mapped_type = std::shared_ptr<Gates>;
    using container_type = std::map<key_type, mapped_type, GatePtrCompare>;

    GateRelations() = default;

    void insert(const key_type& key, const mapped_type& value) {
        _relations[key] = value;
    }

    nlohmann::json to_json() const override {
        nlohmann::json j;
        add_metadata(j, "falcon_core.physics.device_structures.gate_relations", "GateRelations");
        j["container_size"] = _relations.size(); // Placeholder serialization
        return j;
    }

    size_t hash() const override {
        return _relations.size(); // Placeholder hash
    }

private:
    container_type _relations;
};

} // namespace falcon_core
