#pragma once

#include "falcon-core/export.h"
#include "falcon-core/generic/Map.hpp"
#include "falcon-core/physics/device_structures/Connection.hpp"
#include "falcon-core/physics/device_structures/Connections.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief Holds the relations between gates and their neighbors.
 */
class FALCON_CORE_CPP_API GateRelations
    : public generic::Map<Connection, Connections> {
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
  bool operator==(const GateRelations& other) const;
  bool operator!=(const GateRelations& other) const;
};
using GateRelationsSP = std::shared_ptr<GateRelations>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
