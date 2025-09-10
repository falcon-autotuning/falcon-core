#include "falcon_core/physics/device_structures/BaseConnections.hpp"

#include <algorithm>

namespace falcon_core {
namespace physics {
namespace device_structures {

BaseConnections::BaseConnections() = default;
BaseConnections::BaseConnections(size_t count)
    : generic::List<BaseConnection, BaseConnections>(count) {}
BaseConnections::BaseConnections(size_t count, const BaseConnectionSP& value)
    : generic::List<BaseConnection, BaseConnections>(count, value) {}
BaseConnections::BaseConnections(const std::vector<BaseConnectionSP>& vec)
    : generic::List<BaseConnection, BaseConnections>(vec) {}
BaseConnections::BaseConnections(const std::vector<BarrierGateSP>& vec)
    : generic::List<BaseConnection, BaseConnections>([&vec] {
        std::vector<BaseConnectionSP> base_vec;
        base_vec.reserve(vec.size());
        for (auto& g : vec)
          base_vec.push_back(std::static_pointer_cast<BaseConnection>(g));
        return base_vec;
      }()) {}

BaseConnections::BaseConnections(const std::vector<PlungerGateSP>& vec)
    : generic::List<BaseConnection, BaseConnections>([&vec] {
        std::vector<BaseConnectionSP> base_vec;
        base_vec.reserve(vec.size());
        for (auto& g : vec)
          base_vec.push_back(std::static_pointer_cast<BaseConnection>(g));
        return base_vec;
      }()) {}

BaseConnections::BaseConnections(const std::vector<ScreeningGateSP>& vec)
    : generic::List<BaseConnection, BaseConnections>([&vec] {
        std::vector<BaseConnectionSP> base_vec;
        base_vec.reserve(vec.size());
        for (auto& g : vec)
          base_vec.push_back(std::static_pointer_cast<BaseConnection>(g));
        return base_vec;
      }()) {}

BaseConnections::BaseConnections(const std::vector<ReservoirGateSP>& vec)
    : generic::List<BaseConnection, BaseConnections>([&vec] {
        std::vector<BaseConnectionSP> base_vec;
        base_vec.reserve(vec.size());
        for (auto& g : vec)
          base_vec.push_back(std::static_pointer_cast<BaseConnection>(g));
        return base_vec;
      }()) {}

BaseConnections::BaseConnections(const std::vector<OhmicSP>& vec)
    : generic::List<BaseConnection, BaseConnections>([&vec] {
        std::vector<BaseConnectionSP> base_vec;
        base_vec.reserve(vec.size());
        for (auto& g : vec)
          base_vec.push_back(std::static_pointer_cast<BaseConnection>(g));
        return base_vec;
      }()) {}
bool BaseConnections::is_gates() const {
  return std::all_of(
      this->begin(), this->end(), [](const BaseConnectionSP& conn) {
        return conn->is_gate();
      });
}
bool BaseConnections::is_ohmics() const {
  return std::all_of(
      this->begin(), this->end(), [](const BaseConnectionSP& conn) {
        return conn->is_ohmic();
      });
}
bool BaseConnections::is_dot_gates() const {
  return std::all_of(
      this->begin(), this->end(), [](const BaseConnectionSP& conn) {
        return conn->is_dot_gate();
      });
}
bool BaseConnections::is_plunger_gates() const {
  return std::all_of(
      this->begin(), this->end(), [](const BaseConnectionSP& conn) {
        return conn->is_plunger_gate();
      });
}
bool BaseConnections::is_barrier_gates() const {
  return std::all_of(
      this->begin(), this->end(), [](const BaseConnectionSP& conn) {
        return conn->is_barrier_gate();
      });
}
bool BaseConnections::is_reservoir_gates() const {
  return std::all_of(
      this->begin(), this->end(), [](const BaseConnectionSP& conn) {
        return conn->is_reservoir_gate();
      });
}
bool BaseConnections::is_screening_gates() const {
  return std::all_of(
      this->begin(), this->end(), [](const BaseConnectionSP& conn) {
        return conn->is_screening_gate();
      });
}

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::BaseConnections)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::List<
        falcon_core::physics::device_structures::BaseConnection>,
    falcon_core::physics::device_structures::BaseConnections)
