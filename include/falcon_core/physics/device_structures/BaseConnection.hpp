#pragma once

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {
class BaseConnection : public generic::Song<BaseConnection> {
 public:
  BaseConnection(std::string name);
  static constexpr const char *member_names[] = {"_class_name", "_name"};
  static std::string           _static_class_name() { return "BaseConnection"; }
  std::string                  name() const { return _name; }

 private:
  std::string _name;
};
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
