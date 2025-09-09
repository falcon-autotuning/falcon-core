#pragma once

#include <cereal/types/memory.hpp>
#include <cereal/types/vector.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace math {
namespace arrays {

template <typename T>
class FArray : public generic::Song {
 public:
  using value_type = T;
  using array_type = xt::xarray<T>;

  FArray() = default;
  FArray(const array_type& arr) : _data(arr) {}
  FArray(array_type&& arr) : _data(std::move(arr)) {}

  // Forwarding element access
  template <typename... Args>
  auto operator()(Args&&... args)
      -> decltype(_data(std::forward<Args>(args)...)) {
    return _data(std::forward<Args>(args)...);
  }
  template <typename... Args>
  auto operator()(Args&&... args) const
      -> decltype(_data(std::forward<Args>(args)...)) {
    return _data(std::forward<Args>(args)...);
  }

  // Forwarding shape, size, dimension
  auto shape() const { return _data.shape(); }
  auto size() const { return _data.size(); }
  auto dimension() const { return _data.dimension(); }
  auto data() { return _data.data(); }
  auto data() const { return _data.data(); }

  // Iterators
  auto begin() { return _data.begin(); }
  auto end() { return _data.end(); }
  auto cbegin() const { return _data.cbegin(); }
  auto cend() const { return _data.cend(); }

  // Arithmetic operators
  FArray& operator+=(const FArray& other) {
    _data += other._data;
    return *this;
  }
  FArray& operator-=(const FArray& other) {
    _data -= other._data;
    return *this;
  }
  FArray& operator*=(const FArray& other) {
    _data *= other._data;
    return *this;
  }
  FArray& operator/=(const FArray& other) {
    _data /= other._data;
    return *this;
  }

  // Slicing/view
  template <typename... Args>
  auto view(Args&&... args) {
    return xt::view(_data, std::forward<Args>(args)...);
  }
  template <typename... Args>
  auto view(Args&&... args) const {
    return xt::view(_data, std::forward<Args>(args)...);
  }

  // Assignment and conversion
  FArray& operator=(const array_type& arr) {
    _data = arr;
    return *this;
  }
  operator array_type&() { return _data; }
  operator const array_type&() const { return _data; }

  // Comparison
  bool operator==(const FArray& other) const { return _data == other._data; }
  bool operator!=(const FArray& other) const { return !(*this == other); }

  // Serialization
  template <class Archive>
  void serialize(Archive& ar) {
    std::vector<size_t> shape(_data.shape().begin(), _data.shape().end());
    ar(cereal::base_class<generic::Song>(this), shape, _data.storage());
    if (Archive::is_loading::value) {
      _data         = array_type::from_shape(shape);
      auto& storage = _data.storage();
      ar(storage);
    }
  }

  // Access to underlying xtensor
  array_type&       xtensor() { return _data; }
  const array_type& xtensor() const { return _data; }

 private:
  array_type _data;
};

}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
