#pragma once

#include "falcon-core/autotuner_interfaces/names/Channel.hpp"
#include "falcon-core/export.h"
#include "falcon-core/generic/List.hpp"
namespace falcon_core {
namespace generic {
extern template class 
    List<autotuner_interfaces::names::Channel>;
}
namespace autotuner_interfaces {
namespace names {

/**
 * @brief A collection of channels..
 */
class FALCON_CORE_CPP_API Channels : public generic::List<Channel> {
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

  bool operator==(const Channels& other) const;
  bool operator!=(const Channels& other) const;
};
using ChannelsSP = std::shared_ptr<Channels>;
}  // namespace names
}  // namespace autotuner_interfaces
}  // namespace falcon_core
