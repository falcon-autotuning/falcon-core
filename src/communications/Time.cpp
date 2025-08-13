#include "falcon_core/communications/Time.hpp"

#include "falcon_core/constants.hpp"

using namespace falcon_core;
using communications::Time;

Time::Time () : _now (std::chrono::system_clock::now ()) {}

long long
Time::time () const
{
  return std::chrono::duration_cast<std::chrono::seconds> (
             _now.time_since_epoch ())
      .count ();
}

nlohmann::json
Time::to_json () const
{
  nlohmann::json j;
  j["time"] = this->time ();
  add_metadata (j, "falcon_core", "Time");
  return j;
}

size_t
Time::hash () const
{
  return std::hash<long long>{}(this->time ());
}
