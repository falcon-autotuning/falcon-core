#pragma once

#include "falcon_core/Jsonable.hpp"
#include "falcon_core/NameBase.hpp"
#include <memory>
#include <string>

namespace falcon_core {

// Forward declaration
class Instrument;

template <typename T> class InstrumentPort : public Jsonable {
public:
  InstrumentPort(std::string default_name, std::shared_ptr<T> pseudo_name,
                 std::shared_ptr<Instrument> instrument_type,
                 std::string description)
      : _default_name(std::move(default_name)),
        _pseudo_name(std::move(pseudo_name)),
        _instrument_type(std::move(instrument_type)),
        _description(std::move(description)) {}

  const std::string &default_name() const { return _default_name; }
  const std::shared_ptr<T> &pseudo_name() const { return _pseudo_name; }

  nlohmann::json to_json() const override {
    nlohmann::json j;
    add_metadata(j, "falcon_core.instrument_interfaces.names.instrument_port",
                 "InstrumentPort");
    j["_default_name"] = _default_name;
    // Note: pseudo_name and instrument_type serialization requires their
    // definitions. This is a placeholder.
    j["_pseudo_name"] = _pseudo_name->to_json();
    j["_description"] = _description;
    return j;
  }

  size_t hash() const override {
    size_t h1 = std::hash<std::string>{}(_default_name);
    size_t h2 = _pseudo_name ? _pseudo_name->hash() : 0;
    return h1 ^ (h2 << 1);
  }

private:
  std::string _default_name;
  std::shared_ptr<T> _pseudo_name;
  std::shared_ptr<Instrument> _instrument_type;
  std::string _description;
};

} // namespace falcon_core
