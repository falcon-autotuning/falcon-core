#include <gtest/gtest.h>

#include <falcon-core/instrument_interfaces/Waveform.hpp>
#include <falcon-core/math/discrete_spaces/DiscreteSpace.hpp>
#include <stdexcept>

#include "falcon-core/generic/Map.hpp"
#include "falcon-core/instrument_interfaces/Waveform.hpp"
#include "falcon-core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon-core/instrument_interfaces/port_transforms/PortTransform.hpp"
#include "falcon-core/instrument_interfaces/port_transforms/PortTransforms.hpp"
#include "falcon-core/math/Axes.hpp"
#include "falcon-core/math/discrete_spaces/DiscreteSpace.hpp"
#include "falcon-core/math/domains/CoupledLabelledDomain.hpp"
#include "falcon-core/math/domains/Domain.hpp"
#include "falcon-core/math/domains/LabelledDomain.hpp"
namespace {
using namespace falcon_core;
using namespace math;
using namespace instrument_interfaces;
using namespace domains;
using namespace discrete_spaces;
using namespace port_transforms;

using namespace falcon_core::instrument_interfaces;
using namespace falcon_core::math;
using namespace falcon_core::math::domains;
using namespace falcon_core::math::discrete_spaces;
using namespace falcon_core::generic;

class WaveformTest : public ::testing::Test {
 protected:
  DiscreteSpaceSP                        discrete_space;
  CoupledLabelledDomainSP                coupled_domain;
  CoupledLabelledDomainSP                coupled_domain2;
  AxesSP<CoupledLabelledDomain>          axes;
  AxesSP<CoupledLabelledDomain>          axes2D;
  AxesSP<Map<std::string, bool>>         increasing;
  AxesSP<Map<std::string, bool>>         increasing2D;
  MapSP<std::string, bool>               map_increasing;
  MapSP<std::string, bool>               map_increasing2;
  DomainSP                               domain;
  names::InstrumentPortSP                knob_port;
  names::InstrumentPortSP                knob_port2;
  LabelledDomainSP                       labelled_domain;
  LabelledDomainSP                       labelled_domain2;
  ListSP<port_transforms::PortTransform> transforms;
  ListSP<port_transforms::PortTransform> transforms2D;

  void SetUp() override {
    knob_port = names::InstrumentPort::Knob(
        "Vg1",
        falcon_core::physics::device_structures::Connection::PlungerGate("P1"));
    knob_port2 = names::InstrumentPort::Knob(
        "Vg2",
        falcon_core::physics::device_structures::Connection::PlungerGate("P2"));
    domain          = std::make_shared<Domain>(std::pair<double, double>(0, 1));
    labelled_domain = LabelledDomain::from_port_and_domain(knob_port, domain);
    labelled_domain2 = LabelledDomain::from_port_and_domain(knob_port2, domain);
    coupled_domain   = std::make_shared<CoupledLabelledDomain>(
        std::vector<LabelledDomainSP>{labelled_domain});
    coupled_domain2 = std::make_shared<CoupledLabelledDomain>(
        std::vector<LabelledDomainSP>{labelled_domain2});
    axes = std::make_shared<Axes<CoupledLabelledDomain>>();
    axes->push_back(coupled_domain);
    axes2D = std::make_shared<Axes<CoupledLabelledDomain>>();
    axes2D->push_back(coupled_domain);
    axes2D->push_back(coupled_domain2);
    map_increasing = std::make_shared<Map<std::string, bool>>();
    map_increasing->insert("Vg1", true);
    map_increasing2 = std::make_shared<Map<std::string, bool>>();
    map_increasing2->insert("Vg2", true);
    increasing = std::make_shared<Axes<Map<std::string, bool>>>();
    increasing->push_back(map_increasing);
    increasing2D = std::make_shared<Axes<Map<std::string, bool>>>();
    increasing2D->push_back(map_increasing);
    increasing2D->push_back(map_increasing2);
    discrete_space = DiscreteSpace::CartesianDiscreteSpace(
        std::make_shared<Axes<int>>(std::vector<int>{10}),
        axes,
        increasing,
        domain);
    transforms = std::make_shared<List<port_transforms::PortTransform>>();
    transforms->push_back(
        port_transforms::PortTransform::IdentityTransform(knob_port));
    transforms2D = std::make_shared<List<port_transforms::PortTransform>>();
    transforms2D->push_back(
        port_transforms::PortTransform::IdentityTransform(knob_port));
    transforms2D->push_back(
        port_transforms::PortTransform::IdentityTransform(knob_port2));
  }
};

TEST_F(WaveformTest, ConstructorWorks) {
  Waveform waveform(discrete_space, transforms);
  EXPECT_EQ(*waveform.space(), *discrete_space);
}

TEST_F(WaveformTest, ConstructorThrowsOnNullSpace) {
  EXPECT_THROW(Waveform(nullptr, transforms), std::invalid_argument);
}

TEST_F(WaveformTest, ConstructorThrowsOnNullTransforms) {
  EXPECT_THROW(Waveform(discrete_space, nullptr), std::invalid_argument);
}

TEST_F(WaveformTest, CartesianWaveformThrowsOnNullArgs) {
  auto divisions = std::make_shared<Axes<int>>(std::vector<int>{10});
  EXPECT_THROW(Waveform::CartesianWaveform(
                   nullptr, axes, increasing, transforms, domain),
               std::invalid_argument);
  EXPECT_THROW(Waveform::CartesianWaveform(
                   divisions, nullptr, increasing, transforms, domain),
               std::invalid_argument);
  EXPECT_THROW(
      Waveform::CartesianWaveform(divisions, axes, nullptr, transforms, domain),
      std::invalid_argument);
  EXPECT_THROW(
      Waveform::CartesianWaveform(divisions, axes, increasing, nullptr, domain),
      std::invalid_argument);
  EXPECT_THROW(Waveform::CartesianWaveform(
                   divisions, axes, increasing, transforms, nullptr),
               std::invalid_argument);
}

TEST_F(WaveformTest, CartesianWaveformWorks) {
  auto divisions = std::make_shared<Axes<int>>(std::vector<int>{10});
  auto waveform  = Waveform::CartesianWaveform(
      divisions, axes, increasing, transforms, domain);
  ASSERT_NE(waveform, nullptr);
  EXPECT_EQ(waveform->space()->axes()->size(), axes->size());
}

TEST_F(WaveformTest, CartesianWaveformNullptrs) {
  auto divisions = std::make_shared<Axes<int>>(std::vector<int>{10});
  EXPECT_THROW(Waveform::CartesianWaveform(
                   nullptr, axes, increasing, transforms, domain),
               std::invalid_argument);
  EXPECT_THROW(Waveform::CartesianWaveform(
                   divisions, nullptr, increasing, transforms, domain),
               std::invalid_argument);
  EXPECT_THROW(
      Waveform::CartesianWaveform(divisions, axes, nullptr, transforms, domain),
      std::invalid_argument);
  EXPECT_THROW(
      Waveform::CartesianWaveform(divisions, axes, increasing, nullptr, domain),
      std::invalid_argument);
  EXPECT_THROW(Waveform::CartesianWaveform(
                   divisions, axes, increasing, transforms, nullptr),
               std::invalid_argument);
}

TEST_F(WaveformTest, CartesianIdentityWaveformWorks) {
  auto divisions = std::make_shared<Axes<int>>(std::vector<int>{10});
  auto waveform =
      Waveform::CartesianIdentityWaveform(divisions, axes, increasing, domain);
  ASSERT_NE(waveform, nullptr);
}

TEST_F(WaveformTest, CartesianIdentityWaveformNullptrs) {
  auto divisions = std::make_shared<Axes<int>>(std::vector<int>{10});
  EXPECT_THROW(
      Waveform::CartesianIdentityWaveform(nullptr, axes, increasing, domain),
      std::invalid_argument);
  EXPECT_THROW(Waveform::CartesianIdentityWaveform(
                   divisions, nullptr, increasing, domain),
               std::invalid_argument);
  EXPECT_THROW(
      Waveform::CartesianIdentityWaveform(divisions, axes, nullptr, domain),
      std::invalid_argument);
  EXPECT_THROW(
      Waveform::CartesianIdentityWaveform(divisions, axes, increasing, nullptr),
      std::invalid_argument);
}

TEST_F(WaveformTest, CartesianWaveform2DWorks) {
  auto divisions = std::make_shared<Axes<int>>(std::vector<int>{10, 10});
  auto waveform  = Waveform::CartesianWaveform2D(
      divisions, axes2D, increasing2D, transforms2D, domain);
  ASSERT_NE(waveform, nullptr);
  EXPECT_EQ(waveform->space()->axes()->size(), 2);
}

TEST_F(WaveformTest, CartesianWaveform2DNullptrs) {
  auto divisions = std::make_shared<Axes<int>>(std::vector<int>{10, 10});
  EXPECT_THROW(Waveform::CartesianWaveform2D(
                   nullptr, axes, increasing, transforms, domain),
               std::invalid_argument);
  EXPECT_THROW(Waveform::CartesianWaveform2D(
                   divisions, nullptr, increasing, transforms, domain),
               std::invalid_argument);
  EXPECT_THROW(Waveform::CartesianWaveform2D(
                   divisions, axes, nullptr, transforms, domain),
               std::invalid_argument);
  EXPECT_THROW(Waveform::CartesianWaveform2D(
                   divisions, axes, increasing, nullptr, domain),
               std::runtime_error);
  EXPECT_THROW(Waveform::CartesianWaveform2D(
                   divisions, axes, increasing, transforms, nullptr),
               std::runtime_error);
}

TEST_F(WaveformTest, CartesianIdentityWaveform2DWorks) {
  auto divisions = std::make_shared<Axes<int>>(std::vector<int>{10, 10});
  auto waveform  = Waveform::CartesianIdentityWaveform2D(
      divisions, axes2D, increasing2D, domain);
  ASSERT_NE(waveform, nullptr);
  EXPECT_EQ(waveform->space()->axes()->size(), 2);
}

TEST_F(WaveformTest, CartesianIdentityWaveform2DNullptrs) {
  auto divisions = std::make_shared<Axes<int>>(std::vector<int>{10, 10});
  EXPECT_THROW(
      Waveform::CartesianIdentityWaveform2D(nullptr, axes, increasing, domain),
      std::invalid_argument);
  EXPECT_THROW(Waveform::CartesianIdentityWaveform2D(
                   divisions, nullptr, increasing, domain),
               std::invalid_argument);
  EXPECT_THROW(
      Waveform::CartesianIdentityWaveform2D(divisions, axes, nullptr, domain),
      std::invalid_argument);
  EXPECT_THROW(Waveform::CartesianIdentityWaveform2D(
                   divisions, axes, increasing, nullptr),
               std::runtime_error);
}

TEST_F(WaveformTest, CartesianWaveform1DWorks) {
  auto waveform = Waveform::CartesianWaveform1D(
      10, coupled_domain, map_increasing, transforms, domain);
  ASSERT_NE(waveform, nullptr);
}

TEST_F(WaveformTest, CartesianWaveform1DNullptrs) {
  EXPECT_THROW(Waveform::CartesianWaveform1D(
                   10, nullptr, map_increasing, transforms, domain),
               std::invalid_argument);
  EXPECT_THROW(Waveform::CartesianWaveform1D(
                   10, coupled_domain, nullptr, transforms, domain),
               std::invalid_argument);
  EXPECT_THROW(Waveform::CartesianWaveform1D(
                   10, coupled_domain, map_increasing, nullptr, domain),
               std::invalid_argument);
  EXPECT_THROW(Waveform::CartesianWaveform1D(
                   10, coupled_domain, map_increasing, transforms, nullptr),
               std::invalid_argument);
}

TEST_F(WaveformTest, CartesianIdentityWaveform1DWorks) {
  auto waveform = Waveform::CartesianIdentityWaveform1D(
      10, coupled_domain, map_increasing, domain);
  ASSERT_NE(waveform, nullptr);
}

TEST_F(WaveformTest, CartesianIdentityWaveform1DNullptrs) {
  EXPECT_THROW(Waveform::CartesianIdentityWaveform1D(
                   10, nullptr, map_increasing, domain),
               std::invalid_argument);
  EXPECT_THROW(Waveform::CartesianIdentityWaveform1D(
                   10, coupled_domain, nullptr, domain),
               std::invalid_argument);
  EXPECT_THROW(Waveform::CartesianIdentityWaveform1D(
                   10, coupled_domain, map_increasing, nullptr),
               std::invalid_argument);
}

TEST_F(WaveformTest, SerializationRoundTrip) {
  Waveform waveform(discrete_space, transforms);
  auto     string = waveform.to_json_string();
  auto     loaded = Waveform::from_json_string<Waveform>(string);
  EXPECT_EQ(waveform, *loaded);
}
}  // namespace
