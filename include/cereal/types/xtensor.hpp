#pragma once

#include <cereal/cereal.hpp>
#include <cereal/types/vector.hpp>
#include <xtensor/containers/xarray.hpp>
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
