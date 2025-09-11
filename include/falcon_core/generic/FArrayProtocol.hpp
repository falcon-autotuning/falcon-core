#pragma once

#include "falcon_core/generic/List.hpp"
#include "xtensor/core/xshape.hpp"

namespace falcon_core::generic {

template <typename T>
class IFArray {
 public:
  using array_type      = xt::xarray<T>;
  using value_type      = T;
  using reference       = T&;
  using const_reference = const T&;

  virtual ~IFArray() = default;

  // Element access
  virtual reference       operator()(size_t i)       = 0;
  virtual const_reference operator()(size_t i) const = 0;

  // Properties
  virtual const xt::dynamic_shape<size_t>& shape() const noexcept     = 0;
  virtual size_t                           size() const noexcept      = 0;
  virtual size_t                           dimension() const noexcept = 0;
  virtual T*                               data() noexcept            = 0;
  virtual const T*                         data() const noexcept      = 0;

  // Iterators
  virtual size_t begin() noexcept        = 0;
  virtual size_t end() noexcept          = 0;
  virtual size_t cbegin() const noexcept = 0;
  virtual size_t cend() const noexcept   = 0;

  // Math
  virtual T min() const = 0;
  virtual T max() const = 0;

  // View
  virtual array_type&       xtensor() noexcept       = 0;
  virtual const array_type& xtensor() const noexcept = 0;

  // Assignment and conversion
  virtual operator array_type&()             = 0;
  virtual operator const array_type&() const = 0;

  // Comparison
  virtual bool operator>(const T& value) const = 0;
  virtual bool operator<(const T& value) const = 0;

  // Offset
  virtual void remove_offset(const T& offset) = 0;

  // Sum
  virtual T sum() const = 0;

  // Where
  virtual ListSP<List<size_t>> where(const T& value) const = 0;
};

}  // namespace falcon_core::generic
