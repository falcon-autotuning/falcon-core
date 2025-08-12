#include <gtest/gtest.h>
#include "falcon_core/Dimension.hpp"

using namespace falcon_core;

TEST(DimensionTest, IsDimensionless) {
    Dimension d_len({ {BaseDimension::LENGTH, 1} });
    ASSERT_FALSE(d_len.is_dimensionless());

    Dimension d_none({ {BaseDimension::LENGTH, 0} });
    ASSERT_TRUE(d_none.is_dimensionless());
}

TEST(DimensionTest, Multiplication) {
    Dimension d_len({ {BaseDimension::LENGTH, 1} });
    Dimension d_time({ {BaseDimension::TIME, -1} });
    Dimension d_vel = d_len * d_time;

    auto dims = d_vel.get_dimensions();
    ASSERT_EQ(dims.at(BaseDimension::LENGTH), 1);
    ASSERT_EQ(dims.at(BaseDimension::TIME), -1);
}
