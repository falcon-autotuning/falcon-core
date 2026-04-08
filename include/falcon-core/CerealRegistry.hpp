#include <falcon-core/communications/messages/BaseMessage.hpp>
#include <falcon-core/communications/messages/MeasurementRequest.hpp>
#include <falcon-core/communications/messages/MeasurementResponse.hpp>
#include <falcon-core/communications/messages/StandardRequest.hpp>
#include <falcon-core/communications/messages/StandardResponse.hpp>
#include <falcon-core/communications/messages/VoltageStatesResponse.hpp>

#include "falcon-core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon-core/autotuner_interfaces/contexts/MeasurementContext.hpp"
#include "falcon-core/autotuner_interfaces/interpretations/InterpretationContainer.hpp"
#include "falcon-core/autotuner_interfaces/interpretations/InterpretationContext.hpp"
#include "falcon-core/autotuner_interfaces/names/Channel.hpp"
#include "falcon-core/autotuner_interfaces/names/Channels.hpp"
#include "falcon-core/autotuner_interfaces/names/Gname.hpp"
#include "falcon-core/communications/HDF5Data.hpp"
#include "falcon-core/communications/Time.hpp"
#include "falcon-core/communications/voltage_states/DeviceVoltageState.hpp"
#include "falcon-core/generic/FArray.hpp"
#include "falcon-core/generic/List.hpp"
#include "falcon-core/generic/Map.hpp"
#include "falcon-core/generic/Pair.hpp"
#include "falcon-core/instrument_interfaces/Waveform.hpp"
#include "falcon-core/instrument_interfaces/port_transforms/PortTransform.hpp"
#include "falcon-core/math/Quantity.hpp"
#include "falcon-core/math/Vector.hpp"
#include "falcon-core/math/arrays/ControlArray.hpp"
#include "falcon-core/math/arrays/ControlArray1D.hpp"
#include "falcon-core/math/arrays/IncreasingAlignment.hpp"
#include "falcon-core/math/arrays/LabelledArrays.hpp"
#include "falcon-core/math/arrays/LabelledControlArray.hpp"
#include "falcon-core/math/arrays/LabelledControlArray1D.hpp"
#include "falcon-core/math/arrays/LabelledMeasuredArray.hpp"
#include "falcon-core/math/arrays/LabelledMeasuredArray1D.hpp"
#include "falcon-core/math/discrete_spaces/DiscreteSpace.hpp"
#include "falcon-core/math/discrete_spaces/Discretizer.hpp"
#include "falcon-core/math/domains/CoupledLabelledDomain.hpp"
#include "falcon-core/math/domains/LabelledDomain.hpp"
#include "falcon-core/physics/config/core/Adjacency.hpp"
#include "falcon-core/physics/config/core/Config.hpp"
#include "falcon-core/physics/config/core/Group.hpp"
#include "falcon-core/physics/device_structures/Connections.hpp"
#include "falcon-core/physics/device_structures/Impedance.hpp"

CEREAL_REGISTER_TYPE(falcon_core::generic::Song);
CEREAL_REGISTER_TYPE(falcon_core::physics::units::Unit)
CEREAL_REGISTER_TYPE(falcon_core::physics::units::SymbolUnit)
CEREAL_REGISTER_TYPE(falcon_core::generic::FArray<size_t>);
CEREAL_REGISTER_TYPE(falcon_core::generic::FArray<int>)
CEREAL_REGISTER_TYPE(falcon_core::generic::FArray<double>)
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::generic::FArray<double>>);
CEREAL_REGISTER_TYPE(falcon_core::autotuner_interfaces::names::Channel)
CEREAL_REGISTER_TYPE(falcon_core::autotuner_interfaces::names::Channels)
CEREAL_REGISTER_TYPE(falcon_core::autotuner_interfaces::names::Gname)
CEREAL_REGISTER_TYPE(falcon_core::autotuner_interfaces::names::NameBase)
CEREAL_REGISTER_TYPE(falcon_core::communications::messages::BaseMessage)
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::IncreasingAlignment)
CEREAL_REGISTER_TYPE(falcon_core::math::discrete_spaces::Discretizer)
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::ControlArray)
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::ControlArray1D)
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::MeasuredArray)
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::MeasuredArray1D)
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<double, double>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<float, float>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<int, int>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<int, float>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<size_t, size_t>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<std::string, std::string>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<std::string, double>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<std::string, bool>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<int>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<float>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<double>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<size_t>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<std::string>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<bool>)
CEREAL_REGISTER_TYPE(falcon_core::math::Axes<int>)
CEREAL_REGISTER_TYPE(falcon_core::math::Axes<double>)
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::generic::Pair<int, int>>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::generic::Pair<int, float>>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::generic::Pair<float, float>>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::generic::Pair<std::string, double>>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::generic::Pair<std::string, std::string>>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Map<int, int>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Map<float, float>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Map<std::string, bool>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Map<std::string, double>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Map<std::string, std::string>);
CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::Connection)
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::physics::device_structures::Connection>);
CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::Connections)
CEREAL_REGISTER_TYPE(falcon_core::math::Quantity)
CEREAL_REGISTER_TYPE(falcon_core::generic::List<falcon_core::math::Quantity>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<falcon_core::math::Quantity,
                                                falcon_core::math::Quantity>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::generic::Pair<falcon_core::math::Quantity,
                                                falcon_core::math::Quantity>>);
CEREAL_REGISTER_TYPE(falcon_core::physics::config::core::Adjacency)
CEREAL_REGISTER_TYPE(falcon_core::generic::Map<
                     falcon_core::physics::device_structures::Connection,
                     float>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Map<
                     falcon_core::physics::device_structures::Connection,
                     double>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Map<
                     falcon_core::autotuner_interfaces::names::Channel,
                     falcon_core::physics::device_structures::Connections>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,
                              falcon_core::physics::config::core::Group>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Map<
                     falcon_core::physics::device_structures::Connection,
                     falcon_core::math::Quantity>);
CEREAL_REGISTER_TYPE(
    falcon_core::communications::voltage_states::DeviceVoltageState)
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<
        falcon_core::communications::voltage_states::DeviceVoltageState>)
CEREAL_REGISTER_TYPE(
    falcon_core::autotuner_interfaces::interpretations::InterpretationContext)
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::autotuner_interfaces::
                                   interpretations::InterpretationContext>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::Pair<falcon_core::autotuner_interfaces::
                                   interpretations::InterpretationContext,
                               double>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::Pair<falcon_core::autotuner_interfaces::
                                   interpretations::InterpretationContext,
                               std::string>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::Pair<falcon_core::autotuner_interfaces::
                                   interpretations::InterpretationContext,
                               falcon_core::math::Quantity>);
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
    falcon_core::generic::Map<falcon_core::autotuner_interfaces::
                                  interpretations::InterpretationContext,
                              std::string>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::Map<falcon_core::autotuner_interfaces::
                                  interpretations::InterpretationContext,
                              falcon_core::math::Quantity>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::Map<falcon_core::autotuner_interfaces::
                                  interpretations::InterpretationContext,
                              double>);
CEREAL_REGISTER_TYPE(
    falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<
        double>)
CEREAL_REGISTER_TYPE(
    falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<
        std::string>)
CEREAL_REGISTER_TYPE(
    falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<
        falcon_core::math::Quantity>)
CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::names::InstrumentPort)
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<
        falcon_core::instrument_interfaces::names::InstrumentPort>);
CEREAL_REGISTER_TYPE(falcon_core::math::Axes<
                     falcon_core::instrument_interfaces::names::InstrumentPort>)
CEREAL_REGISTER_TYPE(
    falcon_core::generic::Pair<
        falcon_core::instrument_interfaces::names::InstrumentPort,
        falcon_core::instrument_interfaces::port_transforms::PortTransform>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::generic::Pair<
        falcon_core::instrument_interfaces::names::InstrumentPort,
        falcon_core::instrument_interfaces::port_transforms::PortTransform>>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::Map<
        falcon_core::instrument_interfaces::names::InstrumentPort,
        falcon_core::instrument_interfaces::port_transforms::PortTransform>);
CEREAL_REGISTER_TYPE(falcon_core::math::AnalyticFunction)
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<
                     falcon_core::instrument_interfaces::names::InstrumentPort,
                     falcon_core::math::AnalyticFunction>)
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::LabelledMeasuredArray1D)
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::LabelledControlArray)
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::LabelledControlArray1D)
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::LabelledMeasuredArray)
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::math::arrays::LabelledMeasuredArray>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::math::arrays::LabelledMeasuredArray1D>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::math::arrays::LabelledControlArray>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::math::arrays::LabelledControlArray1D>);
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
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::LabelledArrays<
                     falcon_core::math::arrays::LabelledMeasuredArray>)
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::LabelledArrays<
                     falcon_core::math::arrays::LabelledControlArray>)
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::LabelledArrays<
                     falcon_core::math::arrays::LabelledMeasuredArray1D>)
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::LabelledArrays<
                     falcon_core::math::arrays::LabelledControlArray1D>)
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<
                     falcon_core::autotuner_interfaces::names::Channel,
                     falcon_core::physics::device_structures::Connections>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<
                     falcon_core::physics::device_structures::Connection,
                     falcon_core::physics::device_structures::Connections>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<
                     falcon_core::physics::device_structures::Connection,
                     falcon_core::physics::device_structures::Connection>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<
                     falcon_core::physics::device_structures::Connection,
                     falcon_core::math::Quantity>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<
                     falcon_core::physics::device_structures::Connection,
                     falcon_core::generic::Pair<falcon_core::math::Quantity,
                                                falcon_core::math::Quantity>>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname,
                               falcon_core::physics::config::core::Group>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::Pair<
        falcon_core::communications::messages::MeasurementResponse,
        falcon_core::communications::messages::MeasurementRequest>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<
                     falcon_core::physics::device_structures::Connection,
                     float>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<
                     falcon_core::physics::device_structures::Connection,
                     double>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::autotuner_interfaces::names::Gname>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<
        falcon_core::instrument_interfaces::port_transforms::PortTransform>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>);
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
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::physics::device_structures::Impedance>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::physics::config::core::Group>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<
        falcon_core::physics::config::geometries::DotGateWithNeighbors>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::math::discrete_spaces::Discretizer>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::math::domains::CoupledLabelledDomain>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::math::arrays::ControlArray>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::physics::device_structures::Connections>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<
                     falcon_core::autotuner_interfaces::names::Channel>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<
        falcon_core::autotuner_interfaces::contexts::AcquisitionContext>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>);
CEREAL_REGISTER_TYPE(
    falcon_core::autotuner_interfaces::contexts::AcquisitionContext)
CEREAL_REGISTER_TYPE(falcon_core::autotuner_interfaces::contexts::BaseContext)
CEREAL_REGISTER_TYPE(
    falcon_core::autotuner_interfaces::contexts::MeasurementContext)
CEREAL_REGISTER_TYPE(falcon_core::math::domains::CoupledLabelledDomain);
CEREAL_REGISTER_TYPE(falcon_core::math::discrete_spaces::DiscreteSpace)
CEREAL_REGISTER_TYPE(falcon_core::communications::messages::MeasurementRequest)
CEREAL_REGISTER_TYPE(falcon_core::communications::messages::MeasurementResponse)
CEREAL_REGISTER_TYPE(falcon_core::communications::messages::StandardRequest)
CEREAL_REGISTER_TYPE(falcon_core::communications::messages::StandardResponse)
CEREAL_REGISTER_TYPE(
    falcon_core::communications::messages::VoltageStatesResponse)
CEREAL_REGISTER_TYPE(falcon_core::communications::Time)
CEREAL_REGISTER_TYPE(falcon_core::communications::HDF5Data)
CEREAL_REGISTER_TYPE(
    falcon_core::communications::voltage_states::DeviceVoltageStates)
CEREAL_REGISTER_TYPE(falcon_core::physics::config::core::Config)
CEREAL_REGISTER_TYPE(falcon_core::physics::config::core::Group)
CEREAL_REGISTER_TYPE(
    falcon_core::physics::config::core::StandardConfigConnections)
CEREAL_REGISTER_TYPE(falcon_core::physics::config::core::VoltageConstraints)
CEREAL_REGISTER_TYPE(falcon_core::physics::config::geometries::HasLeftNeighbor)
CEREAL_REGISTER_TYPE(falcon_core::physics::config::geometries::HasRightNeighbor)
CEREAL_REGISTER_TYPE(
    falcon_core::physics::config::geometries::DotGateWithNeighbors)
CEREAL_REGISTER_TYPE(
    falcon_core::physics::config::geometries::DotGatesWithNeighbors)
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<
        falcon_core::physics::config::geometries::DotGatesWithNeighbors>)
CEREAL_REGISTER_TYPE(
    falcon_core::physics::config::geometries::GateGeometryArray1D)
CEREAL_REGISTER_TYPE(
    falcon_core::physics::config::geometries::HasImplantedOhmic)
CEREAL_REGISTER_TYPE(
    falcon_core::physics::config::geometries::LeftReservoirWithImplantedOhmic)
CEREAL_REGISTER_TYPE(
    falcon_core::physics::config::geometries::RightReservoirWithImplantedOhmic)
CEREAL_REGISTER_TYPE(falcon_core::math::domains::Domain)
CEREAL_REGISTER_TYPE(falcon_core::math::domains::LabelledDomain)
CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::Waveform)
CEREAL_REGISTER_TYPE(
    falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>)
CEREAL_REGISTER_TYPE(
    falcon_core::math::Axes<
        falcon_core::autotuner_interfaces::contexts::MeasurementContext>)
CEREAL_REGISTER_TYPE(
    falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>)
CEREAL_REGISTER_TYPE(
    falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>)
CEREAL_REGISTER_TYPE(falcon_core::math::Point)
CEREAL_REGISTER_TYPE(falcon_core::math::UnitSpace)
CEREAL_REGISTER_TYPE(falcon_core::math::Vector)
CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::names::Ports)
CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::GateRelations)
CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::Impedance)
CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::Impedances)
CEREAL_REGISTER_TYPE(
    falcon_core::instrument_interfaces::port_transforms::PortTransforms)
CEREAL_REGISTER_TYPE(
    falcon_core::instrument_interfaces::port_transforms::PortTransform)

CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::List<
        falcon_core::physics::device_structures::Connection>,
    falcon_core::physics::device_structures::Connections)
using MapGR = falcon_core::generic::Map<
    falcon_core::physics::device_structures::Connection,
    falcon_core::physics::device_structures::Connections>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    MapGR, falcon_core::physics::device_structures::GateRelations)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::device_structures::Impedance)
using LII = falcon_core::generic::List<
    falcon_core::physics::device_structures::Impedance>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    LII, falcon_core::physics::device_structures::Impedances)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::List<
        falcon_core::instrument_interfaces::port_transforms::PortTransform>,
    falcon_core::instrument_interfaces::port_transforms::PortTransforms)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::AnalyticFunction,
    falcon_core::instrument_interfaces::port_transforms::PortTransform)
using MII = falcon_core::generic::Map<int, int>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, MII);
using MFF = falcon_core::generic::Map<float, float>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, MFF);
using MSB = falcon_core::generic::Map<std::string, bool>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, MSB);
using MSD = falcon_core::generic::Map<std::string, double>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, MSD);
using MSS = falcon_core::generic::Map<std::string, std::string>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, MSS);
using MICSS = falcon_core::generic::Map<
    falcon_core::autotuner_interfaces::interpretations::InterpretationContext,
    std::string>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, MICSS);
using MICQ = falcon_core::generic::Map<
    falcon_core::autotuner_interfaces::interpretations::InterpretationContext,
    falcon_core::math::Quantity>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, MICQ);
using MICD = falcon_core::generic::Map<
    falcon_core::autotuner_interfaces::interpretations::InterpretationContext,
    double>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, MICD);
using MCnF = falcon_core::generic::
    Map<falcon_core::physics::device_structures::Connection, float>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, MCnF);
using MCnD = falcon_core::generic::
    Map<falcon_core::physics::device_structures::Connection, double>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, MCnD);
using MCC = falcon_core::generic::Map<
    falcon_core::autotuner_interfaces::names::Channel,
    falcon_core::physics::device_structures::Connections>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, MCC);
using MGG =
    falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,
                              falcon_core::physics::config::core::Group>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, MGG);
using MCnQ = falcon_core::generic::Map<
    falcon_core::physics::device_structures::Connection,
    falcon_core::math::Quantity>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, MCnQ);
using MIPT = falcon_core::generic::Map<
    falcon_core::instrument_interfaces::names::InstrumentPort,
    falcon_core::instrument_interfaces::port_transforms::PortTransform>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, MIPT);
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::Quantity)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::FArray<int>,
    falcon_core::physics::config::core::Adjacency)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::autotuner_interfaces::interpretations::InterpretationContext)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::autotuner_interfaces::contexts::BaseContext)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::autotuner_interfaces::contexts::BaseContext,
    falcon_core::autotuner_interfaces::contexts::AcquisitionContext)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::autotuner_interfaces::contexts::BaseContext,
    falcon_core::autotuner_interfaces::contexts::MeasurementContext)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::autotuner_interfaces::names::Channel)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::autotuner_interfaces::names::Channels)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::autotuner_interfaces::names::NameBase,
    falcon_core::autotuner_interfaces::names::Gname)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::autotuner_interfaces::names::NameBase)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::communications::messages::BaseMessage)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::generic::FArray<double>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::FArray<double>,
                                     falcon_core::math::arrays::ControlArray)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::discrete_spaces::Discretizer)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>,
    falcon_core::math::domains::CoupledLabelledDomain)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::FArray<double>,
    falcon_core::math::arrays::LabelledMeasuredArray1D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::FArray<double>,
                                     falcon_core::math::arrays::ControlArray1D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::arrays::IncreasingAlignment)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::List<
        falcon_core::math::arrays::LabelledMeasuredArray>,
    falcon_core::math::arrays::LabelledArrays<
        falcon_core::math::arrays::LabelledMeasuredArray>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>,
    falcon_core::math::arrays::LabelledArrays<
        falcon_core::math::arrays::LabelledControlArray>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::List<
        falcon_core::math::arrays::LabelledMeasuredArray1D>,
    falcon_core::math::arrays::LabelledArrays<
        falcon_core::math::arrays::LabelledMeasuredArray1D>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::List<
        falcon_core::math::arrays::LabelledControlArray1D>,
    falcon_core::math::arrays::LabelledArrays<
        falcon_core::math::arrays::LabelledControlArray1D>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::arrays::ControlArray,
    falcon_core::math::arrays::LabelledControlArray)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::FArray<double>,
    falcon_core::math::arrays::LabelledControlArray1D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::arrays::MeasuredArray,
    falcon_core::math::arrays::LabelledMeasuredArray)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::FArray<double>,
                                     falcon_core::math::arrays::MeasuredArray)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::FArray<double>,
                                     falcon_core::math::arrays::MeasuredArray1D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::discrete_spaces::DiscreteSpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::communications::messages::BaseMessage,
    falcon_core::communications::messages::MeasurementRequest)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::communications::messages::BaseMessage,
    falcon_core::communications::messages::MeasurementResponse)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::communications::messages::BaseMessage,
    falcon_core::communications::messages::StandardRequest)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::communications::messages::BaseMessage,
    falcon_core::communications::messages::StandardResponse)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::communications::messages::BaseMessage,
    falcon_core::communications::messages::VoltageStatesResponse)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::communications::Time)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::communications::HDF5Data)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::Quantity,
    falcon_core::communications::voltage_states::DeviceVoltageState)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::List<
        falcon_core::communications::voltage_states::DeviceVoltageState>,
    falcon_core::communications::voltage_states::DeviceVoltageStates)
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
using PSS = falcon_core::generic::Pair<std::string, std::string>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, PSS);
using PSD = falcon_core::generic::Pair<std::string, double>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, PSD);
using PSB = falcon_core::generic::Pair<std::string, bool>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, PSB);
using PDD = falcon_core::generic::Pair<double, double>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, PDD);
using PFF = falcon_core::generic::Pair<float, float>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, PFF);
using PII = falcon_core::generic::Pair<int, int>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, PII);
using PIF = falcon_core::generic::Pair<int, float>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, PIF);
using PCC = falcon_core::generic::Pair<
    falcon_core::autotuner_interfaces::names::Channel,
    falcon_core::physics::device_structures::Connections>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, PCC);
using PCCn = falcon_core::generic::Pair<
    falcon_core::physics::device_structures::Connection,
    falcon_core::physics::device_structures::Connections>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, PCCn);
using PCnCn = falcon_core::generic::Pair<
    falcon_core::physics::device_structures::Connection,
    falcon_core::physics::device_structures::Connection>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, PCnCn);
using PCnQ = falcon_core::generic::Pair<
    falcon_core::physics::device_structures::Connection,
    falcon_core::math::Quantity>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, PCnQ);
using PQQ = falcon_core::generic::Pair<falcon_core::math::Quantity,
                                       falcon_core::math::Quantity>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, PQQ);
using PCnPQQ = falcon_core::generic::Pair<
    falcon_core::physics::device_structures::Connection,
    falcon_core::generic::Pair<falcon_core::math::Quantity,
                               falcon_core::math::Quantity>>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, PCnPQQ);
using PGG =
    falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname,
                               falcon_core::physics::config::core::Group>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, PGG);
using PIPAF = falcon_core::generic::Pair<
    falcon_core::instrument_interfaces::names::InstrumentPort,
    falcon_core::math::AnalyticFunction>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, PIPAF);
using PICQ = falcon_core::generic::Pair<
    falcon_core::autotuner_interfaces::interpretations::InterpretationContext,
    falcon_core::math::Quantity>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, PICQ);
using PIPPT = falcon_core::generic::Pair<
    falcon_core::instrument_interfaces::names::InstrumentPort,
    falcon_core::instrument_interfaces::port_transforms::PortTransform>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, PIPPT);
using PMRMR = falcon_core::generic::Pair<
    falcon_core::communications::messages::MeasurementResponse,
    falcon_core::communications::messages::MeasurementRequest>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, PMRMR);
using PCnF = falcon_core::generic::
    Pair<falcon_core::physics::device_structures::Connection, float>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, PCnF);
using PCnD = falcon_core::generic::
    Pair<falcon_core::physics::device_structures::Connection, double>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, PCnD);
using PICD = falcon_core::generic::Pair<
    falcon_core::autotuner_interfaces::interpretations::InterpretationContext,
    double>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, PICD);
using PICS = falcon_core::generic::Pair<
    falcon_core::autotuner_interfaces::interpretations::InterpretationContext,
    std::string>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, PICS);
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::generic::FArray<int>);
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::generic::FArray<float>);
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::generic::FArray<size_t>);
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::physics::units::SymbolUnit)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::config::core::StandardConfigConnections,
    falcon_core::physics::config::core::Config)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::config::core::StandardConfigConnections,
    falcon_core::physics::config::core::Group)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::config::core::StandardConfigConnections)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::config::core::VoltageConstraints)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::config::geometries::HasLeftNeighbor)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::config::geometries::HasRightNeighbor)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::device_structures::Connection,
    falcon_core::physics::config::geometries::DotGateWithNeighbors)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::config::geometries::HasLeftNeighbor,
    falcon_core::physics::config::geometries::DotGateWithNeighbors)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::config::geometries::HasRightNeighbor,
    falcon_core::physics::config::geometries::DotGateWithNeighbors)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::List<
        falcon_core::physics::config::geometries::DotGateWithNeighbors>,
    falcon_core::physics::config::geometries::DotGatesWithNeighbors)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::config::geometries::GateGeometryArray1D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::config::geometries::HasImplantedOhmic)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::device_structures::Connection,
    falcon_core::physics::config::geometries::LeftReservoirWithImplantedOhmic)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::device_structures::Connection,
    falcon_core::physics::config::geometries::RightReservoirWithImplantedOhmic)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::config::geometries::HasImplantedOhmic,
    falcon_core::physics::config::geometries::RightReservoirWithImplantedOhmic)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::config::geometries::HasLeftNeighbor,
    falcon_core::physics::config::geometries::RightReservoirWithImplantedOhmic)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::List<falcon_core::math::VariableName>,
    falcon_core::math::AnalyticFunction)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::domains::Domain)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::math::domains::Domain,
                                     falcon_core::math::domains::LabelledDomain)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::instrument_interfaces::port_transforms::PortTransforms,
    falcon_core::instrument_interfaces::Waveform)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::generic::List<bool>)
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
using MapP = falcon_core::generic::Map<
    falcon_core::physics::device_structures::Connection,
    falcon_core::math::Quantity>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(MapP, falcon_core::math::Point)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>,
    falcon_core::math::UnitSpace)
using PQQ = falcon_core::generic::Pair<falcon_core::math::Quantity,
                                       falcon_core::math::Quantity>;
using MBD = falcon_core::generic::
    Map<falcon_core::physics::device_structures::Connection, PQQ>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(MBD, falcon_core::math::Vector)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::physics::units::Unit)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::names::InstrumentPort)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::List<
        falcon_core::instrument_interfaces::names::InstrumentPort>,
    falcon_core::instrument_interfaces::names::Ports)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::device_structures::Connection)
using MICD = falcon_core::generic::Map<
    falcon_core::autotuner_interfaces::interpretations::InterpretationContext,
    double>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    MICD,
    falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<
        double>)
using MICS = falcon_core::generic::Map<
    falcon_core::autotuner_interfaces::interpretations::InterpretationContext,
    std::string>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    MICS,
    falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<
        std::string>)
using MICQ = falcon_core::generic::Map<
    falcon_core::autotuner_interfaces::interpretations::InterpretationContext,
    falcon_core::math::Quantity>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    MICQ,
    falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<
        falcon_core::math::Quantity>)
