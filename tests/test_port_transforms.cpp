#include <gtest/gtest.h>

#include <falcon_core/instrument_interfaces/port_transforms/ConstantTransform.hpp>
#include <falcon_core/instrument_interfaces/port_transforms/IdentityTransform.hpp>
#include <falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp>
#include <falcon_core/instrument_interfaces/port_transforms/PortTransforms.hpp>

#include "falcon_core/math/analytic_functions/ConstantFunction.hpp"
#include "falcon_core/math/analytic_functions/Identity.hpp"
namespace tests {
// Dummy InstrumentPort for testing
class DummyInstrumentPort : public falcon_core::generic::Song {
 public:
  DummyInstrumentPort(std::string name) : _name(std::move(name)) {}
  DummyInstrumentPort() : _name("") {}
  std::string name() const { return _name; }

  bool operator==(const DummyInstrumentPort& other) const {
    return _name == other._name;
  }

#ifndef SWIG
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<falcon_core::generic::Song>(this), _name);
  }
#endif

 private:
  std::string _name;
};

TEST(PortTransformTest, InitializationAndApply) {
  auto identity_func =
      std::make_shared<falcon_core::math::analytic_functions::Identity>();
  auto constant_func =
      std::make_shared<falcon_core::math::analytic_functions::ConstantFunction>(
          42.0);

  falcon_core::instrument_interfaces::port_transforms::PortTransform
      identity_transform(identity_func);
  falcon_core::instrument_interfaces::port_transforms::PortTransform
      constant_transform(constant_func);

  EXPECT_DOUBLE_EQ(identity_transform.apply(5.0), 5.0);
  EXPECT_DOUBLE_EQ(constant_transform.apply(5.0), 42.0);
}

TEST(PortTransformsTest, ContainerBehavior) {
  auto identity_func =
      std::make_shared<falcon_core::math::analytic_functions::Identity>();
  auto constant_func =
      std::make_shared<falcon_core::math::analytic_functions::ConstantFunction>(
          3.14);

  auto identity_transform = std::make_shared<
      falcon_core::instrument_interfaces::port_transforms::PortTransform>(
      identity_func);
  auto constant_transform = std::make_shared<
      falcon_core::instrument_interfaces::port_transforms::PortTransform>(
      constant_func);

  falcon_core::instrument_interfaces::port_transforms::PortTransforms
      transforms;
  transforms.append(identity_transform);
  transforms.append(constant_transform);

  ASSERT_EQ(transforms.get_transforms().size(), 2);
  EXPECT_DOUBLE_EQ(transforms.get_transforms()[0]->apply(7.0), 7.0);
  EXPECT_DOUBLE_EQ(transforms.get_transforms()[1]->apply(7.0), 3.14);
}

TEST(PortTransformTest, SerializationRoundTrip) {
  auto constant_func =
      std::make_shared<falcon_core::math::analytic_functions::ConstantFunction>(
          123.456);
  falcon_core::instrument_interfaces::port_transforms::PortTransform original(
      constant_func);

  // Serialize to JSON
  std::string json = original.to_json_string();

  // Deserialize from JSON
  auto recreated = falcon_core::generic::Song::from_json_string<
      falcon_core::instrument_interfaces::port_transforms::PortTransform>(json);

  // Check that the transform still works
  EXPECT_DOUBLE_EQ(recreated->apply(0.0), 123.456);
  EXPECT_DOUBLE_EQ(recreated->apply(999.0), 123.456);
}

TEST(PortTransformsTest, SerializationRoundTrip) {
  auto identity_func =
      std::make_shared<falcon_core::math::analytic_functions::Identity>();
  auto constant_func =
      std::make_shared<falcon_core::math::analytic_functions::ConstantFunction>(
          77.7);

  auto identity_transform = std::make_shared<
      falcon_core::instrument_interfaces::port_transforms::PortTransform>(
      identity_func);
  auto constant_transform = std::make_shared<
      falcon_core::instrument_interfaces::port_transforms::PortTransform>(
      constant_func);

  falcon_core::instrument_interfaces::port_transforms::PortTransforms original;
  original.append(identity_transform);
  original.append(constant_transform);

  // Serialize to JSON
  std::string json = original.to_json_string();

  // Deserialize from JSON
  auto recreated = falcon_core::generic::Song::from_json_string<
      falcon_core::instrument_interfaces::port_transforms::PortTransforms>(
      json);

  ASSERT_EQ(recreated->get_transforms().size(), 2);
  EXPECT_DOUBLE_EQ(recreated->get_transforms()[0]->apply(123.0), 123.0);
  EXPECT_DOUBLE_EQ(recreated->get_transforms()[1]->apply(123.0), 77.7);
}
}  // namespace tests
