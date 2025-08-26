#pragma once

#include <memory>

#include "falcon_core/physics/device_structures/Gate.hpp"
#include "falcon_core/physics/device_structures/Gates.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief Holds the relations between gates and their neighbors.
 */
class GateRelations : public generic::Song {
  std::map<GateSP, GatesSP<Gate>> _relation;

 public:
  GateRelations(const std::map<GateSP, GatesSP<Gate>>& relation)
      : _relation(relation) {}
  /**
   * @brief Get gates for a given gate key (dict-like access).
   */
  GatesSP<Gate> operator[](const GateSP& key) const {
    return _relation.at(key);
  }
  /**
   * @brief Set gates for a given gate key (dict-like access).
   */
  void set(const GateSP& key, const GatesSP<Gate>& value) {
    _relation[key] = value;
  }
  /**
   * @brief Returns the items in the relation as a const reference.
   */
  const std::map<GateSP, GatesSP<Gate>>& items() const { return _relation; }
  /**
   * @brief Checks if the relation contains the key.
   */
  bool contains(const GateSP& key) const {
    return _relation.find(key) != _relation.end();
  }
  /**
   * @brief Returns the keys in the relation.
   */
  std::vector<GateSP> keys() const {
    std::vector<GateSP> out;
    for (const auto& kv : _relation) out.push_back(kv.first);
    return out;
  }
  /**
   * @brief Returns the values in the relation.
   */
  std::vector<GatesSP<Gate>> values() const {
    std::vector<GatesSP<Gate>> out;
    for (const auto& kv : _relation) out.push_back(kv.second);
    return out;
  }
  /**
   * @brief Returns the number of items in the relation.
   */
  std::size_t size() const { return _relation.size(); }
  /**
   * @brief Returns an iterator to the beginning of the relation.
   */
  std::map<GateSP, GatesSP<Gate>>::const_iterator begin() const {
    return _relation.begin();
  }
  /**
   * @brief Returns an iterator to the end of the relation.
   */
  std::map<GateSP, GatesSP<Gate>>::const_iterator end() const {
    return _relation.end();
  }
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _relation);
  }

 protected:
  GateRelations() = default;
  friend class cereal::access;
};
using GateRelationsSP = std::shared_ptr<GateRelations>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core

#ifndef SWIG
using namespace falcon_core::physics::device_structures;
CEREAL_REGISTER_TYPE(GateRelations)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, GateRelations)
#endif
