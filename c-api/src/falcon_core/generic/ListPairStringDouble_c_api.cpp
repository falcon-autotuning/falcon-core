#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairStringDouble_c_api.h"
#include <falcon_core/generic/Pair.hpp>

ListPairStringDoubleHandle ListPairStringDouble_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>(
        falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>());
}

ListPairStringDoubleHandle ListPairStringDouble_fill_value(size_t count, PairStringDoubleHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairStringDouble_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<std::string, double>>(static_cast<falcon_core::generic::Pair<std::string, double>*>(value), [](falcon_core::generic::Pair<std::string, double>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>(
        count, stored_obj);
}
 

ListPairStringDoubleHandle ListPairStringDouble_create(PairStringDoubleHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPairStringDouble_create");
}
    std::vector<falcon_core::generic::PairSP<std::string, double>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::Pair<std::string, double>>(static_cast<falcon_core::generic::Pair<std::string, double>*>(data[i]), [](falcon_core::generic::Pair<std::string, double>*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>(
        falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>(vec));
}

void ListPairStringDouble_destroy(ListPairStringDoubleHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListPairStringDouble_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle);
}

size_t ListPairStringDouble_size(ListPairStringDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringDouble_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle)->size();
}

bool ListPairStringDouble_empty(ListPairStringDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringDouble_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle)->empty();
}

void ListPairStringDouble_erase_at(ListPairStringDoubleHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringDouble_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle)->erase_at(idx);
}

void ListPairStringDouble_clear(ListPairStringDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringDouble_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle)->clear();
}

void ListPairStringDouble_push_back(ListPairStringDoubleHandle handle, PairStringDoubleHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringDouble_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairStringDouble_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<std::string, double>>(static_cast<falcon_core::generic::Pair<std::string, double>*>(value), [](falcon_core::generic::Pair<std::string, double>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle)->push_back(stored_obj);
}

bool ListPairStringDouble_contains(ListPairStringDoubleHandle handle, PairStringDoubleHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringDouble_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairStringDouble_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<std::string, double>>(static_cast<falcon_core::generic::Pair<std::string, double>*>(value), [](falcon_core::generic::Pair<std::string, double>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle)->contains(stored_obj);
}

size_t ListPairStringDouble_index(ListPairStringDoubleHandle handle, PairStringDoubleHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringDouble_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairStringDouble_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<std::string, double>>(static_cast<falcon_core::generic::Pair<std::string, double>*>(value), [](falcon_core::generic::Pair<std::string, double>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle)->index(stored_obj);
}

size_t ListPairStringDouble_items(ListPairStringDoubleHandle handle, PairStringDoubleHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringDouble_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairStringDouble_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::Pair<std::string, double>(*list->items()[i]);
}
    return n;
}

PairStringDoubleHandle ListPairStringDouble_at(ListPairStringDoubleHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringDouble_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle)->at(idx);
    return new falcon_core::generic::Pair<std::string, double>(*obj);
}

bool ListPairStringDouble_equal(ListPairStringDoubleHandle a, ListPairStringDoubleHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairStringDouble_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(b);
    return *listA == *listB;
}

bool ListPairStringDouble_not_equal(ListPairStringDoubleHandle a, ListPairStringDoubleHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairStringDouble_not_equal");
}
    return !ListPairStringDouble_equal(a, b);
}

ListPairStringDoubleHandle ListPairStringDouble_intersection(ListPairStringDoubleHandle handle, ListPairStringDoubleHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairStringDouble_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>(*result);
}

StringHandle      ListPairStringDouble_to_json_string(ListPairStringDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringDouble_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListPairStringDoubleHandle ListPairStringDouble_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListPairStringDouble_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>>(json->raw);
  return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>(*ptr);
}
