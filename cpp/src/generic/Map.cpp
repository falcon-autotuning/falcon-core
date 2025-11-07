#include "falcon_core/generic/Map.hpp"

#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp"
#include "falcon_core/math/Quantity.hpp"

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
                              double>)
CEREAL_REGISTER_TYPE(falcon_core::generic::Map<
                     falcon_core::physics::device_structures::Connection,
                     float>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Map<
                     falcon_core::physics::device_structures::Connection,
                     double>);

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
