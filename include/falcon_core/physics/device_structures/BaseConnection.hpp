#pragma once

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {
class BaseConnection : public generic::Song {
 public:
  BaseConnection(std::string name);
  std::string name() const { return _name; }

 private:
  BaseConnection() = default;   // for cereal access
  friend class cereal::access;  // cereal can access private members
  template <class Archive>
  void serialize(Archive &ar) {
    ar(cereal::base_class<Song>(this), _name);
  }
  std::string _name;
};
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
