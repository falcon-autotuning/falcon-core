/**
 * @file BaseCoupledLabelledDomain.hpp
 * @brief Defines the BaseCoupledLabelledDomain template for FalconCore.
 */

#pragma once

#include "falcon-core/export.h"
#include "falcon-core/generic/List.hpp"
#include "falcon-core/instrument_interfaces/names/Ports.hpp"
#include "falcon-core/math/domains/LabelledDomain.hpp"

namespace falcon_core {
namespace math {
namespace domains {

/**
 * @brief A collection of coupled domains to be attached together.
 */
class FALCON_CORE_CPP_API CoupledLabelledDomain
    : public generic::List<LabelledDomain> {
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
  const std::vector<LabelledDomainSP> domains() const;
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
};
using CoupledLabelledDomainSP = std::shared_ptr<CoupledLabelledDomain>;
}  // namespace domains
}  // namespace math
}  // namespace falcon_core
