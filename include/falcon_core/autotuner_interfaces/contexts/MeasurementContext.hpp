#pragma once

#include "falcon_core/autotuner_interfaces/contexts/BaseContext.hpp"
#include "falcon_core/instrument_interfaces/Instrument.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace contexts {

class MeasurementContext : public BaseContext {
  physics::units::SymbolUnitSP _unit;

  template <class Archive>
  void serialize(Archive& ar);

 protected:
  friend class cereal::access;
  MeasurementContext();

 public:
  /**
   * @brief Constructs the measurement context.
   * @param connection The device connection.
   * @param instrument_type The type of instrument.
   */
  MeasurementContext(physics::device_structures::BaseConnectionSP connection,
                     instrument_interfaces::Instrument instrument_type);

  /**
   * @brief Constructs a MeasururementContext from an AcquisitionContext.
   * @param acquisition_context The acquisition context.
   */
  MeasurementContext(BaseContextSP acquisition_context);
};
using MeasurementContextSP = std::shared_ptr<MeasurementContext>;
}  // namespace contexts
}  // namespace autotuner_interfaces
}  // namespace falcon_core
