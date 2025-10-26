#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairStringString_c_api.h"
#include <falcon_core/generic/Pair.hpp>

ListPairStringStringHandle ListPairStringString_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>(
        falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>());
}

ListPairStringStringHandle ListPairStringString_fill_value(size_t count, PairStringStringHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<std::string, std::string>>(static_cast<falcon_core::generic::Pair<std::string, std::string>*>(value), [](falcon_core::generic::Pair<std::string, std::string>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>(
        falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>(count, stored_obj));
}

ListPairStringStringHandle ListPairStringString_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>(
        falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>(count));
}

ListPairStringStringHandle ListPairStringString_create(PairStringStringHandle* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<std::string, std::string>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::Pair<std::string, std::string>>(static_cast<falcon_core::generic::Pair<std::string, std::string>*>(data[i]), [](falcon_core::generic::Pair<std::string, std::string>*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>(
        falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>(vec));
}

void ListPairStringString_destroy(ListPairStringStringHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>*>(handle);
}

size_t ListPairStringString_size(ListPairStringStringHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>*>(handle)->size();
}

bool ListPairStringString_empty(ListPairStringStringHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>*>(handle)->empty();
}

void ListPairStringString_erase_at(ListPairStringStringHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>*>(handle)->erase_at(idx);
}

void ListPairStringString_clear(ListPairStringStringHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>*>(handle)->clear();
}

void ListPairStringString_push_back(ListPairStringStringHandle handle, PairStringStringHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<std::string, std::string>>(static_cast<falcon_core::generic::Pair<std::string, std::string>*>(value), [](falcon_core::generic::Pair<std::string, std::string>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>*>(handle)->push_back(stored_obj);
}

bool ListPairStringString_contains(ListPairStringStringHandle handle, PairStringStringHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<std::string, std::string>>(static_cast<falcon_core::generic::Pair<std::string, std::string>*>(value), [](falcon_core::generic::Pair<std::string, std::string>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>*>(handle)->contains(stored_obj);
}

size_t ListPairStringString_index(ListPairStringStringHandle handle, PairStringStringHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<std::string, std::string>>(static_cast<falcon_core::generic::Pair<std::string, std::string>*>(value), [](falcon_core::generic::Pair<std::string, std::string>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>*>(handle)->index(stored_obj);
}

size_t ListPairStringString_items(ListPairStringStringHandle handle, PairStringStringHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::Pair<std::string, std::string>(*list->items()[i]);
}
    return n;
}

PairStringStringHandle ListPairStringString_at(ListPairStringStringHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>*>(handle)->at(idx);
    return new falcon_core::generic::Pair<std::string, std::string>(*obj);
}

bool ListPairStringString_equal(ListPairStringStringHandle a, ListPairStringStringHandle b) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>*>(b);
    return *listA == *listB;
}

bool ListPairStringString_not_equal(ListPairStringStringHandle a, ListPairStringStringHandle b) {
    return !ListPairStringString_equal(a, b);
}

ListPairStringStringHandle ListPairStringString_intersection(ListPairStringStringHandle handle, ListPairStringStringHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>(*result);
}

StringHandle      ListPairStringString_to_json_string(ListPairStringStringHandle handle) {
    std::string json = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListPairStringStringHandle ListPairStringString_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>>(json->raw);
  return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, std::string>>(*ptr);
}
