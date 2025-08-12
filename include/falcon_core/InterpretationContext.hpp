#pragma once

#include "falcon_core/Jsonable.hpp"
#include "falcon_core/Axes.hpp"
#include "falcon_core/Domain.hpp" // Using Domain as placeholder for MeasurementContext

namespace falcon_core {

// This is a simplified placeholder for InterpretationContext.
// A full implementation would depend on MeasurementContext.
class InterpretationContext : public Jsonable {
public:
    InterpretationContext(std::shared_ptr<Axes<Domain>> independent_variables)
        : _independent_variables(std::move(independent_variables)) {}

    nlohmann::json to_json() const override {
        nlohmann::json j;
        add_metadata(j, "falcon_core.autotuner_interfaces.interpretations.interpretation_context", "InterpretationContext");
        j["_independent_variables"] = _independent_variables->to_json();
        return j;
    }

    size_t hash() const override {
        return _independent_variables ? _independent_variables->hash() : 0;
    }

private:
    std::shared_ptr<Axes<Domain>> _independent_variables;
};

} // namespace falcon_core
