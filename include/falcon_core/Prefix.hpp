#pragma once

#include <string>
#include <map>
#include <stdexcept>

namespace falcon_core {

class Prefix {
public:
    static double get_value(const std::string& symbol);
    static std::string get_symbol(double value);
private:
    static const std::map<std::string, double> symbol_to_value;
    static const std::map<int, std::string> power_to_symbol;
};

} // namespace falcon_core
