#pragma once

#include "falcon_core/generic/Song.hpp"

/**
 * @file AnalyticFunction.hpp
 * @brief Abstract base class for analytic functions in FalconCore.
 */

namespace falcon_core {
namespace math {
namespace analytic_functions {

class AnalyticFunction : public generic::Song {
 public:
  AnalyticFunction();
  AnalyticFunction(const std::string& name);
  virtual ~AnalyticFunction() = default;

  virtual double evaluate(double x) const = 0;

  std::string name() const;
  void set_name(const std::string& name);

 protected:
  std::string _name;

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar);
};

}  // namespace analytic_functions
}  // namespace math
}  // namespace falcon_core
