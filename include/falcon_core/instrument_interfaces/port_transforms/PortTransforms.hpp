#pragma once

#include "falcon_core/generic/List.hpp"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"
/**
 * @brief Container for multiple PortTransform objects.
 */
namespace falcon_core::instrument_interfaces::port_transforms {

class PortTransforms : public generic::List<PortTransform> {
 public:
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

  template <class Archive>
  void serialize(Archive& ar) {
    return ar(cereal::base_class<generic::List<PortTransform>>(this));
  }
};

}  // namespace falcon_core::instrument_interfaces::port_transforms
