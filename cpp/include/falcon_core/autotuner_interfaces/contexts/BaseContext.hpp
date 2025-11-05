#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/instrument_interfaces/names/Instrument.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
namespace falcon_core {
namespace autotuner_interfaces {
namespace contexts {
class BaseContext : public generic::Song {
  physics::device_structures::ConnectionSP _connection;
  instrument_interfaces::names::Instrument _instrument_type;

 public:
  /**
   * @brief Initialize a BaseContext with a connection and instrument type.
   * @param connection The device connection.
   * @param instrument_type The type of instrument.
   */
  BaseContext(const physics::device_structures::ConnectionSP& connection,
              const instrument_interfaces::names::Instrument& instrument_type);
  /**
   * @brief Initialize a BaseContext with an InstrumentPort.
   * @param port The instrument port.
   */
  BaseContext(const instrument_interfaces::names::InstrumentPortSP& port);
  /**
   * @brief Return the connection.
   */
  const physics::device_structures::ConnectionSP connection() const;
  /**
   * @brief Return the instrument type.
   */
  const instrument_interfaces::names::Instrument instrument_type() const;

  bool operator==(const BaseContext& other) const;
  bool operator!=(const BaseContext& other) const;

 protected:
  friend class cereal::access;
  BaseContext();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _connection, _instrument_type);
  }
};
using BaseContextSP = std::shared_ptr<BaseContext>;
}  // namespace contexts
}  // namespace autotuner_interfaces
}  // namespace falcon_core
