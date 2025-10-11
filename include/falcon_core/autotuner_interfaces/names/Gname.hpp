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
  /**
   * @brief Collect the gname as a string.
   */
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
