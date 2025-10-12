#include "falcon_core/generic/Song_c_api.h"

#include <falcon_core/generic/Song.hpp>
#include <string>

using namespace falcon_core::generic;

extern "C" {

void Song_destroy(SongHandle handle) { delete static_cast<Song*>(handle); }

const char* Song_to_json_string(SongHandle handle) {
  static thread_local std::string json;
  json = static_cast<Song*>(handle)->to_json_string();
  return json.c_str();
}

SongHandle Song_from_json_string(const char* json) {
  auto ptr = Song::from_json_string<Song>(std::string(json));
  // Return a new copy, caller must call Song_destroy
  return new Song(*ptr);
}

int Song_equal(SongHandle a, SongHandle b) {
  return *(static_cast<Song*>(a)) == *(static_cast<Song*>(b));
}

int Song_not_equal(SongHandle a, SongHandle b) {
  return *(static_cast<Song*>(a)) != *(static_cast<Song*>(b));
}
}
