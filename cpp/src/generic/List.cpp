#include "falcon_core/generic/List.hpp"

#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext.hpp"
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp"
#include "falcon_core/autotuner_interfaces/names/Channel.hpp"
#include "falcon_core/autotuner_interfaces/names/Gname.hpp"
#include "falcon_core/generic/FArray.hpp"
#include "falcon_core/generic/Pair.hpp"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"
#include "falcon_core/math/Quantity.hpp"
#include "falcon_core/math/arrays/LabelledControlArray.hpp"
#include "falcon_core/math/arrays/LabelledControlArray1D.hpp"
#include "falcon_core/math/arrays/LabelledMeasuredArray.hpp"
#include "falcon_core/math/arrays/LabelledMeasuredArray1D.hpp"
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
using LPSB =
    falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LPSB);
using LPSD =
    falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LPSD);
using LPSS = falcon_core::generic::List<
    falcon_core::generic::Pair<std::string, std::string>>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LPSS);
using LPSTST =
    falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LPSTST);
using LPQQ = falcon_core::generic::List<
    falcon_core::generic::Pair<falcon_core::math::Quantity,
                               falcon_core::math::Quantity>>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LPQQ);
using LPII = falcon_core::generic::List<falcon_core::generic::Pair<int, int>>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LPII);
using LPIF = falcon_core::generic::List<falcon_core::generic::Pair<int, float>>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LPIF);
using LPFF =
    falcon_core::generic::List<falcon_core::generic::Pair<float, float>>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LPFF);
using LPCC = falcon_core::generic::List<falcon_core::generic::Pair<
    falcon_core::autotuner_interfaces::names::Gname,
    falcon_core::physics::device_structures::Connections>>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LPCC);
using LPChC = falcon_core::generic::List<falcon_core::generic::Pair<
    falcon_core::autotuner_interfaces::names::Channel,
    falcon_core::physics::device_structures::Connections>>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LPChC);
using LPCoCo = falcon_core::generic::List<falcon_core::generic::Pair<
    falcon_core::physics::device_structures::Connection,
    falcon_core::physics::device_structures::Connections>>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LPCoCo);
using LPGG = falcon_core::generic::List<
    falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname,
                               falcon_core::physics::config::core::Group>>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LPGG);
using LPCD = falcon_core::generic::List<falcon_core::generic::Pair<
    falcon_core::physics::device_structures::Connection,
    double>>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LPCD);
using LPCQ = falcon_core::generic::List<falcon_core::generic::Pair<
    falcon_core::physics::device_structures::Connection,
    falcon_core::math::Quantity>>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LPCQ);
using LPCF = falcon_core::generic::List<falcon_core::generic::Pair<
    falcon_core::physics::device_structures::Connection,
    float>>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LPCF);
using LPIPT = falcon_core::generic::List<falcon_core::generic::Pair<
    falcon_core::instrument_interfaces::names::InstrumentPort,
    falcon_core::instrument_interfaces::port_transforms::PortTransform>>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LPIPT);
using LPIIC = falcon_core::generic::List<falcon_core::generic::Pair<
    falcon_core::autotuner_interfaces::interpretations::InterpretationContext,
    double>>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LPIIC);
using LPICQ = falcon_core::generic::List<falcon_core::generic::Pair<
    falcon_core::autotuner_interfaces::interpretations::InterpretationContext,
    falcon_core::math::Quantity>>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LPICQ);
using LPICS = falcon_core::generic::List<falcon_core::generic::Pair<
    falcon_core::autotuner_interfaces::interpretations::InterpretationContext,
    std::string>>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LPICS);
using LPCPQQ = falcon_core::generic::List<falcon_core::generic::Pair<
    falcon_core::physics::device_structures::Connection,
    falcon_core::generic::Pair<falcon_core::math::Quantity,
                               falcon_core::math::Quantity>>>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LPCPQQ);
using LMSB =
    falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LMSB);
using LLST = falcon_core::generic::List<falcon_core::generic::List<size_t>>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LLST);
using LMC = falcon_core::generic::List<
    falcon_core::autotuner_interfaces::contexts::MeasurementContext>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LMC);
using LMA = falcon_core::generic::List<
    falcon_core::math::arrays::LabelledMeasuredArray>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LMA);
using LMA1D = falcon_core::generic::List<
    falcon_core::math::arrays::LabelledMeasuredArray1D>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LMA1D);
using LCA =
    falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LCA);
using LCA1D = falcon_core::generic::List<
    falcon_core::math::arrays::LabelledControlArray1D>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LCA1D);
using LLD =
    falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LLD);
using LIC = falcon_core::generic::List<
    falcon_core::autotuner_interfaces::interpretations::InterpretationContext>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LIC);
using LIP = falcon_core::generic::List<
    falcon_core::instrument_interfaces::names::InstrumentPort>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LIP);
using LImpedance = falcon_core::generic::List<
    falcon_core::physics::device_structures::Impedance>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LImpedance);
using LGroup =
    falcon_core::generic::List<falcon_core::physics::config::core::Group>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, LGroup);
