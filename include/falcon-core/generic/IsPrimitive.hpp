#pragma once

#include <string>
#include <type_traits>

namespace falcon_core {
namespace generic {
// Helper that decides if a type is primitve or not
template <typename T>
struct is_primitive
    : std::integral_constant<
          bool,
          std::is_arithmetic<T>::value || std::is_same<T, std::string>::value ||
              std::is_same<T, char>::value || std::is_same<T, bool>::value> {};
}  // namespace generic
}  // namespace falcon_core
