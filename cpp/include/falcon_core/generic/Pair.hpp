#pragma once
#include <mutex>
#include <shared_mutex>

#include "falcon_core/generic/CategoryTags.hpp"
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
  Pair<T1, T2>(const Pair<T1, T2>& other) {
    std::shared_lock<std::shared_timed_mutex> lock_first(_mu_first,
                                                         std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_second(_mu_second,
                                                          std::defer_lock);
    std::lock(lock_first, lock_second);
    copy_impl(other,
              typename category::determine_tag<T1>::type{},
              typename category::determine_tag<T2>::type{});
  }
  Pair<T1, T2> operator=(const Pair<T1, T2>& other) {
    if (this != &other) {
      std::shared_lock<std::shared_timed_mutex> lock_first(_mu_first,
                                                           std::defer_lock);
      std::shared_lock<std::shared_timed_mutex> lock_second(_mu_second,
                                                            std::defer_lock);
      std::lock(lock_first, lock_second);
      copy_impl(other,
                typename category::determine_tag<T1>::type{},
                typename category::determine_tag<T2>::type{});
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
  std::shared_ptr<Pair> create(const StoredT1& first, const StoredT2& second) {
    return std::make_shared<Pair<T1, T2>>(first, second);
  }

  /**
   * @brief Get the stored first value.
   */
  const StoredT1& first() const {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_first);
    return _first;
  }
  /**
   * @brief Get the stored second value.
   */
  const StoredT2& second() const {
    std::shared_lock<std::shared_timed_mutex> lock(_mu_second);
    return _second;
  }
  /**
   * @brief Get the stored first value.
   */
  StoredT1& first() {
    std::unique_lock<std::shared_timed_mutex> lock(_mu_first);
    return _first;
  }
  /**
   * @brief Get the stored second value.
   */
  StoredT2& second() {
    std::unique_lock<std::shared_timed_mutex> lock(_mu_second);
    return _second;
  }

  bool operator==(const Pair<T1, T2>& other) const {
    return operator_equal_impl(other,
                               typename category::determine_tag<T1>::type{},
                               typename category::determine_tag<T2>::type{});
  }
  bool operator!=(const Pair<T1, T2>& other) const { return !(*this == other); }

 protected:
  friend class cereal::access;
  Pair() = default;
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_first(_mu_first,
                                                         std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_second(_mu_second,
                                                          std::defer_lock);
    std::lock(lock_first, lock_second);
    ar(cereal::base_class<generic::Song>(this), _first, _second);
  }
  // Case 1: Both T1 and T2 are primitive
  template <typename U1, typename U2>
  bool operator_equal_impl(const Pair<U1, U2>& other,
                           category::primitive_tag,
                           category::primitive_tag) const {
    return (first() == other.first()) && (second() == other.second());
  }
  // Case 2: T1 is primitive, T2 is Song
  template <typename U1, typename U2>
  bool operator_equal_impl(const Pair<U1, U2>& other,
                           category::primitive_tag,
                           category::song_tag) const {
    return (first() == other.first()) && (*second() == *other.second());
  }
  // Case 3: U1 is a Song and U2 is primitive
  template <typename U1, typename U2>
  bool operator_equal_impl(const Pair<U1, U2>& other,
                           category::song_tag,
                           category::primitive_tag) const {
    return (*first() == *other.first()) && (second() == other.second());
  }
  // Case 4: Both U1 and U2 are Song
  template <typename U1, typename U2>
  bool operator_equal_impl(const Pair<U1, U2>& other,
                           category::song_tag,
                           category::song_tag) const {
    return (*first() == *other.first()) && (*second() == *other.second());
  }
  // Tag dispatch for deep copy
  void copy_impl(const Pair<T1, T2>& other,
                 category::primitive_tag,
                 category::primitive_tag) {
    _first  = other.first();
    _second = other.second();
  }
  void copy_impl(const Pair<T1, T2>& other,
                 category::primitive_tag,
                 category::song_tag) {
    _first  = other.first();
    _second = std::make_shared<T2>(*other.second());
  }
  void copy_impl(const Pair<T1, T2>& other,
                 category::song_tag,
                 category::primitive_tag) {
    _first  = std::make_shared<T1>(*other.first());
    _second = other._second;
  }
  void copy_impl(const Pair<T1, T2>& other,
                 category::song_tag,
                 category::song_tag) {
    _first  = std::make_shared<T1>(*other.first());
    _second = std::make_shared<T2>(*other.second());
  }
};
template <typename T1, typename T2>
using PairSP = std::shared_ptr<Pair<T1, T2>>;
}  // namespace generic
}  // namespace falcon_core
