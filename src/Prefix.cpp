#include "falcon_core/Prefix.hpp"
#include <cmath>

namespace falcon_core {

const std::map<std::string, double> Prefix::symbol_to_value = {
    {"Y", 1e24}, {"Z", 1e21}, {"E", 1e18}, {"P", 1e15}, {"T", 1e12},
    {"G", 1e9},  {"M", 1e6},  {"k", 1e3},  {"h", 1e2},  {"da", 1e1},
    {"d", 1e-1}, {"c", 1e-2}, {"m", 1e-3}, {"u", 1e-6}, {"n", 1e-9},
    {"p", 1e-12},{"f", 1e-15},{"a", 1e-18},{"z", 1e-21},{"y", 1e-24}
};

const std::map<int, std::string> Prefix::power_to_symbol = {
    {24, "Y"}, {21, "Z"}, {18, "E"}, {15, "P"}, {12, "T"},
    {9, "G"},  {6, "M"},  {3, "k"},  {2, "h"},  {1, "da"},
    {-1, "d"}, {-2, "c"}, {-3, "m"}, {-6, "u"}, {-9, "n"},
    {-12, "p"},{-15, "f"},{-18, "a"},{-21, "z"},{-24, "y"}
};

double Prefix::get_value(const std::string& symbol) {
    auto it = symbol_to_value.find(symbol);
    if (it == symbol_to_value.end()) {
        throw std::runtime_error("Unknown prefix symbol: " + symbol);
    }
    return it->second;
}

std::string Prefix::get_symbol(double value) {
    int power = static_cast<int>(std::round(std::log10(value)));
    auto it = power_to_symbol.find(power);
    if (it == power_to_symbol.end()) {
        throw std::runtime_error("No standard prefix for value: " + std::to_string(value));
    }
    return it->second;
}

} // namespace falcon_core
