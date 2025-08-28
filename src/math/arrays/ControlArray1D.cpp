#include "falcon_core/math/arrays/ControlArray1D.hpp"

namespace falcon_core {
namespace math {
namespace arrays {

ControlArray1D::ControlArray1D(const typename ControlArray<double>::MatrixType& data)
    : ControlArray<double>(data) {
  if (!this->is_1d()) {
    throw std::invalid_argument(
        "Data for ControlArray1D must be 1-dimensional.");
  }
}

ControlArray1D::ControlArray1D() = default;

template <class Archive>
void ControlArray1D::serialize(Archive& ar) {
  ar(cereal::base_class<ControlArray<double>>(this));
}

}}} // namespace

CEREAL_REGISTER_TYPE(falcon_core::math::arrays::ControlArray1D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::arrays::ControlArray1D)
