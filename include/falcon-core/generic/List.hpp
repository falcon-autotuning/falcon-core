#pragma once

#include <algorithm>
#include <memory>
#include <mutex>
#include <shared_mutex>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>

#include "falcon-core/export.h"
#include "falcon-core/generic/IsPrimitive.hpp"
#include "falcon-core/generic/Song.hpp"

namespace falcon_core {
namespace generic {

template <typename Value>
class List : public generic::Song {
  static_assert(!std::is_pointer<Value>::value,
                "Value template argument must not be a pointer type");
  static_assert(std::is_base_of<Song, Value>::value ||
                    is_primitive<Value>::value,
                "Value template argument must be a Song or a primitive.");

 protected:
  using StoredValue =
      typename std::conditional<std::is_base_of<Song, Value>::value,
                                std::shared_ptr<Value>,
                                Value>::type;
  using Container = std::vector<StoredValue>;

 private:
  Container                       _items;
  mutable std::shared_timed_mutex _mu_items;

 public:
  using iterator       = typename Container::iterator;
  using const_iterator = typename Container::const_iterator;

  inline List<Value>(const List<Value>& other) {
    _items.reserve(other._items.size());
    copy_items_from_container(other._items);
  }

  inline List operator=(const List<Value>& other) {
    if (this != &other) {
      clear();
      std::unique_lock<std::shared_timed_mutex> lock_items(_mu_items,
                                                           std::defer_lock);
      std::shared_lock<std::shared_timed_mutex> lock_other_items(
          other._mu_items, std::defer_lock);
      std::lock(lock_items, lock_other_items);
      _items.reserve(other.size());
      copy_items_from_container(other._items);
    }
    return *this;
  }

  inline List(iterator begin, iterator end) : _items(begin, end) {}
  inline List() : _items(std::vector<StoredValue>()) {}
  inline static std::shared_ptr<List<Value>> create_empty() {
    return std::make_shared<List<Value>>();
  }
  inline List(size_t count) {
    if (std::is_base_of<Song, Value>::value) {
      throw std::invalid_argument(
          "List: Default-initialized List of shared_ptr is not allowed");
    } else {
      _items = Container(count);
    }
  }
  inline static std::shared_ptr<List<Value>> allocate(size_t count) {
    return std::make_shared<List<Value>>(count);
  }

  inline List(size_t count, const StoredValue& value) {
    create_duplicates_deferred<Value>(count, value);
  }

  inline static std::shared_ptr<List<Value>> fill_value(
      size_t count, const StoredValue& value) {
    return std::make_shared<List<Value>>(count, value);
  }
  inline List(const Container& init) : _items(std::vector<StoredValue>()) {
    for (const auto& item : init) {
      push_back(item);
    }
  }
  inline static std::shared_ptr<List<Value>> create(const Container& init) {
    return std::make_shared<List<Value>>(init);
  }
  inline const Container items() const {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_items);
    return _items;
  }
  inline Container items() {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_items);
    return _items;
  }

  inline void push_back(const StoredValue& item) {
    push_back_deferred<Value>(item);
  }

  inline void replace_at(size_t idx, const StoredValue& value) {
    std::unique_lock<std::shared_timed_mutex> lock(_mu_items);
    _items.at(idx) = value;
  }
  inline void insert(iterator pos, const_iterator first, const_iterator last) {
    insert_impl<Value>(pos, first, last);
  }

  inline size_t size() const { return items().size(); }
  inline bool   empty() const { return items().empty(); }

  inline auto at(const size_t idx) const
      -> std::conditional_t<std::is_same<bool, Value>::value,
                            StoredValue,
                            const StoredValue&> {
    return at_deferred<Value>(idx);
  }

  inline auto at(const size_t idx)
      -> std::conditional_t<std::is_same<bool, Value>::value,
                            StoredValue,
                            StoredValue&> {
    return at_deferred<Value>(idx);
  }

  inline StoredValue        operator[](const size_t idx) { return at(idx); }
  inline const StoredValue& operator[](const size_t idx) const {
    return at(idx);
  }

  inline iterator begin() {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_items);
    return _items.begin();
  }
  inline iterator end() {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_items);
    return _items.end();
  }
  inline const_iterator begin() const {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_items);
    return _items.begin();
  }
  inline const_iterator end() const {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_items);
    return _items.end();
  }
  inline const_iterator cbegin() const {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_items);
    return _items.cbegin();
  }

  inline const_iterator cend() const {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_items);
    return _items.cend();
  }

  inline bool contains(const StoredValue& value) const {
    return contains_deferred<Value>(value);
  }

  inline size_t index(const StoredValue& value) const {
    return index_deferred<Value>(value);
  }

  inline std::shared_ptr<List<Value>> intersection(
      const std::shared_ptr<List<Value>>& other) const {
    if (!other) {
      throw std::invalid_argument(
          "List: The other intersection value needs to not be null.");
    }
    auto result = std::make_shared<List<Value>>();
    for (const StoredValue& value : items()) {
      if (other->contains(value)) {
        result->push_back(value);
      }
    }
    return result;
  }

  inline void clear() {
    std::unique_lock<std::shared_timed_mutex> lock(_mu_items);
    _items.clear();
  }

  inline void erase_at(size_t idx) {
    std::unique_lock<std::shared_timed_mutex> lock(_mu_items);
    if (idx >= _items.size()) {
      throw std::out_of_range("List: Index out of bounds in erase_at");
    }
    _items.erase(_items.begin() + idx);
  }

  inline StoredValue back() {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_items);
    if (_items.empty()) {
      throw std::out_of_range("List: back() called on empty list");
    }
    return _items.back();
  }

  inline const StoredValue& back() const {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_items);
    if (_items.empty()) {
      throw std::out_of_range("List::back() called on empty list");
    }
    return _items.back();
  }

  template <class Archive>
  inline void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_items(_mu_items);
    ar(cereal::base_class<generic::Song>(this), _items);
  }

  inline bool operator==(const List<Value>& other) const {
    if (this == &other) return true;
    return operator_equal_deferred<Value>(other);
  }

  inline bool operator!=(const List<Value>& other) const {
    return !(*this == other);
  }

 private:
  // at() - deferred for bool type (returns by value)
  template <typename T>
  inline
      typename std::enable_if<std::is_same<T, bool>::value, StoredValue>::type
      at_deferred(size_t idx) const {
    if (idx >= size()) {
      throw std::out_of_range("List: The index " + std::to_string(idx) +
                              " exceeds the length of the array " +
                              std::to_string(size()));
    }
    std::shared_lock<std::shared_timed_mutex> lock(_mu_items);
    return _items.at(idx);
  }

  // at() - deferred for non-bool type (returns by const reference)
  template <typename T>
  inline typename std::enable_if<!std::is_same<T, bool>::value,
                                 const StoredValue&>::type
  at_deferred(size_t idx) const {
    if (idx >= size()) {
      throw std::out_of_range("List: The index " + std::to_string(idx) +
                              " exceeds the length of the array " +
                              std::to_string(size()));
    }
    std::shared_lock<std::shared_timed_mutex> lock(_mu_items);
    return _items.at(idx);
  }

  // at() - deferred for bool type (returns by value) - non-const
  template <typename T>
  inline
      typename std::enable_if<std::is_same<T, bool>::value, StoredValue>::type
      at_deferred(size_t idx) {
    if (idx >= size()) {
      throw std::out_of_range("List: The index " + std::to_string(idx) +
                              " exceeds the length of the array " +
                              std::to_string(size()));
    }
    std::shared_lock<std::shared_timed_mutex> lock(_mu_items);
    return _items.at(idx);
  }

  // at() - deferred for non-bool type (returns by reference) - non-const
  template <typename T>
  inline
      typename std::enable_if<!std::is_same<T, bool>::value, StoredValue&>::type
      at_deferred(size_t idx) {
    if (idx >= size()) {
      throw std::out_of_range("List: The index " + std::to_string(idx) +
                              " exceeds the length of the array " +
                              std::to_string(size()));
    }
    std::shared_lock<std::shared_timed_mutex> lock(_mu_items);
    return _items.at(idx);
  }

  // copy_items_from_container - deferred
  inline void copy_items_from_container(const Container& src) {
    copy_items_impl_deferred<Value>(src);
  }

  template <typename T>
  inline typename std::enable_if<std::is_base_of<Song, T>::value>::type
  copy_items_impl_deferred(const Container& src) {
    for (const auto& item : src) {
      _items.push_back(std::make_shared<T>(*item));
    }
  }

  template <typename T>
  inline typename std::enable_if<is_primitive<T>::value>::type
  copy_items_impl_deferred(const Container& src) {
    for (const auto& item : src) {
      _items.push_back(item);
    }
  }

  template <typename T>
  inline typename std::enable_if<!std::is_base_of<Song, T>::value &&
                                 !is_primitive<T>::value>::type
  copy_items_impl_deferred(const Container& /*src*/) {
    static_assert(sizeof(T) == 0, "Unsupported type for List deep copy");
  }

  // create_duplicates - deferred
  template <typename T>
  inline typename std::enable_if<std::is_base_of<Song, T>::value>::type
  create_duplicates_deferred(size_t count, const std::shared_ptr<T>& item) {
    if (!item) {
      throw std::invalid_argument(
          "List: If an element is to be put in the array, it needs to not be "
          "null");
    }
    _items = Container(count, item);
  }

  template <typename T>
  inline typename std::enable_if<is_primitive<T>::value>::type
  create_duplicates_deferred(size_t count, const T& item) {
    _items = Container(count, item);
  }

  template <typename T>
  inline typename std::enable_if<!std::is_base_of<Song, T>::value &&
                                 !is_primitive<T>::value>::type
  create_duplicates_deferred(size_t /*count*/, const T& /*item*/) {
    static_assert(sizeof(T) == 0, "Unsupported type for List");
  }

  // push_back - deferred
  template <typename T>
  inline typename std::enable_if<std::is_base_of<Song, T>::value>::type
  push_back_deferred(const std::shared_ptr<T>& item) {
    if (!item) throw std::invalid_argument("List: Cannot push nullptr");
    std::unique_lock<std::shared_timed_mutex> lock(_mu_items);
    _items.push_back(item);
  }

  template <typename T>
  inline typename std::enable_if<is_primitive<T>::value>::type
  push_back_deferred(const T& item) {
    std::unique_lock<std::shared_timed_mutex> lock(_mu_items);
    _items.push_back(item);
  }

  template <typename T>
  inline typename std::enable_if<!std::is_base_of<Song, T>::value &&
                                 !is_primitive<T>::value>::type
  push_back_deferred(const T& /*item*/) {
    throw std::runtime_error("Unsupported type for tag.");
  }

  // contains - deferred
  template <typename T>
  inline typename std::enable_if<std::is_base_of<Song, T>::value, bool>::type
  contains_deferred(const std::shared_ptr<T>& value) const {
    if (!value) {
      throw std::invalid_argument(
          "List: The value must be specified and not null to check if this "
          "list contains it.");
    }
    auto items = this->items();
    return std::any_of(
        items.begin(), items.end(), [&value](const StoredValue& item) {
          return *item == *value;
        });
  }

  template <typename T>
  inline typename std::enable_if<is_primitive<T>::value, bool>::type
  contains_deferred(const T& value) const {
    auto items = this->items();
    return std::any_of(
        items.begin(), items.end(), [&value](const StoredValue& item) {
          return item == value;
        });
  }

  template <typename T>
  inline typename std::enable_if<!std::is_base_of<Song, T>::value &&
                                     !is_primitive<T>::value,
                                 bool>::type
  contains_deferred(const T& /*value*/) const {
    throw std::runtime_error("Unsupported type for List");
  }

  // index - deferred
  template <typename T>
  inline typename std::enable_if<std::is_base_of<Song, T>::value, size_t>::type
  index_deferred(const std::shared_ptr<T>& value) const {
    if (!value) {
      throw std::invalid_argument(
          "List: The value must be specified and not null to find its index.");
    }
    for (size_t i = 0; i < size(); ++i) {
      if (*_items[i] == *value) {
        return i;
      }
    }
    throw std::out_of_range("List: Value not found in List");
  }

  template <typename T>
  inline typename std::enable_if<is_primitive<T>::value, size_t>::type
  index_deferred(const T& value) const {
    for (size_t i = 0; i < size(); ++i) {
      if (_items[i] == value) {
        return i;
      }
    }
    throw std::out_of_range("Value not found in List");
  }

  template <typename T>
  inline typename std::enable_if<!std::is_base_of<Song, T>::value &&
                                     !is_primitive<T>::value,
                                 size_t>::type
  index_deferred(const T& /*value*/) const {
    throw std::runtime_error("Unsupported type for List");
  }

  // operator== - deferred
  template <typename T>
  inline typename std::enable_if<std::is_base_of<Song, T>::value, bool>::type
  operator_equal_deferred(const List<T>& other) const {
    if (size() != other.size()) {
      return false;
    }
    for (size_t i = 0; i < size(); i++) {
      const std::shared_ptr<T> our_conn   = this->at(i);
      const std::shared_ptr<T> other_conn = other.at(i);
      if (*our_conn != *other_conn) {
        return false;
      }
    }
    return true;
  }

  template <typename T>
  inline typename std::enable_if<is_primitive<T>::value, bool>::type
  operator_equal_deferred(const List<T>& other) const {
    if (size() != other.size()) {
      return false;
    }
    for (size_t i = 0; i < size(); i++) {
      const StoredValue our_conn   = this->at(i);
      const StoredValue other_conn = other.at(i);
      if (our_conn != other_conn) {
        return false;
      }
    }
    return true;
  }

  template <typename T>
  inline typename std::enable_if<!std::is_base_of<Song, T>::value &&
                                     !is_primitive<T>::value,
                                 bool>::type
  operator_equal_deferred(const List<T>& /*other*/) const {
    throw std::runtime_error("Unsupported type for List");
  }
  // insert() - deferred for Song types (check for nullptr)
  template <typename T>
  inline typename std::enable_if<std::is_base_of<Song, T>::value>::type
  insert_impl(iterator pos, const_iterator first, const_iterator last) {
    // For Song types, StoredValue is shared_ptr<T>, so we can check for nullptr
    for (auto it = first; it != last; ++it) {
      if (!*it) {
        throw std::invalid_argument("List: Cannot insert nullptr element.");
      }
    }
    std::unique_lock<std::shared_timed_mutex> lock(_mu_items);
    _items.insert(pos, first, last);
  }

  // insert() - deferred for primitive types (no nullptr check needed)
  template <typename T>
  inline typename std::enable_if<is_primitive<T>::value>::type insert_impl(
      iterator pos, const_iterator first, const_iterator last) {
    // For primitives (including std::string), no nullptr check needed
    std::unique_lock<std::shared_timed_mutex> lock(_mu_items);
    _items.insert(pos, first, last);
  }

  // insert() - deferred for unsupported types
  template <typename T>
  inline typename std::enable_if<!std::is_base_of<Song, T>::value &&
                                 !is_primitive<T>::value>::type
  insert_impl(iterator pos, const_iterator first, const_iterator last) {
    throw std::runtime_error("Unsupported type for List::insert");
  }

 protected:
  friend class cereal::access;
};

template <typename Value>
using ListSP = std::shared_ptr<List<Value>>;
extern template class FALCON_CORE_CPP_API List<std::string>;
}  // namespace generic
}  // namespace falcon_core
