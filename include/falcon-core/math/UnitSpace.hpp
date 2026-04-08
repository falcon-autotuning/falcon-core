/**
 * @file UnitSpace.hpp
 * @brief Defines the UnitSpace class for FalconCore.
 */

#pragma once

#include "falcon-core/export.h"
#include "falcon-core/math/Axes.hpp"
#include "falcon-core/math/arrays/ControlArray1D.hpp"
#include "falcon-core/math/discrete_spaces/Discretizer.hpp"

namespace falcon_core {
namespace math {

/**
 * @brief Respresents a hypercube of measurement space. It is defined by a set
 * of axes, each of which can be discretized.
 *
 * This space can be compiled and packed into the space when necessary.
 *
 * @details
 * UnitSpace is the base class for spaces with axes and a domain.
 */
class FALCON_CORE_CPP_API UnitSpace
    : public math::Axes<discrete_spaces::Discretizer> {
  domains::DomainSP               _domain;
  AxesSP<arrays::ControlArray1D>  _ranges;
  generic::FArraySP<double>       _space;
  mutable std::shared_timed_mutex _mu_space;
  mutable std::shared_timed_mutex _mu_ranges;
  mutable std::shared_timed_mutex _mu_domain;

  /**
   * @brief Store the computed discrete ranges.
   * @throws std::runtime_error if the discretizer is not supported.
   */
  void make_discrete_axes();

 public:
  UnitSpace(const UnitSpace& other);
  UnitSpace& operator=(const UnitSpace& other);
  /**
   * @brief Initialize a UnitSpace.
   * @param axes The axes defining the space.
   * @param domain The domain of the space.
   */
  UnitSpace(const AxesSP<discrete_spaces::Discretizer>& axes,
            const domains::DomainSP&                    domain);
  /**
   * @brief Create a ray space with radial and angular discretization.
   * @param dr the radial delta.
   * @param dtheta the angular delta.
   * @param domain The domain of the space.
   */
  static std::shared_ptr<UnitSpace> RaySpace(const double&            dr,
                                             const double&            dtheta,
                                             const domains::DomainSP& domain);
  /**
   * @brief Create a ND cartesian space.
   * @param deltas The discretizations for each axis.
   * @param domain The domain of the space.
   */
  static std::shared_ptr<UnitSpace> CartesianSpace(
      const AxesSP<double>& deltas, const domains::DomainSP& domain);
  /**
   * @brief Create a 1D cartesian space.
   * @param delta The discretization for the main axis.
   * @param domain The domain of the space.
   */
  static std::shared_ptr<UnitSpace> Cartesian1DSpace(
      const double& delta, const domains::DomainSP& domain);
  /**
   * @brief Create a 2D cartesian space.
   * @param deltas The discretizations for each axis.
   * @param domain The domain of the space.
   */
  static std::shared_ptr<UnitSpace> Cartesian2DSpace(
      const AxesSP<double>& deltas, const domains::DomainSP& domain);
  /**
   * @brief Return the axes of the space.
   */
  const AxesSP<discrete_spaces::Discretizer> axes() const;
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
  bool operator==(const UnitSpace& other) const;
  bool operator!=(const UnitSpace& other) const;

 protected:
  friend class cereal::access;
  UnitSpace();
  template <class Archive>
  inline void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_domain(_mu_domain,
                                                          std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_ranges(_mu_ranges,
                                                          std::defer_lock);
    std::lock(lock_domain, lock_ranges);
    ar(cereal::base_class<math::Axes<discrete_spaces::Discretizer>>(this),
       _domain,
       _ranges);
  }
};
using UnitSpaceSP = std::shared_ptr<UnitSpace>;
}  // namespace math
}  // namespace falcon_core
