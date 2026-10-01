#pragma once

#include "falcon-core/communications/messages/BaseMessage.hpp"
#include "falcon-core/export.h"
#include "falcon-core/generic/Map.hpp"
#include "falcon-core/instrument_interfaces/names/Ports.hpp"
#include "falcon-core/math/Quantity.hpp"

namespace falcon_core {
namespace communications {
namespace messages {

// A special request to the Hub to request the setting and getting of
// characteristics
class FALCON_CORE_CPP_API SettingRequest : public BaseMessage {
  instrument_interfaces::names::PortsSP _getters;
  generic::MapSP<instrument_interfaces::names::InstrumentPort, math::Quantity>
      _setters;
  mutable std::shared_timed_mutex _mu_getters;
  mutable std::shared_timed_mutex _mu_setters;

public:
  SettingRequest(const SettingRequest &other);
  SettingRequest &operator=(const SettingRequest &other);
  SettingRequest(
      const std::string &message,
      const instrument_interfaces::names::PortsSP &getters,
      const generic::MapSP<instrument_interfaces::names::InstrumentPort,
                           math::Quantity> &setters);

  const instrument_interfaces::names::PortsSP &getters() const;
  const generic::MapSP<instrument_interfaces::names::InstrumentPort,
                       math::Quantity> &
  setters() const;
  bool operator==(const SettingRequest &other) const;
  bool operator!=(const SettingRequest &other) const;

protected:
  SettingRequest();
  friend class cereal::access;
  template <class Archive> void serialize(Archive &ar) {
    std::shared_lock<std::shared_timed_mutex> lock_g(_mu_getters,
                                                     std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_s(_mu_setters,
                                                     std::defer_lock);
    std::lock(lock_g, lock_s);
    ar(cereal::base_class<BaseMessage>(this), _getters, _setters);
  }
};
using SettingRequestSP = std::shared_ptr<SettingRequest>;
} // namespace messages
} // namespace communications
} // namespace falcon_core
