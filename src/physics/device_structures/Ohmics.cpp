#include "falcon_core/physics/device_structures/Ohmics.hpp"
using namespace falcon_core::physics::device_structures;

Ohmics::Ohmics() = default;

Ohmics::Ohmics(size_t count) : BaseConnections<Ohmic, Ohmics>(count) {}

Ohmics::Ohmics(size_t count, const OhmicSP& value)
    : BaseConnections<Ohmic, Ohmics>(count, value) {}

Ohmics::Ohmics(const std::vector<OhmicSP>& vec)
    : BaseConnections<Ohmic, Ohmics>(vec) {}

// Explicit template instantiation for serialize
template <class Archive>
void Ohmics::serialize(Archive& ar) {
  ar(cereal::base_class<BaseConnections<Ohmic, Ohmics>>(this));
}

CEREAL_REGISTER_TYPE(Ohmics)
using GOO = BaseConnections<Ohmic, Ohmics>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(GOO, Ohmics)
