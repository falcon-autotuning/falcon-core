#include "falcon_core/generic/Pair.hpp"

#include "falcon_core/autotuner_interfaces/names/Channel.hpp"
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
