#pragma once

#include <memory>
#include <string>
#include <vector>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/instrument_interfaces/Instrument.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace names {

// Forward declarations for type aliases
class Knob;
class Meter;

// InstrumentPort: base class for all instrument ports
template <typename T>
class InstrumentPort : public generic::Song {
 public:
  InstrumentPort(std::string        default_name,
                 std::shared_ptr<T> pseudo_name,
                 Instrument         instrument_type,
                 std::shared_ptr<physics::units::SymbolUnit> units,
                 std::string        description)
      : _default_name(std::move(default_name)),
        _pseudo_name(std::move(pseudo_name)),
        _instrument_type(std::move(instrument_type)),
        _units(std::move(units)),
        _description(std::move(description)) {}

  InstrumentPort() = default;

  const std::string&        default_name() const { return _default_name; }
  const std::shared_ptr<T>& pseudo_name() const { return _pseudo_name; }
  const Instrument&         instrument_type() const { return _instrument_type; }
  const std::shared_ptr<physics::units::SymbolUnit>& units() const { return _units; }
  const std::string&        description() const { return _description; }

  // cereal serialization
  template <class Archive>
  void serialize(Archive& ar) {
    ar(_default_name, _pseudo_name, _instrument_type, _units, _description);
  }

 private:
  std::string        _default_name;
  std::shared_ptr<T> _pseudo_name;
  Instrument         _instrument_type;
  std::shared_ptr<physics::units::SymbolUnit> _units;
  std::string        _description;
};

// Type aliases for Knob and Meter
using Knob  = InstrumentPort<physics::device_structures::UsefulGate>;
using Meter = InstrumentPort<physics::units::Ohmic>;

}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core

// No CEREAL_REGISTER_TYPE for InstrumentPort because it is a template.
// No CEREAL_REGISTER_TYPE for Knob/Meter because they are type aliases.
