#include <falcon_core/generic/FArray.hpp>
#include "falcon_core/generic/FArrayDouble_c_api.h"
#include <falcon_core/generic/FArray.hpp>
#include <xtensor/xadapt.hpp>

FArrayDoubleHandle FArrayDouble_create_empty() {
    return new falcon_core::generic::FArray<double>(falcon_core::generic::FArray<double>());
}

FArrayDoubleHandle FArrayDouble_create_zeros(const size_t* shape, size_t ndim) {
    std::vector<size_t> vec;
    for (size_t i =0; i < ndim; ++i) {
        vec.push_back(shape[i]);
    }
    return new falcon_core::generic::FArray<double>(*falcon_core::generic::FArray<double>::zeros(vec));
}

FArrayDoubleHandle FArrayDouble_from_shape(const size_t* shape, size_t ndim) {
    std::vector<size_t> vec;
    for (size_t i =0; i < ndim; ++i) {
        vec.push_back(shape[i]);
    }
    return new falcon_core::generic::FArray<double>(falcon_core::generic::FArray<double>(vec));
}

FArrayDoubleHandle FArrayDouble_from_data(const double* data, const size_t* shape, size_t ndim) {
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
    delete static_cast<falcon_core::generic::FArray<double>*>(handle);
}
size_t FArrayDouble_size(FArrayDoubleHandle handle) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return farray->size();
}
size_t FArrayDouble_dimension(FArrayDoubleHandle handle) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return farray->dimension();
}
size_t FArrayDouble_shape(FArrayDoubleHandle handle, size_t* out_buffer, size_t ndim) {
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
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    if (farray->size() > numdata) {
        throw std::runtime_error("Trying to store more datapoints than buffer allocated.");
    }
    out_buffer = farray->xtensor().data();
    return farray->size();
}
void FArrayDouble_plusequals_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    *farray += *oarray;
}
void FArrayDouble_plusequals_double(FArrayDoubleHandle handle, const double other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    *farray += other;
}
void FArrayDouble_plusequals_int(FArrayDoubleHandle handle, const int other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    *farray += other;
}
FArrayDoubleHandle FArrayDouble_plus_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    return new falcon_core::generic::FArray<double>(
        *(*farray +
            std::make_shared<falcon_core::generic::FArray<double>>(*oarray)));
}
FArrayDoubleHandle FArrayDouble_plus_double(FArrayDoubleHandle handle, const double other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(*farray + other));
}
FArrayDoubleHandle FArrayDouble_plus_int(FArrayDoubleHandle handle, const int other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(*farray + other));
}
void FArrayDouble_minusequals_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    *farray -= *oarray;
}
void FArrayDouble_minusequals_double(FArrayDoubleHandle handle, const double other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    *farray -= other;
}
void FArrayDouble_minusequals_int(FArrayDoubleHandle handle, const int other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    *farray -= other;
}
FArrayDoubleHandle FArrayDouble_minus_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    return new falcon_core::generic::FArray<double>(
        *(*farray -
            std::make_shared<falcon_core::generic::FArray<double>>(*oarray)));
}
FArrayDoubleHandle FArrayDouble_minus_double(FArrayDoubleHandle handle, const double other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(*farray - other));
}
FArrayDoubleHandle FArrayDouble_minus_int(FArrayDoubleHandle handle, const int other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(*farray - other));
}
FArrayDoubleHandle FArrayDouble_negation(FArrayDoubleHandle handle) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(-*farray));
}
void FArrayDouble_timesequals_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    *farray *= *oarray;
}
void FArrayDouble_timesequals_double(FArrayDoubleHandle handle, const double other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    *farray *= other;
}
void FArrayDouble_timesequals_int(FArrayDoubleHandle handle, const int other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    *farray *= other;
}
FArrayDoubleHandle FArrayDouble_times_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    return new falcon_core::generic::FArray<double>(
        *(*farray *
            std::make_shared<falcon_core::generic::FArray<double>>(*oarray)));
}
FArrayDoubleHandle FArrayDouble_times_double(FArrayDoubleHandle handle, const double other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(*farray * other));
}
FArrayDoubleHandle FArrayDouble_times_int(FArrayDoubleHandle handle, const int other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(*farray * other));
}
void FArrayDouble_dividesequals_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    *farray /= *oarray;
}
void FArrayDouble_dividesequals_double(FArrayDoubleHandle handle, const double other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    *farray /= other;
}
void FArrayDouble_dividesequals_int(FArrayDoubleHandle handle, const int other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    *farray /= other;
}
FArrayDoubleHandle FArrayDouble_divides_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    return new falcon_core::generic::FArray<double>(
        *(*farray /
            std::make_shared<falcon_core::generic::FArray<double>>(*oarray)));
}
FArrayDoubleHandle FArrayDouble_divides_double(FArrayDoubleHandle handle, const double other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(*farray / other));
}
FArrayDoubleHandle FArrayDouble_divides_int(FArrayDoubleHandle handle, const int other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(*farray / other));
}
FArrayDoubleHandle FArrayDouble_pow(FArrayDoubleHandle handle, const double other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*farray ^ other);
}
FArrayDoubleHandle FArrayDouble_abs(FArrayDoubleHandle handle) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*farray->abs());
}
FArrayDoubleHandle FArrayDouble_min(FArrayDoubleHandle handle) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(farray->min());
}
FArrayDoubleHandle FArrayDouble_min_arraywise(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    return new falcon_core::generic::FArray<double>(
        *farray->min(std::shared_ptr<falcon_core::generic::FArray<double>>(oarray)));
}
bool FArrayDouble_equality(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    return *farray == *oarray;
}
bool FArrayDouble_notequality(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    return *farray != *oarray;
}
bool FArrayDouble_greaterthan(FArrayDoubleHandle handle, const double value) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return *farray > value;
}
bool FArrayDouble_lessthan(FArrayDoubleHandle handle, const double value) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return *farray < value;
}
void FArrayDouble_remove_offset(FArrayDoubleHandle handle, const double offset) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    farray->remove_offset(offset);
}
double FArrayDouble_sum(FArrayDoubleHandle handle) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return farray->sum();
}
FArrayDoubleHandle FArrayDouble_reshape(FArrayDoubleHandle handle, const size_t* shape, size_t ndims) {
    std::vector<size_t> vec;
    for (size_t i =0; i < ndims; ++i) {
        vec.push_back(shape[i]);
    }
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*farray->reshape(vec));
}
ListListSizeTHandle FArrayDouble_where(FArrayDoubleHandle handle, const double value) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::List<falcon_core::generic::List<size_t>>(*farray->where(value));
}
FArrayDoubleHandle FArrayDouble_flip(FArrayDoubleHandle handle, size_t axis) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*farray->flip(axis));
}
size_t FArrayDouble_full_gradient(FArrayDoubleHandle handle, FArrayDoubleHandle* out_buffer, size_t buffer_size) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto many_gradients = farray->gradient();
    if (many_gradients->size() > buffer_size) {
        throw std::runtime_error("Trying to store more gradients than buffer allocated.");
    }
    for (size_t i = 0; i < many_gradients->size(); ++i) {
        out_buffer[i] = many_gradients->items()[i].get();
    }
    return many_gradients->size();
}
FArrayDoubleHandle FArrayDouble_gradient(FArrayDoubleHandle handle, size_t axis) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*farray->gradient(axis));
}
double FArrayDouble_get_sum_of_squares(FArrayDoubleHandle handle) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return farray->get_sum_of_squares();
}
double FArrayDouble_get_summed_diff_int_of_squares(FArrayDoubleHandle handle, const int other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return farray->get_sum_of_squares(other);
}

double FArrayDouble_get_summed_diff_double_of_squares(FArrayDoubleHandle handle, const double other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return farray->get_sum_of_squares(other);
}
double FArrayDouble_get_summed_diff_array_of_squares(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray = static_cast<falcon_core::generic::FArray<double>*>(other);
    return farray->get_sum_of_squares(std::make_shared<falcon_core::generic::FArray<double>>(*oarray));
}
StringHandle      FArrayDouble_to_json_string(FArrayDoubleHandle handle) {
  std::string json = static_cast<falcon_core::generic::FArray<double>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}
FArrayDoubleHandle FArrayDouble_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::FArray<double>::from_json_string<falcon_core::generic::FArray<double>>(json->raw);
  return new falcon_core::generic::FArray<double>(*ptr);
}
