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

  /**
   * @brief Construct a UnitSpace.
   * @param axes The axes for discretization.
   * @param domain The domain of the space.
   */
  UnitSpace(const AxesType& axes, DomainPtr domain)
      : _axes(axes), _domain(domain) {}

  /**
   * @brief Get the axes.
   * @return Reference to the axes.
   */
  const AxesType& axes() const { return _axes; }

  /**
   * @brief Get the domain.
   * @return Reference to the domain pointer.
   */
  const DomainPtr& domain() const { return _domain; }

 protected:
  AxesType  _axes;    ///< Discretization axes.
  DomainPtr _domain;  ///< Domain of the space.

  friend class cereal::access;
  /**
   * @brief Default constructor for cereal access.
   */
  UnitSpace() = default;
  /**
   * @brief Serialization method for cereal.
   * @param ar Archive object.
   */
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _axes, _domain);
  }
};

}  // namespace spaces
}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::math::spaces::UnitSpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::spaces::UnitSpace)
#endif
