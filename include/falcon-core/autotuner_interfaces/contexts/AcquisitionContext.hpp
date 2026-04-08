#pragma once

#include "falcon-core/autotuner_interfaces/contexts/BaseContext.hpp"
#include "falcon-core/export.h"
#include "falcon-core/instrument_interfaces/names/InstrumentPort.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace contexts {

class FALCON_CORE_CPP_API AcquisitionContext : public BaseContext {
  physics::units::SymbolUnitSP    _units;
  mutable std::shared_timed_mutex _mu_units;

 protected:
  friend class cereal::access;
  AcquisitionContext();
  template <class Archive>
  inline void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_u(_mu_units);
    ar(cereal::base_class<BaseContext>(this), _units);
  }

 public:
  AcquisitionContext(const AcquisitionContext& other);
  AcquisitionContext& operator=(const AcquisitionContext& other);
  /**
   * @brief Initialize an AcquisitionContext with a connection, instrument type,
   * and units.
   * @param connection The device connection.
   * @param instrument_type The type of instrument.
   * @param units The measurement units.
   */
  AcquisitionContext(
      const physics::device_structures::ConnectionSP& connection,
      const instrument_interfaces::names::Instrument& instrument_type,
      const physics::units::SymbolUnitSP&             units);
  /**
   * @brief Create an AcquisitionContext from an InstrumentPort.
   * @param port The instrument port.
   */
  AcquisitionContext(
      const instrument_interfaces::names::InstrumentPortSP& port);
  /**
   * @brief Create an AcquisitionContext from a MeasurementContext.
   * @param measurement_context The base measurement context.
   * @param units The measurement units.
   */
  static std::shared_ptr<AcquisitionContext> from_context(
      const BaseContextSP&                measurement_context,
      const physics::units::SymbolUnitSP& unit);
  /**
   * @brief Returns the units of the context.
   */
  const physics::units::SymbolUnitSP units() const;

  /**
   * @brief Divide the units. The context on the top keeps all other details.
   * @param other: The unit to divide by.
   * @return A new context with the divided units.
   */
  const std::shared_ptr<AcquisitionContext> operator/(
      const physics::units::SymbolUnitSP& other) const;
  /**
   * @brief Divide the units. The context on the top keeps all other details.
   * @param other: The unit to divide by.
   * @return A new context with the divided units.
   */
  const std::shared_ptr<AcquisitionContext> operator/(
      const std::shared_ptr<AcquisitionContext>& other) const;
  /**
   * @brief Returns if the connection is inside this context.
   */
  const bool match_connection(
      physics::device_structures::ConnectionSP other) const;
  /**
   * @brief Returns if the instrument type matches this context.
   */
  const bool match_instrument_type(
      instrument_interfaces::names::Instrument other) const;
  bool operator==(const AcquisitionContext& other) const;
  bool operator!=(const AcquisitionContext& other) const;
};
using AcquisitionContextSP = std::shared_ptr<AcquisitionContext>;
}  // namespace contexts
}  // namespace autotuner_interfaces
}  // namespace falcon_core
