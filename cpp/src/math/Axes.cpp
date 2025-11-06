

#include "falcon_core/math/Axes.hpp"

#include <cereal/types/polymorphic.hpp>

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/math/arrays/ControlArray.hpp"
#include "falcon_core/math/arrays/ControlArray1D.hpp"
#include "falcon_core/math/arrays/LabelledControlArray.hpp"
#include "falcon_core/math/arrays/LabelledControlArray1D.hpp"
#include "falcon_core/math/arrays/LabelledMeasuredArray.hpp"
#include "falcon_core/math/arrays/LabelledMeasuredArray1D.hpp"
#include "falcon_core/math/discrete_spaces/Discretizer.hpp"
#include "falcon_core/math/domains/CoupledLabelledDomain.hpp"

CEREAL_REGISTER_TYPE(falcon_core::math::Axes<int>)
CEREAL_REGISTER_TYPE(falcon_core::math::Axes<double>)
CEREAL_REGISTER_TYPE(
    falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>)
CEREAL_REGISTER_TYPE(falcon_core::math::Axes<
                     falcon_core::instrument_interfaces::names::InstrumentPort>)
CEREAL_REGISTER_TYPE(
    falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>)
CEREAL_REGISTER_TYPE(
    falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>)
CEREAL_REGISTER_TYPE(
    falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>)
CEREAL_REGISTER_TYPE(
    falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>)
CEREAL_REGISTER_TYPE(
    falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>)
CEREAL_REGISTER_TYPE(
    falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>)
CEREAL_REGISTER_TYPE(
    falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>)
