/**
 * @file BaseCoupledLabelledDomain.hpp
 * @brief Defines the BaseCoupledLabelledDomain template for FalconCore.
 */

#pragma once

#include "falcon_core/generic/List.hpp"
#include "falcon_core/math/domains/BaseLabelledDomain.hpp"

namespace falcon_core::math::domains {

/**
 * @brief A collection of coupled domains to be attached together.
 */
template <typename Label>
class BaseCoupledLabelledDomain
    : public generic::List<BaseLabelledDomain<Label>> {
 public:
  BaseCoupledLabelledDomain() = default;
  /**
   * @brief Construct from a vector of labelled domains.
   * @param domains Vector of shared pointers to labelled domains.
   */
  BaseCoupledLabelledDomain(
      const std::vector<BaseLabelledDomainSP<Label>>& init)
      : generic::List<BaseLabelledDomainSP<Label>>(init) {}
  /**
   * @brief Get all domains.
   */
  const std::vector<BaseLabelledDomainSP<Label>>& domains() const {
    return this->items();
  }
  /**
   * @brief Get all labels.
   * @return Vector of shared pointers to labels.
   */
  generic::List<Label> labels() const {
    generic::List<Label> result;
    for (const auto& domain : domains()) {
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
  BaseLabelledDomainSP<Label> get_domain(
      const std::shared_ptr<Label>& search) const {
    for (const auto& domain : domains()) {
      if (*(domain->label()) == *search) {
        return domain;
      }
    }
    throw std::runtime_error("No domain found matching label");
  }

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::List<BaseLabelledDomain<Label>>>(this));
  }
};
template <typename T>
using BaseCoupledLabelledDomainSP =
    std::shared_ptr<BaseCoupledLabelledDomain<T>>;
}  // namespace falcon_core::math::domains
