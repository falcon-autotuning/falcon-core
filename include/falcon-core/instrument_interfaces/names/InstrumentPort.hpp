#pragma once

#include "falcon-core/export.h"
#include "falcon-core/generic/Song.hpp"
#include "falcon-core/physics/device_structures/Connection.hpp"
#include "falcon-core/physics/units/SymbolUnit.hpp"
#include <cstdint>

namespace falcon_core {
namespace instrument_interfaces {
namespace names {

enum class PortType : std::uint8_t {
  Knob,
  Meter,
  Setting,
};
inline const char *ToString(PortType type) {
  switch (type) {
  case PortType::Knob:
    return "Knob";
  case PortType::Meter:
    return "Meter";
  case PortType::Setting:
    return "Setting";
  default:
    return "Unknown";
  }
}

enum class Scope : std::uint8_t {
  Local,  // Local scope implies that the property applies to a channel
  Global, // Global scope implies that the property applies to a whole
          // instrument
};

inline const char *ToString(Scope scope) {
  switch (scope) {
  case Scope::Local:
    return "Local";
  case Scope::Global:
    return "Global";
  default:
    return "Unknown";
  }
}

enum class Access : std::uint8_t {
  Read,
  Write,
  ReadWrite,
};

inline const char *ToString(Access access) {
  switch (access) {
  case Access::Read:
    return "Read";
  case Access::Write:
    return "Write";
  case Access::ReadWrite:
    return "ReadWrite";
  default:
    return "Unknown";
  }
}

enum class Instrument : std::uint8_t {
  DC_Voltage_Source,
  Amnmeter,
  Magnet,
  Lockin,
  Voltage_Source,
  Current_Source,
  HF_Voltage_Source,
  DC_Current_Source,
  HF_Current_Source,
  Thermometer,
  Voltmeter,
  FPGA,
  Clock,
  Discrete,
};

inline const char *ToString(Instrument instrument) {
  switch (instrument) {
  case Instrument::DC_Voltage_Source:
    return "DC_Voltage_Source";
  case Instrument::Amnmeter:
    return "Amnmeter";
  case Instrument::Magnet:
    return "Magnet";
  case Instrument::Lockin:
    return "Lockin";
  case Instrument::Voltage_Source:
    return "Voltage_Source";
  case Instrument::Current_Source:
    return "Current_Source";
  case Instrument::HF_Voltage_Source:
    return "HF_Voltage_Source";
  case Instrument::DC_Current_Source:
    return "DC_Current_Source";
  case Instrument::HF_Current_Source:
    return "HF_Current_Source";
  case Instrument::Thermometer:
    return "Thermometer";
  case Instrument::Voltmeter:
    return "Voltmeter";
  case Instrument::FPGA:
    return "FPGA";
  case Instrument::Clock:
    return "Clock";
  case Instrument::Discrete:
    return "Discrete";
  }

  return "Unknown";
}

enum class InstrumentCharacteristic : std::uint8_t {
  None,
  Sample_Rate,
  Max_Sample_Rate,
  Min_Sample_Rate,
  Applied_Voltage,
  Max_Source_Voltage,
  Min_Source_Voltage,
  Number_Of_Samples,
  Max_Number_Of_Samples,
  Min_Number_Of_Samples,
  Voltage_Ramp_Slope,
  Max_Voltage_Ramp_Slope,
  Min_Voltage_Ramp_Slope,
  // Currently only the characteristics suitable for DC_Voltage_Source and
  // Amnmeter
};

inline const char *ToString(InstrumentCharacteristic characteristic) {
  switch (characteristic) {
  case InstrumentCharacteristic::None:
    return "None";
  case InstrumentCharacteristic::Sample_Rate:
    return "Sample_Rate";
  case InstrumentCharacteristic::Max_Sample_Rate:
    return "Max_Sample_Rate";
  case InstrumentCharacteristic::Min_Sample_Rate:
    return "Min_Sample_Rate";
  case InstrumentCharacteristic::Applied_Voltage:
    return "Applied_Voltage";
  case InstrumentCharacteristic::Max_Source_Voltage:
    return "Max_Source_Voltage";
  case InstrumentCharacteristic::Min_Source_Voltage:
    return "Min_Source_Voltage";
  case InstrumentCharacteristic::Number_Of_Samples:
    return "Number_Of_Samples";
  case InstrumentCharacteristic::Max_Number_Of_Samples:
    return "Max_Number_Of_Samples";
  case InstrumentCharacteristic::Min_Number_Of_Samples:
    return "Min_Number_Of_Samples";
  case InstrumentCharacteristic::Voltage_Ramp_Slope:
    return "Voltage_Ramp_Slope";
  case InstrumentCharacteristic::Max_Voltage_Ramp_Slope:
    return "Max_Voltage_Ramp_Slope";
  case InstrumentCharacteristic::Min_Voltage_Ramp_Slope:
    return "Min_Voltage_Ramp_Slope";
  }

  return "Unknown";
}

class FALCON_CORE_CPP_API InstrumentPort : public generic::Song {
  std::string _default_name;
  std::string _instrument_name;
  std::string _description;
  physics::units::SymbolUnitSP _units;
  physics::device_structures::ConnectionSP _pseudo_name;
  Instrument _instrument_type;
  Scope _scope;
  Access _access;
  InstrumentCharacteristic _characteristic_name;
  PortType _type;

  mutable std::shared_timed_mutex _mu_default_name;
  mutable std::shared_timed_mutex _mu_instrument_name;
  mutable std::shared_timed_mutex _mu_pseudo_name;
  mutable std::shared_timed_mutex _mu_instrument_type;
  mutable std::shared_timed_mutex _mu_scope;
  mutable std::shared_timed_mutex _mu_access;
  mutable std::shared_timed_mutex _mu_characteristic_name;
  mutable std::shared_timed_mutex _mu_units;
  mutable std::shared_timed_mutex _mu_description;
  mutable std::shared_timed_mutex _mu_type;

public:
  InstrumentPort(InstrumentPort &&) = delete;
  InstrumentPort &operator=(InstrumentPort &&) = delete;
  InstrumentPort(const InstrumentPort &other);
  InstrumentPort &operator=(const InstrumentPort &other);
  /**
   * @brief Initialize a InstrumentPort.
   * @param default_name The default name of the port (e.g. "Vg1").
   * @param instrument_name The name of the instrument
   * @param pseudo_name The pseudo name (e.g. "plunger gate 1").
   * @param instrument_type The type of instrument (e.g. DC_VOLTAGE_SOURCE).
   * @param units The units of the instrument (e.g. Volt).
   * @param scope The access scope to this parameter (Read, Write, ReadWrite)
   * @param access The spread of this parameter (Global or local insturment
   * control)
   * @param characteristic The type of characteristic
   * @param type The type of port to construct
   * @description A description of the port.
   */
  InstrumentPort(
      const std::string &default_name, const std::string &instrument_name,
      Scope scope, Access access, InstrumentCharacteristic characteristic,
      PortType type,
      const physics::device_structures::ConnectionSP &pseudo_name = nullptr,
      const Instrument &instrument_type = Instrument::DC_Voltage_Source,
      const physics::units::SymbolUnitSP &units =
          physics::units::SymbolUnit::Volt(),
      const std::string &description = "");
  /**
   * @brief Initialize a Setting.
   * @param default_name The default name of the port (e.g. "Vg1").
   * @param pseudo_name The pseudo name (e.g. "plunger gate 1").
   * @param instrument_type The type of instrument (e.g. DC_VOLTAGE_SOURCE).
   * @param units The units of the instrument (e.g. Volt).
   * @param scope The access scope to this parameter (Read, Write, ReadWrite)
   * @param access The spread of this parameter (Global or local insturment
   * control)
   * @param characteristic The type of characteristic
   * @description A description of the port.
   */
  static std::shared_ptr<InstrumentPort>
  Setting(const std::string &default_name, const std::string &instrument_name,
          Scope scope, Access access, InstrumentCharacteristic characteristic,
          const physics::device_structures::ConnectionSP &pseudo_name = nullptr,
          const Instrument &instrument_type = Instrument::DC_Voltage_Source,
          const physics::units::SymbolUnitSP &units =
              physics::units::SymbolUnit::Volt(),
          const std::string &description = "");
  /**
   * @brief A constructor for a Instrument Knob. This is used as a setter
   * interface.
   * @param default_name The default name of the port (e.g. "Vg1").
   * @param instrument_name The name of the instrument that this is from
   * @param pseudo_name The pseudo name (e.g. "plunger gate 1").
   * @param instrument_type The type of instrument (e.g. DC_VOLTAGE_SOURCE).
   * @param units The units of the instrument (e.g. Volt).
   * @description A description of the port.
   * @type The type of the port.
   */
  static std::shared_ptr<InstrumentPort>
  Knob(const std::string &default_name, const std::string &instrument_name,
       const physics::device_structures::ConnectionSP &pseudo_name = nullptr,
       const Instrument &instrument_type = Instrument::DC_Voltage_Source,
       physics::units::SymbolUnitSP units =
           physics::units::SymbolUnit::MilliVolt(),
       const std::string &description = "A default voltage source");
  /**
   * @brief A constructor for a Instrument Meter. This is used as a getter
   * interface.
   * @param default_name The default name of the port (e.g. "Vg1").
   * @param pseudo_name The pseudo name (e.g. "plunger gate 1").
   * @param instrument_name The name of the instrument that this is from
   * @param instrument_type The type of instrument (e.g. DC_VOLTAGE_SOURCE).
   * @param units The units of the instrument (e.g. Volt).
   * @description A description of the port.
   */
  static std::shared_ptr<InstrumentPort>
  Meter(const std::string &default_name, const std::string &instrument_name,
        const physics::device_structures::ConnectionSP &pseudo_name = nullptr,
        const Instrument &instrument_type = Instrument::Amnmeter,
        physics::units::SymbolUnitSP units =
            physics::units::SymbolUnit::NanoAmpere(),
        const std::string &description = "A default current source");
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
   * @brief Return the default name of the port.
   */
  const std::string default_name() const;
  /**
   * @brief Return the instrument name associated with the port.
   */
  const std::string instrument_name() const;
  /**
   * @brief Return the pseudo name of the port.
   * @throws std::runtime_error if the pseudo name is not set.
   */
  const std::shared_ptr<physics::device_structures::Connection>
  pseudo_name() const;
  /**
   * @brief Returns the type of the instrument that the port is connected to.
   */
  const Instrument instrument_type() const;
  /**
   * @brief Returns the scope of the port, whether is applies to the whole
   * instrument or is isolated.
   */
  const Scope scope() const;
  /**
   * @brief Returns the access of the port, whether it is Read only, Write only,
   * etc.
   */
  const Access access() const;
  /**
   * @brief Returns the optional characteristic of the port, describing what
   * memory this port maps to.
   */
  const InstrumentCharacteristic characteristic() const;
  /**
   * @brief Returns the units of the port.
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
   * @brief Checks if this port is a setting.
   */
  const bool is_setting() const;
  bool operator==(const InstrumentPort &other) const;
  bool operator!=(const InstrumentPort &other) const;
  const PortType type() const;

protected:
  friend class cereal::access;
  InstrumentPort();
  template <class Archive> void serialize(Archive &ar) {
    std::shared_lock<std::shared_timed_mutex> lock_default_name(
        _mu_default_name, std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_pseudo_name(_mu_pseudo_name,
                                                               std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_instrument_type(
        _mu_instrument_type, std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_units(_mu_units,
                                                         std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_description(_mu_description,
                                                               std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_type(_mu_type,
                                                        std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_instrument_name(
        _mu_instrument_name, std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_scope(_mu_scope,
                                                         std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_access(_mu_access,
                                                          std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_characteristic_name(
        _mu_characteristic_name, std::defer_lock);
    std::lock(lock_default_name, lock_pseudo_name, lock_instrument_type,
              lock_units, lock_description, lock_type, lock_instrument_name,
              lock_scope, lock_access, lock_characteristic_name);
    ar(cereal::base_class<generic::Song>(this), _default_name, _pseudo_name,
       _instrument_type, _units, _description, _type, _instrument_name, _scope,
       _access, _characteristic_name);
  }
};

using InstrumentPortSP = std::shared_ptr<InstrumentPort>;
} // namespace names
} // namespace instrument_interfaces
} // namespace falcon_core
