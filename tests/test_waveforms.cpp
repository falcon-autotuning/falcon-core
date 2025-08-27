#include <gtest/gtest.h>

#include <falcon_core/generic/Song.hpp>
#include <falcon_core/instrument_interfaces/port_transforms/ConstantTransform.hpp>
#include <falcon_core/instrument_interfaces/port_transforms/IdentityTransform.hpp>
#include <falcon_core/instrument_interfaces/waveforms/CartesianWaveform.hpp>
#include <falcon_core/instrument_interfaces/waveforms/CartesianWaveform1D.hpp>
#include <falcon_core/instrument_interfaces/waveforms/CartesianWaveform2D.hpp>
#include <falcon_core/instrument_interfaces/waveforms/Waveform.hpp>
#include <falcon_core/math/discrete_spaces/BaseDiscreteSpace.hpp>
#include <falcon_core/math/discrete_spaces/CartesianDiscreteSpace.hpp>
#include <falcon_core/math/discrete_spaces/CartesianDiscreteSpace1D.hpp>
#include <falcon_core/math/domains/Domain.hpp>
#include <memory>
#include <string>
#include <vector>

TEST(WaveformTest, BasicConstructionAndAccess) {
  using namespace falcon_core::instrument_interfaces::waveforms;
  using namespace falcon_core::math::discrete_spaces;
  using namespace falcon_core::math::domains;
  using namespace falcon_core::instrument_interfaces::port_transforms;

  auto domain = std::make_shared<Domain>(0.0, 1.0);
  // Use a 1D CartesianDiscreteSpace for valid construction
  auto cartesian_space = std::make_shared<falcon_core::math::spaces::Cartesian1DSpace>(10.0, domain);
  auto axes = std::make_shared<falcon_core::math::Axes<falcon_core::math::domains::CoupledKnobDomain>>();
  auto space  = std::make_shared<CartesianDiscreteSpace1D>(cartesian_space, axes);

  auto identity_transform = std::make_shared<IdentityTransform>();
  auto constant_transform = std::make_shared<ConstantTransform>(3.14);

  Waveform waveform(space, {identity_transform, constant_transform});

  ASSERT_EQ(waveform.space(), space);
  ASSERT_EQ(waveform.get_transforms().size(), 2);
}

TEST(WaveformTest, SerializationRoundTrip) {
  using namespace falcon_core::instrument_interfaces::waveforms;
  using namespace falcon_core::math::discrete_spaces;
  using namespace falcon_core::math::domains;
  using namespace falcon_core::instrument_interfaces::port_transforms;

  auto domain = std::make_shared<Domain>(-5.0, 5.0);
  // Use a 1D CartesianDiscreteSpace for valid construction
  auto cartesian_space = std::make_shared<falcon_core::math::spaces::Cartesian1DSpace>(10.0, domain);
  auto axes = std::make_shared<falcon_core::math::Axes<falcon_core::math::domains::CoupledKnobDomain>>();
  auto space  = std::make_shared<CartesianDiscreteSpace1D>(cartesian_space, axes);

  auto identity_transform = std::make_shared<IdentityTransform>();
  auto constant_transform = std::make_shared<ConstantTransform>(42.0);

  Waveform original(space, {identity_transform, constant_transform});

  std::string json = original.to_json_string();
  auto recreated = falcon_core::generic::Song::from_json_string<Waveform>(json);

  ASSERT_EQ(recreated->get_transforms().size(), 2);
  EXPECT_DOUBLE_EQ(
      dynamic_cast<ConstantTransform*>(recreated->get_transforms()[1].get())
          ->apply(0.0),
      42.0);
}

TEST(CartesianWaveformTest, NDConstructionAndSerialization) {
  using namespace falcon_core::instrument_interfaces::waveforms;
  using namespace falcon_core::math::discrete_spaces;
  using namespace falcon_core::math::domains;
  using namespace falcon_core::instrument_interfaces::port_transforms;

  auto domain = std::make_shared<Domain>(0.0, 10.0);

  // ND: 3 axes
  auto divisions = std::make_shared<falcon_core::math::Axes<int>>(
      std::vector<int>{10, 20, 30});
  auto axes = std::make_shared<
      falcon_core::math::Axes<falcon_core::math::domains::CoupledKnobDomain>>();
  auto increasing =
      std::make_shared<falcon_core::math::Axes<std::map<std::string, bool>>>();

  auto identity_transform = std::make_shared<IdentityTransform>();
  auto constant_transform = std::make_shared<ConstantTransform>(1.23);

  auto waveform = CartesianWaveform::from_divisions(
      divisions,
      axes,
      increasing,
      {identity_transform, constant_transform},
      domain);

  ASSERT_TRUE(waveform != nullptr);
  ASSERT_EQ(waveform->get_transforms().size(), 2);

  // Serialization round-trip
  std::string json = waveform->to_json_string();
  auto        recreated =
      falcon_core::generic::Song::from_json_string<CartesianWaveform>(json);
  ASSERT_EQ(recreated->get_transforms().size(), 2);
}

TEST(CartesianWaveform1DTest, ConstructionAndSerialization) {
  using namespace falcon_core::instrument_interfaces::waveforms;
  using namespace falcon_core::math::domains;
  using namespace falcon_core::math::discrete_spaces;
  using namespace falcon_core::instrument_interfaces::port_transforms;

  auto domain = std::make_shared<Domain>(-1.0, 1.0);
  auto shared_domain =
      std::make_shared<falcon_core::math::domains::CoupledKnobDomain>();
  auto increasing =
      std::make_shared<falcon_core::math::Axes<std::map<std::string, bool>>>();

  auto identity_transform = std::make_shared<IdentityTransform>();

  auto waveform = CartesianWaveform1D::from_division(
      10, shared_domain, increasing, {identity_transform}, domain);

  ASSERT_TRUE(waveform != nullptr);
  ASSERT_EQ(waveform->get_transforms().size(), 1);

  // Serialization round-trip
  std::string json = waveform->to_json_string();
  auto        recreated =
      falcon_core::generic::Song::from_json_string<CartesianWaveform1D>(json);
  ASSERT_EQ(recreated->get_transforms().size(), 1);
}

TEST(CartesianWaveform2DTest, ConstructionAndSerialization) {
  using namespace falcon_core::instrument_interfaces::waveforms;
  using namespace falcon_core::math::domains;
  using namespace falcon_core::math::discrete_spaces;
  using namespace falcon_core::instrument_interfaces::port_transforms;

  auto domain = std::make_shared<Domain>(-2.0, 2.0);
  auto divisions =
      std::make_shared<falcon_core::math::Axes<int>>(std::vector<int>{5, 5});
  auto axes = std::make_shared<
      falcon_core::math::Axes<falcon_core::math::domains::CoupledKnobDomain>>();
  auto increasing =
      std::make_shared<falcon_core::math::Axes<std::map<std::string, bool>>>();

  auto identity_transform = std::make_shared<IdentityTransform>();

  auto waveform = CartesianWaveform2D::from_divisions(
      divisions, axes, increasing, {identity_transform}, domain);

  ASSERT_TRUE(waveform != nullptr);
  ASSERT_EQ(waveform->get_transforms().size(), 1);

  // Serialization round-trip
  std::string json = waveform->to_json_string();
  auto        recreated =
      falcon_core::generic::Song::from_json_string<CartesianWaveform2D>(json);
  ASSERT_EQ(recreated->get_transforms().size(), 1);
}
