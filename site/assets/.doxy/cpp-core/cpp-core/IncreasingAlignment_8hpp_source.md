

# File IncreasingAlignment.hpp

[**File List**](files.md) **>** [**arrays**](dir_1ba4fdf981bee86d96b3ddb48a8d8b03.md) **>** [**IncreasingAlignment.hpp**](IncreasingAlignment_8hpp.md)

[Go to the documentation of this file](IncreasingAlignment_8hpp.md)


```C++


#pragma once

#include <shared_mutex>

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace math {
namespace arrays {

class IncreasingAlignment : public generic::Song {
  int                             _alignment;
  mutable std::shared_timed_mutex _mu_alignment;

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_a(_mu_alignment);
    ar(cereal::base_class<falcon_core::generic::Song>(this), _alignment);
  }

 public:
  IncreasingAlignment(const IncreasingAlignment& other);
  IncreasingAlignment& operator=(const IncreasingAlignment& other);
  IncreasingAlignment();
  IncreasingAlignment(const bool alignment);
  int  alignment() const;
  bool operator==(const IncreasingAlignment& other) const;
  bool operator!=(const IncreasingAlignment& other) const;
};
using IncreasingAlignmentSP = std::shared_ptr<IncreasingAlignment>;
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
```


