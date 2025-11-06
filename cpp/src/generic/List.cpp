#include "falcon_core/generic/List.hpp"

#include "falcon_core/autotuner_interfaces/names/Gname.hpp"
#include "falcon_core/generic/FArray.hpp"
#include "falcon_core/generic/Pair.hpp"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"
#include "falcon_core/math/Quantity.hpp"

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
