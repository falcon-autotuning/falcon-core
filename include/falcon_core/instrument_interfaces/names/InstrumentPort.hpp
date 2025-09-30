#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/instrument_interfaces/names/Instrument.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core::instrument_interfaces::names {

enum class PortType {
  Knob,
  Meter,
  InstrumentPort,
};
class InstrumentPort : public generic::Song {
  std::string                              _default_name;
  physics::device_structures::ConnectionSP _pseudo_name;
  Instrument                               _instrument_type;
  physics::units::SymbolUnitSP             _units;
  std::string                              _description;
  PortType                                 _type;

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
      const std::string&                              default_name,
      const physics::device_structures::ConnectionSP& pseudo_name = nullptr,
      const Instrument& instrument_type = INSTRUMENT_TYPES::DC_VOLTAGE_SOURCE,
      const physics::units::SymbolUnitSP& units =
          physics::units::SymbolUnit::Volt(),
      const std::string& description = "",
      const PortType&    type        = PortType::InstrumentPort);
  /**
   * @brief A constructor for a Instrument Knob. This is used as a setter
   * interface.
   * @param default_name The default name of the port (e.g. "Vg1").
   * @param pseudo_name The pseudo name (e.g. "plunger gate 1").
   * @param instrument_type The type of instrument (e.g. DC_VOLTAGE_SOURCE).
   * @param units The units of the instrument (e.g. Volt).
   * @description A description of the port.
   * @type The type of the port.
   */
  static std::shared_ptr<InstrumentPort> Knob(
      const std::string&                              default_name,
      const physics::device_structures::ConnectionSP& pseudo_name = nullptr,
      const Instrument& instrument_type = INSTRUMENT_TYPES::DC_VOLTAGE_SOURCE,
      const physics::units::SymbolUnitSP units =
          physics::units::SymbolUnit::MilliVolt(),
      const std::string& description = "A default voltage source");
  /**
   * @brief A constructor for a Instrument Meter. This is used as a getter
   * interface.
   * @param default_name The default name of the port (e.g. "Vg1").
   * @param pseudo_name The pseudo name (e.g. "plunger gate 1").
   * @param instrument_type The type of instrument (e.g. DC_VOLTAGE_SOURCE).
   * @param units The units of the instrument (e.g. Volt).
   * @description A description of the port.
   */
  static std::shared_ptr<InstrumentPort> Meter(
      const std::string&                              default_name,
      const physics::device_structures::ConnectionSP& pseudo_name = nullptr,
      const Instrument& instrument_type = INSTRUMENT_TYPES::AMNMETER,
      const physics::units::SymbolUnitSP units =
          physics::units::SymbolUnit::NanoAmpere(),
      const std::string& description =
          "A default current instrument_interface");
  /**
   * @brief A constructor for a Timer. This is used a dependant variable for
   * measurements.
   */
  static std::shared_ptr<InstrumentPort> Timer();
  /**
   * @brief A constructor for a ExecutionClock. This is used a dependant
   * variable for output measurements.
   */
  static std::shared_ptr<InstrumentPort> ExecutionClock();

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
  /**
   * @brief Checks if this port is a knob.
   */
  const bool is_knob() const;
  /**
   * @brief Checks if this port is a meter.
   */
  const bool is_meter() const;
  /**
   * @brief Checks if this port is a port.
   */
  const bool is_port() const;
  bool       operator==(const InstrumentPort& other) const;
  bool       operator!=(const InstrumentPort& other) const;

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
       _description,
       _type);
  }
};

using InstrumentPortSP = std::shared_ptr<InstrumentPort>;
}  // namespace falcon_core::instrument_interfaces::names
