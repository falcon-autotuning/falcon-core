#pragma once

#include "falcon_core/Jsonable.hpp"
#include <functional>
#include <nlohmann/json.hpp>

namespace falcon_core {

template <typename T> class NameBase : public Jsonable {
public:
  NameBase(T name) : _name(name) {}

  T name() const { return _name; }

  nlohmann::json to_json() const override {
    nlohmann::json j;
    // Subclasses should call this and add their own metadata
    j["_name"] = _name;
    return j;
  }

  size_t hash() const override { return std::hash<T>{}(_name); }

protected:
  T _name;
};

} // namespace falcon_core
