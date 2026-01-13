

# File Ports.hpp

[**File List**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**instrument\_interfaces**](dir_1d63ba24e228ec3f87efddb1c2728844.md) **>** [**names**](dir_a1bb891a070db74bff5519c1e6868927.md) **>** [**Ports.hpp**](Ports_8hpp.md)

[Go to the documentation of this file](Ports_8hpp.md)


```C++
#pragma once

#include "falcon_core/generic/List.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace names {

// Generic collection of instrument ports
class Ports : public generic::List<InstrumentPort> {
 public:
  Ports();
  Ports(const std::vector<InstrumentPortSP> ports);
  Ports(const generic::ListSP<InstrumentPort> ports);
  generic::ListSP<InstrumentPort> ports() const;
  generic::ListSP<std::string> get_default_names() const;
  generic::ListSP<physics::device_structures::Connection> get_pseudo_names()
      const;
  generic::ListSP<std::string> _get_raw_names() const;
  generic::ListSP<std::string> _get_instrument_facing_names() const;
  InstrumentPortSP _get_psuedoname_matching_port(
      const physics::device_structures::ConnectionSP& name) const;
  InstrumentPortSP _get_instrument_type_matching_port(
      const Instrument& type) const;
  const bool is_knobs() const;
  const bool is_meters() const;
  bool       operator==(const Ports& other) const;
  bool       operator!=(const Ports& other) const;
};
using PortsSP = std::shared_ptr<Ports>;
}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core
```


