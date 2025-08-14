#include "falcon_core/physics/device_structures/Impedances.hpp"

using namespace falcon_core;
using namespace falcon_core::physics::device_structures;
CEREAL_REGISTER_TYPE(Impedances<Impedance>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(generic::Song, Impedances<Impedance>)
