#include "falcon_core/physics/units/SymbolUnit.hpp"

#include "falcon_core/constants.hpp"
#include "falcon_core/physics/units/Unit.hpp"

#include <functional>
#include <memory>

namespace falcon_core
{
namespace physics
{
namespace units
{

physics::units::SymbolUnit::SymbolUnit (std::shared_ptr<Unit> unit,
                                        std::string           symbol)
    : _unit (std::move (unit)), _symbol (std::move (symbol))
{
}

const std::shared_ptr<Unit> &
physics::units::SymbolUnit::unit () const
{
  return _unit;
}

std::string
physics::units::SymbolUnit::symbol () const
{
  return _symbol;
}

nlohmann::json
physics::units::SymbolUnit::to_json () const
{
  nlohmann::json j;
  add_metadata (j, "falcon_core.physics.units.symbol_unit", "SymbolUnit");
  j["_unit"]   = _unit->to_json ();
  j["_symbol"] = _symbol;
  return j;
}

size_t
physics::units::SymbolUnit::hash () const
{
  size_t h1 = _unit ? _unit->hash () : 0;
  size_t h2 = std::hash<std::string>{}(_symbol);
  return h1 ^ (h2 << 1);
}

}
}
} // namespace falcon_core
