#include <memory>
#include <string>
#include <vector>

#include <cereal/types/memory.hpp>
#include <cereal/types/polymorphic.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/vector.hpp>

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

// Register polymorphic Song-derived types that appear inside
// InterpretationContext so cereal can (de)serialize them via shared_ptr<Song).
CEREAL_REGISTER_TYPE(falcon_core::autotuner_interfaces::contexts::MeasurementContext)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::autotuner_interfaces::contexts::MeasurementContext)

CEREAL_REGISTER_TYPE(
    falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>)

CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>)

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

// Additional behavior tests to increase coverage of simple methods.
TEST(InterpretationContextTest, BehaviorOperations) {
  auto conn1 = Connection::PlungerGate("ind_conn");
  auto conn2 = Connection::PlungerGate("dep_conn");
  Instrument instr = InstrumentTypes::VOLTAGE_SOURCE;

  auto m_ind = std::make_shared<MeasurementContext>(conn1, instr);
  auto m_dep = std::make_shared<MeasurementContext>(conn2, instr);

  std::vector<std::shared_ptr<MeasurementContext>> indep_items{m_ind};
  auto independent = std::make_shared<Axes<MeasurementContext>>(indep_items);

  auto dependent = std::make_shared<List<MeasurementContext>>();
  dependent->push_back(m_dep);

  auto unit = std::make_shared<SymbolUnit>(Unit::Meter());

  InterpretationContext ctx(independent, dependent, unit);

  // dimension() should equal independent size
  EXPECT_EQ(ctx.dimension(), static_cast<int>(independent->size()));

  // add_dependent_variable increases dependent size
  size_t before = ctx.dependent_variables()->size();
  ctx.add_dependent_variable(m_ind);
  EXPECT_EQ(ctx.dependent_variables()->size(), before + 1);

  // replace_dependent_variable replaces element at index 0
  ctx.replace_dependent_variable(0, m_ind);
  EXPECT_EQ(ctx.dependent_variables()->size(), before + 1);

  // replace_dependent_variable throws when out of range
  ASSERT_THROW(ctx.replace_dependent_variable(100, m_ind), std::out_of_range);

  // with_unit returns new InterpretationContext with changed unit
  auto new_unit = std::make_shared<SymbolUnit>(Unit::Kilogram());
  auto new_ctx = ctx.with_unit(new_unit);
  ASSERT_NE(new_ctx, nullptr);
  EXPECT_EQ(new_ctx->unit(), new_unit);
  // original unchanged
  EXPECT_NE(ctx.unit(), new_unit);
}
