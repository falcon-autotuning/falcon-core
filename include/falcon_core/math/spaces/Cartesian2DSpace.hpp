/**
 * @file Cartesian2DSpace.hpp
 * @brief Defines the Cartesian2DSpace class for FalconCore.
 */

#pragma once

#include "falcon_core/math/spaces/CartesianSpace.hpp"

namespace falcon_core {
namespace math {
namespace spaces {

/**
 * @brief Represents a 2D Cartesian space.
 */
class Cartesian2DSpace : public CartesianSpace {
 public:
  /**
   * @brief Construct a 2D Cartesian space.
   * @param deltas Vector of two discretization steps.
   * @param domain Shared pointer to the domain.
   * @throws std::invalid_argument if deltas.size() != 2.
   */
  Cartesian2DSpace(const std::vector<double>&       deltas,
                   std::shared_ptr<domains::Domain> domain)
      : CartesianSpace(deltas, domain) {
    if (deltas.size() != 2) {
      throw std::invalid_argument("A 2D space must have two deltas.");
    }
  }

 protected:
  friend class cereal::access;
  /**
   * @brief Default constructor for cereal access.
   */
  Cartesian2DSpace() = default;
  /**
   * @brief Serialization method for cereal.
   * @param ar Archive object.
   */
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<CartesianSpace>(this));
  }
};

}  // namespace spaces
}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::math::spaces::Cartesian2DSpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::spaces::Cartesian2DSpace)
#endif
