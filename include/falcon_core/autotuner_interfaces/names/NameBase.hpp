#pragma once

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace names {
class NameBase : public generic::Song {
  std::string _name;
  int         _num;
  std::string _index_string = "";

 public:
  NameBase(std::string name);
  NameBase(int num);
  /**
   * @brief The string form of the name.
   */
  std::string name() const { return _name; }
  /**
   * @brief The numeric form of the name.
   */
  int                       num() const { return _num; }
  std::shared_ptr<NameBase> operator+(const NameBase& other) const;
  std::shared_ptr<NameBase> operator-(const NameBase& other) const;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Song>(this), _name);
  }

 protected:
  NameBase() = default;
  friend class cereal::access;
};
using NameBaseSP = std::shared_ptr<NameBase>;
}  // namespace names
}  // namespace autotuner_interfaces
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core::autotuner_interfaces::names;
CEREAL_REGISTER_TYPE(NameBase)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, NameBase)
#endif
