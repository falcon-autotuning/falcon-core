#pragma once

#include <cereal/archives/json.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/types/polymorphic.hpp>
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
  std::string class_name_;
  /**
   * @brief Returns the class name (override if desired).
   */
  virtual std::string class_name() const { return "Song"; }

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
  static std::shared_ptr<Song> from_json_string(const std::string& json);

  /**
   * @brief Deserialize an object from a JSON archive (input stream).
   * @return std::shared_ptr<Song> (actually the derived type)
   */
  static std::shared_ptr<Song> from_json_stream(std::istream& is);
};
}  // namespace generic
}  // namespace falcon_core
