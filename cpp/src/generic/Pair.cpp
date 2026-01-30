#include "falcon_core/generic/Pair.hpp"

#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp"
#include "falcon_core/autotuner_interfaces/names/Channel.hpp"
#include "falcon_core/autotuner_interfaces/names/Gname.hpp"
#include "falcon_core/communications/messages/MeasurementRequest.hpp"
#include "falcon_core/communications/messages/MeasurementResponse.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"
#include "falcon_core/math/AnalyticFunction.hpp"
#include "falcon_core/math/Quantity.hpp"
#include "falcon_core/physics/config/core/Group.hpp"
#include "falcon_core/physics/device_structures/Connections.hpp"

CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<std::string, std::string>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<std::string, double>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<std::string, bool>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<double, double>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<float, float>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<int, int>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<int, float>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<size_t, size_t>);
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
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<falcon_core::math::Quantity,
                                                falcon_core::math::Quantity>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<
                     falcon_core::physics::device_structures::Connection,
                     falcon_core::generic::Pair<falcon_core::math::Quantity,
                                                falcon_core::math::Quantity>>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname,
                               falcon_core::physics::config::core::Group>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<
                     falcon_core::instrument_interfaces::names::InstrumentPort,
                     falcon_core::math::AnalyticFunction>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::Pair<falcon_core::autotuner_interfaces::
                                   interpretations::InterpretationContext,
                               falcon_core::math::Quantity>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::Pair<
        falcon_core::instrument_interfaces::names::InstrumentPort,
        falcon_core::instrument_interfaces::port_transforms::PortTransform>);
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
CEREAL_REGISTER_TYPE(
    falcon_core::generic::Pair<falcon_core::autotuner_interfaces::
                                   interpretations::InterpretationContext,
                               double>);
CEREAL_REGISTER_TYPE(
    falcon_core::generic::Pair<falcon_core::autotuner_interfaces::
                                   interpretations::InterpretationContext,
                               std::string>);

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
//
// Explicit template instantiations exported from the falcon_core library.
// These are the definitions that consumers should import via extern
// templates (see Pair.hpp guarded by FALCON_CORE_USE_EXTERN_TEMPLATES).
//
// The FALCON_CORE_CPP_API macro ensures symbols are exported from the DLL
// when building the library and imported in consumers.
//
template class FALCON_CORE_CPP_API
    falcon_core::generic::Pair<std::string, std::string>;
template class FALCON_CORE_CPP_API
    falcon_core::generic::Pair<std::string, double>;
template class FALCON_CORE_CPP_API
    falcon_core::generic::Pair<std::string, bool>;
template class FALCON_CORE_CPP_API falcon_core::generic::Pair<double, double>;
template class FALCON_CORE_CPP_API falcon_core::generic::Pair<float, float>;
template class FALCON_CORE_CPP_API falcon_core::generic::Pair<int, int>;
template class FALCON_CORE_CPP_API falcon_core::generic::Pair<int, float>;
template class FALCON_CORE_CPP_API falcon_core::generic::Pair<size_t, size_t>;
template class FALCON_CORE_CPP_API falcon_core::generic::Pair<
    falcon_core::autotuner_interfaces::names::Channel,
    falcon_core::physics::device_structures::Connections>;
template class FALCON_CORE_CPP_API falcon_core::generic::Pair<
    falcon_core::physics::device_structures::Connection,
    falcon_core::physics::device_structures::Connections>;
template class FALCON_CORE_CPP_API falcon_core::generic::Pair<
    falcon_core::physics::device_structures::Connection,
    falcon_core::physics::device_structures::Connection>;
template class FALCON_CORE_CPP_API falcon_core::generic::Pair<
    falcon_core::physics::device_structures::Connection,
    falcon_core::math::Quantity>;
template class FALCON_CORE_CPP_API
    falcon_core::generic::Pair<falcon_core::math::Quantity,
                               falcon_core::math::Quantity>;
template class FALCON_CORE_CPP_API falcon_core::generic::Pair<
    falcon_core::physics::device_structures::Connection,
    falcon_core::generic::Pair<falcon_core::math::Quantity,
                               falcon_core::math::Quantity>>;
template class FALCON_CORE_CPP_API
    falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname,
                               falcon_core::physics::config::core::Group>;
template class FALCON_CORE_CPP_API falcon_core::generic::Pair<
    falcon_core::instrument_interfaces::names::InstrumentPort,
    falcon_core::math::AnalyticFunction>;
template class FALCON_CORE_CPP_API falcon_core::generic::Pair<
    falcon_core::autotuner_interfaces::interpretations::InterpretationContext,
    falcon_core::math::Quantity>;
template class FALCON_CORE_CPP_API falcon_core::generic::Pair<
    falcon_core::instrument_interfaces::names::InstrumentPort,
    falcon_core::instrument_interfaces::port_transforms::PortTransform>;
template class FALCON_CORE_CPP_API falcon_core::generic::Pair<
    falcon_core::communications::messages::MeasurementResponse,
    falcon_core::communications::messages::MeasurementRequest>;
template class FALCON_CORE_CPP_API falcon_core::generic::
    Pair<falcon_core::physics::device_structures::Connection, float>;
template class FALCON_CORE_CPP_API falcon_core::generic::
    Pair<falcon_core::physics::device_structures::Connection, double>;
template class FALCON_CORE_CPP_API falcon_core::generic::Pair<
    falcon_core::autotuner_interfaces::interpretations::InterpretationContext,
    double>;
template class FALCON_CORE_CPP_API falcon_core::generic::Pair<
    falcon_core::autotuner_interfaces::interpretations::InterpretationContext,
    std::string>;
