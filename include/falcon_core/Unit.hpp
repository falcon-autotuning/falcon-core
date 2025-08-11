#pragma once

#include "falcon_core/Dimension.hpp"
#include "falcon_core/Jsonable.hpp"
#include <string>
#include <memory>

namespace falcon_core {

class Unit : public Jsonable {
public:
    Unit(double scale, Dimension dimension);
    
    const Dimension& dimension() const;
    double scale() const;

    bool is_compatible(const Unit& other) const;
    double get_conversion_factor(const Unit& target_unit) const;
    double convert_value_to(double value, const Unit& target_unit) const;

    std::shared_ptr<Unit> operator*(const Unit& other) const;
    std::shared_ptr<Unit> operator/(const Unit& other) const;

    std::shared_ptr<Unit> with_prefix(const std::string& prefix_symbol) const;

    // Jsonable interface
    nlohmann::json to_json() const override;
    size_t hash() const override;

private:
    double _scale;
    Dimension _dimension;
};

} // namespace falcon_core
