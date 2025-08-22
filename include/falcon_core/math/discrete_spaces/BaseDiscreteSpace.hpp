#pragma once
#include <memory>
#include "falcon_core/generic/Song.hpp"
#include "falcon_core/math/Axes.hpp"
#include "falcon_core/math/spaces/UnitSpace.hpp"
#include "falcon_core/math/domains/CoupledKnobDomain.hpp"

namespace falcon_core {
namespace math {
namespace discrete_spaces {

class BaseDiscreteSpace : public generic::Song {
 public:
  using AxesType = Axes<domains::CoupledKnobDomain>;
  using SpacePtr = std::shared_ptr<spaces::UnitSpace>;

  BaseDiscreteSpace() = default;
  BaseDiscreteSpace(SpacePtr space,
                    std::shared_ptr<AxesType> axes)
      : _space(space), _axes(axes) {}

  const SpacePtr& space() const { return _space; }
  const std::shared_ptr<AxesType>& axes() const { return _axes; }

  // TODO: Add validation and projection methods as needed

 private:
  SpacePtr _space;
  std::shared_ptr<AxesType> _axes;

  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _space, _axes);
  }
};

}  // namespace discrete_spaces
}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::math::discrete_spaces::BaseDiscreteSpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, falcon_core::math::discrete_spaces::BaseDiscreteSpace)
#endif
