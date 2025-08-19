#pragma once
#include <cereal/types/map.hpp>
#include <cereal/types/memory.hpp>

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace math {

template <typename T>
class Axes : public std::vector<std::shared_ptr<T>>, public generic::Song {
 public:
  using std::vector<std::shared_ptr<T>>::vector;

 private:
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this),
       cereal::base_class<std::vector<std::shared_ptr<T>>>(this));
  }

 protected:
  Axes() = default;
  friend class cereal::access;
};

using namespace falcon_core::math;
CEREAL_REGISTER_TYPE(Axes<double>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, Axes<double>)

}  // namespace math
}  // namespace falcon_core
