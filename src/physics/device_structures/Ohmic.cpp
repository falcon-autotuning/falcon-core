#include "falcon_core/physics/device_structures/Ohmic.hpp"

#include "falcon_core/physics/device_structures/BaseConnection.hpp"
using namespace falcon_core::physics::device_structures;

Ohmic::Ohmic(std::string name) : BaseConnection(std::move(name)) {}
Ohmic::Ohmic() = default;

template <class Archive>
void Ohmic::serialize(Archive &ar) {
  ar(cereal::base_class<BaseConnection>(this));
}

// Explicit instantiation for cereal
template void Ohmic::serialize<cereal::JSONOutputArchive>(
    cereal::JSONOutputArchive &);
template void Ohmic::serialize<cereal::JSONInputArchive>(
    cereal::JSONInputArchive &);

CEREAL_REGISTER_TYPE(Ohmic)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseConnection, Ohmic)
