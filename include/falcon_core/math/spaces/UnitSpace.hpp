/**
 * @file UnitSpace.hpp
 * @brief Defines the UnitSpace class for FalconCore.
 */

#pragma once

#include "falcon_core/math/Axes.hpp"
#include "falcon_core/math/arrays/ControlArray1D.hpp"
#include "falcon_core/math/discretizers/BaseDiscretizer.hpp"
#include "falcon_core/math/domains/Domain.hpp"

namespace falcon_core::math::spaces {

/**
 * @brief Respresents a hypercube of measurement space. It is defined by a set
 * of axes, each of which can be discretized.
 *
 * This space can be compiled and packed into the space when necessary.
 *
 * @details
 * UnitSpace is the base class for spaces with axes and a domain.
 */
class UnitSpace : public math::Axes<discretizers::BaseDiscretizer> {
  domains::DomainSP              _domain;
  AxesSP<arrays::ControlArray1D> _ranges;
  generic::FArraySP<double>      _space;

  /**
   * @brief Store the computed discrete ranges.
   * @throws std::runtime_error if the discretizer is not supported.
   */
  void make_discrete_axes() const;

 public:
  /**
   * @brief Initialize a UnitSpace.
   * @param axes The axes defining the space.
   * @param domain The domain of the space.
   */
  UnitSpace(const AxesSP<discretizers::BaseDiscretizer>& axes,
            const domains::DomainSP&                     domain);
  /**
   * @brief Return the axes of the space.
   */
  const AxesSP<discretizers::BaseDiscretizer> axes() const;
  /**
   * @brief Return the domain of the space
   */
  const domains::DomainSP& domain() const;
  /**
   * @brief Return the stored space.
   */
  const generic::FArraySP<double>& space() const;
  /**
   * @brief Return the shape of the unit space.
   */
  const generic::ListSP<int> shape() const;
  /**
   * @brief Return the number of dimensions in the space.
   */
  const int dimension() const;
  /**
   * @brief Compile the unit space into a space.
   */
  void compile();
  /**
   * @brief Return the projection of the space onto the given axes.
   * The projection contains the indexes of the axes to project onto.
   * @param axes The axes to project onto.
   * @return A set of proper Control Arrays
   */
  const AxesSP<arrays::ControlArray> create_array(
      const AxesSP<int>& axes) const;

 protected:
  friend class cereal::access;
  UnitSpace();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<math::Axes<discretizers::BaseDiscretizer>>(this),
       _domain,
       _ranges,
       _space);
  }
};

}  // namespace falcon_core::math::spaces
