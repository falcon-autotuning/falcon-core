#include <falcon_core/generic/FArray.hpp>
#include "falcon_core/generic/FArrayDouble_c_api.h"
#include <falcon_core/generic/FArray.hpp>
#include <xtensor/xadapt.hpp>

FArrayDoubleHandle FArrayDouble_create_empty() {
    return new falcon_core::generic::FArray<double>(falcon_core::generic::FArray<double>());
}

FArrayDoubleHandle FArrayDouble_create_zeros(const size_t* shape, size_t ndim) {
if (!shape) {
throw std::invalid_argument("Null shape passed to FArrayDouble_create_zeros");
}
    std::vector<size_t> vec;
    for (size_t i =0; i < ndim; ++i) {
        vec.push_back(shape[i]);
    }
    return new falcon_core::generic::FArray<double>(*falcon_core::generic::FArray<double>::zeros(vec));
}

FArrayDoubleHandle FArrayDouble_from_shape(const size_t* shape, size_t ndim) {
if (!shape) {
throw std::invalid_argument("Null shape passed to FArrayDouble_from_shape");
}
    std::vector<size_t> vec;
    for (size_t i =0; i < ndim; ++i) {
        vec.push_back(shape[i]);
    }
    return new falcon_core::generic::FArray<double>(falcon_core::generic::FArray<double>(vec));
}

FArrayDoubleHandle FArrayDouble_from_data(const double* data, const size_t* shape, size_t ndim) {
if (!data) {
throw std::invalid_argument("Null data passed to FArrayDouble_from_data");
}
if (!shape) {
throw std::invalid_argument("Null shape passed to FArrayDouble_from_data");
}
  std::vector<std::vector<double>::size_type> shapeVec;
  size_t                                      total_size = 1;
  for (size_t i = 0; i < ndim; ++i) {
    shapeVec.push_back(shape[i]);
    total_size *= shape[i];
  }
  xt::xarray<double> arr =
      xt::adapt(data, total_size, xt::no_ownership(), shapeVec);
  return new falcon_core::generic::FArray<double>(
      falcon_core::generic::FArray<double>(arr));
}

void FArrayDouble_destroy(FArrayDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_destroy");
}
    delete static_cast<falcon_core::generic::FArray<double>*>(handle);
}

size_t FArrayDouble_size(FArrayDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_size");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return farray->size();
}

size_t FArrayDouble_dimension(FArrayDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_dimension");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return farray->dimension();
}
size_t FArrayDouble_shape(FArrayDoubleHandle handle, size_t* out_buffer, size_t ndim) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_shape");
}
if (!out_buffer) {
throw std::invalid_argument("Null out_buffer passed to FArrayDouble_shape");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto shape = farray->shape();
    size_t count   = shape.size();
    size_t to_copy = (ndim < count) ? ndim : count;
    for (size_t i = 0; i < to_copy; ++i) {
        out_buffer[i] = shape[i];
    }
    return to_copy;
}

size_t FArrayDouble_data(FArrayDoubleHandle handle, double* out_buffer, size_t numdata) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_data");
}
if (!out_buffer) {
throw std::invalid_argument("Null out_buffer passed to FArrayDouble_shape");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    if (farray->size() > numdata) {
        throw std::runtime_error("Trying to store more datapoints than buffer allocated.");
    }
    out_buffer = farray->xtensor().data();
    return farray->size();
}
 
void FArrayDouble_plusequals_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_plusequals_farray");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    *farray += *oarray;
}

void FArrayDouble_plusequals_double(FArrayDoubleHandle handle, const double other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_plusequals_double");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    *farray += other;
}

void FArrayDouble_plusequals_int(FArrayDoubleHandle handle, const int other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_plusequals_int");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    *farray += other;
}

FArrayDoubleHandle FArrayDouble_plus_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_plus_farray");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    return new falcon_core::generic::FArray<double>(
        *(*farray +
            std::make_shared<falcon_core::generic::FArray<double>>(*oarray)));
}

FArrayDoubleHandle FArrayDouble_plus_double(FArrayDoubleHandle handle, const double other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_plus_double");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(*farray + other));
}

FArrayDoubleHandle FArrayDouble_plus_int(FArrayDoubleHandle handle, const int other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_plus_int");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(*farray + other));
}

void FArrayDouble_minusequals_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_minusequals_farray");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    *farray -= *oarray;
}

void FArrayDouble_minusequals_double(FArrayDoubleHandle handle, const double other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_minusequals_double");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    *farray -= other;
}

void FArrayDouble_minusequals_int(FArrayDoubleHandle handle, const int other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_minusequals_int");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    *farray -= other;
}

FArrayDoubleHandle FArrayDouble_minus_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_minus_farray");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    return new falcon_core::generic::FArray<double>(
        *(*farray -
            std::make_shared<falcon_core::generic::FArray<double>>(*oarray)));
}

FArrayDoubleHandle FArrayDouble_minus_double(FArrayDoubleHandle handle, const double other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_minus_double");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(*farray - other));
}

FArrayDoubleHandle FArrayDouble_minus_int(FArrayDoubleHandle handle, const int other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_minus_int");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(*farray - other));
}

FArrayDoubleHandle FArrayDouble_negation(FArrayDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_negation");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(-*farray));
}

void FArrayDouble_timesequals_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_timesequals_farray");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    *farray *= *oarray;
}

void FArrayDouble_timesequals_double(FArrayDoubleHandle handle, const double other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_timesequals_double");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    *farray *= other;
}

void FArrayDouble_timesequals_int(FArrayDoubleHandle handle, const int other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_timesequals_int");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    *farray *= other;
}

FArrayDoubleHandle FArrayDouble_times_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_times_farray");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    return new falcon_core::generic::FArray<double>(
        *(*farray *
            std::make_shared<falcon_core::generic::FArray<double>>(*oarray)));
}

FArrayDoubleHandle FArrayDouble_times_double(FArrayDoubleHandle handle, const double other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_times_double");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(*farray * other));
}

FArrayDoubleHandle FArrayDouble_times_int(FArrayDoubleHandle handle, const int other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_times_int");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(*farray * other));
}

void FArrayDouble_dividesequals_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_dividesequals_farray");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    *farray /= *oarray;
}

void FArrayDouble_dividesequals_double(FArrayDoubleHandle handle, const double other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_dividesequals_double");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    *farray /= other;
}

void FArrayDouble_dividesequals_int(FArrayDoubleHandle handle, const int other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_dividesequals_int");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    *farray /= other;
}

FArrayDoubleHandle FArrayDouble_divides_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_divides_farray");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    return new falcon_core::generic::FArray<double>(
        *(*farray /
            std::make_shared<falcon_core::generic::FArray<double>>(*oarray)));
}

FArrayDoubleHandle FArrayDouble_divides_double(FArrayDoubleHandle handle, const double other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_divides_double");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(*farray / other));
}

FArrayDoubleHandle FArrayDouble_divides_int(FArrayDoubleHandle handle, const int other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_divides_int");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(*farray / other));
}

FArrayDoubleHandle FArrayDouble_pow(FArrayDoubleHandle handle, const double other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_pow");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*farray ^ other);
}

FArrayDoubleHandle FArrayDouble_abs(FArrayDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_abs");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*farray->abs());
}

double FArrayDouble_min(FArrayDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_min");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return farray->min();
}

FArrayDoubleHandle FArrayDouble_min_arraywise(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_min_arraywise");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    return new falcon_core::generic::FArray<double>(
    *farray->min(std::make_shared<falcon_core::generic::FArray<double>>(*oarray)));
}

double FArrayDouble_max(FArrayDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_max");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return farray->max();
}

FArrayDoubleHandle FArrayDouble_max_arraywise(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_max_arraywise");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    return new falcon_core::generic::FArray<double>(
    *farray->max(std::make_shared<falcon_core::generic::FArray<double>>(*oarray)));
}

bool FArrayDouble_equality(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_equality");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    return *farray == *oarray;
}

bool FArrayDouble_notequality(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_notequality");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    return *farray != *oarray;
}

bool FArrayDouble_greaterthan(FArrayDoubleHandle handle, const double value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_greaterthan");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return *farray > value;
}

bool FArrayDouble_lessthan(FArrayDoubleHandle handle, const double value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_lessthan");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return *farray < value;
}

void FArrayDouble_remove_offset(FArrayDoubleHandle handle, const double offset) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_remove_offset");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    farray->remove_offset(offset);
}

double FArrayDouble_sum(FArrayDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_sum");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return farray->sum();
}

FArrayDoubleHandle FArrayDouble_reshape(FArrayDoubleHandle handle, const size_t* shape, size_t ndims) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_reshape");
}
    std::vector<size_t> vec;
    for (size_t i =0; i < ndims; ++i) {
        vec.push_back(shape[i]);
    }
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*farray->reshape(vec));
}

ListListSizeTHandle FArrayDouble_where(FArrayDoubleHandle handle, const double value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_where");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::List<falcon_core::generic::List<size_t>>(*farray->where(value));
}

FArrayDoubleHandle FArrayDouble_flip(FArrayDoubleHandle handle, size_t axis) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_flip");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*farray->flip(axis));
}

size_t FArrayDouble_full_gradient(FArrayDoubleHandle handle, FArrayDoubleHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_full_gradient");
}
if (!out_buffer) {
throw std::invalid_argument("Null out_buffer passed to FArrayDouble_full_gradient");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto many_gradients = farray->gradient();
    if (many_gradients->size() > buffer_size) {
        throw std::runtime_error("Trying to store more double gradients than buffer allocated.");
    }
    for (size_t i = 0; i < many_gradients->size(); ++i) {
        out_buffer[i] = new falcon_core::generic::FArray<double>(*(many_gradients->items()[i]));
    }
    return many_gradients->size();
}

FArrayDoubleHandle FArrayDouble_gradient(FArrayDoubleHandle handle, size_t axis) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_gradient");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*farray->gradient(axis));
}

double FArrayDouble_get_sum_of_squares(FArrayDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_get_sum_of_squares");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return farray->get_sum_of_squares();
}

double FArrayDouble_get_summed_diff_int_of_squares(FArrayDoubleHandle handle, const int other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_get_summed_diff_int_of_squares");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return farray->get_sum_of_squares(other);
}

double FArrayDouble_get_summed_diff_double_of_squares(FArrayDoubleHandle handle, const double other) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_get_summed_diff_double_of_squares");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return farray->get_sum_of_squares(other);
}

double FArrayDouble_get_summed_diff_array_of_squares(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_get_summed_diff_array_of_squares");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray = static_cast<falcon_core::generic::FArray<double>*>(other);
    return farray->get_sum_of_squares(std::make_shared<falcon_core::generic::FArray<double>>(*oarray));
}

StringHandle      FArrayDouble_to_json_string(FArrayDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_to_json_string");
}
  std::string json = static_cast<falcon_core::generic::FArray<double>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

FArrayDoubleHandle FArrayDouble_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to FArrayDouble_from_json_string");
}
  auto ptr = falcon_core::generic::FArray<double>::from_json_string<falcon_core::generic::FArray<double>>(json->raw);
  return new falcon_core::generic::FArray<double>(*ptr);
}
