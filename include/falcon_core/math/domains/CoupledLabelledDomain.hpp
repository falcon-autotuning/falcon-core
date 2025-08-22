#pragma once

#include <cereal/types/vector.hpp>
#include <memory>
#include <vector>

#include "falcon_core/math/domains/BaseCoupledLabelledDomain.hpp"
#include "falcon_core/math/domains/LabelledDomain.hpp"

namespace falcon_core {
namespace math {
namespace domains {

template <typename T>
class CoupledLabelledDomain : public BaseCoupledLabelledDomain<T> {
 public:
  using LabelledDomainT = LabelledDomain<T>;
  using DomainPtr       = std::shared_ptr<LabelledDomainT>;

  CoupledLabelledDomain(const std::vector<DomainPtr>& domains)
      : BaseCoupledLabelledDomain<T>(domains) {}

 private:
  friend class cereal::access;
  CoupledLabelledDomain() = default;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseCoupledLabelledDomain<T>>(this));
  }
};

}  // namespace domains
}  // namespace math
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core::math::domains;
CEREAL_REGISTER_TYPE(falcon_core::math::domains::CoupledLabelledDomain<int>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::domains::CoupledLabelledDomain<int>)
#endif
