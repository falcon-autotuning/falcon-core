#pragma once

#include <cereal/types/memory.hpp>
#include <cereal/types/vector.hpp>
#include <xtensor/containers/xarray.hpp>
#include <xtensor/io/xio.hpp>
#include <xtensor/views/xview.hpp>

#include "falcon_core/generic/Song.hpp"
#define XTENSOR_ENABLE_CEREAL
#include <cereal/archives/binary.hpp>

namespace falcon_core {
namespace math {
namespace arrays {

template <typename T>
class FArray : public generic::Song {
 public:
  using array_type      = xt::xarray<T>;
  using value_type      = T;
  using reference       = T&;
  using const_reference = const T&;

  FArray() = default;
  FArray(const array_type& arr) : _data(arr) {}
  FArray(array_type&& arr) noexcept : _data(std::move(arr)) {}
  explicit FArray(const std::vector<size_t>& shape) : _data(shape) {}

  FArray(const FArray&)                = default;
  FArray(FArray&&) noexcept            = default;
  FArray& operator=(const FArray&)     = default;
  FArray& operator=(FArray&&) noexcept = default;

  static FArray zeros(const std::vector<size_t>& shape) {
    return FArray(xt::zeros<T>(shape));
  }
  static FArray empty(const std::vector<size_t>& shape) {
    return FArray(xt::empty<T>(shape));
  }

  template <typename... Args>
  decltype(auto) operator()(Args&&... args) {
    return _data(std::forward<Args>(args)...);
  }
  template <typename... Args>
  decltype(auto) operator()(Args&&... args) const {
    return _data(std::forward<Args>(args)...);
  }

  [[nodiscard]] const auto& shape() const noexcept { return _data.shape(); }
  [[nodiscard]] auto        size() const noexcept { return _data.size(); }
  [[nodiscard]] auto dimension() const noexcept { return _data.dimension(); }
  [[nodiscard]] auto data() noexcept { return _data.data(); }
  [[nodiscard]] auto data() const noexcept { return _data.data(); }

  auto begin() noexcept { return _data.begin(); }
  auto end() noexcept { return _data.end(); }
  auto cbegin() const noexcept { return _data.cbegin(); }
  auto cend() const noexcept { return _data.cend(); }

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

  template <typename... Args>
  decltype(auto) view(Args&&... args) {
    return xt::view(_data, std::forward<Args>(args)...);
  }
  template <typename... Args>
  decltype(auto) view(Args&&... args) const {
    return xt::view(_data, std::forward<Args>(args)...);
  }

  // Assignment and conversion
  FArray& operator=(const array_type& arr) {
    _data = arr;
    return *this;
  }
  operator array_type&() { return _data; }
  operator const array_type&() const { return _data; }

  bool operator==(const FArray& other) const { return _data == other._data; }
  bool operator!=(const FArray& other) const { return !(*this == other); }

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this));
    ar(_data);
  }

  array_type&       xtensor() noexcept { return _data; }
  const array_type& xtensor() const noexcept { return _data; }

 private:
  array_type _data;
};

}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
