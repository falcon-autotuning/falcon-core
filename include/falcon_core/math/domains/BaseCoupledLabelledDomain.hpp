#pragma once

#include <cereal/types/vector.hpp>
#include <vector>
#include <memory>
#include "falcon_core/math/domains/LabelledDomain.hpp"

namespace falcon_core {
namespace math {
namespace domains {

template <typename T>
class BaseCoupledLabelledDomain : public generic::Song {
 public:
  using LabelledDomainT = LabelledDomain<T>;
  using DomainPtr = std::shared_ptr<LabelledDomainT>;

  BaseCoupledLabelledDomain(const std::vector<DomainPtr>& domains)
      : _domains(domains) {}

  const std::vector<DomainPtr>& domains() const { return _domains; }

  std::vector<std::shared_ptr<T>> labels() const {
    std::vector<std::shared_ptr<T>> result;
    for (const auto& domain : _domains) {
      result.push_back(domain->label());
    }
    return result;
  }

  DomainPtr get_domain(const std::shared_ptr<T>& search) const {
    for (const auto& domain : _domains) {
      if (domain->label() == search) {
        return domain;
      }
    }
    throw std::runtime_error("No domain found matching label");
  }

  typename std::vector<DomainPtr>::const_iterator begin() const { return _domains.begin(); }
  typename std::vector<DomainPtr>::const_iterator end() const { return _domains.end(); }

 private:
  std::vector<DomainPtr> _domains;

  friend class cereal::access;
  BaseCoupledLabelledDomain() = default;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(_domains);
  }
};

}  // namespace domains
}  // namespace math
}  // namespace falcon_core

using namespace falcon_core::math::domains;

#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::math::domains::BaseCoupledLabelledDomain<int>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::domains::BaseCoupledLabelledDomain<int>)
#endif
