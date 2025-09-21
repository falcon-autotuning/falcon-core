#include <gtest/gtest.h>

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/math/domains/CoupledLabelledDomain.hpp"
#include "falcon_core/math/domains/Domain.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
namespace tests {
using namespace falcon_core;
using namespace math;
using namespace domains;
using namespace instrument_interfaces::names;
TEST(DomainTest, BasicFunctionality) {
  Domain d(1.0, 5.0);
  EXPECT_DOUBLE_EQ(d.lesser_bound(), 1.0);
  EXPECT_DOUBLE_EQ(d.greater_bound(), 5.0);
  EXPECT_DOUBLE_EQ(d.range(), 4.0);
}

TEST(DomainTest, SerializationRoundTrip) {
  auto        d    = std::make_shared<Domain>(2.0, 7.0);
  std::string json = d->to_json_string();
  auto        d2   = Domain::from_json_string<Domain>(json);
  ASSERT_NE(d2, nullptr);
  EXPECT_DOUBLE_EQ(d2->lesser_bound(), 2.0);
  EXPECT_DOUBLE_EQ(d2->greater_bound(), 7.0);
}

TEST(LabelledDomainTest, BasicFunctionality) {
  auto label = std::make_shared<InstrumentPort>(
      "foo", physics::device_structures::Connection::PlungerGate("P1"));
  LabelledDomainSP ld =
      LabelledDomain::from_port(std::make_pair(0.0, 10.0), label);
  EXPECT_EQ(ld->port()->default_name(), "foo");
  EXPECT_DOUBLE_EQ(ld->lesser_bound(), 0.0);
  EXPECT_DOUBLE_EQ(ld->greater_bound(), 10.0);
}

TEST(LabelledDomainTest, SerializationRoundTrip) {
  InstrumentPortSP label = std::make_shared<InstrumentPort>(
      "bar", physics::device_structures::Connection::BarrierGate("B1"));
  LabelledDomainSP ld =
      LabelledDomain::from_port(std::make_pair(1.0, 2.0), label);
  std::string      json = ld->to_json_string();
  LabelledDomainSP ld2 = LabelledDomain::from_json_string<LabelledDomain>(json);
  ASSERT_NE(ld2, nullptr);
  EXPECT_EQ(ld2->port()->default_name(), "bar");
  EXPECT_DOUBLE_EQ(ld2->lesser_bound(), 1.0);
  EXPECT_DOUBLE_EQ(ld2->greater_bound(), 2.0);
}

TEST(BaseCoupledLabelledDomainTest, BasicFunctionality) {
  auto label1 = std::make_shared<InstrumentPort>("a");
  auto label2 = std::make_shared<InstrumentPort>("b");
  auto d1     = LabelledDomain::from_port(std::make_pair(0.0, 1.0), label1);
  auto d2     = LabelledDomain::from_port(std::make_pair(1.0, 2.0), label2);
  std::vector<std::shared_ptr<LabelledDomain>> domains{d1, d2};
  CoupledLabelledDomain                        bcld(domains);

  EXPECT_EQ(bcld.domains().size(), 2);
  EXPECT_EQ(bcld.labels()->size(), 2);
  EXPECT_EQ(bcld.labels()->at(0)->default_name(), "a");

  auto found = bcld.get_domain(label2);
  EXPECT_EQ(found->port()->default_name(), "b");
}

TEST(BaseCoupledLabelledDomainTest, SerializationRoundTrip) {
  auto label1 = std::make_shared<InstrumentPort>("x");
  auto label2 = std::make_shared<InstrumentPort>("y");
  auto d1     = LabelledDomain::from_port(std::make_pair(5.0, 6.0), label1);
  auto d2     = LabelledDomain::from_port(std::make_pair(6.0, 7.0), label2);
  std::vector<std::shared_ptr<LabelledDomain>> domains{d1, d2};
  auto bcld = std::make_shared<CoupledLabelledDomain>(domains);

  std::string json = bcld->to_json_string();
  auto        bcld2 =
      CoupledLabelledDomain::from_json_string<CoupledLabelledDomain>(json);
  ASSERT_NE(bcld2, nullptr);
  EXPECT_EQ(bcld2->domains().size(), 2);
  EXPECT_EQ(bcld2->labels()->at(1)->default_name(), "y");
}

TEST(CoupledLabelledDomainTest, BasicFunctionality) {
  auto label1 = std::make_shared<InstrumentPort>("first");
  auto label2 = std::make_shared<InstrumentPort>("second");
  auto d1     = LabelledDomain::from_port(std::make_pair(10.0, 20.0), label1);
  auto d2     = LabelledDomain::from_port(std::make_pair(20.0, 30.0), label2);
  std::vector<std::shared_ptr<LabelledDomain>> domains{d1, d2};
  auto cld = std::make_shared<CoupledLabelledDomain>(domains);

  EXPECT_EQ(cld->domains().size(), 2);
  EXPECT_EQ(cld->labels()->at(0)->default_name(), "first");
  EXPECT_EQ(cld->labels()->at(1)->default_name(), "second");
}

TEST(CoupledLabelledDomainTest, SerializationRoundTrip) {
  auto label1 = std::make_shared<InstrumentPort>("first");
  auto label2 = std::make_shared<InstrumentPort>("second");
  auto d1     = LabelledDomain::from_port(std::make_pair(10.0, 20.0), label1);
  auto d2     = LabelledDomain::from_port(std::make_pair(20.0, 30.0), label2);
  std::vector<std::shared_ptr<LabelledDomain>> domains{d1, d2};
  auto cld = std::make_shared<CoupledLabelledDomain>(domains);

  std::string json = cld->to_json_string();
  auto        cld2 =
      CoupledLabelledDomain::from_json_string<CoupledLabelledDomain>(json);
  ASSERT_NE(cld2, nullptr);
  EXPECT_EQ(cld2->domains().size(), 2);
  EXPECT_EQ(cld2->labels()->at(0)->default_name(), "first");
  EXPECT_EQ(cld2->labels()->at(1)->default_name(), "second");
}
}  // namespace tests
