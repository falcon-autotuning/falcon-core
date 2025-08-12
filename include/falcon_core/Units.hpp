#pragma once

#include "falcon_core/SymbolUnit.hpp"
#include <memory>

namespace falcon_core {

class Units {
public:
    Units() = delete; // Static class

    static std::shared_ptr<SymbolUnit> V();
    static std::shared_ptr<SymbolUnit> A();
    static std::shared_ptr<SymbolUnit> s();
    static std::shared_ptr<SymbolUnit> Hz();
    static std::shared_ptr<SymbolUnit> dimensionless();
};

} // namespace falcon_core
