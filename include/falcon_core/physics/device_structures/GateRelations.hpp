#pragma once

#include "falcon_core/generic/Map.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/physics/device_structures/Connections.hpp"
namespace falcon_core::physics::device_structures {

/**
 * @brief Holds the relations between gates and their neighbors.
 */
class GateRelations : public generic::Map<Connection, Connections> {
 public:
  GateRelations();
  GateRelations(std::vector<std::pair<ConnectionSP, ConnectionsSP>> init);
  /**
   * @brief Override the default Map assignment to force gate typing.
   */
  void insert_or_assign(const ConnectionSP& key, const ConnectionsSP& value);
  /**
   * @brief Override the assert method to force gate typing.
   */
  std::pair<generic::List<generic::Pair<Connection, Connections>>::iterator,
            bool>
  insert(const ConnectionSP& key, const ConnectionsSP& value);

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Map<Connection, Connections>>(this));
  }
};
using GateRelationsSP = std::shared_ptr<GateRelations>;
}  // namespace falcon_core::physics::device_structures
