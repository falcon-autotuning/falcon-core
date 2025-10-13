#include <falcon_core/generic/List.hpp>
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>
#include "falcon_core/generic/Pair_c_api.h"
#include "falcon_core/generic/List_c_api.h"

using namespace falcon_core::generic;
using namespace falcon_core::physics::device_structures;

// Implementation for all list types

ListIntHandle ListInt_create_empty() {
    return new std::shared_ptr<List<int>>(
        std::make_shared<List<int>>());
}

ListIntHandle ListInt_allocate(size_t count) {
    return new std::shared_ptr<List<int>>(
        std::make_shared<List<int>>(count));
}

ListIntHandle ListInt_fill_value(size_t count, int value) {
    return new std::shared_ptr<List<int>>(
        std::make_shared<List<int>>(count, value));
}

ListIntHandle ListInt_create(const int* data, size_t count) {
    std::vector<int> vec(data, data + count);
    return new std::shared_ptr<List<int>>(
        std::make_shared<List<int>>(vec));
}

void ListInt_destroy(ListIntHandle handle) {
    delete static_cast<std::shared_ptr<List<int>>*>(handle);
}

void ListInt_push_back(ListIntHandle handle, int value) {
    (*static_cast<std::shared_ptr<List<int>>*>(handle))->push_back(value);
}

size_t ListInt_size(ListIntHandle handle) {
    return (*static_cast<std::shared_ptr<List<int>>*>(handle))->size();
}

bool ListInt_empty(ListIntHandle handle) {
    return (*static_cast<std::shared_ptr<List<int>>*>(handle))->empty();
}

void ListInt_erase_at(ListIntHandle handle, size_t idx) {
    (*static_cast<std::shared_ptr<List<int>>*>(handle))->erase_at(idx);
}

void ListInt_clear(ListIntHandle handle) {
    (*static_cast<std::shared_ptr<List<int>>*>(handle))->clear();
}

int ListInt_const_at(ListIntHandle handle, size_t idx) {
    return (*static_cast<std::shared_ptr<List<int>>*>(handle))->at(idx);
}

int ListInt_at(ListIntHandle handle, size_t idx) {
    return (*static_cast<std::shared_ptr<List<int>>*>(handle))->at(idx);
}

size_t ListInt_items(ListIntHandle handle, int* out_buffer, size_t buffer_size) {
    auto& list = *static_cast<std::shared_ptr<List<int>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    std::copy_n(list->items().begin(), n, out_buffer);
    return n;
}

bool ListInt_contains(ListIntHandle handle, int value) {
    return (*static_cast<std::shared_ptr<List<int>>*>(handle))->contains(value);
}

size_t ListInt_index(ListIntHandle handle, int value) {
    return (*static_cast<std::shared_ptr<List<int>>*>(handle))->index(value);
}

ListIntHandle ListInt_intersection(ListIntHandle handle, ListIntHandle other) {
    auto& listA = *static_cast<std::shared_ptr<List<int>>*>(handle);
    auto& listB = *static_cast<std::shared_ptr<List<int>>*>(other);
    auto result = listA->intersection(listB);
    return new std::shared_ptr<List<int>>(result);
}

bool ListInt_equal(ListIntHandle a, ListIntHandle b) {
    auto& listA = *static_cast<std::shared_ptr<List<int>>*>(a);
    auto& listB = *static_cast<std::shared_ptr<List<int>>*>(b);
    return *listA == *listB;
}

bool ListInt_not_equal(ListIntHandle a, ListIntHandle b) {
    return !ListInt_equal(a, b);
}

ListFloatHandle ListFloat_create_empty() {
    return new std::shared_ptr<List<float>>(
        std::make_shared<List<float>>());
}

ListFloatHandle ListFloat_allocate(size_t count) {
    return new std::shared_ptr<List<float>>(
        std::make_shared<List<float>>(count));
}

ListFloatHandle ListFloat_fill_value(size_t count, float value) {
    return new std::shared_ptr<List<float>>(
        std::make_shared<List<float>>(count, value));
}

ListFloatHandle ListFloat_create(const float* data, size_t count) {
    std::vector<float> vec(data, data + count);
    return new std::shared_ptr<List<float>>(
        std::make_shared<List<float>>(vec));
}

void ListFloat_destroy(ListFloatHandle handle) {
    delete static_cast<std::shared_ptr<List<float>>*>(handle);
}

void ListFloat_push_back(ListFloatHandle handle, float value) {
    (*static_cast<std::shared_ptr<List<float>>*>(handle))->push_back(value);
}

size_t ListFloat_size(ListFloatHandle handle) {
    return (*static_cast<std::shared_ptr<List<float>>*>(handle))->size();
}

bool ListFloat_empty(ListFloatHandle handle) {
    return (*static_cast<std::shared_ptr<List<float>>*>(handle))->empty();
}

void ListFloat_erase_at(ListFloatHandle handle, size_t idx) {
    (*static_cast<std::shared_ptr<List<float>>*>(handle))->erase_at(idx);
}

void ListFloat_clear(ListFloatHandle handle) {
    (*static_cast<std::shared_ptr<List<float>>*>(handle))->clear();
}

float ListFloat_const_at(ListFloatHandle handle, size_t idx) {
    return (*static_cast<std::shared_ptr<List<float>>*>(handle))->at(idx);
}

float ListFloat_at(ListFloatHandle handle, size_t idx) {
    return (*static_cast<std::shared_ptr<List<float>>*>(handle))->at(idx);
}

size_t ListFloat_items(ListFloatHandle handle, float* out_buffer, size_t buffer_size) {
    auto& list = *static_cast<std::shared_ptr<List<float>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    std::copy_n(list->items().begin(), n, out_buffer);
    return n;
}

bool ListFloat_contains(ListFloatHandle handle, float value) {
    return (*static_cast<std::shared_ptr<List<float>>*>(handle))->contains(value);
}

size_t ListFloat_index(ListFloatHandle handle, float value) {
    return (*static_cast<std::shared_ptr<List<float>>*>(handle))->index(value);
}

ListFloatHandle ListFloat_intersection(ListFloatHandle handle, ListFloatHandle other) {
    auto& listA = *static_cast<std::shared_ptr<List<float>>*>(handle);
    auto& listB = *static_cast<std::shared_ptr<List<float>>*>(other);
    auto result = listA->intersection(listB);
    return new std::shared_ptr<List<float>>(result);
}

bool ListFloat_equal(ListFloatHandle a, ListFloatHandle b) {
    auto& listA = *static_cast<std::shared_ptr<List<float>>*>(a);
    auto& listB = *static_cast<std::shared_ptr<List<float>>*>(b);
    return *listA == *listB;
}

bool ListFloat_not_equal(ListFloatHandle a, ListFloatHandle b) {
    return !ListFloat_equal(a, b);
}

ListPairIntIntHandle ListPairIntInt_create_empty() {
    return new std::shared_ptr<List<falcon_core::generic::Pair<int, int>>>(
        std::make_shared<List<falcon_core::generic::Pair<int, int>>>());
}

ListPairIntIntHandle ListPairIntInt_allocate(size_t count) {
    return new std::shared_ptr<List<falcon_core::generic::Pair<int, int>>>(
        std::make_shared<List<falcon_core::generic::Pair<int, int>>>(count));
}

ListPairIntIntHandle ListPairIntInt_fill_value(size_t count, PairIntIntHandle value) {
    auto stored_obj = *static_cast<falcon_core::generic::PairSP<int, int>*>(value);
    return new std::shared_ptr<List<falcon_core::generic::Pair<int, int>>>(
        std::make_shared<List<falcon_core::generic::Pair<int, int>>>(count, stored_obj));
}

ListPairIntIntHandle ListPairIntInt_create(const PairIntIntHandle* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<int, int>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<falcon_core::generic::PairSP<int, int>*>(data[i]));
    }
    return new std::shared_ptr<List<falcon_core::generic::Pair<int, int>>>(
        std::make_shared<List<falcon_core::generic::Pair<int, int>>>(vec));
}

void ListPairIntInt_destroy(ListPairIntIntHandle handle) {
    delete static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, int>>>*>(handle);
}

void ListPairIntInt_push_back(ListPairIntIntHandle handle, PairIntIntHandle value) {
    auto stored_obj = *static_cast<falcon_core::generic::PairSP<int, int>*>(value);
    (*static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, int>>>*>(handle))->push_back(stored_obj);
}

size_t ListPairIntInt_size(ListPairIntIntHandle handle) {
    return (*static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, int>>>*>(handle))->size();
}

bool ListPairIntInt_empty(ListPairIntIntHandle handle) {
    return (*static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, int>>>*>(handle))->empty();
}

void ListPairIntInt_erase_at(ListPairIntIntHandle handle, size_t idx) {
    (*static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, int>>>*>(handle))->erase_at(idx);
}

void ListPairIntInt_clear(ListPairIntIntHandle handle) {
    (*static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, int>>>*>(handle))->clear();
}

PairIntIntHandle ListPairIntInt_const_at(ListPairIntIntHandle handle, size_t idx) {
    auto& obj = (*static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, int>>>*>(handle))->at(idx);
    return new falcon_core::generic::PairSP<int, int>(obj);
}

PairIntIntHandle ListPairIntInt_at(ListPairIntIntHandle handle, size_t idx) {
    auto& obj = (*static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, int>>>*>(handle))->at(idx);
    return new falcon_core::generic::PairSP<int, int>(obj);
}

size_t ListPairIntInt_items(ListPairIntIntHandle handle, PairIntIntHandle* out_buffer, size_t buffer_size) {
    auto& list = *static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, int>>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    for (size_t i = 0; i < n; ++i) {
        out_buffer[i] = new falcon_core::generic::PairSP<int, int>(list->items()[i]);
    }
    return n;
}

bool ListPairIntInt_contains(ListPairIntIntHandle handle, PairIntIntHandle value) {
    auto stored_obj = *static_cast<falcon_core::generic::PairSP<int, int>*>(value);
    return (*static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, int>>>*>(handle))->contains(stored_obj);
}

size_t ListPairIntInt_index(ListPairIntIntHandle handle, PairIntIntHandle value) {
    auto stored_obj = *static_cast<falcon_core::generic::PairSP<int, int>*>(value);
    return (*static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, int>>>*>(handle))->index(stored_obj);
}

ListPairIntIntHandle ListPairIntInt_intersection(ListPairIntIntHandle handle, ListPairIntIntHandle other) {
    auto& listA = *static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, int>>>*>(handle);
    auto& listB = *static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, int>>>*>(other);
    auto result = listA->intersection(listB);
    return new std::shared_ptr<List<falcon_core::generic::Pair<int, int>>>(result);
}

bool ListPairIntInt_equal(ListPairIntIntHandle a, ListPairIntIntHandle b) {
    auto& listA = *static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, int>>>*>(a);
    auto& listB = *static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, int>>>*>(b);
    return *listA == *listB;
}

bool ListPairIntInt_not_equal(ListPairIntIntHandle a, ListPairIntIntHandle b) {
    return !ListPairIntInt_equal(a, b);
}

ListPairFloatFloatHandle ListPairFloatFloat_create_empty() {
    return new std::shared_ptr<List<falcon_core::generic::Pair<float, float>>>(
        std::make_shared<List<falcon_core::generic::Pair<float, float>>>());
}

ListPairFloatFloatHandle ListPairFloatFloat_allocate(size_t count) {
    return new std::shared_ptr<List<falcon_core::generic::Pair<float, float>>>(
        std::make_shared<List<falcon_core::generic::Pair<float, float>>>(count));
}

ListPairFloatFloatHandle ListPairFloatFloat_fill_value(size_t count, PairFloatFloatHandle value) {
    auto stored_obj = *static_cast<falcon_core::generic::PairSP<float, float>*>(value);
    return new std::shared_ptr<List<falcon_core::generic::Pair<float, float>>>(
        std::make_shared<List<falcon_core::generic::Pair<float, float>>>(count, stored_obj));
}

ListPairFloatFloatHandle ListPairFloatFloat_create(const PairFloatFloatHandle* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<float, float>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<falcon_core::generic::PairSP<float, float>*>(data[i]));
    }
    return new std::shared_ptr<List<falcon_core::generic::Pair<float, float>>>(
        std::make_shared<List<falcon_core::generic::Pair<float, float>>>(vec));
}

void ListPairFloatFloat_destroy(ListPairFloatFloatHandle handle) {
    delete static_cast<std::shared_ptr<List<falcon_core::generic::Pair<float, float>>>*>(handle);
}

void ListPairFloatFloat_push_back(ListPairFloatFloatHandle handle, PairFloatFloatHandle value) {
    auto stored_obj = *static_cast<falcon_core::generic::PairSP<float, float>*>(value);
    (*static_cast<std::shared_ptr<List<falcon_core::generic::Pair<float, float>>>*>(handle))->push_back(stored_obj);
}

size_t ListPairFloatFloat_size(ListPairFloatFloatHandle handle) {
    return (*static_cast<std::shared_ptr<List<falcon_core::generic::Pair<float, float>>>*>(handle))->size();
}

bool ListPairFloatFloat_empty(ListPairFloatFloatHandle handle) {
    return (*static_cast<std::shared_ptr<List<falcon_core::generic::Pair<float, float>>>*>(handle))->empty();
}

void ListPairFloatFloat_erase_at(ListPairFloatFloatHandle handle, size_t idx) {
    (*static_cast<std::shared_ptr<List<falcon_core::generic::Pair<float, float>>>*>(handle))->erase_at(idx);
}

void ListPairFloatFloat_clear(ListPairFloatFloatHandle handle) {
    (*static_cast<std::shared_ptr<List<falcon_core::generic::Pair<float, float>>>*>(handle))->clear();
}

PairFloatFloatHandle ListPairFloatFloat_const_at(ListPairFloatFloatHandle handle, size_t idx) {
    auto& obj = (*static_cast<std::shared_ptr<List<falcon_core::generic::Pair<float, float>>>*>(handle))->at(idx);
    return new falcon_core::generic::PairSP<float, float>(obj);
}

PairFloatFloatHandle ListPairFloatFloat_at(ListPairFloatFloatHandle handle, size_t idx) {
    auto& obj = (*static_cast<std::shared_ptr<List<falcon_core::generic::Pair<float, float>>>*>(handle))->at(idx);
    return new falcon_core::generic::PairSP<float, float>(obj);
}

size_t ListPairFloatFloat_items(ListPairFloatFloatHandle handle, PairFloatFloatHandle* out_buffer, size_t buffer_size) {
    auto& list = *static_cast<std::shared_ptr<List<falcon_core::generic::Pair<float, float>>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    for (size_t i = 0; i < n; ++i) {
        out_buffer[i] = new falcon_core::generic::PairSP<float, float>(list->items()[i]);
    }
    return n;
}

bool ListPairFloatFloat_contains(ListPairFloatFloatHandle handle, PairFloatFloatHandle value) {
    auto stored_obj = *static_cast<falcon_core::generic::PairSP<float, float>*>(value);
    return (*static_cast<std::shared_ptr<List<falcon_core::generic::Pair<float, float>>>*>(handle))->contains(stored_obj);
}

size_t ListPairFloatFloat_index(ListPairFloatFloatHandle handle, PairFloatFloatHandle value) {
    auto stored_obj = *static_cast<falcon_core::generic::PairSP<float, float>*>(value);
    return (*static_cast<std::shared_ptr<List<falcon_core::generic::Pair<float, float>>>*>(handle))->index(stored_obj);
}

ListPairFloatFloatHandle ListPairFloatFloat_intersection(ListPairFloatFloatHandle handle, ListPairFloatFloatHandle other) {
    auto& listA = *static_cast<std::shared_ptr<List<falcon_core::generic::Pair<float, float>>>*>(handle);
    auto& listB = *static_cast<std::shared_ptr<List<falcon_core::generic::Pair<float, float>>>*>(other);
    auto result = listA->intersection(listB);
    return new std::shared_ptr<List<falcon_core::generic::Pair<float, float>>>(result);
}

bool ListPairFloatFloat_equal(ListPairFloatFloatHandle a, ListPairFloatFloatHandle b) {
    auto& listA = *static_cast<std::shared_ptr<List<falcon_core::generic::Pair<float, float>>>*>(a);
    auto& listB = *static_cast<std::shared_ptr<List<falcon_core::generic::Pair<float, float>>>*>(b);
    return *listA == *listB;
}

bool ListPairFloatFloat_not_equal(ListPairFloatFloatHandle a, ListPairFloatFloatHandle b) {
    return !ListPairFloatFloat_equal(a, b);
}

ListPairIntFloatHandle ListPairIntFloat_create_empty() {
    return new std::shared_ptr<List<falcon_core::generic::Pair<int, float>>>(
        std::make_shared<List<falcon_core::generic::Pair<int, float>>>());
}

ListPairIntFloatHandle ListPairIntFloat_allocate(size_t count) {
    return new std::shared_ptr<List<falcon_core::generic::Pair<int, float>>>(
        std::make_shared<List<falcon_core::generic::Pair<int, float>>>(count));
}

ListPairIntFloatHandle ListPairIntFloat_fill_value(size_t count, PairIntFloatHandle value) {
    auto stored_obj = *static_cast<falcon_core::generic::PairSP<int, float>*>(value);
    return new std::shared_ptr<List<falcon_core::generic::Pair<int, float>>>(
        std::make_shared<List<falcon_core::generic::Pair<int, float>>>(count, stored_obj));
}

ListPairIntFloatHandle ListPairIntFloat_create(const PairIntFloatHandle* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<int, float>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<falcon_core::generic::PairSP<int, float>*>(data[i]));
    }
    return new std::shared_ptr<List<falcon_core::generic::Pair<int, float>>>(
        std::make_shared<List<falcon_core::generic::Pair<int, float>>>(vec));
}

void ListPairIntFloat_destroy(ListPairIntFloatHandle handle) {
    delete static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, float>>>*>(handle);
}

void ListPairIntFloat_push_back(ListPairIntFloatHandle handle, PairIntFloatHandle value) {
    auto stored_obj = *static_cast<falcon_core::generic::PairSP<int, float>*>(value);
    (*static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, float>>>*>(handle))->push_back(stored_obj);
}

size_t ListPairIntFloat_size(ListPairIntFloatHandle handle) {
    return (*static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, float>>>*>(handle))->size();
}

bool ListPairIntFloat_empty(ListPairIntFloatHandle handle) {
    return (*static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, float>>>*>(handle))->empty();
}

void ListPairIntFloat_erase_at(ListPairIntFloatHandle handle, size_t idx) {
    (*static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, float>>>*>(handle))->erase_at(idx);
}

void ListPairIntFloat_clear(ListPairIntFloatHandle handle) {
    (*static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, float>>>*>(handle))->clear();
}

PairIntFloatHandle ListPairIntFloat_const_at(ListPairIntFloatHandle handle, size_t idx) {
    auto& obj = (*static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, float>>>*>(handle))->at(idx);
    return new falcon_core::generic::PairSP<int, float>(obj);
}

PairIntFloatHandle ListPairIntFloat_at(ListPairIntFloatHandle handle, size_t idx) {
    auto& obj = (*static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, float>>>*>(handle))->at(idx);
    return new falcon_core::generic::PairSP<int, float>(obj);
}

size_t ListPairIntFloat_items(ListPairIntFloatHandle handle, PairIntFloatHandle* out_buffer, size_t buffer_size) {
    auto& list = *static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, float>>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    for (size_t i = 0; i < n; ++i) {
        out_buffer[i] = new falcon_core::generic::PairSP<int, float>(list->items()[i]);
    }
    return n;
}

bool ListPairIntFloat_contains(ListPairIntFloatHandle handle, PairIntFloatHandle value) {
    auto stored_obj = *static_cast<falcon_core::generic::PairSP<int, float>*>(value);
    return (*static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, float>>>*>(handle))->contains(stored_obj);
}

size_t ListPairIntFloat_index(ListPairIntFloatHandle handle, PairIntFloatHandle value) {
    auto stored_obj = *static_cast<falcon_core::generic::PairSP<int, float>*>(value);
    return (*static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, float>>>*>(handle))->index(stored_obj);
}

ListPairIntFloatHandle ListPairIntFloat_intersection(ListPairIntFloatHandle handle, ListPairIntFloatHandle other) {
    auto& listA = *static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, float>>>*>(handle);
    auto& listB = *static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, float>>>*>(other);
    auto result = listA->intersection(listB);
    return new std::shared_ptr<List<falcon_core::generic::Pair<int, float>>>(result);
}

bool ListPairIntFloat_equal(ListPairIntFloatHandle a, ListPairIntFloatHandle b) {
    auto& listA = *static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, float>>>*>(a);
    auto& listB = *static_cast<std::shared_ptr<List<falcon_core::generic::Pair<int, float>>>*>(b);
    return *listA == *listB;
}

bool ListPairIntFloat_not_equal(ListPairIntFloatHandle a, ListPairIntFloatHandle b) {
    return !ListPairIntFloat_equal(a, b);
}

ListConnectionHandle ListConnection_create_empty() {
    return new std::shared_ptr<List<falcon_core::physics::device_structures::Connection>>(
        std::make_shared<List<falcon_core::physics::device_structures::Connection>>());
}

ListConnectionHandle ListConnection_allocate(size_t count) {
    return new std::shared_ptr<List<falcon_core::physics::device_structures::Connection>>(
        std::make_shared<List<falcon_core::physics::device_structures::Connection>>(count));
}

ListConnectionHandle ListConnection_fill_value(size_t count, ConnectionHandle value) {
    auto stored_obj = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(value);
    return new std::shared_ptr<List<falcon_core::physics::device_structures::Connection>>(
        std::make_shared<List<falcon_core::physics::device_structures::Connection>>(count, stored_obj));
}

ListConnectionHandle ListConnection_create(const ConnectionHandle* data, size_t count) {
    std::vector<falcon_core::physics::device_structures::ConnectionSP> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<falcon_core::physics::device_structures::ConnectionSP*>(data[i]));
    }
    return new std::shared_ptr<List<falcon_core::physics::device_structures::Connection>>(
        std::make_shared<List<falcon_core::physics::device_structures::Connection>>(vec));
}

void ListConnection_destroy(ListConnectionHandle handle) {
    delete static_cast<std::shared_ptr<List<falcon_core::physics::device_structures::Connection>>*>(handle);
}

void ListConnection_push_back(ListConnectionHandle handle, ConnectionHandle value) {
    auto stored_obj = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(value);
    (*static_cast<std::shared_ptr<List<falcon_core::physics::device_structures::Connection>>*>(handle))->push_back(stored_obj);
}

size_t ListConnection_size(ListConnectionHandle handle) {
    return (*static_cast<std::shared_ptr<List<falcon_core::physics::device_structures::Connection>>*>(handle))->size();
}

bool ListConnection_empty(ListConnectionHandle handle) {
    return (*static_cast<std::shared_ptr<List<falcon_core::physics::device_structures::Connection>>*>(handle))->empty();
}

void ListConnection_erase_at(ListConnectionHandle handle, size_t idx) {
    (*static_cast<std::shared_ptr<List<falcon_core::physics::device_structures::Connection>>*>(handle))->erase_at(idx);
}

void ListConnection_clear(ListConnectionHandle handle) {
    (*static_cast<std::shared_ptr<List<falcon_core::physics::device_structures::Connection>>*>(handle))->clear();
}

ConnectionHandle ListConnection_const_at(ListConnectionHandle handle, size_t idx) {
    auto& obj = (*static_cast<std::shared_ptr<List<falcon_core::physics::device_structures::Connection>>*>(handle))->at(idx);
    return new falcon_core::physics::device_structures::ConnectionSP(obj);
}

ConnectionHandle ListConnection_at(ListConnectionHandle handle, size_t idx) {
    auto& obj = (*static_cast<std::shared_ptr<List<falcon_core::physics::device_structures::Connection>>*>(handle))->at(idx);
    return new falcon_core::physics::device_structures::ConnectionSP(obj);
}

size_t ListConnection_items(ListConnectionHandle handle, ConnectionHandle* out_buffer, size_t buffer_size) {
    auto& list = *static_cast<std::shared_ptr<List<falcon_core::physics::device_structures::Connection>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    for (size_t i = 0; i < n; ++i) {
        out_buffer[i] = new falcon_core::physics::device_structures::ConnectionSP(list->items()[i]);
    }
    return n;
}

bool ListConnection_contains(ListConnectionHandle handle, ConnectionHandle value) {
    auto stored_obj = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(value);
    return (*static_cast<std::shared_ptr<List<falcon_core::physics::device_structures::Connection>>*>(handle))->contains(stored_obj);
}

size_t ListConnection_index(ListConnectionHandle handle, ConnectionHandle value) {
    auto stored_obj = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(value);
    return (*static_cast<std::shared_ptr<List<falcon_core::physics::device_structures::Connection>>*>(handle))->index(stored_obj);
}

ListConnectionHandle ListConnection_intersection(ListConnectionHandle handle, ListConnectionHandle other) {
    auto& listA = *static_cast<std::shared_ptr<List<falcon_core::physics::device_structures::Connection>>*>(handle);
    auto& listB = *static_cast<std::shared_ptr<List<falcon_core::physics::device_structures::Connection>>*>(other);
    auto result = listA->intersection(listB);
    return new std::shared_ptr<List<falcon_core::physics::device_structures::Connection>>(result);
}

bool ListConnection_equal(ListConnectionHandle a, ListConnectionHandle b) {
    auto& listA = *static_cast<std::shared_ptr<List<falcon_core::physics::device_structures::Connection>>*>(a);
    auto& listB = *static_cast<std::shared_ptr<List<falcon_core::physics::device_structures::Connection>>*>(b);
    return *listA == *listB;
}

bool ListConnection_not_equal(ListConnectionHandle a, ListConnectionHandle b) {
    return !ListConnection_equal(a, b);
}
