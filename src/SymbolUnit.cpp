#include "falcon_core/SymbolUnit.hpp"
#include "falcon_core/constants.hpp"
// #include <map>
#include <memory>

namespace falcon_core {

// A simple prefix map for demonstration
<<<<<<< HEAD
static const std::map<std::string, double> prefix_map = {
    {"k", 1e3}, {"M", 1e6}, {"G", 1e9}, {"m", 1e-3}, {"u", 1e-6}, {"n", 1e-9}};
=======
// static const std::map<std::string, double> prefix_map = {
//     {"k", 1e3}, {"M", 1e6}, {"G", 1e9},
//     {"m", 1e-3}, {"u", 1e-6}, {"n", 1e-9}
// };
>>>>>>> a0c46a44b586bc31633613c401acb75a9215aa05

// SymbolUnit::SymbolUnit(std::shared_ptr<Unit> unit, std::string symbol)
//     : _unit(std::move(unit)), _symbol(std::move(symbol)) {}

std::string SymbolUnit::symbol() const { return _symbol; }

<<<<<<< HEAD
const std::shared_ptr<Unit> &SymbolUnit::unit() const { return _unit; }

SymbolUnit SymbolUnit::with_prefix(const std::string &prefix_symbol) const {
  auto it = prefix_map.find(prefix_symbol);
  if (it == prefix_map.end()) {
    throw std::runtime_error("Unknown prefix: " + prefix_symbol);
  }
  auto new_unit = std::make_shared<Unit>(_unit->get_factor() * it->second,
                                         _unit->dimensions());
  return SymbolUnit(new_unit, prefix_symbol + _symbol);
}

nlohmann::json SymbolUnit::to_json() const {
  nlohmann::json j;
  j["symbol"] = _symbol;
  j["unit"] = _unit->to_json();
  add_metadata(j, "falcon_core", "SymbolUnit");
  return j;
}

size_t SymbolUnit::hash() const {
  return std::hash<std::string>{}(_symbol) ^ _unit->hash();
=======
// const std::shared_ptr<Unit>& SymbolUnit::unit() const {
//     return _unit;
// }

// SymbolUnit SymbolUnit::with_prefix(const std::string& prefix_symbol) const {
//     auto it = prefix_map.find(prefix_symbol);
//     if (it == prefix_map.end()) {
//         throw std::runtime_error("Unknown prefix: " + prefix_symbol);
//     }
//     auto new_unit = std::make_shared<Unit>(_unit->get_factor() * it->second, _unit->get_dimension());
//     return SymbolUnit(new_unit, prefix_symbol + _symbol);
// }

nlohmann::json SymbolUnit::to_json() const {
    nlohmann::json j;
    j["symbol"] = _symbol;
    // j["unit"] = _unit->to_json();
    add_metadata(j, "falcon_core", "SymbolUnit");
    return j;
}

size_t SymbolUnit::hash() const {
    return std::hash<std::string>{}(_symbol); // ^ _unit->hash();
>>>>>>> a0c46a44b586bc31633613c401acb75a9215aa05
}

} // namespace falcon_core
