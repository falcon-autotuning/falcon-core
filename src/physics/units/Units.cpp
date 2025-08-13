#include "falcon_core/physics/units/Units.hpp"

#include <map>

namespace falcon_core
{

// Helper functions to create dimensions for common units
static std::map<std::string, int>
voltage_dims ()
{
  return { { "MASS", 1 }, { "LENGTH", 2 }, { "TIME", -3 }, { "CURRENT", -1 } };
}
static std::map<std::string, int>
current_dims ()
{
  return { { "CURRENT", 1 } };
}
static std::map<std::string, int>
time_dims ()
{
  return { { "TIME", 1 } };
}
static std::map<std::string, int>
frequency_dims ()
{
  return { { "TIME", -1 } };
}
static std::map<std::string, int>
dimensionless_dims ()
{
  return {};
}

std::shared_ptr<SymbolUnit>
Units::V ()
{
  auto unit = std::make_shared<Unit> (voltage_dims ());
  return std::make_shared<SymbolUnit> (unit, "V");
}

std::shared_ptr<SymbolUnit>
Units::A ()
{
  auto unit = std::make_shared<Unit> (current_dims ());
  return std::make_shared<SymbolUnit> (unit, "A");
}

std::shared_ptr<SymbolUnit>
Units::s ()
{
  auto unit = std::make_shared<Unit> (time_dims ());
  return std::make_shared<SymbolUnit> (unit, "s");
}

std::shared_ptr<SymbolUnit>
Units::Hz ()
{
  auto unit = std::make_shared<Unit> (frequency_dims ());
  return std::make_shared<SymbolUnit> (unit, "Hz");
}

std::shared_ptr<SymbolUnit>
Units::dimensionless ()
{
  auto unit = std::make_shared<Unit> (dimensionless_dims ());
  return std::make_shared<SymbolUnit> (unit, "");
}

} // namespace falcon_core
