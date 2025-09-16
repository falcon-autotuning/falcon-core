#include "falcon_core/autotuner_interfaces/names/NameBase.hpp"

namespace falcon_core::autotuner_interfaces::names {

NameBase::NameBase(const std::string& name) : _name(name) {
  _num = std::stoi(name.substr(_index_string.length()));
}
NameBase::NameBase(const int& num) : _num(num) {
  _name = _index_string + std::to_string(num);
}
std::string NameBase::name() const { return _name; }
int         NameBase::num() const { return _num; }

NameBaseSP NameBase::operator+(const NameBase& other) const {
  return std::make_shared<NameBase>(this->num() + other.num());
}
NameBaseSP NameBase::operator-(const NameBase& other) const {
  return std::make_shared<NameBase>(this->num() - other.num());
}
}  // namespace falcon_core::autotuner_interfaces::names
CEREAL_REGISTER_TYPE(falcon_core::autotuner_interfaces::names::NameBase)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::autotuner_interfaces::names::NameBase)
