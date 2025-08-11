#pragma once

#include <nlohmann/json.hpp>
#include <string>

namespace falcon_core {

class Jsonable {
public:
    virtual ~Jsonable() = default;

    // In python, from_dict is a classmethod. In C++, this can't be virtual.
    // Deserialization will be handled by concrete classes or a factory.

    virtual nlohmann::json to_json() const = 0;
    
    // The python version has a __hash__.
    virtual size_t hash() const = 0;

    std::string to_json_string() const;

protected:
    // Helper for subclasses to add metadata
    void add_metadata(nlohmann::json& j, const std::string& module_name, const std::string& class_name) const;
};

} // namespace falcon_core
