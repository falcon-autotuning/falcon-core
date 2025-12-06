#include "falcon_core/physics/device_structures/Impedances_c_api.h"

#include <falcon_core/physics/device_structures/Impedances.hpp>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/ListImpedance_c_api.h"
using namespace falcon_core::physics::device_structures;

extern "C" {
ImpedancesHandle Impedances_create_empty() {
  FALCON_C_API_BEGIN
  return new ImpedancesSP(std::make_shared<Impedances>());
  FALCON_C_API_END(nullptr)
}

ImpedancesHandle Impedances_create(const ListImpedanceHandle items) {
  FALCON_C_API_BEGIN
  if (!items) {
    throw std::invalid_argument("Impedances_create: items cannot be null");
  }
  falcon_core::generic::ListSP<Impedance> list =
      std::make_shared<falcon_core::generic::List<Impedance>>(
          *static_cast<falcon_core::generic::List<Impedance>*>(items));
  return new ImpedancesSP(std::make_shared<Impedances>(list->items()));
  FALCON_C_API_END(nullptr)
}

void Impedances_destroy(ImpedancesHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Impedances_destroy: handle cannot be null");
  }
  delete static_cast<ImpedancesSP*>(handle);
  FALCON_C_API_END()
}

ImpedancesHandle Impedances_intersection(ImpedancesHandle handle,
                                         ImpedancesHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Impedances_intersection: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "Impedances_intersection: other cannot be null");
  }
  falcon_core::generic::ListSP<Impedance> result =
      (*static_cast<ImpedancesSP*>(handle))
          ->intersection(*static_cast<ImpedancesSP*>(other));
  return new ImpedancesSP(std::make_shared<Impedances>(result->items()));
  FALCON_C_API_END(nullptr)
}

void Impedances_push_back(ImpedancesHandle handle, ImpedanceHandle value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Impedances_push_back: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("Impedances_push_back: value cannot be null");
  }
  (*static_cast<ImpedancesSP*>(handle))
      ->push_back(*static_cast<ImpedanceSP*>(value));
  FALCON_C_API_END()
}

size_t Impedances_size(ImpedancesHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Impedances_size: handle cannot be null");
  }
  return (*static_cast<ImpedancesSP*>(handle))->size();
  FALCON_C_API_END(0)
}

bool Impedances_empty(ImpedancesHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Impedances_empty: handle cannot be null");
  }
  return (*static_cast<ImpedancesSP*>(handle))->empty();
  FALCON_C_API_END(false)
}

void Impedances_erase_at(ImpedancesHandle handle, size_t idx) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Impedances_erase_at: handle cannot be null");
  }
  (*static_cast<ImpedancesSP*>(handle))->erase_at(idx);
  FALCON_C_API_END()
}

void Impedances_clear(ImpedancesHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Impedances_clear: handle cannot be null");
  }
  (*static_cast<ImpedancesSP*>(handle))->clear();
  FALCON_C_API_END()
}

ImpedanceHandle Impedances_at(ImpedancesHandle handle, size_t idx) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Impedances_at: handle cannot be null");
  }
  auto conn = (*static_cast<ImpedancesSP*>(handle))->at(idx);
  return new ImpedanceSP(conn);
  FALCON_C_API_END(nullptr)
}

ListImpedanceHandle Impedances_items(ImpedancesHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Impedances_items: handle cannot be null");
  }
  auto items = (*static_cast<ImpedancesSP*>(handle))->items();
  return new falcon_core::generic::ListSP<Impedance>(
      std::make_shared<falcon_core::generic::List<Impedance>>(items));
  FALCON_C_API_END(nullptr)
}

bool Impedances_contains(ImpedancesHandle handle, ImpedanceHandle value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Impedances_contains: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("Impedances_contains: value cannot be null");
  }
  return (*static_cast<ImpedancesSP*>(handle))
      ->contains(*static_cast<ImpedanceSP*>(value));
  FALCON_C_API_END(false)
}

size_t Impedances_index(ImpedancesHandle handle, ImpedanceHandle value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Impedances_index: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("Impedances_index: value cannot be null");
  }
  return (*static_cast<ImpedancesSP*>(handle))
      ->index(*static_cast<ImpedanceSP*>(value));
  FALCON_C_API_END(0)
}

bool Impedances_equal(ImpedancesHandle a, ImpedancesHandle b) {
  FALCON_C_API_BEGIN
  if (!a) {
    throw std::invalid_argument("Impedances_equal: handle cannot be null");
  }
  if (!b) {
    throw std::invalid_argument("Impedances_equal: handle cannot be null");
  }
  return *(static_cast<ImpedancesSP*>(a)) == *(static_cast<ImpedancesSP*>(b));
  FALCON_C_API_END(false)
}

bool Impedances_not_equal(ImpedancesHandle a, ImpedancesHandle b) {
  FALCON_C_API_BEGIN
  if (!a) {
    throw std::invalid_argument("Impedances_not_equal: handle cannot be null");
  }
  if (!b) {
    throw std::invalid_argument("Impedances_not_equal: handle cannot be null");
  }
  return *(static_cast<ImpedancesSP*>(a)) != *(static_cast<ImpedancesSP*>(b));
  FALCON_C_API_END(false)
}

StringHandle Impedances_to_json_string(ImpedancesHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Impedances_to_json_string: handle cannot be null");
  }
  std::string json = (*static_cast<ImpedancesSP*>(handle))->to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

ImpedancesHandle Impedances_from_json_string(StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "Impedances_from_json_string: json cannot be null");
  }
  auto ptr = Impedances::from_json_string<Impedances>(json->raw);
  return new ImpedancesSP(ptr);
  FALCON_C_API_END(nullptr)
}
}
