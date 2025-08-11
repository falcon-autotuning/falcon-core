#pragma once

#include "falcon_core/Unit.hpp"
#include "falcon_core/Jsonable.hpp"
#include <string>
#include <memory>

namespace falcon_core {

class SymbolUnit : public Jsonable {
public:
    SymbolUnit(std::shared_ptr<Unit> unit, std::string symbol);

    const std::string& symbol() const;
    const std::shared_ptr<Unit>& unit() const;
    
    bool is_compatible(const SymbolUnit& other) const;
    double get_conversion_factor(const SymbolUnit& target_unit) const;
    double convert_value_to(double value, const SymbolUnit& target_unit) const;

    std::shared_ptr<SymbolUnit> with_prefix(const std::string& prefix_symbol) const;

    // Jsonable interface
    nlohmann::json to_json() const override;
    size_t hash() const override;

private:
    std::shared_ptr<Unit> _unit;
    std::string _symbol;
};
} // namespace falcon_core
