#pragma once

#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core {
namespace physics {
namespace units {

struct Units {
  static const SymbolUnit Volt;
  // ... (other units omitted for brevity)
};

}  // namespace units
}  // namespace physics
}  // namespace falcon_core

// Provide definition for Units::Volt
namespace falcon_core {
namespace physics {
namespace units {
inline const SymbolUnit Units::Volt = SymbolUnit();
}  // namespace units
}  // namespace physics
}  // namespace falcon_core

}  // namespace units
}  // namespace physics
}  // namespace falcon_core
