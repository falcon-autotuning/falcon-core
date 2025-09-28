
#include <gtest/gtest.h>

#include <memory>

#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/physics/device_structures/Impedance.hpp"
#include "falcon_core/physics/device_structures/Impedances.hpp"
namespace {
using namespace falcon_core::physics::device_structures;

TEST(ImpedancesTest, DefaultConstructor) {
  Impedances imps;
  EXPECT_EQ(imps.size(), 0);
}

TEST(ImpedancesTest, VectorConstructor) {
  auto                     conn1 = Connection::BarrierGate("a");
  auto                     conn2 = Connection::Ohmic("b");
  auto                     imp1  = std::make_shared<Impedance>(conn1, 1.1, 2.2);
  auto                     imp2  = std::make_shared<Impedance>(conn2, 3.3, 4.4);
  std::vector<ImpedanceSP> vec{imp1, imp2};
  Impedances               imps(vec);
  EXPECT_EQ(imps.size(), 2);
  EXPECT_EQ(imps[0], imp1);
  EXPECT_EQ(imps[1], imp2);
}

TEST(ImpedancesTest, SerializationRoundTrip) {
  auto       conn = Connection::BarrierGate("foo");
  auto       imp  = std::make_shared<Impedance>(conn, 5.0, 6.0);
  Impedances imps({imp});
  auto       json  = imps.to_json_string();
  auto       imps2 = Impedances::from_json_string<Impedances>(json);
  ASSERT_EQ(imps2->size(), 1);
  EXPECT_EQ(imps2->at(0)->connection()->name(), "foo");
  EXPECT_DOUBLE_EQ(imps2->at(0)->resistance(), 5.0);
  EXPECT_DOUBLE_EQ(imps2->at(0)->capacitance(), 6.0);
}
}  // namespace
