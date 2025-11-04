#include "falcon_core/math/arrays/IncreasingAlignment_c_api.h"

#include <falcon_core/math/arrays/IncreasingAlignment.hpp>
#include <string>

using namespace falcon_core;
using namespace falcon_core::math;
using namespace falcon_core::math::arrays;

IncreasingAlignmentHandle IncreasingAlignment_create_empty() {
  return new IncreasingAlignment(IncreasingAlignment());
}
IncreasingAlignmentHandle IncreasingAlignment_create(bool alignment) {
  return new IncreasingAlignment(IncreasingAlignment(alignment));
}

void IncreasingAlignment_destroy(IncreasingAlignmentHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "IncreasingAlignment_destroy: handle cannot be null");
  }
  delete static_cast<IncreasingAlignment*>(handle);
}

int IncreasingAlignment_alignment(IncreasingAlignmentHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "IncreasingAlignment_alignment: handle cannot be null");
  }
  IncreasingAlignment self = *static_cast<IncreasingAlignment*>(handle);
  return self.alignment();
}

bool IncreasingAlignment_equal(IncreasingAlignmentHandle a,
                               IncreasingAlignmentHandle b) {
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
}

bool IncreasingAlignment_not_equal(IncreasingAlignmentHandle a,
                                   IncreasingAlignmentHandle b) {
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
}

StringHandle IncreasingAlignment_to_json_string(
    IncreasingAlignmentHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "IncreasingAlignment_to_json_string: handle cannot be null");
  }
  IncreasingAlignment self = *static_cast<IncreasingAlignment*>(handle);
  std::string         json = self.to_json_string();
  return String_create(json.c_str(), json.size());
}

IncreasingAlignmentHandle IncreasingAlignment_from_json_string(
    StringHandle json) {
  if (!json) {
    throw std::invalid_argument(
        "IncreasingAlignment_from_json_string: json cannot be null");
  }
  std::string raw_json(json->raw);
  auto        ptr =
      IncreasingAlignment::from_json_string<IncreasingAlignment>(raw_json);
  return new IncreasingAlignment(*ptr);
}
