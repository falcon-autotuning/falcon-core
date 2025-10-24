#include <falcon_core/generic/FArray.hpp>
#include "falcon_core/generic/FArrayInt_c_api.h"
#include <falcon_core/generic/FArray.hpp>
#include <xtensor/xadapt.hpp>

FArrayIntHandle FArrayInt_create_empty() {
    return new falcon_core::generic::FArray<int>(falcon_core::generic::FArray<int>());
}

FArrayIntHandle FArrayInt_from_shape(const size_t* shape, size_t ndim) {
    std::vector<size_t> vec;
    for (size_t i =0; i < ndim; ++i) {
        vec.push_back(shape[i]);
    }
    return new falcon_core::generic::FArray<int>(falcon_core::generic::FArray<int>(vec));
}

FArrayIntHandle FArrayInt_from_data(const int* data, const size_t* shape, size_t ndim) {
  std::vector<std::vector<int>::size_type> shapeVec;
  size_t                                      total_size = 1;
  for (size_t i = 0; i < ndim; ++i) {
    shapeVec.push_back(shape[i]);
    total_size *= shape[i];
  }
  xt::xarray<int> arr =
      xt::adapt(data, total_size, xt::no_ownership(), shapeVec);
  return new falcon_core::generic::FArray<int>(
      falcon_core::generic::FArray<int>(arr));
}
void FArrayInt_destroy(FArrayIntHandle handle) {
    delete static_cast<falcon_core::generic::FArray<int>*>(handle);
}
size_t FArrayInt_size(FArrayIntHandle handle) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return farray->size();
}
size_t FArrayInt_dimension(FArrayIntHandle handle) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return farray->dimension();
}
size_t FArrayInt_shape(FArrayIntHandle handle, size_t* out_buffer, size_t ndim) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    auto shape = farray->shape();
    size_t count   = shape.size();
    size_t to_copy = (ndim < count) ? ndim : count;
    for (size_t i = 0; i < to_copy; ++i) {
        out_buffer[i] = shape[i];
    }
    return to_copy;
}
size_t FArrayInt_data(FArrayIntHandle handle, int* out_buffer, size_t numdata) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    if (farray->size() > numdata) {
        throw std::runtime_error("Trying to store more datapoints than buffer allocated.");
    }
    out_buffer = farray->xtensor().data();
    return farray->size();
}
void FArrayInt_plusequals_farray(FArrayIntHandle handle, FArrayIntHandle other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<int>*>(other);
    *farray += *oarray;
}
void FArrayInt_plusequals_double(FArrayIntHandle handle, const double other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    *farray += other;
}
void FArrayInt_plusequals_int(FArrayIntHandle handle, const int other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    *farray += other;
}
FArrayIntHandle FArrayInt_plus_farray(FArrayIntHandle handle, FArrayIntHandle other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<int>*>(other);
    return new falcon_core::generic::FArray<int>(
        *(*farray +
            std::make_shared<falcon_core::generic::FArray<int>>(*oarray)));
}
FArrayIntHandle FArrayInt_plus_double(FArrayIntHandle handle, const double other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(*(*farray + other));
}
FArrayIntHandle FArrayInt_plus_int(FArrayIntHandle handle, const int other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(*(*farray + other));
}
void FArrayInt_minusequals_farray(FArrayIntHandle handle, FArrayIntHandle other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<int>*>(other);
    *farray -= *oarray;
}
void FArrayInt_minusequals_double(FArrayIntHandle handle, const double other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    *farray -= other;
}
void FArrayInt_minusequals_int(FArrayIntHandle handle, const int other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    *farray -= other;
}
FArrayIntHandle FArrayInt_minus_farray(FArrayIntHandle handle, FArrayIntHandle other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<int>*>(other);
    return new falcon_core::generic::FArray<int>(
        *(*farray -
            std::make_shared<falcon_core::generic::FArray<int>>(*oarray)));
}
FArrayIntHandle FArrayInt_minus_double(FArrayIntHandle handle, const double other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(*(*farray - other));
}
FArrayIntHandle FArrayInt_minus_int(FArrayIntHandle handle, const int other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(*(*farray - other));
}
FArrayIntHandle FArrayInt_negation(FArrayIntHandle handle) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(*(-*farray));
}
void FArrayInt_timesequals_farray(FArrayIntHandle handle, FArrayIntHandle other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<int>*>(other);
    *farray *= *oarray;
}
void FArrayInt_timesequals_double(FArrayIntHandle handle, const double other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    *farray *= other;
}
void FArrayInt_timesequals_int(FArrayIntHandle handle, const int other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    *farray *= other;
}
FArrayIntHandle FArrayInt_times_farray(FArrayIntHandle handle, FArrayIntHandle other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<int>*>(other);
    return new falcon_core::generic::FArray<int>(
        *(*farray *
            std::make_shared<falcon_core::generic::FArray<int>>(*oarray)));
}
FArrayIntHandle FArrayInt_times_double(FArrayIntHandle handle, const double other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(*(*farray * other));
}
FArrayIntHandle FArrayInt_times_int(FArrayIntHandle handle, const int other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(*(*farray * other));
}
void FArrayInt_dividesequals_farray(FArrayIntHandle handle, FArrayIntHandle other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<int>*>(other);
    *farray /= *oarray;
}
void FArrayInt_dividesequals_double(FArrayIntHandle handle, const double other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    *farray /= other;
}
void FArrayInt_dividesequals_int(FArrayIntHandle handle, const int other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    *farray /= other;
}
FArrayIntHandle FArrayInt_divides_farray(FArrayIntHandle handle, FArrayIntHandle other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<int>*>(other);
    return new falcon_core::generic::FArray<int>(
        *(*farray /
            std::make_shared<falcon_core::generic::FArray<int>>(*oarray)));
}
FArrayIntHandle FArrayInt_divides_double(FArrayIntHandle handle, const double other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(*(*farray / other));
}
FArrayIntHandle FArrayInt_divides_int(FArrayIntHandle handle, const int other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(*(*farray / other));
}
FArrayIntHandle FArrayInt_pow(FArrayIntHandle handle, const double other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(*farray ^ other);
}
FArrayIntHandle FArrayInt_abs(FArrayIntHandle handle) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(*farray->abs());
}
FArrayIntHandle FArrayInt_min(FArrayIntHandle handle) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(farray->min());
}
FArrayIntHandle FArrayInt_min_arraywise(FArrayIntHandle handle, FArrayIntHandle other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<int>*>(other);
    return new falcon_core::generic::FArray<int>(
        *farray->min(std::shared_ptr<falcon_core::generic::FArray<int>>(oarray)));
}
bool FArrayInt_equality(FArrayIntHandle handle, FArrayIntHandle other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<int>*>(other);
    return *farray == *oarray;
}
bool FArrayInt_notequality(FArrayIntHandle handle, FArrayIntHandle other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<int>*>(other);
    return *farray != *oarray;
}
bool FArrayInt_greaterthan(FArrayIntHandle handle, const int value) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return *farray > value;
}
bool FArrayInt_lessthan(FArrayIntHandle handle, const int value) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return *farray < value;
}
void FArrayInt_remove_offset(FArrayIntHandle handle, const int offset) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    farray->remove_offset(offset);
}
int FArrayInt_sum(FArrayIntHandle handle) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return farray->sum();
}
FArrayIntHandle FArrayInt_reshape(FArrayIntHandle handle, const size_t* shape, size_t ndims) {
    std::vector<size_t> vec;
    for (size_t i =0; i < ndims; ++i) {
        vec.push_back(shape[i]);
    }
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(*farray->reshape(vec));
}
ListListSizeTHandle FArrayInt_where(FArrayIntHandle handle, const int value) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::List<falcon_core::generic::List<size_t>>(*farray->where(value));
}
FArrayIntHandle FArrayInt_flip(FArrayIntHandle handle, size_t axis) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(*farray->flip(axis));
}
size_t FArrayInt_full_gradient(FArrayIntHandle handle, FArrayIntHandle* out_buffer, size_t buffer_size) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    auto many_gradients = farray->gradient();
    if (many_gradients->size() > buffer_size) {
        throw std::runtime_error("Trying to store more gradients than buffer allocated.");
    }
    for (size_t i = 0; i < many_gradients->size(); ++i) {
        out_buffer[i] = many_gradients->items()[i].get();
    }
    return many_gradients->size();
}
FArrayIntHandle FArrayInt_gradient(FArrayIntHandle handle, size_t axis) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(*farray->gradient(axis));
}
double FArrayInt_get_sum_of_squares(FArrayIntHandle handle) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return farray->get_sum_of_squares();
}
double FArrayInt_get_summed_diff_int_of_squares(FArrayIntHandle handle, const int other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return farray->get_sum_of_squares(other);
}

double FArrayInt_get_summed_diff_double_of_squares(FArrayIntHandle handle, const double other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return farray->get_sum_of_squares(other);
}
double FArrayInt_get_summed_diff_array_of_squares(FArrayIntHandle handle, FArrayIntHandle other) {
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    auto oarray = static_cast<falcon_core::generic::FArray<int>*>(other);
    return farray->get_sum_of_squares(std::make_shared<falcon_core::generic::FArray<int>>(*oarray));
}
const char*      FArrayInt_to_json_string(FArrayIntHandle handle) {
  static thread_local std::string json;
  json = static_cast<falcon_core::generic::FArray<int>*>(handle)->to_json_string();
  return json.c_str();
}
FArrayIntHandle FArrayInt_from_json_string(const char* json) {
  auto ptr = falcon_core::generic::FArray<int>::from_json_string<falcon_core::generic::FArray<int>>(std::string(json));
  return new falcon_core::generic::FArray<int>(*ptr);
}
