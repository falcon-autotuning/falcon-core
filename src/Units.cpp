#include "falcon_core/Units.hpp"
#include "falcon_core/Unit.hpp"
#include "falcon_core/Dimension.hpp"
#include <map>

namespace falcon_core {

// Helper functions to create dimensions for common units
static std::map<std::string, int> voltage_dims() { return {{"MASS", 1}, {"LENGTH", 2}, {"TIME", -3}, {"CURRENT", -1}}; }
static std::map<std::string, int> current_dims() { return {{"CURRENT", 1}}; }
static std::map<std::string, int> time_dims() { return {{"TIME", 1}}; }
static std::map<std::string, int> frequency_dims() { return {{"TIME", -1}}; }
static std::map<std::string, int> dimensionless_dims() { return {}; }

std::shared_ptr<SymbolUnit> Units::V() {
    auto unit = std::make_shared<Unit>(1.0, voltage_dims());
    return std::make_shared<SymbolUnit>(unit, "V");
}

std::shared_ptr<SymbolUnit> Units::A() {
    auto unit = std::make_shared<Unit>(1.0, current_dims());
    return std::make_shared<SymbolUnit>(unit, "A");
}

std::shared_ptr<SymbolUnit> Units::s() {
    auto unit = std::make_shared<Unit>(1.0, time_dims());
    return std::make_shared<SymbolUnit>(unit, "s");
}

std::shared_ptr<SymbolUnit> Units::Hz() {
    auto unit = std::make_shared<Unit>(1.0, frequency_dims());
    return std::make_shared<SymbolUnit>(unit, "Hz");
}

std::shared_ptr<SymbolUnit> Units::dimensionless() {
    auto unit = std::make_shared<Unit>(1.0, dimensionless_dims());
    return std::make_shared<SymbolUnit>(unit, "");
}

} // namespace falcon_core
