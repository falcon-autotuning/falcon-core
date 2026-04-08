#include <gtest/gtest.h>

#include "falcon-core/physics/config/core/Adjacency.hpp"
#include "falcon-core/physics/config/core/VoltageConstraints.hpp"
#include "falcon-core/physics/device_structures/Connection.hpp"
#include "falcon-core/physics/device_structures/Connections.hpp"
namespace {
using namespace falcon_core::physics::config::core;
using namespace falcon_core::physics::device_structures;

class VoltageConstraintsTest : public ::testing::Test {
 protected:
  AdjacencySP               adjacency;
  xt::xarray<int>           adj_matrix;
  double                    max_safe_diff;
  std::pair<double, double> bounds;

  void SetUp() override {
    auto indexes = std::make_shared<Connections>();
    indexes->push_back(Connection::Ohmic("O1"));
    indexes->push_back(Connection::ReservoirGate("R1"));
    indexes->push_back(Connection::BarrierGate("B1"));
    adj_matrix    = xt::xarray<int>{{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
    adjacency     = std::make_shared<Adjacency>(adj_matrix, indexes);
    max_safe_diff = 1.5;
    bounds        = {0.0, 5.0};
  }
};

TEST_F(VoltageConstraintsTest, ConstructorValid) {
  EXPECT_NO_THROW(VoltageConstraints vc(adjacency, max_safe_diff, bounds));
}

TEST_F(VoltageConstraintsTest, ConstructorNullptrAdjacencyThrows) {
  EXPECT_THROW(VoltageConstraints vc(nullptr, max_safe_diff, bounds),
               std::invalid_argument);
}

TEST_F(VoltageConstraintsTest, AdjacencyReturnsExpected) {
  VoltageConstraints vc(adjacency, max_safe_diff, bounds);
  EXPECT_EQ(vc.adjacency(), adjacency);
}

TEST_F(VoltageConstraintsTest, LimitsReturnsExpected) {
  VoltageConstraints  vc(adjacency, max_safe_diff, bounds);
  std::vector<double> limits_data{
      5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 1.5, 1.5, 1.5, 1.5};
  EXPECT_EQ(std::vector<double>(vc.limits().raw_data(),
                                vc.limits().raw_data() + vc.limits().size()),
            limits_data);
}

TEST_F(VoltageConstraintsTest, SerializationRoundTrip) {
  VoltageConstraints vc(adjacency, max_safe_diff, bounds);
  auto               string = vc.to_json_string();
  auto               loaded =
      VoltageConstraints::from_json_string<VoltageConstraints>(string);
  EXPECT_EQ(vc.matrix().shape(), loaded->matrix().shape());
  EXPECT_EQ(vc.limits(), loaded->limits());
  // Adjacency shape and indexes
  EXPECT_EQ(vc.adjacency()->shape(), loaded->adjacency()->shape());
  EXPECT_EQ(vc.adjacency()->indexes()->size(),
            loaded->adjacency()->indexes()->size());
}

TEST_F(VoltageConstraintsTest, ConstMatrixGetter) {
  VoltageConstraints        vc(adjacency, max_safe_diff, bounds);
  const VoltageConstraints& cvc = vc;
  const auto&               m   = cvc.matrix();
  EXPECT_EQ(m.shape(), vc.matrix().shape());
}

TEST_F(VoltageConstraintsTest, EqualityOperatorTrueForIdentical) {
  VoltageConstraints vc1(adjacency, max_safe_diff, bounds);
  VoltageConstraints vc2(adjacency, max_safe_diff, bounds);
  EXPECT_TRUE(vc1 == vc2);
  EXPECT_FALSE(vc1 != vc2);
}

TEST_F(VoltageConstraintsTest, EqualityOperatorFalseForDifferentLimits) {
  VoltageConstraints vc1(adjacency, max_safe_diff, bounds);
  VoltageConstraints vc2(adjacency, max_safe_diff, std::make_pair(1.0, 5.0));
  EXPECT_FALSE(vc1 == vc2);
  EXPECT_TRUE(vc1 != vc2);
}

TEST_F(VoltageConstraintsTest, EqualityOperatorFalseForDifferentAdjacency) {
  auto indexes2 = std::make_shared<Connections>();
  indexes2->push_back(Connection::Ohmic("O1"));
  indexes2->push_back(Connection::ReservoirGate("R1"));
  indexes2->push_back(Connection::BarrierGate("B2"));  // Different
  auto               adj2 = std::make_shared<Adjacency>(adj_matrix, indexes2);
  VoltageConstraints vc1(adjacency, max_safe_diff, bounds);
  VoltageConstraints vc2(adj2, max_safe_diff, bounds);
  EXPECT_FALSE(vc1 == vc2);
  EXPECT_TRUE(vc1 != vc2);
}

TEST_F(VoltageConstraintsTest, EqualityOperatorFalseForDifferentMatrix) {
  xt::xarray<int> other_matrix{{0, 0, 0}, {0, 0, 1}, {0, 1, 0}};
  auto adj2 = std::make_shared<Adjacency>(other_matrix, adjacency->indexes());
  VoltageConstraints vc1(adjacency, max_safe_diff, bounds);
  VoltageConstraints vc2(adj2, max_safe_diff, bounds);
  EXPECT_FALSE(vc1 == vc2);
  EXPECT_TRUE(vc1 != vc2);
}
}  // namespace
