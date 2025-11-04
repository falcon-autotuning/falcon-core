#include "falcon_core/communications/Time_c_api.h"

#include <falcon_core/generic/String_c_api.h>

#include <falcon_core/communications/Time.hpp>
#include <string>

using namespace falcon_core;
using namespace falcon_core::communications;

TimeHandle Time_create_now() { return new Time(Time()); }
TimeHandle Time_create_at(long long micro_seconds_since_epoch) {
  return new Time(Time(micro_seconds_since_epoch));
}

void Time_destroy(TimeHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to Time_destroy");
  }
  delete static_cast<Time*>(handle);
}

long long Time_micro_seconds_since_epoch(TimeHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to Time_micro_seconds_since_epoch");
  }
  auto time = static_cast<Time*>(handle);
  return time->micro_seconds_since_epoch();
}

long long Time_time(TimeHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to Time_time");
  }
  auto time = static_cast<Time*>(handle);
  return time->time();
}

StringHandle Time_to_string(TimeHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to Time_to_string");
  }
  auto        time = static_cast<Time*>(handle);
  std::string str  = time->to_string();
  return String_create(str.c_str(), str.size());
}

bool Time_equal(TimeHandle a, TimeHandle b) {
  if (!a) {
    throw std::invalid_argument("Null handle passed to Time_equal for a");
  }
  if (!b) {
    throw std::invalid_argument("Null handle passed to Time_equal for b");
  }
  return *(static_cast<Time*>(a)) == *(static_cast<Time*>(b));
}

bool Time_not_equal(TimeHandle a, TimeHandle b) {
  if (!a) {
    throw std::invalid_argument("Null handle passed to Time_not_equal for a");
  }
  if (!b) {
    throw std::invalid_argument("Null handle passed to Time_not_equal for b");
  }
  return *(static_cast<Time*>(a)) != *(static_cast<Time*>(b));
}

StringHandle Time_to_json_string(TimeHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to Time_to_json_string");
  }
  auto        time = static_cast<Time*>(handle);
  std::string json = time->to_json_string();
  return String_create(json.c_str(), json.size());
}

TimeHandle Time_from_json_string(StringHandle json) {
  if (!json) {
    throw std::invalid_argument(
        "Null string handle passed to Time_from_json_string");
  }
  std::string raw_json(json->raw);
  auto        ptr = Time::from_json_string<Time>(raw_json);
  return new Time(*ptr);
}
