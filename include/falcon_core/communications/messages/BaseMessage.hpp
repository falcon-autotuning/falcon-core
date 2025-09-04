#pragma once

#include <falcon_core/generic/Song.hpp>
#include <string>

namespace falcon_core {
namespace communications {
namespace messages {

class BaseMessage : public generic::Song {
 public:
  BaseMessage();
  explicit BaseMessage(const std::string& message);

  const std::string& message() const;

 private:
  std::string _message;

  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar);
};

}  // namespace messages
}  // namespace communications
}  // namespace falcon_core
