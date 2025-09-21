#include <gtest/gtest.h>

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/math/Axes.hpp"
#include "falcon_core/math/discrete_spaces/CartesianDiscreteSpace.hpp"
#include "falcon_core/math/discrete_spaces/CartesianDiscreteSpace1D.hpp"
#include "falcon_core/math/discrete_spaces/CartesianDiscreteSpace2D.hpp"
#include "falcon_core/math/discrete_spaces/DiscreteSpace.hpp"
#include "falcon_core/math/discrete_spaces/Discretizer.hpp"
#include "falcon_core/math/domains/CoupledLabelledDomain.hpp"
#include "falcon_core/math/domains/LabelledDomain.hpp"
#include "falcon_core/math/spaces/Cartesian1DSpace.hpp"
#include "falcon_core/math/spaces/Cartesian2DSpace.hpp"
#include "falcon_core/math/spaces/CartesianSpace.hpp"
#include "xtensor/reducers/xreducer.hpp"
namespace tests {
using namespace falcon_core;
using namespace falcon_core::math;
using namespace discrete_spaces;
using namespace domains;
using namespace spaces;

CoupledLabelledDomainSP make_coupled_domain(double min, double max) {
  return std::make_shared<CoupledLabelledDomain>(
      std::vector({LabelledDomain::from_port_and_domain(
          nullptr, std::make_shared<Domain>(min, max))}));
}

class DiscreteSpaces1DTestFixture : public ::testing::Test {
 protected:
  DomainSP                                domain;
  UnitSpaceSP                             space;
  AxesSP<CoupledLabelledDomain>           axes;
  AxesSP<generic::Map<std::string, bool>> increasing;
  generic::MapSP<std::string, bool>       dim1;
  std::shared_ptr<BaseDiscreteSpace>      ds;

  void SetUp() override {
    domain = std::make_shared<Domain>(0.0, 1.0);
    space  = std::make_shared<UnitSpace>(
        std::make_shared<Axes<discrete_spaces::Discretizer>>(), domain);
    axes = std::make_shared<Axes<CoupledLabelledDomain>>(
        std::vector<std::shared_ptr<CoupledLabelledDomain>>{
            make_coupled_domain(0.0, 1.0)});
    increasing = std::make_shared<Axes<generic::Map<std::string, bool>>>();
    dim1       = std::make_shared<generic::Map<std::string, bool>>();
    dim1->insert("", true);
    increasing->push_back(dim1);
    ds = std::make_shared<BaseDiscreteSpace>(space, axes, increasing);
  }
};
class CartesianSpaces1DTestFixture : public ::testing::Test {
 protected:
  DomainSP                                domain;
  UnitSpaceSP                             space;
  AxesSP<CoupledLabelledDomain>           axes;
  AxesSP<generic::Map<std::string, bool>> increasing;
  generic::MapSP<std::string, bool>       dim1;
  std::shared_ptr<BaseDiscreteSpace>      ds;

  void SetUp() override {
    domain = std::make_shared<Domain>(0.0, 2.0);
    space  = std::make_shared<Cartesian1DSpace>(0.5, domain);
    AxesSP<CoupledLabelledDomain> axes;
    axes->push_back(
        std::make_shared<CoupledLabelledDomain>(std::vector<LabelledDomainSP>{
            LabelledDomain::from_port_and_domain(nullptr, domain)}));
    increasing = std::make_shared<Axes<generic::Map<std::string, bool>>>();
    dim1       = std::make_shared<generic::Map<std::string, bool>>();
    dim1->insert("", true);
    increasing->push_back(dim1);
    ds = std::make_shared<BaseDiscreteSpace>(space, axes, increasing);
  }
};
class CartesianDiscreteSpaces2DTestFixture : public ::testing::Test {
 protected:
  std::shared_ptr<Domain>                        domain;
  std::shared_ptr<Cartesian2DSpace>              space;
  std::shared_ptr<Axes<CoupledLabelledDomain>>   axes;
  std::shared_ptr<CartesianDiscreteSpace2D>      ds;
  AxesSP<generic::Map<std::string, bool>>        increasing;
  generic::MapSP<std::string, bool>              dim1;
  generic::MapSP<std::string, bool>              dim2;
  instrument_interfaces::names::InstrumentPortSP knob1;
  instrument_interfaces::names::InstrumentPortSP knob2;

  void SetUp() override {
    domain = std::make_shared<Domain>(-1.0, 1.0);
    std::vector<double> deltas{0.1, 0.2};
    space = std::make_shared<Cartesian2DSpace>(deltas, domain);
    instrument_interfaces::names::InstrumentPortSP knob1 =
        instrument_interfaces::names::InstrumentPort::Knob(
            "x0", nullptr, "clock", nullptr, "desc");
    instrument_interfaces::names::InstrumentPortSP knob2 =
        instrument_interfaces::names::InstrumentPort::Knob(
            "x1", nullptr, "clock", nullptr, "desc");
    LabelledDomainSP kd1 =
        LabelledDomain::from_port(std::make_pair(0.0, 1.0), knob1);
    LabelledDomainSP kd2 =
        LabelledDomain::from_port(std::make_pair(0.0, 1.0), knob2);
    std::vector<LabelledDomainSP> domains = std::vector{kd1, kd2};
    CoupledLabelledDomainSP       coupled_domains =
        std::make_shared<CoupledLabelledDomain>(std::vector{domains});
    AxesSP<CoupledLabelledDomain> axes_coupled =
        std::make_shared<Axes<CoupledLabelledDomain>>(
            std::vector{coupled_domains});
    increasing = std::make_shared<Axes<generic::Map<std::string, bool>>>();
    dim1       = std::make_shared<generic::Map<std::string, bool>>();
    dim1->insert("", true);
    dim2 = std::make_shared<generic::Map<std::string, bool>>();
    dim2->insert("", true);
    increasing->push_back(dim1);
    increasing->push_back(dim2);
    ds = std::make_shared<CartesianDiscreteSpace2D>(space, axes, increasing);
  }
};

TEST_F(DiscreteSpaces1DTestFixture, DiscreteSpaceBasicFunctionality) {
  EXPECT_EQ(ds->space(), space);
  EXPECT_EQ(ds->axes(), axes);
}

TEST_F(DiscreteSpaces1DTestFixture, DiscreteSpaceSerializationRoundTrip) {
  std::string json = ds->to_json_string();
  auto        ds2  = DiscreteSpace::from_json_string<DiscreteSpace>(json);

  ASSERT_NE(ds2, nullptr);
  EXPECT_EQ(ds2->axes()->size(), 1);
}

TEST_F(CartesianDiscreteSpaces2DTestFixture,
       CartesianDiscreteSpaceBasicFunctionality) {
  EXPECT_EQ(ds->space(), space);
  EXPECT_EQ(ds->axes(), axes);
}

TEST_F(CartesianDiscreteSpaces2DTestFixture,
       CartesianDiscreteSpaceSerializationRoundTrip) {
  std::string json = ds->to_json_string();
  auto        ds2 =
      CartesianDiscreteSpace::from_json_string<CartesianDiscreteSpace>(json);

  ASSERT_NE(ds2, nullptr);
  EXPECT_EQ(ds2->axes()->size(), 2);
}

TEST_F(CartesianSpaces1DTestFixture,
       CartesianDiscreteSpace1DBasicFunctionality) {
  EXPECT_EQ(ds->space(), space);
  EXPECT_EQ(ds->axes(), axes);
}

TEST_F(CartesianSpaces1DTestFixture,
       CartesianDiscreteSpace1DSerializationRoundTrip) {
  std::string json = ds->to_json_string();
  auto        ds2 =
      CartesianDiscreteSpace1D::from_json_string<CartesianDiscreteSpace1D>(
          json);

  ASSERT_NE(ds2, nullptr);
  EXPECT_EQ(ds2->axes()->size(), 1);
}

TEST_F(CartesianDiscreteSpaces2DTestFixture, ComplexProjectionFunctionality) {
  std::vector<instrument_interfaces::names::InstrumentPortSP> knob_vec{knob1,
                                                                       knob2};
  auto                                                        axes_knobs =
      std::make_shared<Axes<instrument_interfaces::names::InstrumentPort>>(
          knob_vec);
  auto result = ds->get_projection(axes_knobs);

  // 6. Check result
  ASSERT_EQ(result->size(), 2);
  EXPECT_EQ(ds->axes()->size(), 2);
  EXPECT_EQ(ds->space(), space);
}
}  // namespace tests
