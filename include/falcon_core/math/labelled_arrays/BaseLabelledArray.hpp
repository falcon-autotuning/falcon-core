#pragma once

#include <cereal/types/memory.hpp>
#include <memory>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/math/arrays/BaseArray.hpp"

namespace falcon_core {
namespace math {
namespace labelled_arrays {
template <typename ArrayType, typename LabelType>
class BaseLabelledArray : public generic::Song {
 public:
  BaseLabelledArray(std::shared_ptr<ArrayType> array,
                    std::shared_ptr<LabelType> label)
      : _array(std::move(array)), _label(std::move(label)) {}

  const std::shared_ptr<ArrayType>& array() const { return _array; }
  const std::shared_ptr<LabelType>& label() const { return _label; }

 protected:
  std::shared_ptr<ArrayType> _array;
  std::shared_ptr<LabelType> _label;

 private:
  friend class cereal::access;
  BaseLabelledArray() = default;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _array, _label);
  }
};
}  // namespace labelled_arrays
}  // namespace math
}  // namespace falcon_core

using namespace falcon_core::math;
using BLA = labelled_arrays::BaseLabelledArray<arrays::BaseArray<double>, int>;

CEREAL_REGISTER_TYPE(BLA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, BLA)
