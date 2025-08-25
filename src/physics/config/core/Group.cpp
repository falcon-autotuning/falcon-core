#include "falcon_core/physics/config/core/Group.hpp"

using namespace falcon_core::physics::config::core;
bool Group::has_channel(const ChannelSP& channel) const {
  return *this->_name == *channel;
}
bool Group::is_charge_sensor() const { return this->_num_dots == 1; }
