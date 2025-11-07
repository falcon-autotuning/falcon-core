#include "falcon_core/generic/Map.hpp"

CEREAL_REGISTER_TYPE(falcon_core::generic::Map<int, int>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Map<float, float>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Map<std::string, bool>);

using MII = falcon_core::generic::Map<int, int>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, MII);
using MFF = falcon_core::generic::Map<float, float>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, MFF);
using MSB = falcon_core::generic::Map<std::string, bool>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, MSB);
