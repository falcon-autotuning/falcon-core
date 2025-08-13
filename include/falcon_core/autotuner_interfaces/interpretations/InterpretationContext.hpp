#pragma once

#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext.hpp"
#include "falcon_core/generic/Song.hpp"
#include "falcon_core/math/Axes.hpp"

namespace falcon_core
{
namespace autotuner_interfaces
{
namespace interpretations
{

// This is a simplified placeholder for InterpretationContext.
// A full implementation would depend on MeasurementContext.
class InterpretationContext : public generic::Song
{
public:
  InterpretationContext (
      std::shared_ptr<
          math::Axes<autotuner_interfaces::contexts::MeasurementContext>>
          independent_variables)
      : _independent_variables (std::move (independent_variables))
  {
  }

  nlohmann::json
  to_json () const override
  {
    nlohmann::json j;
    add_metadata (j,
                  "falcon_core.autotuner_interfaces.interpretations."
                  "interpretation_context",
                  "InterpretationContext");
    j["_independent_variables"] = _independent_variables->to_json ();
    return j;
  }

  size_t
  hash () const override
  {
    return _independent_variables ? _independent_variables->hash () : 0;
  }

private:
  std::shared_ptr<
      math::Axes<autotuner_interfaces::contexts::MeasurementContext>>
      _independent_variables;
};
}
}
} // namespace falcon_core
