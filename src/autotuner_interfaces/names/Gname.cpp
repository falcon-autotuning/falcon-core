#include "falcon_core/autotuner_interfaces/names/Gname.hpp"

namespace falcon_core::autotuner_interfaces::names {
Gname::Gname() : NameBase() {}
Gname::Gname(const std::string& name) : NameBase(name) {}
Gname::Gname(const int& num) : NameBase(num) {}
std::string Gname::gname() const { return name(); }
}  // namespace falcon_core::autotuner_interfaces::names
CEREAL_REGISTER_TYPE(falcon_core::autotuner_interfaces::names::Gname)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::autotuner_interfaces::names::NameBase,
    falcon_core::autotuner_interfaces::names::Gname)
