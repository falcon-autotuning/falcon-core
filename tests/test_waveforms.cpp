#include <gtest/gtest.h>
#include "falcon_core/BaseDiscretizer.hpp"
#include "falcon_core/Spaces.hpp"
#include "falcon_core/Waveform.hpp"
#include "falcon_core/Domain.hpp"
#include "falcon_core/ControlArray.hpp"
#include "falcon_core/MeasuredArray.hpp"
#include "falcon_core/Axes.hpp"
#include "falcon_core/MeasurementContext.hpp"
#include "falcon_core/BaseConnection.hpp"
#include "falcon_core/SymbolUnit.hpp"
#include "falcon_core/Unit.hpp"
#include <memory>
#include <Eigen/Dense>

using namespace falcon_core;

TEST(BaseDiscretizerTest, ConstructionAndAccessors) {
    auto domain = std::make_shared<Domain>(0.1, 1.0);
    BaseDiscretizer bd(0.5, domain);

    ASSERT_DOUBLE_EQ(bd.delta(), 0.5);
    ASSERT_EQ(bd.delta_domain(), domain);

    bd.set_delta(0.6);
    ASSERT_DOUBLE_EQ(bd.delta(), 0.6);
}

TEST(SpacesTest, AppendAndAccess) {
    auto conn = std::make_shared<BaseConnection>("v_gate_1");
    auto unit = std::make_shared<Unit>(1.0, std::map<std::string, int>{});
    auto symbol_unit = std::make_shared<SymbolUnit>(unit, "V");
    auto mc = std::make_shared<MeasurementContext>(conn, symbol_unit);
    
    auto axes = std::make_shared<Axes<MeasurementContext>>();
    axes->append(mc);

    Spaces spaces;
    spaces.append(axes);

    ASSERT_EQ(spaces.get_spaces().size(), 1);
    ASSERT_EQ(spaces.get_spaces()[0], axes);
}

TEST(WaveformTest, Construction) {
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> control_data(1, 2);
    control_data << 1.0, 2.0;
    auto control_array = std::make_shared<ControlArray<double>>(control_data);

    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> measured_data(1, 2);
    measured_data << 3.0, 4.0;
    auto measured_array = std::make_shared<MeasuredArray<double>>(measured_data);

    auto spaces = std::make_shared<Spaces>();

    Waveform waveform(control_array, measured_array, spaces);

    nlohmann::json j = waveform.to_json();
    ASSERT_EQ(j["__module__"], "falcon_core.math.waveform.waveform");
    ASSERT_EQ(j["__class__"], "Waveform");
    ASSERT_TRUE(j.contains("_control_array"));
    ASSERT_TRUE(j.contains("_measured_array"));
    ASSERT_TRUE(j.contains("_spaces"));
}

#include "falcon_core/CartesianDiscretizer.hpp"

TEST(CartesianDiscretizerTest, Construction) {
    auto domain = std::make_shared<Domain>(0.0, 1.0);
    CartesianDiscretizer cd(0.1, domain);
    nlohmann::json j = cd.to_json();
    ASSERT_EQ(j["__class__"], "CartesianDiscretizer");
}
