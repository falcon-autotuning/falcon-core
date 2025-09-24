#pragma once

#include "falcon_core/autotuner_interfaces/contexts/BaseContext.hpp"
#include "falcon_core/instrument_interfaces/names/Instrument.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core::autotuner_interfaces::contexts {

class MeasurementContext : public contexts::BaseContext {
  physics::units::SymbolUnitSP _unit;

 protected:
  friend class cereal::access;
  MeasurementContext();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<contexts::BaseContext>(this));
  }

 public:
  /**
   * @brief Constructs the measurement context.
   * @param connection The device connection.
   * @param instrument_type The type of instrument.
   */
  MeasurementContext(
      const physics::device_structures::ConnectionSP& connection,
      const instrument_interfaces::names::Instrument& instrument_type);

  /**
   * @brief Constructs a MeasururementContext from an AcquisitionContext.
   * @param acquisition_context The acquisition context.
   */
  MeasurementContext(const contexts::BaseContextSP& acquisition_context);
};
using MeasurementContextSP = std::shared_ptr<MeasurementContext>;
}  // namespace falcon_core::autotuner_interfaces::contexts
