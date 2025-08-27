#pragma once

#include "falcon_core/autotuner_interfaces/names/NameBase.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace names {
class Gname : public NameBase {
  std::string _index_string = "group";

 public:
  Gname(std::string name) : NameBase(name) {}
  Gname(int num) : NameBase(num) {}
  /**
   * @brief Collect the gname as a string.
   */
  std::string gname() const { return name(); }
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<NameBase>(this));
  }

 protected:
  Gname() = default;
  friend class cereal::access;
};
using GnameSP = std::shared_ptr<Gname>;
}  // namespace names
}  // namespace autotuner_interfaces
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core::autotuner_interfaces::names;
CEREAL_REGISTER_TYPE(Gname)
CEREAL_REGISTER_POLYMORPHIC_RELATION(NameBase, Gname)
#endif
