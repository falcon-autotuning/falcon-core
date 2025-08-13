#pragma once

#include "falcon_core/generic/NameBase.hpp"

namespace falcon_core {

class Channel : public NameBase<int> {
public:
  using NameBase<int>::NameBase;

  nlohmann::json to_json() const override {
    nlohmann::json j = NameBase<int>::to_json();
    add_metadata(j, "falcon_core.physics.device_structures.channel", "Channel");
    return j;
  }
};

} // namespace falcon_core
