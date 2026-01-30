#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContainer.hpp"
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp"
#include "falcon_core/autotuner_interfaces/names/Channel.hpp"
#include "falcon_core/autotuner_interfaces/names/Gname.hpp"
#include "falcon_core/export.h"
#include "falcon_core/generic/Map.hpp"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"
#include "falcon_core/math/Quantity.hpp"
#include "falcon_core/physics/config/core/Adjacency.hpp"
#include "falcon_core/physics/config/core/Group.hpp"
#include "falcon_core/physics/device_structures/Connections.hpp"
CEREAL_REGISTER_TYPE(falcon_core::physics::config::core::Adjacency)
CEREAL_REGISTER_TYPE(falcon_core::math::Quantity)
CEREAL_REGISTER_TYPE(falcon_core::generic::FArray<int>)
CEREAL_REGISTER_TYPE(
    falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<
        double>)
CEREAL_REGISTER_TYPE(
    falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<
        std::string>)
CEREAL_REGISTER_TYPE(
    falcon_core::autotuner_interfaces::interpretations::InterpretationContext)
CEREAL_REGISTER_TYPE(
    falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<
        falcon_core::math::Quantity>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::Quantity)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<
        double>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<
        std::string>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<
        falcon_core::math::Quantity>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::FArray<int>,
    falcon_core::physics::config::core::Adjacency)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::autotuner_interfaces::interpretations::InterpretationContext)
CEREAL_REGISTER_TYPE(falcon_core::generic::Map<int, int>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Map<float, float>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Map<std::string, bool>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Map<std::string, double>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Map<std::string, std::string>);
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
    falcon_core::generic::Map<
        falcon_core::instrument_interfaces::names::InstrumentPort,
        falcon_core::instrument_interfaces::port_transforms::PortTransform>);

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
