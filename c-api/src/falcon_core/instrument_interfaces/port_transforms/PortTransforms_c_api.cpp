#include "falcon_core/instrument_interfaces/port_transforms/PortTransforms_c_api.h"

#include <falcon_core/instrument_interfaces/port_transforms/PortTransforms.hpp>
#include <string>

#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core;
using namespace instrument_interfaces;
using namespace port_transforms;
using namespace names;

PortTransformsHandle PortTransforms_create_empty() {
  return new PortTransforms(PortTransforms());
}

PortTransformsHandle PortTransforms_create_raw(PortTransformHandle* data,
                                               size_t               count) {
  if (!data) {
    throw std::invalid_argument(
        "PortTransforms_create_raw: data cannot be null");
  }
  std::vector<PortTransformSP> vec;
  vec.reserve(count);
  for (size_t i = 0; i < count; ++i) {
    vec.push_back(std::shared_ptr<PortTransform>(
        static_cast<PortTransform*>(data[i]), [](PortTransform*) {}));
  }
  generic::List<PortTransform> list(vec);
  return new PortTransforms(
      std::make_shared<generic::List<PortTransform>>(list));
}

PortTransformHandle PortTransforms_create(ListPortTransformHandle handle) {
  if (!handle) {
    throw std::invalid_argument("PortTransforms_create: handle cannot be null");
  }
  falcon_core::generic::List<PortTransform> list =
      *static_cast<falcon_core::generic::List<PortTransform>*>(handle);
  return new PortTransforms(PortTransforms(list.items()));
}

void PortTransforms_destroy(PortTransformsHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "PortTransforms_destroy: handle cannot be null");
  }
  delete static_cast<PortTransforms*>(handle);
}

ListPortTransformHandle PortTransforms_transforms(PortTransformHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "PortTransforms_transforms: handle cannot be null");
  }
  PortTransforms self = *static_cast<PortTransforms*>(handle);
  return new generic::List<PortTransform>(self.transforms()->items());
}

void PortTransforms_push_back(PortTransformsHandle handle,
                              PortTransformHandle  value) {
  if (!handle) {
    throw std::invalid_argument(
        "PortTransforms_push_back: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument(
        "PortTransforms_push_back: value cannot be null");
  }
  PortTransforms* self = static_cast<PortTransforms*>(handle);
  self->push_back(std::shared_ptr<PortTransform>(
      static_cast<PortTransform*>(value), [](PortTransform*) {}));
}

size_t PortTransforms_size(PortTransformsHandle handle) {
  if (!handle) {
    throw std::invalid_argument("PortTransforms_size: handle cannot be null");
  }
  return static_cast<PortTransforms*>(handle)->size();
}

bool PortTransforms_empty(PortTransformsHandle handle) {
  if (!handle) {
    throw std::invalid_argument("PortTransforms_empty: handle cannot be null");
  }
  return static_cast<PortTransforms*>(handle)->empty();
}

void PortTransforms_erase_at(PortTransformsHandle handle, size_t idx) {
  if (!handle) {
    throw std::invalid_argument(
        "PortTransforms_erase_at: handle cannot be null");
  }
  static_cast<PortTransforms*>(handle)->erase_at(idx);
}

void PortTransforms_clear(PortTransformsHandle handle) {
  if (!handle) {
    throw std::invalid_argument("PortTransforms_clear: handle cannot be null");
  }
  static_cast<PortTransforms*>(handle)->clear();
}

PortTransformHandle PortTransforms_at(PortTransformsHandle handle, size_t idx) {
  if (!handle) {
    throw std::invalid_argument("PortTransforms_at: handle cannot be null");
  }
  PortTransformSP conn = static_cast<PortTransforms*>(handle)->at(idx);
  return new PortTransform(*conn);
}

ListPortTransformHandle PortTransforms_items(PortTransformsHandle handle) {
  if (!handle) {
    throw std::invalid_argument("PortTransforms_items: handle cannot be null");
  }
  auto items = static_cast<PortTransforms*>(handle)->items();
  return new falcon_core::generic::List<PortTransform>(items);
}
bool PortTransforms_contains(PortTransformsHandle handle,
                             PortTransformHandle  value) {
  if (!handle) {
    throw std::invalid_argument(
        "PortTransforms_contains: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument(
        "PortTransforms_contains: value cannot be null");
  }
  return static_cast<PortTransforms*>(handle)->contains(
      std::shared_ptr<PortTransform>(static_cast<PortTransform*>(value),
                                     [](PortTransform*) {}));
}

size_t PortTransforms_index(PortTransformsHandle handle,
                            PortTransformHandle  value) {
  if (!handle) {
    throw std::invalid_argument("PortTransforms_index: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("PortTransforms_index: value cannot be null");
  }
  return static_cast<PortTransforms*>(handle)->index(
      std::shared_ptr<PortTransform>(static_cast<PortTransform*>(value),
                                     [](PortTransform*) {}));
}

PortTransformsHandle PortTransforms_intersection(PortTransformsHandle handle,
                                                 PortTransformsHandle other) {
  if (!handle) {
    throw std::invalid_argument(
        "PortTransforms_intersection: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "PortTransforms_intersection: other cannot be null");
  }
  falcon_core::generic::ListSP<PortTransform> result =
      static_cast<PortTransforms*>(handle)->intersection(
          std::shared_ptr<PortTransforms>(static_cast<PortTransforms*>(other),
                                          [](PortTransforms*) {}));
  return new PortTransforms(result->items());
}

bool PortTransforms_equal(PortTransformsHandle a, PortTransformsHandle b) {
  if (!a) {
    throw std::invalid_argument(
        "PortTransforms_equal: handle a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument(
        "PortTransforms_equal: handle b cannot be null");
  }
  return *(static_cast<PortTransforms*>(a)) ==
         *(static_cast<PortTransforms*>(b));
}

bool PortTransforms_not_equal(PortTransformsHandle a, PortTransformsHandle b) {
  if (!a) {
    throw std::invalid_argument(
        "PortTransforms_not_equal: handle a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument(
        "PortTransforms_not_equal: handle b cannot be null");
  }
  return *(static_cast<PortTransforms*>(a)) !=
         *(static_cast<PortTransforms*>(b));
}

StringHandle PortTransforms_to_json_string(PortTransformsHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "PortTransforms_to_json_string: handle cannot be null");
  }
  std::string json = static_cast<PortTransforms*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

PortTransformsHandle PortTransforms_from_json_string(StringHandle json) {
  if (!json) {
    throw std::invalid_argument(
        "PortTransforms_from_json_string: json cannot be null");
  }
  std::string raw_json(json->raw);
  auto        ptr = PortTransforms::from_json_string<PortTransforms>(raw_json);
  return new PortTransforms(*ptr);
}
