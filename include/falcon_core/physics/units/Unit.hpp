#pragma once

#include "falcon_core/Constants.hpp"
#include "falcon_core/generic/Jsonable.hpp"
#include "falcon_core/physics/units/TotalDimensions.hpp"

#include <memory>
#include <nlohmann/json.hpp>

namespace falcon_core
{

class Unit : public Jsonable
{
public:
  Unit (TotalDimensions dimensions,
        double          scale_factor = 1.0,
        double          offset       = 0.0,
        std::string     prefix       = SI::UNIT_SYMBOL);

  /**
   * @brief The prefix applied to this unit.
   */
  std::string
  prefix () const
  {
    return this->_prefix;
  }
  /**
   * @brief Dimensions of this unit.
   */
  TotalDimensions
  dimensions () const
  {
    return this->_dimensions;
  }
  /**
   * @brief Scale factor relatice to SI base units.
   */
  double
  scale_factor () const
  {
    return this->_scale_factor;
  }
  /**
   * @brief Offset from base unit.
   */
  double
  offset () const
  {
    return this->_offset;
  }

  nlohmann::json
  to_json () const override
  {
    nlohmann::json j;
    j["dimensions"]   = _dimensions;   // Serialize the dimensions
    j["scale_factor"] = _scale_factor; // Serialize the scale factor
    j["offset"]       = _offset;       // Serialize the offset
    j["prefix"]       = _prefix;       // Serialize the prefix
    return j;
  }

  size_t
  hash () const override
  {
    // Implement your hashing function here
    return std::hash<std::string> () (
        this->to_json ().dump ()); // Example implementation
  }

  /*
   * @brief Multiply this unit by another unit.
   * @param other The unit to multiply by.
   * @return A new Unit representing the product of this unit and the other.
   */
  std::shared_ptr<Unit> operator* (const Unit &other) const;
  /*
   * @brief Divide this unit by another unit.
   * @param other The unit to divide by.
   * @return A new Unit representing the division of this unit by the other.
   */
  std::shared_ptr<Unit> operator/ (const Unit &other) const;
  /*
   * @brief Raise the unit to a power.
   * @param power The exponent to raise the unit to.
   * @return A new Unit raised to the specified power.
   */
  std::shared_ptr<Unit> operator^ (const int power) const;
  /*
   * @brief Apply a prefix to this unit.
   * @param prefix The prefix symbol to apply (e.g. "k" for kilo
   * @return A new Unit with the specified prefix applied.
   * @throws std::invalid_argument if the prefix is not valid.
   */
  std::shared_ptr<Unit> with_prefix (const std::string prefix) const;
  /*
   * @brief Convert a value from this unit to a target unit.
   * @param value The value in this unit to convert.
   * @param target_unit The unit to convert the value to.
   * @return The converted value in the target unit.
   * @throws std::invalid_argument if the units are not compatible.
   */
  double convert_value_to (const double value, const Unit target_unit) const;
  /*
   * @brief Check if this unit is compatible with another unit.
   * @param other The unit to check compatibility with.
   * @return True if the units are compatible (same dimensions), false
   * otherwise.
   */
  bool is_compatible_with (const Unit other) const;

private:
  double          _scale_factor; // Scale factor relative to SI base units
  double          _offset;       // Offset form base unit (e.g. for Celsius)
  std::string     _prefix;       // The SI prefix symbol (e.g. "k" for kilo)
  TotalDimensions _dimensions; // dictionary mapping dimensions to their powers
};
};
