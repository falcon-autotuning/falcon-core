#pragma once

#include "falcon_core/generic/Song.hpp"

namespace falcon_core::communications {
/**
 * @brief Represents a point in time with microsecond precision.
 */
class Time : public generic::Song {
  long long _micro_seconds_since_epoch;

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _micro_seconds_since_epoch);
  }

 public:
  /**
   * @brief Construct a Tiem object at the current time.
   */
  Time();

  /**
   * @brief Construct a Time object at a specific time.
   * @param micro_seconds_since_epoch The time in microseconds since the epoch.
   */
  Time(long long micro_seconds_since_epoch);

  /**
   * @brief Get the time in microseconds since epoch.
   * @return The time in microseconds since epoch.
   */
  const long long micro_seconds_since_epoch() const;
  /**
   * @brief Get the time in seconds since epoch.
   * @return The time in seconds since epoch.
   */
  const long long time() const;

  /**
   * @brief Convert the Time to a human-readable string.
   * @return A string representation of the Time.
   */
  const std::string to_string() const;
};
}  // namespace falcon_core::communications
