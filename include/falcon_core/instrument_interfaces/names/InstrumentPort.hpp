#pragma once

#include <memory>
#include <stdexcept>
#include <string>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/instrument_interfaces/Instrument.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"
#include "falcon_core/physics/units/Units.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace names {

template <typename T>
class InstrumentPort : public generic::Song {
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
      std::string        default_name,
      std::shared_ptr<T> pseudo_name     = nullptr,
      Instrument         instrument_type = INSTRUMENT_TYPES::DC_VOLTAGE_SOURCE,
      std::shared_ptr<physics::units::SymbolUnit> units =
          std::make_shared<physics::units::SymbolUnit>(
              physics::units::Units::Volt),
      std::string description = "")
      : _default_name(std::move(default_name)),
        _pseudo_name(std::move(pseudo_name)),
        _instrument_type(std::move(instrument_type)),
        _units(std::move(units)),
        _description(std::move(description)) {}

  InstrumentPort() = default;
  /**
   * @brief Rreturn the default name of the port.
   */
  const std::string default_name() const { return _default_name; }
  /**
   * @brief Return the pseudo name of the port.
   * @throws std::runtime_error if the pseudo name is not set.
   */
  const std::shared_ptr<T> pseudo_name() const {
    if (!_pseudo_name) {
      throw std::runtime_error("The pseudo_name of the port is not set");
    }
    return _pseudo_name;
  }
  /**
   * @brief Returns the type of the instrument that the port is connected to.
   */
  const Instrument instrument_type() const { return _instrument_type; }
  /**
   * @brief Returns the untis of the port.
   */
  const std::shared_ptr<physics::units::SymbolUnit> units() const {
    return _units;
  }
  /**
   * @brief Returns the description of the port.
   */
  const std::string description() const { return _description; }
  /**
   * @brief Returns the psuedo name if it exists, otherwise the instrument type
   * as a string.
   */
  const std::string instrument_facing_name() const {
    if (_pseudo_name) {
      return pseudo_name()->name();
    } else {
      return instrument_type();
    }
  }

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this),
       _default_name,
       _pseudo_name,
       _instrument_type,
       _units,
       _description);
  }

 private:
  std::string                                 _default_name;
  std::shared_ptr<T>                          _pseudo_name;
  Instrument                                  _instrument_type;
  std::shared_ptr<physics::units::SymbolUnit> _units;
  std::string                                 _description;

  friend class cereal::access;
};

using InstrumentPortSP =
    std::shared_ptr<InstrumentPort<physics::device_structures::BaseConnection>>;
}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core

#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::names::InstrumentPort<
                     falcon_core::physics::device_structures::BaseConnection>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::names::InstrumentPort<
        falcon_core::physics::device_structures::BaseConnection>)
#endif
