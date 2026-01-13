

# File Gname.hpp

[**File List**](files.md) **>** [**autotuner\_interfaces**](dir_f103c4a8c56717e1b25b9ff095326f77.md) **>** [**names**](dir_8292229a53142724ca7ed55be1de9aba.md) **>** [**Gname.hpp**](Gname_8hpp.md)

[Go to the documentation of this file](Gname_8hpp.md)


```C++
#pragma once

#include "falcon_core/autotuner_interfaces/names/NameBase.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace names {
class Gname : public NameBase {
  std::string _index_string = "group";

 public:
  Gname(const std::string& name);
  Gname(const int& num);
  std::string gname() const;
  bool        operator==(const Gname& other) const;
  bool        operator!=(const Gname& other) const;

 protected:
  Gname();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<NameBase>(this));
  }
};
using GnameSP = std::shared_ptr<Gname>;
}  // namespace names
}  // namespace autotuner_interfaces
}  // namespace falcon_core
```


