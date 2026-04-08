#pragma once

#include "falcon-core/export.h"
#include "falcon-core/generic/Song.hpp"
#include "falcon-core/instrument_interfaces/names/Instrument.hpp"
#include "falcon-core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon-core/physics/device_structures/Connection.hpp"
namespace falcon_core {
namespace autotuner_interfaces {
namespace contexts {
class FALCON_CORE_CPP_API BaseContext : public generic::Song {
  physics::device_structures::ConnectionSP _connection;
  instrument_interfaces::names::Instrument _instrument_type;
  mutable std::shared_timed_mutex          _mu_connection;
  mutable std::shared_timed_mutex          _mu_instrument_type;

 public:
  BaseContext(const BaseContext& other);
  BaseContext& operator=(const BaseContext& other);
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
  inline void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_c(_mu_connection,
                                                     std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_i(_mu_instrument_type,
                                                     std::defer_lock);
    std::lock(lock_c, lock_i);
    ar(cereal::base_class<generic::Song>(this), _connection, _instrument_type);
  }
};
using BaseContextSP = std::shared_ptr<BaseContext>;
}  // namespace contexts
}  // namespace autotuner_interfaces
}  // namespace falcon_core
