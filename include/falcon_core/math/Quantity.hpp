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
  Quantity(double value, std::shared_ptr<physics::units::SymbolUnit> unit);

  double value() const;
  std::shared_ptr<physics::units::SymbolUnit> unit();

  void convert_to(std::shared_ptr<physics::units::SymbolUnit> target_unit);

  std::shared_ptr<Quantity> operator*(int other) const;
  std::shared_ptr<Quantity> operator*(double other) const;
  std::shared_ptr<Quantity> operator*(std::shared_ptr<Quantity> other) const;

  std::shared_ptr<Quantity> operator/(int other) const;
  std::shared_ptr<Quantity> operator/(double other) const;
  std::shared_ptr<Quantity> operator/(std::shared_ptr<Quantity> other) const;

  std::shared_ptr<Quantity> operator^(int other) const;

  std::shared_ptr<Quantity> operator+(int other) const;
  std::shared_ptr<Quantity> operator+(double other) const;
  std::shared_ptr<Quantity> operator+(std::shared_ptr<Quantity> other) const;

  std::shared_ptr<Quantity> operator-() const;

  std::shared_ptr<Quantity> operator-(int other) const;
  std::shared_ptr<Quantity> operator-(double other) const;
  std::shared_ptr<Quantity> operator-(std::shared_ptr<Quantity> other) const;

  std::shared_ptr<Quantity> abs() const;

 private:
  double                                      _value; ///< Value of the quantity.
  std::shared_ptr<physics::units::SymbolUnit> _unit;  ///< Unit of the quantity.

  friend class cereal::access;  // cereal can access private members
  template <class Archive>
  void serialize(Archive &ar);

 protected:
  Quantity();
};
}  // namespace math
}  // namespace falcon_core
