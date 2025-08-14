#pragma once

#include <memory>
#include <string>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/instrument_interfaces/Instrument.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace names {

template <typename T>
class InstrumentPort : public generic::Song {
 public:
  InstrumentPort(std::string        default_name,
                 std::shared_ptr<T> pseudo_name,
                 Instrument         instrument_type,
                 std::string        description)
      : _default_name(std::move(default_name)),
        _pseudo_name(std::move(pseudo_name)),
        _instrument_type(std::move(instrument_type)),
        _description(std::move(description)) {}

  const std::string&        default_name() const { return _default_name; }
  const std::shared_ptr<T>& pseudo_name() const { return _pseudo_name; }

 private:
  std::string        _default_name;
  std::shared_ptr<T> _pseudo_name;
  Instrument         _instrument_type;
  std::string        _description;
};
}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core
