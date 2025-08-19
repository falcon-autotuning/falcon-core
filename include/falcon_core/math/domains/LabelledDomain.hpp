#pragma once

#include <memory>
#include <cereal/types/memory.hpp>

#include "falcon_core/math/domains/Domain.hpp"

namespace falcon_core {
namespace math {
namespace domains {
template <typename T>
class LabelledDomain : public Domain {
 public:
  LabelledDomain(double min_val, double max_val, std::shared_ptr<T> label)
      : Domain(min_val, max_val), _label(std::move(label)) {}

  const std::shared_ptr<T>& label() const { return _label; }

 private:
  std::shared_ptr<T> _label;

  friend class cereal::access;
  LabelledDomain() = default;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Domain>(this), _label);
  }
};
}  // namespace domains
}  // namespace math
}  // namespace falcon_core

using namespace falcon_core::math::domains;
CEREAL_REGISTER_TYPE(falcon_core::math::domains::LabelledDomain<int>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, falcon_core::math::domains::LabelledDomain<int>)
