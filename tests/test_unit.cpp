#include <gtest/gtest.h>
#include "falcon_core/Unit.hpp"
#include "falcon_core/SymbolUnit.hpp"

using namespace falcon_core;

TEST(UnitTest, Conversion) {
    // Dimension dim_len({ {BaseDimension::LENGTH, 1} });
    // Unit meter(1.0, dim_len);
    // Unit kilometer(1000.0, dim_len);

    // ASSERT_DOUBLE_EQ(kilometer.get_conversion_factor(meter), 1000.0);
    // ASSERT_DOUBLE_EQ(meter.get_conversion_factor(kilometer), 0.001);

    // Dimension dim_time({ {BaseDimension::TIME, 1} });
    // Unit second(1.0, dim_time);

    // ASSERT_THROW(meter.get_conversion_factor(second), std::runtime_error);
}

TEST(SymbolUnitTest, Prefix) {
    // Dimension dim_len({ {BaseDimension::LENGTH, 1} });
    // auto meter_ptr = std::make_shared<Unit>(1.0, dim_len);
    // SymbolUnit meter(meter_ptr, "m");

    // SymbolUnit km = meter.with_prefix("k");
    // ASSERT_EQ(km.symbol(), "km");

    // auto m_unit = meter.unit();
    // auto km_unit = km.unit();
    // ASSERT_DOUBLE_EQ(km_unit->get_conversion_factor(*m_unit), 1000.0);
}
