#include "falcon-core/instrument_interfaces/port_transforms/PortTransforms_c_api.h"

#include <falcon-core/instrument_interfaces/port_transforms/PortTransforms.hpp>

#include "falcon-core/Precompiled_c_api.h"

using namespace falcon_core;
using namespace instrument_interfaces;
using namespace port_transforms;
using namespace names;

extern "C" {
DEFINE_C_API_COPY(PortTransforms);
DEFINE_C_API_DESTROY(PortTransforms);
DEFINE_C_API_EQUAL(PortTransforms);
DEFINE_C_API_NOT_EQUAL(PortTransforms);
DEFINE_C_API_TO_JSON(PortTransforms);
DEFINE_C_API_FROM_JSON(PortTransforms);
PortTransformsHandle PortTransforms_create_empty() {
  FALCON_C_API_BEGIN
  return new PortTransformsSP(std::make_shared<PortTransforms>());
  FALCON_C_API_END(nullptr)
}

PortTransformsHandle PortTransforms_create_raw(PortTransformHandle* data,
                                               size_t               count) {
  FALCON_C_API_BEGIN
  if (!data) {
    throw std::invalid_argument(
        "PortTransforms_create_raw: data cannot be null");
  }
  std::vector<PortTransformSP> vec;
  vec.reserve(count);
  for (size_t i = 0; i < count; ++i) {
    vec.push_back(*static_cast<PortTransformSP*>(data[i]));
  }
  generic::ListSP<PortTransform> list =
      std::make_shared<generic::List<PortTransform>>(vec);
  return new PortTransformsSP(std::make_shared<PortTransforms>(list));
  FALCON_C_API_END(nullptr)
}

PortTransformHandle PortTransforms_create(ListPortTransformHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("PortTransforms_create: handle cannot be null");
  }
  falcon_core::generic::ListSP<PortTransform> list =
      *static_cast<falcon_core::generic::ListSP<PortTransform>*>(handle);
  return new PortTransformsSP(std::make_shared<PortTransforms>(list->items()));
  FALCON_C_API_END(nullptr)
}

ListPortTransformHandle PortTransforms_transforms(PortTransformHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "PortTransforms_transforms: handle cannot be null");
  }
  PortTransformsSP self = *static_cast<PortTransformsSP*>(handle);
  return new generic::ListSP<PortTransform>(
      std::make_shared<generic::List<PortTransform>>(
          self->transforms()->items()));
  FALCON_C_API_END(nullptr)
}

void PortTransforms_push_back(PortTransformsHandle handle,
                              PortTransformHandle  value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "PortTransforms_push_back: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument(
        "PortTransforms_push_back: value cannot be null");
  }
  PortTransformsSP self = *static_cast<PortTransformsSP*>(handle);
  self->push_back(*static_cast<PortTransformSP*>(value));
  FALCON_C_API_END()
}

size_t PortTransforms_size(PortTransformsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("PortTransforms_size: handle cannot be null");
  }
  return (*static_cast<PortTransformsSP*>(handle))->size();
  FALCON_C_API_END(0)
}

bool PortTransforms_empty(PortTransformsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("PortTransforms_empty: handle cannot be null");
  }
  return (*static_cast<PortTransformsSP*>(handle))->empty();
  FALCON_C_API_END(false)
}

void PortTransforms_erase_at(PortTransformsHandle handle, size_t idx) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "PortTransforms_erase_at: handle cannot be null");
  }
  (*static_cast<PortTransformsSP*>(handle))->erase_at(idx);
  FALCON_C_API_END()
}

void PortTransforms_clear(PortTransformsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("PortTransforms_clear: handle cannot be null");
  }
  (*static_cast<PortTransformsSP*>(handle))->clear();
  FALCON_C_API_END()
}

PortTransformHandle PortTransforms_at(PortTransformsHandle handle, size_t idx) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("PortTransforms_at: handle cannot be null");
  }
  PortTransformSP conn = (*static_cast<PortTransformsSP*>(handle))->at(idx);
  return new PortTransformSP(conn);
  FALCON_C_API_END(nullptr)
}

ListPortTransformHandle PortTransforms_items(PortTransformsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("PortTransforms_items: handle cannot be null");
  }
  auto items = (*static_cast<PortTransformsSP*>(handle))->items();
  return new falcon_core::generic::ListSP<PortTransform>(
      std::make_shared<falcon_core::generic::List<PortTransform>>(items));
  FALCON_C_API_END(nullptr)
}
bool PortTransforms_contains(PortTransformsHandle handle,
                             PortTransformHandle  value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "PortTransforms_contains: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument(
        "PortTransforms_contains: value cannot be null");
  }
  return (*static_cast<PortTransformsSP*>(handle))
      ->contains(*static_cast<PortTransformSP*>(value));
  FALCON_C_API_END(false)
}

size_t PortTransforms_index(PortTransformsHandle handle,
                            PortTransformHandle  value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("PortTransforms_index: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("PortTransforms_index: value cannot be null");
  }
  return (*static_cast<PortTransformsSP*>(handle))
      ->index(*static_cast<PortTransformSP*>(value));
  FALCON_C_API_END(0)
}

PortTransformsHandle PortTransforms_intersection(PortTransformsHandle handle,
                                                 PortTransformsHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "PortTransforms_intersection: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "PortTransforms_intersection: other cannot be null");
  }
  falcon_core::generic::ListSP<PortTransform> result =
      (*static_cast<PortTransformsSP*>(handle))
          ->intersection(*static_cast<PortTransformsSP*>(other));
  return new PortTransformsSP(
      std::make_shared<PortTransforms>(result->items()));
  FALCON_C_API_END(nullptr)
}
}
