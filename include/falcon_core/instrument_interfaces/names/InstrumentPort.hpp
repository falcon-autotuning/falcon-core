#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/instrument_interfaces/Instrument.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core::instrument_interfaces::names {

class InstrumentPort : public generic::Song {
  std::string                                             _default_name;
  std::shared_ptr<physics::device_structures::Connection> _pseudo_name;
  Instrument                                              _instrument_type;
  std::shared_ptr<physics::units::SymbolUnit>             _units;
  std::string                                             _description;

 public:
  /**
   * @brief Initialize an InstrumentPort.
   * @param default_name The default name of the port (e.g. "Vg1").
   * @param pseudo_name The pseudo name (e.g. "plunger gate 1").
   * @param instrument_type The type of instrument (e.g. DC_VOLTAGE_SOURCE).
   * @param units The units of the instrument (e.g. Volt).
   * @description A description of the port.
   */
  InstrumentPort(
      std::string                                             default_name,
      std::shared_ptr<physics::device_structures::Connection> pseudo_name =
          nullptr,
      Instrument instrument_type = INSTRUMENT_TYPES::DC_VOLTAGE_SOURCE,
      std::shared_ptr<physics::units::SymbolUnit> units =
          physics::units::SymbolUnit::Volt(),
      std::string description = "");

  /**
   * @brief Rreturn the default name of the port.
   */
  const std::string default_name() const;
  /**
   * @brief Return the pseudo name of the port.
   * @throws std::runtime_error if the pseudo name is not set.
   */
  const std::shared_ptr<physics::device_structures::Connection> pseudo_name()
      const;
  /**
   * @brief Returns the type of the instrument that the port is connected to.
   */
  const Instrument instrument_type() const;
  /**
   * @brief Returns the untis of the port.
   */
  const std::shared_ptr<physics::units::SymbolUnit> units() const;
  /**
   * @brief Returns the description of the port.
   */
  const std::string description() const;
  /**
   * @brief Returns the psuedo name if it exists, otherwise the instrument type
   * as a string.
   */
  const std::string instrument_facing_name() const;

 protected:
  friend class cereal::access;
  InstrumentPort();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this),
       _default_name,
       _pseudo_name,
       _instrument_type,
       _units,
       _description);
  }
};

using InstrumentPortSP = std::shared_ptr<InstrumentPort>;
}  // namespace falcon_core::instrument_interfaces::names
