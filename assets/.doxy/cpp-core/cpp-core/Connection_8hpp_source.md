

# File Connection.hpp

[**File List**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**physics**](dir_ef8a5933242b0e98f781c5d9eb0e15a8.md) **>** [**device\_structures**](dir_30b06ebaf5519c029f1c8cff468fc8e6.md) **>** [**Connection.hpp**](Connection_8hpp.md)

[Go to the documentation of this file](Connection_8hpp.md)


```C++
#pragma once

#include <mutex>
#include <shared_mutex>

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {
enum class DeviceFeature {
  BarrierGate,
  PlungerGate,
  ReservoirGate,
  ScreeningGate,
  Ohmic
};
static const std::map<DeviceFeature, std::string> DeviceFeatureNames = {
    {DeviceFeature::BarrierGate, "BarrierGate"},
    {DeviceFeature::PlungerGate, "PlungerGate"},
    {DeviceFeature::ReservoirGate, "ReservoirGate"},
    {DeviceFeature::ScreeningGate, "ScreeningGate"},
    {DeviceFeature::Ohmic, "Ohmic"}};
class Connection : public virtual generic::Song {
  std::string                     _name;
  DeviceFeature                   _type;
  mutable std::shared_timed_mutex _mu_name;
  mutable std::shared_timed_mutex _mu_type;

 public:
  Connection(const Connection& other);
  Connection& operator=(const Connection& other);
  bool        operator<(const Connection& other) const;
  Connection(const std::string& name, const DeviceFeature& type);
  static std::shared_ptr<Connection> BarrierGate(const std::string& name);
  static std::shared_ptr<Connection> PlungerGate(const std::string& name);
  static std::shared_ptr<Connection> ReservoirGate(const std::string& name);
  static std::shared_ptr<Connection> ScreeningGate(const std::string& name);
  static std::shared_ptr<Connection> Ohmic(const std::string& name);
  const std::string name() const;
  const std::string type() const;
  bool is_dot_gate() const;
  bool is_barrier_gate() const;
  bool is_plunger_gate() const;
  bool is_reservoir_gate() const;
  bool is_screening_gate() const;
  bool is_ohmic() const;
  bool is_gate() const;
  bool operator==(const Connection& other) const;
  bool operator!=(const Connection& other) const;

 protected:
  friend class cereal::access;
  Connection();
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_name(_mu_name,
                                                        std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_type(_mu_type,
                                                        std::defer_lock);
    std::lock(lock_name, lock_type);
    ar(cereal::base_class<falcon_core::generic::Song>(this), _name, _type);
  }
};
using ConnectionSP = std::shared_ptr<Connection>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
```


