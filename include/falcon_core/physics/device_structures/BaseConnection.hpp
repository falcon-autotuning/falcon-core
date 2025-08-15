#pragma once

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {
class BaseConnection : public generic::Song {
  std::string _name;

  template <class Archive>
  void serialize(Archive &ar) {
    ar(cereal::base_class<Song>(this), _name);
  }

 public:
  BaseConnection(std::string name) : _name(std::move(name)) {}
  std::string name() const { return _name; }
};
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
