#pragma once

#include <memory>
#include <vector>

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace names {

// Generic collection of instrument ports
template <typename T>
class Ports : public generic::Song {
 public:
  using value_type     = T;
  using container_type = std::vector<std::shared_ptr<value_type>>;

  Ports() = default;

  void push_back(const std::shared_ptr<value_type>& port) {
    _ports.push_back(port);
  }

  size_t                      size() const { return _ports.size(); }
  std::shared_ptr<value_type> at(size_t idx) const { return _ports.at(idx); }
  const container_type&       items() const { return _ports; }
  container_type&             items() { return _ports; }

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _ports);
  }

 private:
  container_type _ports;

  friend class cereal::access;
};

}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core

#ifndef SWIG
// Example registration for Ports<Knob> and Ports<Meter> if needed
// CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::names::Ports<falcon_core::instrument_interfaces::names::Knob>)
// CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
// falcon_core::instrument_interfaces::names::Ports<falcon_core::instrument_interfaces::names::Knob>)
#endif
