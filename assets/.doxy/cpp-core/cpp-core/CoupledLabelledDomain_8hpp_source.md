

# File CoupledLabelledDomain.hpp

[**File List**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**math**](dir_deeec2dd49335e06d18546a1be264a01.md) **>** [**domains**](dir_0f4cd819bc4c9a3cbf40e528a3341d04.md) **>** [**CoupledLabelledDomain.hpp**](CoupledLabelledDomain_8hpp.md)

[Go to the documentation of this file](CoupledLabelledDomain_8hpp.md)


```C++

#pragma once

#include "falcon_core/generic/List.hpp"
#include "falcon_core/instrument_interfaces/names/Ports.hpp"
#include "falcon_core/math/domains/LabelledDomain.hpp"

namespace falcon_core {
namespace math {
namespace domains {

class CoupledLabelledDomain : public generic::List<LabelledDomain> {
 public:
  CoupledLabelledDomain();
  CoupledLabelledDomain(const std::vector<LabelledDomainSP>& init);
  const std::vector<LabelledDomainSP> domains() const;
  const instrument_interfaces::names::PortsSP labels() const;

  LabelledDomainSP get_domain(
      const instrument_interfaces::names::InstrumentPortSP& search) const;
  bool operator==(const CoupledLabelledDomain& other) const;
  bool operator!=(const CoupledLabelledDomain& other) const;
};
using CoupledLabelledDomainSP = std::shared_ptr<CoupledLabelledDomain>;
}  // namespace domains
}  // namespace math
}  // namespace falcon_core
```


