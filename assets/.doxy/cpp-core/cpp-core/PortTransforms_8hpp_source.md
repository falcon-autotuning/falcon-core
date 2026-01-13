

# File PortTransforms.hpp

[**File List**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**instrument\_interfaces**](dir_1d63ba24e228ec3f87efddb1c2728844.md) **>** [**port\_transforms**](dir_d7bc952b8ca4307cb9fd2891297c099c.md) **>** [**PortTransforms.hpp**](PortTransforms_8hpp.md)

[Go to the documentation of this file](PortTransforms_8hpp.md)


```C++
#pragma once

#include "falcon_core/generic/List.hpp"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"
namespace falcon_core {
namespace instrument_interfaces {
namespace port_transforms {

class PortTransforms : public generic::List<PortTransform> {
 public:
  PortTransforms(const PortTransforms& other);
  PortTransforms();
  PortTransforms(const generic::ListSP<PortTransform>& init);
  PortTransforms(const std::vector<PortTransformSP>& init);
  const generic::ListSP<PortTransform> transforms() const;
};
using PortTransformsSP = std::shared_ptr<PortTransforms>;
}  // namespace port_transforms
}  // namespace instrument_interfaces
}  // namespace falcon_core
```


