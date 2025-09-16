#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/instrument_interfaces/Instrument.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
namespace falcon_core::autotuner_interfaces::contexts {
class BaseContext : public generic::Song {
  physics::device_structures::BaseConnectionSP _connection;
  instrument_interfaces::Instrument            _instrument_type;

 public:
  /**
   * @brief Initialize a BaseContext with a connection and instrument type.
   * @param connection The device connection.
   * @param instrument_type The type of instrument.
   */
  BaseContext(const physics::device_structures::BaseConnectionSP& connection,
              const instrument_interfaces::Instrument& instrument_type);
  /**
   * @brief Initialize a BaseContext with an InstrumentPort.
   * @param port The instrument port.
   */
  BaseContext(const instrument_interfaces::names::InstrumentPortSP& port);
  /**
   * @brief Return the connection.
   */
  const physics::device_structures::BaseConnectionSP connection() const;
  /**
   * @brief Return the instrument type.
   */
  const instrument_interfaces::Instrument instrument_type() const;

 protected:
  friend class cereal::access;
  BaseContext();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _connection, _instrument_type);
  }
};
using BaseContextSP = std::shared_ptr<BaseContext>;
}  // namespace falcon_core::autotuner_interfaces::contexts
