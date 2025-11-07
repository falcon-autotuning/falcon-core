#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairGnameGroup_c_api.h"
#include <falcon_core/autotuner_interfaces/names/Gname.hpp>
#include <falcon_core/physics/config/core/Group.hpp>

PairGnameGroupHandle PairGnameGroup_create(GnameHandle first, GroupHandle second) {
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairGnameGroup_create");
                }
                auto first_obj= std::make_shared<falcon_core::autotuner_interfaces::names::Gname>(*static_cast<falcon_core::autotuner_interfaces::names::Gname*>(first));
    
                if (!second) {
                throw std::invalid_argument("Null value passed to PairGnameGroup_create");
                }
                auto second_obj= std::make_shared<falcon_core::physics::config::core::Group>(*static_cast<falcon_core::physics::config::core::Group*>(second));
    return new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>(first_obj, second_obj);
}

void PairGnameGroup_destroy(PairGnameGroupHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairGnameGroup_destroy");
}
    delete static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*>(handle);
}

GnameHandle PairGnameGroup_first(PairGnameGroupHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairGnameGroup_first");
}
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*>(handle);
    return new falcon_core::autotuner_interfaces::names::Gname(*pair->first());
}

GroupHandle PairGnameGroup_second(PairGnameGroupHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairGnameGroup_second");
}
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*>(handle);
    return new falcon_core::physics::config::core::Group(*pair->second());
}

bool PairGnameGroup_equal(PairGnameGroupHandle a, PairGnameGroupHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairGnameGroup_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*>(b);
    return *pair_a == *pair_b;
}

bool PairGnameGroup_not_equal(PairGnameGroupHandle a, PairGnameGroupHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairGnameGroup_not_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*>(b);
    return *pair_a != *pair_b;
}

StringHandle      PairGnameGroup_to_json_string(PairGnameGroupHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairGnameGroup_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

PairGnameGroupHandle PairGnameGroup_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to PairGnameGroup_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>::from_json_string<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>>(json->raw);
  return new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>(*ptr);
}
