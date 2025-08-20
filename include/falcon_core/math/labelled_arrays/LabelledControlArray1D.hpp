#pragma once

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/math/arrays/ControlArray1D.hpp"
#include "falcon_core/math/labelled_arrays/BaseLabelledArray.hpp"
#include "falcon_core/math/labelled_arrays/IsLabelled1D.hpp"
#include "falcon_core/physics/device_structures/Gate.hpp"
namespace falcon_core {
namespace math {
namespace labelled_arrays {

class LabelledControlArray1D
    : public BaseLabelledArray<arrays::ControlArray1D,
                               instrument_interfaces::names::InstrumentPort<
                                   physics::device_structures::Gate>>,
      public IsLabelled1D<LabelledControlArray1D> {
 public:
  LabelledControlArray1D(
      std::shared_ptr<arrays::ControlArray1D> array,
      std::shared_ptr<instrument_interfaces::names::InstrumentPort<
          physics::device_structures::Gate>>  label)
      : BaseLabelledArray<arrays::ControlArray1D, LabelType>(array, label) {}
  const arrays::ControlArray1D& get_array() const {
    if (!this->_array) {
      throw std::runtime_error("Array is null");
    }
    return *this->_array;
  }
  using LabelType = instrument_interfaces::names::InstrumentPort<
      physics::device_structures::Gate>;

 private:
  friend class cereal::access;
  LabelledControlArray1D() = default;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseLabelledArray<arrays::ControlArray1D, LabelType>>(
        this));
  }
};
}  // namespace labelled_arrays
}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
using namespace falcon_core::math::labelled_arrays;
CEREAL_REGISTER_TYPE(falcon_core::math::labelled_arrays::LabelledControlArray1D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::labelled_arrays::LabelledControlArray1D)
#endif
