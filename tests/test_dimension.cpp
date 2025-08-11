#include <gtest/gtest.h>
#include "falcon_core/Dimension.hpp"

using namespace falcon_core;

TEST(DimensionTest, IsDimensionless) {
    Dimension d1;
    ASSERT_TRUE(d1.is_dimensionless());

    Dimension d2({{BaseDimension::LENGTH, 1}});
    ASSERT_FALSE(d2.is_dimensionless());
}

TEST(DimensionTest, Compatibility) {
    Dimension d_len({{BaseDimension::LENGTH, 1}});
    Dimension d_time({{BaseDimension::TIME, 1}});
    Dimension d_len2({{BaseDimension::LENGTH, 1}});

    ASSERT_TRUE(d_len.is_compatible(d_len2));
    ASSERT_FALSE(d_len.is_compatible(d_time));
}

TEST(DimensionTest, Multiplication) {
    Dimension d_len({{BaseDimension::LENGTH, 1}});
    Dimension d_time_inv({{BaseDimension::TIME, -1}});
    Dimension d_speed = d_len * d_time_inv;

    Dimension d_speed_expected({{BaseDimension::LENGTH, 1}, {BaseDimension::TIME, -1}});
    ASSERT_TRUE(d_speed.is_compatible(d_speed_expected));
}

TEST(DimensionTest, Division) {
    Dimension d_len({{BaseDimension::LENGTH, 1}});
    Dimension d_time({{BaseDimension::TIME, 1}});
    Dimension d_speed = d_len / d_time;

    Dimension d_speed_expected({{BaseDimension::LENGTH, 1}, {BaseDimension::TIME, -1}});
    ASSERT_TRUE(d_speed.is_compatible(d_speed_expected));
}

TEST(DimensionTest, Power) {
    Dimension d_len({{BaseDimension::LENGTH, 1}});
    Dimension d_area = d_len.pow(2);

    Dimension d_area_expected({{BaseDimension::LENGTH, 2}});
    ASSERT_TRUE(d_area.is_compatible(d_area_expected));
}
