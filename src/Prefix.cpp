#include "falcon_core/Prefix.hpp"
#include "falcon_core/constants.hpp"

namespace falcon_core {

Prefix::Prefix(const std::string& symbol, double factor) : _symbol(symbol), _factor(factor) {}

std::string Prefix::symbol() const {
    return _symbol;
}

double Prefix::factor() const {
    return _factor;
}

nlohmann::json Prefix::to_json() const {
    nlohmann::json j;
    j["symbol"] = _symbol;
    j["factor"] = _factor;
    add_metadata(j, "falcon_core", "Prefix");
    return j;
}

size_t Prefix::hash() const {
    return std::hash<std::string>{}(_symbol) ^ std::hash<double>{}(_factor);
}

} // namespace falcon_core
