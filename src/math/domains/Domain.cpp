#include "falcon_core/math/domains/Domain.hpp"

using namespace falcon_core;
using namespace falcon_core::math::domains;

CEREAL_REGISTER_TYPE(Domain)
CEREAL_REGISTER_POLYMORPHIC_RELATION(generic::Song, Domain)

#include <functional>

#include "falcon_core/constants.hpp"
using namespace falcon_core::math::domains;
