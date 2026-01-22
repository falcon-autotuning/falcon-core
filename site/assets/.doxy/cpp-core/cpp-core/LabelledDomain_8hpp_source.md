

# File LabelledDomain.hpp

[**File List**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**math**](dir_deeec2dd49335e06d18546a1be264a01.md) **>** [**domains**](dir_0f4cd819bc4c9a3cbf40e528a3341d04.md) **>** [**LabelledDomain.hpp**](LabelledDomain_8hpp.md)

[Go to the documentation of this file](LabelledDomain_8hpp.md)


```C++


#pragma once

#include <memory>

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/math/domains/Domain.hpp"
namespace falcon_core {
namespace math {
namespace domains {

class LabelledDomain : public Domain {
  instrument_interfaces::names::InstrumentPortSP _port;
  mutable std::shared_timed_mutex                _mu_port;

 public:
  LabelledDomain(const LabelledDomain& other);
  LabelledDomain& operator=(const LabelledDomain& other);
  LabelledDomain(
      const std::string&                              default_name,
      const std::pair<double, double>&                bounds,
      const physics::device_structures::ConnectionSP& psuedo_name,
      const instrument_interfaces::names::Instrument& instrument_type,
      bool                                            lesser_bound_contained,
      bool                                            greater_bound_contained,
      const physics::units::SymbolUnitSP&             units,
      const std::string&                              description,
      const instrument_interfaces::names::PortType    type =
          instrument_interfaces::names::PortType::Knob);
  static const std::shared_ptr<LabelledDomain> from_port(
      const std::pair<double, double>&                      bounds,
      const instrument_interfaces::names::InstrumentPortSP& port,
      const bool& lesser_bound_contained  = true,
      const bool& greater_bound_contained = true);
  static const std::shared_ptr<LabelledDomain> from_port_and_domain(
      const instrument_interfaces::names::InstrumentPortSP& port,
      const DomainSP&                                       domain);
  static const std::shared_ptr<LabelledDomain> from_domain(
      const DomainSP&                                 domain,
      const std::string&                              default_name,
      const physics::device_structures::ConnectionSP& pseudo_name,
      const instrument_interfaces::names::Instrument& instrument_type,
      const physics::units::SymbolUnitSP&             units =
          physics::units::SymbolUnit::Volt(),
      const std::string& description = "");

  const instrument_interfaces::names::InstrumentPortSP& port() const;
  std::shared_ptr<Domain> domain() const;
  bool matching_port(
      const instrument_interfaces::names::InstrumentPortSP& port) const;
  bool operator==(const LabelledDomain& other) const;
  bool operator!=(const LabelledDomain& other) const;

 protected:
  LabelledDomain();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_port(_mu_port);
    ar(cereal::base_class<Domain>(this), _port);
  }
};
using LabelledDomainSP = std::shared_ptr<LabelledDomain>;
}  // namespace domains
}  // namespace math
}  // namespace falcon_core
```


