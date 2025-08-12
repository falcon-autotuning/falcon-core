#include <gtest/gtest.h>
#include "falcon_core/NameBase.hpp"
#include "falcon_core/Channel.hpp"
#include "falcon_core/BaseConnection.hpp"
#include "falcon_core/Gate.hpp"
#include "falcon_core/Ohmic.hpp"
#include <string>

using namespace falcon_core;

TEST(NameBaseTest, ConstructionAndAccessors) {
    NameBase<int> nb_int(42);
    ASSERT_EQ(nb_int.name(), 42);

    NameBase<std::string> nb_str("test_name");
    ASSERT_EQ(nb_str.name(), "test_name");
}

TEST(ChannelTest, ConstructionAndSerialization) {
    Channel ch(1);
    ASSERT_EQ(ch.name(), 1);

    nlohmann::json j = ch.to_json();
    ASSERT_EQ(j["__module__"], "falcon_core.physics.device_structures.channel");
    ASSERT_EQ(j["__class__"], "Channel");
    ASSERT_EQ(j["_name"], 1);
}

TEST(BaseConnectionTest, ConstructionAndSerialization) {
    BaseConnection bc("conn1");
    ASSERT_EQ(bc.name(), "conn1");

    nlohmann::json j = bc.to_json();
    ASSERT_EQ(j["__module__"], "falcon_core.physics.device_structures.base_connection");
    ASSERT_EQ(j["__class__"], "BaseConnection");
    ASSERT_EQ(j["_name"], "conn1");
}

TEST(GateTest, InheritanceAndSerialization) {
    Gate g("gate1");
    ASSERT_EQ(g.name(), "gate1");

    // Test inheritance from BaseConnection
    BaseConnection* bc_ptr = &g;
    ASSERT_EQ(bc_ptr->name(), "gate1");

    nlohmann::json j = g.to_json();
    ASSERT_EQ(j["__module__"], "falcon_core.physics.device_structures.gate");
    ASSERT_EQ(j["__class__"], "Gate");
    ASSERT_EQ(j["_name"], "gate1");
}

TEST(OhmicTest, InheritanceAndSerialization) {
    Ohmic o("ohmic1");
    ASSERT_EQ(o.name(), "ohmic1");

    // Test inheritance from BaseConnection
    BaseConnection* bc_ptr = &o;
    ASSERT_EQ(bc_ptr->name(), "ohmic1");

    nlohmann::json j = o.to_json();
    ASSERT_EQ(j["__module__"], "falcon_core.physics.device_structures.ohmic");
    ASSERT_EQ(j["__class__"], "Ohmic");
    ASSERT_EQ(j["_name"], "ohmic1");
}

#include "falcon_core/BaseConnections.hpp"
#include "falcon_core/Impedance.hpp"
#include "falcon_core/Impedances.hpp"
#include "falcon_core/GateRelations.hpp"
#include "falcon_core/Quantity.hpp"
#include "falcon_core/SymbolUnit.hpp"
#include "falcon_core/Unit.hpp"
#include <memory>
#include <complex>

TEST(BaseConnectionsTest, AppendAndIndex) {
    auto g1 = std::make_shared<Gate>("g1");
    auto g2 = std::make_shared<Gate>("g2");
    BaseConnections<Gate> connections;
    connections.append(g1);
    connections.append(g2);

    ASSERT_EQ(connections.index(g1), 0);
    ASSERT_EQ(connections.index(g2), 1);
    ASSERT_THROW(connections.index(std::make_shared<Gate>("g3")), std::out_of_range);
}

TEST(ImpedanceTest, Construction) {
    auto unit = std::make_shared<Unit>(1.0, std::map<std::string, int>{});
    auto symbol_unit = std::make_shared<SymbolUnit>(unit, "Ohm");
    auto quantity = std::make_shared<Quantity<std::complex<double>>>(std::complex<double>(50.0, 25.0), symbol_unit);
    Impedance imp(quantity);

    ASSERT_EQ(imp.get_impedance()->value().real(), 50.0);
    ASSERT_EQ(imp.get_impedance()->value().imag(), 25.0);
}

TEST(ImpedancesTest, Append) {
    auto unit = std::make_shared<Unit>(1.0, std::map<std::string, int>{});
    auto symbol_unit = std::make_shared<SymbolUnit>(unit, "Ohm");
    auto quantity = std::make_shared<Quantity<std::complex<double>>>(std::complex<double>(50.0, 0.0), symbol_unit);
    auto imp1 = std::make_shared<Impedance>(quantity);

    Impedances impedances;
    impedances.append(imp1);
    // A bit hard to test more without an accessor, but we can check serialization
    nlohmann::json j = impedances.to_json();
    ASSERT_EQ(j["_impedances"].size(), 1);
}

TEST(GateRelationsTest, Insert) {
    auto g1 = std::make_shared<Gate>("g1");
    auto g2 = std::make_shared<Gate>("g2");
    auto related_gates = std::make_shared<BaseConnections<Gate>>();
    related_gates->append(g2);

    GateRelations relations;
    relations.insert(g1, related_gates);

    nlohmann::json j = relations.to_json();
    ASSERT_EQ(j["container_size"], 1);
}

#include "falcon_core/StandardConfigConnections.hpp"
#include "falcon_core/Loader.hpp"

TEST(StandardConfigConnectionsTest, ConstructionAndAccessors) {
    auto ohmics = std::make_shared<BaseConnections<Ohmic>>();
    ohmics->append(std::make_shared<Ohmic>("o1"));
    
    auto gates = std::make_shared<BaseConnections<Gate>>();
    gates->append(std::make_shared<Gate>("g1"));

    StandardConfigConnections scc(ohmics, gates);

    ASSERT_EQ(scc.get_ohmics()->get_connections().size(), 1);
    ASSERT_EQ(scc.get_gates()->get_connections().size(), 1);

    nlohmann::json j_scc = scc.to_json();
    ASSERT_EQ(j_scc["__module__"], "falcon_core.physics.config.core.standard_config_connections");
    ASSERT_EQ(j_scc["__class__"], "StandardConfigConnections");
    ASSERT_TRUE(j_scc.contains("_ohmics"));
    ASSERT_TRUE(j_scc.contains("_gates"));
}

TEST(LoaderTest, Construction) {
    auto ohmics = std::make_shared<BaseConnections<Ohmic>>();
    auto gates = std::make_shared<BaseConnections<Gate>>();
    auto scc = std::make_shared<StandardConfigConnections>(ohmics, gates);
    Loader loader(scc);

    nlohmann::json j_loader = loader.to_json();
    ASSERT_EQ(j_loader["__module__"], "falcon_core.physics.config.loader");
    ASSERT_EQ(j_loader["__class__"], "Loader");
    ASSERT_TRUE(j_loader.contains("_config"));
}

#include "falcon_core/Channels.hpp"

TEST(ChannelsTest, AppendAndIndex) {
    auto c1 = std::make_shared<Channel>(1);
    auto c2 = std::make_shared<Channel>(2);
    Channels channels;
    channels.append(c1);
    channels.append(c2);

    ASSERT_EQ(channels.index(c1), 0);
    ASSERT_EQ(channels.index(c2), 1);
    ASSERT_THROW(channels.index(std::make_shared<Channel>(3)), std::out_of_range);
}
