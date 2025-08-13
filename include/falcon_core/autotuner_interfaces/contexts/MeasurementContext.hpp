#pragma once

#include "falcon_core/generic/Jsonable.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

#include <memory>

namespace falcon_core
{

class MeasurementContext : public Jsonable
{
public:
  MeasurementContext (std::shared_ptr<BaseConnection> connection,
                      std::shared_ptr<SymbolUnit>     unit);

  const std::shared_ptr<BaseConnection> &connection () const;
  const std::shared_ptr<SymbolUnit>     &unit () const;

  nlohmann::json to_json () const override;
  size_t         hash () const override;

private:
  std::shared_ptr<BaseConnection> _connection;
  std::shared_ptr<SymbolUnit>     _unit;
};

} // namespace falcon_core
