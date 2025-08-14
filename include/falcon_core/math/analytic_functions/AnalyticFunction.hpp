#pragma once

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace math {
namespace analytic_functions {

class AnalyticFunction : public generic::Song {
 public:
  virtual ~AnalyticFunction()             = default;
  virtual double evaluate(double x) const = 0;
};
}  // namespace analytic_functions
}  // namespace math
}  // namespace falcon_core
