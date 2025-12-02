#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairStringDouble_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
ListPairStringDoubleHandle ListPairStringDouble_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>();
    FALCON_C_API_END(nullptr)
}

ListPairStringDoubleHandle ListPairStringDouble_fill_value(size_t count, PairStringDoubleHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairStringDouble_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::generic::Pair<std::string, double>>(*static_cast<falcon_core::generic::Pair<std::string, double>*>(value));
    
    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>(
        count, stored_obj);
    FALCON_C_API_END(nullptr)
}
 

ListPairStringDoubleHandle ListPairStringDouble_create(PairStringDoubleHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPairStringDouble_create");
}
    std::vector<falcon_core::generic::PairSP<std::string, double>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::make_shared<falcon_core::generic::Pair<std::string, double>>(*static_cast<falcon_core::generic::Pair<std::string, double>*>(data[i]))); 
    }

    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>(vec);
    FALCON_C_API_END(nullptr)
}

void ListPairStringDouble_destroy(ListPairStringDoubleHandle handle) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListPairStringDouble_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle);
    FALCON_C_API_END()
}

size_t ListPairStringDouble_size(ListPairStringDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringDouble_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle)->size();
    FALCON_C_API_END(0)
}

bool ListPairStringDouble_empty(ListPairStringDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringDouble_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle)->empty();
    FALCON_C_API_END(false)
}

void ListPairStringDouble_erase_at(ListPairStringDoubleHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringDouble_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle)->erase_at(idx);
    FALCON_C_API_END()
}

void ListPairStringDouble_clear(ListPairStringDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringDouble_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle)->clear();
    FALCON_C_API_END()
}

void ListPairStringDouble_push_back(ListPairStringDoubleHandle handle, PairStringDoubleHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringDouble_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairStringDouble_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::generic::Pair<std::string, double>>(*static_cast<falcon_core::generic::Pair<std::string, double>*>(value));
    
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle)->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListPairStringDouble_contains(ListPairStringDoubleHandle handle, PairStringDoubleHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringDouble_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairStringDouble_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::generic::Pair<std::string, double>>(*static_cast<falcon_core::generic::Pair<std::string, double>*>(value));
    
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle)->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListPairStringDouble_index(ListPairStringDoubleHandle handle, PairStringDoubleHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringDouble_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairStringDouble_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::generic::Pair<std::string, double>>(*static_cast<falcon_core::generic::Pair<std::string, double>*>(value));
    
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle)->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListPairStringDouble_items(ListPairStringDoubleHandle handle, PairStringDoubleHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
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
    FALCON_C_API_END(0)
}

PairStringDoubleHandle ListPairStringDouble_at(ListPairStringDoubleHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringDouble_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle)->at(idx);
    return new falcon_core::generic::Pair<std::string, double>(*obj);
    FALCON_C_API_END(nullptr)
}

bool ListPairStringDouble_equal(ListPairStringDoubleHandle a, ListPairStringDoubleHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairStringDouble_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(b);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool ListPairStringDouble_not_equal(ListPairStringDoubleHandle a, ListPairStringDoubleHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairStringDouble_not_equal");
}
    return !ListPairStringDouble_equal(a, b);
    FALCON_C_API_END(false)
}

ListPairStringDoubleHandle ListPairStringDouble_intersection(ListPairStringDoubleHandle handle, ListPairStringDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairStringDouble_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>(*result);
    FALCON_C_API_END(nullptr)
}

StringHandle      ListPairStringDouble_to_json_string(ListPairStringDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairStringDouble_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

ListPairStringDoubleHandle ListPairStringDouble_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to ListPairStringDouble_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>>(json->raw);
  return new falcon_core::generic::List<falcon_core::generic::Pair<std::string, double>>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
