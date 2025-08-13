#pragma once

#include "falcon_core/generic/Song.hpp"

#include <chrono>

namespace falcon_core
{
namespace communications
{

class Time : public generic::Song
{
public:
  Time ();

  // Returns seconds since epoch
  long long      time () const;
  nlohmann::json to_json () const override;
  size_t         hash () const override;

private:
  std::chrono::system_clock::time_point _now;
};
}
} // namespace falcon_core
