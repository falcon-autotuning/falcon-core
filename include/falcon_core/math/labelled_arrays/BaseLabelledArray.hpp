#pragma once

#include <cereal/types/memory.hpp>
#include <memory>

#include "falcon_core/generic/Song.hpp"

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
