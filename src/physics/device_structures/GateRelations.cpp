#include "falcon_core/physics/device_structures/GateRelations.hpp"

using namespace falcon_core::physics::device_structures;
using MapGR                    = falcon_core::generic::Map<Gate, Gates<Gate>>;
GateRelations::GateRelations() = default;
GateRelations::GateRelations(
    std::initializer_list<std::pair<GateSP, GatesSP>> init)
    : generic::Map<Gate, Gates<Gate>, GateRelations>(init) {};
template <class Archive>
void GateRelations::serialize(Archive& ar) {
  ar(cereal::base_class<Map<Gate, Gates<Gate>, GateRelations>>(this));
}
CEREAL_REGISTER_TYPE(MapGR)
CEREAL_REGISTER_TYPE(GateRelations)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, MapGR)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, GateRelations)
