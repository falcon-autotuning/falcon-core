#pragma once

#include "falcon_core/generic/Map.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/device_structures/BaseConnections.hpp"
namespace falcon_core::physics::device_structures {

/**
 * @brief Holds the relations between gates and their neighbors.
 */
class GateRelations
    : public generic::Map<BaseConnection, BaseConnections, GateRelations> {
 public:
  GateRelations();
  GateRelations(
      std::vector<std::pair<BaseConnectionSP, BaseConnectionsSP>> init);
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
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Map<BaseConnection, BaseConnections, GateRelations>>(
        this));
  }
};
using GateRelationsSP = std::shared_ptr<GateRelations>;
}  // namespace falcon_core::physics::device_structures
