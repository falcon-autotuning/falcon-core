#pragma once

#include "falcon_core/autotuner_interfaces/contexts/BaseContext.hpp"
#include "falcon_core/instrument_interfaces/Instrument.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace contexts {

// This is a simplified placeholder for AcquisitionContext.
// A full implementation would depend on MeasurementContext.
class AcquisitionContext : public BaseContext {
  physics::units::SymbolUnitSP _units;

  template <class Archive>
  void serialize(Archive& ar);

 protected:
  friend class cereal::access;
  AcquisitionContext();

 public:
  /**
   * @brief Initialize an AcquisitionContext with a connection, instrument type,
   * and units.
   * @param connection The device connection.
   * @param instrument_type The type of instrument.
   * @param units The measurement units.
   */
  AcquisitionContext(physics::device_structures::BaseConnectionSP connection,
                     instrument_interfaces::Instrument instrument_type,
                     physics::units::SymbolUnitSP      units);
  /**
   * @brief Create an AcquisitionContext from an InstrumentPort.
   * @param port The instrument port.
   */
  AcquisitionContext(instrument_interfaces::names::InstrumentPortSP port);
  /**
   * @brief Create an AcquisitionContext from a MeasurementContext.
   * @param measurement_context The base measurement context.
   * @param units The measurement units.
   */
  AcquisitionContext(BaseContextSP                measurement_context,
                     physics::units::SymbolUnitSP unit);
  /**
   * @brief Returns the units of the context.
   */
  physics::units::SymbolUnitSP units() const;

  /**
   * @brief Returns the InstrumentPort associated with this context, if any.
   */
  instrument_interfaces::names::InstrumentPortSP port() const {
    // If this context was constructed from an InstrumentPort, return it.
    // Otherwise, return nullptr.
    // You may need to adjust this if you store the port differently.
    // This assumes you have a member _port or can reconstruct it from _label.
    // For now, try to get it from the connection if possible.
    // If you have a _port member, just: return _port;
    // Otherwise, try to dynamic_pointer_cast:
    auto port = std::dynamic_pointer_cast<instrument_interfaces::names::InstrumentPort>(this->connection());
    return port;
  }
  /**
   * @brief Divide the units. The context on the top keeps all other details.
   * @param other: The unit to divide by.
   * @return A new context with the divided units.
   */
  std::shared_ptr<AcquisitionContext> operator/(
      const physics::units::SymbolUnitSP& other) const;
  /**
   * @brief Divide the units. The context on the top keeps all other details.
   * @param other: The unit to divide by.
   * @return A new context with the divided units.
   */
  std::shared_ptr<AcquisitionContext> operator/(
      const std::shared_ptr<AcquisitionContext>& other) const;
  /**
   * @brief Returns if the connection is inside this context.
   */
  bool match_connection(
      physics::device_structures::BaseConnectionSP other) const;
  /**
   * @brief Returns if the instrument type matches this context.
   */
  bool match_instrument_type(instrument_interfaces::Instrument other) const;
};
using AcquisitionContextSP = std::shared_ptr<AcquisitionContext>;
}  // namespace contexts
}  // namespace autotuner_interfaces
}  // namespace falcon_core
