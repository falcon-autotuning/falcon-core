#pragma once

#include "falcon-core/export.h"
#include "falcon-core/generic/List.hpp"
#include "falcon-core/instrument_interfaces/port_transforms/PortTransform.hpp"
/**
 * @brief Container for multiple PortTransform objects.
 */
namespace falcon_core {
namespace generic {
extern template class List<
    instrument_interfaces::port_transforms::PortTransform>;
}
namespace instrument_interfaces {
namespace port_transforms {

class FALCON_CORE_CPP_API PortTransforms : public generic::List<PortTransform> {
 public:
  PortTransforms(const PortTransforms& other);
  PortTransforms();
  /**
   * @brief Constructor for a collection of port transforms.
   * @param init a list of port transforms.
   */
  PortTransforms(const generic::ListSP<PortTransform>& init);
  /**
   * @brief Constructor for a collection of port transforms.
   * @param init a list of port transforms.
   */
  PortTransforms(const std::vector<PortTransformSP>& init);
  const generic::ListSP<PortTransform> transforms() const;
};
using PortTransformsSP = std::shared_ptr<PortTransforms>;
}  // namespace port_transforms
}  // namespace instrument_interfaces
}  // namespace falcon_core
