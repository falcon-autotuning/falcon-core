#include <gtest/gtest.h>
#include <memory>
#include <string>

#include "falcon_core/math/discrete_spaces/BaseDiscreteSpace.hpp"
#include "falcon_core/math/discrete_spaces/DiscreteSpace.hpp"
#include "falcon_core/math/discrete_spaces/BaseCartesianDiscreteSpace.hpp"
#include "falcon_core/math/discrete_spaces/CartesianDiscreteSpace.hpp"
#include "falcon_core/math/discrete_spaces/CartesianDiscreteSpace1D.hpp"
#include "falcon_core/math/discrete_spaces/CartesianDiscreteSpace2D.hpp"
#include "falcon_core/math/domains/CoupledKnobDomain.hpp"
#include "falcon_core/math/domains/Domain.hpp"
#include "falcon_core/math/spaces/UnitSpace.hpp"
#include "falcon_core/math/spaces/CartesianSpace.hpp"
#include "falcon_core/math/spaces/Cartesian1DSpace.hpp"
#include "falcon_core/math/spaces/Cartesian2DSpace.hpp"
#include "falcon_core/math/Axes.hpp"

using namespace falcon_core::math::discrete_spaces;
using namespace falcon_core::math::domains;
using namespace falcon_core::math::spaces;

// Helper to create a dummy CoupledKnobDomain
std::shared_ptr<CoupledKnobDomain> make_knob_domain(double min, double max) {
    // You may need to adjust the constructor arguments for your actual CoupledKnobDomain
    return std::make_shared<CoupledKnobDomain>(min, max, nullptr, nullptr);
}

TEST(DiscreteSpacesTest, BaseDiscreteSpaceBasicFunctionality) {
    auto domain = std::make_shared<Domain>(0.0, 1.0);
    auto space = std::make_shared<UnitSpace>(Axes<discretizers::BaseDiscretizer>{}, domain);
    auto axes = std::make_shared<Axes<CoupledKnobDomain>>(std::vector<std::shared_ptr<CoupledKnobDomain>>{make_knob_domain(0.0, 1.0)});
    auto ds = std::make_shared<BaseDiscreteSpace>(space, axes);

    EXPECT_EQ(ds->space(), space);
    EXPECT_EQ(ds->axes(), axes);
}

TEST(DiscreteSpacesTest, BaseDiscreteSpaceSerializationRoundTrip) {
    auto domain = std::make_shared<Domain>(0.0, 1.0);
    auto space = std::make_shared<UnitSpace>(Axes<discretizers::BaseDiscretizer>{}, domain);
    auto axes = std::make_shared<Axes<CoupledKnobDomain>>(std::vector<std::shared_ptr<CoupledKnobDomain>>{make_knob_domain(0.0, 1.0)});
    auto ds = std::make_shared<BaseDiscreteSpace>(space, axes);

    std::string json = ds->to_json_string();
    auto ds2 = BaseDiscreteSpace::from_json_string<BaseDiscreteSpace>(json);

    ASSERT_NE(ds2, nullptr);
    EXPECT_EQ(ds2->axes()->size(), 1);
}

TEST(DiscreteSpacesTest, DiscreteSpaceBasicFunctionality) {
    auto domain = std::make_shared<Domain>(0.0, 1.0);
    auto space = std::make_shared<UnitSpace>(Axes<discretizers::BaseDiscretizer>{}, domain);
    auto axes = std::make_shared<Axes<CoupledKnobDomain>>(std::vector<std::shared_ptr<CoupledKnobDomain>>{make_knob_domain(0.0, 1.0)});
    auto ds = std::make_shared<DiscreteSpace>(space, axes);

    EXPECT_EQ(ds->space(), space);
    EXPECT_EQ(ds->axes(), axes);
}

TEST(DiscreteSpacesTest, DiscreteSpaceSerializationRoundTrip) {
    auto domain = std::make_shared<Domain>(0.0, 1.0);
    auto space = std::make_shared<UnitSpace>(Axes<discretizers::BaseDiscretizer>{}, domain);
    auto axes = std::make_shared<Axes<CoupledKnobDomain>>(std::vector<std::shared_ptr<CoupledKnobDomain>>{make_knob_domain(0.0, 1.0)});
    auto ds = std::make_shared<DiscreteSpace>(space, axes);

    std::string json = ds->to_json_string();
    auto ds2 = DiscreteSpace::from_json_string<DiscreteSpace>(json);

    ASSERT_NE(ds2, nullptr);
    EXPECT_EQ(ds2->axes()->size(), 1);
}

TEST(DiscreteSpacesTest, CartesianDiscreteSpaceBasicFunctionality) {
    auto domain = std::make_shared<Domain>(-1.0, 1.0);
    std::vector<double> deltas{0.1, 0.2};
    auto space = std::make_shared<CartesianSpace>(deltas, domain);
    auto axes = std::make_shared<Axes<CoupledKnobDomain>>(std::vector<std::shared_ptr<CoupledKnobDomain>>{
        make_knob_domain(-1.0, 1.0), make_knob_domain(-1.0, 1.0)});
    auto ds = std::make_shared<CartesianDiscreteSpace>(space, axes);

    EXPECT_EQ(ds->space(), space);
    EXPECT_EQ(ds->axes(), axes);
}

TEST(DiscreteSpacesTest, CartesianDiscreteSpaceSerializationRoundTrip) {
    auto domain = std::make_shared<Domain>(-1.0, 1.0);
    std::vector<double> deltas{0.1, 0.2};
    auto space = std::make_shared<CartesianSpace>(deltas, domain);
    auto axes = std::make_shared<Axes<CoupledKnobDomain>>(std::vector<std::shared_ptr<CoupledKnobDomain>>{
        make_knob_domain(-1.0, 1.0), make_knob_domain(-1.0, 1.0)});
    auto ds = std::make_shared<CartesianDiscreteSpace>(space, axes);

    std::string json = ds->to_json_string();
    auto ds2 = CartesianDiscreteSpace::from_json_string<CartesianDiscreteSpace>(json);

    ASSERT_NE(ds2, nullptr);
    EXPECT_EQ(ds2->axes()->size(), 2);
}

TEST(DiscreteSpacesTest, CartesianDiscreteSpace1DBasicFunctionality) {
    auto domain = std::make_shared<Domain>(0.0, 2.0);
    auto space = std::make_shared<Cartesian1DSpace>(0.5, domain);
    auto axes = std::make_shared<Axes<CoupledKnobDomain>>(std::vector<std::shared_ptr<CoupledKnobDomain>>{make_knob_domain(0.0, 2.0)});
    auto ds = std::make_shared<CartesianDiscreteSpace1D>(space, axes);

    EXPECT_EQ(ds->space(), space);
    EXPECT_EQ(ds->axes(), axes);
}

TEST(DiscreteSpacesTest, CartesianDiscreteSpace1DSerializationRoundTrip) {
    auto domain = std::make_shared<Domain>(0.0, 2.0);
    auto space = std::make_shared<Cartesian1DSpace>(0.5, domain);
    auto axes = std::make_shared<Axes<CoupledKnobDomain>>(std::vector<std::shared_ptr<CoupledKnobDomain>>{make_knob_domain(0.0, 2.0)});
    auto ds = std::make_shared<CartesianDiscreteSpace1D>(space, axes);

    std::string json = ds->to_json_string();
    auto ds2 = CartesianDiscreteSpace1D::from_json_string<CartesianDiscreteSpace1D>(json);

    ASSERT_NE(ds2, nullptr);
    EXPECT_EQ(ds2->axes()->size(), 1);
}

TEST(DiscreteSpacesTest, CartesianDiscreteSpace2DBasicFunctionality) {
    auto domain = std::make_shared<Domain>(-2.0, 2.0);
    std::vector<double> deltas{0.1, 0.2};
    auto space = std::make_shared<Cartesian2DSpace>(deltas, domain);
    auto axes = std::make_shared<Axes<CoupledKnobDomain>>(std::vector<std::shared_ptr<CoupledKnobDomain>>{
        make_knob_domain(-2.0, 2.0), make_knob_domain(-2.0, 2.0)});
    auto ds = std::make_shared<CartesianDiscreteSpace2D>(space, axes);

    EXPECT_EQ(ds->space(), space);
    EXPECT_EQ(ds->axes(), axes);
}

TEST(DiscreteSpacesTest, CartesianDiscreteSpace2DSerializationRoundTrip) {
    auto domain = std::make_shared<Domain>(-2.0, 2.0);
    std::vector<double> deltas{0.1, 0.2};
    auto space = std::make_shared<Cartesian2DSpace>(deltas, domain);
    auto axes = std::make_shared<Axes<CoupledKnobDomain>>(std::vector<std::shared_ptr<CoupledKnobDomain>>{
        make_knob_domain(-2.0, 2.0), make_knob_domain(-2.0, 2.0)});
    auto ds = std::make_shared<CartesianDiscreteSpace2D>(space, axes);

    std::string json = ds->to_json_string();
    auto ds2 = CartesianDiscreteSpace2D::from_json_string<CartesianDiscreteSpace2D>(json);

    ASSERT_NE(ds2, nullptr);
    EXPECT_EQ(ds2->axes()->size(), 2);
}
