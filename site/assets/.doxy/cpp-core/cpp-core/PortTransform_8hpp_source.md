

# File PortTransform.hpp

[**File List**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**instrument\_interfaces**](dir_1d63ba24e228ec3f87efddb1c2728844.md) **>** [**port\_transforms**](dir_d7bc952b8ca4307cb9fd2891297c099c.md) **>** [**PortTransform.hpp**](PortTransform_8hpp.md)

[Go to the documentation of this file](PortTransform_8hpp.md)


```C++
#pragma once

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/math/AnalyticFunction.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace port_transforms {

class PortTransform : public math::AnalyticFunction {
  names::InstrumentPortSP         _port;
  mutable std::shared_timed_mutex _mu_port;

 public:
  PortTransform(const PortTransform& other);
  PortTransform& operator=(const PortTransform& other);
  PortTransform(const names::InstrumentPortSP&  port,
                const math::AnalyticFunctionSP& transform);
  static std::shared_ptr<PortTransform> ConstantTransform(
      const names::InstrumentPortSP& port, const double& value);
  static std::shared_ptr<PortTransform> IdentityTransform(
      const names::InstrumentPortSP& port);
  const names::InstrumentPortSP port() const;
  bool                          operator==(const PortTransform& other) const;
  bool                          operator!=(const PortTransform& other) const;

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_p(_mu_port);
    ar(cereal::base_class<math::AnalyticFunction>(this), _port);
  };
  PortTransform();
};
using PortTransformSP = std::shared_ptr<PortTransform>;
}  // namespace port_transforms
}  // namespace instrument_interfaces
}  // namespace falcon_core
```


