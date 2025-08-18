#include "falcon_core/math/domains/Domain.hpp"
#include <cereal/types/polymorphic.hpp>
#include "falcon_core/generic/Song.hpp"

CEREAL_REGISTER_TYPE(falcon_core::math::domains::Domain)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, falcon_core::math::domains::Domain)

#include <functional>

#include "falcon_core/constants.hpp"
using namespace falcon_core::math::domains;
