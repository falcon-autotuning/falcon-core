#include "falcon_core/generic/List.hpp"

#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext.hpp"
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp"
#include "falcon_core/autotuner_interfaces/names/Channel.hpp"
#include "falcon_core/autotuner_interfaces/names/Gname.hpp"
#include "falcon_core/communications/voltage_states/DeviceVoltageState.hpp"
#include "falcon_core/generic/FArray.hpp"
#include "falcon_core/generic/Pair.hpp"
#include "falcon_core/instrument_interfaces/Waveform.hpp"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"
#include "falcon_core/math/Quantity.hpp"
#include "falcon_core/math/arrays/LabelledControlArray.hpp"
#include "falcon_core/math/arrays/LabelledControlArray1D.hpp"
#include "falcon_core/math/arrays/LabelledMeasuredArray.hpp"
#include "falcon_core/math/arrays/LabelledMeasuredArray1D.hpp"
#include "falcon_core/math/discrete_spaces/Discretizer.hpp"
#include "falcon_core/math/domains/CoupledLabelledDomain.hpp"
#include "falcon_core/math/domains/LabelledDomain.hpp"
#include "falcon_core/physics/config/core/Group.hpp"
#include "falcon_core/physics/device_structures/Connections.hpp"
#include "falcon_core/physics/device_structures/Impedance.hpp"

CEREAL_REGISTER_TYPE(falcon_core::generic::List<int>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<float>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<double>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<size_t>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<std::string>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<falcon_core::math::Quantity>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::generic::FArray<double>>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::autotuner_interfaces::names::Gname>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<
        falcon_core::instrument_interfaces::port_transforms::PortTransform>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::generic::Pair<std::string, double>>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::generic::Pair<std::string, std::string>>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::generic::Pair<falcon_core::math::Quantity,
                                                falcon_core::math::Quantity>>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::generic::Pair<int, int>>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::generic::Pair<int, float>>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::generic::Pair<float, float>>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::generic::Pair<
        falcon_core::autotuner_interfaces::names::Gname,
        falcon_core::physics::device_structures::Connections>>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::generic::Pair<
        falcon_core::autotuner_interfaces::names::Channel,
        falcon_core::physics::device_structures::Connections>>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::generic::Pair<
        falcon_core::physics::device_structures::Connection,
        falcon_core::physics::device_structures::Connections>>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<falcon_core::generic::Pair<
                         falcon_core::autotuner_interfaces::names::Gname,
                         falcon_core::physics::config::core::Group>>)
CEREAL_REGISTER_TYPE(falcon_core::generic::List<falcon_core::generic::Pair<
                         falcon_core::physics::device_structures::Connection,
                         double>>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<falcon_core::generic::Pair<
                         falcon_core::physics::device_structures::Connection,
                         falcon_core::math::Quantity>>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<falcon_core::generic::Pair<
                         falcon_core::physics::device_structures::Connection,
                         float>>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::generic::Pair<
        falcon_core::instrument_interfaces::names::InstrumentPort,
        falcon_core::instrument_interfaces::port_transforms::PortTransform>>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<
        falcon_core::generic::Pair<falcon_core::autotuner_interfaces::
                                       interpretations::InterpretationContext,
                                   double>>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<
        falcon_core::generic::Pair<falcon_core::autotuner_interfaces::
                                       interpretations::InterpretationContext,
                                   falcon_core::math::Quantity>>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<
        falcon_core::generic::Pair<falcon_core::autotuner_interfaces::
                                       interpretations::InterpretationContext,
                                   std::string>>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::generic::Pair<
        falcon_core::physics::device_structures::Connection,
        falcon_core::generic::Pair<falcon_core::math::Quantity,
                                   falcon_core::math::Quantity>>>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::generic::List<size_t>>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<
        falcon_core::autotuner_interfaces::contexts::MeasurementContext>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::math::arrays::LabelledMeasuredArray>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::math::arrays::LabelledMeasuredArray1D>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::math::arrays::LabelledControlArray>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::math::arrays::LabelledControlArray1D>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::autotuner_interfaces::
                                   interpretations::InterpretationContext>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<
        falcon_core::instrument_interfaces::names::InstrumentPort>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::physics::device_structures::Impedance>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::physics::config::core::Group>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<
        falcon_core::physics::config::geometries::DotGateWithNeighbors>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::math::discrete_spaces::Discretizer>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<
        falcon_core::communications::voltage_states::DeviceVoltageState>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::math::domains::CoupledLabelledDomain>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::math::arrays::ControlArray>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::physics::device_structures::Connection>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::physics::device_structures::Connections>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::autotuner_interfaces::names::Channel>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<
        falcon_core::autotuner_interfaces::contexts::AcquisitionContext>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>);

CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::generic::List<int>);
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::generic::List<double>);
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::generic::List<float>);
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::generic::List<size_t>);
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::generic::List<std::string>);
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::generic::List<falcon_core::math::Quantity>);
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::generic::List<falcon_core::generic::FArray<double>>);
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::generic::List<
        falcon_core::autotuner_interfaces::names::Gname>);
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::generic::List<
        falcon_core::instrument_interfaces::port_transforms::PortTransform>);

// -----------------------------------------------------------------------------
// Explicit template instantiations
//
// These force the falcon_core library to emit the concrete List<T> symbols.
// Consumers (tests) should compile with FALCON_CORE_USE_EXTERN_TEMPLATES
// defined so they do not instantiate the same templates again (avoids
// duplicate-link).
// -----------------------------------------------------------------------------

template class FALCON_CORE_CPP_API falcon_core::generic::List<int>;
template class FALCON_CORE_CPP_API falcon_core::generic::List<float>;
template class FALCON_CORE_CPP_API falcon_core::generic::List<double>;
template class FALCON_CORE_CPP_API falcon_core::generic::List<size_t>;
template class FALCON_CORE_CPP_API falcon_core::generic::List<std::string>;
template class FALCON_CORE_CPP_API
    falcon_core::generic::List<falcon_core::math::Quantity>;
template class FALCON_CORE_CPP_API
    falcon_core::generic::List<falcon_core::generic::FArray<double>>;
template class FALCON_CORE_CPP_API
    falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>;
template class FALCON_CORE_CPP_API falcon_core::generic::List<
    falcon_core::instrument_interfaces::port_transforms::PortTransform>;
template class FALCON_CORE_CPP_API
    falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>;
template class FALCON_CORE_CPP_API
    falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>;
template class FALCON_CORE_CPP_API falcon_core::generic::List<
    falcon_core::generic::Pair<std::string, std::string>>;
template class FALCON_CORE_CPP_API
    falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>;
template class FALCON_CORE_CPP_API falcon_core::generic::List<
    falcon_core::generic::Pair<falcon_core::math::Quantity,
                               falcon_core::math::Quantity>>;
template class FALCON_CORE_CPP_API
    falcon_core::generic::List<falcon_core::generic::Pair<int, int>>;
template class FALCON_CORE_CPP_API
    falcon_core::generic::List<falcon_core::generic::Pair<int, float>>;
template class FALCON_CORE_CPP_API
    falcon_core::generic::List<falcon_core::generic::Pair<float, float>>;
template class FALCON_CORE_CPP_API
    falcon_core::generic::List<falcon_core::generic::Pair<
        falcon_core::autotuner_interfaces::names::Gname,
        falcon_core::physics::device_structures::Connections>>;
template class FALCON_CORE_CPP_API
    falcon_core::generic::List<falcon_core::generic::Pair<
        falcon_core::autotuner_interfaces::names::Channel,
        falcon_core::physics::device_structures::Connections>>;
template class FALCON_CORE_CPP_API
    falcon_core::generic::List<falcon_core::generic::Pair<
        falcon_core::physics::device_structures::Connection,
        falcon_core::physics::device_structures::Connections>>;
template class FALCON_CORE_CPP_API falcon_core::generic::List<
    falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname,
                               falcon_core::physics::config::core::Group>>;
template class FALCON_CORE_CPP_API falcon_core::generic::List<
    falcon_core::generic::
        Pair<falcon_core::physics::device_structures::Connection, double>>;
template class FALCON_CORE_CPP_API
    falcon_core::generic::List<falcon_core::generic::Pair<
        falcon_core::physics::device_structures::Connection,
        falcon_core::math::Quantity>>;
template class FALCON_CORE_CPP_API falcon_core::generic::List<
    falcon_core::generic::
        Pair<falcon_core::physics::device_structures::Connection, float>>;
template class FALCON_CORE_CPP_API
    falcon_core::generic::List<falcon_core::generic::Pair<
        falcon_core::instrument_interfaces::names::InstrumentPort,
        falcon_core::instrument_interfaces::port_transforms::PortTransform>>;
template class FALCON_CORE_CPP_API falcon_core::generic::List<
    falcon_core::generic::Pair<falcon_core::autotuner_interfaces::
                                   interpretations::InterpretationContext,
                               double>>;
template class FALCON_CORE_CPP_API falcon_core::generic::List<
    falcon_core::generic::Pair<falcon_core::autotuner_interfaces::
                                   interpretations::InterpretationContext,
                               falcon_core::math::Quantity>>;
template class FALCON_CORE_CPP_API falcon_core::generic::List<
    falcon_core::generic::Pair<falcon_core::autotuner_interfaces::
                                   interpretations::InterpretationContext,
                               std::string>>;
template class FALCON_CORE_CPP_API
    falcon_core::generic::List<falcon_core::generic::Pair<
        falcon_core::physics::device_structures::Connection,
        falcon_core::generic::Pair<falcon_core::math::Quantity,
                                   falcon_core::math::Quantity>>>;
template class FALCON_CORE_CPP_API
    falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>;
template class FALCON_CORE_CPP_API
    falcon_core::generic::List<falcon_core::generic::List<size_t>>;
template class FALCON_CORE_CPP_API falcon_core::generic::List<
    falcon_core::autotuner_interfaces::contexts::MeasurementContext>;
template class FALCON_CORE_CPP_API falcon_core::generic::List<
    falcon_core::math::arrays::LabelledMeasuredArray>;
template class FALCON_CORE_CPP_API falcon_core::generic::List<
    falcon_core::math::arrays::LabelledMeasuredArray1D>;
template class FALCON_CORE_CPP_API
    falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>;
template class FALCON_CORE_CPP_API falcon_core::generic::List<
    falcon_core::math::arrays::LabelledControlArray1D>;
template class FALCON_CORE_CPP_API
    falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>;
template class FALCON_CORE_CPP_API falcon_core::generic::List<
    falcon_core::autotuner_interfaces::interpretations::InterpretationContext>;
template class FALCON_CORE_CPP_API falcon_core::generic::List<
    falcon_core::instrument_interfaces::names::InstrumentPort>;
template class FALCON_CORE_CPP_API falcon_core::generic::List<
    falcon_core::physics::device_structures::Impedance>;
template class FALCON_CORE_CPP_API
    falcon_core::generic::List<falcon_core::physics::config::core::Group>;
template class FALCON_CORE_CPP_API falcon_core::generic::List<
    falcon_core::physics::config::geometries::DotGateWithNeighbors>;
template class FALCON_CORE_CPP_API
    falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>;
template class FALCON_CORE_CPP_API falcon_core::generic::List<
    falcon_core::communications::voltage_states::DeviceVoltageState>;
template class FALCON_CORE_CPP_API falcon_core::generic::List<
    falcon_core::math::domains::CoupledLabelledDomain>;
template class FALCON_CORE_CPP_API
    falcon_core::generic::List<falcon_core::math::arrays::ControlArray>;
template class FALCON_CORE_CPP_API
    falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>;
template class FALCON_CORE_CPP_API falcon_core::generic::List<
    falcon_core::physics::device_structures::Connection>;
template class FALCON_CORE_CPP_API falcon_core::generic::List<
    falcon_core::physics::device_structures::Connections>;
template class FALCON_CORE_CPP_API falcon_core::generic::List<
    falcon_core::autotuner_interfaces::names::Channel>;
template class FALCON_CORE_CPP_API falcon_core::generic::List<
    falcon_core::autotuner_interfaces::contexts::AcquisitionContext>;
template class FALCON_CORE_CPP_API
    falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>;
