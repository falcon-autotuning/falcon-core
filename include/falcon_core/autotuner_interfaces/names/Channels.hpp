#pragma once

#include <cereal/archives/json.hpp>

#include "falcon_core/autotuner_interfaces/names/Channel.hpp"
namespace falcon_core {
namespace autotuner_interfaces {
namespace names {

/**
 * @brief A collection of channels..
 */
class Channels : public virtual falcon_core::generic::Song {
  std::vector<std::shared_ptr<Channel>> _values;

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
  Channels() = default;
  Channels(size_t count) : _values(count) {}
  Channels(size_t count, const std::shared_ptr<Channel>& value)
      : _values(count, value) {}
  Channels(const std::vector<std::shared_ptr<Channel>>& vec) : _values(vec) {}

  // Forwarding methods
  void push_back(const std::shared_ptr<Channel>& item) {
    _values.push_back(item);
  }
  void                     clear() { _values.clear(); }
  void                     reserve(size_t n) { _values.reserve(n); }
  size_t                   size() const { return _values.size(); }
  std::shared_ptr<Channel> at(const size_t idx) const {
    return _values.at(idx);
  }
  const std::shared_ptr<Channel> operator[](const size_t idx) const {
    return _values[idx];
  }
  const std::vector<std::shared_ptr<Channel>> items() const { return _values; }
  std::vector<std::shared_ptr<Channel>>       items() { return _values; }
  typename std::vector<std::shared_ptr<Channel>>::iterator begin() {
    return _values.begin();
  }
  typename std::vector<std::shared_ptr<Channel>>::iterator end() {
    return _values.end();
  }
  typename std::vector<std::shared_ptr<Channel>>::const_iterator begin() const {
    return _values.begin();
  }
  typename std::vector<std::shared_ptr<Channel>>::const_iterator end() const {
    return _values.end();
  }
  void insert(
      typename std::vector<std::shared_ptr<Channel>>::iterator       pos,
      typename std::vector<std::shared_ptr<Channel>>::const_iterator first,
      typename std::vector<std::shared_ptr<Channel>>::const_iterator last) {
    _values.insert(pos, first, last);
  }

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _values);
  }

 protected:
  friend class cereal::access;
};
using ChannelsSP = std::shared_ptr<Channels>;
}  // namespace names
}  // namespace autotuner_interfaces
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core::autotuner_interfaces::names;
CEREAL_REGISTER_TYPE(Channels)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, Channels)
#endif
