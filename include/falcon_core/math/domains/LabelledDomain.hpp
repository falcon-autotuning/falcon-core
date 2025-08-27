/**
 * @file LabelledDomain.hpp
 * @brief Defines the LabelledDomain template for FalconCore.
 */

#pragma once

#include <cereal/types/memory.hpp>
#include <memory>
#include "falcon_core/math/domains/Domain.hpp"

namespace falcon_core {
namespace math {
namespace domains {

/**
 * @brief Domain with an associated label.
 * @tparam T Type of the label.
 */
template <typename T>
class LabelledDomain : public Domain {
 public:
  /**
   * @brief Construct a labelled domain.
   * @param min_val Minimum value of the domain.
   * @param max_val Maximum value of the domain.
   * @param label Shared pointer to the label.
   */
  LabelledDomain(double min_val, double max_val, std::shared_ptr<T> label)
      : Domain(min_val, max_val), _label(std::move(label)) {}

  /**
   * @brief Get the label.
   * @return Shared pointer to the label.
   */
  const std::shared_ptr<T>& label() const { return _label; }

 private:
  std::shared_ptr<T> _label;

  friend class cereal::access;
  LabelledDomain() = default;
  /**
   * @brief Serialization method for cereal.
   */
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Domain>(this), _label);
  }
};
}  // namespace domains
}  // namespace math
}  // namespace falcon_core
#ifndef SWIG

using namespace falcon_core::math::domains;
CEREAL_REGISTER_TYPE(falcon_core::math::domains::LabelledDomain<int>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::domains::LabelledDomain<int>)
#endif
