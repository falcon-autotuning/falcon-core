/**
 * @file PolarDiscretizer.hpp
 * @brief Defines the PolarDiscretizer class for FalconCore.
 */

#pragma once

#include "falcon_core/math/discretizers/BaseDiscretizer.hpp"
#include "falcon_core/Constants.hpp"
#include "falcon_core/math/domains/Domain.hpp"

namespace falcon_core {
namespace math {
namespace discretizers {

/**
 * @brief Discretizer for polar axes (angles).
 *
 * @details
 * Divides a domain into equal angular steps.
 */
class PolarDiscretizer : public BaseDiscretizer {
 public:
  /**
   * @brief Construct a PolarDiscretizer.
   * @param delta Angular step size.
   */
  PolarDiscretizer(double delta)
      : BaseDiscretizer(
            delta,
            std::make_shared<domains::Domain>(
                -2.0 * falcon_core::PI, 2.0 * falcon_core::PI)) {}

 private:
  friend class cereal::access;
  /**
   * @brief Default constructor for cereal.
   */
  PolarDiscretizer() = default;
  /**
   * @brief Serialization method for cereal.
   * @param ar Archive object.
   */
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseDiscretizer>(this));
  }
};

}  // namespace discretizers
}  // namespace math
}  // namespace falcon_core

using namespace falcon_core::math::discretizers;

#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::math::discretizers::PolarDiscretizer)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::discretizers::PolarDiscretizer)
#endif
