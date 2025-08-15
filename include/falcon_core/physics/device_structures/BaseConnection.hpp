#pragma once

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {
class BaseConnection : public generic::Song {
  std::string _name;

 public:
  BaseConnection(std::string name) : _name(std::move(name)) {}
  std::string name() const { return _name; }
  template <class Archive>
  void serialize(Archive &ar) {
    ar(cereal::base_class<Song>(this), _name);
  }

 protected:
  BaseConnection() : _name("") {}  // or initialize _name with a default value
  friend class cereal::access;
};
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
