

# File InstrumentPort.hpp

[**File List**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**instrument\_interfaces**](dir_1d63ba24e228ec3f87efddb1c2728844.md) **>** [**names**](dir_a1bb891a070db74bff5519c1e6868927.md) **>** [**InstrumentPort.hpp**](InstrumentPort_8hpp.md)

[Go to the documentation of this file](InstrumentPort_8hpp.md)


```C++
#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/instrument_interfaces/names/Instrument.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace names {

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
  mutable std::shared_timed_mutex          _mu_default_name;
  mutable std::shared_timed_mutex          _mu_pseudo_name;
  mutable std::shared_timed_mutex          _mu_instrument_type;
  mutable std::shared_timed_mutex          _mu_units;
  mutable std::shared_timed_mutex          _mu_description;
  mutable std::shared_timed_mutex          _mu_type;

 public:
  InstrumentPort(const InstrumentPort& other);
  InstrumentPort& operator=(const InstrumentPort& other);
  InstrumentPort(
      const std::string&                              default_name,
      const physics::device_structures::ConnectionSP& pseudo_name = nullptr,
      const Instrument& instrument_type = INSTRUMENT_TYPES::DC_VOLTAGE_SOURCE,
      const physics::units::SymbolUnitSP& units =
          physics::units::SymbolUnit::Volt(),
      const std::string& description = "",
      const PortType&    type        = PortType::InstrumentPort);
  static std::shared_ptr<InstrumentPort> Knob(
      const std::string&                              default_name,
      const physics::device_structures::ConnectionSP& pseudo_name = nullptr,
      const Instrument& instrument_type = INSTRUMENT_TYPES::DC_VOLTAGE_SOURCE,
      const physics::units::SymbolUnitSP units =
          physics::units::SymbolUnit::MilliVolt(),
      const std::string& description = "A default voltage source");
  static std::shared_ptr<InstrumentPort> Meter(
      const std::string&                              default_name,
      const physics::device_structures::ConnectionSP& pseudo_name = nullptr,
      const Instrument& instrument_type = INSTRUMENT_TYPES::AMNMETER,
      const physics::units::SymbolUnitSP units =
          physics::units::SymbolUnit::NanoAmpere(),
      const std::string& description =
          "A default current instrument_interface");
  static std::shared_ptr<InstrumentPort> Timer();
  static std::shared_ptr<InstrumentPort> ExecutionClock();

  const std::string default_name() const;
  const std::shared_ptr<physics::device_structures::Connection> pseudo_name()
      const;
  const Instrument instrument_type() const;
  const std::shared_ptr<physics::units::SymbolUnit> units() const;
  const std::string description() const;
  const std::string instrument_facing_name() const;
  const bool is_knob() const;
  const bool is_meter() const;
  const bool     is_port() const;
  bool           operator==(const InstrumentPort& other) const;
  bool           operator!=(const InstrumentPort& other) const;
  const PortType type() const;

 protected:
  friend class cereal::access;
  InstrumentPort();
  template <class Archive>
  void serialize(Archive& ar) {
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
    std::lock(lock_default_name,
              lock_pseudo_name,
              lock_instrument_type,
              lock_units,
              lock_description,
              lock_type);
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
}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core
```


