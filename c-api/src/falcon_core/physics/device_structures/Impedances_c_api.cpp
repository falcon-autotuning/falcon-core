#include "falcon_core/physics/device_structures/Impedances_c_api.h"

#include <falcon_core/physics/device_structures/Impedances.hpp>

#include "falcon_core/generic/ListImpedance_c_api.h"
using namespace falcon_core::physics::device_structures;

extern "C" {

ImpedancesHandle Impedances_create_empty() { return new Impedances(); }

ImpedancesHandle Impedances_create(const ListImpedanceHandle items) {
  auto list_ptr = static_cast<falcon_core::generic::List<Impedance>*>(items);
  return new Impedances(list_ptr->items());
}

void Impedances_destroy(ImpedancesHandle handle) {
  delete static_cast<Impedances*>(handle);
}

ImpedancesHandle Impedances_intersection(ImpedancesHandle handle,
                                         ImpedancesHandle other) {
  falcon_core::generic::ListSP<Impedance> result =
      static_cast<Impedances*>(handle)->intersection(
          std::shared_ptr<Impedances>(static_cast<Impedances*>(other),
                                      [](Impedances*) {}));
  return new Impedances(result->items());
}

void Impedances_push_back(ImpedancesHandle handle, ImpedanceHandle value) {
  static_cast<Impedances*>(handle)->push_back(std::shared_ptr<Impedance>(
      static_cast<Impedance*>(value), [](Impedance*) {}));
}

size_t Impedances_size(ImpedancesHandle handle) {
  return static_cast<Impedances*>(handle)->size();
}

bool Impedances_empty(ImpedancesHandle handle) {
  return static_cast<Impedances*>(handle)->empty();
}

void Impedances_erase_at(ImpedancesHandle handle, size_t idx) {
  static_cast<Impedances*>(handle)->erase_at(idx);
}

void Impedances_clear(ImpedancesHandle handle) {
  static_cast<Impedances*>(handle)->clear();
}

ImpedanceHandle Impedances_const_at(ImpedancesHandle handle, size_t idx) {
  const auto conn = static_cast<Impedances*>(handle)->at(idx);
  return static_cast<ImpedanceHandle>(conn.get());
}

ImpedanceHandle Impedances_at(ImpedancesHandle handle, size_t idx) {
  auto conn = static_cast<Impedances*>(handle)->at(idx);
  return static_cast<ImpedanceHandle>(conn.get());
}

size_t Impedances_items(ImpedancesHandle handle,
                        ImpedanceHandle* out_buffer,
                        size_t           buffer_size) {
  auto&  items   = static_cast<Impedances*>(handle)->items();
  size_t count   = items.size();
  size_t to_copy = (buffer_size < count) ? buffer_size : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = static_cast<ImpedanceHandle>(items[i].get());
  }
  return to_copy;
}

bool Impedances_contains(ImpedancesHandle handle, ImpedanceHandle value) {
  return static_cast<Impedances*>(handle)->contains(std::shared_ptr<Impedance>(
      static_cast<Impedance*>(value), [](Impedance*) {}));
}

size_t Impedances_index(ImpedancesHandle handle, ImpedanceHandle value) {
  return static_cast<Impedances*>(handle)->index(std::shared_ptr<Impedance>(
      static_cast<Impedance*>(value), [](Impedance*) {}));
}

bool Impedances_equal(ImpedancesHandle a, ImpedancesHandle b) {
  return *(static_cast<Impedances*>(a)) == *(static_cast<Impedances*>(b));
}

bool Impedances_not_equal(ImpedancesHandle a, ImpedancesHandle b) {
  return *(static_cast<Impedances*>(a)) != *(static_cast<Impedances*>(b));
}

const char* Impedances_to_json_string(ImpedancesHandle handle) {
  static thread_local std::string json;
  json = static_cast<Impedances*>(handle)->to_json_string();
  return json.c_str();
}

ImpedancesHandle Impedances_from_json_string(const char* json) {
  auto ptr = Impedances::from_json_string<Impedances>(std::string(json));
  return new Impedances(*ptr);
}
}
