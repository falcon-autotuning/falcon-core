

# File xtensor.hpp

[**File List**](files.md) **>** [**cereal**](dir_254c24e7a692cc8d0840008ecd80fdac.md) **>** [**types**](dir_ecdc6e8e768a84f1e8450c29e072ccdb.md) **>** [**xtensor.hpp**](xtensor_8hpp.md)

[Go to the documentation of this file](xtensor_8hpp.md)


```C++
#pragma once

#include <cereal/cereal.hpp>
#include <cereal/types/vector.hpp>
#include <xtensor/xarray.hpp>
namespace cereal {
// Save for xt::xarray
template <class Archive, class T>
void save(Archive& ar, const xt::xarray<T>& arr) {
  std::vector<size_t> shape(arr.shape().begin(), arr.shape().end());
  std::vector<T>      flat(arr.begin(), arr.end());
  ar(shape, flat);
}

// Load for xt::xarray
template <class Archive, class T>
void load(Archive& ar, xt::xarray<T>& arr) {
  std::vector<size_t> shape;
  std::vector<T>      flat;
  ar(shape, flat);
  arr = xt::xarray<T>::from_shape(shape);
  std::copy(flat.begin(), flat.end(), arr.begin());
}
}  // namespace cereal
```


