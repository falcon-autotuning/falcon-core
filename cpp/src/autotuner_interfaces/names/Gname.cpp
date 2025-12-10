#include "falcon_core/autotuner_interfaces/names/Gname.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace names {
Gname::Gname() : NameBase() {}
Gname::Gname(const std::string& name)
    : NameBase(name.rfind("group", 0) == 0
                   ? NameBase(name, "group")
                   : NameBase(name)) {}
Gname::Gname(const int& num) : NameBase(num, "group") {}
std::string Gname::gname() const { return name(); }
bool        Gname::operator==(const Gname& other) const {
  return name() == other.name();
}
bool Gname::operator!=(const Gname& other) const { return !(*this == other); }
}  // namespace names
}  // namespace autotuner_interfaces
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::autotuner_interfaces::names::Gname)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::autotuner_interfaces::names::NameBase,
    falcon_core::autotuner_interfaces::names::Gname)
