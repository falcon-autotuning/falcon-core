#include "falcon_core/generic/List.hpp"

#include "falcon_core/math/Quantity.hpp"

CEREAL_REGISTER_TYPE(falcon_core::generic::List<int>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<float>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<double>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<size_t>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<std::string>);
CEREAL_REGISTER_TYPE(falcon_core::generic::List<falcon_core::math::Quantity>);

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
