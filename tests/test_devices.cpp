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
