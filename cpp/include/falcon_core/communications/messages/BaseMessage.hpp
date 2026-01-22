#pragma once

#include <falcon_core/generic/Song.hpp>
#include <shared_mutex>

#include "falcon_core/export.h"

namespace falcon_core {
namespace communications {
namespace messages {

class FALCON_CORE_CPP_API BaseMessage : public generic::Song {
  std::string                     _message;
  mutable std::shared_timed_mutex _mu_message;

 public:
  BaseMessage(const BaseMessage& other);
  BaseMessage& operator=(const BaseMessage& other);
  BaseMessage(const std::string& message);

  const std::string& message() const;
  bool               operator==(const BaseMessage& other) const;
  bool               operator!=(const BaseMessage& other) const;

 protected:
  friend class cereal::access;
  BaseMessage();
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_m(_mu_message);
    ar(cereal::base_class<generic::Song>(this), _message);
  }
};
using BaseMessageSP = std::shared_ptr<BaseMessage>;
}  // namespace messages
}  // namespace communications
}  // namespace falcon_core
