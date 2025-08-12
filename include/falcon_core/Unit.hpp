#pragma once

#include "Dimension.hpp"
#include <memory>

namespace falcon_core {

class Unit : public Jsonable {
public:
    Unit(double factor, Dimension dimension);

    double get_factor() const;
    const Dimension& get_dimension() const;
    double get_conversion_factor(const Unit& target_unit) const;

    nlohmann::json to_json() const override;
    size_t hash() const override;

    std::shared_ptr<Unit> operator*(const Unit& other) const;
    std::shared_ptr<Unit> operator/(const Unit& other) const;

private:
    double _factor;
    Dimension _dimension;
};

} // namespace falcon_core
