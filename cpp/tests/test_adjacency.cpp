#include <gtest/gtest.h>

#include "falcon_core/physics/config/core/Adjacency.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/physics/device_structures/Connections.hpp"
CEREAL_REGISTER_TYPE(falcon_core::physics::config::core::Adjacency)
CEREAL_REGISTER_TYPE(falcon_core::generic::FArray<int>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::FArray<int>,
    falcon_core::physics::config::core::Adjacency)
namespace {
using namespace falcon_core;
using namespace physics;
using namespace config;
using namespace core;
using namespace device_structures;

class AdjacencyTest : public ::testing::Test {
 protected:
  ConnectionsSP   indexes;
  xt::xarray<int> matrix;

  void SetUp() override {
    indexes = std::make_shared<Connections>();
    indexes->push_back(Connection::Ohmic("O1"));
    indexes->push_back(Connection::ReservoirGate("R1"));
    indexes->push_back(Connection::BarrierGate("B1"));
    matrix = xt::xarray<int>{{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
  }
};

TEST_F(AdjacencyTest, ConstructorValid) {
  EXPECT_NO_THROW(Adjacency adj(matrix, indexes));
}

TEST_F(AdjacencyTest, ConstructorNullptrIndexesThrows) {
  EXPECT_THROW(Adjacency adj(matrix, nullptr), std::invalid_argument);
}

TEST_F(AdjacencyTest, IndexesReturnsExpected) {
  Adjacency adj(matrix, indexes);
  EXPECT_EQ(adj.indexes(), indexes);
}

TEST_F(AdjacencyTest, GetTruePairsReturnsCorrectPairs) {
  Adjacency                              adj(matrix, indexes);
  auto                                   pairs = adj.get_true_pairs();
  std::vector<std::pair<size_t, size_t>> expected{{0, 1}, {1, 2}};
  EXPECT_EQ(pairs, expected);
}

TEST_F(AdjacencyTest, SerializationRoundTrip) {
  Adjacency adj(matrix, indexes);
  auto      string = adj.to_json_string();
  auto      loaded = Adjacency::from_json_string<Adjacency>(string);
  EXPECT_EQ(adj.shape(), loaded->shape());
  EXPECT_EQ(adj.indexes()->size(), loaded->indexes()->size());
  EXPECT_EQ(adj.get_true_pairs(), loaded->get_true_pairs());
}

TEST_F(AdjacencyTest, EqualityOperatorTrueForIdentical) {
  Adjacency adj1(matrix, indexes);
  Adjacency adj2(matrix, indexes);
  EXPECT_TRUE(adj1 == adj2);
  EXPECT_FALSE(adj1 != adj2);
}

TEST_F(AdjacencyTest, EqualityOperatorFalseForDifferentIndexes) {
  auto other_indexes = std::make_shared<Connections>();
  other_indexes->push_back(Connection::Ohmic("O1"));
  other_indexes->push_back(Connection::ReservoirGate("R1"));
  // Different third connection
  other_indexes->push_back(Connection::BarrierGate("B2"));
  Adjacency adj1(matrix, indexes);
  Adjacency adj2(matrix, other_indexes);
  EXPECT_FALSE(adj1 == adj2);
  EXPECT_TRUE(adj1 != adj2);
}

TEST_F(AdjacencyTest, EqualityOperatorFalseForDifferentMatrix) {
  xt::xarray<int> other_matrix{{0, 0, 0}, {0, 0, 1}, {0, 1, 0}};
  Adjacency       adj1(matrix, indexes);
  Adjacency       adj2(other_matrix, indexes);
  EXPECT_FALSE(adj1 == adj2);
  EXPECT_TRUE(adj1 != adj2);
}
}  // namespace
