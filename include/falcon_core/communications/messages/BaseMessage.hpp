#pragma once

#include <falcon_core/generic/Song.hpp>

namespace falcon_core::communications::messages {

class BaseMessage : public generic::Song {
  std::string _message;

 public:
  BaseMessage(const std::string& message);

  const std::string& message() const;
  bool               operator==(const BaseMessage& other) const;
  bool               operator!=(const BaseMessage& other) const;

 protected:
  friend class cereal::access;
  BaseMessage();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _message);
  }
};
using BaseMessageSP = std::shared_ptr<BaseMessage>;
}  // namespace falcon_core::communications::messages
