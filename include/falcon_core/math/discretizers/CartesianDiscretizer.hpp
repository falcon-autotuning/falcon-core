/**
 * @file CartesianDiscretizer.hpp
 * @brief Defines the CartesianDiscretizer class for FalconCore.
 */

#pragma once

#include "falcon_core/math/discretizers/BaseDiscretizer.hpp"

namespace falcon_core::math::discretizers {

/**
 * @brief Discretizer for Cartesian axes.
 *
 * @details
 * Divides a domain into equal steps along a Cartesian axis.
 */
class CartesianDiscretizer : public BaseDiscretizer {
 public:
  CartesianDiscretizer(double delta);

 private:
  friend class cereal::access;
  CartesianDiscretizer();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseDiscretizer>(this));
  }
};
}  // namespace falcon_core::math::discretizers
