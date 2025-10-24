#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairStringBool_c_api.h"
#include <falcon_core/generic/Pair.hpp>

ListPairStringBoolHandle ListPairStringBool_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>(
        falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>());
}

ListPairStringBoolHandle ListPairStringBool_fill_value(size_t count, PairStringBoolHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<std::string, bool>>(static_cast<falcon_core::generic::Pair<std::string, bool>*>(value), [](falcon_core::generic::Pair<std::string, bool>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>(
        falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>(count, stored_obj));
}

ListPairStringBoolHandle ListPairStringBool_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>(
        falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>(count));
}

ListPairStringBoolHandle ListPairStringBool_create(const PairStringBoolHandle* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<std::string, bool>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::Pair<std::string, bool>>(static_cast<falcon_core::generic::Pair<std::string, bool>*>(data[i]), [](falcon_core::generic::Pair<std::string, bool>*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>(
        falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>(vec));
}

void ListPairStringBool_destroy(ListPairStringBoolHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(handle);
}

size_t ListPairStringBool_size(ListPairStringBoolHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(handle)->size();
}

bool ListPairStringBool_empty(ListPairStringBoolHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(handle)->empty();
}

void ListPairStringBool_erase_at(ListPairStringBoolHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(handle)->erase_at(idx);
}

void ListPairStringBool_clear(ListPairStringBoolHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(handle)->clear();
}

void ListPairStringBool_push_back(ListPairStringBoolHandle handle, PairStringBoolHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<std::string, bool>>(static_cast<falcon_core::generic::Pair<std::string, bool>*>(value), [](falcon_core::generic::Pair<std::string, bool>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(handle)->push_back(stored_obj);
}

bool ListPairStringBool_contains(ListPairStringBoolHandle handle, PairStringBoolHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<std::string, bool>>(static_cast<falcon_core::generic::Pair<std::string, bool>*>(value), [](falcon_core::generic::Pair<std::string, bool>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(handle)->contains(stored_obj);
}

size_t ListPairStringBool_index(ListPairStringBoolHandle handle, PairStringBoolHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<std::string, bool>>(static_cast<falcon_core::generic::Pair<std::string, bool>*>(value), [](falcon_core::generic::Pair<std::string, bool>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(handle)->index(stored_obj);
}

size_t ListPairStringBool_items(ListPairStringBoolHandle handle, PairStringBoolHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::Pair<std::string, bool>(*list->items()[i]);
}
    return n;
}

PairStringBoolHandle ListPairStringBool_at(ListPairStringBoolHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(handle)->at(idx);
    return new falcon_core::generic::Pair<std::string, bool>(*obj);
}

bool ListPairStringBool_equal(ListPairStringBoolHandle a, ListPairStringBoolHandle b) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(b);
    return *listA == *listB;
}

bool ListPairStringBool_not_equal(ListPairStringBoolHandle a, ListPairStringBoolHandle b) {
    return !ListPairStringBool_equal(a, b);
}

ListPairStringBoolHandle ListPairStringBool_intersection(ListPairStringBoolHandle handle, ListPairStringBoolHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>(*result);
}

StringHandle      ListPairStringBool_to_json_string(ListPairStringBoolHandle handle) {
    std::string json = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListPairStringBoolHandle ListPairStringBool_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>>(json->raw);
  return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, bool>>(*ptr);
}
