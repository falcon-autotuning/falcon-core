#pragma once

#include "falcon_core/generic/Map.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/device_structures/BaseConnections.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief Holds the relations between gates and their neighbors.
 */
class GateRelations
    : public generic::Map<BaseConnection, BaseConnections, GateRelations> {
 public:
  GateRelations();
  GateRelations(
      std::vector<std::pair<BaseConnectionSP, BaseConnectionsSP>> init);
  template <class Archive>
  void serialize(Archive& ar);
  /**
   * @brief Override the default Map assignment to force gate typing.
   */
  void insert_or_assign(const BaseConnectionSP&  key,
                        const BaseConnectionsSP& value);
  /**
   * @brief Override the assert method to force gate typing.
   */
  std::pair<
      std::vector<std::pair<BaseConnectionSP, BaseConnectionsSP>>::iterator,
      bool>
  insert(const BaseConnectionSP& key, const BaseConnectionsSP& value);

 protected:
  friend class cereal::access;
};
using GateRelationsSP = std::shared_ptr<GateRelations>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
