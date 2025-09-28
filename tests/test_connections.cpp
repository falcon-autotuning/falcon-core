#include <gtest/gtest.h>

#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/physics/device_structures/Connections.hpp"
namespace {
using namespace falcon_core::physics::device_structures;

TEST(ConnectionsTest, DefaultConstructor) {
  Connections c = Connections();
  EXPECT_EQ(c.size(), 0);
}

TEST(ConnectionsTest, CountValueConstructor) {
  auto        conn = Connection::BarrierGate("a");
  Connections c(2, conn);
  EXPECT_EQ(c.size(), 2);
  for (const auto& item : c) {
    EXPECT_EQ(item, conn);
  }
}

TEST(ConnectionsTest, VectorConstructor) {
  auto                      c1 = Connection::BarrierGate("a");
  auto                      c2 = Connection::Ohmic("b");
  std::vector<ConnectionSP> vec{c1, c2};
  Connections               c(vec);
  EXPECT_EQ(c.size(), 2);
  EXPECT_EQ(c[0], c1);
  EXPECT_EQ(c[1], c2);
}

TEST(ConnectionsTest, ListSPConstructor) {
  auto c1     = Connection::BarrierGate("a");
  auto c2     = Connection::Ohmic("b");
  auto listsp = std::make_shared<falcon_core::generic::List<Connection>>(
      std::vector<ConnectionSP>{c1, c2});
  Connections c(listsp);
  EXPECT_EQ(c.size(), 2);
  EXPECT_EQ(c[0], c1);
  EXPECT_EQ(c[1], c2);
}

TEST(ConnectionsTest, TypeChecks) {
  auto gate      = Connection::ScreeningGate("g");
  auto ohmic     = Connection::Ohmic("o");
  auto plunger   = Connection::PlungerGate("p");
  auto barrier   = Connection::BarrierGate("b");
  auto reservoir = Connection::ReservoirGate("r");
  auto screening = Connection::ScreeningGate("s");

  Connections gates({gate, gate});
  EXPECT_TRUE(gates.is_gates());
  EXPECT_FALSE(gates.is_dot_gates());
  EXPECT_FALSE(gates.is_reservoir_gates());
  EXPECT_FALSE(gates.is_barrier_gates());
  EXPECT_FALSE(gates.is_plunger_gates());
  EXPECT_FALSE(gates.is_ohmics());

  Connections ohmics({ohmic, ohmic});
  EXPECT_TRUE(ohmics.is_ohmics());
  EXPECT_FALSE(gates.is_dot_gates());
  EXPECT_FALSE(gates.is_reservoir_gates());
  EXPECT_FALSE(gates.is_barrier_gates());
  EXPECT_FALSE(gates.is_plunger_gates());
  EXPECT_FALSE(ohmics.is_screening_gates());
  EXPECT_FALSE(ohmics.is_gates());

  Connections plungers({plunger, plunger});
  EXPECT_TRUE(plungers.is_plunger_gates());
  EXPECT_TRUE(plungers.is_dot_gates());

  Connections barriers({barrier, barrier});
  EXPECT_TRUE(barriers.is_barrier_gates());

  Connections dotmixed({plunger, barrier});
  EXPECT_TRUE(dotmixed.is_dot_gates());
  EXPECT_FALSE(dotmixed.is_plunger_gates());
  EXPECT_FALSE(dotmixed.is_barrier_gates());

  Connections reservoirs({reservoir, reservoir});
  EXPECT_TRUE(reservoirs.is_reservoir_gates());

  Connections screenings({screening, screening});
  EXPECT_TRUE(screenings.is_screening_gates());

  Connections mixed({gate, ohmic});
  EXPECT_FALSE(mixed.is_gates());
  EXPECT_FALSE(mixed.is_ohmics());
}

TEST(ConnectionsTest, SerializationRoundTrip) {
  auto        gate  = Connection::PlungerGate("g");
  auto        ohmic = Connection::Ohmic("o");
  Connections c({gate, ohmic});
  auto        string = c.to_json_string();
  auto        c2     = Connections::from_json_string<Connections>(string);
  ASSERT_EQ(c2->size(), 2);
  EXPECT_EQ(c2->at(0)->name(), "g");
  EXPECT_EQ(c2->at(1)->name(), "o");
}
}  // namespace
