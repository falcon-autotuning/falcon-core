#pragma once
#include <cereal/types/memory.hpp>
#include <cereal/types/vector.hpp>
#include <memory>
#include <vector>

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace math {

template <typename T>
class Axes : public generic::Song {
 public:
  Axes() = default;
  explicit Axes(const std::vector<std::shared_ptr<T>>& items) : _items(items) {}

  // Vector-like methods
  size_t size() const { return _items.size(); }
  bool   empty() const { return _items.empty(); }
  void   push_back(const std::shared_ptr<T>& item) { _items.push_back(item); }
  const std::shared_ptr<T>& at(size_t idx) const { return _items.at(idx); }
  std::shared_ptr<T>&       at(size_t idx) { return _items.at(idx); }
  const std::vector<std::shared_ptr<T>>& items() const { return _items; }
  std::vector<std::shared_ptr<T>>&       items() { return _items; }

#ifndef SWIG
  const std::shared_ptr<T>& operator[](size_t idx) const { return _items[idx]; }
  std::shared_ptr<T>&       operator[](size_t idx) { return _items[idx]; }
#endif

 private:
  std::vector<std::shared_ptr<T>> _items;

  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _items);
  }
};

}  // namespace math
}  // namespace falcon_core

using namespace falcon_core::math;

#ifndef SWIG
CEREAL_REGISTER_TYPE(Axes<double>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, Axes<double>)
CEREAL_REGISTER_TYPE(Axes<falcon_core::math::discretizers::BaseDiscretizer>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, Axes<falcon_core::math::discretizers::BaseDiscretizer>)
#endif
