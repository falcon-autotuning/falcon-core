#pragma once
#include <blake3.h>

#include <algorithm>
#include <array>
#include <cstdint>
#include <iterator>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace generic {

using Blake3Hash = std::array<uint8_t, 32>;

struct Blake3HashEqual {
  bool operator()(const Blake3Hash& a, const Blake3Hash& b) const {
    return a == b;
  }
};

class Blake3MapKey {
 public:
  Blake3Hash hash;

  Blake3MapKey() = default;
  explicit Blake3MapKey(const std::string& data) {
    blake3_hasher hasher;
    blake3_hasher_init(&hasher);
    blake3_hasher_update(&hasher, data.data(), data.size());
    blake3_hasher_finalize(&hasher, hash.data(), 32);
  }
  bool operator==(const Blake3MapKey& other) const {
    return hash == other.hash;
  }
  bool operator!=(const Blake3MapKey& other) const { return !(*this == other); }
};

struct Blake3MapKeyHasher {
  std::size_t operator()(const Blake3MapKey& key) const {
    std::size_t result = 0;
    for (size_t i = 0; i < sizeof(std::size_t); ++i) {
      result = (result << 8) | key.hash[i];
    }
    return result;
  }
};

template <typename Key, typename ValueType>
class Map {
 public:
  using key_type         = Key;
  using mapped_type      = ValueType;
  using storage_key_type = Blake3MapKey;
  using value_type       = std::pair<const storage_key_type, mapped_type>;
  using container_type   = std::vector<value_type>;
  using iterator         = typename container_type::iterator;
  using const_iterator   = typename container_type::const_iterator;

  Map() = default;
  Map(std::initializer_list<std::pair<const Key, ValueType>> init) {
    for (const auto& kv : init) {
      insert_or_assign(kv.first, kv.second);
    }
  }
  // Insert or assign
  void insert_or_assign(const key_type& key, const mapped_type& value) {
    storage_key_type skey = make_key(key);
    auto             it   = find_storage(skey);
    if (it != _items.end()) {
      it->second = value;
    } else {
      _items.emplace_back(skey, value);
    }
  }

  // Insert
  std::pair<iterator, bool> insert(const key_type&    key,
                                   const mapped_type& value) {
    storage_key_type skey = make_key(key);
    auto             it   = find_storage(skey);
    if (it != _items.end()) {
      return {it, false};
    }
    _items.emplace_back(skey, value);
    return {std::prev(_items.end()), true};
  }

  // Find
  iterator find(const key_type& key) {
    storage_key_type skey = make_key(key);
    return find_storage(skey);
  }
  const_iterator find(const key_type& key) const {
    storage_key_type skey = make_key(key);
    return find_storage(skey);
  }

  // at
  mapped_type& at(const key_type& key) {
    auto it = find(key);
    if (it == _items.end()) throw std::out_of_range("Key not found");
    return it->second;
  }
  const mapped_type& at(const key_type& key) const {
    auto it = find(key);
    if (it == _items.end()) throw std::out_of_range("Key not found");
    return it->second;
  }

  // operator[]
  mapped_type& operator[](const key_type& key) {
    auto it = find(key);
    if (it == _items.end()) {
      storage_key_type skey = make_key(key);
      _items.emplace_back(skey, mapped_type{});
      return _items.back().second;
    }
    return it->second;
  }

  // erase
  void erase(const key_type& key) {
    auto it = find(key);
    if (it != _items.end()) _items.erase(it);
  }

  // size
  std::size_t size() const { return _items.size(); }

  // empty
  bool empty() const { return _items.empty(); }

  // clear
  void clear() { _items.clear(); }

  // iterators
  iterator       begin() { return _items.begin(); }
  iterator       end() { return _items.end(); }
  const_iterator begin() const { return _items.begin(); }
  const_iterator end() const { return _items.end(); }
  const_iterator cbegin() const { return _items.cbegin(); }
  const_iterator cend() const { return _items.cend(); }

  // contains
  bool contains(const key_type& key) const { return find(key) != _items.end(); }
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Song>(this), _items);
  }

 private:
  container_type _items;

  // Helper: convert key to string for hashing
  template <typename T = Key>
  static std::string key_to_string(const T& key) {
    if (std::is_base_of<Song, T>::value) {
      return key.to_json_string();
    } else if (std::is_convertible<T, std::string>::value) {
      return static_cast<std::string>(key);
    } else {
      static_assert(sizeof(T) == 0,
                    "Key type must be Song or convertible to std::string");
    }
  }

  storage_key_type make_key(const key_type& key) const {
    return storage_key_type(key_to_string(key));
  }

  iterator find_storage(const storage_key_type& skey) {
    return std::find_if(_items.begin(), _items.end(), [&](const value_type& v) {
      return v.first == skey;
    });
  }
  const_iterator find_storage(const storage_key_type& skey) const {
    return std::find_if(_items.begin(), _items.end(), [&](const value_type& v) {
      return v.first == skey;
    });
  }

 protected:
  friend class cereal::access;
};
template <typename Key, typename ValueType>
using MapSP = std::shared_ptr<Map<Key, ValueType>>;
}  // namespace generic
}  // namespace falcon_core
