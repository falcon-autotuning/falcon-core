#pragma once

#include "falcon_core/generic/IsPrimitive.hpp"
#include "falcon_core/generic/Song.hpp"
namespace falcon_core {
namespace generic {
template <typename Value, typename Derived = void>
class List : public generic::Song {
  static_assert(!std::is_pointer<Value>::value,
                "Value template argument must not be a pointer type");
  using StoredValue = typename std::conditional<is_primitive<Value>::value,
                                                Value,
                                                std::shared_ptr<Value>>::type;
  using Container   = std::vector<StoredValue>;
  Container _items;

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
  List() = default;
  List(size_t count) : _items(count) {}
  List(size_t count, const StoredValue& value) : _items(count, value) {}
  List(const Container& init) : _items(init) {}
  void        push_back(const StoredValue& item) { _items.push_back(item); }
  size_t      size() const { return _items.size(); }
  bool        empty() const { return _items.empty(); }
  StoredValue at(const size_t idx) const { return _items.at(idx); }
  const StoredValue operator[](const size_t idx) const { return _items[idx]; }
  const Container&  items() const { return _items; }
  Container&        items() { return _items; }
  iterator          begin() { return _items.begin(); }
  iterator          end() { return _items.end(); }
  const_iterator    begin() const { return _items.begin(); }
  const_iterator    end() const { return _items.end(); }
  void insert(iterator pos, const_iterator first, const_iterator last) {
    _items.insert(pos, first, last);
  }
  // SFINAE: If Derived is void, clone returns Map
  template <typename D = Derived>
  typename std::enable_if<std::is_same<D, void>::value,
                          std::shared_ptr<List>>::type
  clone() const {
    std::shared_ptr<List> result = std::make_shared<List>(*this);
    result->clear();
    result->_items = _items;
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
    ar(cereal::base_class<generic::Song>(this), _items);
  }

 protected:
  friend class cereal::access;
};
template <typename Value>
using ListSP = std::shared_ptr<List<Value>>;
template <typename T>
typename T::StoredValue at(const std::shared_ptr<T>& list, size_t idx) {
  return (*list)[idx];
}
}  // namespace generic
}  // namespace falcon_core
