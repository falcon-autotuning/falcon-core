#pragma once

#include "falcon_core/generic/Jsonable.hpp"

#include <map>
#include <string>

namespace falcon_core
{

enum class BaseDimension
{
  LENGTH,
  MASS,
  TIME,
  CURRENT,
  TEMPERATURE,
  LUMINOUS_INTENSITY,
  AMOUNT_OF_SUBSTANCE
};

class Dimension : public Jsonable
{
public:
  Dimension (std::map<BaseDimension, int> dimensions);

  bool           is_dimensionless () const;
  std::string    to_string () const;
  nlohmann::json to_json () const override;
  size_t         hash () const override;

  // Dimension operator*(const Dimension& other) const;
  // Dimension operator/(const Dimension& other) const;
  bool operator== (const Dimension &other) const;
  bool operator!= (const Dimension &other) const;

  const std::map<BaseDimension, int> &get_dimensions () const;

private:
  std::map<BaseDimension, int> _dimensions;
};

} // namespace falcon_core
