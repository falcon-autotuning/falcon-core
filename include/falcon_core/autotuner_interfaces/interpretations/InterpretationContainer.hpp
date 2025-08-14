#pragma once

#include <map>
#include <memory>

#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp"
#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace interpretations {

template <typename T>
class InterpretationContainer : public generic::Song {
 public:
  using key_type       = std::shared_ptr<InterpretationContext>;
  using mapped_type    = T;
  using container_type = std::map<key_type, mapped_type, InterpretationContext>;

  InterpretationContainer() = default;

  void insert(const key_type &context, const mapped_type &value) {
    _container[context] = value;
  }

  const mapped_type &at(const key_type &context) const {
    return _container.at(context);
  }

 private:
  container_type _container;
};
}  // namespace interpretations
}  // namespace autotuner_interfaces
}  // namespace falcon_core
