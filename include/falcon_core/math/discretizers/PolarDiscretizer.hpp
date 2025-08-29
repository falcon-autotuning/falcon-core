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
  PolarDiscretizer(double delta);
  PolarDiscretizer();

  template <class Archive>
  void serialize(Archive& ar);
};

}  // namespace discretizers
}  // namespace math
}  // namespace falcon_core
