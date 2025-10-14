
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/generic/Pair_c_api.h"

using namespace falcon_core::generic;
using namespace falcon_core::physics::device_structures;

// Implementation for all pair types

PairIntIntHandle PairIntInt_create(int first, int second) {
    return new Pair<int, int>(first, second);
}

void PairIntInt_destroy(PairIntIntHandle handle) {
    delete static_cast<Pair<int, int>*>(handle);
}

int PairIntInt_first(PairIntIntHandle handle) {
    return static_cast<Pair<int, int>*>(handle)->first();
}

int PairIntInt_second(PairIntIntHandle handle) {
    return static_cast<Pair<int, int>*>(handle)->second();
}

bool PairIntInt_equal(PairIntIntHandle a, PairIntIntHandle b) {
    auto pair_a = static_cast<Pair<int, int>*>(a);
    auto pair_b = static_cast<Pair<int, int>*>(b);
    return *pair_a == *pair_b;
}

PairFloatFloatHandle PairFloatFloat_create(float first, float second) {
    return new Pair<float, float>(first, second);
}

void PairFloatFloat_destroy(PairFloatFloatHandle handle) {
    delete static_cast<Pair<float, float>*>(handle);
}

float PairFloatFloat_first(PairFloatFloatHandle handle) {
    return static_cast<Pair<float, float>*>(handle)->first();
}

float PairFloatFloat_second(PairFloatFloatHandle handle) {
    return static_cast<Pair<float, float>*>(handle)->second();
}

bool PairFloatFloat_equal(PairFloatFloatHandle a, PairFloatFloatHandle b) {
    auto pair_a = static_cast<Pair<float, float>*>(a);
    auto pair_b = static_cast<Pair<float, float>*>(b);
    return *pair_a == *pair_b;
}

PairIntFloatHandle PairIntFloat_create(int first, float second) {
    return new Pair<int, float>(first, second);
}

void PairIntFloat_destroy(PairIntFloatHandle handle) {
    delete static_cast<Pair<int, float>*>(handle);
}

int PairIntFloat_first(PairIntFloatHandle handle) {
    return static_cast<Pair<int, float>*>(handle)->first();
}

float PairIntFloat_second(PairIntFloatHandle handle) {
    return static_cast<Pair<int, float>*>(handle)->second();
}

bool PairIntFloat_equal(PairIntFloatHandle a, PairIntFloatHandle b) {
    auto pair_a = static_cast<Pair<int, float>*>(a);
    auto pair_b = static_cast<Pair<int, float>*>(b);
    return *pair_a == *pair_b;
}

PairConnectionConnectionHandle PairConnectionConnection_create(ConnectionHandle first, ConnectionHandle second) {
    auto first_obj = static_cast<falcon_core::physics::device_structures::ConnectionSP*>(first);
    auto second_obj = static_cast<falcon_core::physics::device_structures::ConnectionSP*>(second);
    return new Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>(*first_obj, *second_obj);
}

void PairConnectionConnection_destroy(PairConnectionConnectionHandle handle) {
    delete static_cast<Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>*>(handle);
}

ConnectionHandle PairConnectionConnection_first(PairConnectionConnectionHandle handle) {
    auto pair = static_cast<Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>*>(handle);
    return new falcon_core::physics::device_structures::ConnectionSP(pair->first());
}

ConnectionHandle PairConnectionConnection_second(PairConnectionConnectionHandle handle) {
    auto pair = static_cast<Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>*>(handle);
    return new falcon_core::physics::device_structures::ConnectionSP(pair->second());
}

bool PairConnectionConnection_equal(PairConnectionConnectionHandle a, PairConnectionConnectionHandle b) {
    auto pair_a = static_cast<Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>*>(a);
    auto pair_b = static_cast<Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connection>*>(b);
    return *pair_a == *pair_b;
}

PairConnectionFloatHandle PairConnectionFloat_create(ConnectionHandle first, float second) {
    auto first_obj = static_cast<falcon_core::physics::device_structures::ConnectionSP*>(first);
    return new Pair<falcon_core::physics::device_structures::Connection, float>(*first_obj, second);
}

void PairConnectionFloat_destroy(PairConnectionFloatHandle handle) {
    delete static_cast<Pair<falcon_core::physics::device_structures::Connection, float>*>(handle);
}

ConnectionHandle PairConnectionFloat_first(PairConnectionFloatHandle handle) {
    auto pair = static_cast<Pair<falcon_core::physics::device_structures::Connection, float>*>(handle);
    return new falcon_core::physics::device_structures::ConnectionSP(pair->first());
}

float PairConnectionFloat_second(PairConnectionFloatHandle handle) {
    return static_cast<Pair<falcon_core::physics::device_structures::Connection, float>*>(handle)->second();
}

bool PairConnectionFloat_equal(PairConnectionFloatHandle a, PairConnectionFloatHandle b) {
    auto pair_a = static_cast<Pair<falcon_core::physics::device_structures::Connection, float>*>(a);
    auto pair_b = static_cast<Pair<falcon_core::physics::device_structures::Connection, float>*>(b);
    return *pair_a == *pair_b;
}
