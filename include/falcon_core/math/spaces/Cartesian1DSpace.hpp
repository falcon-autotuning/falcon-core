/**
 * @file Cartesian1DSpace.hpp
 * @brief Defines the Cartesian1DSpace class for FalconCore.
 */

#pragma once

#include "falcon_core/math/spaces/CartesianSpace.hpp"

namespace falcon_core {
namespace math {
namespace spaces {

/**
 * @brief Represents a 1D Cartesian space.
 */
class Cartesian1DSpace : public CartesianSpace {
 public:
  Cartesian1DSpace(double delta, std::shared_ptr<domains::Domain> domain);

 protected:
  friend class cereal::access;
  Cartesian1DSpace();
  template <class Archive>
  void serialize(Archive& ar);
};

}  // namespace spaces
}  // namespace math
}  // namespace falcon_core
