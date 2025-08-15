#include "falcon_core/physics/units/CommonUnits.hpp"

namespace falcon_core {
namespace physics {
namespace units {
namespace common_units {
using Unit = falcon_core::physics::units::Unit;
std::shared_ptr<Unit> get_unit_with_prefix(Unit unit, std::string prefix) {
  return unit.with_prefix(prefix);
}
std::shared_ptr<Unit> get_milli(Unit unit) {
  return unit.with_prefix(SI::MILLI_SYMBOL);
}
std::shared_ptr<Unit> get_micro(Unit unit) {
  return unit.with_prefix(SI::MICRO_SYMBOL);
}
std::shared_ptr<Unit> get_nano(Unit unit) {
  return unit.with_prefix(SI::NANO_SYMBOL);
}
std::shared_ptr<Unit> get_pico(Unit unit) {
  return unit.with_prefix(SI::PICO_SYMBOL);
}
std::shared_ptr<Unit> get_kilo(Unit unit) {
  return unit.with_prefix(SI::KILO_SYMBOL);
}
std::shared_ptr<Unit> get_mega(Unit unit) {
  return unit.with_prefix(SI::MEGA_SYMBOL);
}
std::shared_ptr<Unit> get_giga(Unit unit) {
  return unit.with_prefix(SI::GIGA_SYMBOL);
}
}  // namespace common_units
}  // namespace units
}  // namespace physics
}  // namespace falcon_core
