#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListDiscretizer_c_api.h"
#include <falcon_core/math/discrete_spaces/Discretizer.hpp>

ListDiscretizerHandle ListDiscretizer_create_empty() {
    return new falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>(
        falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>());
}

ListDiscretizerHandle ListDiscretizer_fill_value(size_t count, DiscretizerHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::discrete_spaces::Discretizer>(static_cast<falcon_core::math::discrete_spaces::Discretizer*>(value), [](falcon_core::math::discrete_spaces::Discretizer*) {} );
    return new falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>(
        falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>(count, stored_obj));
}

ListDiscretizerHandle ListDiscretizer_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>(
        falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>(count));
}

ListDiscretizerHandle ListDiscretizer_create(DiscretizerHandle* data, size_t count) {
    std::vector<falcon_core::math::discrete_spaces::DiscretizerSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::math::discrete_spaces::Discretizer>(static_cast<falcon_core::math::discrete_spaces::Discretizer*>(data[i]), [](falcon_core::math::discrete_spaces::Discretizer*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>(
        falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>(vec));
}

void ListDiscretizer_destroy(ListDiscretizerHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>*>(handle);
}

size_t ListDiscretizer_size(ListDiscretizerHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>*>(handle)->size();
}

bool ListDiscretizer_empty(ListDiscretizerHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>*>(handle)->empty();
}

void ListDiscretizer_erase_at(ListDiscretizerHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>*>(handle)->erase_at(idx);
}

void ListDiscretizer_clear(ListDiscretizerHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>*>(handle)->clear();
}

void ListDiscretizer_push_back(ListDiscretizerHandle handle, DiscretizerHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::discrete_spaces::Discretizer>(static_cast<falcon_core::math::discrete_spaces::Discretizer*>(value), [](falcon_core::math::discrete_spaces::Discretizer*) {} );
    static_cast<falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>*>(handle)->push_back(stored_obj);
}

bool ListDiscretizer_contains(ListDiscretizerHandle handle, DiscretizerHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::discrete_spaces::Discretizer>(static_cast<falcon_core::math::discrete_spaces::Discretizer*>(value), [](falcon_core::math::discrete_spaces::Discretizer*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>*>(handle)->contains(stored_obj);
}

size_t ListDiscretizer_index(ListDiscretizerHandle handle, DiscretizerHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::discrete_spaces::Discretizer>(static_cast<falcon_core::math::discrete_spaces::Discretizer*>(value), [](falcon_core::math::discrete_spaces::Discretizer*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>*>(handle)->index(stored_obj);
}

size_t ListDiscretizer_items(ListDiscretizerHandle handle, DiscretizerHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::math::discrete_spaces::Discretizer(*list->items()[i]);
}
    return n;
}

DiscretizerHandle ListDiscretizer_at(ListDiscretizerHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>*>(handle)->at(idx);
    return new falcon_core::math::discrete_spaces::Discretizer(*obj);
}

bool ListDiscretizer_equal(ListDiscretizerHandle a, ListDiscretizerHandle b) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>*>(b);
    return *listA == *listB;
}

bool ListDiscretizer_not_equal(ListDiscretizerHandle a, ListDiscretizerHandle b) {
    return !ListDiscretizer_equal(a, b);
}

ListDiscretizerHandle ListDiscretizer_intersection(ListDiscretizerHandle handle, ListDiscretizerHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>>(*listB));
    return new falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>(*result);
}

StringHandle      ListDiscretizer_to_json_string(ListDiscretizerHandle handle) {
    std::string json = static_cast<falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListDiscretizerHandle ListDiscretizer_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>::from_json_string<falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>>(json->raw);
  return new falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>(*ptr);
}
