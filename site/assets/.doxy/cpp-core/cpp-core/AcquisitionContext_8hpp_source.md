

# File AcquisitionContext.hpp

[**File List**](files.md) **>** [**autotuner\_interfaces**](dir_f103c4a8c56717e1b25b9ff095326f77.md) **>** [**contexts**](dir_78197d33e09341695ca03f828462ffe3.md) **>** [**AcquisitionContext.hpp**](AcquisitionContext_8hpp.md)

[Go to the documentation of this file](AcquisitionContext_8hpp.md)


```C++
#pragma once

#include "falcon_core/autotuner_interfaces/contexts/BaseContext.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace contexts {

class AcquisitionContext : public BaseContext {
  physics::units::SymbolUnitSP    _units;
  mutable std::shared_timed_mutex _mu_units;

 protected:
  friend class cereal::access;
  AcquisitionContext();
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_u(_mu_units);
    ar(cereal::base_class<BaseContext>(this), _units);
  }

 public:
  AcquisitionContext(const AcquisitionContext& other);
  AcquisitionContext& operator=(const AcquisitionContext& other);
  AcquisitionContext(
      const physics::device_structures::ConnectionSP& connection,
      const instrument_interfaces::names::Instrument& instrument_type,
      const physics::units::SymbolUnitSP&             units);
  AcquisitionContext(
      const instrument_interfaces::names::InstrumentPortSP& port);
  static std::shared_ptr<AcquisitionContext> from_context(
      const BaseContextSP&                measurement_context,
      const physics::units::SymbolUnitSP& unit);
  const physics::units::SymbolUnitSP units() const;

  const std::shared_ptr<AcquisitionContext> operator/(
      const physics::units::SymbolUnitSP& other) const;
  const std::shared_ptr<AcquisitionContext> operator/(
      const std::shared_ptr<AcquisitionContext>& other) const;
  const bool match_connection(
      physics::device_structures::ConnectionSP other) const;
  const bool match_instrument_type(
      instrument_interfaces::names::Instrument other) const;
  bool operator==(const AcquisitionContext& other) const;
  bool operator!=(const AcquisitionContext& other) const;
};
using AcquisitionContextSP = std::shared_ptr<AcquisitionContext>;
}  // namespace contexts
}  // namespace autotuner_interfaces
}  // namespace falcon_core
```


