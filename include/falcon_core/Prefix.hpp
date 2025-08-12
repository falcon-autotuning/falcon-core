#pragma once

#include "Jsonable.hpp"
#include <map>
#include <string>

namespace falcon_core {

class Prefix : public Jsonable {
public:
  Prefix(const std::string &symbol, double factor);

  std::string symbol() const;
  double factor() const;

  nlohmann::json to_json() const override;
  size_t hash() const override;

private:
  std::string _symbol;
  double _factor;
};

} // namespace falcon_core
