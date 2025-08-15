#pragma once

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {
class BaseConnection : public generic::Song {
<<<<<<< HEAD
 public:
  BaseConnection(std::string name) : _name(std::move(name)) {}
  std::string name() const { return _name; }

  bool operator<(const BaseConnection& other) const { return _name < other._name; }

 private:
=======
  std::string _name;
>>>>>>> 1128ada7a7e3e226ca56a6a13f15884266037517
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
