

# File FArrayProtocol.hpp

[**File List**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**generic**](dir_b58ad87d7b49f24215c248c1165fe6c1.md) **>** [**FArrayProtocol.hpp**](FArrayProtocol_8hpp.md)

[Go to the documentation of this file](FArrayProtocol_8hpp.md)


```C++
#pragma once

#include <xtensor/xshape.hpp>

#include "falcon_core/generic/List.hpp"

namespace falcon_core {
namespace generic {

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
  virtual T*                               raw_data() noexcept        = 0;
  virtual const T*                         raw_data() const noexcept  = 0;

  // Iterators
  virtual typename array_type::iterator       begin() noexcept        = 0;
  virtual typename array_type::iterator       end() noexcept          = 0;
  virtual typename array_type::const_iterator cbegin() const noexcept = 0;
  virtual typename array_type::const_iterator cend() const noexcept   = 0;

  // Math
  virtual T min() const = 0;
  virtual T max() const = 0;

  // View
  virtual array_type&       data() noexcept       = 0;
  virtual const array_type& data() const noexcept = 0;

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

}  // namespace generic
}  // namespace falcon_core
```


