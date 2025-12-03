#pragma once

#include <algorithm>
#include <memory>
#include <mutex>
#include <shared_mutex>
#include <stdexcept>
#include <type_traits>

#include "falcon_core/generic/CategoryTags.hpp"
#include "falcon_core/generic/Song.hpp"
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
  List<Value>(const List<Value>& other) {
    std::shared_lock<std::shared_timed_mutex> lock_items(other._mu_items);
    _items = other._items;
  }
  List operator=(const List<Value>& other) {
    if (this != &other) {
      std::shared_lock<std::shared_timed_mutex> lock_other_items(
          other._mu_items, std::defer_lock);
      std::unique_lock<std::shared_timed_mutex> lock_items(_mu_items,
                                                           std::defer_lock);
      std::lock(lock_items, lock_other_items);
      _items = other._items;
    }
    return *this;
  }
  List(iterator begin, iterator end) : _items(begin, end) {}
  /**
   * @brief List can be constructed in 5 different ways:
   *
   * - Default constructor: creates an empty List container.
   *   @code
   *   List o;
   *   @endcode
   *
   * - Sized constructor: creates an List container with a given
   * number of default-initialized elements.
   *   @param count Number of elements.
   *   @code
   *   List o(10);
   *   @endcode
   *
   * - Fill constructor: creates an List container with a given
   * number of copies of a specified value.
   *   @param count Number of elements.
   *   @param value Value to copy.
   *   @code
   *   List o(10, someValue);
   *   @endcode
   *
   * - Vector constructor: creates an List container from an existing
   * vector of values.
   *   @param vec Vector of values to copy.
   *   @code
   *   std::vector<ListP> v = ...;
   *   List o(v);
   *   @endcode
   * - Initializer list constructor: creates a List container
   *from an initializer list of shared pointers.
   *   @param init Initializer list of shared_ptr<T> to copy.
   *   @code
   *   List o{ptr1, ptr2, ptr3};
   *   @endcode
   */
  List() : _items(std::vector<StoredValue>()) {}
  static std::shared_ptr<List<Value>> create_empty() {
    return std::make_shared<List<Value>>();
  }
  List(size_t count) {
    if (std::is_base_of<Song, Value>::value) {
      throw std::invalid_argument(
          "List: Default-initialized List of shared_ptr is not allowed");
    } else {
      _items = Container(count);
    }
  }
  static std::shared_ptr<List<Value>> allocate(size_t count) {
    return std::make_shared<List<Value>>(count);
  }
  List(size_t count, const StoredValue& value) {
    create_duplicates_impl(
        count, value, typename category::determine_tag<Value>::type{});
  }
  static std::shared_ptr<List<Value>> fill_value(size_t             count,
                                                 const StoredValue& value) {
    return std::make_shared<List<Value>>(count, value);
  }
  List(const Container& init) : _items(std::vector<StoredValue>()) {
    for (const auto& item : init) {
      push_back(item);
    }
  }
  static std::shared_ptr<List<Value>> create(const Container& init) {
    return std::make_shared<List<Value>>(init);
  }
  const Container& items() const {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_items);
    return _items;
  }
  Container& items() {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_items);
    return _items;
  }
  void push_back(const StoredValue& item) {
    push_back_impl<Value>(item,
                          typename category::determine_tag<Value>::type{});
  }
  void insert(iterator pos, const_iterator first, const_iterator last)
  // FIXME: Might be broken for single items in list
  {
    if (std::is_base_of<Song, Value>::value) {
      for (auto it = first; it != last; ++it) {
        if (!*it) {
          throw std::invalid_argument("List: Cannot insert nullptr element.");
        }
      }
    }
    std::unique_lock<std::shared_timed_mutex> lock(_mu_items);
    _items.insert(pos, first, last);
  }

  size_t size() const { return items().size(); }
  bool   empty() const { return items().empty(); }

  auto at(const size_t idx) const -> std::conditional_t<
      std::is_same<typename category::determine_bool_tag<Value>::type,
                   category::bool_tag>::value,
      StoredValue,
      const StoredValue&> {
    return at_impl(idx, typename category::determine_bool_tag<Value>::type{});
  }
  auto at(const size_t idx) -> std::conditional_t<
      std::is_same<typename category::determine_bool_tag<Value>::type,
                   category::bool_tag>::value,
      StoredValue,
      StoredValue&> {
    return at_impl(idx, typename category::determine_bool_tag<Value>::type{});
  }
  StoredValue&       operator[](const size_t idx) { return at(idx); }
  const StoredValue& operator[](const size_t idx) const { return at(idx); }
  iterator           begin() { return items().begin(); }
  iterator           end() { return items().end(); }
  const_iterator     begin() const { return items().begin(); }
  const_iterator     end() const { return items().end(); }
  bool               contains(const StoredValue& value) const {
    return contains_impl(value,
                         typename category::determine_tag<Value>::type{});
  }

  size_t index(const StoredValue& value) const {
    return index_impl(value, typename category::determine_tag<Value>::type{});
  }

  /**
   * @brief Finds the intersection between this list and another.
   * @param other the other list to compare again.
   * @returns A list of values containing elements from both.
   */
  std::shared_ptr<List<Value>> intersection(
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
  /**
   * @brief clears to contents of the list.
   */
  void clear() {
    std::unique_lock<std::shared_timed_mutex> lock(_mu_items);
    _items.clear();
  }
  /**
   * @brief Allows for targetted eraseall of elements at an index.
   * @param idx The index to erase at.
   */
  void erase_at(size_t idx) {
    std::unique_lock<std::shared_timed_mutex> lock(_mu_items);
    if (idx >= _items.size()) {
      throw std::out_of_range("List: Index out of bounds in erase_at");
    }
    _items.erase(_items.begin() + idx);
  }
  /**
   * @brief Return the last element of a list.
   */
  StoredValue& back() {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_items);
    if (_items.empty()) {
      throw std::out_of_range("List: back() called on empty list");
    }
    return _items.back();
  }

  /**
   * @brief Return the last element of a list.
   */
  const StoredValue& back() const {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_items);
    if (_items.empty()) {
      throw std::out_of_range("List::back() called on empty list");
    }
    return _items.back();
  }

  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_items(_mu_items);
    ar(cereal::base_class<generic::Song>(this), _items);
  }
  bool operator==(const List<Value>& other) const {
    return operator_equal_impl(other,
                               typename category::determine_tag<Value>::type{});
  }
  bool operator!=(const List<Value>& other) const { return !(*this == other); }

 protected:
  friend class cereal::access;
  StoredValue& at_impl(size_t idx, category::other_tag) {
    if (idx >= size()) {
      throw std::out_of_range("List: The index " + std::to_string(idx) +
                              " exceeds the length of the array " +
                              std::to_string(size()));
    }
    std::shared_lock<std::shared_timed_mutex> lock(_mu_items);
    return _items.at(idx);
  }
  const StoredValue& at_impl(size_t idx, category::other_tag) const {
    if (idx >= size()) {
      throw std::out_of_range("List: The index " + std::to_string(idx) +
                              " exceeds the length of the array " +
                              std::to_string(size()));
    }
    std::shared_lock<std::shared_timed_mutex> lock(_mu_items);
    return _items.at(idx);
  }
  StoredValue at_impl(size_t idx, category::bool_tag) {
    if (idx >= size()) {
      throw std::out_of_range("List: The index " + std::to_string(idx) +
                              " exceeds the length of the array " +
                              std::to_string(size()));
    }
    std::shared_lock<std::shared_timed_mutex> lock(_mu_items);
    return _items.at(idx);
  }
  const StoredValue at_impl(size_t idx, category::bool_tag) const {
    if (idx >= size()) {
      throw std::out_of_range("List: The index " + std::to_string(idx) +
                              " exceeds the length of the array " +
                              std::to_string(size()));
    }
    std::shared_lock<std::shared_timed_mutex> lock(_mu_items);
    return _items.at(idx);
  }

  template <typename T>
  void create_duplicates_impl(size_t                    count,
                              const std::shared_ptr<T>& item,
                              category::song_tag) {
    if (!item) {
      throw std::invalid_argument(
          "List: If an element is to be put in the array, it needs to not be "
          "null");
    }
    _items = Container(count, item);
  }
  template <typename T>
  void create_duplicates_impl(size_t   count,
                              const T& item,
                              category::primitive_tag) {
    _items = Container(count, item);
  }
  template <typename T>
  void create_duplicates_impl(size_t   count,
                              const T& item,
                              category::other_tag) {
    // Handle or static_assert if not supported
    static_assert(sizeof(T) == 0, "Unsupported type for List");
  }
  template <typename T>
  void push_back_impl(const std::shared_ptr<T>& item, category::song_tag) {
    if (!item) throw std::invalid_argument("List: Cannot push nullptr");
    std::unique_lock<std::shared_timed_mutex> lock(_mu_items);
    _items.push_back(item);
  }
  template <typename T>
  void push_back_impl(const T& item, category::primitive_tag) {
    std::unique_lock<std::shared_timed_mutex> lock(_mu_items);
    _items.push_back(item);
  }
  template <typename T>
  void push_back_impl(const T& item, category::other_tag) {
    // Handle or static_assert if not supported
    throw std::runtime_error("Unsupported type for tag.");
  }
  template <typename T>
  bool contains_impl(const std::shared_ptr<T>& value,
                     category::song_tag) const {
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
  bool contains_impl(const T& value, category::primitive_tag) const {
    auto items = this->items();
    return std::any_of(
        items.begin(), items.end(), [&value](const StoredValue& item) {
          return item == value;
        });
  }
  template <typename T>
  bool contains_impl(const T& value, category::other_tag) const {
    // Handle or static_assert if not supported
    throw std::runtime_error("Unsupported type for List");
  }
  template <typename T>
  size_t index_impl(const std::shared_ptr<T>& value, category::song_tag) const {
    if (!value) {
      throw std::invalid_argument(
          "List: The value must be specified and not null to find its "
          "index.");
    }

    for (size_t i = 0; i < size(); ++i) {
      if (*_items[i] == *value) {
        return i;
      }
    }
    throw std::out_of_range("List: Value not found in List");
  }
  template <typename T>
  size_t index_impl(const T& value, category::primitive_tag) const {
    for (size_t i = 0; i < size(); ++i) {
      if (_items[i] == value) {
        return i;
      }
    }
    throw std::out_of_range("Value not found in List");
  }
  template <typename T>
  size_t index_impl(const T& value, category::other_tag) const {
    // Handle or static_assert if not supported
    throw std::runtime_error("Unsupported type for List");
  }
  bool operator_equal_impl(const List<Value>& other, category::song_tag) const {
    if (size() != other.size()) {
      return false;
    }
    for (size_t i = 0; i < size(); i++) {
      const std::shared_ptr<Value> our_conn   = this->at(i);
      const std::shared_ptr<Value> other_conn = other.at(i);
      if (*our_conn != *other_conn) {
        return false;
      }
    }
    return true;
  }
  bool operator_equal_impl(const List<Value>& other,
                           category::primitive_tag) const {
    if (size() != other.size()) {
      return false;
    }
    for (size_t i = 0; i < size(); i++) {
      const Value our_conn   = this->at(i);
      const Value other_conn = other.at(i);
      if (our_conn != other_conn) {
        return false;
      }
    }
    return true;
  }
  bool operator_equal_impl(const List<Value>& other,
                           category::other_tag) const {
    throw std::runtime_error("Unsupported type for List");
  }
};
template <typename Value>
using ListSP = std::shared_ptr<List<Value>>;
}  // namespace generic
}  // namespace falcon_core
