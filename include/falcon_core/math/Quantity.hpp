/**
 * @file Quantity.hpp
 * @brief Defines the Quantity class for FalconCore.
 */

#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core {
namespace math {

/**
 * @brief Represents a physical quantity with a value and unit.
 *
 * @details
 * Supports arithmetic operations and unit conversion.
 */
class Quantity : public generic::Song {
 public:
  /**
   * @brief Construct a Quantity.
   * @param value The numeric value.
   * @param unit Shared pointer to the unit.
   */
  Quantity(double value, std::shared_ptr<physics::units::SymbolUnit> unit)
      : _value(value), _unit(std::move(unit)) {}

  /**
   * @brief Get the value of the quantity.
   * @return The value.
   */
  double value() const { return _value; }

  /**
   * @brief Get the unit of the quantity.
   * @return Shared pointer to the unit.
   */
  std::shared_ptr<physics::units::SymbolUnit> unit() { return _unit; }

  /**
   * @brief Convert the quantity to a different unit.
   * @param target_unit The unit to convert to.
   */
  void convert_to(std::shared_ptr<physics::units::SymbolUnit> target_unit);

  /**
   * @brief Multiply two quantities.
   * @param other The quantity to multiply with.
   * @return Shared pointer to the result.
   */
  std::shared_ptr<Quantity> operator*(int other) const;
  std::shared_ptr<Quantity> operator*(double other) const;
  std::shared_ptr<Quantity> operator*(std::shared_ptr<Quantity> other) const;

  /**
   * @brief Divide two quantities.
   * @param other The quantity to divide by.
   * @return Shared pointer to the result.
   */
  std::shared_ptr<Quantity> operator/(int other) const;
  std::shared_ptr<Quantity> operator/(double other) const;
  std::shared_ptr<Quantity> operator/(std::shared_ptr<Quantity> other) const;

  /**
   * @brief Raise a quantity to a power.
   * @param other The exponent.
   * @return Shared pointer to the result.
   */
  std::shared_ptr<Quantity> operator^(int other) const;

  /**
   * @brief Add two quantities.
   * @param other The quantity to add.
   * @return Shared pointer to the result.
   */
  std::shared_ptr<Quantity> operator+(int other) const;
  std::shared_ptr<Quantity> operator+(double other) const;
  std::shared_ptr<Quantity> operator+(std::shared_ptr<Quantity> other) const;

  /**
   * @brief Negate a quantity.
   * @return Shared pointer to the result.
   */
  std::shared_ptr<Quantity> operator-() const;

  /**
   * @brief Subtract two quantities.
   * @param other The quantity to subtract.
   * @return Shared pointer to the result.
   */
  std::shared_ptr<Quantity> operator-(int other) const;
  std::shared_ptr<Quantity> operator-(double other) const;
  std::shared_ptr<Quantity> operator-(std::shared_ptr<Quantity> other) const;

  /**
   * @brief Take the absolute value of a quantity.
   * @return Shared pointer to the result.
   */
  std::shared_ptr<Quantity> abs() const;

 private:
  double                                      _value; ///< Value of the quantity.
  std::shared_ptr<physics::units::SymbolUnit> _unit;  ///< Unit of the quantity.

  friend class cereal::access;  // cereal can access private members
  /**
   * @brief Serialization method for cereal.
   * @param ar Archive object.
   */
  template <class Archive>
  void serialize(Archive &ar) {
    ar(cereal::base_class<Song>(this), _value, _unit);
  }

 protected:
  /**
   * @brief Default constructor for cereal access.
   */
  Quantity() = default;
};
}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
using namespace falcon_core::math;
CEREAL_REGISTER_TYPE(falcon_core::math::Quantity)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::Quantity)
#endif
