#pragma once

#include <memory>

#include "falcon-core/Constants.hpp"
#include "falcon-core/export.h"
#include "falcon-core/generic/Song.hpp"
#include "falcon-core/physics/units/TotalDimensions.hpp"

namespace falcon_core {
namespace physics {
namespace units {

class FALCON_CORE_CPP_API Unit : public generic::Song {
  double          _scale_factor;  // Scale factor relative to SI base units
  double          _offset;        // Offset form base unit (e.g. for Celsius)
  std::string     _prefix;        // The SI prefix symbol (e.g. "k" for kilo)
  TotalDimensions _dimensions;  // dictionary mapping dimensions to their powers
 public:
  Unit(TotalDimensions dimensions,
       double          scale_factor = 1.0,
       double          offset       = 0.0,
       std::string     prefix       = SI::UNIT_SYMBOL);
  /**
   * @brief A special constructor to build a meter unit.
   */
  static std::shared_ptr<Unit> Meter();
  /**
   * @brief A special constructor to build a kilogram unit.
   */
  static std::shared_ptr<Unit> Kilogram();
  /**
   * @brief A special constructor to build a second unit.
   */
  static std::shared_ptr<Unit> Second();
  /**
   * @brief A special constructor to build a ampere unit.
   */
  static std::shared_ptr<Unit> Ampere();
  /**
   * @brief A special constructor to build a kelvin unit.
   */
  static std::shared_ptr<Unit> Kelvin();
  /**
   * @brief A special constructor to build a mole unit.
   */
  static std::shared_ptr<Unit> Mole();
  /**
   * @brief A special constructor to build a candela unit.
   */
  static std::shared_ptr<Unit> Candela();
  /**
   * @brief A special constructor to build a hertz unit.
   */
  static std::shared_ptr<Unit> Hertz();
  /**
   * @brief A special constructor to build a newton unit.
   */
  static std::shared_ptr<Unit> Newton();
  /**
   * @brief A special constructor to build a pascal unit.
   */
  static std::shared_ptr<Unit> Pascal();
  /**
   * @brief A special constructor to build a joule unit.
   */
  static std::shared_ptr<Unit> Joule();
  /**
   * @brief A special constructor to build a watt unit.
   */
  static std::shared_ptr<Unit> Watt();
  /**
   * @brief A special constructor to build a coulomb unit.
   */
  static std::shared_ptr<Unit> Coulomb();
  /**
   * @brief A special constructor to build a volt unit.
   */
  static std::shared_ptr<Unit> Volt();
  /**
   * @brief A special constructor to build a farad unit.
   */
  static std::shared_ptr<Unit> Farad();
  /**
   * @brief A special constructor to build a ohm unit.
   */
  static std::shared_ptr<Unit> Ohm();
  /**
   * @brief A special constructor to build a seimen unit.
   */
  static std::shared_ptr<Unit> Siemens();
  /**
   * @brief A special constructor to build a weber unit.
   */
  static std::shared_ptr<Unit> Weber();
  /**
   * @brief A special constructor to build a tesla unit.
   */
  static std::shared_ptr<Unit> Tesla();
  /**
   * @brief A special constructor to build a henry unit.
   */
  static std::shared_ptr<Unit> Henry();
  /**
   * @brief A special constructor to build a minute unit.
   */
  static std::shared_ptr<Unit> Minute();
  /**
   * @brief A special constructor to build a hour unit.
   */
  static std::shared_ptr<Unit> Hour();
  /**
   * @brief A special constructor to build a electronvolt unit.
   */
  static std::shared_ptr<Unit> ElectronVolt();
  /**
   * @brief A special constructor to build a celsius unit.
   */
  static std::shared_ptr<Unit> Celsius();
  /**
   * @brief A special constructor to build a fahrenheit unit.
   */
  static std::shared_ptr<Unit> Fahrenheit();
  /**
   * @brief A special constructor to build a dimensionless unit.
   */
  static std::shared_ptr<Unit> Dimensionless();
  /**
   * @brief A special constructor to build a percent unit.
   */
  static std::shared_ptr<Unit> Percent();
  /**
   * @brief A special constructor to build a radian unit.
   */
  static std::shared_ptr<Unit> Radian();

  // Utility to clean dimensions: remove zero exponents
  static void clean_dimensions(TotalDimensions& dims);

  /**
   * @brief The prefix applied to this unit.
   */
  std::string prefix() const;
  /**
   * @brief Dimensions of this unit.
   */
  TotalDimensions dimensions() const;
  /**
   * @brief Scale factor relatice to SI base units.
   */
  double scale_factor() const;
  /**
   * @brief Offset from base unit.
   */
  double offset() const;

  /**
   * @brief Multiply this unit by another unit.
   * @param other The unit to multiply by.
   * @return A new Unit representing the product of this unit and the other.
   */
  std::shared_ptr<Unit> operator*(const std::shared_ptr<Unit>& other) const;
  /**
   * @brief Divide this unit by another unit.
   * @param other The unit to divide by.
   * @return A new Unit representing the division of this unit by the other.
   */
  std::shared_ptr<Unit> operator/(const std::shared_ptr<Unit>& other) const;
  /**
   * @brief Raise the unit to a power.
   * @param power The exponent to raise the unit to.
   * @return A new Unit raised to the specified power.
   */
  std::shared_ptr<Unit> operator^(const int power) const;
  /**
   * @brief Apply a prefix to this unit.
   * @param prefix The prefix symbol to apply (e.g. "k" for kilo
   * @return A new Unit with the specified prefix applied.
   * @throws std::invalid_argument if the prefix is not valid.
   */
  std::shared_ptr<Unit> with_prefix(const std::string prefix) const;
  /**
   * @brief Apply a milli prefix to this unit.
   */
  std::shared_ptr<Unit> get_milli() const;
  /**
   * @brief Apply a micro prefix to this unit.
   */
  std::shared_ptr<Unit> get_micro() const;
  /**
   * @brief Apply a nano prefix to this unit.
   */
  std::shared_ptr<Unit> get_nano() const;
  /**
   * @brief Apply a pico prefix to this unit.
   */
  std::shared_ptr<Unit> get_pico() const;
  /**
   * @brief Apply a kilo prefix to this unit.
   */
  std::shared_ptr<Unit> get_kilo() const;
  /**
   * @brief Apply a mega prefix to this unit.
   */
  std::shared_ptr<Unit> get_mega() const;
  /**
   * @brief Apply a giga prefix to this unit.
   */
  std::shared_ptr<Unit> get_giga() const;
  /**
   * @brief Convert a value from this unit to a target unit.
   * @param value The value in this unit to convert.
   * @param target_unit The unit to convert the value to.
   * @return The converted value in the target unit.
   * @throws std::invalid_argument if the units are not compatible.
   */
  double convert_value_to(const double                 value,
                          const std::shared_ptr<Unit>& target_unit) const;
  /**
   * @brief Check if this unit is compatible with another unit.
   * @param other The unit to check compatibility with.
   * @return True if the units are compatible (same dimensions), false
   * otherwise.
   */
  bool is_compatible_with(const std::shared_ptr<Unit>& other) const;
  bool operator==(const Unit& other) const;
  bool operator!=(const Unit& other) const;

 protected:
  Unit() = default;  // or initialize _name with a default value
  friend class cereal::access;
  template <class Archive>
  inline void serialize(Archive& ar) {
    ar(cereal::base_class<Song>(this),
       _scale_factor,
       _offset,
       _prefix,
       _dimensions);
  }
};
using UnitSP = std::shared_ptr<Unit>;
}  // namespace units
}  // namespace physics
}  // namespace falcon_core
