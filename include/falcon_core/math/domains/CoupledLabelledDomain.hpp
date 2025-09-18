/**
 * @file CoupledLabelledDomain.hpp
 * @brief Defines the CoupledLabelledDomain template for FalconCore.
 */

#pragma once

#include "falcon_core/math/domains/BaseCoupledLabelledDomain.hpp"

namespace falcon_core::math::domains {

/**
 * @brief Domain with a label and a set of coupled domains.
 */
template <typename Label>
class CoupledLabelledDomain : public BaseCoupledLabelledDomain<Label> {
 public:
  CoupledLabelledDomain() = default;
  /**
   * @brief Construct from a vector of labelled domains.
   * @param domains Vector of shared pointers to labelled domains.
   */
  CoupledLabelledDomain(const std::vector<BaseLabelledDomainSP<Label>>& init)
      : BaseCoupledLabelledDomain<Label>(init) {}

 public:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseCoupledLabelledDomain<Label>>(this));
  }
};

}  // namespace falcon_core::math::domains
