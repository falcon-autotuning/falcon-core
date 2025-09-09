/**
 * @file BaseArray.hpp
 * @brief Defines the BaseArray template for FalconCore.
 */

#pragma once

#include <Eigen/Dense>
#include <Eigen/Tensor>
#include <cereal/types/eigen.hpp>

#include "falcon_core/generic/List.hpp"
#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace math {
namespace arrays {

/// @brief Base class for array-like objects using Eigen matrices.
/// @tparam T Element type (e.g., double, float).
template <typename numeric, typename dimensions>
class BaseArray : public generic::Song {
 public:
  using ArrayType = Eigen::Tensor<numeric, dimensions>;

  /**
   * @brief Initializes an array object.
   */
  BaseArray(const MatrixType &data) : _data(data) {}
  BaseArray() = default;
  /**
   * @brief Returns the underlying data in the array.
   */
  const MatrixType &data() const { return _data; }
  /**
   * @brief Returns the underlying data in the array.
   */
  MatrixType &data() { return _data; }
  /**
   * @brief Check if the data is equal to the other data.
   * @param other The other data to compare to.
   * @returnTrue if the data is equal, false otherwise.
   */
  bool operator==(const std::shared_ptr<BaseArray<numeric>> &other) const {
    return data().isApprox(other->data());
  }
  /**
   * @brief Add the data to the other data.
   * @param other The other data to add.
   * @return A new BaseArray with the added data.
   */
  std::shared_ptr<BaseArray<numeric>> operator+(
      const std::shared_ptr<BaseArray<numeric>> &other) const {
    return std::make_shared<BaseArray>(
        BaseArray(data().array() + other->data().array()));
  }
  /**
   * @brief Negates the data.
   */
  std::shared_ptr<BaseArray<numeric>> operator-() const {
    return std::make_shared<BaseArray>(BaseArray(-data().array()));
  }
  /**
   * @brief Subtracts the other data from to the data.
   * @param other The other data to subtract.
   * @return A new BaseArray with the subtracted data.
   */
  std::shared_ptr<BaseArray<numeric>> operator-(
      const std::shared_ptr<BaseArray<numeric>> &other) const {
    return std::make_shared<BaseArray>(
        BaseArray(data().array() - other->data().array()));
  }
  /**
   * @brief Raise the data to the power.
   * @param power The power of the data to raise to.
   * @return The data raised to the power.
   */
  std::shared_ptr<BaseArray<numeric>> operator^(const double &power) {
    return std::make_shared<BaseArray>(BaseArray(data().array().pow(power)));
  }
  /**
   * @brief Raise the data to the power.
   * @param power The power of the data to raise to.
   * @return The data raised to the power.
   */
  std::shared_ptr<BaseArray<numeric>> operator^(const int &power) {
    return std::make_shared<BaseArray>(BaseArray(data().array().pow(power)));
  }
  /**
   * @brief Mutliply the data by the other data.
   * @param other The other data to mulitply by.
   * @returns The product of the data and the other data.
   */
  std::shared_ptr<BaseArray<numeric>> operator*(
      const std::shared_ptr<BaseArray<numeric>> &other) const {
    return std::make_shared<BaseArray>(
        BaseArray(data().array() * other->data().array()));
  }
  /**
   * @brief Divide the data by the other data.
   * @param other The other data to divide by.
   * @returns the data divided by the other data.
   */
  std::shared_ptr<BaseArray<numeric>> operator/(
      const std::shared_ptr<BaseArray<numeric>> &other) const {
    return std::make_shared<BaseArray>(
        BaseArray(data().array() / other->data().array()));
  }
  /**
   * @brief Return the sum of the squares of the data.
   */
  double get_sum_of_squares() { return (this ^ 2).array().sum(); }
  /**
   * @brief Return the sum of the squares of the data.
   * @param other The numeric target to difference against.
   */
  double get_sum_of_squares(int other) {
    return ((this - other) ^ 2).array().sum();
  }
  /**
   * @brief Return the sum of the squares of the data.
   * @param other The numeric target to difference against.
   */
  double get_sum_of_squares(double other) {
    return ((this - other) ^ 2).array().sum();
  }
  /**
   * @brief Return the sum of the squares of the data.
   * @param other The numeric target to difference against.
   */
  double get_sum_of_squares(const std::shared_ptr<BaseArray<numeric>> &other) {
    return ((this - *other) ^ 2).array().sum();
  }
  /**
   * @brief Returns the absolute value of the array.
   */
  std::shared_ptr<BaseArray<numeric>> abs() const {
    return std::make_shared<BaseArray>(BaseArray(this->data().array().abs()));
  }
  /**
   * @brief Returns the min of the array.
   */
  numeric min() const { return this->data().array().minCoeff(); }
  /**
   * @brief Returns the minimum of the two arrays stacked.
   */
  std::shared_ptr<BaseArray<numeric>> min(
      const std::shared_ptr<BaseArray<numeric>> &other) const {
    return std::make_shared<BaseArray>(
        BaseArray(this->data().min(other->data())));
  }
  /**
   * @brief Returns the max of the array.
   */
  T max() const { return this->data().array().maxCoeff(); }
  /**
   * @brief Returns the maximum of the two arrays stacked.
   */
  std::shared_ptr<BaseArray<numeric>> max(
      const std::shared_ptr<BaseArray<numeric>> &other) const {
    return std::make_shared<BaseArray>(
        BaseArray(this->data().max(other->data())));
  }
  /**
   * @brief Returns the item selected from eigen.
   */
  std::shared_ptr<BaseArray<numeric>> operator[](const int index) const {
    return this->data()(index);
  }
  /**
   * @brief Returns the item selected from eigen.
   */
  generic::ListSP<BaseArray<numeric>> operator[](
      const generic::ListSP<int> index) const {
    return this->data()(index);
  }
  /**
   * @brief Returns if any of the data is greater than the value.
   * @param value the value to compare to.
   * @returns True if any of the data is greater than the value, False
   * otherwise.
   */
  bool operator>(double value) const { return }

 protected:
  MatrixType _data;

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive &ar) {
    ar(cereal::base_class<generic::Song>(this), _data);
  }
};
template <typename numeric>
using BaseArraySP = std::shared_ptr<BaseArray<numeric>>;
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
