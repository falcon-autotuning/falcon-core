#pragma once

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace names {
class NameBase : public generic::Song {
  std::string _name;
  int         _num;
  std::string _index_string;

 public:
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
  void serialize(Archive& ar) {
    ar(cereal::base_class<Song>(this), _name, _index_string);
  }
};
using NameBaseSP = std::shared_ptr<NameBase>;
}  // namespace names
}  // namespace autotuner_interfaces
}  // namespace falcon_core
