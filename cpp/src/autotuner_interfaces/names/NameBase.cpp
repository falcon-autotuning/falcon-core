#include "falcon_core/autotuner_interfaces/names/NameBase.hpp"

#include <stdexcept>

namespace falcon_core {
namespace autotuner_interfaces {
namespace names {
NameBase::NameBase(const NameBase& other) {
  std::unique_lock<std::shared_timed_mutex> lock_name(_mu_name,
                                                      std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_num(_mu_num, std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_index_string(_mu_index_string,
                                                              std::defer_lock);
  std::shared_lock<std::shared_timed_mutex> lock_other_index_string(
      other._mu_index_string, std::defer_lock);
  std::lock(lock_name, lock_num, lock_index_string, lock_other_index_string);
  _name         = other.name();
  _num          = other.num();
  _index_string = other._index_string;
}
NameBase& NameBase::operator=(const NameBase& other) {
  if (this != &other) {
    std::unique_lock<std::shared_timed_mutex> lock_name(_mu_name,
                                                        std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_num(_mu_num,
                                                       std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_index_string(
        _mu_index_string, std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_other_index_string(
        other._mu_index_string, std::defer_lock);
    std::lock(lock_name, lock_num, lock_index_string, lock_other_index_string);
    _name         = other.name();
    _num          = other.num();
    _index_string = other._index_string;
  }
  return *this;
}

NameBase::NameBase(const std::string& name)
    : _name(name), _num(-1), _index_string("") {}
NameBase::NameBase(const std::string& name, const std::string& index_string)
    : _name(name), _index_string(index_string) {
  _num = std::stoi(name.substr(_index_string.length()));
}
NameBase::NameBase(const int& num, const std::string& index_string)
    : _name(index_string + std::to_string(num)),
      _num(num),
      _index_string(index_string) {}
std::string NameBase::name() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_name);
  return _name;
}
int NameBase::num() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_num);
  return _num;
}

NameBaseSP NameBase::operator+(const NameBaseSP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "NameBase: The other name to be added needs to be not null.");
  }
  std::shared_lock<std::shared_timed_mutex> lock_other_index_string(
      other->_mu_index_string);
  return std::make_shared<NameBase>(this->num() + other->num(),
                                    this->_index_string);
}
NameBaseSP NameBase::operator-(const NameBaseSP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "NameBase: The other name to be subtracted needs to be not null.");
  }
  std::shared_lock<std::shared_timed_mutex> lock_other_index_string(
      other->_mu_index_string);
  return std::make_shared<NameBase>(this->num() - other->num(),
                                    this->_index_string);
}
}  // namespace names
}  // namespace autotuner_interfaces
}  // namespace falcon_core
