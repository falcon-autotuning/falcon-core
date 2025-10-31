#include <memory>
#include <string>
#include <vector>

#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext.hpp"
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp"
#include "falcon_core/generic/List.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentTypes.hpp"
#include "falcon_core/math/Axes.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"
#include "gtest/gtest.h"

using namespace falcon_core;
using namespace falcon_core::autotuner_interfaces::interpretations;
using namespace falcon_core::autotuner_interfaces::contexts;
using namespace falcon_core::generic;
using namespace falcon_core::physics::units;
using namespace falcon_core::math;
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::instrument_interfaces::names;

TEST(InterpretationContextTest, JsonSerializeDeserialize) {
  // Build valid MeasurementContext instances (non-null)
  auto       conn1 = Connection::PlungerGate("ind_conn");
  auto       conn2 = Connection::PlungerGate("dep_conn");
  Instrument instr = InstrumentTypes::VOLTAGE_SOURCE;

  auto m_ind = std::make_shared<MeasurementContext>(conn1, instr);
  auto m_dep = std::make_shared<MeasurementContext>(conn2, instr);

  // independent: an Axes with one MeasurementContext
  std::vector<std::shared_ptr<MeasurementContext>> indep_items{m_ind};
  auto independent = std::make_shared<Axes<MeasurementContext>>(indep_items);

  // dependent: a List with one MeasurementContext
  auto dependent = std::make_shared<List<MeasurementContext>>();
  dependent->push_back(m_dep);

  // unit must be non-null; construct with a UnitSP
  auto unit = std::make_shared<SymbolUnit>(Unit::Meter());

  InterpretationContext ctx(independent, dependent, unit);

  // exercise JSONOutputArchive instantiation via Song::to_json_string()
  std::string json = ctx.to_json_string();
  ASSERT_FALSE(json.empty());

  // exercise JSONInputArchive instantiation via Song::from_json_string
  auto other =
      InterpretationContext::from_json_string<InterpretationContext>(json);
  ASSERT_NE(other, nullptr);
  EXPECT_NE(other->unit(), nullptr);

  // Basic round-trip property checks
  EXPECT_EQ(other->dimension(), ctx.dimension());
  EXPECT_EQ(other->dependent_variables()->size(),
            ctx.dependent_variables()->size());
}

// New test that registers polymorphic types for cereal and uses ASSERT_NO_THROW
// to ensure exceptions are surfaced (so coverage records the JSON archive
// instantiations).
#include <cereal/types/memory.hpp>
#include <cereal/types/polymorphic.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/vector.hpp>

TEST(InterpretationContextTest,
     JsonSerializeDeserialize_WithCerealRegistration) {
  // Build valid MeasurementContext instances (non-null)
  auto       conn1 = Connection::PlungerGate("ind_conn");
  auto       conn2 = Connection::PlungerGate("dep_conn");
  Instrument instr = InstrumentTypes::VOLTAGE_SOURCE;

  auto m_ind = std::make_shared<MeasurementContext>(conn1, instr);
  auto m_dep = std::make_shared<MeasurementContext>(conn2, instr);

  // independent: an Axes with one MeasurementContext
  std::vector<std::shared_ptr<MeasurementContext>> indep_items{m_ind};
  auto independent = std::make_shared<Axes<MeasurementContext>>(indep_items);

  // dependent: a List with one MeasurementContext
  auto dependent = std::make_shared<List<MeasurementContext>>();
  dependent->push_back(m_dep);

  // unit must be non-null; construct with a UnitSP
  auto unit = std::make_shared<SymbolUnit>(Unit::Meter());

  InterpretationContext ctx(independent, dependent, unit);

  // exercise JSONOutputArchive instantiation via Song::to_json_string()
  std::string json;
  ASSERT_NO_THROW(json = ctx.to_json_string());
  ASSERT_FALSE(json.empty());

  // exercise JSONInputArchive instantiation via Song::from_json_string
  std::shared_ptr<InterpretationContext> other;
  ASSERT_NO_THROW(
      other =
          InterpretationContext::from_json_string<InterpretationContext>(json));
  ASSERT_NE(other, nullptr);
  EXPECT_NE(other->unit(), nullptr);

  // Basic round-trip property checks
  EXPECT_EQ(other->dimension(), ctx.dimension());
  EXPECT_EQ(other->dependent_variables()->size(),
            ctx.dependent_variables()->size());
}
