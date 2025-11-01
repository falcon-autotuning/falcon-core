#include "falcon_core/math/Sign_c_api.h"

#include <falcon_core/math/Sign.hpp>
using namespace falcon_core::math;

int Sign_positive() { return static_cast<int>(Sign::POSITIVE); }
int Sign_negative() { return static_cast<int>(Sign::NEGATIVE); }
