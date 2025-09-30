#pragma once

#include "falcon_core/generic/List.hpp"
#include "falcon_core/generic/Pair.hpp"
#include "falcon_core/generic/Song.hpp"
namespace falcon_core::generic {

template <typename Key, typename Value>
class Map : public virtual generic::Song {
  static_assert(!std::is_pointer<Key>::value,
                "Key template argument must not be a pointer type");
  static_assert(!std::is_pointer<Value>::value,
                "ValueType template argument must not be a pointer type");
  using ContainerItem   = generic::Pair<Key, Value>;
  using ContainerItemSP = std::shared_ptr<ContainerItem>;
  using Container       = generic::List<ContainerItem>;
  std::shared_ptr<Container> _items;

 protected:
  using iterator       = typename Container::iterator;
  using const_iterator = typename Container::const_iterator;

 public:
  Map() : _items(std::make_shared<Container>()) {}
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

  void insert_or_assign(const ContainerItem::StoredT1& key,
                        const ContainerItem::StoredT2& value) {
    auto it = find(key);
    if (it != _items->end()) {
      (*it)->second() = value;
    } else {
      _items->push_back(std::make_shared<Pair<Key, Value>>(key, value));
    }
  }

  std::pair<iterator, bool> insert(const ContainerItem::StoredT1& key,
                                   const ContainerItem::StoredT2& value) {
    auto it = find(key);
    if (it != _items->end()) {
      return {it, false};
    }
    _items->push_back(std::make_shared<Pair<Key, Value>>(key, value));
    return {std::prev(_items->end()), true};
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

  // at
  ContainerItem::StoredT2 at(const ContainerItem::StoredT1& key) {
    iterator it = find(key);
    if (it == _items->end()) throw std::out_of_range("Key not found");
    return (*it)->second();
  }
  const ContainerItem::StoredT2 at(const ContainerItem::StoredT1& key) const {
    const_iterator it = find(key);
    if (it == _items->end()) throw std::out_of_range("Key not found");
    return (*it)->second();
  }

  ContainerItem::StoredT2& operator[](const ContainerItem::StoredT1& key) {
    auto it = find(key);
    if (it != _items->end()) {
      return (*it)->second();
    }
    auto out = typename ContainerItem::StoredT2();
    _items->push_back(std::make_shared<Pair<Key, Value>>(key, out));
    return _items->back()->second();
  }

  // erase
  void erase(const ContainerItem::StoredT1& key) {
    auto it = find(key);
    if (it != _items->end()) {
      auto idx = it - _items->begin();
      _items->erase_at(std::distance(_items->begin(), it));
    }
  }

  // size
  std::size_t size() const { return _items->size(); }

  // empty
  bool empty() const { return _items->empty(); }

  // clear
  void clear() { _items->clear(); }

  // iterators
  iterator       begin() { return _items->begin(); }
  iterator       end() { return _items->end(); }
  const_iterator begin() const { return _items->begin(); }
  const_iterator end() const { return _items->end(); }
  const_iterator cbegin() const { return _items->cbegin(); }
  const_iterator cend() const { return _items->cend(); }

  // contains
  bool contains(const ContainerItem::StoredT1& key) const {
    return find(key) != _items->end();
  }

  /**
   * @brief Return the keys of the Map.
   */
  const generic::ListSP<Key> keys() const {
    generic::ListSP<Key> out = std::make_shared<generic::List<Key>>();
    for (const ContainerItemSP pair : *_items) {
      out->push_back(pair->first());
    }
    return out;
  }
  const Container items() const { return *_items; }
  Container       items() { return *_items; }

  /**
   * @brief Return the values of the Map.
   */
  const generic::ListSP<Value> values() const {
    generic::ListSP<Value> out = std::make_shared<generic::List<Value>>();
    for (const ContainerItemSP pair : *_items) {
      out->push_back(pair->second());
    }
    return out;
  }
  bool operator==(const Map<Key, Value>& other) const {
    return *_items == *other._items;
  }
  bool operator!=(const Map<Key, Value>& other) const {
    return !(*this == other);
  }

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Song>(this), *_items);
  }
};
template <typename Key, typename Value>
using MapSP = std::shared_ptr<Map<Key, Value>>;
}  // namespace falcon_core::generic
