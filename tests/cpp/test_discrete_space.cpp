#include <gtest/gtest.h>

#include <stdexcept>

#include "falcon-core/instrument_interfaces/names/Ports.hpp"
#include "falcon-core/math/Axes.hpp"
#include "falcon-core/math/UnitSpace.hpp"
#include "falcon-core/math/discrete_spaces/DiscreteSpace.hpp"
#include "falcon-core/math/discrete_spaces/Discretizer.hpp"
#include "falcon-core/math/domains/CoupledLabelledDomain.hpp"
#include "falcon-core/math/domains/LabelledDomain.hpp"

namespace {
using namespace falcon_core::math::discrete_spaces;
using namespace falcon_core::math;
using namespace falcon_core::math::domains;
using namespace falcon_core::instrument_interfaces::names;
using namespace falcon_core::generic;

class DiscreteSpaceTest : public ::testing::Test {
 protected:
  UnitSpaceSP                    unit_space;
  CoupledLabelledDomainSP        coupled_domain;
  AxesSP<CoupledLabelledDomain>  axes;
  AxesSP<Map<std::string, bool>> increasing;
  MapSP<std::string, bool>       map_increasing;
  PortsSP                        knobs;
  DomainSP                       domain;
  InstrumentPortSP               knob_port;
  LabelledDomainSP               labelled_domain;
  DiscretizerSP                  discretizer;

  void SetUp() override {
    // Create a knob InstrumentPort
    knob_port = InstrumentPort::Knob(
        "Vg1",
        falcon_core::physics::device_structures::Connection::PlungerGate("P1"));

    // Create a domain for the knob
    domain = std::make_shared<Domain>(std::pair<double, double>(0, 1));

    // Create a LabelledDomain using the correct static API
    labelled_domain = LabelledDomain::from_port_and_domain(knob_port, domain);

    // CoupledLabelledDomain from vector of labelled domains
    std::vector<LabelledDomainSP> domain_vec{labelled_domain};
    coupled_domain = std::make_shared<CoupledLabelledDomain>(domain_vec);

    // Axes for CoupledLabelledDomain
    axes = std::make_shared<Axes<CoupledLabelledDomain>>();
    axes->push_back(coupled_domain);

    // Increasing map
    map_increasing = std::make_shared<Map<std::string, bool>>();
    map_increasing->insert("P1", true);
    increasing = std::make_shared<Axes<Map<std::string, bool>>>();
    increasing->push_back(map_increasing);

    // Knobs
    knobs = std::make_shared<Ports>();
    knobs->push_back(knob_port);

    // Discretizer using correct static API
    discretizer = Discretizer::CartesianDiscretizer(0.1);

    // Axes for Discretizer
    auto axes_discretizer = std::make_shared<Axes<Discretizer>>();
    axes_discretizer->push_back(discretizer);

    // UnitSpace using correct constructor
    unit_space = std::make_shared<UnitSpace>(axes_discretizer, domain);
  }
};

TEST_F(DiscreteSpaceTest, ConstructorWorks) {
  DiscreteSpace space(unit_space, axes, increasing);
  EXPECT_EQ(*space.space(), *unit_space);
  EXPECT_EQ(*space.axes(), *axes);
  EXPECT_EQ(*space.increasing(), *increasing);
}
TEST_F(DiscreteSpaceTest, CartesianDiscreteSpaceWorks) {
  auto divisions = std::make_shared<Axes<int>>();
  divisions->push_back(10);
  auto space = DiscreteSpace::CartesianDiscreteSpace(
      divisions, axes, increasing, domain);
  ASSERT_NE(space, nullptr);
}
TEST_F(DiscreteSpaceTest, CartesianDiscreteSpace1DWorks) {
  auto space = DiscreteSpace::CartesianDiscreteSpace1D(
      10, coupled_domain, map_increasing, domain);
  ASSERT_NE(space, nullptr);
}
TEST_F(DiscreteSpaceTest, NullptrThrows) {
  EXPECT_THROW(DiscreteSpace(nullptr, axes, increasing), std::invalid_argument);
  EXPECT_THROW(DiscreteSpace(unit_space, nullptr, increasing),
               std::invalid_argument);
  EXPECT_THROW(DiscreteSpace(unit_space, axes, nullptr), std::invalid_argument);
}
TEST_F(DiscreteSpaceTest, GetAxisThrowsOnNullKnob) {
  DiscreteSpace space(unit_space, axes, increasing);
  EXPECT_THROW(space.get_axis(nullptr), std::invalid_argument);
}
TEST_F(DiscreteSpaceTest, GetDomainThrowsOnNullKnob) {
  DiscreteSpace space(unit_space, axes, increasing);
  EXPECT_THROW(space.get_domain(nullptr), std::invalid_argument);
}
TEST_F(DiscreteSpaceTest, KnobsAreCorrect) {
  DiscreteSpace space(unit_space, axes, increasing);
  auto          space_knobs = space.knobs();
  ASSERT_EQ(space_knobs->size(), 1);
  EXPECT_EQ(space_knobs->at(0)->default_name(), "Vg1");
}
TEST_F(DiscreteSpaceTest, ValidateUnitSpaceDimensionalityMatchesKnobs) {
  DiscreteSpace space(unit_space, axes, increasing);
  EXPECT_NO_THROW(space.validate_unit_space_dimensionality_matches_knobs());
}
TEST_F(DiscreteSpaceTest, ValidateKnobUniqueness) {
  DiscreteSpace space(unit_space, axes, increasing);
  EXPECT_NO_THROW(space.validate_knob_uniqueness());
}
TEST_F(DiscreteSpaceTest, SerializationRoundTrip) {
  DiscreteSpace space(unit_space, axes, increasing);
  auto          string = space.to_json_string();
  auto          loaded = DiscreteSpace::from_json_string<DiscreteSpace>(string);
  EXPECT_EQ(space, *loaded);
}

TEST_F(DiscreteSpaceTest, CartesianDiscreteSpaceThrowsOnNullArgs) {
  auto divisions = std::make_shared<Axes<int>>();
  divisions->push_back(10);
  EXPECT_THROW(
      DiscreteSpace::CartesianDiscreteSpace(nullptr, axes, increasing, domain),
      std::invalid_argument);
  EXPECT_THROW(DiscreteSpace::CartesianDiscreteSpace(
                   divisions, nullptr, increasing, domain),
               std::invalid_argument);
  EXPECT_THROW(
      DiscreteSpace::CartesianDiscreteSpace(divisions, axes, nullptr, domain),
      std::invalid_argument);
  EXPECT_THROW(DiscreteSpace::CartesianDiscreteSpace(
                   divisions, axes, increasing, nullptr),
               std::invalid_argument);
}

TEST_F(DiscreteSpaceTest, ValidateUnitSpaceDimensionalityThrows) {
  auto axes_mismatch = std::make_shared<Axes<CoupledLabelledDomain>>();
  axes_mismatch->push_back(coupled_domain);
  axes_mismatch->push_back(coupled_domain);  // size 2
  EXPECT_THROW(DiscreteSpace space(unit_space, axes_mismatch, increasing),
               std::invalid_argument);
}

TEST_F(DiscreteSpaceTest, GetAxisThrowsIfKnobNotFound) {
  DiscreteSpace space(unit_space, axes, increasing);
  auto          other_knob = InstrumentPort::Knob(
      "Vg2",
      falcon_core::physics::device_structures::Connection::PlungerGate("P5"));
  EXPECT_THROW(space.get_axis(other_knob), std::runtime_error);
}

TEST_F(DiscreteSpaceTest, GetDomainThrowsIfKnobNotFound) {
  DiscreteSpace space(unit_space, axes, increasing);
  auto          other_knob = InstrumentPort::Knob(
      "Vg2",
      falcon_core::physics::device_structures::Connection::PlungerGate("P5"));
  EXPECT_THROW(space.get_domain(other_knob), std::runtime_error);
}

TEST_F(DiscreteSpaceTest, OperatorNotEqual) {
  DiscreteSpace space1(unit_space, axes, increasing);
  auto          other_knob = InstrumentPort::Knob(
      "Vg2",
      falcon_core::physics::device_structures::Connection::PlungerGate("P5"));
  auto labelled_domain2 =
      LabelledDomain::from_port_and_domain(other_knob, domain);
  auto coupled_domain2 = std::make_shared<CoupledLabelledDomain>(
      std::vector<LabelledDomainSP>{labelled_domain2});
  auto axes2 = std::make_shared<Axes<CoupledLabelledDomain>>();
  axes2->push_back(coupled_domain2);
  DiscreteSpace space2(unit_space, axes2, increasing);
  EXPECT_TRUE(space1 != space2);
}

TEST_F(DiscreteSpaceTest, GetProjectionThrowsOnNullProjection) {
  DiscreteSpace space(unit_space, axes, increasing);
  EXPECT_THROW(space.get_projection(nullptr), std::invalid_argument);
}

TEST_F(DiscreteSpaceTest, GetProjectionThrowsOnDimensionalityMismatch) {
  DiscreteSpace space(unit_space, axes, increasing);
  auto          projection = std::make_shared<Axes<InstrumentPort>>();
  projection->push_back(knob_port);
  projection->push_back(knob_port);  // dimension > unit_space->dimension()
  EXPECT_THROW(space.get_projection(projection), std::runtime_error);
}

TEST_F(DiscreteSpaceTest, GetProjectionThrowsOnDuplicateAxes) {
  // Create a second knob and domain
  auto knob_port2 = InstrumentPort::Knob(
      "Vg2",
      falcon_core::physics::device_structures::Connection::PlungerGate("P2"));
  auto labelled_domain2 =
      LabelledDomain::from_port_and_domain(knob_port2, domain);
  auto coupled_domain2 = std::make_shared<CoupledLabelledDomain>(
      std::vector<LabelledDomainSP>{labelled_domain2});

  // fudge unit_space dimension to match projection size
  auto fudge_unit_space = std::make_shared<UnitSpace>(
      std::make_shared<Axes<Discretizer>>(
          std::vector<DiscretizerSP>{discretizer, discretizer}),
      domain);

  // axes and increasing to match dimension, but not duplicate
  auto fudge_axes = std::make_shared<Axes<CoupledLabelledDomain>>();
  fudge_axes->push_back(coupled_domain);
  fudge_axes->push_back(coupled_domain2);
  auto fudge_increasing = std::make_shared<Axes<Map<std::string, bool>>>();
  fudge_increasing->push_back(map_increasing);
  auto map_increasing2 = std::make_shared<Map<std::string, bool>>();
  map_increasing2->insert("Vg2", true);
  fudge_increasing->push_back(map_increasing2);

  DiscreteSpace fudge_space(fudge_unit_space, fudge_axes, fudge_increasing);

  auto projection = std::make_shared<Axes<InstrumentPort>>();
  projection->push_back(knob_port);
  projection->push_back(knob_port);  // duplicate knob

  EXPECT_THROW(fudge_space.get_projection(projection), std::runtime_error);
}

TEST_F(DiscreteSpaceTest, GetProjectionThrowsOnKnobNotFound) {
  DiscreteSpace space(unit_space, axes, increasing);
  auto          projection = std::make_shared<Axes<InstrumentPort>>();
  auto          other_knob = InstrumentPort::Knob(
      "Vg2",
      falcon_core::physics::device_structures::Connection::PlungerGate("P5"));
  projection->push_back(other_knob);
  EXPECT_THROW(space.get_projection(projection), std::runtime_error);
}

TEST_F(DiscreteSpaceTest, GetProjectionWorks) {
  DiscreteSpace space(unit_space, axes, increasing);
  auto          projection = std::make_shared<Axes<InstrumentPort>>();
  projection->push_back(knob_port);
  auto result = space.get_projection(projection);
  ASSERT_NE(result, nullptr);
  ASSERT_EQ(result->size(), 1);
  ASSERT_NE(result->at(0), nullptr);
  ASSERT_EQ(result->at(0)->label()->connection()->name(), "P1");
}
}  // namespace
