#pragma once

#include <stdexcept>

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace math {
namespace domains {

class Domain : public generic::Song {
 public:
  Domain(double min_val, double max_val);
  double min() const;
  double max() const;
  double range() const;

 protected:
  double _min;
  double _max;

  friend class cereal::access;
  Domain();
  template <class Archive>
  void serialize(Archive& ar);
};

}  // namespace domains
}  // namespace math
}  // namespace falcon_core
