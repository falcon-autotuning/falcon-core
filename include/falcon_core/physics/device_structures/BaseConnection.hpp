#pragma once

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {
class BaseConnection : public virtual generic::Song {
  std::string _name;

 public:
  bool operator<(const BaseConnection& other) const {
    return _name < other._name;  // Compare based on name
  }
  BaseConnection(std::string name) : _name(std::move(name)) {}
  BaseConnection() : _name("") {}
  std::string name() const { return _name; }
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Song>(this), _name);
  }

 protected:
  friend class cereal::access;
};
using BaseConnectionSP = std::shared_ptr<BaseConnection>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core

#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::BaseConnection)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::device_structures::BaseConnection)
#endif
