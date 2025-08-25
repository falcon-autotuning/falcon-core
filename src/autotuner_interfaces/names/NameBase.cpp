#include "falcon_core/autotuner_interfaces/names/NameBase.hpp"

using namespace falcon_core::autotuner_interfaces::names;

NameBase::NameBase(std::string name) : _name(name) {
  _num = std::stoi(name.substr(_index_string.length()));
}
NameBase::NameBase(int num) : _num(num) {
  _name = _index_string + std::to_string(num);
}

NameBaseSP NameBase::operator+(const NameBase& other) const {
  return std::make_shared<NameBase>(this->num() + other.num());
}
NameBaseSP NameBase::operator-(const NameBase& other) const {
  return std::make_shared<NameBase>(this->num() - other.num());
}
