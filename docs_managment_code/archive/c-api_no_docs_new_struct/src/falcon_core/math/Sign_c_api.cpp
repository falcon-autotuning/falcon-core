#include "falcon_core/math/Sign_c_api.h"

#include <exception>
#include <falcon_core/math/Sign.hpp>

#include "falcon_core/generic/ErrorHandling_c_api.h"
using namespace falcon_core::math;

extern "C" {
int Sign_positive() {
  FALCON_C_API_BEGIN
  return static_cast<int>(Sign::POSITIVE);
  FALCON_C_API_END(0)
}
int Sign_negative() {
  FALCON_C_API_BEGIN
  return static_cast<int>(Sign::NEGATIVE);
  FALCON_C_API_END(0)
}
}
