#pragma once

#include "falcon_core/Constants.hpp"
#include "falcon_core/physics/units/Unit.hpp"

namespace falcon_core {
namespace physics {
namespace units {
namespace common_units {
const Unit Meter{SI::DIMENSIONS_METER, 1.0, 0.0, SI::UNIT_SYMBOL_METER};
const Unit Kilogram{SI::DIMENSIONS_KILOGRAM,
                    1.0,
                    0.0,
                    SI::UNIT_SYMBOL_KILOGRAM};
const Unit Second{SI::DIMENSIONS_SECOND, 1.0, 0.0, SI::UNIT_SYMBOL_SECOND};
const Unit Ampere{SI::DIMENSIONS_AMPERE, 1.0, 0.0, SI::UNIT_SYMBOL_AMPERE};
const Unit Kelvin{SI::DIMENSIONS_KELVIN, 1.0, 0.0, SI::UNIT_SYMBOL_KELVIN};
const Unit Mole{SI::DIMENSIONS_MOLE, 1.0, 0.0, SI::UNIT_SYMBOL_MOLE};
const Unit Candela{SI::DIMENSIONS_CANDELA, 1.0, 0.0, SI::UNIT_SYMBOL_CANDELA};
const Unit Hertz{SI::DIMENSIONS_HERTZ, 1.0, 0.0, SI::UNIT_SYMBOL_HERTZ};
const Unit Newton{SI::DIMENSIONS_NEWTON, 1.0, 0.0, SI::UNIT_SYMBOL_NEWTON};
const Unit Pascal{SI::DIMENSIONS_PASCAL, 1.0, 0.0, SI::UNIT_SYMBOL_PASCAL};
const Unit Joule{SI::DIMENSIONS_JOULE, 1.0, 0.0, SI::UNIT_SYMBOL_JOULE};
const Unit Watt{SI::DIMENSIONS_WATT, 1.0, 0.0, SI::UNIT_SYMBOL_WATT};
const Unit Coulomb{SI::DIMENSIONS_COULOMB, 1.0, 0.0, SI::UNIT_SYMBOL_COULOMB};
const Unit Volt{SI::DIMENSIONS_VOLT, 1.0, 0.0, SI::UNIT_SYMBOL_VOLT};
const Unit Farad{SI::DIMENSIONS_FARAD, 1.0, 0.0, SI::UNIT_SYMBOL_FARAD};
const Unit Ohm{SI::DIMENSIONS_OHM, 1.0, 0.0, SI::UNIT_SYMBOL_OHM};
const Unit Siemens{SI::DIMENSIONS_SIEMENS, 1.0, 0.0, SI::UNIT_SYMBOL_SIEMENS};
const Unit Weber{SI::DIMENSIONS_WEBER, 1.0, 0.0, SI::UNIT_SYMBOL_WEBER};
const Unit Tesla{SI::DIMENSIONS_TESLA, 1.0, 0.0, SI::UNIT_SYMBOL_TESLA};
const Unit Henry{SI::DIMENSIONS_HENRY, 1.0, 0.0, SI::UNIT_SYMBOL_HENRY};
const Unit Minute{SI::DIMENSIONS_SECOND,
                  SECONDS_PER_MINUTE,
                  0.0,
                  SI::UNIT_SYMBOL_MINUTE};
const Unit Hour{SI::DIMENSIONS_SECOND,
                SECONDS_PER_MINUTE *MINUTES_PER_HOUR,
                0.0,
                SI::UNIT_SYMBOL_HOUR};
const Unit ElectronVolt{SI::DIMENSIONS_JOULE,
                        ELECTRON_CHARGE,
                        0.0,
                        SI::UNIT_SYMBOL_ELECTRON_VOLT};
const Unit Celsius{SI::DIMENSIONS_KELVIN,
                   1.0,
                   CELSIUS_OFFSET,
                   SI::UNIT_SYMBOL_CELSIUS};
const Unit Fahrenheit{SI::DIMENSIONS_KELVIN,
                      UNIT_SCALE_FAHRENHEIT,
                      FAHRENHEIT_OFFSET,
                      SI::UNIT_SYMBOL_FAHRENHEIT};
const Unit Dimensionless{SI::DIMENSIONS_DIMENSIONLESS};
const Unit Percent{SI::DIMENSIONS_DIMENSIONLESS,
                   0.01,
                   0.0,
                   SI::UNIT_SYMBOL_PERCENT};
const Unit Radian{SI::DIMENSIONS_DIMENSIONLESS,
                  1.0,
                  0.0,
                  SI::UNIT_SYMBOL_RADIAN};
/*
 * @brief Get a unit with a specific prefix.
 * @param unit The base unit to apply the prefix to.
 * @param prefix The prefix to apply.
 * @return A shared pointer to the new unit with the specified prefix.
 */
std::shared_ptr<Unit> get_unit_with_prefix(Unit unit, std::string prefix);
/*
 * @brief Get the milli- version of a unit.
 * @param unit The base unit to convert to milli-.
 * @return A shared pointer to the new unit with the milli- prefix.
 */
std::shared_ptr<Unit> get_milli(Unit unit);
/*
 * @brief Get the micro- version of a unit.
 * @param unit The base unit to convert to micro-.
 * @return A shared pointer to the new unit with the micro- prefix.
 */
std::shared_ptr<Unit> get_micro(Unit unit);
/*
 * @brief Get the nano- version of a unit.
 * @param unit The base unit to convert to nano-.
 * @return A shared pointer to the new unit with the nano- prefix.
 */
std::shared_ptr<Unit> get_nano(Unit unit);
/*
 * @brief Get the pico- version of a unit.
 * @param unit The base unit to convert to pico-.
 * @return A shared pointer to the new unit with the pico- prefix.
 */
std::shared_ptr<Unit> get_pico(Unit unit);
/*
 * @brief Get the kilo- version of a unit.
 * @param unit The base unit to convert to kilo-.
 * @return A shared pointer to the new unit with the kilo- prefix.
 */
std::shared_ptr<Unit> get_kilo(Unit unit);
/*
 * @brief Get the mega- version of a unit.
 * @param unit The base unit to convert to mega-.
 * @return A shared pointer to the new unit with the mega- prefix.
 */
std::shared_ptr<Unit> get_mega(Unit unit);
/*
 * @brief Get the giga- version of a unit.
 * @param unit The base unit to convert to giga-.
 * @return A shared pointer to the new unit with the giga- prefix.
 */
std::shared_ptr<Unit> get_giga(Unit unit);
}  // namespace common_units
}  // namespace units
}  // namespace physics
}  // namespace falcon_core
