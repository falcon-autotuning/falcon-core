

# File Prefix.hpp

[**File List**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**physics**](dir_ef8a5933242b0e98f781c5d9eb0e15a8.md) **>** [**units**](dir_666a9a136551104f62f39018fd37905b.md) **>** [**Prefix.hpp**](Prefix_8hpp.md)

[Go to the documentation of this file](Prefix_8hpp.md)


```C++
#pragma once

#include <map>
#include <string>

namespace falcon_core {
namespace physics {
namespace units {

class Prefix {
 public:
  static const std::map<std::string, int>& get_symbol_to_power_map();
  static const std::map<int, std::string>& get_power_to_symbol_map();
  static std::string get_symbol(int prefix_value);
  static int get_value(std::string prefix_symbol);
  static bool is_valid(std::string prefix_symbol);
  static std::pair<double, std::string> prefix_multiplication(
      std::string first_prefix, std::string second_prefix, double scale_factor);
};
}  // namespace units
}  // namespace physics
}  // namespace falcon_core
```


