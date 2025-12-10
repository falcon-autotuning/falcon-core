#include "falcon_core/communications/Time_c_api.h"

#include <falcon_core/communications/Time.hpp>

#include "falcon_core/Precompiled_c_api.h"

using namespace falcon_core;
using namespace falcon_core::communications;

extern "C" {
DEFINE_C_API_COPY(Time);
DEFINE_C_API_DESTROY(Time);
DEFINE_C_API_EQUAL(Time);
DEFINE_C_API_NOT_EQUAL(Time);
DEFINE_C_API_TO_JSON(Time);
DEFINE_C_API_FROM_JSON(Time);
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
}
