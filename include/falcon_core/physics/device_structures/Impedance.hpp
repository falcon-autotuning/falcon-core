#pragma once

#include "falcon_core/Jsonable.hpp"
#include "falcon_core/Quantity.hpp"
#include <complex>

namespace falcon_core {

class Impedance : public Jsonable {
public:
  using ComplexQuantity = Quantity<std::complex<double>>;

  Impedance(std::shared_ptr<ComplexQuantity> impedance)
      : _impedance(std::move(impedance)) {}

  const std::shared_ptr<ComplexQuantity> &get_impedance() const {
    return _impedance;
  }

  nlohmann::json to_json() const override {
    nlohmann::json j;
    add_metadata(j, "falcon_core.physics.device_structures.impedance",
                 "Impedance");
    j["_impedance"] = _impedance->to_json();
    return j;
  }

  size_t hash() const override { return _impedance ? _impedance->hash() : 0; }

private:
  std::shared_ptr<ComplexQuantity> _impedance;
};

} // namespace falcon_core
