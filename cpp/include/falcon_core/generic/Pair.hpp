#pragma once
#include <mutex>
#include <shared_mutex>

#include "falcon_core/generic/IsPrimitive.hpp"
#include "falcon_core/generic/Song.hpp"
namespace falcon_core {
namespace generic {
template <typename T1, typename T2>
class Pair : public generic::Song {
  static_assert(!std::is_pointer<T1>::value,
                "First template argument must not be a pointer type");
  static_assert(!std::is_pointer<T2>::value,
                "Second template argument must not be a pointer type");
  static_assert(std::is_base_of<Song, T1>::value || is_primitive<T1>::value,
                "First template argument must be a Song or a primitive.");
  static_assert(std::is_base_of<Song, T2>::value || is_primitive<T2>::value,
                "Second template argument must be a Song or a primitive.");

 public:
  using StoredT1 =
      typename std::conditional<std::is_base_of<generic::Song, T1>::value,
                                std::shared_ptr<T1>,
                                T1>::type;
  using StoredT2 =
      typename std::conditional<std::is_base_of<generic::Song, T2>::value,
                                std::shared_ptr<T2>,
                                T2>::type;

 private:
  StoredT1                        _first;
  StoredT2                        _second;
  mutable std::shared_timed_mutex _mu_first;
  mutable std::shared_timed_mutex _mu_second;

 public:
  Pair<T1, T2>(const Pair<T1, T2>& other) { copy_impl_deferred<T1, T2>(other); }

  Pair<T1, T2>& operator=(const Pair<T1, T2>& other) {
    if (this != &other) {
      std::shared_lock<std::shared_timed_mutex> lock_first(_mu_first,
                                                           std::defer_lock);
      std::shared_lock<std::shared_timed_mutex> lock_second(_mu_second,
                                                            std::defer_lock);
      std::shared_lock<std::shared_timed_mutex> lock_other_first(
          other._mu_first, std::defer_lock);
      std::shared_lock<std::shared_timed_mutex> lock_other_second(
          other._mu_second, std::defer_lock);
      std::lock(lock_first, lock_second, lock_other_first, lock_other_second);
      copy_impl_deferred<T1, T2>(other);
    }
    return *this;
  }

  /**
   * @brief Store a pair of values.
   * @param first The first value.
   * @param second The second value.
   */
  Pair(const StoredT1& first, const StoredT2& second)
      : _first(first), _second(second) {}

  /**
   * @brief Store a pair of values.
   * @param first The first value.
   * @param second The second value.
   */
  inline std::shared_ptr<Pair> create(const StoredT1& first,
                                      const StoredT2& second) {
    return std::make_shared<Pair<T1, T2>>(first, second);
  }

  /**
   * @brief Get the stored first value.
   */
  inline const StoredT1 first() const {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_first);
    return _first;
  }
  /**
   * @brief Get the stored second value.
   */
  inline const StoredT2 second() const {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_second);
    return _second;
  }
  /**
   * @brief Get the stored first value.
   */
  inline StoredT1 first() {
    std::unique_lock<std::shared_timed_mutex> lock(_mu_first);
    return _first;
  }
  /**
   * @brief Get the stored second value.
   */
  inline StoredT2 second() {
    std::unique_lock<std::shared_timed_mutex> lock(_mu_second);
    return _second;
  }

  inline bool operator==(const Pair<T1, T2>& other) const {
    if (this == &other) return true;
    return operator_equal_deferred<T1, T2>(other);
  }

  inline bool operator!=(const Pair<T1, T2>& other) const {
    return !(*this == other);
  }

 protected:
  friend class cereal::access;
  Pair() = default;
  template <class Archive>
  inline void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_first(_mu_first,
                                                         std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_second(_mu_second,
                                                          std::defer_lock);
    std::lock(lock_first, lock_second);
    ar(cereal::base_class<generic::Song>(this), _first, _second);
  }

 private:
  // ==== DEFERRED INSTANTIATION METHODS (Windows fix) ====

  // operator== implementations - deferred
  template <typename U1, typename U2>
  inline typename std::
      enable_if<is_primitive<U1>::value && is_primitive<U2>::value, bool>::type
      operator_equal_deferred(const Pair<U1, U2>& other) const {
    return (first() == other.first()) && (second() == other.second());
  }

  template <typename U1, typename U2>
  inline typename std::enable_if<is_primitive<U1>::value &&
                                     std::is_base_of<Song, U2>::value,
                                 bool>::type
  operator_equal_deferred(const Pair<U1, U2>& other) const {
    return (first() == other.first()) && (*second() == *other.second());
  }

  template <typename U1, typename U2>
  inline typename std::enable_if<std::is_base_of<Song, U1>::value &&
                                     is_primitive<U2>::value,
                                 bool>::type
  operator_equal_deferred(const Pair<U1, U2>& other) const {
    return (*first() == *other.first()) && (second() == other.second());
  }

  template <typename U1, typename U2>
  inline typename std::enable_if<std::is_base_of<Song, U1>::value &&
                                     std::is_base_of<Song, U2>::value,
                                 bool>::type
  operator_equal_deferred(const Pair<U1, U2>& other) const {
    return (*first() == *other.first()) && (*second() == *other.second());
  }

  // copy_impl implementations - deferred
  template <typename U1, typename U2>
  inline typename std::enable_if<is_primitive<U1>::value &&
                                 is_primitive<U2>::value>::type
  copy_impl_deferred(const Pair<U1, U2>& other) {
    _first  = other._first;
    _second = other._second;
  }

  template <typename U1, typename U2>
  inline typename std::enable_if<is_primitive<U1>::value &&
                                 std::is_base_of<Song, U2>::value>::type
  copy_impl_deferred(const Pair<U1, U2>& other) {
    if (!other._second) {
      throw std::invalid_argument(
          "Pair copy constructor: Other Pair contains null shared pointer.");
    }
    _first  = other._first;
    _second = std::make_shared<U2>(*other._second);
  }

  template <typename U1, typename U2>
  inline typename std::enable_if<std::is_base_of<Song, U1>::value &&
                                 is_primitive<U2>::value>::type
  copy_impl_deferred(const Pair<U1, U2>& other) {
    if (!other._first) {
      throw std::invalid_argument(
          "Pair copy constructor: Other Pair contains null shared pointer.");
    }
    _first  = std::make_shared<U1>(*other._first);
    _second = other._second;
  }

  template <typename U1, typename U2>
  inline typename std::enable_if<std::is_base_of<Song, U1>::value &&
                                 std::is_base_of<Song, U2>::value>::type
  copy_impl_deferred(const Pair<U1, U2>& other) {
    if (!other._first || !other._second) {
      throw std::invalid_argument(
          "Pair copy constructor: Other Pair contains null shared pointer.");
    }
    _first  = std::make_shared<U1>(*other._first);
    _second = std::make_shared<U2>(*other._second);
  }
};

template <typename T1, typename T2>
using PairSP = std::shared_ptr<Pair<T1, T2>>;
}  // namespace generic
}  // namespace falcon_core
