#include "falcon_core/generic/Pair.hpp"

CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<std::string, std::string>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<std::string, double>);
CEREAL_REGISTER_TYPE(falcon_core::generic::Pair<std::string, bool>);

using PSS = falcon_core::generic::Pair<std::string, std::string>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, PSS);
using PSD = falcon_core::generic::Pair<std::string, double>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, PSD);
using PSB = falcon_core::generic::Pair<std::string, bool>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, PSB);
