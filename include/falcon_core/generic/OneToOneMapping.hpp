#pragma once

#include <map>
#include <stdexcept>

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace generic {

template <typename K, typename V>
class OneToOneMapping : public generic::Song<OneToOneMapping<K, V>> {
 public:
  OneToOneMapping() = default;

  void insert(const K &key, const V &value) {
    if (_forward.count(key)) {
      throw std::invalid_argument("Key already exists.");
    }
    if (_backward.count(value)) {
      throw std::invalid_argument("Value already exists.");
    }
    _forward[key]    = value;
    _backward[value] = key;
  }

  const V &at_key(const K &key) const { return _forward.at(key); }

  const K &at_value(const V &value) const { return _backward.at(value); }

 private:
  std::map<K, V> _forward;
  std::map<V, K> _backward;
};
}  // namespace generic
}  // namespace falcon_core
