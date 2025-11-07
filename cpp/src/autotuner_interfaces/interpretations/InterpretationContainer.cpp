#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContainer.hpp"

#include "falcon_core/math/Quantity.hpp"
CEREAL_REGISTER_TYPE(
    falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<
        double>)
CEREAL_REGISTER_TYPE(
    falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<
        std::string>)
CEREAL_REGISTER_TYPE(
    falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<
        falcon_core::math::Quantity>)
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
