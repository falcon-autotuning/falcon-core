#include <gtest/gtest.h>

#include <memory>
#include <stdexcept>

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentTypes.hpp"
#include "falcon_core/math/domains/LabelledDomain.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"
namespace {
using namespace falcon_core::math::domains;
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::instrument_interfaces::names;
using namespace falcon_core::physics::units;

class LabelledDomainTest : public ::testing::Test {
 protected:
  std::string               default_name   = "test";
  std::pair<double, double> bounds         = {0.0, 1.0};
  ConnectionSP              pseudo_name    = Connection::Ohmic("pseudo");
  Instrument       instrument_type         = InstrumentTypes::DC_VOLTAGE_SOURCE;
  bool             lesser_bound_contained  = true;
  bool             greater_bound_contained = false;
  SymbolUnitSP     units                   = SymbolUnit::Volt();
  std::string      description             = "desc";
  InstrumentPortSP port =
      std::make_shared<InstrumentPort>("port", pseudo_name, instrument_type);

  std::shared_ptr<LabelledDomain> make_domain() {
    return std::make_shared<LabelledDomain>(default_name,
                                            bounds,
                                            pseudo_name,
                                            instrument_type,
                                            lesser_bound_contained,
                                            greater_bound_contained,
                                            units,
                                            description);
  }
};

TEST_F(LabelledDomainTest, ConstructorValid) {
  auto domain = make_domain();
  EXPECT_EQ(domain->port()->default_name(), "test");
}

TEST_F(LabelledDomainTest, ConstructorThrowsOnNullPseudoName) {
  EXPECT_THROW(LabelledDomain(default_name,
                              bounds,
                              nullptr,
                              instrument_type,
                              lesser_bound_contained,
                              greater_bound_contained,
                              units,
                              description),
               std::invalid_argument);
}

TEST_F(LabelledDomainTest, FromPortValid) {
  auto domain = LabelledDomain::from_port(bounds, port);
  EXPECT_EQ(domain->port()->default_name(), "port");
}

TEST_F(LabelledDomainTest, FromPortThrowsOnNullPort) {
  EXPECT_THROW(LabelledDomain::from_port(bounds, nullptr),
               std::invalid_argument);
}

TEST_F(LabelledDomainTest, FromPortAndDomainValid) {
  auto domain  = make_domain();
  auto domain2 = LabelledDomain::from_port_and_domain(port, domain);
  EXPECT_EQ(domain2->port()->default_name(), "port");
}

TEST_F(LabelledDomainTest, FromPortAndDomainThrowsOnNullPort) {
  auto domain = make_domain();
  EXPECT_THROW(LabelledDomain::from_port_and_domain(nullptr, domain),
               std::invalid_argument);
}

TEST_F(LabelledDomainTest, FromPortAndDomainThrowsOnNullDomain) {
  EXPECT_THROW(LabelledDomain::from_port_and_domain(port, nullptr),
               std::invalid_argument);
}

TEST_F(LabelledDomainTest, FromDomainValid) {
  auto domain  = make_domain();
  auto domain2 = LabelledDomain::from_domain(
      domain, default_name, pseudo_name, instrument_type, units, description);
  EXPECT_EQ(domain2->port()->default_name(), "test");
}

TEST_F(LabelledDomainTest, FromDomainThrowsOnNullDomain) {
  EXPECT_THROW(LabelledDomain::from_domain(nullptr,
                                           default_name,
                                           pseudo_name,
                                           instrument_type,
                                           units,
                                           description),
               std::invalid_argument);
}

TEST_F(LabelledDomainTest, FromDomainThrowsOnNullPseudoName) {
  auto domain = make_domain();
  EXPECT_THROW(
      LabelledDomain::from_domain(
          domain, default_name, nullptr, instrument_type, units, description),
      std::invalid_argument);
}

TEST_F(LabelledDomainTest, SerializationRoundTrip) {
  auto domain = make_domain();
  auto json   = domain->to_json_string();
  auto loaded = LabelledDomain::from_json_string<LabelledDomain>(json);
  EXPECT_EQ(domain->port()->default_name(), loaded->port()->default_name());
  EXPECT_EQ(domain->domain()->bounds(), loaded->domain()->bounds());
}

TEST_F(LabelledDomainTest, MatchingPortTrue) {
  auto domain = LabelledDomain::from_port(bounds, port);
  // Use the same port as in the domain
  EXPECT_TRUE(domain->matching_port(port));
}

TEST_F(LabelledDomainTest, MatchingPortFalse) {
  auto domain = make_domain();
  // Different port (different name)
  auto other_port = std::make_shared<InstrumentPort>(
      "other_port", pseudo_name, instrument_type);
  EXPECT_FALSE(domain->matching_port(other_port));
}

TEST_F(LabelledDomainTest, MatchingPortThrowsOnNull) {
  auto domain = make_domain();
  EXPECT_THROW(domain->matching_port(nullptr), std::invalid_argument);
}
}  // namespace
