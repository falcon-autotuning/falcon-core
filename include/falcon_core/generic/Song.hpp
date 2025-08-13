#pragma once

#include <cstddef>
#include <functional>
#include <memory>
#include <nlohmann/json.hpp>
#include <string>
#include <unordered_map>
namespace falcon_core {
namespace generic {

/**
 * @brief Abstract base for all serializable Song objects.
 *
 * All Song-derived classes must implement to_json() and class_name().
 */
struct ISongBase {
  virtual ~ISongBase()                      = default;
  virtual nlohmann::json to_json() const    = 0;
  virtual std::string    class_name() const = 0;
};

/**
 * @brief Factory function type for Song-derived classes.
 */
using SongFactory =
    std::function<std::unique_ptr<ISongBase>(const nlohmann::json&)>;

/**
 * @brief Registry for Song-derived classes.
 *
 * Allows dynamic creation of Song-derived objects from JSON using the
 * "_class_name" field.
 *
 * @section usage Usage
 * To register a Song-derived class, inherit from Song<YourClass> and provide:
 *   - a static constexpr array of member names
 *   - a static _static_class_name() function
 *   - public aggregate members
 *
 * @section example Example
 * @code
 * struct MySong : Song<MySong> {
 *     std::string _class_name = "MySong";
 *     int _foo = 0;
 *     std::string _bar = "unset";
 *     MySong() : Song("MySong") {}
 *     static constexpr const char* member_names[] = {"_class_name", "_foo",
 * "_bar"}; static std::string _static_class_name() { return "MySong"; }
 * };
 * @endcode
 */
class SongRegistry {
 public:
  static SongRegistry& instance();
  void                 register_class(const std::string& name, SongFactory f);
  std::unique_ptr<ISongBase> create(const nlohmann::json& j) const;

 private:
  std::unordered_map<std::string, SongFactory> registry_;
};

/**
 * @brief Serialize an aggregate type to JSON using Boost.PFR.
 * @tparam T Aggregate type
 * @param j Output JSON
 * @param obj Object to serialize
 * @param names Array of member names
 */
template <typename T, std::size_t N>
void pfr_to_json(nlohmann::json& j,
                 const T&        obj,
                 const char* const (&names)[N]);

/**
 * @brief Deserialize an aggregate type from JSON using Boost.PFR.
 * @tparam T Aggregate type
 * @param j Input JSON
 * @param obj Object to fill
 * @param names Array of member names
 */
template <typename T, std::size_t N>
void pfr_from_json(const nlohmann::json& j,
                   T&                    obj,
                   const char* const (&names)[N]);

/**
 * @brief CRTP base for all Song-derived classes using Boost.PFR.
 *
 * @tparam Derived The derived class type.
 *
 * @section usage Usage
 * Inherit from Song<YourClass> and provide:
 *   - a static constexpr array of member names
 *   - a static _static_class_name() function
 *   - public aggregate members
 */
template <typename Derived>
struct Song : ISongBase {
  std::string _class_name;

  Song(const std::string& name);

  nlohmann::json     to_json() const override;
  std::string        class_name() const override;
  static std::string _static_class_name();
};
}  // namespace generic
}  // namespace falcon_core
