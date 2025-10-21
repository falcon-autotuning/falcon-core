#pragma once

#include "falcon_core/autotuner_interfaces/names/Channel.hpp"
#include "falcon_core/generic/List.hpp"
namespace falcon_core {
namespace autotuner_interfaces {
namespace names {

/**
 * @brief A collection of channels..
 */
class Channels : public generic::List<Channel> {
 public:
  /**
   * @brief Channels can be constructed in 5 different ways:
   *
   * - Default constructor: creates an empty Channels container.
   *   @code
   *   Channels o;
   *   @endcode
   *
   * - Sized constructor: creates an Channels container with a given
   * number of default-initialized elements.
   *   @param count Number of elements.
   *   @code
   *   Channels o(10);
   *   @endcode
   *
   * - Fill constructor: creates an Channels container with a given
   * number of copies of a specified value.
   *   @param count Number of elements.
   *   @param value Value to copy.
   *   @code
   *   Channels o(10, someChannelSP);
   *   @endcode
   *
   * - Vector constructor: creates an Channels container from an existing
   * vector of BaseConnectionSP.
   *   @param vec Vector of ChannelSP to copy.
   *   @code
   *   std::vector<ChannelsP> v = ...;
   *   Channels o(v);
   *   @endcode
   * - Initializer list constructor: creates a Channels container
   *from an initializer list of shared pointers.
   *   @param init Initializer list of shared_ptr<T> to copy.
   *   @code
   *   Channels o{ptr1, ptr2, ptr3};
   *   @endcode
   */
  Channels();
  Channels(const std::vector<std::shared_ptr<Channel>>& vec);

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::List<Channel>>(this));
  }
};
using ChannelsSP = std::shared_ptr<Channels>;
}  // namespace names
}  // namespace autotuner_interfaces
}  // namespace falcon_core
