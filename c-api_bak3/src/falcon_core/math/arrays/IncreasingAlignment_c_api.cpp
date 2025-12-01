#include "falcon_core/math/arrays/IncreasingAlignment_c_api.h"

#include <falcon_core/math/arrays/IncreasingAlignment.hpp>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"

using namespace falcon_core;
using namespace falcon_core::math;
using namespace falcon_core::math::arrays;

extern "C" {
IncreasingAlignmentHandle IncreasingAlignment_create_empty() {
  FALCON_C_API_BEGIN
  return new IncreasingAlignment(IncreasingAlignment());
  FALCON_C_API_END(nullptr)
}
IncreasingAlignmentHandle IncreasingAlignment_create(bool alignment) {
  FALCON_C_API_BEGIN
  return new IncreasingAlignment(IncreasingAlignment(alignment));
  FALCON_C_API_END(nullptr)
}

void IncreasingAlignment_destroy(IncreasingAlignmentHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "IncreasingAlignment_destroy: handle cannot be null");
  }
  delete static_cast<IncreasingAlignment*>(handle);
  FALCON_C_API_END()
}

int IncreasingAlignment_alignment(IncreasingAlignmentHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "IncreasingAlignment_alignment: handle cannot be null");
  }
  IncreasingAlignment self = *static_cast<IncreasingAlignment*>(handle);
  return self.alignment();
  FALCON_C_API_END(0)
}

bool IncreasingAlignment_equal(IncreasingAlignmentHandle a,
                               IncreasingAlignmentHandle b) {
  FALCON_C_API_BEGIN
  if (!a) {
    throw std::invalid_argument(
        "IncreasingAlignment_equal: handle a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument(
        "IncreasingAlignment_equal: handle b cannot be null");
  }
  return *(static_cast<IncreasingAlignment*>(a)) ==
         *(static_cast<IncreasingAlignment*>(b));
  FALCON_C_API_END(false)
}

bool IncreasingAlignment_not_equal(IncreasingAlignmentHandle a,
                                   IncreasingAlignmentHandle b) {
  FALCON_C_API_BEGIN
  if (!a) {
    throw std::invalid_argument(
        "IncreasingAlignment_not_equal: handle a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument(
        "IncreasingAlignment_not_equal: handle b cannot be null");
  }
  return *(static_cast<IncreasingAlignment*>(a)) !=
         *(static_cast<IncreasingAlignment*>(b));
  FALCON_C_API_END(false)
}

StringHandle IncreasingAlignment_to_json_string(
    IncreasingAlignmentHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "IncreasingAlignment_to_json_string: handle cannot be null");
  }
  IncreasingAlignment self = *static_cast<IncreasingAlignment*>(handle);
  std::string         json = self.to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

IncreasingAlignmentHandle IncreasingAlignment_from_json_string(
    StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "IncreasingAlignment_from_json_string: json cannot be null");
  }
  std::string raw_json(json->raw);
  auto        ptr =
      IncreasingAlignment::from_json_string<IncreasingAlignment>(raw_json);
  return new IncreasingAlignment(*ptr);
  FALCON_C_API_END(nullptr)
}
}
