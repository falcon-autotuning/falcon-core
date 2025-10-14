#!/usr/bin/env python3
type_combinations = [
    # (C_type, CPP_real_type, name_suffix)
    ("int", "int", "Int"),
    ("float", "float", "Float"),
    ("double", "double", "Double"),
]

header_path = "./include/falcon_core/generic/FArray_c_api.h"
implementation_path = "./src/falcon_core/generic/FArray_c_api.cpp"

#TODO: view and operator() and xtensor are not wrapped
def generate_header():
    with open(header_path, "w") as f:
        f.write("""#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>
// Forward declarations for opaque handles
""")
        for (c_type, cpp_type, name) in type_combinations:
            f.write(f"typedef void* FArray{name}Handle;\n")
        f.write("\n// Function declarations\n")
        for (c_type, cpp_type, name) in type_combinations:
            f.write(f"""
FArray{name}Handle FArray{name}_create_empty();
FArray{name}Handle FArray{name}_from_shape(const size_t* shape, size_t ndim);
FArray{name}Handle FArray{name}_from_data(const {c_type}* data, const size_t* shape, size_t ndim);
void FArray{name}_destroy(FArray{name}Handle handle);
size_t FArray{name}_size(FArray{name}Handle handle);
size_t FArray{name}_dimension(FArray{name}Handle handle);
const size_t* FArray{name}_shape(FArray{name}Handle handle);
{c_type}* FArray{name}_data(FArray{name}Handle handle);
FArray{name}Handle FArray{name}_plusequals_farray(FArray{name}Handle handle, FArray{name}Handle other);
FArray{name}Handle FArray{name}_plusequals_double(FArray{name}Handle handle, const double other);
FArray{name}Handle FArray{name}_plusequals_int(FArray{name}Handle handle, const int other);
FArray{name}Handle FArray{name}_plus_farray(FArray{name}Handle handle, FArray{name}Handle other);
FArray{name}Handle FArray{name}_plus_double(FArray{name}Handle handle, const double other);
FArray{name}Handle FArray{name}_plus_int(FArray{name}Handle handle, const int other);
FArray{name}Handle FArray{name}_minusequals_farray(FArray{name}Handle handle, FArray{name}Handle other);
FArray{name}Handle FArray{name}_minusequals_double(FArray{name}Handle handle, const double other);
FArray{name}Handle FArray{name}_minusequals_int(FArray{name}Handle handle, const int other);
FArray{name}Handle FArray{name}_minus_farray(FArray{name}Handle handle, FArray{name}Handle other);
FArray{name}Handle FArray{name}_minus_double(FArray{name}Handle handle, const double other);
FArray{name}Handle FArray{name}_minus_int(FArray{name}Handle handle, const int other);
FArray{name}Handle FArray{name}_negation(FArray{name}Handle handle);
FArray{name}Handle FArray{name}_timesequals_farray(FArray{name}Handle handle, FArray{name}Handle other);
FArray{name}Handle FArray{name}_timesequals_double(FArray{name}Handle handle, const double other);
FArray{name}Handle FArray{name}_timesequals_int(FArray{name}Handle handle, const int other);
FArray{name}Handle FArray{name}_times_farray(FArray{name}Handle handle, FArray{name}Handle other);
FArray{name}Handle FArray{name}_times_double(FArray{name}Handle handle, const double other);
FArray{name}Handle FArray{name}_times_int(FArray{name}Handle handle, const int other);
FArray{name}Handle FArray{name}_dividesequals_farray(FArray{name}Handle handle, FArray{name}Handle other);
FArray{name}Handle FArray{name}_dividesequals_double(FArray{name}Handle handle, const double other);
FArray{name}Handle FArray{name}_dividesequals_int(FArray{name}Handle handle, const int other);
FArray{name}Handle FArray{name}_divides_farray(FArray{name}Handle handle, FArray{name}Handle other);
FArray{name}Handle FArray{name}_divides_double(FArray{name}Handle handle, const double other);
FArray{name}Handle FArray{name}_divides_int(FArray{name}Handle handle, const int other);
FArray{name}Handle FArray{name}_pow(FArray{name}Handle handle, const double other);
FArray{name}Handle FArray{name}_abs(FArray{name}Handle handle);
FArray{name}Handle FArray{name}_min(FArray{name}Handle handle);
FArray{name}Handle FArray{name}_min_arraywise(FArray{name}Handle handle, FArray{name}Handle other);
FArray{name}Handle FArray{name}_max(FArray{name}Handle handle);
FArray{name}Handle FArray{name}_max_arraywise(FArray{name}Handle handle, FArray{name}Handle other);
bool FArray{name}_equality(FArray{name}Handle handle, FArray{name}Handle other);
bool FArray{name}_notequality(FArray{name}Handle handle, FArray{name}Handle other);
bool FArray{name}_greaterthan(FArray{name}Handle handle, const {c_type} value);
bool FArray{name}_lessthan(FArray{name}Handle handle, const {c_type} value);
void FArray{name}_remove_offset(FArray{name}Handle handle, const {c_type} offset);
{c_type} FArray{name}_sum(FArray{name}Handle handle);
FArray{name}Handle FArray{name}_reshape(FArray{name}Handle handle, const size_t* shape, size_t ndims);
ListListSizeTHandle FArray{name}_where(FArray{name}Handle handle, const {c_type} value);
FArray{name}Handle FArray{name}_flip(FArray{name}Handle handle, size_t axis);
ListFArray{c_type}Handle FArray{name}_full_gradient(FArray{name}Handle handle);
FArray{name}Handle FArray{name}_gradient(FArray{name}Handle handle, size_t axis);
double FArray{name}_get_sum_of_squares(FArray{name}Handle handle);
double FArray{name}_get_summed_diff_int_of_squares(FArray{name}Handle handle, const int other);
double FArray{name}_get_summed_diff_double_of_squares(FArray{name}Handle handle, const double other);
double FArray{name}_get_summed_diff_array_of_squares(FArray{name}Handle handle, FArray{name}Handle other);

""")
        f.write("""
#ifdef __cplusplus
}
#endif
""")

def generate_implementation():
    with open(implementation_path, "w") as f:
        f.write("""
#include <falcon_core/generic/FArray.hpp>
#include "falcon_core/generic/FArray_c_api.h"
using namespace falcon_core::generic;
// Implementation for all FArray types
""")
        for (c_type, cpp_type, name) in type_combinations:
            f.write(f"""
FArray{name}Handle FArray{name}_create_empty() {{
    return new std::shared_ptr<FArray<{cpp_type}>>(std::make_shared<FArray<{cpp_type}>>());
}}
FArray{name}Handle FArray{name}_from_shape(const size_t* shape, size_t ndim) {{
    std::vector<size_t> shape_vec(shape, shape + ndim);
    return new std::shared_ptr<FArray<{cpp_type}>>(std::make_shared<FArray<{cpp_type}>>(shape_vec));
}}
FArray{name}Handle FArray{name}_from_data(const {c_type}* data, const size_t* shape, size_t ndim) {{
    std::vector<size_t> shape_vec(shape, shape + ndim);
    xt::xarray<{cpp_type}> arr = xt::adapt(data, xt::xshape(shape_vec));
    return new std::shared_ptr<FArray<{cpp_type}>>(std::make_shared<FArray<{cpp_type}>>(arr));
}}
void FArray{name}_destroy(FArray{name}Handle handle) {{
    delete static_cast<std::shared_ptr<FArray<{cpp_type}> >*>(handle);
}}
size_t FArray{name}_size(FArray{name}Handle handle) {{
    return (*static_cast<std::shared_ptr<FArray<{cpp_type}> >*>(handle))->size();
}}
size_t FArray{name}_dimension(FArray{name}Handle handle) {{
    return (*static_cast<std::shared_ptr<FArray<{cpp_type}> >*>(handle))->dimension();
}}
const size_t* FArray{name}_shape(FArray{name}Handle handle) {{
    return (*static_cast<std::shared_ptr<FArray<{cpp_type}> >*>(handle))->shape().data();
}}
{c_type}* FArray{name}_data(FArray{name}Handle handle) {{
    return (*static_cast<std::shared_ptr<FArray<{cpp_type}> >*>(handle))->data();
}}
""")

if __name__ == "__main__":
    generate_header()
    generate_implementation()
    print("Generated FArray_c_api.h and FArray_c_api.cpp")
```
