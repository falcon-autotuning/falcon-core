

# File InterpretationContext.hpp

[**File List**](files.md) **>** [**autotuner\_interfaces**](dir_f103c4a8c56717e1b25b9ff095326f77.md) **>** [**interpretations**](dir_92f2bf5775a05c88a2ac27aeb91ddc9f.md) **>** [**InterpretationContext.hpp**](InterpretationContext_8hpp.md)

[Go to the documentation of this file](InterpretationContext_8hpp.md)


```C++
#pragma once

#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext.hpp"
#include "falcon_core/math/Axes.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace interpretations {

class InterpretationContext : public generic::Song {
  math::AxesSP<autotuner_interfaces::contexts::MeasurementContext>
      _independent_variables;
  generic::ListSP<autotuner_interfaces::contexts::MeasurementContext>
                                  _dependent_variables;
  physics::units::SymbolUnitSP    _unit;
  mutable std::shared_timed_mutex _mu_independent_variables;
  mutable std::shared_timed_mutex _mu_dependent_variables;
  mutable std::shared_timed_mutex _mu_unit;

 public:
  InterpretationContext(const InterpretationContext& other);
  InterpretationContext& operator=(const InterpretationContext& other);
  InterpretationContext(
      const math::AxesSP<autotuner_interfaces::contexts::MeasurementContext>&
          independent_variables,
      const generic::ListSP<autotuner_interfaces::contexts::MeasurementContext>&
                                          dependent_variables,
      const physics::units::SymbolUnitSP& unit);
  const math::AxesSP<autotuner_interfaces::contexts::MeasurementContext>
  independent_variables() const;
  const generic::ListSP<autotuner_interfaces::contexts::MeasurementContext>
  dependent_variables() const;
  const physics::units::SymbolUnitSP unit() const;
  const int dimension() const;
  void add_dependent_variable(
      const autotuner_interfaces::contexts::MeasurementContextSP& variable);
  void replace_dependent_variable(
      int                                                         index,
      const autotuner_interfaces::contexts::MeasurementContextSP& variable);
  const contexts::MeasurementContextSP get_independent_variable(
      int index) const;
  const std::shared_ptr<InterpretationContext> with_unit(
      physics::units::SymbolUnitSP unit) const;
  bool operator==(const InterpretationContext& other) const;
  bool operator!=(const InterpretationContext& other) const;

 protected:
  friend class cereal::access;
  InterpretationContext();
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_iv(_mu_independent_variables,
                                                      std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_dv(_mu_dependent_variables,
                                                      std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_u(_mu_unit, std::defer_lock);
    std::lock(lock_iv, lock_dv, lock_u);
    ar(cereal::base_class<generic::Song>(this),
       _independent_variables,
       _dependent_variables,
       _unit);
  }
};
using InterpretationContextSP = std::shared_ptr<InterpretationContext>;
}  // namespace interpretations
}  // namespace autotuner_interfaces
}  // namespace falcon_core
```


