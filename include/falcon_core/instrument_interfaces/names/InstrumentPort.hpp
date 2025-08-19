#pragma once

#include <memory>
#include <string>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/instrument_interfaces/Instrument.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace names {

template <typename T>
class InstrumentPort : public generic::Song {
  std::string        _default_name;
  std::shared_ptr<T> _pseudo_name;
  Instrument         _instrument_type;
  std::string        _description;

 public:
  InstrumentPort(std::string        default_name,
                 std::shared_ptr<T> pseudo_name,
                 Instrument         instrument_type,
                 std::string        description)
      : _default_name(std::move(default_name)),
        _pseudo_name(std::move(pseudo_name)),
        _instrument_type(std::move(instrument_type)),
        _description(std::move(description)) {}
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Song>(this),
       _default_name,
       _pseudo_name,
       _instrument_type,
       _description);
  }

  const std::string&        default_name() const { return _default_name; }
  const std::shared_ptr<T>& pseudo_name() const { return _pseudo_name; }

 protected:
  InstrumentPort() = default;  // or initialize _name with a default value

  friend class cereal::access;
};
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
