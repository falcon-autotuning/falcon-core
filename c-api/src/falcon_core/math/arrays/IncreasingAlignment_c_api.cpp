#include "falcon_core/math/arrays/IncreasingAlignment_c_api.h"

#include <falcon_core/math/arrays/IncreasingAlignment.hpp>

#include "falcon_core/Precompiled_c_api.h"

using namespace falcon_core;
using namespace falcon_core::math;
using namespace falcon_core::math::arrays;

extern "C" {
DEFINE_C_API_COPY(IncreasingAlignment);
DEFINE_C_API_DESTROY(IncreasingAlignment);
DEFINE_C_API_EQUAL(IncreasingAlignment);
DEFINE_C_API_NOT_EQUAL(IncreasingAlignment);
DEFINE_C_API_TO_JSON(IncreasingAlignment);
DEFINE_C_API_FROM_JSON(IncreasingAlignment);
IncreasingAlignmentHandle IncreasingAlignment_create_empty() {
  FALCON_C_API_BEGIN
  return new IncreasingAlignmentSP(std::make_shared<IncreasingAlignment>());
  FALCON_C_API_END(nullptr)
}
IncreasingAlignmentHandle IncreasingAlignment_create(bool alignment) {
  FALCON_C_API_BEGIN
  return new IncreasingAlignmentSP(
      std::make_shared<IncreasingAlignment>(alignment));
  FALCON_C_API_END(nullptr)
}

int IncreasingAlignment_alignment(IncreasingAlignmentHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "IncreasingAlignment_alignment: handle cannot be null");
  }
  IncreasingAlignmentSP self = *static_cast<IncreasingAlignmentSP*>(handle);
  return self->alignment();
  FALCON_C_API_END(0)
}
}
