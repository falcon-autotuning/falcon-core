

# File MeasurementContext.hpp

[**File List**](files.md) **>** [**autotuner\_interfaces**](dir_f103c4a8c56717e1b25b9ff095326f77.md) **>** [**contexts**](dir_78197d33e09341695ca03f828462ffe3.md) **>** [**MeasurementContext.hpp**](MeasurementContext_8hpp.md)

[Go to the documentation of this file](MeasurementContext_8hpp.md)


```C++
#pragma once

#include "falcon_core/autotuner_interfaces/contexts/BaseContext.hpp"
#include "falcon_core/instrument_interfaces/names/Instrument.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace contexts {

class MeasurementContext : public contexts::BaseContext {
 protected:
  friend class cereal::access;
  MeasurementContext();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<contexts::BaseContext>(this));
  }

 public:
  MeasurementContext(const MeasurementContext& other);
  MeasurementContext& operator=(const MeasurementContext& other);
  MeasurementContext(
      const physics::device_structures::ConnectionSP& connection,
      const instrument_interfaces::names::Instrument& instrument_type);

  MeasurementContext(const contexts::BaseContextSP& acquisition_context);
};
using MeasurementContextSP = std::shared_ptr<MeasurementContext>;
}  // namespace contexts
}  // namespace autotuner_interfaces
}  // namespace falcon_core
```


