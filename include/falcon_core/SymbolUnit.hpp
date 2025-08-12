#pragma once

#include "Prefix.hpp"
#include "Unit.hpp"
#include <string>
// #include <memory>

namespace falcon_core {

class SymbolUnit : public Jsonable {
public:
  SymbolUnit(std::shared_ptr<Unit> unit, std::string symbol);

  std::string symbol() const;
  const std::shared_ptr<Unit> &unit() const;

  // SymbolUnit with_prefix(const std::string& prefix_symbol) const;

  nlohmann::json to_json() const override;
  size_t hash() const override;

private:
  std::shared_ptr<Unit> _unit;
  std::string _symbol;
};

} // namespace falcon_core
