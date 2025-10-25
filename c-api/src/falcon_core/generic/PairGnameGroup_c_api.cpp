#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairGnameGroup_c_api.h"
#include <falcon_core/autotuner_interfaces/names/Gname.hpp>
#include <falcon_core/physics/config/core/Group.hpp>

PairGnameGroupHandle PairGnameGroup_create(GnameHandle first, GroupHandle second) {
    auto first_obj= std::shared_ptr<falcon_core::autotuner_interfaces::names::Gname>(static_cast<falcon_core::autotuner_interfaces::names::Gname*>(first),[](falcon_core::autotuner_interfaces::names::Gname*) {});
    auto second_obj= std::shared_ptr<falcon_core::physics::config::core::Group>(static_cast<falcon_core::physics::config::core::Group*>(second),[](falcon_core::physics::config::core::Group*) {});
    return new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>(first_obj, second_obj);
}

void PairGnameGroup_destroy(PairGnameGroupHandle handle) {
    delete static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*>(handle);
}

GnameHandle PairGnameGroup_first(PairGnameGroupHandle handle) {
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*>(handle);
    return new falcon_core::autotuner_interfaces::names::Gname(*pair->first());
}

GroupHandle PairGnameGroup_second(PairGnameGroupHandle handle) {
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*>(handle);
    return new falcon_core::physics::config::core::Group(*pair->second());
}

bool PairGnameGroup_equal(PairGnameGroupHandle a, PairGnameGroupHandle b) {
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*>(b);
    return *pair_a == *pair_b;
}

StringHandle      PairGnameGroup_to_json_string(PairGnameGroupHandle handle) {
std::string json = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}
PairGnameGroupHandle PairGnameGroup_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>::from_json_string<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>>(json->raw);
  return new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>(*ptr);
}
