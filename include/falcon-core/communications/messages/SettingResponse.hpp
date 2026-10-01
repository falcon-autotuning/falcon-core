#pragma once

#include "falcon-core/communications/messages/BaseMessage.hpp"
#include "falcon-core/export.h"
#include "falcon-core/generic/Map.hpp"
#include "falcon-core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon-core/math/Quantity.hpp"

namespace falcon_core {
namespace communications {
namespace messages {

// A special response from the Hub to indicate any gotten results if any
class FALCON_CORE_CPP_API SettingResponse : public BaseMessage {
  generic::MapSP<instrument_interfaces::names::InstrumentPort, math::Quantity>
      _getters;
  mutable std::shared_timed_mutex _mu_getters;

public:
  SettingResponse(const SettingResponse &other);
  SettingResponse &operator=(const SettingResponse &other);
  SettingResponse(
      const std::string &message,
      const generic::MapSP<instrument_interfaces::names::InstrumentPort,
                           math::Quantity> &getters);

  const generic::MapSP<instrument_interfaces::names::InstrumentPort,
                       math::Quantity> &
  getters() const;
  bool operator==(const SettingResponse &other) const;
  bool operator!=(const SettingResponse &other) const;

protected:
  SettingResponse();
  friend class cereal::access;
  template <class Archive> void serialize(Archive &ar) {
    std::shared_lock<std::shared_timed_mutex> lock_g(_mu_getters);
    ar(cereal::base_class<BaseMessage>(this), _getters);
  }
};
using SettingResponseSP = std::shared_ptr<SettingResponse>;
} // namespace messages
} // namespace communications
} // namespace falcon_core
