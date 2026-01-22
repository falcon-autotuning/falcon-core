#pragma once

#include <numeric>

#include "falcon_core/export.h"
#include "falcon_core/generic/List.hpp"
#include "falcon_core/generic/Pair.hpp"
namespace falcon_core {
namespace generic {

template <typename Key, typename Value>
class FALCON_CORE_CPP_API Map : public virtual generic::Song {
  static_assert(!std::is_pointer<Key>::value,
                "Key template argument must not be a pointer type");
  static_assert(!std::is_pointer<Value>::value,
                "ValueType template argument must not be a pointer type");
  using ContainerItem   = generic::Pair<Key, Value>;
  using ContainerItemSP = std::shared_ptr<ContainerItem>;
  using Container       = generic::List<ContainerItem>;
  std::shared_ptr<Container>      _items;
  mutable std::shared_timed_mutex _mu_items;

 protected:
  using iterator       = typename Container::iterator;
  using const_iterator = typename Container::const_iterator;

 public:
  Map<Key, Value>(const Map<Key, Value>& other) {
    _items = std::make_shared<Container>(*other.items());
  }
  Map<Key, Value>& operator=(const Map<Key, Value>& other) {
    if (this != &other) {
      std::unique_lock<std::shared_timed_mutex> lock_items(_mu_items);
      _items = std::make_shared<Container>(*other.items());
    }
    return *this;
  }
  Map() : _items(std::make_shared<Container>()) {}
  static std::shared_ptr<Map<Key, Value>> create_empty() {
    return std::make_shared<Map<Key, Value>>();
  }
  Map(const std::vector<std::pair<typename ContainerItem::StoredT1,
                                  typename ContainerItem::StoredT2>>& init)
      : _items(std::make_shared<Container>()) {
    for (const auto& kv : init) {
      insert_or_assign(kv.first, kv.second);
    }
  }
  Map(const Container& init) : _items(std::make_shared<Container>()) {
    for (const PairSP<Key, Value>& kv : init) {
      insert_or_assign((*kv).first(), (*kv).second());
    }
  }
  std::shared_ptr<Map<Key, Value>> create(const Container& init) {
    return std::make_shared<Map<Key, Value>>(init);
  }
  const std::shared_ptr<Container> items() const {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_items);
    return _items;
  }
  std::shared_ptr<Container> items() {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_items);
    return _items;
  }

  void insert_or_assign(const typename ContainerItem::StoredT1& key,
                        const typename ContainerItem::StoredT2& value) {
    erase(key);
    std::unique_lock<std::shared_timed_mutex> lock(_mu_items);
    _items->push_back(std::make_shared<Pair<Key, Value>>(key, value));
  }

  std::pair<iterator, bool> insert(
      const typename ContainerItem::StoredT1& key,
      const typename ContainerItem::StoredT2& value) {
    std::unique_lock<std::shared_timed_mutex> lock(_mu_items);
    auto                                      it = find(key);
    if (it != _items->end()) {
      return {it, false};
    }
    _items->push_back(std::make_shared<Pair<Key, Value>>(key, value));
    return {std::prev(_items->end()), true};
  }

  // at
  typename ContainerItem::StoredT2 at(
      const typename ContainerItem::StoredT1& key) {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_items);
    iterator                                  it = find(key);
    if (it == _items->end()) throw std::out_of_range("Map: Key not found");
    return (*it)->second();
  }
  const typename ContainerItem::StoredT2 at(
      const typename ContainerItem::StoredT1& key) const {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_items);
    const_iterator                            it = find(key);
    if (it == _items->end()) throw std::out_of_range("Map: Key not found");
    return (*it)->second();
  }

  typename ContainerItem::StoredT2 operator[](
      const typename ContainerItem::StoredT1& key) {
    std::unique_lock<std::shared_timed_mutex> lock(_mu_items);
    auto                                      it = find(key);
    if (it != _items->end()) {
      return (*it)->second();
    }
    auto out = typename ContainerItem::StoredT2();
    _items->push_back(std::make_shared<Pair<Key, Value>>(key, out));
    return _items->back()->second();
  }

  // erase
  void erase(const typename ContainerItem::StoredT1& key) {
    std::unique_lock<std::shared_timed_mutex> lock(_mu_items);
    auto                                      it = find(key);
    if (it != _items->end()) {
      auto idx = it - _items->begin();
      _items->erase_at(std::distance(_items->begin(), it));
    }
  }

  // size
  std::size_t size() const { return items()->size(); }

  // empty
  bool empty() const { return items()->empty(); }

  // clear
  void clear() {
    std::unique_lock<std::shared_timed_mutex> lock(_mu_items);
    _items->clear();
  }

  // iterators
  iterator       begin() { return items()->begin(); }
  iterator       end() { return items()->end(); }
  const_iterator begin() const { return items()->begin(); }
  const_iterator end() const { return items()->end(); }
  const_iterator cbegin() const { return items()->cbegin(); }
  const_iterator cend() const { return items()->cend(); }

  // contains
  bool contains(const typename ContainerItem::StoredT1& key) const {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_items);
    return find(key) != items()->end();
  }

  /**
   * @brief Return the keys of the Map.
   */
  const generic::ListSP<Key> keys() const {
    generic::List<Key> out   = generic::List<Key>();
    auto               items = *this->items();
    for (const ContainerItemSP& pair : items) {
      out.push_back(pair->first());
    }
    return std::make_shared<generic::List<Key>>(out);
  }

  /**
   * @brief Return the values of the Map.
   */
  const generic::ListSP<Value> values() const {
    generic::List<Value> out   = generic::List<Value>();
    auto                 items = *this->items();
    for (const ContainerItemSP& pair : items) {
      out.push_back(pair->second());
    }
    return std::make_shared<generic::List<Value>>(out);
  }
  bool operator==(const Map<Key, Value>& other) const {
    if (this == &other) return true;
    if (size() != other.size()) return false;
    std::vector<size_t> unmatched_indexes(size());
    std::iota(
        unmatched_indexes.begin(), unmatched_indexes.end(), 0);  // 0..size()-1
    auto items = *this->items();
    for (const PairSP<Key, Value>& pair : items) {
      bool found = false;
      for (auto it = unmatched_indexes.begin(); it != unmatched_indexes.end();
           ++it) {
        if (*pair == *other.items()->at(*it)) {
          unmatched_indexes.erase(it);  // Remove matched index
          found = true;
          break;
        }
      }
      if (!found) return false;  // No match found for this pair
    }
    return unmatched_indexes.empty();  // All pairs matched
  }
  bool operator!=(const Map<Key, Value>& other) const {
    return !(*this == other);
  }

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_items);
    ar(cereal::base_class<Song>(this), *_items);
  }
  // Find
  iterator find(const Key& key) {
    return std::find_if(
        _items->begin(), _items->end(), [&](const ContainerItemSP& v) {
          return v->first() == key;
        });
  }
  iterator find(const std::shared_ptr<Key>& key) {
    if (!key) return _items->end();
    return std::find_if(
        _items->begin(), _items->end(), [&](const ContainerItemSP& v) {
          return v->first() && (*v->first() == *key);
        });
  }
  const_iterator find(const Key& key) const {
    return std::find_if(
        _items->begin(), _items->end(), [&](const ContainerItemSP& v) {
          return v->first() == key;
        });
  }
  const_iterator find(const std::shared_ptr<Key>& key) const {
    if (!key) return _items->end();
    return std::find_if(
        _items->begin(), _items->end(), [&](const ContainerItemSP& v) {
          return v->first() && (*v->first() == *key);
        });
  }
};
template <typename Key, typename Value>
using MapSP = std::shared_ptr<Map<Key, Value>>;
}  // namespace generic
}  // namespace falcon_core
