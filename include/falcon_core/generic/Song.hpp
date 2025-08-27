#pragma once

#include <cereal/archives/json.hpp>
#include <cereal/types/map.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/types/polymorphic.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/unordered_map.hpp>
#include <cereal/types/utility.hpp>
#include <cereal/types/vector.hpp>
#include <memory>
#include <sstream>
#include <string>

namespace falcon_core {
namespace generic {
/**
 * @brief Abstract base for all serializable Song objects.
 *
 * Inherit from Song in your serializable class, implement serialize(), and
 * register with cereal.
 *
 * @note
 * std::hash<falcon_core::generic::Song> is specialized (see Song.cpp)
 * so Song can be used as a key in std::unordered_map.
 *
 * @section usage Usage
 * @code
 * struct Animal : public Song {
 *     int legs = 4;
 *     template<class Archive>
 *     void serialize(Archive& ar) { ar(CEREAL_NVP(legs)); }
 *     virtual ~Animal() = default;
 * };
 * struct Dog : public Animal {
 *     bool tail = true;
 *     template<class Archive>
 *     void serialize(Archive& ar) {
 *         ar(cereal::base_class<Animal>(this), CEREAL_NVP(tail));
 *     }
 * };
 * CEREAL_REGISTER_TYPE(Animal)
 * CEREAL_REGISTER_TYPE(Dog)
 * CEREAL_REGISTER_POLYMORPHIC_RELATION(Animal, Dog)
 * @endcode
 */

class Song {
 public:
  virtual ~Song() = default;
  /**
   * @brief cereal serialization interface.
   * Override in derived classes.
   */
  template <class Archive>
  void serialize(Archive&) {}

  /**
   * @brief Serialize this object to a JSON string.
   */
  std::string to_json_string() const;

  /**
   * @brief Serialize this object to a JSON archive (output stream).
   */
  void to_json_stream(std::ostream& os) const;

  /**
   * @brief Deserialize an object from a JSON string.
   * @return std::shared_ptr<Song> (actually the derived type)
   */
  template <typename T>
  static std::shared_ptr<T> from_json_string(const std::string& json) {
    std::istringstream iss(json);
    return from_json_stream<T>(iss);
  }

  /**
   * @brief Deserialize an object from a JSON archive (input stream).
   * @return std::shared_ptr<Song> (actually the derived type)
   */
  template <typename T>
  static std::shared_ptr<T> from_json_stream(std::istream& is) {
    cereal::JSONInputArchive archive(is);
    std::shared_ptr<Song>    ptr;
    archive(ptr);
    return std::dynamic_pointer_cast<T>(ptr);
  }
  /**
   * @brief Equality operator.
   * Override in derived classes to compare member variables.
   */
  bool        operator==(const Song& other) const;
  bool        operator!=(const Song& other) const;
  std::string repr() const { return to_json_string(); }
};

struct SongPtrEqual {
  bool operator()(const std::shared_ptr<Song>& a,
                  const std::shared_ptr<Song>& b) const {
    return a->to_json_string() == b->to_json_string();
  }
};

}  // namespace generic
}  // namespace falcon_core
   //
