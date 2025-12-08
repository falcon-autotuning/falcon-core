#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairGnameGroup_c_api.h"
#include <falcon_core/autotuner_interfaces/names/Gname.hpp>
#include <falcon_core/physics/config/core/Group.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
PairGnameGroupHandle PairGnameGroup_create(GnameHandle first, GroupHandle second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairGnameGroup_create");
                }
                auto first_obj= *static_cast<falcon_core::autotuner_interfaces::names::GnameSP*>(first);
    
                if (!second) {
                throw std::invalid_argument("Null value passed to PairGnameGroup_create");
                }
                auto second_obj= *static_cast<falcon_core::physics::config::core::GroupSP*>(second);
    return new falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>(
        std::make_shared<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

void PairGnameGroup_destroy(PairGnameGroupHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairGnameGroup_destroy");
}
    delete static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*>(handle);
    FALCON_C_API_END()
}

GnameHandle PairGnameGroup_first(PairGnameGroupHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairGnameGroup_first");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*>(handle);
    return new falcon_core::autotuner_interfaces::names::GnameSP(pair->first());
    FALCON_C_API_END(nullptr)
}

GroupHandle PairGnameGroup_second(PairGnameGroupHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairGnameGroup_second");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*>(handle);
    return new falcon_core::physics::config::core::GroupSP(pair->second());
    FALCON_C_API_END(nullptr)
}

bool PairGnameGroup_equal(PairGnameGroupHandle handle, PairGnameGroupHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to PairGnameGroup_equal");
}
    auto pair_a = *static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*>(handle);
    auto pair_b = *static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*>(other);
    return *pair_a == *pair_b;
    FALCON_C_API_END(false)
}

bool PairGnameGroup_not_equal(PairGnameGroupHandle handle, PairGnameGroupHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to PairGnameGroup_not_equal");
}
    auto pair_a = *static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*>(handle);
    auto pair_b = *static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*>(other);
    return *pair_a != *pair_b;
    FALCON_C_API_END(false)
}

StringHandle      PairGnameGroup_to_json_string(PairGnameGroupHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairGnameGroup_to_json_string");
}
std::string json = (*static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle))->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

PairGnameGroupHandle PairGnameGroup_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to PairGnameGroup_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>::from_json_string<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>>(json->raw);
  return new falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>(ptr);
    FALCON_C_API_END(nullptr)
}
}
