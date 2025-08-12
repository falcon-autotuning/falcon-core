#include <gtest/gtest.h>
#include "falcon_core/Domain.hpp"
#include "falcon_core/Quantity.hpp"
#include "falcon_core/OneToOneMapping.hpp"
#include "falcon_core/BaseArray.hpp"
#include "falcon_core/ControlArray.hpp"
#include "falcon_core/MeasuredArray.hpp"
#include "falcon_core/Axes.hpp"
#include "falcon_core/Unit.hpp"
#include "falcon_core/Dimension.hpp"
#include "falcon_core/SymbolUnit.hpp"
#include <Eigen/Dense>
#include <memory>

using namespace falcon_core;

// Mock Unit implementation for testing purposes
namespace falcon_core {
    Unit::Unit(double factor, std::map<std::string, int> dimensions) : _factor(factor), _dimensions(std::move(dimensions)) {}
    double Unit::get_factor() const { return _factor; }
    const std::map<std::string, int>& Unit::dimensions() const { return _dimensions; }
    nlohmann::json Unit::to_json() const {
        nlohmann::json j;
        add_metadata(j, "falcon_core.physics.units.unit", "Unit");
        j["_factor"] = _factor;
        return j;
    }
    size_t Unit::hash() const { return std::hash<double>{}(_factor); }
    std::shared_ptr<Unit> Unit::operator*(const Unit& other) const { return nullptr; }
    std::shared_ptr<Unit> Unit::operator/(const Unit& other) const { return nullptr; }
}


TEST(DomainTest, ConstructionAndAccessors) {
    Domain d(0.0, 5.0);
    ASSERT_DOUBLE_EQ(d.min(), 0.0);
    ASSERT_DOUBLE_EQ(d.max(), 5.0);
    ASSERT_DOUBLE_EQ(d.range(), 5.0);

    ASSERT_THROW(Domain(5.0, 0.0), std::invalid_argument);
}

TEST(DomainTest, Serialization) {
    Domain d(1.0, 10.0);
    nlohmann::json j = d.to_json();
    ASSERT_EQ(j["__module__"], "falcon_core.math.domains.domain");
    ASSERT_EQ(j["__class__"], "Domain");
    ASSERT_EQ(j["_min"], 1.0);
    ASSERT_EQ(j["_max"], 10.0);
}

TEST(QuantityTest, ConstructionAndAccessors) {
    auto unit = std::make_shared<Unit>(1.0, std::map<std::string, int>{{"LENGTH", 1}});
    auto symbol_unit = std::make_shared<SymbolUnit>(unit, "m");
    
    Quantity<double> q(12.5, symbol_unit);
    ASSERT_DOUBLE_EQ(q.value(), 12.5);
    ASSERT_EQ(q.unit()->symbol(), "m");
}

TEST(OneToOneMappingTest, InsertionAndLookup) {
    OneToOneMapping<std::string, int> o2o;
    o2o.insert("one", 1);
    o2o.insert("two", 2);

    ASSERT_EQ(o2o.at_key("one"), 1);
    ASSERT_EQ(o2o.at_value(2), "two");

    ASSERT_THROW(o2o.insert("one", 3), std::invalid_argument);
    ASSERT_THROW(o2o.insert("three", 1), std::invalid_argument);
}

TEST(ArrayTest, ConstructionAndData) {
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> m(2, 2);
    m << 1, 2, 3, 4;

    BaseArray<double> ba(m);
    ASSERT_EQ(ba.data(), m);

    ControlArray<double> ca(m);
    ASSERT_EQ(ca.data(), m);

    MeasuredArray<double> ma(m);
    ASSERT_EQ(ma.data(), m);
}

TEST(ArrayTest, Is1D) {
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> row_vec(1, 5);
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> col_vec(5, 1);
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrix(2, 2);

    BaseArray<double> ba_row(row_vec);
    ASSERT_TRUE(ba_row.is_1d());

    BaseArray<double> ba_col(col_vec);
    ASSERT_TRUE(ba_col.is_1d());

    BaseArray<double> ba_mat(matrix);
    ASSERT_FALSE(ba_mat.is_1d());
}

TEST(AxesTest, AppendAndAccess) {
    auto d1 = std::make_shared<Domain>(0, 1);
    auto d2 = std::make_shared<Domain>(1, 2);

    Axes<Domain> axes;
    axes.append(d1);
    axes.append(d2);

    ASSERT_EQ(axes.size(), 2);
    ASSERT_EQ(axes.at(0), d1);
    ASSERT_EQ(axes.at(1), d2);
    ASSERT_FALSE(axes.empty());
}

#include "falcon_core/LabelledDomain.hpp"
#include "falcon_core/CoupledLabelledDomain.hpp"
#include "falcon_core/BaseConnection.hpp"

TEST(LabelledDomainTest, ConstructionAndAccessors) {
    auto label = std::make_shared<BaseConnection>("my_label");
    LabelledDomain<BaseConnection> ld(0.0, 10.0, label);

    ASSERT_DOUBLE_EQ(ld.min(), 0.0);
    ASSERT_EQ(ld.label()->name(), "my_label");

    nlohmann::json j = ld.to_json();
    ASSERT_EQ(j["__class__"], "LabelledDomain");
    ASSERT_TRUE(j.contains("_label"));
}

TEST(CoupledLabelledDomainTest, ConstructionAndAccessors) {
    auto label1 = std::make_shared<BaseConnection>("label1");
    auto coupled_domain = std::make_shared<LabelledDomain<BaseConnection>>(0, 5, label1);

    auto main_label = std::make_shared<BaseConnection>("main_label");
    std::vector<std::shared_ptr<LabelledDomain<BaseConnection>>> coupled_vec;
    coupled_vec.push_back(coupled_domain);

    CoupledLabelledDomain<BaseConnection> cld(0, 10, main_label, coupled_vec);

    ASSERT_EQ(cld.coupled_domains().size(), 1);
    ASSERT_EQ(cld.coupled_domains()[0]->label()->name(), "label1");

    nlohmann::json j = cld.to_json();
    ASSERT_EQ(j["__class__"], "CoupledLabelledDomain");
    ASSERT_TRUE(j.contains("_coupled_domains"));
}

#include "falcon_core/LabelledControlArray1D.hpp"
#include "falcon_core/BaseLabelledArrays.hpp"
#include "falcon_core/InstrumentPort.hpp"
#include "falcon_core/Gate.hpp"

TEST(LabelledControlArray1DTest, ConstructionAndGetStart) {
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> m(1, 3);
    m << 10.0, 20.0, 30.0;
    auto array = std::make_shared<ControlArray1D>(m);
    
    auto instrument = std::shared_ptr<Instrument>(); // Null for testing
    auto gate = std::make_shared<Gate>("g1");
    auto port = std::make_shared<InstrumentPort<Gate>>("port1", gate, instrument, "desc");

    LabelledControlArray1D lca(array, port);

    ASSERT_DOUBLE_EQ(lca.get_start(), 10.0);
    ASSERT_EQ(lca.label()->default_name(), "port1");
}

TEST(BaseLabelledArraysTest, AppendAndAccess) {
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> m(1, 2);
    m << 1.0, 2.0;
    auto array = std::make_shared<ControlArray1D>(m);
    auto instrument = std::shared_ptr<Instrument>();
    auto gate = std::make_shared<Gate>("g1");
    auto port = std::make_shared<InstrumentPort<Gate>>("port1", gate, instrument, "desc");
    auto lca = std::make_shared<LabelledControlArray1D>(array, port);

    BaseLabelledArrays<LabelledControlArray1D> arrays;
    arrays.append(lca);

    ASSERT_EQ(arrays.get_arrays().size(), 1);
    ASSERT_EQ(arrays.get_arrays()[0], lca);
}
