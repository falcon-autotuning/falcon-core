

# File BaseContext.hpp

[**File List**](files.md) **>** [**autotuner\_interfaces**](dir_f103c4a8c56717e1b25b9ff095326f77.md) **>** [**contexts**](dir_78197d33e09341695ca03f828462ffe3.md) **>** [**BaseContext.hpp**](BaseContext_8hpp.md)

[Go to the documentation of this file](BaseContext_8hpp.md)


```C++
#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/instrument_interfaces/names/Instrument.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
namespace falcon_core {
namespace autotuner_interfaces {
namespace contexts {
class BaseContext : public generic::Song {
  physics::device_structures::ConnectionSP _connection;
  instrument_interfaces::names::Instrument _instrument_type;
  mutable std::shared_timed_mutex          _mu_connection;
  mutable std::shared_timed_mutex          _mu_instrument_type;

 public:
  BaseContext(const BaseContext& other);
  BaseContext& operator=(const BaseContext& other);
  BaseContext(const physics::device_structures::ConnectionSP& connection,
              const instrument_interfaces::names::Instrument& instrument_type);
  BaseContext(const instrument_interfaces::names::InstrumentPortSP& port);
  const physics::device_structures::ConnectionSP connection() const;
  const instrument_interfaces::names::Instrument instrument_type() const;

  bool operator==(const BaseContext& other) const;
  bool operator!=(const BaseContext& other) const;

 protected:
  friend class cereal::access;
  BaseContext();
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_c(_mu_connection,
                                                     std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_i(_mu_instrument_type,
                                                     std::defer_lock);
    std::lock(lock_c, lock_i);
    ar(cereal::base_class<generic::Song>(this), _connection, _instrument_type);
  }
};
using BaseContextSP = std::shared_ptr<BaseContext>;
}  // namespace contexts
}  // namespace autotuner_interfaces
}  // namespace falcon_core
```


