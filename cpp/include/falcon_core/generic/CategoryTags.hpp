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
}  // namespace category
}  // namespace generic
}  // namespace falcon_core
