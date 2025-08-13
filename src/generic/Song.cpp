#include "falcon_core/generic/Song.hpp"

#include <boost/pfr.hpp>
#include <stdexcept>

// --- SongRegistry Implementation ---
using falcon_core::generic::Song;
SongRegistry& SongRegistry::instance() {
  static SongRegistry reg;
  return reg;
}

void SongRegistry::register_class(const std::string& name, SongFactory f) {
  registry_[name] = std::move(f);
}

std::unique_ptr<ISongBase> SongRegistry::create(const nlohmann::json& j) const {
  std::string name = j.at("_class_name").get<std::string>();
  auto        it   = registry_.find(name);
  if (it == registry_.end()) throw std::runtime_error("Unknown class: " + name);
  return it->second(j);
}

// --- PFR-based serialization/deserialization ---

template <typename T, std::size_t N>
void pfr_to_json(nlohmann::json& j,
                 const T&        obj,
                 const char* const (&names)[N]) {
  boost::pfr::for_each_field(
      obj, [&](const auto& field, std::size_t idx) { j[names[idx]] = field; });
}

template <typename T, std::size_t N>
void pfr_from_json(const nlohmann::json& j,
                   T&                    obj,
                   const char* const (&names)[N]) {
  boost::pfr::for_each_field(obj, [&](auto& field, std::size_t idx) {
    field = j.at(names[idx]).get<std::decay_t<decltype(field)>>();
  });
}

// Explicit instantiations for linker (optional, not needed for templates in
// headers)

// --- Song CRTP base implementation ---

template <typename Derived>
Song<Derived>::Song(const std::string& name) : _class_name(name) {
  static bool reg = [] {
    SongRegistry::instance().register_class(
        Derived::_static_class_name(), [](const nlohmann::json& j) {
          auto                  ptr = std::make_unique<Derived>();
          constexpr std::size_t N =
              sizeof(Derived::member_names) / sizeof(Derived::member_names[0]);
          pfr_from_json(j, *ptr, Derived::member_names);
          return ptr;
        });
    return true;
  }();
  (void)reg;
}

template <typename Derived>
nlohmann::json Song<Derived>::to_json() const {
  nlohmann::json        j;
  constexpr std::size_t N =
      sizeof(Derived::member_names) / sizeof(Derived::member_names[0]);
  pfr_to_json(j, static_cast<const Derived&>(*this), Derived::member_names);
  return j;
}

template <typename Derived>
std::string Song<Derived>::class_name() const {
  return _class_name;
}

template <typename Derived>
std::string Song<Derived>::_static_class_name() {
  return Derived::_static_class_name();
}

// Explicit template instantiations (optional, for faster builds)
// template class Song<YourDerivedClass>;
