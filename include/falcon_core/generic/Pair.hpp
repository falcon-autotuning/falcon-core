#pragma once
#include "falcon_core/generic/IsPrimitive.hpp"
#include "falcon_core/generic/Song.hpp"
namespace falcon_core::generic {
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
  StoredT1 _first;
  StoredT2 _second;

 public:
  /**
   * @brief Store a pair of values.
   * @param first The first value.
   * @param second The second value.
   */
  Pair(const StoredT1& first, const StoredT2& second)
      : _first(first), _second(second) {}

  /**
   * @brief Get the stored first value.
   */
  StoredT1& first() { return _first; }
  /**
   * @brief Get the stored second value.
   */
  StoredT2& second() { return _second; }

 protected:
  friend class cereal::access;
  Pair() = default;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _first, _second);
  }
};
template <typename T1, typename T2>
using PairSP = std::shared_ptr<Pair<T1, T2>>;
}  // namespace falcon_core::generic
