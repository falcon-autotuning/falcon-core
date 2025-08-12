#pragma once

#include "Jsonable.hpp"

namespace falcon_core {

// A simple wrapper to enforce sign semantics if needed later.
// For now, it's a simple integer.
enum class Sign {
    POSITIVE = 1,
    NEGATIVE = -1
};

} // namespace falcon_core
