#include "falcon_core/autotuner_interfaces/names/NameBase.hpp"

#include <stdexcept>

namespace falcon_core {
namespace autotuner_interfaces {
namespace names {

NameBase::NameBase(const std::string& name)
    : _name(name), _num(-1), _index_string("") {}
NameBase::NameBase(const std::string& name, const std::string& index_string)
    : _name(name), _index_string(index_string) {
  _num = std::stoi(name.substr(_index_string.length()));
}
NameBase::NameBase(const int& num, const std::string& index_string)
    : _num(num), _index_string(index_string) {
  _name = _index_string + std::to_string(num);
}
std::string NameBase::name() const { return _name; }
int         NameBase::num() const { return _num; }

NameBaseSP NameBase::operator+(const NameBaseSP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "NameBase: The other name to be added needs to be not null.");
  }
  return std::make_shared<NameBase>(this->num() + other->num(),
                                    this->_index_string);
}
NameBaseSP NameBase::operator-(const NameBaseSP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "NameBase: The other name to be subtracted needs to be not null.");
  }
  return std::make_shared<NameBase>(this->num() - other->num(),
                                    this->_index_string);
}
}  // namespace names
}  // namespace autotuner_interfaces
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::autotuner_interfaces::names::NameBase)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::autotuner_interfaces::names::NameBase)
