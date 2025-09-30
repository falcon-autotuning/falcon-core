/**
 * @file Quantity.hpp
 * @brief Defines the Quantity class for FalconCore.
 */

#pragma once

#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core::math {

/**
 * @brief Represents a physical quantity with a value and unit.
 *
 * @details
 * Supports arithmetic operations and unit conversion.
 */
class Quantity : public generic::Song {
  double                       _value;
  physics::units::SymbolUnitSP _unit;

 public:
  /**
   * @brief Initialize a Quantity, which is a float with a unit.
   * @param value the value of the quantity.
   * @param unit the unit of the quantity.
   */
  Quantity(
      double                       value,
      physics::units::SymbolUnitSP unit = physics::units::SymbolUnit::Volt());

  /**
   * @brief Return the value of the quantity.
   */
  double value() const;
  /**
   * @brief Return the unit of the quantity.
   */
  physics::units::SymbolUnitSP unit() const;
  /**
   * @brief Convert the quantity to a different unit.
   * @param target_unit the raget unit to convert to.
   */
  void convert_to(physics::units::SymbolUnitSP target_unit);

  std::shared_ptr<Quantity> operator*(const int& other) const;
  std::shared_ptr<Quantity> operator*(const double& other) const;
  std::shared_ptr<Quantity> operator*(
      const std::shared_ptr<Quantity>& other) const;
  Quantity& operator*=(const int& other);
  Quantity& operator*=(const double& other);
  Quantity& operator*=(const std::shared_ptr<Quantity>& other);

  std::shared_ptr<Quantity> operator/(const int& other) const;
  std::shared_ptr<Quantity> operator/(const double& other) const;
  std::shared_ptr<Quantity> operator/(
      const std::shared_ptr<Quantity>& other) const;
  Quantity& operator/=(const int& other);
  Quantity& operator/=(const double& other);
  Quantity& operator/=(const std::shared_ptr<Quantity>& other);

  std::shared_ptr<Quantity> operator^(const int& other) const;

  std::shared_ptr<Quantity> operator+(const int& other) const;
  std::shared_ptr<Quantity> operator+(const double& other) const;
  std::shared_ptr<Quantity> operator+(
      const std::shared_ptr<Quantity>& other) const;
  Quantity& operator+=(const int& other);
  Quantity& operator+=(const double& other);
  Quantity& operator+=(const std::shared_ptr<Quantity>& other);

  std::shared_ptr<Quantity> operator-() const;

  std::shared_ptr<Quantity> operator-(const int& other) const;
  std::shared_ptr<Quantity> operator-(const double& other) const;
  std::shared_ptr<Quantity> operator-(
      const std::shared_ptr<Quantity>& other) const;
  Quantity& operator-=(const int& other);
  Quantity& operator-=(const double& other);
  Quantity& operator-=(const std::shared_ptr<Quantity>& other);

  std::shared_ptr<Quantity> abs() const;
  bool                      operator==(const Quantity& other) const;
  bool                      operator!=(const Quantity& other) const;

 protected:
  friend class cereal::access;
  Quantity();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Song>(this), _value, _unit);
  }
};
using QuantitySP = std::shared_ptr<Quantity>;
}  // namespace falcon_core::math
