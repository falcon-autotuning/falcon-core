#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core {
namespace math {

class Quantity : public generic::Song {
 public:
  Quantity(double value, std::shared_ptr<physics::units::SymbolUnit> unit)
      : _value(value), _unit(std::move(unit)) {}
  /**
   * @brief collect the value of the quantity
   */
  double value() const { return _value; }
  /**
   * @brief collect the unit of the quantity
   */
  std::shared_ptr<physics::units::SymbolUnit> unit() { return _unit; }
  /***
   * @brief converts the quantity to a different unit
   * @param target_unit the unit to convert to
   */
  void convert_to(std::shared_ptr<physics::units::SymbolUnit> target_unit);
  /***
   * @brief Multiply two quantities.
   * @param other the quantity to multiply with
   * @return a new Quantity object with the result
   */
  std::shared_ptr<Quantity> operator*(int other) const;
  std::shared_ptr<Quantity> operator*(double other) const;
  std::shared_ptr<Quantity> operator*(std::shared_ptr<Quantity> other) const;
  /***
   * @brief Divide two quantities.
   * @param other the quantity to divide by
   * @return a new Quantity object with the result
   */
  std::shared_ptr<Quantity> operator/(int other) const;
  std::shared_ptr<Quantity> operator/(double other) const;
  std::shared_ptr<Quantity> operator/(std::shared_ptr<Quantity> other) const;
  /***
   * @brief Raise a quantity to a power.
   * @param other the int to raise to the power of
   * @return a new Quantity object with the result
   */
  std::shared_ptr<Quantity> operator^(int other) const;
  /***
   * @brief Add two quantities.
   * @param other the quantity to add
   * @return a new Quantity object with the result
   */
  std::shared_ptr<Quantity> operator+(int other) const;
  std::shared_ptr<Quantity> operator+(double other) const;
  std::shared_ptr<Quantity> operator+(std::shared_ptr<Quantity> other) const;
  /***
   * @brief Negate a quantity.
   * @return a new Quantity object with the result
   */
  std::shared_ptr<Quantity> operator-() const;
  /***
   * @brief Subtract two quantities.
   * @param other the quantity to subtract
   * @return a new Quantity object with the result
   */
  std::shared_ptr<Quantity> operator-(int other) const;
  std::shared_ptr<Quantity> operator-(double other) const;
  std::shared_ptr<Quantity> operator-(std::shared_ptr<Quantity> other) const;
  /***
   * @brief Take the absolute value of a quantity.
   * @return a new Quantity object with the result
   */
  std::shared_ptr<Quantity> abs() const;

 private:
  double                                      _value;
  std::shared_ptr<physics::units::SymbolUnit> _unit;

  friend class cereal::access;  // cereal can access private members
  template <class Archive>
  void serialize(Archive &ar) {
    ar(cereal::base_class<Song>(this), _value, _unit);
  }

 protected:
  Quantity() = default;  // for cereal access
};
}  // namespace math
}  // namespace falcon_core
