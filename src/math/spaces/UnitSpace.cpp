#include "falcon_core/math/spaces/UnitSpace.hpp"

namespace falcon_core {
namespace math {
namespace spaces {

UnitSpace::UnitSpace(const AxesType& axes, DomainPtr domain)
    : _axes(axes), _domain(domain) {}

const UnitSpace::AxesType& UnitSpace::axes() const { return _axes; }
const UnitSpace::DomainPtr& UnitSpace::domain() const { return _domain; }

UnitSpace::UnitSpace() = default;

template <class Archive>
void UnitSpace::serialize(Archive& ar) {
  ar(cereal::base_class<generic::Song>(this), _axes, _domain);
}

}}} // namespace

CEREAL_REGISTER_TYPE(falcon_core::math::spaces::UnitSpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::spaces::UnitSpace)
