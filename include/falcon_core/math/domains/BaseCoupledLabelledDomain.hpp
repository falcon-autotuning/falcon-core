/**
 * @file BaseCoupledLabelledDomain.hpp
 * @brief Defines the BaseCoupledLabelledDomain template for FalconCore.
 */

#pragma once

#include <cereal/types/vector.hpp>
#include <memory>
#include <vector>
#include "falcon_core/math/domains/LabelledDomain.hpp"

namespace falcon_core {
namespace math {
namespace domains {

/**
 * @brief Container for a set of coupled labelled domains.
 * @tparam T Type of the label.
 */
template <typename T>
class BaseCoupledLabelledDomain : public generic::Song {
 public:
  using LabelledDomainT = LabelledDomain<T>;
  using DomainPtr       = std::shared_ptr<LabelledDomainT>;

  /**
   * @brief Construct from a vector of labelled domains.
   * @param domains Vector of shared pointers to labelled domains.
   */
  BaseCoupledLabelledDomain(const std::vector<DomainPtr>& domains)
      : _domains(domains) {}

  /**
   * @brief Get all domains.
   * @return Vector of shared pointers to labelled domains.
   */
  const std::vector<DomainPtr>& domains() const { return _domains; }

  /**
   * @brief Get all labels.
   * @return Vector of shared pointers to labels.
   */
  std::vector<std::shared_ptr<T>> labels() const {
    std::vector<std::shared_ptr<T>> result;
    for (const auto& domain : _domains) {
      result.push_back(domain->label());
    }
    return result;
  }

  /**
   * @brief Get domain by label.
   * @param search Shared pointer to label to search for.
   * @return Shared pointer to the matching domain.
   * @throws std::runtime_error if not found.
   */
  DomainPtr get_domain(const std::shared_ptr<T>& search) const {
    for (const auto& domain : _domains) {
      if (domain->label() == search) {
        return domain;
      }
    }
    throw std::runtime_error("No domain found matching label");
  }

  typename std::vector<DomainPtr>::const_iterator begin() const {
    return _domains.begin();
  }
  typename std::vector<DomainPtr>::const_iterator end() const {
    return _domains.end();
  }

 protected:
  std::vector<DomainPtr> _domains;

  friend class cereal::access;
  BaseCoupledLabelledDomain() = default;
  /**
   * @brief Serialization method for cereal.
   */
  template <class Archive>
  void serialize(Archive& ar) {
    ar(_domains);
  }
};

}  // namespace domains
}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
using namespace falcon_core::math::domains;

CEREAL_REGISTER_TYPE(falcon_core::math::domains::BaseCoupledLabelledDomain<int>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::domains::BaseCoupledLabelledDomain<int>)
#endif
