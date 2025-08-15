#pragma once

#include <memory>
#include <vector>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/math/labelled_arrays/BaseLabelledArray.hpp"

namespace falcon_core {
namespace math {
namespace labelled_arrays {
template <typename T>
class BaseLabelledArrays : public generic::Song {
 public:
  using value_type     = T;
  using container_type = std::vector<std::shared_ptr<value_type>>;

  BaseLabelledArrays() = default;

  void append(const std::shared_ptr<value_type> &labelled_array) {
    _arrays.push_back(labelled_array);
  }

  const container_type &get_arrays() const { return _arrays; }

 private:
  container_type _arrays;
};
}  // namespace labelled_arrays
}  // namespace math
}  // namespace falcon_core
