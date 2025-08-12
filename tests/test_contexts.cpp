#include <gtest/gtest.h>
#include "falcon_core/AcquisitionContext.hpp"
#include "falcon_core/InterpretationContext.hpp"
#include "falcon_core/Axes.hpp"
#include "falcon_core/Domain.hpp"
#include "falcon_core/MeasurementContext.hpp"
#include "falcon_core/BaseConnection.hpp"
#include "falcon_core/SymbolUnit.hpp"
#include "falcon_core/Unit.hpp"
#include <memory>

using namespace falcon_core;

TEST(MeasurementContextTest, ConstructionAndSerialization) {
    auto conn = std::make_shared<BaseConnection>("v_gate_1");
    auto unit = std::make_shared<Unit>(1.0, std::map<std::string, int>{});
    auto symbol_unit = std::make_shared<SymbolUnit>(unit, "V");
    MeasurementContext mc(conn, symbol_unit);

    ASSERT_EQ(mc.connection()->name(), "v_gate_1");
    ASSERT_EQ(mc.unit()->symbol(), "V");

    nlohmann::json j = mc.to_json();
    ASSERT_EQ(j["__module__"], "falcon_core.autotuner_interfaces.contexts.measurement_context");
    ASSERT_EQ(j["__class__"], "MeasurementContext");
}

TEST(AcquisitionContextTest, ConstructionAndSerialization) {
    AcquisitionContext ac;
    nlohmann::json j = ac.to_json();
    ASSERT_EQ(j["__module__"], "falcon_core.autotuner_interfaces.contexts.acquisition_context");
    ASSERT_EQ(j["__class__"], "AcquisitionContext");
}

TEST(InterpretationContextTest, ConstructionAndSerialization) {
    auto d1 = std::make_shared<Domain>(0, 1);
    auto axes = std::make_shared<Axes<Domain>>();
    axes->append(d1);

    InterpretationContext ic(axes);
    nlohmann::json j = ic.to_json();
    ASSERT_EQ(j["__module__"], "falcon_core.autotuner_interfaces.interpretations.interpretation_context");
    ASSERT_EQ(j["__class__"], "InterpretationContext");
    ASSERT_TRUE(j.contains("_independent_variables"));
}
