#pragma once

#include <algorithm>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <utility>
#include <vector>

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace generic {
template <typename Key, typename ValueType, typename Derived = void>
class Map : public generic::Song {
 public:
  using StoredKey   = std::shared_ptr<Key>;
  using StoredValue = typename std::conditional<
      std::is_arithmetic<ValueType>::value ||
          std::is_same<ValueType, std::string>::value ||
          std::is_same<ValueType, char>::value ||
          std::is_same<ValueType, bool>::value,
      ValueType,
      std::shared_ptr<ValueType>>::type;
  using value          = std::pair<StoredKey, StoredValue>;
  using container_type = std::vector<value>;
  using iterator       = typename container_type::iterator;
  using const_iterator = typename container_type::const_iterator;

  Map() = default;
  // For primitive ValueType
  template <
      typename T = ValueType,
      typename std::enable_if<
          std::is_arithmetic<T>::value || std::is_same<T, std::string>::value ||
              std::is_same<T, char>::value || std::is_same<T, bool>::value,
          int>::type = 0>
  Map(std::initializer_list<std::pair<StoredKey, ValueType>> init) {
    for (const auto& kv : init) {
      insert_or_assign(kv.first, kv.second);
    }
  }

  // For non-primitive ValueType
  template <typename T                         = ValueType,
            typename std::enable_if<!(std::is_arithmetic<T>::value ||
                                      std::is_same<T, std::string>::value ||
                                      std::is_same<T, char>::value ||
                                      std::is_same<T, bool>::value),
                                    int>::type = 0>
  Map(std::initializer_list<std::pair<StoredKey, std::shared_ptr<ValueType>>>
          init) {
    for (const auto& kv : init) {
      insert_or_assign(kv.first, kv.second);
    }
  }
  // Insert or assign
  void insert_or_assign(const StoredKey& key, const StoredValue& value) {
    auto it = find_storage(key);
    if (it != _items.end()) {
      it->second = value;
    } else {
      _items.emplace_back(key, value);
      _key_ptrs.push_back(key);
      _value_ptrs.push_back(value);
    }
  }
  template <typename V = ValueType>
  typename std::enable_if<
      std::is_arithmetic<V>::value || std::is_same<V, std::string>::value ||
          std::is_same<V, char>::value || std::is_same<V, bool>::value,
      V>::type
  make_stored_value(const V& v) {
    return v;
  }

  template <typename V = ValueType>
  typename std::enable_if<
      !(std::is_arithmetic<V>::value || std::is_same<V, std::string>::value ||
        std::is_same<V, char>::value || std::is_same<V, bool>::value),
      std::shared_ptr<V>>::type
  make_stored_value(const V& v) {
    return std::make_shared<V>(v);
  }

  // Insert
  std::pair<iterator, bool> insert(const StoredKey&   key,
                                   const StoredValue& value) {
    auto it = find_storage(key);
    if (it != _items.end()) {
      return {it, false};
    }
    _items.emplace_back(key, value);
    _key_ptrs.push_back(key);
    _value_ptrs.push_back(value);
    return {std::prev(_items.end()), true};
  }

  // Find
  iterator       find(const StoredKey& key) { return find_storage(key); }
  const_iterator find(const StoredKey& key) const { return find_storage(key); }

  // at
  StoredValue at(const StoredKey& key) {
    iterator it = find(key);
    if (it == _items.end()) throw std::out_of_range("Key not found");
    return it->second;
  }
  const StoredValue at(const StoredKey& key) const {
    iterator it = find(key);
    if (it == _items.end()) throw std::out_of_range("Key not found");
    return *(it->second);
  }

  // For primitive types
  template <typename K = Key, typename V = ValueType>
  typename std::enable_if<
      std::is_arithmetic<V>::value || std::is_same<V, std::string>::value ||
          std::is_same<V, char>::value || std::is_same<V, bool>::value,
      V&>::type
  operator[](const std::shared_ptr<K>& key) {
    auto it = find(key);
    if (it == _items.end()) {
      _items.emplace_back(key, V());
      _key_ptrs.push_back(key);
      _value_ptrs.push_back(V());
      return _items.back().second;
    }
    return it->second;
  }

  // For non-primitive types
  template <typename K = Key, typename V = ValueType>
  typename std::enable_if<
      !(std::is_arithmetic<V>::value || std::is_same<V, std::string>::value ||
        std::is_same<V, char>::value || std::is_same<V, bool>::value),
      V&>::type
  operator[](const std::shared_ptr<K>& key) {
    auto it = find(key);
    if (it == _items.end()) {
      auto ptr = std::make_shared<V>();
      _items.emplace_back(key, ptr);
      _key_ptrs.push_back(key);
      _value_ptrs.push_back(ptr);
      return *(_items.back().second);
    }
    return *(it->second);
  }

  // erase
  void erase(const StoredKey& key) {
    auto it = find(key);
    if (it != _items.end()) {
      auto idx = it - _items.begin();
      _items.erase(it);
      _key_ptrs.erase(_key_ptrs.begin() + idx);
      _value_ptrs.erase(_value_ptrs.begin() + idx);
    }
  }

  // size
  std::size_t size() const { return _items.size(); }

  // empty
  bool empty() const { return _items.empty(); }

  // clear
  void clear() {
    _items.clear();
    _key_ptrs.clear();
    _value_ptrs.clear();
  }

  // iterators
  iterator       begin() { return _items.begin(); }
  iterator       end() { return _items.end(); }
  const_iterator begin() const { return _items.begin(); }
  const_iterator end() const { return _items.end(); }
  const_iterator cbegin() const { return _items.cbegin(); }
  const_iterator cend() const { return _items.cend(); }

  // contains
  bool contains(const StoredKey& key) const {
    return find(key) != _items.end();
  }

  // Get all key shared_ptrs
  const std::vector<StoredKey>& keys() const { return _key_ptrs; }
  const container_type          items() const { return _items; }
  // Get all value shared_ptrs
  const std::vector<StoredValue>& values() const { return _value_ptrs; }
  // SFINAE: If Derived is void, clone returns Map
  template <typename D = Derived>
  typename std::enable_if<std::is_same<D, void>::value,
                          std::shared_ptr<Map>>::type
  clone() const {
    auto result = std::make_shared<Map>(*this);
    result->clear();
    for (const auto& kv : _items) {
      result->insert_or_assign(kv.first, kv.second);
    }
    return result;
  }

  // SFINAE: If Derived is not void, clone returns Derived
  template <typename D = Derived>
  typename std::enable_if<!std::is_same<D, void>::value,
                          std::shared_ptr<Derived>>::type
  clone() const {
    auto result = std::make_shared<Derived>(static_cast<const Derived&>(*this));
    result->clear();
    for (const auto& kv : _items) {
      result->insert_or_assign(kv.first, kv.second);
    }
    return result;
  }

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Song>(this), _items);
  }

 private:
  container_type           _items;
  std::vector<StoredKey>   _key_ptrs;
  std::vector<StoredValue> _value_ptrs;

  iterator find_storage(const StoredKey& key) {
    return std::find_if(_items.begin(), _items.end(), [&](const value& v) {
      return *(v.first) == *key;
    });
  }
  const_iterator find_storage(const StoredKey& key) const {
    return std::find_if(_items.begin(), _items.end(), [&](const value& v) {
      return *(v.first) == *key;
    });
  }
  template <typename T = ValueType>
  typename std::enable_if<
      std::is_arithmetic<T>::value || std::is_same<T, std::string>::value ||
      std::is_same<T, char>::value || std::is_same<T, bool>::value>::type
  insert_item(std::shared_ptr<Derived>& result, const ValueType& kv) const {
    result->insert_or_assign(kv.first, kv.second);
  }

  template <typename T = ValueType>
  typename std::enable_if<
      !(std::is_arithmetic<T>::value || std::is_same<T, std::string>::value ||
        std::is_same<T, char>::value || std::is_same<T, bool>::value)>::type
  insert_item(std::shared_ptr<Derived>& result, const ValueType& kv) const {
    result->insert_or_assign(kv.first, std::make_shared<ValueType>(*kv.second));
  }

 protected:
  friend class cereal::access;
};
template <typename Key, typename ValueType>
using MapSP = std::shared_ptr<Map<Key, ValueType>>;
}  // namespace generic
}  // namespace falcon_core
