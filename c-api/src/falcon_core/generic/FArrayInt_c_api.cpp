#include <falcon_core/generic/FArray.hpp>
#include "falcon_core/generic/FArrayInt_c_api.h"
#include <falcon_core/generic/FArray.hpp>
#include <xtensor/xadapt.hpp>

FArrayIntHandle FArrayInt_create_empty() {
    return new falcon_core::generic::FArray<int>(falcon_core::generic::FArray<int>());
}

FArrayIntHandle FArrayInt_create_zeros(const size_t* shape, size_t ndim) {
if (!shape) {
throw std::invalid_argument("Null shape passed to FArrayInt_create_zeros");
}
    std::vector<size_t> vec;
    for (size_t i =0; i < ndim; ++i) {
        vec.push_back(shape[i]);
    }
    return new falcon_core::generic::FArray<int>(*falcon_core::generic::FArray<int>::zeros(vec));
}

FArrayIntHandle FArrayInt_from_shape(const size_t* shape, size_t ndim) {
if (!shape) {
throw std::invalid_argument("Null shape passed to FArrayInt_from_shape");
}
    std::vector<size_t> vec;
    for (size_t i =0; i < ndim; ++i) {
        vec.push_back(shape[i]);
    }
    return new falcon_core::generic::FArray<int>(falcon_core::generic::FArray<int>(vec));
}

FArrayIntHandle FArrayInt_from_data(const int* data, const size_t* shape, size_t ndim) {
if (!data) {
throw std::invalid_argument("Null data passed to FArrayInt_from_data");
}
if (!shape) {
throw std::invalid_argument("Null shape passed to FArrayInt_from_data");
}
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
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_destroy");
}
    delete static_cast<falcon_core::generic::FArray<int>*>(handle);
}

size_t FArrayInt_size(FArrayIntHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_size");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return farray->size();
}

size_t FArrayInt_dimension(FArrayIntHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_dimension");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return farray->dimension();
}
size_t FArrayInt_shape(FArrayIntHandle handle, size_t* out_buffer, size_t ndim) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_shape");
}
if (!out_buffer) {
throw std::invalid_argument("Null out_buffer passed to FArrayInt_shape");
}
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
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_data");
}
if (!out_buffer) {
throw std::invalid_argument("Null out_buffer passed to FArrayInt_shape");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    if (farray->size() > numdata) {
        throw std::runtime_error("Trying to store more datapoints than buffer allocated.");
    }
    out_buffer = farray->xtensor().data();
    return farray->size();
}
 
void FArrayInt_plusequals_farray(FArrayIntHandle handle, FArrayIntHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayInt_plusequals_farray");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<int>*>(other);
    *farray += *oarray;
}

void FArrayInt_plusequals_double(FArrayIntHandle handle, const double other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_plusequals_double");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    *farray += other;
}

void FArrayInt_plusequals_int(FArrayIntHandle handle, const int other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_plusequals_int");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    *farray += other;
}

FArrayIntHandle FArrayInt_plus_farray(FArrayIntHandle handle, FArrayIntHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayInt_plus_farray");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<int>*>(other);
    return new falcon_core::generic::FArray<int>(
        *(*farray +
            std::make_shared<falcon_core::generic::FArray<int>>(*oarray)));
}

FArrayIntHandle FArrayInt_plus_double(FArrayIntHandle handle, const double other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_plus_double");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(*(*farray + other));
}

FArrayIntHandle FArrayInt_plus_int(FArrayIntHandle handle, const int other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_plus_int");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(*(*farray + other));
}

void FArrayInt_minusequals_farray(FArrayIntHandle handle, FArrayIntHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayInt_minusequals_farray");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<int>*>(other);
    *farray -= *oarray;
}

void FArrayInt_minusequals_double(FArrayIntHandle handle, const double other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_minusequals_double");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    *farray -= other;
}

void FArrayInt_minusequals_int(FArrayIntHandle handle, const int other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_minusequals_int");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    *farray -= other;
}

FArrayIntHandle FArrayInt_minus_farray(FArrayIntHandle handle, FArrayIntHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayInt_minus_farray");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<int>*>(other);
    return new falcon_core::generic::FArray<int>(
        *(*farray -
            std::make_shared<falcon_core::generic::FArray<int>>(*oarray)));
}

FArrayIntHandle FArrayInt_minus_double(FArrayIntHandle handle, const double other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_minus_double");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(*(*farray - other));
}

FArrayIntHandle FArrayInt_minus_int(FArrayIntHandle handle, const int other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_minus_int");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(*(*farray - other));
}

FArrayIntHandle FArrayInt_negation(FArrayIntHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_negation");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(*(-*farray));
}

void FArrayInt_timesequals_farray(FArrayIntHandle handle, FArrayIntHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayInt_timesequals_farray");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<int>*>(other);
    *farray *= *oarray;
}

void FArrayInt_timesequals_double(FArrayIntHandle handle, const double other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_timesequals_double");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    *farray *= other;
}

void FArrayInt_timesequals_int(FArrayIntHandle handle, const int other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_timesequals_int");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    *farray *= other;
}

FArrayIntHandle FArrayInt_times_farray(FArrayIntHandle handle, FArrayIntHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayInt_times_farray");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<int>*>(other);
    return new falcon_core::generic::FArray<int>(
        *(*farray *
            std::make_shared<falcon_core::generic::FArray<int>>(*oarray)));
}

FArrayIntHandle FArrayInt_times_double(FArrayIntHandle handle, const double other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_times_double");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(*(*farray * other));
}

FArrayIntHandle FArrayInt_times_int(FArrayIntHandle handle, const int other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_times_int");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(*(*farray * other));
}

void FArrayInt_dividesequals_farray(FArrayIntHandle handle, FArrayIntHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayInt_dividesequals_farray");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<int>*>(other);
    *farray /= *oarray;
}

void FArrayInt_dividesequals_double(FArrayIntHandle handle, const double other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_dividesequals_double");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    *farray /= other;
}

void FArrayInt_dividesequals_int(FArrayIntHandle handle, const int other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_dividesequals_int");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    *farray /= other;
}

FArrayIntHandle FArrayInt_divides_farray(FArrayIntHandle handle, FArrayIntHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayInt_divides_farray");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<int>*>(other);
    return new falcon_core::generic::FArray<int>(
        *(*farray /
            std::make_shared<falcon_core::generic::FArray<int>>(*oarray)));
}

FArrayIntHandle FArrayInt_divides_double(FArrayIntHandle handle, const double other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_divides_double");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(*(*farray / other));
}

FArrayIntHandle FArrayInt_divides_int(FArrayIntHandle handle, const int other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_divides_int");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(*(*farray / other));
}

FArrayIntHandle FArrayInt_pow(FArrayIntHandle handle, const double other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_pow");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(*farray ^ other);
}

FArrayIntHandle FArrayInt_abs(FArrayIntHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_abs");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(*farray->abs());
}

int FArrayInt_min(FArrayIntHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_min");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return farray->min();
}

FArrayIntHandle FArrayInt_min_arraywise(FArrayIntHandle handle, FArrayIntHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayInt_min_arraywise");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<int>*>(other);
    return new falcon_core::generic::FArray<int>(
    *farray->min(std::make_shared<falcon_core::generic::FArray<int>>(*oarray)));
}

int FArrayInt_max(FArrayIntHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_max");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return farray->max();
}

FArrayIntHandle FArrayInt_max_arraywise(FArrayIntHandle handle, FArrayIntHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayInt_max_arraywise");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<int>*>(other);
    return new falcon_core::generic::FArray<int>(
    *farray->max(std::make_shared<falcon_core::generic::FArray<int>>(*oarray)));
}

bool FArrayInt_equality(FArrayIntHandle handle, FArrayIntHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayInt_equality");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<int>*>(other);
    return *farray == *oarray;
}

bool FArrayInt_notequality(FArrayIntHandle handle, FArrayIntHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayInt_notequality");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<int>*>(other);
    return *farray != *oarray;
}

bool FArrayInt_greaterthan(FArrayIntHandle handle, const int value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_greaterthan");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return *farray > value;
}

bool FArrayInt_lessthan(FArrayIntHandle handle, const int value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_lessthan");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return *farray < value;
}

void FArrayInt_remove_offset(FArrayIntHandle handle, const int offset) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_remove_offset");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    farray->remove_offset(offset);
}

int FArrayInt_sum(FArrayIntHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_sum");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return farray->sum();
}

FArrayIntHandle FArrayInt_reshape(FArrayIntHandle handle, const size_t* shape, size_t ndims) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_reshape");
}
    std::vector<size_t> vec;
    for (size_t i =0; i < ndims; ++i) {
        vec.push_back(shape[i]);
    }
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(*farray->reshape(vec));
}

ListListSizeTHandle FArrayInt_where(FArrayIntHandle handle, const int value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_where");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::List<falcon_core::generic::List<size_t>>(*farray->where(value));
}

FArrayIntHandle FArrayInt_flip(FArrayIntHandle handle, size_t axis) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_flip");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(*farray->flip(axis));
}

size_t FArrayInt_full_gradient(FArrayIntHandle handle, FArrayIntHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_full_gradient");
}
if (!out_buffer) {
throw std::invalid_argument("Null out_buffer passed to FArrayInt_full_gradient");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    auto many_gradients = farray->gradient();
    if (many_gradients->size() > buffer_size) {
        throw std::runtime_error("Trying to store more int gradients than buffer allocated.");
    }
    for (size_t i = 0; i < many_gradients->size(); ++i) {
        out_buffer[i] = new falcon_core::generic::FArray<int>(*(many_gradients->items()[i]));
    }
    return many_gradients->size();
}

FArrayIntHandle FArrayInt_gradient(FArrayIntHandle handle, size_t axis) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_gradient");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return new falcon_core::generic::FArray<int>(*farray->gradient(axis));
}

double FArrayInt_get_sum_of_squares(FArrayIntHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_get_sum_of_squares");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return farray->get_sum_of_squares();
}

double FArrayInt_get_summed_diff_int_of_squares(FArrayIntHandle handle, const int other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_get_summed_diff_int_of_squares");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return farray->get_sum_of_squares(other);
}

double FArrayInt_get_summed_diff_double_of_squares(FArrayIntHandle handle, const double other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_get_summed_diff_double_of_squares");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    return farray->get_sum_of_squares(other);
}

double FArrayInt_get_summed_diff_array_of_squares(FArrayIntHandle handle, FArrayIntHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayInt_get_summed_diff_array_of_squares");
}
    auto farray = static_cast<falcon_core::generic::FArray<int>*>(handle);
    auto oarray = static_cast<falcon_core::generic::FArray<int>*>(other);
    return farray->get_sum_of_squares(std::make_shared<falcon_core::generic::FArray<int>>(*oarray));
}

StringHandle      FArrayInt_to_json_string(FArrayIntHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_to_json_string");
}
  std::string json = static_cast<falcon_core::generic::FArray<int>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

FArrayIntHandle FArrayInt_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to FArrayInt_from_json_string");
}
  auto ptr = falcon_core::generic::FArray<int>::from_json_string<falcon_core::generic::FArray<int>>(json->raw);
  return new falcon_core::generic::FArray<int>(*ptr);
}
