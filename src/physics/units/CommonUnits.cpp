#include "falcon_core/physics/units/CommonUnits.hpp"

using namespace falcon_core::physics::units;
using namespace falcon_core;
std::shared_ptr<Unit>
get_unit_with_prefix (const Unit &unit, const std::string prefix)
{
  return unit.with_prefix (prefix);
}
std::shared_ptr<Unit>
get_milli (const Unit &unit)
{
  return unit.with_prefix (SI::MILLI_SYMBOL);
}
std::shared_ptr<Unit>
get_micro (const Unit &unit)
{
  return unit.with_prefix (SI::MICRO_SYMBOL);
}
std::shared_ptr<Unit>
get_nano (const Unit &unit)
{
  return unit.with_prefix (SI::NANO_SYMBOL);
}
std::shared_ptr<Unit>
get_pico (const Unit &unit)
{
  return unit.with_prefix (SI::PICO_SYMBOL);
}
std::shared_ptr<Unit>
get_kilo (const Unit &unit)
{
  return unit.with_prefix (SI::KILO_SYMBOL);
}
std::shared_ptr<Unit>
get_mega (const Unit &unit)
{
  return unit.with_prefix (SI::MEGA_SYMBOL);
}
std::shared_ptr<Unit>
get_giga (const Unit &unit)
{
  return unit.with_prefix (SI::GIGA_SYMBOL);
}
