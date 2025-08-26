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
template <typename Key, typename ValueType>
class Map {
 public:
  using key_type    = Key;
  using mapped_type = ValueType;
  using value_type =
      std::pair<std::shared_ptr<key_type>, std::shared_ptr<mapped_type>>;
  using container_type = std::vector<value_type>;
  using iterator       = typename container_type::iterator;
  using const_iterator = typename container_type::const_iterator;

  Map() = default;
  template <typename K, typename V>
  Map(std::initializer_list<std::pair<K, V>> init) {
    for (const auto& kv : init) {
      insert_or_assign(std::make_shared<Key>(kv.first),
                       std::make_shared<ValueType>(kv.second));
    }
  }
  // Insert or assign
  void insert_or_assign(const std::shared_ptr<key_type>&    key,
                        const std::shared_ptr<mapped_type>& value) {
    auto it = find_storage(key);
    if (it != _items.end()) {
      it->second = value;
    } else {
      _items.emplace_back(key, value);
      _key_ptrs.push_back(key);
      _value_ptrs.push_back(value);
    }
  }

  // Insert
  std::pair<iterator, bool> insert(const std::shared_ptr<key_type>&    key,
                                   const std::shared_ptr<mapped_type>& value) {
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
  iterator find(const std::shared_ptr<key_type>& key) {
    return find_storage(key);
  }
  const_iterator find(const std::shared_ptr<key_type>& key) const {
    return find_storage(key);
  }

  // at
  std::shared_ptr<mapped_type> at(const std::shared_ptr<key_type>& key) {
    auto it = find(key);
    if (it == _items.end()) throw std::out_of_range("Key not found");
    return *(it->second);
  }
  const std::shared_ptr<mapped_type> at(
      const std::shared_ptr<key_type>& key) const {
    auto it = find(key);
    if (it == _items.end()) throw std::out_of_range("Key not found");
    return *(it->second);
  }

  // operator[]
  mapped_type& operator[](const std::shared_ptr<key_type>& key) {
    auto it = find(key);
    if (it == _items.end()) {
      auto value = std::make_shared<mapped_type>();
      _items.emplace_back(key, value);
      _key_ptrs.push_back(key);
      _value_ptrs.push_back(value);
      return *value;
    }
    return *(it->second);
  }

  // erase
  void erase(const std::shared_ptr<key_type>& key) {
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
  bool contains(const std::shared_ptr<key_type>& key) const {
    return find(key) != _items.end();
  }

  // Get all key shared_ptrs
  const std::vector<std::shared_ptr<key_type>>& keys() const {
    return _key_ptrs;
  }
  // Get all value shared_ptrs
  const std::vector<std::shared_ptr<mapped_type>>& values() const {
    return _value_ptrs;
  }

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Song>(this), _items);
  }

 private:
  container_type                            _items;
  std::vector<std::shared_ptr<key_type>>    _key_ptrs;
  std::vector<std::shared_ptr<mapped_type>> _value_ptrs;

  iterator find_storage(const std::shared_ptr<key_type>& key) {
    return std::find_if(_items.begin(), _items.end(), [&](const value_type& v) {
      return *(v.first) == *key;
    });
  }
  const_iterator find_storage(const std::shared_ptr<key_type>& key) const {
    return std::find_if(_items.begin(), _items.end(), [&](const value_type& v) {
      return *(v.first) == *key;
    });
  }

 protected:
  friend class cereal::access;
};
template <typename Key, typename ValueType>
using MapSP = std::shared_ptr<Map<Key, ValueType>>;
}  // namespace generic
}  // namespace falcon_core
