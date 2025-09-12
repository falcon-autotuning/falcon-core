/**
 * @file PolarDiscretizer.hpp
 * @brief Defines the PolarDiscretizer class for FalconCore.
 */

#pragma once

#include "falcon_core/math/discretizers/BaseDiscretizer.hpp"

namespace falcon_core::math::discretizers {

/**
 * @brief Discretizer for polar axes (angles).
 *
 * @details
 * Divides a domain into equal angular steps.
 */
class PolarDiscretizer : public BaseDiscretizer {
 public:
  PolarDiscretizer(double delta);

 private:
  friend class cereal::access;
  PolarDiscretizer();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseDiscretizer>(this));
  }
};
}  // namespace falcon_core::math::discretizers
