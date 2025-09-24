#include <gtest/gtest.h>

#include <falcon_core/generic/Song.hpp>
#include <falcon_core/instrument_interfaces/Waveform.hpp>
#include <falcon_core/math/discrete_spaces/DiscreteSpace.hpp>

#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"
namespace tests {
using namespace falcon_core;
using namespace math;
using namespace instrument_interfaces;
using namespace domains;
using namespace discrete_spaces;
using namespace port_transforms;
TEST(WaveformTest, BasicConstructionAndAccess) {
  DomainSP                domain = std::make_shared<Domain>(0.0, 1.0);
  names::InstrumentPortSP knob   = names::InstrumentPort::Knob(
      "test", physics::device_structures::Connection::PlungerGate("P1"));
  LabelledDomainSP labelledD =
      LabelledDomain::from_port_and_domain(knob, domain);
  CoupledLabelledDomainSP coupledDomain =
      std::make_shared<CoupledLabelledDomain>(
          CoupledLabelledDomain(std::vector<LabelledDomainSP>{labelledD}));
  generic::MapSP<std::string, bool> increasing =
      std::make_shared<generic::Map<std::string, bool>>();
  increasing->insert("P1", true);
  auto space =
      DiscreteSpace::CartesianDiscreteSpace1D(10, coupledDomain, increasing);

  auto identity_transform =
      port_transforms::PortTransform::IdentityTransform(knob);
  auto constant_transform =
      port_transforms::PortTransform::ConstantTransform(knob, 3.14);
  generic::ListSP<PortTransform> transforms =
      std::make_shared<generic::List<PortTransform>>(
          std::vector{identity_transform, constant_transform});
  Waveform waveform(space, transforms);

  ASSERT_EQ(waveform.space(), space);
  ASSERT_EQ(waveform.transforms()->size(), 2);
}

TEST(WaveformTest, SerializationRoundTrip) {
  auto                          domain = std::make_shared<Domain>(-5.0, 5.0);
  AxesSP<CoupledLabelledDomain> axes = std::make_shared<falcon_core::math::Axes<
      falcon_core::math::domains::CoupledLabelledDomain>>();
  names::InstrumentPortSP       knob = names::InstrumentPort::Knob(
      "test", physics::device_structures::Connection::PlungerGate("P1"));
  LabelledDomainSP labelledD =
      LabelledDomain::from_port_and_domain(knob, domain);
  CoupledLabelledDomainSP coupledDomain =
      std::make_shared<CoupledLabelledDomain>(
          CoupledLabelledDomain(std::vector<LabelledDomainSP>{labelledD}));
  generic::MapSP<std::string, bool> increasing =
      std::make_shared<generic::Map<std::string, bool>>();
  increasing->insert("P1", true);
  DiscreteSpaceSP space =
      DiscreteSpace::CartesianDiscreteSpace1D(10, coupledDomain, increasing);

  PortTransformSP identity_transform = PortTransform::IdentityTransform(knob);
  PortTransformSP constant_transform =
      PortTransform::ConstantTransform(knob, 42.0);

  generic::ListSP<PortTransform> transforms =
      std::make_shared<generic::List<PortTransform>>(
          std::vector({identity_transform, constant_transform}));
  Waveform original(space, transforms);

  std::string json = original.to_json_string();
  auto recreated = falcon_core::generic::Song::from_json_string<Waveform>(json);

  ASSERT_EQ(recreated->transforms()->size(), 2);
  generic::MapSP<std::string, double> map;
  map->insert("x", 0.0);
  EXPECT_DOUBLE_EQ(recreated->transforms()->at(2)->evaluate(map, 0.0), 42.0);
}

TEST(CartesianWaveformTest, NDConstructionAndSerialization) {
  auto domain = std::make_shared<Domain>(0.0, 10.0);

  // ND: 3 axes
  AxesSP<int> divisions =
      std::make_shared<math::Axes<int>>(std::vector<int>{10, 20, 30});
  names::InstrumentPortSP knob = names::InstrumentPort::Knob(
      "test", physics::device_structures::Connection::PlungerGate("P1"));
  LabelledDomainSP labelledD =
      LabelledDomain::from_port_and_domain(knob, domain);
  CoupledLabelledDomainSP coupledDomain =
      std::make_shared<CoupledLabelledDomain>(
          CoupledLabelledDomain(std::vector<LabelledDomainSP>{labelledD}));
  AxesSP<CoupledLabelledDomain> axes =
      std::make_shared<Axes<CoupledLabelledDomain>>(
          std::vector<CoupledLabelledDomainSP>{coupledDomain});
  AxesSP<generic::Map<std::string, bool>> increasing =
      std::make_shared<Axes<generic::Map<std::string, bool>>>(
          std::vector<generic::MapSP<std::string, bool>>{
              std::make_shared<generic::Map<std::string, bool>>()});
  increasing->at(0)->insert("P1", true);

  auto identity_transform = PortTransform::IdentityTransform(knob);
  auto constant_transform = PortTransform::ConstantTransform(knob, 1.23);

  generic::ListSP<PortTransform> transforms =
      std::make_shared<generic::List<PortTransform>>(
          std::vector({identity_transform, constant_transform}));
  auto waveform = Waveform::CartesianWaveform(
      divisions, axes, increasing, transforms, domain);

  ASSERT_TRUE(waveform != nullptr);
  ASSERT_EQ(waveform->transforms()->size(), 2);

  // Serialization round-trip
  std::string json      = waveform->to_json_string();
  auto        recreated = Waveform::from_json_string<Waveform>(json);
  ASSERT_EQ(recreated->transforms()->size(), 2);
}

TEST(CartesianWaveform1DTest, ConstructionAndSerialization) {
  auto domain = std::make_shared<Domain>(-1.0, 1.0);
  auto shared_domain =
      std::make_shared<falcon_core::math::domains::CoupledLabelledDomain>();
  auto increasing = std::make_shared<generic::Map<std::string, bool>>();

  names::InstrumentPortSP knob = names::InstrumentPort::Knob(
      "test", physics::device_structures::Connection::PlungerGate("P1"));
  auto identity_transform = PortTransform::IdentityTransform(knob);

  generic::ListSP<PortTransform> transforms =
      std::make_shared<generic::List<PortTransform>>(
          std::vector({identity_transform}));
  auto waveform = Waveform::CartesianWaveform1D(
      10, shared_domain, increasing, transforms, domain);

  ASSERT_TRUE(waveform != nullptr);
  ASSERT_EQ(waveform->transforms()->size(), 1);

  // Serialization round-trip
  std::string json      = waveform->to_json_string();
  auto        recreated = Waveform::from_json_string<Waveform>(json);
  ASSERT_EQ(recreated->transforms()->size(), 1);
}

TEST(CartesianWaveform2DTest, ConstructionAndSerialization) {
  auto domain = std::make_shared<Domain>(-2.0, 2.0);
  auto divisions =
      std::make_shared<falcon_core::math::Axes<int>>(std::vector<int>{5, 5});
  auto axes = std::make_shared<falcon_core::math::Axes<
      falcon_core::math::domains::CoupledLabelledDomain>>();
  AxesSP<generic::Map<std::string, bool>> increasing =
      std::make_shared<Axes<generic::Map<std::string, bool>>>(
          std::vector<generic::MapSP<std::string, bool>>{
              std::make_shared<generic::Map<std::string, bool>>()});
  increasing->at(0)->insert("P1", true);

  names::InstrumentPortSP knob = names::InstrumentPort::Knob(
      "test", physics::device_structures::Connection::PlungerGate("P1"));
  auto identity_transform = PortTransform::IdentityTransform(knob);
  generic::ListSP<PortTransform> transforms =
      std::make_shared<generic::List<PortTransform>>(
          std::vector({identity_transform}));

  auto waveform = Waveform::CartesianWaveform2D(
      divisions, axes, increasing, transforms, domain);

  ASSERT_TRUE(waveform != nullptr);
  ASSERT_EQ(waveform->transforms()->size(), 1);

  // Serialization round-trip
  std::string json      = waveform->to_json_string();
  auto        recreated = Waveform::from_json_string<Waveform>(json);
  ASSERT_EQ(recreated->transforms()->size(), 1);
}
}  // namespace tests
