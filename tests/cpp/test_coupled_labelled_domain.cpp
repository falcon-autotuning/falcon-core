#include <gtest/gtest.h>

#include <cereal/archives/binary.hpp>
#include <sstream>

#include "falcon-core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon-core/instrument_interfaces/names/Ports.hpp"
#include "falcon-core/math/domains/CoupledLabelledDomain.hpp"
#include "falcon-core/math/domains/LabelledDomain.hpp"
#include "falcon-core/physics/device_structures/Connection.hpp"
namespace {
using namespace falcon_core;
using namespace physics;
using namespace math::domains;
using namespace instrument_interfaces::names;

class CoupledLabelledDomainTest : public ::testing::Test {
protected:
  // Dummy values for LabelledDomain constructor
  std::string nameA = "A";
  std::string nameB = "B";
  std::string instrument = "instrument1";
  std::pair<double, double> bounds = {0.0, 1.0};
  device_structures::ConnectionSP pseudoA =
      device_structures::Connection::PlungerGate("P1");
  device_structures::ConnectionSP pseudoB =
      device_structures::Connection::PlungerGate("P2");
  Instrument instrumentA = Instrument::Voltage_Source;
  Instrument instrumentB = Instrument::Voltage_Source;
  bool lesser = true;
  bool greater = false;
  units::SymbolUnitSP units = units::SymbolUnit::Volt();
  std::string desc = "desc";
  Scope scope = Scope::Local;
  Access access = Access::Read;
  InstrumentCharacteristic characteristic = InstrumentCharacteristic::None;
  PortType type = PortType::Meter;

  LabelledDomainSP domainA = std::make_shared<LabelledDomain>(
      nameA, instrument, scope, access, characteristic, bounds, type, units,
      desc, pseudoA, instrumentA, lesser, greater);
  InstrumentPortSP portA = domainA->port();
  LabelledDomainSP domainB = std::make_shared<LabelledDomain>(
      nameB, instrument, scope, access, characteristic, bounds, type, units,
      desc, pseudoB, instrumentB, lesser, greater);
  InstrumentPortSP portB = domainB->port();
  CoupledLabelledDomain makeDomainAB() {
    return CoupledLabelledDomain({domainA, domainB});
  }
};

TEST_F(CoupledLabelledDomainTest, DefaultConstructor) {
  CoupledLabelledDomain d;
  EXPECT_TRUE(d.domains().empty());
}

TEST_F(CoupledLabelledDomainTest, VectorConstructor) {
  CoupledLabelledDomain d({domainA, domainB});
  ASSERT_EQ(d.domains().size(), 2);
  EXPECT_EQ(d.domains()[0], domainA);
  EXPECT_EQ(d.domains()[1], domainB);
}

TEST_F(CoupledLabelledDomainTest, LabelsReturnsPorts) {
  CoupledLabelledDomain d({domainA, domainB});
  PortsSP labels = d.labels();
  ASSERT_EQ(labels->size(), 2);
  EXPECT_EQ(*labels->at(0), *portA);
  EXPECT_EQ(*labels->at(1), *portB);
}

TEST_F(CoupledLabelledDomainTest, GetDomainByLabel) {
  CoupledLabelledDomain d({domainA, domainB});
  EXPECT_EQ(d.get_domain(portA), domainA);
  EXPECT_EQ(d.get_domain(portB), domainB);
}

TEST_F(CoupledLabelledDomainTest, GetDomainThrowsOnNullptr) {
  CoupledLabelledDomain d({domainA});
  EXPECT_THROW(d.get_domain(nullptr), std::invalid_argument);
}

TEST_F(CoupledLabelledDomainTest, GetDomainThrowsOnNotFound) {
  CoupledLabelledDomain d({domainA});
  InstrumentPortSP notFound = std::make_shared<InstrumentPort>(
      "X", "instrumentX", Scope::Local, Access::Read,
      InstrumentCharacteristic::None, PortType::Meter);
  EXPECT_THROW(d.get_domain(notFound), std::runtime_error);
}

TEST_F(CoupledLabelledDomainTest, EqualityOperators) {
  CoupledLabelledDomain d1({domainA, domainB});
  CoupledLabelledDomain d2({domainA, domainB});
  CoupledLabelledDomain d3({domainA});
  EXPECT_TRUE(d1 == d2);
  EXPECT_FALSE(d1 != d2);
  EXPECT_FALSE(d1 == d3);
  EXPECT_TRUE(d1 != d3);
}

TEST_F(CoupledLabelledDomainTest, SerializationRoundTrip) {
  CoupledLabelledDomain d1({domainA, domainB});
  std::stringstream ss;
  {
    cereal::BinaryOutputArchive oarchive(ss);
    oarchive(d1);
  }
  CoupledLabelledDomain d2;
  {
    cereal::BinaryInputArchive iarchive(ss);
    iarchive(d2);
  }
  EXPECT_EQ(d1, d2);
}

TEST_F(CoupledLabelledDomainTest, EqualityOperators_DifferentDomainsSameSize) {
  // domainA and domainB are different, so this will trigger the *our_conn !=
  // *other_conn branch
  CoupledLabelledDomain d1({domainA, domainB});
  CoupledLabelledDomain d2({domainA, domainA}); // second domain is different
  EXPECT_FALSE(d1 == d2);
  EXPECT_TRUE(d1 != d2);
}
} // namespace
