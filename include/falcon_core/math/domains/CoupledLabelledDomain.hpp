#pragma once

#include <vector>
#include <cereal/types/vector.hpp>

#include "falcon_core/math/domains/LabelledDomain.hpp"

namespace falcon_core {
namespace math {
namespace domains {

template <typename T>
class CoupledLabelledDomain : public LabelledDomain<T> {
 public:
  CoupledLabelledDomain(
      double                                          min_val,
      double                                          max_val,
      std::shared_ptr<T>                              label,
      std::vector<std::shared_ptr<LabelledDomain<T>>> coupled_domains)
      : LabelledDomain<T>(min_val, max_val, label),
        _coupled_domains(std::move(coupled_domains)) {}

  const std::vector<std::shared_ptr<LabelledDomain<T>>>& coupled_domains()
      const {
    return _coupled_domains;
  }

 private:
  std::vector<std::shared_ptr<LabelledDomain<T>>> _coupled_domains;

  friend class cereal::access;
  CoupledLabelledDomain() = default;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<LabelledDomain<T>>(this), _coupled_domains);
  }
};
}  // namespace domains
}  // namespace math
}  // namespace falcon_core
