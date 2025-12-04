#pragma once
#include "falcon_core/generic/IsPrimitive.hpp"
#include "falcon_core/generic/Song.hpp"
namespace falcon_core {
namespace generic {
namespace category {
struct song_tag {};
struct primitive_tag {};
struct bool_tag {};
struct other_tag {};

template <typename T>
struct determine_tag {
  using type = std::conditional_t<
      std::is_base_of<Song, T>::value && !is_primitive<T>::value,
      song_tag,
      std::conditional_t<is_primitive<T>::value, primitive_tag, other_tag>>;
};
template <typename T>
struct determine_bool_tag {
  using type =
      std::conditional_t<std::is_same<T, bool>::value, bool_tag, other_tag>;
};
template <typename T>
struct is_shared_ptr : std::false_type {};

template <typename T>
struct is_shared_ptr<std::shared_ptr<T>> : std::true_type {};
// For shared_ptr types
template <typename T>
bool compare_value(const T& a, const T& b, std::true_type /*is_ptr*/) {
  if (!a || !b) return false;
  return *a == *b;
}

// For non-pointer types
template <typename T>
bool compare_value(const T& a, const T& b, std::false_type /*is_ptr*/) {
  return a == b;
}
}  // namespace category
}  // namespace generic
}  // namespace falcon_core
