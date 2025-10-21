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
 public:
  Channel(const std::string& name);
  std::string name() const;
  bool        operator==(const Channel& other) const;
  bool        operator!=(const Channel& other) const;

 protected:
  Channel();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _name);
  }
};
using ChannelSP = std::shared_ptr<Channel>;
}  // namespace names
}  // namespace autotuner_interfaces
}  // namespace falcon_core
