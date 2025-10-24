#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairStringDouble_c_api.h"
#include <falcon_core/generic/Pair.hpp>

ListPairStringDoubleHandle ListPairStringDouble_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>(
        falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>());
}

ListPairStringDoubleHandle ListPairStringDouble_fill_value(size_t count, PairStringDoubleHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<std::string, double>>(static_cast<falcon_core::generic::Pair<std::string, double>*>(value), [](falcon_core::generic::Pair<std::string, double>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>(
        falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>(count, stored_obj));
}

ListPairStringDoubleHandle ListPairStringDouble_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>(
        falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>(count));
}

ListPairStringDoubleHandle ListPairStringDouble_create(const PairStringDoubleHandle* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<std::string, double>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::Pair<std::string, double>>(static_cast<falcon_core::generic::Pair<std::string, double>*>(data[i]), [](falcon_core::generic::Pair<std::string, double>*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>(
        falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>(vec));
}

void ListPairStringDouble_destroy(ListPairStringDoubleHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle);
}

size_t ListPairStringDouble_size(ListPairStringDoubleHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle)->size();
}

bool ListPairStringDouble_empty(ListPairStringDoubleHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle)->empty();
}

void ListPairStringDouble_erase_at(ListPairStringDoubleHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle)->erase_at(idx);
}

void ListPairStringDouble_clear(ListPairStringDoubleHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle)->clear();
}

void ListPairStringDouble_push_back(ListPairStringDoubleHandle handle, PairStringDoubleHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<std::string, double>>(static_cast<falcon_core::generic::Pair<std::string, double>*>(value), [](falcon_core::generic::Pair<std::string, double>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle)->push_back(stored_obj);
}

bool ListPairStringDouble_contains(ListPairStringDoubleHandle handle, PairStringDoubleHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<std::string, double>>(static_cast<falcon_core::generic::Pair<std::string, double>*>(value), [](falcon_core::generic::Pair<std::string, double>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle)->contains(stored_obj);
}

size_t ListPairStringDouble_index(ListPairStringDoubleHandle handle, PairStringDoubleHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<std::string, double>>(static_cast<falcon_core::generic::Pair<std::string, double>*>(value), [](falcon_core::generic::Pair<std::string, double>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle)->index(stored_obj);
}

size_t ListPairStringDouble_items(ListPairStringDoubleHandle handle, PairStringDoubleHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::Pair<std::string, double>(*list->items()[i]);
}
    return n;
}

PairStringDoubleHandle ListPairStringDouble_at(ListPairStringDoubleHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle)->at(idx);
    return new falcon_core::generic::Pair<std::string, double>(*obj);
}

bool ListPairStringDouble_equal(ListPairStringDoubleHandle a, ListPairStringDoubleHandle b) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(b);
    return *listA == *listB;
}

bool ListPairStringDouble_not_equal(ListPairStringDoubleHandle a, ListPairStringDoubleHandle b) {
    return !ListPairStringDouble_equal(a, b);
}

ListPairStringDoubleHandle ListPairStringDouble_intersection(ListPairStringDoubleHandle handle, ListPairStringDoubleHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>(*result);
}

StringHandle      ListPairStringDouble_to_json_string(ListPairStringDoubleHandle handle) {
    std::string json = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListPairStringDoubleHandle ListPairStringDouble_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>>(json->raw);
  return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>(*ptr);
}
