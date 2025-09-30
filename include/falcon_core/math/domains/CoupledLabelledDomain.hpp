/**
 * @file BaseCoupledLabelledDomain.hpp
 * @brief Defines the BaseCoupledLabelledDomain template for FalconCore.
 */

#pragma once

#include "falcon_core/generic/List.hpp"
#include "falcon_core/instrument_interfaces/names/Ports.hpp"
#include "falcon_core/math/domains/LabelledDomain.hpp"

namespace falcon_core::math::domains {

/**
 * @brief A collection of coupled domains to be attached together.
 */
class CoupledLabelledDomain : public generic::List<LabelledDomain> {
 public:
  CoupledLabelledDomain();
  /**
   * @brief Construct from a vector of labelled domains.
   * @param domains Vector of shared pointers to labelled domains.
   */
  CoupledLabelledDomain(const std::vector<LabelledDomainSP>& init);
  /**
   * @brief Get all domains.
   */
  const std::vector<LabelledDomainSP>& domains() const;
  /**
   * @brief Get all labels.
   * @return Vector of shared pointers to labels.
   */
  const instrument_interfaces::names::PortsSP labels() const;

  /**
   * @brief Get domain by label.
   * @param search Shared pointer to label to search for.
   * @return Shared pointer to the matching domain.
   * @throws std::runtime_error if not found.
   */
  LabelledDomainSP get_domain(
      const instrument_interfaces::names::InstrumentPortSP& search) const;
  bool operator==(const CoupledLabelledDomain& other) const;
  bool operator!=(const CoupledLabelledDomain& other) const;

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::List<LabelledDomain>>(this));
  }
};
using CoupledLabelledDomainSP = std::shared_ptr<CoupledLabelledDomain>;
}  // namespace falcon_core::math::domains
