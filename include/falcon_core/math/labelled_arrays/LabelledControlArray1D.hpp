#pragma once

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/math/arrays/ControlArray1D.hpp"
#include "falcon_core/math/labelled_arrays/BaseLabelledArray.hpp"
#include "falcon_core/math/labelled_arrays/IsLabelled1D.hpp"
#include "falcon_core/physics/device_structures/Gate.hpp"
namespace falcon_core
{
namespace math
{
namespace labelled_arrays
{
using LabelType = instrument_interfaces::names::InstrumentPort<
    physics::device_structures::Gate>;

class LabelledControlArray1D
    : public BaseLabelledArray<arrays::ControlArray1D, LabelType>,
      public IsLabelled1D<LabelledControlArray1D>
{
public:
  LabelledControlArray1D (std::shared_ptr<arrays::ControlArray1D> array,
                          std::shared_ptr<LabelType>              label)
      : BaseLabelledArray<arrays::ControlArray1D, LabelType> (array, label)
  {
  }
  const arrays::ControlArray1D &
  get_array () const
  {
    if (!this->_array)
      {
        throw std::runtime_error ("Array is null");
      }
    return *this->_array;
  }

  nlohmann::json
  to_json () const override
  {
    nlohmann::json j = this->to_json ();
    add_metadata (j,
                  "falcon_core.math.labelled_arrays.labelled_control_array_1D",
                  "LabelledControlArray1D");
    return j;
  }
};
}
}
} // namespace falcon_core
