/**
 * @file BaseLabelledArray.hpp
 * @brief Defines the BaseLabelledArray template for FalconCore.
 */

#pragma once

#include <cereal/types/memory.hpp>
#include <memory>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/math/arrays/BaseArray.hpp"

namespace falcon_core {
namespace math {
namespace labelled_arrays {

/// @brief Associates an array with a label.
/// @tparam ArrayType Type of the array.
/// @tparam LabelType Type of the label.
template <typename ArrayType, typename LabelType>
class BaseLabelledArray : public generic::Song {
 public:
  BaseLabelledArray(std::shared_ptr<ArrayType> array,
                    std::shared_ptr<LabelType> label);

  const std::shared_ptr<ArrayType>& array() const;
  const std::shared_ptr<LabelType>& label() const;

 protected:
  std::shared_ptr<ArrayType> _array;
  std::shared_ptr<LabelType> _label;

 private:
  friend class cereal::access;
  BaseLabelledArray();
  template <class Archive>
  void serialize(Archive& ar);
};
}  // namespace labelled_arrays
}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
using namespace falcon_core::math;
using BLA = labelled_arrays::BaseLabelledArray<arrays::BaseArray<double>, int>;

CEREAL_REGISTER_TYPE(BLA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, BLA)
#endif
