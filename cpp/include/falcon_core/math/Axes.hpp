#pragma once

#include "falcon_core/generic/List.hpp"

/**
 * @file Axes.hpp
 * @brief Defines the Axes container for FalconCore.
 */

namespace falcon_core {
namespace math {
template <typename Value>
static const generic::List<Value>& list_check_and_deref(
    const generic::ListSP<Value>& items) {
  if (!items) throw std::invalid_argument("Axes: items must not be null.");
  return *items;
}
/**
 * @brief Container for a collection of axis objects.
 *
 * @details
 * Axes is a vector-like container for axis objects, such as discretizers or
 * numeric axes. Provides standard vector access methods.
 *
 * The order matters, as it is used to index the hypercube
 *
 * @tparam T The type of axis object (e.g., double, BaseDiscretizer).
 */
template <typename Value>
class Axes : public generic::List<Value> {
 public:
  Axes() = default;
  /**
   * @brief Construct Axes from a vector of items.
   * @param items Vector of axis objects.
   */
  explicit Axes(const typename generic::List<Value>::Container& items)
      : generic::List<Value>(items) {}
  /**
   * @brief Construct Axes from a vector of items.
   * @param items Vector of axis objects.
   */
  explicit Axes(const generic::ListSP<Value>& items)
      : generic::List<Value>(list_check_and_deref<Value>(items)) {}
  inline bool operator==(const Axes<Value>& other) const {
    return generic::List<Value>::operator==(other);
  }
  inline bool operator!=(const Axes<Value>& other) const {
    return !(*this == other);
  }
};
template <typename V>
using AxesSP = std::shared_ptr<Axes<V>>;
}  // namespace math
}  // namespace falcon_core

// -----------------------------------------------------------------------------
// Optional extern template declarations for commonly used Axes<T>.
// Consumers that link against the compiled library should define
// FALCON_CORE_USE_EXTERN_TEMPLATES so these are imported rather than
// instantiated locally.
// -----------------------------------------------------------------------------

#ifdef FALCON_CORE_USE_EXTERN_TEMPLATES

// forwards declarations for concrete project types (used below)
namespace falcon_core {
namespace math {
namespace domains {
class CoupledLabelledDomain;
}
namespace discrete_spaces {
class Discretizer;
}
namespace arrays {
class ControlArray;
class ControlArray1D;
class LabelledControlArray;
class LabelledMeasuredArray;
}  // namespace arrays
}  // namespace math
namespace autotuner_interfaces {
namespace contexts {
class MeasurementContext;
}
}  // namespace autotuner_interfaces
namespace instrument_interfaces {
namespace names {
class InstrumentPort;
}
}  // namespace instrument_interfaces
namespace generic {
class Map<std::string, bool>;
}
}  // namespace falcon_core

extern template class FALCON_CORE_CPP_API falcon_core::math::Axes<int>;
extern template class FALCON_CORE_CPP_API falcon_core::math::Axes<double>;
extern template class FALCON_CORE_CPP_API
    falcon_core::math::Axes<falcon_core::math::domains::CoupledLabelledDomain>;
extern template class FALCON_CORE_CPP_API falcon_core::math::Axes<
    falcon_core::autotuner_interfaces::contexts::MeasurementContext>;
extern template class FALCON_CORE_CPP_API falcon_core::math::Axes<
    falcon_core::instrument_interfaces::names::InstrumentPort>;
extern template class FALCON_CORE_CPP_API
    falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>;
extern template class FALCON_CORE_CPP_API
    falcon_core::math::Axes<falcon_core::math::arrays::ControlArray>;
extern template class FALCON_CORE_CPP_API
    falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>;
extern template class FALCON_CORE_CPP_API
    falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>;
extern template class FALCON_CORE_CPP_API
    falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>;
extern template class FALCON_CORE_CPP_API
    falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>;
extern template class FALCON_CORE_CPP_API
    falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>;
extern template class FALCON_CORE_CPP_API
    falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>;

#endif  // FALCON_CORE_USE_EXTERN_TEMPLATES
