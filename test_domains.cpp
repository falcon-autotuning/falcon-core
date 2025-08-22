#include <gtest/gtest.h>
#include <cereal/archives/json.hpp>
#include <sstream>
#include <memory>
#include <vector>
#include <string>

#include "falcon_core/math/domains/Domain.hpp"
#include "falcon_core/math/domains/LabelledDomain.hpp"
#include "falcon_core/math/domains/BaseLabelledDomain.hpp"
#include "falcon_core/math/domains/BaseCoupledLabelledDomain.hpp"
#include "falcon_core/math/domains/CoupledLabelledDomain.hpp"

// Dummy label type for testing
struct DummyLabel : public falcon_core::generic::Song {
    std::string name;
    int id;
    DummyLabel(std::string n, int i) : name(std::move(n)), id(i) {}
    DummyLabel() : name(""), id(0) {}
    bool operator==(const DummyLabel& other) const { return name == other.name && id == other.id; }

    template <class Archive>
    void serialize(Archive& ar) {
        ar(cereal::base_class<falcon_core::generic::Song>(this), name, id);
    }
};

#ifndef SWIG
CEREAL_REGISTER_TYPE(DummyLabel)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, DummyLabel)
#endif

using namespace falcon_core::math::domains;

TEST(DomainTest, BasicFunctionality) {
    Domain d(1.0, 5.0);
    EXPECT_DOUBLE_EQ(d.min(), 1.0);
    EXPECT_DOUBLE_EQ(d.max(), 5.0);
    EXPECT_DOUBLE_EQ(d.range(), 4.0);
}

TEST(DomainTest, Serialization) {
    Domain d(2.0, 7.0);
    std::stringstream ss;
    {
        cereal::JSONOutputArchive oarchive(ss);
        oarchive(d);
    }
    Domain d2;
    {
        cereal::JSONInputArchive iarchive(ss);
        iarchive(d2);
    }
    EXPECT_DOUBLE_EQ(d2.min(), 2.0);
    EXPECT_DOUBLE_EQ(d2.max(), 7.0);
}

TEST(LabelledDomainTest, BasicFunctionality) {
    auto label = std::make_shared<DummyLabel>("foo", 42);
    LabelledDomain<DummyLabel> ld(0.0, 10.0, label);
    EXPECT_EQ(ld.label()->name, "foo");
    EXPECT_EQ(ld.label()->id, 42);
    EXPECT_DOUBLE_EQ(ld.min(), 0.0);
    EXPECT_DOUBLE_EQ(ld.max(), 10.0);
}

TEST(LabelledDomainTest, Serialization) {
    auto label = std::make_shared<DummyLabel>("bar", 99);
    LabelledDomain<DummyLabel> ld(1.0, 2.0, label);
    std::stringstream ss;
    {
        cereal::JSONOutputArchive oarchive(ss);
        oarchive(ld);
    }
    LabelledDomain<DummyLabel> ld2;
    {
        cereal::JSONInputArchive iarchive(ss);
        iarchive(ld2);
    }
    EXPECT_EQ(ld2.label()->name, "bar");
    EXPECT_EQ(ld2.label()->id, 99);
    EXPECT_DOUBLE_EQ(ld2.min(), 1.0);
    EXPECT_DOUBLE_EQ(ld2.max(), 2.0);
}

TEST(BaseCoupledLabelledDomainTest, BasicFunctionality) {
    auto label1 = std::make_shared<DummyLabel>("a", 1);
    auto label2 = std::make_shared<DummyLabel>("b", 2);
    auto d1 = std::make_shared<LabelledDomain<DummyLabel>>(0.0, 1.0, label1);
    auto d2 = std::make_shared<LabelledDomain<DummyLabel>>(1.0, 2.0, label2);
    std::vector<std::shared_ptr<LabelledDomain<DummyLabel>>> domains{d1, d2};
    BaseCoupledLabelledDomain<DummyLabel> bcld(domains);

    EXPECT_EQ(bcld.domains().size(), 2);
    EXPECT_EQ(bcld.labels().size(), 2);
    EXPECT_EQ(bcld.labels()[0]->name, "a");
    EXPECT_EQ(bcld.labels()[1]->id, 2);

    auto found = bcld.get_domain(label2);
    EXPECT_EQ(found->label()->name, "b");
}

TEST(BaseCoupledLabelledDomainTest, Serialization) {
    auto label1 = std::make_shared<DummyLabel>("x", 10);
    auto label2 = std::make_shared<DummyLabel>("y", 20);
    auto d1 = std::make_shared<LabelledDomain<DummyLabel>>(5.0, 6.0, label1);
    auto d2 = std::make_shared<LabelledDomain<DummyLabel>>(6.0, 7.0, label2);
    std::vector<std::shared_ptr<LabelledDomain<DummyLabel>>> domains{d1, d2};
    BaseCoupledLabelledDomain<DummyLabel> bcld(domains);

    std::stringstream ss;
    {
        cereal::JSONOutputArchive oarchive(ss);
        oarchive(bcld);
    }
    BaseCoupledLabelledDomain<DummyLabel> bcld2;
    {
        cereal::JSONInputArchive iarchive(ss);
        iarchive(bcld2);
    }
    EXPECT_EQ(bcld2.domains().size(), 2);
    EXPECT_EQ(bcld2.labels()[0]->id, 10);
    EXPECT_EQ(bcld2.labels()[1]->name, "y");
}

TEST(CoupledLabelledDomainTest, BasicFunctionalityAndSerialization) {
    auto label1 = std::make_shared<DummyLabel>("first", 100);
    auto label2 = std::make_shared<DummyLabel>("second", 200);
    auto d1 = std::make_shared<LabelledDomain<DummyLabel>>(10.0, 20.0, label1);
    auto d2 = std::make_shared<LabelledDomain<DummyLabel>>(20.0, 30.0, label2);
    std::vector<std::shared_ptr<LabelledDomain<DummyLabel>>> domains{d1, d2};
    CoupledLabelledDomain<DummyLabel> cld(domains);

    EXPECT_EQ(cld.domains().size(), 2);
    EXPECT_EQ(cld.labels()[0]->name, "first");
    EXPECT_EQ(cld.labels()[1]->id, 200);

    std::stringstream ss;
    {
        cereal::JSONOutputArchive oarchive(ss);
        oarchive(cld);
    }
    CoupledLabelledDomain<DummyLabel> cld2;
    {
        cereal::JSONInputArchive iarchive(ss);
        iarchive(cld2);
    }
    EXPECT_EQ(cld2.domains().size(), 2);
    EXPECT_EQ(cld2.labels()[0]->id, 100);
    EXPECT_EQ(cld2.labels()[1]->name, "second");
}
