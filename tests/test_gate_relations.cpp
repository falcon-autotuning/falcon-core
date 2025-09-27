
#include <gtest/gtest.h>

#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/physics/device_structures/Connections.hpp"
#include "falcon_core/physics/device_structures/GateRelations.hpp"
namespace {
using namespace falcon_core::physics::device_structures;

TEST(GateRelationsTest, DefaultConstructor) {
  GateRelations gr;
  EXPECT_EQ(gr.size(), 0);
}

TEST(GateRelationsTest, InitConstructor) {
  auto gate1     = Connection::BarrierGate("g1");
  auto gate2     = Connection::BarrierGate("g2");
  auto neighbor1 = Connection::ScreeningGate("n1");
  auto neighbor2 = Connection::ScreeningGate("n2");

  auto neighbors1 =
      std::make_shared<Connections>(std::vector<ConnectionSP>{neighbor1});
  auto neighbors2 =
      std::make_shared<Connections>(std::vector<ConnectionSP>{neighbor2});

  std::vector<std::pair<ConnectionSP, ConnectionsSP>> init = {
      {gate1, neighbors1}, {gate2, neighbors2}};
  GateRelations gr(init);
  EXPECT_EQ(gr.size(), 2);
  EXPECT_EQ(gr.at(gate1)->at(0)->name(), "n1");
  EXPECT_EQ(gr.at(gate2)->at(0)->name(), "n2");
}

TEST(GateRelationsTest, InsertOrAssign) {
  GateRelations gr;
  auto          gate     = Connection::BarrierGate("g");
  auto          neighbor = Connection::ScreeningGate("n");
  auto          neighbors =
      std::make_shared<Connections>(std::vector<ConnectionSP>{neighbor});
  gr.insert_or_assign(gate, neighbors);
  EXPECT_EQ(gr.size(), 1);
  EXPECT_EQ(gr.at(gate)->at(0)->name(), "n");
}

TEST(GateRelationsTest, Insert) {
  GateRelations gr;
  auto          gate     = Connection::BarrierGate("g");
  auto          neighbor = Connection::ScreeningGate("n");
  auto          neighbors =
      std::make_shared<Connections>(std::vector<ConnectionSP>{neighbor});
  auto result = gr.insert(gate, neighbors);
  EXPECT_TRUE(result.second);
  EXPECT_EQ(gr.size(), 1);
  EXPECT_EQ(gr.at(gate)->at(0)->name(), "n");
}

TEST(GateRelationsTest, SerializationRoundTrip) {
  auto gate     = Connection::BarrierGate("g");
  auto neighbor = Connection::ScreeningGate("n");
  auto neighbors =
      std::make_shared<Connections>(std::vector<ConnectionSP>{neighbor});
  GateRelations gr;
  gr.insert_or_assign(gate, neighbors);
  auto json = gr.to_json_string();
  auto gr2  = GateRelations::from_json_string<GateRelations>(json);
  ASSERT_EQ(gr2->size(), 1);
  auto got = gr2->at(gate);
  ASSERT_TRUE(got);
  EXPECT_EQ(got->at(0)->name(), "n");
}
}  // namespace
