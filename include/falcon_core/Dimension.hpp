#pragma once

#include <map>
#include <string>
#include <vector>

namespace falcon_core {

// The base dimensions of the SI system, plus Angle.
enum class BaseDimension {
    LENGTH,
    MASS,
    TIME,
    CURRENT,
    TEMPERATURE,
    LUMINOUS_INTENSITY,
    AMOUNT_OF_SUBSTANCE,
    ANGLE
};

class Dimension {
public:
    Dimension(std::map<BaseDimension, int> dims = {});

    bool is_dimensionless() const;
    bool is_compatible(const Dimension& other) const;

    Dimension operator*(const Dimension& other) const;
    Dimension operator/(const Dimension& other) const;
    Dimension pow(int power) const;

    bool operator==(const Dimension& other) const;
    const std::map<BaseDimension, int>& get_dims() const;
    size_t hash() const;

private:
    std::map<BaseDimension, int> _dims;
};

} // namespace falcon_core
