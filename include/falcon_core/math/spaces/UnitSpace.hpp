/**
 * @file UnitSpace.hpp
 * @brief Defines the UnitSpace class for FalconCore.
 */

#pragma once

#include <memory>
#include <vector>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/math/Axes.hpp"
#include "falcon_core/math/discretizers/BaseDiscretizer.hpp"
#include "falcon_core/math/domains/Domain.hpp"

namespace falcon_core {
namespace math {
namespace spaces {

/**
 * @brief Represents a space with units and discretization axes.
 *
 * @details
 * UnitSpace is the base class for spaces with axes and a domain.
 */
class UnitSpace : public generic::Song {
 public:
  using DiscretizerPtr = std::shared_ptr<discretizers::BaseDiscretizer>;
  using AxesType       = Axes<discretizers::BaseDiscretizer>;
  using DomainPtr      = std::shared_ptr<domains::Domain>;

  UnitSpace(const AxesType& axes, DomainPtr domain);

  const AxesType&  axes() const;
  const DomainPtr& domain() const;

 protected:
  AxesType  _axes;
  DomainPtr _domain;

  friend class cereal::access;
  UnitSpace();
  template <class Archive>
  void serialize(Archive& ar);
};

}  // namespace spaces
}  // namespace math
}  // namespace falcon_core
