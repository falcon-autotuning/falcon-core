#pragma once

#include <mutex>
#include <shared_mutex>

#include "falcon_core/export.h"
#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace names {
class FALCON_CORE_CPP_API NameBase : public generic::Song {
  std::string                     _name;
  int                             _num;
  std::string                     _index_string;
  mutable std::shared_timed_mutex _mu_name;
  mutable std::shared_timed_mutex _mu_num;
  mutable std::shared_timed_mutex _mu_index_string;

 public:
  NameBase(const NameBase& other);
  NameBase& operator=(const NameBase& other);
  NameBase(const std::string& name);
  NameBase(const std::string& name, const std::string& index_string);
  NameBase(const int& num, const std::string& index_string);
  /**
   * @brief The string form of the name.
   */
  std::string name() const;
  /**
   * @brief The numeric form of the name.
   */
  int                       num() const;
  std::shared_ptr<NameBase> operator+(
      const std::shared_ptr<NameBase>& other) const;
  std::shared_ptr<NameBase> operator-(
      const std::shared_ptr<NameBase>& other) const;

 protected:
  NameBase() = default;
  friend class cereal::access;
  template <class Archive>
  inline void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_name(_mu_name,
                                                        std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_num(_mu_num,
                                                       std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_index_string(
        _mu_index_string, std::defer_lock);
    std::lock(lock_name, lock_num, lock_index_string);
    ar(cereal::base_class<Song>(this), _name, _index_string);
  }
};
using NameBaseSP = std::shared_ptr<NameBase>;
}  // namespace names
}  // namespace autotuner_interfaces
}  // namespace falcon_core
