#include <gtest/gtest.h>

#include "falcon-core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon-core/instrument_interfaces/port_transforms/PortTransform.hpp"
#include "falcon-core/instrument_interfaces/port_transforms/PortTransforms.hpp"

namespace {
using namespace falcon_core;
using namespace generic;
using namespace instrument_interfaces::port_transforms;
using namespace instrument_interfaces::names;

class PortTransformsTest : public ::testing::Test {
 protected:
  InstrumentPortSP portA = std::make_shared<InstrumentPort>("A");
  InstrumentPortSP portB = std::make_shared<InstrumentPort>("B");
  PortTransformSP  ptA   = PortTransform::IdentityTransform(portA);
  PortTransformSP  ptB   = PortTransform::ConstantTransform(portB, 42.0);
};

TEST_F(PortTransformsTest, DefaultConstructor) {
  PortTransforms pts;
  EXPECT_EQ(pts.size(), 0);
}
TEST_F(PortTransformsTest, ListSPConstructorAndNullThrows) {
  auto list = std::make_shared<generic::List<PortTransform>>();
  list->push_back(ptA);
  PortTransforms pts(list);
  EXPECT_EQ(pts.size(), 1);
  EXPECT_THROW(PortTransforms(nullptr), std::invalid_argument);
}
TEST_F(PortTransformsTest, VectorConstructor) {
  std::vector<PortTransformSP> vec{ptA, ptB};
  PortTransforms               pts(vec);
  EXPECT_EQ(pts.size(), 2);
  EXPECT_EQ(*pts.at(0), *ptA);
  EXPECT_EQ(*pts.at(1), *ptB);
}
TEST_F(PortTransformsTest, TransformsGetter) {
  std::vector<PortTransformSP> vec{ptA, ptB};
  PortTransforms               pts(vec);
  auto                         tlist = pts.transforms();
  EXPECT_EQ(tlist->size(), 2);
  EXPECT_EQ(tlist->at(0), ptA);
}
TEST_F(PortTransformsTest, SerializationRoundTrip) {
  std::vector<PortTransformSP> vec{ptA, ptB};
  PortTransforms               pts(vec);
  auto                         json = pts.to_json_string();
  auto pts2 = PortTransforms::from_json_string<PortTransforms>(json);
  EXPECT_EQ(pts, *pts2);
}
}  // namespace
