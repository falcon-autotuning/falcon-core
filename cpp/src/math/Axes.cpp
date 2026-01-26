

#include "falcon_core/math/Axes.hpp"

#include <cereal/types/polymorphic.hpp>

#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext.hpp"
#include "falcon_core/generic/Map.hpp"
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
CEREAL_REGISTER_TYPE(
    falcon_core::math::Axes<
        falcon_core::autotuner_interfaces::contexts::MeasurementContext>)
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
CEREAL_REGISTER_TYPE(
    falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::Axes<int>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::Axes<double>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::Axes<
        falcon_core::autotuner_interfaces::contexts::MeasurementContext>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::Axes<
        falcon_core::instrument_interfaces::names::InstrumentPort>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>)
using AxesMapStringBool =
    falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     AxesMapStringBool)

// Explicit instantiations exported from the falcon_core library.
template class FALCON_CORE_CPP_API falcon_core::math::Axes<int>;
template class FALCON_CORE_CPP_API falcon_core::math::Axes<double>;
template class FALCON_CORE_CPP_API
    falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>;
template class FALCON_CORE_CPP_API falcon_core::math::Axes<
    falcon_core::autotuner_interfaces::contexts::MeasurementContext>;
template class FALCON_CORE_CPP_API falcon_core::math::Axes<
    falcon_core::instrument_interfaces::names::InstrumentPort>;
template class FALCON_CORE_CPP_API
    falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>;
template class FALCON_CORE_CPP_API
    falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>;
template class FALCON_CORE_CPP_API
    falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>;
template class FALCON_CORE_CPP_API
    falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>;
template class FALCON_CORE_CPP_API
    falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>;
template class FALCON_CORE_CPP_API
    falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>;
template class FALCON_CORE_CPP_API
    falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>;
template class FALCON_CORE_CPP_API
    falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>;
