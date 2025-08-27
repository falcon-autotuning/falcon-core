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

  /**
   * @brief Default constructor.
   */
  PortTransforms() = default;

  /**
   * @brief Append a PortTransform.
   * @param transform The PortTransform to add.
   */
  void append(const std::shared_ptr<value_type> &transform) {
    _transforms.push_back(transform);
  }

  /**
   * @brief Get all transforms.
   * @return The container of transforms.
   */
  const container_type &get_transforms() const { return _transforms; }

  template <class Archive>
  void serialize(Archive &ar) {
    ar(cereal::base_class<generic::Song>(this), _transforms);
  }

 private:
  container_type _transforms;
};

}  // namespace port_transforms
}  // namespace instrument_interfaces
}  // namespace falcon_core

#ifndef SWIG
CEREAL_REGISTER_TYPE(
    falcon_core::instrument_interfaces::port_transforms::PortTransforms)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::port_transforms::PortTransforms)
#endif
