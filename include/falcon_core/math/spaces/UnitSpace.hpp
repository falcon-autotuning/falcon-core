#pragma once

#include <memory>
#include <vector>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/math/Axes.hpp"
#include "falcon_core/math/discretizers/BaseDiscretizer.hpp"
#include "falcon_core/math/domains/Domain.hpp"

namespace falcon_core {
namespace math {
namespace spaces {

class UnitSpace : public generic::Song {
 public:
  using DiscretizerPtr = std::shared_ptr<discretizers::BaseDiscretizer>;
  using AxesType       = Axes<discretizers::BaseDiscretizer>;
  using DomainPtr      = std::shared_ptr<domains::Domain>;

  UnitSpace(const AxesType& axes, DomainPtr domain)
      : _axes(axes), _domain(domain) {}

  const AxesType&  axes() const { return _axes; }
  const DomainPtr& domain() const { return _domain; }

 protected:
  AxesType  _axes;
  DomainPtr _domain;

  friend class cereal::access;
  UnitSpace() = default;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _axes, _domain);
  }
};

}  // namespace spaces
}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::math::spaces::UnitSpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::spaces::UnitSpace)
#endif
