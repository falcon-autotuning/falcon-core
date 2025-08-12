#pragma once

#include "falcon_core/Jsonable.hpp"
#include "falcon_core/InterpretationContext.hpp"
#include <map>
#include <memory>
#include <nlohmann/json.hpp>

namespace falcon_core {

template<typename T>
class InterpretationContainer : public Jsonable {
public:
    using key_type = std::shared_ptr<InterpretationContext>;
    using mapped_type = T;
    using container_type = std::map<key_type, mapped_type>;

    InterpretationContainer() = default;

    void insert(const key_type& context, const mapped_type& value) {
        _container[context] = value;
    }

    const mapped_type& at(const key_type& context) const {
        return _container.at(context);
    }

    nlohmann::json to_json() const override {
        nlohmann::json j;
        add_metadata(j, "falcon_core.autotuner_interfaces.interpretations.interpretation_container", "InterpretationContainer");
        // Serialization is complex because keys are objects.
        // This is a placeholder.
        j["container_size"] = _container.size();
        return j;
    }

    size_t hash() const override {
        // Placeholder hash
        return _container.size();
    }

private:
    container_type _container;
};

} // namespace falcon_core
