#include <gtest/gtest.h>

#include "falcon_core/math/domains/CoupledLabelledDomain.hpp"
namespace tests {
using namespace falcon_core::math::domains;
// Dummy label type for testing
struct DummyLabel : public falcon_core::generic::Song {
  std::string name;
  int         id;
  DummyLabel(std::string n, int i) : name(std::move(n)), id(i) {}
  DummyLabel() : name(""), id(0) {}
  bool operator==(const DummyLabel& other) const {
    return name == other.name && id == other.id;
  }

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<falcon_core::generic::Song>(this), name, id);
  }
};
}  // namespace tests
CEREAL_REGISTER_TYPE(tests::DummyLabel)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     tests::DummyLabel)
CEREAL_REGISTER_TYPE(
    falcon_core::math::domains::BaseLabelledDomain<tests::DummyLabel>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::domains::BaseLabelledDomain<tests::DummyLabel>)

CEREAL_REGISTER_TYPE(
    falcon_core::math::domains::BaseCoupledLabelledDomain<tests::DummyLabel>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::domains::BaseCoupledLabelledDomain<tests::DummyLabel>)

CEREAL_REGISTER_TYPE(
    falcon_core::math::domains::CoupledLabelledDomain<tests::DummyLabel>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::domains::CoupledLabelledDomain<tests::DummyLabel>)

namespace tests {

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
  auto label = std::make_shared<DummyLabel>("foo", 42);
  BaseLabelledDomain<DummyLabel> ld(0.0, 10.0, label);
  EXPECT_EQ(ld.label()->name, "foo");
  EXPECT_EQ(ld.label()->id, 42);
  EXPECT_DOUBLE_EQ(ld.lesser_bound(), 0.0);
  EXPECT_DOUBLE_EQ(ld.greater_bound(), 10.0);
}

TEST(LabelledDomainTest, SerializationRoundTrip) {
  auto label = std::make_shared<DummyLabel>("bar", 99);
  auto ld = std::make_shared<BaseLabelledDomain<DummyLabel>>(1.0, 2.0, label);
  std::string json = ld->to_json_string();
  auto        ld2  = BaseLabelledDomain<DummyLabel>::from_json_string<
              BaseLabelledDomain<DummyLabel>>(json);
  ASSERT_NE(ld2, nullptr);
  EXPECT_EQ(ld2->label()->name, "bar");
  EXPECT_EQ(ld2->label()->id, 99);
  EXPECT_DOUBLE_EQ(ld2->lesser_bound(), 1.0);
  EXPECT_DOUBLE_EQ(ld2->greater_bound(), 2.0);
}

TEST(BaseCoupledLabelledDomainTest, BasicFunctionality) {
  auto label1 = std::make_shared<DummyLabel>("a", 1);
  auto label2 = std::make_shared<DummyLabel>("b", 2);
  auto d1 = std::make_shared<BaseLabelledDomain<DummyLabel>>(0.0, 1.0, label1);
  auto d2 = std::make_shared<BaseLabelledDomain<DummyLabel>>(1.0, 2.0, label2);
  std::vector<std::shared_ptr<BaseLabelledDomain<DummyLabel>>> domains{d1, d2};
  BaseCoupledLabelledDomain<DummyLabel>                        bcld(domains);

  EXPECT_EQ(bcld.domains().size(), 2);
  EXPECT_EQ(bcld.labels()->size(), 2);
  EXPECT_EQ(bcld.labels()->at(0)->name, "a");
  EXPECT_EQ(bcld.labels()->at(1)->id, 2);

  auto found = bcld.get_domain(label2);
  EXPECT_EQ(found->label()->name, "b");
}

TEST(BaseCoupledLabelledDomainTest, SerializationRoundTrip) {
  auto label1 = std::make_shared<DummyLabel>("x", 10);
  auto label2 = std::make_shared<DummyLabel>("y", 20);
  auto d1 = std::make_shared<BaseLabelledDomain<DummyLabel>>(5.0, 6.0, label1);
  auto d2 = std::make_shared<BaseLabelledDomain<DummyLabel>>(6.0, 7.0, label2);
  std::vector<std::shared_ptr<BaseLabelledDomain<DummyLabel>>> domains{d1, d2};
  auto bcld = std::make_shared<BaseCoupledLabelledDomain<DummyLabel>>(domains);

  std::string json  = bcld->to_json_string();
  auto        bcld2 = BaseCoupledLabelledDomain<DummyLabel>::from_json_string<
             BaseCoupledLabelledDomain<DummyLabel>>(json);
  ASSERT_NE(bcld2, nullptr);
  EXPECT_EQ(bcld2->domains().size(), 2);
  EXPECT_EQ(bcld2->labels()->at(0)->id, 10);
  EXPECT_EQ(bcld2->labels()->at(1)->name, "y");
}

TEST(CoupledLabelledDomainTest, BasicFunctionality) {
  auto label1 = std::make_shared<DummyLabel>("first", 100);
  auto label2 = std::make_shared<DummyLabel>("second", 200);
  auto d1 =
      std::make_shared<BaseLabelledDomain<DummyLabel>>(10.0, 20.0, label1);
  auto d2 =
      std::make_shared<BaseLabelledDomain<DummyLabel>>(20.0, 30.0, label2);
  std::vector<std::shared_ptr<BaseLabelledDomain<DummyLabel>>> domains{d1, d2};
  auto cld = std::make_shared<CoupledLabelledDomain<DummyLabel>>(domains);

  EXPECT_EQ(cld->domains().size(), 2);
  EXPECT_EQ(cld->labels()->at(0)->name, "first");
  EXPECT_EQ(cld->labels()->at(0)->id, 100);
  EXPECT_EQ(cld->labels()->at(1)->name, "second");
  EXPECT_EQ(cld->labels()->at(1)->id, 200);
}

TEST(CoupledLabelledDomainTest, SerializationRoundTrip) {
  auto label1 = std::make_shared<DummyLabel>("first", 100);
  auto label2 = std::make_shared<DummyLabel>("second", 200);
  auto d1 =
      std::make_shared<BaseLabelledDomain<DummyLabel>>(10.0, 20.0, label1);
  auto d2 =
      std::make_shared<BaseLabelledDomain<DummyLabel>>(20.0, 30.0, label2);
  std::vector<std::shared_ptr<BaseLabelledDomain<DummyLabel>>> domains{d1, d2};
  auto cld = std::make_shared<CoupledLabelledDomain<DummyLabel>>(domains);

  std::string json = cld->to_json_string();
  auto        cld2 = CoupledLabelledDomain<DummyLabel>::from_json_string<
             CoupledLabelledDomain<DummyLabel>>(json);
  ASSERT_NE(cld2, nullptr);
  EXPECT_EQ(cld2->domains().size(), 2);
  EXPECT_EQ(cld2->labels()->at(0)->name, "first");
  EXPECT_EQ(cld2->labels()->at(0)->id, 100);
  EXPECT_EQ(cld2->labels()->at(1)->name, "second");
  EXPECT_EQ(cld2->labels()->at(1)->id, 200);
}
}  // namespace tests
