#include <gtest/gtest.h>
#include "falcon_core/Jsonable.hpp"
#include <string>

// A concrete implementation for testing
class MyJsonable : public falcon_core::Jsonable {
public:
    MyJsonable(std::string name, int value) : _name(std::move(name)), _value(value) {}

    nlohmann::json to_json() const override {
        nlohmann::json j;
        j["name"] = _name;
        j["value"] = _value;
        add_metadata(j, "my_module", "MyJsonable");
        return j;
    }

    size_t hash() const override {
        return std::hash<std::string>{}(_name) ^ std::hash<int>{}(_value);
    }

private:
    std::string _name;
    int _value;
};


TEST(JsonableTest, Serialization) {
    MyJsonable obj("test_obj", 42);
    
    nlohmann::json j = obj.to_json();
    
    ASSERT_EQ(j["name"], "test_obj");
    ASSERT_EQ(j["value"], 42);
    ASSERT_EQ(j["__module__"], "my_module");
    ASSERT_EQ(j["__class__"], "MyJsonable");
}
