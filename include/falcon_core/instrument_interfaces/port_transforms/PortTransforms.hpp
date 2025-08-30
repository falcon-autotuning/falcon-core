#pragma once

#include <memory>
#include <vector>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"

/**
 * @brief Container for multiple PortTransform objects.
 */
namespace falcon_core {
namespace instrument_interfaces {
namespace port_transforms {

class PortTransforms : public generic::Song {
 public:
  using value_type     = PortTransform;
  using container_type = std::vector<std::shared_ptr<value_type>>;

  PortTransforms();

  void append(const std::shared_ptr<value_type> &transform);
  const container_type &get_transforms() const;

  template <class Archive>
  void serialize(Archive &ar);

 private:
  container_type _transforms;
};

}  // namespace port_transforms
}  // namespace instrument_interfaces
}  // namespace falcon_core
