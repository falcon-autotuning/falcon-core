#include "falcon_core/physics/device_structures/Impedance.hpp"

using namespace falcon_core::physics::device_structures;

Impedance::Impedance(std::shared_ptr<BaseConnection> connection,
                     double                          resistance,
                     double                          capacitance)
    : _connection(std::move(connection)),
      _resistance(resistance),
      _capacitance(capacitance) {}

Impedance::Impedance() = default;
BaseConnectionSP Impedance::connection() const { return _connection; }
double           Impedance::resistance() const { return _resistance; }
double           Impedance::capacitance() const { return _capacitance; }
template <class Archive>
void Impedance::serialize(Archive& ar) {
  ar(cereal::base_class<generic::Song>(this),
     _connection,
     _resistance,
     _capacitance);
}

CEREAL_REGISTER_TYPE(Impedance)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, Impedance)
