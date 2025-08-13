#pragma once

#include "falcon_core/generic/Jsonable.hpp"
#include "falcon_core/physics/units/Prefix.hpp"
#include "falcon_core/physics/units/Unit.hpp"

#include <memory>
#include <string>
// #include <memory>

namespace falcon_core
{
namespace physics
{
namespace units
{

class SymbolUnit : public Jsonable
{
public:
  SymbolUnit (std::shared_ptr<Unit> unit, std::string symbol);

  std::string                  symbol () const;
  const std::shared_ptr<Unit> &unit () const;

  // SymbolUnit with_prefix(const std::string& prefix_symbol) const;

  nlohmann::json to_json () const override;
  size_t         hash () const override;

private:
  std::shared_ptr<Unit> _unit;
  std::string           _symbol;
};

}
}
} // namespace falcon_core
