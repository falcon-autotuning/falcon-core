#pragma once

#include <cereal/types/memory.hpp>
#include <memory>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/math/domains/Domain.hpp"

namespace falcon_core {
namespace math {
namespace discretizers {
class BaseDiscretizer : public generic::Song {
 public:
  BaseDiscretizer(double delta, std::shared_ptr<domains::Domain> delta_domain)
      : _delta(delta), _delta_domain(std::move(delta_domain)) {}

  virtual ~BaseDiscretizer() = default;

  double delta() const { return _delta; }
  void   set_delta(double delta) { _delta = delta; }

  const std::shared_ptr<domains::Domain>& delta_domain() const {
    return _delta_domain;
  }

protected:
  double                           _delta;
  std::shared_ptr<domains::Domain> _delta_domain;

  friend class cereal::access;
  BaseDiscretizer() = default;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _delta, _delta_domain);
  }
};
}  // namespace discretizers
}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
using namespace falcon_core::math::discretizers;
CEREAL_REGISTER_TYPE(falcon_core::math::discretizers::BaseDiscretizer)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::discretizers::BaseDiscretizer)
#endif
