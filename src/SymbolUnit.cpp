#include "falcon_core/SymbolUnit.hpp"
#include "falcon_core/Prefix.hpp"

namespace falcon_core {

SymbolUnit::SymbolUnit(std::shared_ptr<Unit> unit, std::string symbol)
    : _unit(std::move(unit)), _symbol(std::move(symbol)) {}

const std::string& SymbolUnit::symbol() const { return _symbol; }
const std::shared_ptr<Unit>& SymbolUnit::unit() const { return _unit; }

bool SymbolUnit::is_compatible(const SymbolUnit& other) const {
    return _unit->is_compatible(*other._unit);
}

double SymbolUnit::get_conversion_factor(const SymbolUnit& target_unit) const {
    return _unit->get_conversion_factor(*target_unit._unit);
}

double SymbolUnit::convert_value_to(double value, const SymbolUnit& target_unit) const {
    return _unit->convert_value_to(value, *target_unit._unit);
}

std::shared_ptr<SymbolUnit> SymbolUnit::with_prefix(const std::string& prefix_symbol) const {
    auto new_unit = _unit->with_prefix(prefix_symbol);
    auto new_symbol = prefix_symbol + _symbol;
    return std::make_shared<SymbolUnit>(new_unit, new_symbol);
}

nlohmann::json SymbolUnit::to_json() const {
    nlohmann::json j;
    j["symbol"] = _symbol;
    j["unit"] = _unit->to_json();
    add_metadata(j, "falcon_core.physics.units.symbol_unit", "SymbolUnit");
    return j;
}

size_t SymbolUnit::hash() const {
    return std::hash<std::string>{}(_symbol) ^ (_unit->hash() << 1);
}

} // namespace falcon_core
