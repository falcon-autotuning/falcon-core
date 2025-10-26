#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairQuantityQuantity_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/math/Quantity.hpp>

ListPairQuantityQuantityHandle ListPairQuantityQuantity_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>());
}

ListPairQuantityQuantityHandle ListPairQuantityQuantity_fill_value(size_t count, PairQuantityQuantityHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>(static_cast<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>*>(value), [](falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>(count, stored_obj));
}

ListPairQuantityQuantityHandle ListPairQuantityQuantity_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>(count));
}

ListPairQuantityQuantityHandle ListPairQuantityQuantity_create(PairQuantityQuantityHandle* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<falcon_core::math::Quantity, falcon_core::math::Quantity>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>(static_cast<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>*>(data[i]), [](falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>(vec));
}

void ListPairQuantityQuantity_destroy(ListPairQuantityQuantityHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(handle);
}

size_t ListPairQuantityQuantity_size(ListPairQuantityQuantityHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(handle)->size();
}

bool ListPairQuantityQuantity_empty(ListPairQuantityQuantityHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(handle)->empty();
}

void ListPairQuantityQuantity_erase_at(ListPairQuantityQuantityHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(handle)->erase_at(idx);
}

void ListPairQuantityQuantity_clear(ListPairQuantityQuantityHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(handle)->clear();
}

void ListPairQuantityQuantity_push_back(ListPairQuantityQuantityHandle handle, PairQuantityQuantityHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>(static_cast<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>*>(value), [](falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(handle)->push_back(stored_obj);
}

bool ListPairQuantityQuantity_contains(ListPairQuantityQuantityHandle handle, PairQuantityQuantityHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>(static_cast<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>*>(value), [](falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(handle)->contains(stored_obj);
}

size_t ListPairQuantityQuantity_index(ListPairQuantityQuantityHandle handle, PairQuantityQuantityHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>(static_cast<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>*>(value), [](falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(handle)->index(stored_obj);
}

size_t ListPairQuantityQuantity_items(ListPairQuantityQuantityHandle handle, PairQuantityQuantityHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>(*list->items()[i]);
}
    return n;
}

PairQuantityQuantityHandle ListPairQuantityQuantity_at(ListPairQuantityQuantityHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(handle)->at(idx);
    return new falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>(*obj);
}

bool ListPairQuantityQuantity_equal(ListPairQuantityQuantityHandle a, ListPairQuantityQuantityHandle b) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(b);
    return *listA == *listB;
}

bool ListPairQuantityQuantity_not_equal(ListPairQuantityQuantityHandle a, ListPairQuantityQuantityHandle b) {
    return !ListPairQuantityQuantity_equal(a, b);
}

ListPairQuantityQuantityHandle ListPairQuantityQuantity_intersection(ListPairQuantityQuantityHandle handle, ListPairQuantityQuantityHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>(*result);
}

StringHandle      ListPairQuantityQuantity_to_json_string(ListPairQuantityQuantityHandle handle) {
    std::string json = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListPairQuantityQuantityHandle ListPairQuantityQuantity_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>>(json->raw);
  return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>(*ptr);
}
