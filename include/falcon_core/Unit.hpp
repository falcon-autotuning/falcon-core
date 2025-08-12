#pragma once

#include "falcon_core/Jsonable.hpp"
#include <map>
#include <memory>
#include <nlohmann/json.hpp>
#include <string>

namespace falcon_core {

class Unit : public Jsonable {
public:
  Unit(double factor, std::map<std::string, int> dimensions);

  double get_factor() const;
  const std::map<std::string, int> &dimensions() const;
  double get_conversion_factor(const Unit &target_unit) const;

  nlohmann::json to_json() const override;
  size_t hash() const override;

  std::shared_ptr<Unit> operator*(const Unit &other) const;
  std::shared_ptr<Unit> operator/(const Unit &other) const;

private:
  double _factor;
  std::map<std::string, int> _dimensions;
};

} // namespace falcon_core
