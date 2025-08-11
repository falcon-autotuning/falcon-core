#include <gtest/gtest.h>
#include "falcon_core/Unit.hpp"
#include "falcon_core/SymbolUnit.hpp"

using namespace falcon_core;

TEST(UnitTest, Compatibility) {
    Dimension dim_len({{BaseDimension::LENGTH, 1}});
    Dimension dim_time({{BaseDimension::TIME, 1}});

    Unit meter(1.0, dim_len);
    Unit second(1.0, dim_time);
    Unit kilometer(1000.0, dim_len);

    ASSERT_TRUE(meter.is_compatible(kilometer));
    ASSERT_FALSE(meter.is_compatible(second));
}

TEST(UnitTest, Conversion) {
    Dimension dim_len({{BaseDimension::LENGTH, 1}});
    Unit meter(1.0, dim_len);
    Unit kilometer(1000.0, dim_len);
    
    ASSERT_DOUBLE_EQ(meter.get_conversion_factor(kilometer), 0.001);
    ASSERT_DOUBLE_EQ(kilometer.get_conversion_factor(meter), 1000.0);
    ASSERT_DOUBLE_EQ(meter.convert_value_to(5000, kilometer), 5.0);
    ASSERT_DOUBLE_EQ(kilometer.convert_value_to(2.5, meter), 2500.0);
}

TEST(SymbolUnitTest, WithPrefix) {
    Dimension dim_len({{BaseDimension::LENGTH, 1}});
    auto meter_unit = std::make_shared<Unit>(1.0, dim_len);
    SymbolUnit meter(meter_unit, "m");

    auto km = meter.with_prefix("k");
    ASSERT_EQ(km->symbol(), "km");
    ASSERT_TRUE(km->unit()->is_compatible(*meter_unit));
    ASSERT_DOUBLE_EQ(km->unit()->scale(), 1000.0);
}
