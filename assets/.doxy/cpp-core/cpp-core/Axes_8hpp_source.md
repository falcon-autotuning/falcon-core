

# File Axes.hpp

[**File List**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**math**](dir_deeec2dd49335e06d18546a1be264a01.md) **>** [**Axes.hpp**](Axes_8hpp.md)

[Go to the documentation of this file](Axes_8hpp.md)


```C++
#pragma once

#include "falcon_core/generic/List.hpp"

namespace falcon_core {
namespace math {
template <typename Value>
static const generic::List<Value>& list_check_and_deref(
    const generic::ListSP<Value>& items) {
  if (!items) throw std::invalid_argument("Axes: items must not be null.");
  return *items;
}
template <typename Value>
class Axes : public generic::List<Value> {
 public:
  Axes() = default;
  explicit Axes(const typename generic::List<Value>::Container& items)
      : generic::List<Value>(items) {}
  explicit Axes(const generic::ListSP<Value>& items)
      : generic::List<Value>(list_check_and_deref<Value>(items)) {}
  bool operator==(const Axes<Value>& other) const {
    return operator_equal_impl(
        other, typename generic::category::determine_tag<Value>::type{});
  }
  bool operator!=(const Axes<Value>& other) const { return !(*this == other); }

 protected:
  bool operator_equal_impl(const Axes<Value>& other,
                           generic::category::song_tag) const {
    if (this->size() != other.size()) {
      return false;
    }
    for (size_t i = 0; i < this->size(); i++) {
      const std::shared_ptr<Value> our_conn   = this->at(i);
      const std::shared_ptr<Value> other_conn = other.at(i);
      if (*our_conn != *other_conn) {
        return false;
      }
    }
    return true;
  }
  bool operator_equal_impl(const Axes<Value>& other,
                           generic::category::primitive_tag) const {
    if (this->size() != other.size()) {
      return false;
    }
    for (size_t i = 0; i < this->size(); i++) {
      const Value our_conn   = this->at(i);
      const Value other_conn = other.at(i);
      if (our_conn != other_conn) {
        return false;
      }
    }
    return true;
  }
  bool operator_equal_impl(const Axes<Value>& other,
                           generic::category::other_tag) const {
    throw std::runtime_error("Unsupported type for Axes");
  }
};
template <typename V>
using AxesSP = std::shared_ptr<Axes<V>>;
}  // namespace math
}  // namespace falcon_core
```


