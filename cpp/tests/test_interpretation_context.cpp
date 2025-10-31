#include <cereal/types/memory.hpp>
#include <cereal/types/polymorphic.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/vector.hpp>
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

CEREAL_REGISTER_TYPE(
    falcon_core::autotuner_interfaces::contexts::MeasurementContext)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::autotuner_interfaces::contexts::MeasurementContext)

CEREAL_REGISTER_TYPE(
    falcon_core::math::Axes<
        falcon_core::autotuner_interfaces::contexts::MeasurementContext>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::Axes<
        falcon_core::autotuner_interfaces::contexts::MeasurementContext>)

CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<
        falcon_core::autotuner_interfaces::contexts::MeasurementContext>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::generic::List<
        falcon_core::autotuner_interfaces::contexts::MeasurementContext>)

TEST(InterpretationContextTest, JsonSerializeDeserialize) {
  auto       conn1 = Connection::PlungerGate("ind_conn");
  auto       conn2 = Connection::PlungerGate("dep_conn");
  Instrument instr = InstrumentTypes::VOLTAGE_SOURCE;

  auto m_ind = std::make_shared<MeasurementContext>(conn1, instr);
  auto m_dep = std::make_shared<MeasurementContext>(conn2, instr);

  std::vector<std::shared_ptr<MeasurementContext>> indep_items{m_ind};
  auto independent = std::make_shared<Axes<MeasurementContext>>(indep_items);

  auto dependent = std::make_shared<List<MeasurementContext>>();
  dependent->push_back(m_dep);

  auto unit = std::make_shared<SymbolUnit>(Unit::Meter());

  InterpretationContext ctx(independent, dependent, unit);

  std::string json = ctx.to_json_string();
  ASSERT_FALSE(json.empty());

  auto other =
      InterpretationContext::from_json_string<InterpretationContext>(json);
  ASSERT_NE(other, nullptr);
  EXPECT_NE(other->unit(), nullptr);

  EXPECT_EQ(other->dimension(), ctx.dimension());
  EXPECT_EQ(other->dependent_variables()->size(),
            ctx.dependent_variables()->size());
}

TEST(InterpretationContextTest,
     JsonSerializeDeserialize_WithCerealRegistration) {
  auto       conn1 = Connection::PlungerGate("ind_conn");
  auto       conn2 = Connection::PlungerGate("dep_conn");
  Instrument instr = InstrumentTypes::VOLTAGE_SOURCE;

  auto m_ind = std::make_shared<MeasurementContext>(conn1, instr);
  auto m_dep = std::make_shared<MeasurementContext>(conn2, instr);

  std::vector<std::shared_ptr<MeasurementContext>> indep_items{m_ind};
  auto independent = std::make_shared<Axes<MeasurementContext>>(indep_items);

  auto dependent = std::make_shared<List<MeasurementContext>>();
  dependent->push_back(m_dep);

  auto unit = std::make_shared<SymbolUnit>(Unit::Meter());

  InterpretationContext ctx(independent, dependent, unit);

  std::string json;
  ASSERT_NO_THROW(json = ctx.to_json_string());
  ASSERT_FALSE(json.empty());

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

TEST(InterpretationContextTest, BehaviorOperations) {
  auto       conn1 = Connection::PlungerGate("ind_conn");
  auto       conn2 = Connection::PlungerGate("dep_conn");
  Instrument instr = InstrumentTypes::VOLTAGE_SOURCE;

  auto m_ind = std::make_shared<MeasurementContext>(conn1, instr);
  auto m_dep = std::make_shared<MeasurementContext>(conn2, instr);

  std::vector<std::shared_ptr<MeasurementContext>> indep_items{m_ind};
  auto independent = std::make_shared<Axes<MeasurementContext>>(indep_items);

  auto dependent = std::make_shared<List<MeasurementContext>>();
  dependent->push_back(m_dep);

  auto unit = std::make_shared<SymbolUnit>(Unit::Meter());

  InterpretationContext ctx(independent, dependent, unit);

  EXPECT_EQ(ctx.dimension(), static_cast<int>(independent->size()));

  auto got = ctx.get_independent_variable(0);
  ASSERT_NE(got, nullptr);
  EXPECT_EQ(got->instrument_type(), m_ind->instrument_type());

  ASSERT_THROW(ctx.get_independent_variable(-1), std::out_of_range);
  ASSERT_THROW(ctx.get_independent_variable(ctx.dimension()),
               std::out_of_range);

  size_t before = ctx.dependent_variables()->size();
  ctx.add_dependent_variable(m_ind);
  EXPECT_EQ(ctx.dependent_variables()->size(), before + 1);

  ctx.replace_dependent_variable(0, m_ind);
  EXPECT_EQ(ctx.dependent_variables()->size(), before + 1);

  ASSERT_THROW(ctx.replace_dependent_variable(100, m_ind), std::out_of_range);

  auto new_unit = std::make_shared<SymbolUnit>(Unit::Kilogram());
  auto new_ctx  = ctx.with_unit(new_unit);
  ASSERT_NE(new_ctx, nullptr);
  EXPECT_EQ(new_ctx->unit(), new_unit);
  EXPECT_NE(ctx.unit(), new_unit);
}
