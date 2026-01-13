

# File IsPrimitive.hpp

[**File List**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**generic**](dir_b58ad87d7b49f24215c248c1165fe6c1.md) **>** [**IsPrimitive.hpp**](IsPrimitive_8hpp.md)

[Go to the documentation of this file](IsPrimitive_8hpp.md)


```C++
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
```


