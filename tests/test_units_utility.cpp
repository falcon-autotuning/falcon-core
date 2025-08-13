#include "falcon_core/SymbolUnit.hpp"
#include "falcon_core/Units.hpp"
#include "falcon_core/physics/units/Unit.hpp"

#include <gtest/gtest.h>

using namespace falcon_core;

// TEST (UnitsUtilityTest, GetVoltage)
// {
//   auto v = Units::V ();
//   ASSERT_EQ (v->symbol (), "V");
//   ASSERT_EQ (v->unit ()->get_factor (), 1.0);
//   const auto &dims = v->unit ()->dimensions ();
//   ASSERT_EQ (dims.at ("MASS"), 1);
//   ASSERT_EQ (dims.at ("LENGTH"), 2);
//   ASSERT_EQ (dims.at ("TIME"), -3);
//   ASSERT_EQ (dims.at ("CURRENT"), -1);
// }
//
// TEST (UnitsUtilityTest, GetDimensionless)
// {
//   auto dimensionless = Units::dimensionless ();
//   ASSERT_EQ (dimensionless->symbol (), "");
//   ASSERT_TRUE (dimensionless->unit ()->dimensions ().empty ());
// }
