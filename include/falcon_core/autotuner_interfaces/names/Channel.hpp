#pragma once

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace names {
/**
 * @brief A string corresponding to a channel name.
 */
class Channel : public generic::Song {
  std::string _name;
  /**
   * @brief Constructs a channel with the given name.
   */
  Channel(std::string name) : _name(name) {};
  std::string name() const { return _name; }
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _name);
  }
};
using ChannelSP = std::shared_ptr<Channel>;
}  // namespace names
}  // namespace autotuner_interfaces
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core::autotuner_interfaces::names;
CEREAL_REGISTER_TYPE(Channel)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, Channel)
#endif
