#include "falcon_core/physics/config/core/Group.hpp"

using namespace falcon_core::physics::config::core;
Group::Group(const ChannelSP&         name,
             const int&               num_dots,
             const ScreeningGatesSP&  screening_gates,
             const ReservoirGatesSP&  reservoir_gates,
             const PlungerGatesSP&    plunger_gates,
             const BarrierGatesSP&    barrier_gates,
             const BaseConnectionsSP& order)
    : StandardConfigConnections(screening_gates,
                                reservoir_gates,
                                plunger_gates,
                                barrier_gates,
                                std::make_shared<Ohmics>()),
      _name(name),
      _num_dots(num_dots),
      _order(std::make_shared<GateGeometryArray1D>(order, screening_gates)) {}
bool Group::has_channel(const ChannelSP& channel) const {
  return *this->_name == *channel;
}
bool          Group::is_charge_sensor() const { return this->_num_dots == 1; }
GatesSP<Gate> Group::get_all_channel_gates(const ChannelSP& channel) const {
  if (has_channel(channel)) {
    return get_all_gates();
  }
  return nullptr;
}
