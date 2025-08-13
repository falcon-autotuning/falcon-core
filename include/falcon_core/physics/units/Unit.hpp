#pragma once

#include "falcon_core/Constants.hpp"
#include "falcon_core/Jsonable.hpp"
#include "falcon_core/physics/units/TotalDimensions.hpp"

#include <memory>
#include <nlohmann/json.hpp>

namespace falcon_core
{

class Unit : public Jsonable
{
public:
  Unit (TotalDimensions dimensions,
        double          scale_factor = 1.0,
        double          offset       = 0.0,
        char            prefix       = *SI::UNIT_SYMBOL);

  /**
   * @brief The prefix applied to this unit.
   */
  char
  prefix ()
  {
    return this->_prefix;
  }
  /**
   * @brief Dimensions of this unit.
   */
  TotalDimensions
  dimensions ()
  {
    return this->_dimensions;
  }
  /**
   * @brief Scale factor relatice to SI base units.
   */
  double
  scale_factor ()
  {
    return this->_scale_factor;
  }
  /**
   * @brief Offset from base unit.
   */
  double
  offset ()
  {
    return this->_offset;
  }

  std::shared_ptr<Unit> operator* (const Unit &other) const;
  std::shared_ptr<Unit> operator/ (const Unit &other) const;

private:
  double          _scale_factor; // Scale factor relative to SI base units
  double          _offset;       // Offset form base unit (e.g. for Celsius)
  char            _prefix;       // The SI prefix symbol (e.g. "k" for kilo)
  TotalDimensions _dimensions; // dictionary mapping dimensions to their powers
};
};
