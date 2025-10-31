#include "gtest/gtest.h"

#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp"
#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext.hpp"
#include "falcon_core/generic/List.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"
#include "falcon_core/math/Axes.hpp"

#include <memory>
#include <string>

using namespace falcon_core;
using namespace falcon_core::autotuner_interfaces::interpretations;
using namespace falcon_core::autotuner_interfaces::contexts;
using namespace falcon_core::generic;
using namespace falcon_core::physics::units;
using namespace falcon_core::math;

TEST(InterpretationContextTest, JsonSerializeDeserialize) {
  // independent can be null (empty shared_ptr)
  AxesSP<MeasurementContext> independent;  // nullptr
  // dependent is an empty list
  auto dependent = std::make_shared<List<MeasurementContext>>();
  // unit must be non-null to exercise unit serialization
  // SymbolUnit has a protected default ctor; construct with a UnitSP instead
  auto unit = std::make_shared<SymbolUnit>(Unit::Meter());

  InterpretationContext ctx(independent, dependent, unit);

  // exercise JSONOutputArchive instantiation via Song::to_json_string()
  std::string json = ctx.to_json_string();
  ASSERT_FALSE(json.empty());

  // exercise JSONInputArchive instantiation via Song::from_json_string()
  auto other =
      InterpretationContext::from_json_string<InterpretationContext>(json);
  ASSERT_NE(other, nullptr);
  EXPECT_NE(other->unit(), nullptr);

  // Basic round-trip property checks
  EXPECT_EQ(other->dimension(), ctx.dimension());
  EXPECT_EQ(other->dependent_variables()->size(),
            ctx.dependent_variables()->size());
}
