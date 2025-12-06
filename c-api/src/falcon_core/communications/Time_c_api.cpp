#include "falcon_core/communications/Time_c_api.h"

#include <falcon_core/generic/String_c_api.h>

#include <falcon_core/communications/Time.hpp>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"

using namespace falcon_core;
using namespace falcon_core::communications;

extern "C" {
TimeHandle Time_create_now() {
  FALCON_C_API_BEGIN
  return new TimeSP(std::make_shared<Time>());
  FALCON_C_API_END(nullptr)
}
TimeHandle Time_create_at(long long micro_seconds_since_epoch) {
  FALCON_C_API_BEGIN
  return new TimeSP(std::make_shared<Time>(micro_seconds_since_epoch));
  FALCON_C_API_END(nullptr)
}

void Time_destroy(TimeHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to Time_destroy");
  }
  delete static_cast<TimeSP*>(handle);
  FALCON_C_API_END()
}

long long Time_micro_seconds_since_epoch(TimeHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to Time_micro_seconds_since_epoch");
  }
  auto time = *static_cast<TimeSP*>(handle);
  return time->micro_seconds_since_epoch();
  FALCON_C_API_END(0.0)
}

long long Time_time(TimeHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to Time_time");
  }
  auto time = *static_cast<TimeSP*>(handle);
  return time->time();
  FALCON_C_API_END(0.0)
}

StringHandle Time_to_string(TimeHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to Time_to_string");
  }
  auto        time = *static_cast<TimeSP*>(handle);
  std::string str  = time->to_string();
  return String_create(str.c_str(), str.size());
  FALCON_C_API_END(nullptr)
}

StringHandle Time_to_json_string(TimeHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to Time_to_json_string");
  }
  auto        time = *static_cast<TimeSP*>(handle);
  std::string json = time->to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

TimeHandle Time_from_json_string(StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "Null string handle passed to Time_from_json_string");
  }
  std::string raw_json(json->raw);
  auto        ptr = Time::from_json_string<Time>(raw_json);
  return new TimeSP(ptr);
  FALCON_C_API_END(nullptr)
}

bool Time_equal(TimeHandle handle, TimeHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Time_equal: handle a cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("Time_equal: handle b cannot be null");
  }
  return *(static_cast<TimeSP*>(handle)) == *(static_cast<TimeSP*>(other));
  FALCON_C_API_END(false)
}

bool Time_not_equal(TimeHandle handle, TimeHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Time_not_equal: handle a cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("Time_not_equal: handle b cannot be null");
  }
  return *(static_cast<TimeSP*>(handle)) != *(static_cast<TimeSP*>(other));
  FALCON_C_API_END(false)
}
}
