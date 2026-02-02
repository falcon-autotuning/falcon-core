#include <falcon_core\generic/Pair.hpp>
#include "falcon_core\generic\PairGnameGroup_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/autotuner_interfaces/names/Gname.hpp>
#include <falcon_core/physics/config/core/Group.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROPairGnameHandleGroupHandle = falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>;
DEFINE_C_API_COPY_TEMPLATE(PairGnameGroup, MACROPairGnameHandleGroupHandle)
DEFINE_C_API_DESTROY_TEMPLATE(PairGnameGroup, MACROPairGnameHandleGroupHandle);
DEFINE_C_API_EQUAL_TEMPLATE(PairGnameGroup, MACROPairGnameHandleGroupHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(PairGnameGroup, MACROPairGnameHandleGroupHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(PairGnameGroup, MACROPairGnameHandleGroupHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(PairGnameGroup, MACROPairGnameHandleGroupHandle);
PairGnameGroupHandle PairGnameGroup_create(GnameHandle first, GroupHandle second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairGnameGroup_create");
                }
                auto first_obj= *static_cast<std::shared_ptr<falcon_core::autotuner_interfaces::names::Gname>*>(first);
    
                if (!second) {
                throw std::invalid_argument("Null value passed to PairGnameGroup_create");
                }
                auto second_obj= *static_cast<std::shared_ptr<falcon_core::physics::config::core::Group>*>(second);
    return new falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>(
        std::make_shared<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

GnameHandle PairGnameGroup_first(PairGnameGroupHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairGnameGroup_first");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*>(handle);
    return new std::shared_ptr<falcon_core::autotuner_interfaces::names::Gname>(pair->first());
    FALCON_C_API_END(nullptr)
}

GroupHandle PairGnameGroup_second(PairGnameGroupHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairGnameGroup_second");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>*>(handle);
    return new std::shared_ptr<falcon_core::physics::config::core::Group>(pair->second());
    FALCON_C_API_END(nullptr)
}
}
