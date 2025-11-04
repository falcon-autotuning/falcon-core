#include "falcon_core/autotuner_interfaces/names/Gname.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace names {
Gname::Gname() : NameBase() {}
Gname::Gname(const std::string& name)
    : Gname(name.rfind("group", 0) == 0
                ? Gname(std::stoi(name.substr(std::string("group").length())))
                : Gname()) {
  if (name.rfind("group", 0) != 0) {
    // This is a hack to allow for non-standard gnames.
    // The delegating constructor calls the default constructor,
    // then we overwrite the name.
    const_cast<std::string&>(this->name()) = name;
  }
}
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
