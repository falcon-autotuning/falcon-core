#pragma once

#include <algorithm>
#include <memory>
#include <stdexcept>

#include "falcon_core/generic/IsPrimitive.hpp"
#include "falcon_core/generic/Song.hpp"
namespace falcon_core::generic {
namespace category {
struct song_tag {};
struct primitive_tag {};
struct other_tag {};

template <typename T>
struct determine_tag {
  using type = std::conditional_t<
      std::is_base_of<Song, T>::value && !is_primitive<T>::value,
      song_tag,
      std::conditional_t<is_primitive<T>::value, primitive_tag, other_tag>>;
};
}  // namespace category
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
  Container _items;

 protected:
  template <typename T>
  void push_back_impl(const std::shared_ptr<T>& item, category::song_tag) {
    if (!item) throw std::invalid_argument("List: Cannot push nullptr");
    _items.push_back(item);
  }
  template <typename T>
  void push_back_impl(const T& item, category::primitive_tag) {
    _items.push_back(item);
  }
  template <typename T>
  void push_back_impl(const T& item, category::other_tag) {
    // Handle or static_assert if not supported
    static_assert(sizeof(T) == 0, "Unsupported type for List");
  }
  template <typename T>
  bool contains_impl(const std::shared_ptr<T>& value, category::song_tag) {
    if (!value) {
      throw std::invalid_argument(
          "List: The value must be specified and not null to check if this "
          "list contains it.");
    }

    return std::any_of(
        _items.begin(), _items.end(), [&value](const StoredValue& item) {
          return *item == *value;
        });
  }
  template <typename T>
  bool contains_impl(const T& value, category::primitive_tag) {
    return std::any_of(
        _items.begin(), _items.end(), [&value](const StoredValue& item) {
          return item == value;
        });
  }
  template <typename T>
  bool contains_impl(const T& value, category::other_tag) {
    // Handle or static_assert if not supported
    static_assert(sizeof(T) == 0, "Unsupported type for List");
  }
  template <typename T>
  size_t index_impl(const std::shared_ptr<T>& value, category::song_tag) {
    if (!value) {
      throw std::invalid_argument(
          "List: The value must be specified and not null to find its "
          "index.");
    }

    for (size_t i = 0; i < _items.size(); ++i) {
      if (*_items[i] == *value) {
        return i;
      }
    }
    throw std::out_of_range("List: Value not found in List");
  }
  template <typename T>
  size_t index_impl(const T& value, category::primitive_tag) {
    for (size_t i = 0; i < _items.size(); ++i) {
      if (_items[i] == value) {
        return i;
      }
    }
    throw std::out_of_range("Value not found in List");
  }
  template <typename T>
  size_t index_impl(const T& value, category::other_tag) {
    // Handle or static_assert if not supported
    static_assert(sizeof(T) == 0, "Unsupported type for List");
  }
  template <typename T>
  bool operator_equal_impl(const List<Value>& other, category::song_tag) {
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
  template <typename T>
  bool operator_equal_impl(const List<Value>& other, category::primitive_tag) {
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
  template <typename T>
  bool operator_equal_impl(const List<Value>& other, category::other_tag) {
    // Handle or static_assert if not supported
    static_assert(sizeof(T) == 0, "Unsupported type for List");
  }

 public:
  using iterator       = typename Container::iterator;
  using const_iterator = typename Container::const_iterator;
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
    if (!value) {
      throw std::invalid_argument(
          "List: If an element is to be put in the array, it needs to not be "
          "null");
    }
    _items = Container(count, value);
  }
  static std::shared_ptr<List<Value>> fill_value(size_t             count,
                                                 const StoredValue& value) {
    return std::make_shared<List<Value>>(count, value);
  }
  List(const Container& init) : _items() {
    for (const auto& item : init) {
      push_back(item);
    }
  }
  static std::shared_ptr<List<Value>> create(const Container& init) {
    return std::make_shared<List<Value>>(init);
  }
  List<Value>(const List<Value>&)                = default;
  List<Value>(List<Value>&&) noexcept            = default;
  List<Value>& operator=(const List<Value>&)     = default;
  List<Value>& operator=(List<Value>&&) noexcept = default;
  void         push_back(const StoredValue& item) {
    push_back_impl(item, typename category::determine_tag<Value>::type{});
  }

  size_t             size() const { return _items.size(); }
  bool               empty() const { return _items.empty(); }
  const StoredValue& at(const size_t idx) const {
    if (idx >= _items.size()) {
      throw std::out_of_range("List: The index " + std::to_string(idx) +
                              " exceeds the length of the array " +
                              std::to_string(_items.size()));
    }
    return _items.at(idx);
  }
  StoredValue& at(const size_t idx) {
    if (idx >= _items.size()) {
      throw std::out_of_range("List: The index " + std::to_string(idx) +
                              " exceeds the length of the array " +
                              std::to_string(_items.size()));
    }
    return _items.at(idx);
  }
  StoredValue&       operator[](const size_t idx) { return at(idx); }
  const StoredValue& operator[](const size_t idx) const { return at(idx); }
  const Container&   items() const { return _items; }
  Container&         items() { return _items; }
  iterator           begin() { return _items.begin(); }
  iterator           end() { return _items.end(); }
  const_iterator     begin() const { return _items.begin(); }
  const_iterator     end() const { return _items.end(); }
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
  void clear() { _items.clear(); }
  /**
   * @brief Allows for targetted eraseall of elements at an index.
   * @param idx The index to erase at.
   */
  void erase_at(size_t idx) {
    if (idx >= _items.size()) {
      throw std::out_of_range("List: Index out of bounds in erase_at");
    }
    _items.erase(_items.begin() + idx);
  }
  /**
   * @brief Return the last element of a list.
   */
  StoredValue& back() {
    if (_items.empty()) {
      throw std::out_of_range("List: back() called on empty list");
    }
    return _items.back();
  }

  /**
   * @brief Return the last element of a list.
   */
  const StoredValue& back() const {
    if (_items.empty()) {
      throw std::out_of_range("List::back() called on empty list");
    }
    return _items.back();
  }

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _items);
  }
  bool operator==(const List<Value>& other) const {
    return operator_equal_impl(other,
                               typename category::determine_tag<Value>::type{});
  }
  bool operator!=(const List<Value>& other) const { return !(*this == other); }

 protected:
  friend class cereal::access;
};
template <typename Value>
using ListSP = std::shared_ptr<List<Value>>;
}  // namespace falcon_core::generic
