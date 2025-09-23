#pragma once

#include <algorithm>

#include "falcon_core/generic/IsPrimitive.hpp"
#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace generic {

template <typename Key, typename Value, typename Derived = void>
class Map : public virtual generic::Song {
  static_assert(!std::is_pointer<Key>::value,
                "Key template argument must not be a pointer type");
  static_assert(!std::is_pointer<Value>::value,
                "ValueType template argument must not be a pointer type");

 protected:
  using StoredKey = typename std::
      conditional<is_primitive<Key>::value, Key, std::shared_ptr<Key>>::type;
  using StoredValue = typename std::conditional<is_primitive<Value>::value,
                                                Value,
                                                std::shared_ptr<Value>>::type;

  using ContainerItem  = std::pair<StoredKey, StoredValue>;
  using Container      = std::vector<ContainerItem>;
  using iterator       = typename Container::iterator;
  using const_iterator = typename Container::const_iterator;

 private:
  Container                _items;
  std::vector<StoredKey>   _key_ptrs;
  std::vector<StoredValue> _value_ptrs;
  iterator                 find_storage(const Key& key) {
    return std::find_if(_items.begin(),
                        _items.end(),
                        [&](const ContainerItem& v) { return v.first == key; });
  }
  iterator find_storage(const std::shared_ptr<Key>& key) {
    return std::find_if(
        _items.begin(), _items.end(), [&](const ContainerItem& v) {
          return *v.first == *key;
        });
  }
  const_iterator find_storage(const Key& key) const {
    return std::find_if(_items.begin(),
                        _items.end(),
                        [&](const ContainerItem& v) { return v.first == key; });
  }
  const_iterator find_storage(const std::shared_ptr<Key>& key) const {
    return std::find_if(
        _items.begin(), _items.end(), [&](const ContainerItem& v) {
          return *v.first == *key;
        });
  }

 public:
  Map() = default;
  Map(const Container& init) {
    for (const auto& kv : init) {
      insert_or_assign(kv.first, kv.second);
    }
  }

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
    const_iterator it = find(key);
    if (it == _items.end()) throw std::out_of_range("Key not found");
    return it->second;
  }

  StoredValue& operator[](const StoredKey& key) {
    auto it = find(key);
    if (it != _items.end()) {
      return it->second;
    }
    _items.emplace_back(key, StoredValue());
    _key_ptrs.push_back(key);
    _value_ptrs.push_back(StoredValue());
    return _items.back().second;
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
  const Container               items() const { return _items; }
  Container                     items() { return _items; }

  // Get all value shared_ptrs
  const std::vector<StoredValue>& values() const { return _value_ptrs; }

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Song>(this), _items);
  }

 protected:
  friend class cereal::access;
};
template <typename Key, typename Value>
using MapSP = std::shared_ptr<Map<Key, Value>>;
}  // namespace generic
}  // namespace falcon_core
