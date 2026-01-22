

# Class falcon\_core::math::arrays::MeasuredArray1D



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**math**](namespacefalcon__core_1_1math.md) **>** [**arrays**](namespacefalcon__core_1_1math_1_1arrays.md) **>** [**MeasuredArray1D**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray1D.md)



_Array type for measured data, derived from BaseArray._ 

* `#include <MeasuredArray1D.hpp>`



Inherits the following classes: [falcon\_core::math::arrays::MeasuredArray](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md),  [falcon\_core::math::arrays::Is1D](classfalcon__core_1_1math_1_1arrays_1_1Is1D.md)














## Public Types

| Type | Name |
| ---: | :--- |
| typedef double | [**value\_type**](#typedef-value_type)  <br> |




## Public Types inherited from falcon_core::generic::FArray

See [falcon\_core::generic::FArray](classfalcon__core_1_1generic_1_1FArray.md)

| Type | Name |
| ---: | :--- |
| typedef xt::xarray&lt; T &gt; | [**array\_type**](classfalcon__core_1_1generic_1_1FArray.md#typedef-array_type)  <br> |
| typedef const T & | [**const\_reference**](classfalcon__core_1_1generic_1_1FArray.md#typedef-const_reference)  <br> |
| typedef T & | [**reference**](classfalcon__core_1_1generic_1_1FArray.md#typedef-reference)  <br> |
| typedef T | [**value\_type**](classfalcon__core_1_1generic_1_1FArray.md#typedef-value_type)  <br> |




## Public Types inherited from falcon_core::generic::IFArray

See [falcon\_core::generic::IFArray](classfalcon__core_1_1generic_1_1IFArray.md)

| Type | Name |
| ---: | :--- |
| typedef xt::xarray&lt; T &gt; | [**array\_type**](classfalcon__core_1_1generic_1_1IFArray.md#typedef-array_type)  <br> |
| typedef const T & | [**const\_reference**](classfalcon__core_1_1generic_1_1IFArray.md#typedef-const_reference)  <br> |
| typedef T & | [**reference**](classfalcon__core_1_1generic_1_1IFArray.md#typedef-reference)  <br> |
| typedef T | [**value\_type**](classfalcon__core_1_1generic_1_1IFArray.md#typedef-value_type)  <br> |




## Public Types inherited from falcon_core::generic::IFArray

See [falcon\_core::generic::IFArray](classfalcon__core_1_1generic_1_1IFArray.md)

| Type | Name |
| ---: | :--- |
| typedef xt::xarray&lt; T &gt; | [**array\_type**](classfalcon__core_1_1generic_1_1IFArray.md#typedef-array_type)  <br> |
| typedef const T & | [**const\_reference**](classfalcon__core_1_1generic_1_1IFArray.md#typedef-const_reference)  <br> |
| typedef T & | [**reference**](classfalcon__core_1_1generic_1_1IFArray.md#typedef-reference)  <br> |
| typedef T | [**value\_type**](classfalcon__core_1_1generic_1_1IFArray.md#typedef-value_type)  <br> |
































































































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**MeasuredArray1D**](#function-measuredarray1d-15) () <br> |
|   | [**MeasuredArray1D**](#function-measuredarray1d-25) (const generic::FArraySP&lt; double &gt; & arr) <br> |
|   | [**MeasuredArray1D**](#function-measuredarray1d-35) (const MeasuredArraySP & arr) <br> |
|   | [**MeasuredArray1D**](#function-measuredarray1d-45) (const xt::xarray&lt; double &gt; & arr) <br> |
|   | [**MeasuredArray1D**](#function-measuredarray1d-55) (xt::xarray&lt; double &gt; && arr) noexcept<br> |
|  std::shared\_ptr&lt; MeasuredArray1D &gt; | [**abs**](#function-abs) () const<br> |
|  std::shared\_ptr&lt; MeasuredArray1D &gt; | [**flip**](#function-flip) (size\_t axis) const<br>_Flip the data along the given axis._  |
|  generic::FArraySP&lt; double &gt; | [**gradient**](#function-gradient-12) (size\_t axis) const<br>_Return the gradient of the data along a given axis._  |
|  generic::ListSP&lt; [**generic::FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; double &gt; &gt; | [**gradient**](#function-gradient-22) () const<br>_Return the gradient of the data along all axes._  |
| virtual double | [**max**](#function-max-13) () const<br>_Return the maximum value of the array._  |
|  std::shared\_ptr&lt; MeasuredArray1D &gt; | [**max**](#function-max-23) (const std::shared\_ptr&lt; MeasuredArray1D &gt; & other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray1D &gt; | [**max**](#function-max-33) (const std::shared\_ptr&lt; FArray&lt; double &gt; &gt; & other) const<br> |
| virtual double | [**min**](#function-min-13) () const<br>_Return the minimum value of the array._  |
|  std::shared\_ptr&lt; MeasuredArray1D &gt; | [**min**](#function-min-23) (const std::shared\_ptr&lt; MeasuredArray1D &gt; & other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray1D &gt; | [**min**](#function-min-33) (const std::shared\_ptr&lt; FArray&lt; double &gt; &gt; & other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray1D &gt; | [**operator\***](#function-operator) (const double other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray1D &gt; | [**operator\***](#function-operator_1) (const int other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray1D &gt; | [**operator\***](#function-operator_2) (const std::shared\_ptr&lt; MeasuredArray1D &gt; & other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray1D &gt; | [**operator\***](#function-operator_3) (const std::shared\_ptr&lt; FArray&lt; double &gt; &gt; & other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray1D &gt; | [**operator+**](#function-operator_4) (const double other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray1D &gt; | [**operator+**](#function-operator_5) (const int other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray1D &gt; | [**operator+**](#function-operator_6) (const std::shared\_ptr&lt; MeasuredArray1D &gt; & other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray1D &gt; | [**operator+**](#function-operator_7) (const std::shared\_ptr&lt; FArray &gt; & other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray1D &gt; | [**operator-**](#function-operator-) (const double other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray1D &gt; | [**operator-**](#function-operator-_1) (const int other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray1D &gt; | [**operator-**](#function-operator-_2) (const std::shared\_ptr&lt; MeasuredArray1D &gt; & other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray1D &gt; | [**operator-**](#function-operator-_3) (const std::shared\_ptr&lt; FArray&lt; double &gt; &gt; & other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray1D &gt; | [**operator-**](#function-operator-_4) () const<br> |
|  std::shared\_ptr&lt; MeasuredArray1D &gt; | [**operator/**](#function-operator_8) (const double other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray1D &gt; | [**operator/**](#function-operator_9) (const int other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray1D &gt; | [**operator/**](#function-operator_10) (const std::shared\_ptr&lt; MeasuredArray1D &gt; & other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray1D &gt; | [**operator/**](#function-operator_11) (const std::shared\_ptr&lt; FArray&lt; double &gt; &gt; & other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray1D &gt; | [**operator^**](#function-operator_12) (const double other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray1D &gt; | [**reshape**](#function-reshape) (const std::vector&lt; size\_t &gt; & shape) const<br>_Return a new Array with the given shape._  |


## Public Functions inherited from falcon_core::math::arrays::MeasuredArray

See [falcon\_core::math::arrays::MeasuredArray](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md)

| Type | Name |
| ---: | :--- |
|   | [**MeasuredArray**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-measuredarray-25) (const MeasuredArray & other) <br> |
|   | [**MeasuredArray**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-measuredarray-35) (const generic::FArraySP&lt; double &gt; & arr) <br> |
|   | [**MeasuredArray**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-measuredarray-45) (const xt::xarray&lt; double &gt; & arr) <br> |
|   | [**MeasuredArray**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-measuredarray-55) (xt::xarray&lt; double &gt; && arr) noexcept<br> |
|  std::shared\_ptr&lt; MeasuredArray &gt; | [**abs**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-abs) () const<br> |
|  std::shared\_ptr&lt; MeasuredArray &gt; | [**flip**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-flip) (size\_t axis) const<br>_Flip the data along the given axis._  |
|  generic::FArraySP&lt; double &gt; | [**gradient**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-gradient-12) (size\_t axis) const<br>_Return the gradient of the data along a given axis._  |
|  generic::ListSP&lt; [**generic::FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; double &gt; &gt; | [**gradient**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-gradient-22) () const<br>_Return the gradient of the data along all axes._  |
| virtual double | [**max**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-max-13) () override const<br>_Return the maximum value of the array._  |
|  std::shared\_ptr&lt; MeasuredArray &gt; | [**max**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-max-23) (const std::shared\_ptr&lt; MeasuredArray &gt; & other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray &gt; | [**max**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-max-33) (const std::shared\_ptr&lt; FArray&lt; double &gt; &gt; & other) const<br> |
| virtual double | [**min**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-min-13) () override const<br>_Return the minimum value of the array._  |
|  std::shared\_ptr&lt; MeasuredArray &gt; | [**min**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-min-23) (const std::shared\_ptr&lt; MeasuredArray &gt; & other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray &gt; | [**min**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-min-33) (const std::shared\_ptr&lt; FArray&lt; double &gt; &gt; & other) const<br> |
|  bool | [**operator!=**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-operator) (const MeasuredArray & other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray &gt; | [**operator\***](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-operator_1) (const double other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray &gt; | [**operator\***](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-operator_2) (const int other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray &gt; | [**operator\***](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-operator_3) (const std::shared\_ptr&lt; MeasuredArray &gt; & other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray &gt; | [**operator\***](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-operator_4) (const std::shared\_ptr&lt; FArray&lt; double &gt; &gt; & other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray &gt; | [**operator+**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-operator_5) (const double other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray &gt; | [**operator+**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-operator_6) (const int other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray &gt; | [**operator+**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-operator_7) (const std::shared\_ptr&lt; MeasuredArray &gt; & other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray &gt; | [**operator+**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-operator_8) (const std::shared\_ptr&lt; FArray &gt; & other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray &gt; | [**operator-**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-operator-) (const double other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray &gt; | [**operator-**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-operator-_1) (const int other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray &gt; | [**operator-**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-operator-_2) (const std::shared\_ptr&lt; MeasuredArray &gt; & other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray &gt; | [**operator-**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-operator-_3) (const std::shared\_ptr&lt; FArray&lt; double &gt; &gt; & other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray &gt; | [**operator-**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-operator-_4) () const<br> |
|  std::shared\_ptr&lt; MeasuredArray &gt; | [**operator/**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-operator_9) (const double other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray &gt; | [**operator/**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-operator_10) (const int other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray &gt; | [**operator/**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-operator_11) (const std::shared\_ptr&lt; MeasuredArray &gt; & other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray &gt; | [**operator/**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-operator_12) (const std::shared\_ptr&lt; FArray&lt; double &gt; &gt; & other) const<br> |
|  MeasuredArray & | [**operator=**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-operator_13) (const MeasuredArray & other) <br> |
|  bool | [**operator==**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-operator_14) (const MeasuredArray & other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray &gt; | [**operator^**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-operator_15) (const double other) const<br> |
|  std::shared\_ptr&lt; MeasuredArray &gt; | [**reshape**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-reshape) (const std::vector&lt; size\_t &gt; & shape) const<br>_Return a new Array with the given shape._  |


## Public Functions inherited from falcon_core::generic::FArray

See [falcon\_core::generic::FArray](classfalcon__core_1_1generic_1_1FArray.md)

| Type | Name |
| ---: | :--- |
|   | [**FArray**](classfalcon__core_1_1generic_1_1FArray.md#function-farray-15) (const FArray&lt; T &gt; & other) <br> |
|   | [**FArray**](classfalcon__core_1_1generic_1_1FArray.md#function-farray-25) () = default<br> |
|   | [**FArray**](classfalcon__core_1_1generic_1_1FArray.md#function-farray-35) (const array\_type & arr) <br> |
|   | [**FArray**](classfalcon__core_1_1generic_1_1FArray.md#function-farray-45) (array\_type && arr) noexcept<br> |
|   | [**FArray**](classfalcon__core_1_1generic_1_1FArray.md#function-farray-55) (const std::vector&lt; size\_t &gt; & shape) <br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**abs**](classfalcon__core_1_1generic_1_1FArray.md#function-abs) () const<br> |
| virtual array\_type::iterator | [**begin**](classfalcon__core_1_1generic_1_1FArray.md#function-begin) () noexcept override<br> |
| virtual array\_type::const\_iterator | [**cbegin**](classfalcon__core_1_1generic_1_1FArray.md#function-cbegin) () noexcept override const<br> |
| virtual array\_type::const\_iterator | [**cend**](classfalcon__core_1_1generic_1_1FArray.md#function-cend) () noexcept override const<br> |
| virtual array\_type & | [**data**](classfalcon__core_1_1generic_1_1FArray.md#function-data-12) () noexcept override<br> |
| virtual const array\_type & | [**data**](classfalcon__core_1_1generic_1_1FArray.md#function-data-22) () noexcept override const<br> |
| virtual size\_t | [**dimension**](classfalcon__core_1_1generic_1_1FArray.md#function-dimension) () noexcept override const<br> |
| virtual array\_type::iterator | [**end**](classfalcon__core_1_1generic_1_1FArray.md#function-end) () noexcept override<br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**flip**](classfalcon__core_1_1generic_1_1FArray.md#function-flip) (size\_t axis) const<br>_Flip the data along the given axis._  |
|  double | [**get\_sum\_of\_squares**](classfalcon__core_1_1generic_1_1FArray.md#function-get_sum_of_squares-14) () const<br> |
|  double | [**get\_sum\_of\_squares**](classfalcon__core_1_1generic_1_1FArray.md#function-get_sum_of_squares-24) (const int other) const<br> |
|  double | [**get\_sum\_of\_squares**](classfalcon__core_1_1generic_1_1FArray.md#function-get_sum_of_squares-34) (const double other) const<br> |
|  double | [**get\_sum\_of\_squares**](classfalcon__core_1_1generic_1_1FArray.md#function-get_sum_of_squares-44) (const std::shared\_ptr&lt; [**generic::FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; & other) const<br> |
|  ListSP&lt; FArray&lt; T &gt; &gt; | [**gradient**](classfalcon__core_1_1generic_1_1FArray.md#function-gradient-12) () const<br>_Return the gradient of the data along all axes._  |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**gradient**](classfalcon__core_1_1generic_1_1FArray.md#function-gradient-22) (size\_t axis) const<br>_Return the gradient of the data along a given axis._  |
| virtual T | [**max**](classfalcon__core_1_1generic_1_1FArray.md#function-max-12) () override const<br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**max**](classfalcon__core_1_1generic_1_1FArray.md#function-max-22) (const std::shared\_ptr&lt; FArray&lt; T &gt; &gt; other) const<br> |
| virtual T | [**min**](classfalcon__core_1_1generic_1_1FArray.md#function-min-12) () override const<br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**min**](classfalcon__core_1_1generic_1_1FArray.md#function-min-22) (const std::shared\_ptr&lt; FArray&lt; T &gt; &gt; other) const<br> |
| virtual  | [**operator array\_type &**](classfalcon__core_1_1generic_1_1FArray.md#function-operator-array_type-&) () override<br> |
| virtual  | [**operator const array\_type &**](classfalcon__core_1_1generic_1_1FArray.md#function-operator-const-array_type-&) () override const<br> |
|  bool | [**operator!=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator) (const FArray&lt; T &gt; & other) const<br> |
|  decltype(auto) | [**operator()**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_1) (Args &&... args) <br> |
|  decltype(auto) | [**operator()**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_2) (Args &&... args) const<br> |
| virtual reference | [**operator()**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_3) (size\_t i) override<br> |
| virtual const\_reference | [**operator()**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_4) (size\_t i) override const<br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator\***](classfalcon__core_1_1generic_1_1FArray.md#function-operator_5) (const double other) const<br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator\***](classfalcon__core_1_1generic_1_1FArray.md#function-operator_6) (const int other) const<br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator\***](classfalcon__core_1_1generic_1_1FArray.md#function-operator_7) (const std::shared\_ptr&lt; FArray&lt; T &gt; &gt; & other) const<br> |
|  FArray&lt; T &gt; & | [**operator\*=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_8) (const double other) <br> |
|  FArray&lt; T &gt; & | [**operator\*=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_9) (const int other) <br> |
|  FArray&lt; T &gt; & | [**operator\*=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_10) (const FArray&lt; T &gt; & other) <br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator+**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_11) (const double other) const<br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator+**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_12) (const int other) const<br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator+**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_13) (const std::shared\_ptr&lt; FArray&lt; T &gt; &gt; & other) const<br> |
|  FArray&lt; T &gt; & | [**operator+=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_14) (const FArray&lt; T &gt; & other) <br> |
|  FArray&lt; T &gt; & | [**operator+=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_15) (const double other) <br> |
|  FArray&lt; T &gt; & | [**operator+=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_16) (const int other) <br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator-**](classfalcon__core_1_1generic_1_1FArray.md#function-operator-) () const<br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator-**](classfalcon__core_1_1generic_1_1FArray.md#function-operator-_1) () <br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator-**](classfalcon__core_1_1generic_1_1FArray.md#function-operator-_2) (const std::shared\_ptr&lt; FArray&lt; T &gt; &gt; & other) const<br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator-**](classfalcon__core_1_1generic_1_1FArray.md#function-operator-_3) (const double other) const<br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator-**](classfalcon__core_1_1generic_1_1FArray.md#function-operator-_4) (const int other) const<br> |
|  FArray&lt; T &gt; & | [**operator-=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator-_5) (const FArray&lt; T &gt; & other) <br> |
|  FArray&lt; T &gt; & | [**operator-=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator-_6) (const double other) <br> |
|  FArray&lt; T &gt; & | [**operator-=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator-_7) (const int other) <br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator/**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_17) (const double other) const<br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator/**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_18) (const int other) const<br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator/**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_19) (const std::shared\_ptr&lt; FArray&lt; T &gt; &gt; & other) const<br> |
|  FArray&lt; T &gt; & | [**operator/=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_20) (const double other) <br> |
|  FArray&lt; T &gt; & | [**operator/=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_21) (const int other) <br> |
|  FArray&lt; T &gt; & | [**operator/=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_22) (const FArray&lt; T &gt; & other) <br> |
| virtual bool | [**operator&lt;**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_23) (const T & value) override const<br>_Check if any of the data is less than the value._  |
|  FArray&lt; T &gt; & | [**operator=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_24) (const FArray&lt; T &gt; & other) <br> |
|  FArray&lt; T &gt; & | [**operator=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_25) (const array\_type & arr) <br> |
|  bool | [**operator==**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_26) (const FArray&lt; T &gt; & other) const<br> |
| virtual bool | [**operator&gt;**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_27) (const T & value) override const<br>_Check if any of the data is greater than the value._  |
|  std::shared\_ptr&lt; FArray&lt; double &gt; &gt; | [**operator^**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_28) (const double other) const<br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator^**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_29) (const int other) const<br> |
|  void | [**pow\_inplace**](classfalcon__core_1_1generic_1_1FArray.md#function-pow_inplace) (const T other) <br> |
| virtual T \* | [**raw\_data**](classfalcon__core_1_1generic_1_1FArray.md#function-raw_data-12) () noexcept override<br> |
| virtual const T \* | [**raw\_data**](classfalcon__core_1_1generic_1_1FArray.md#function-raw_data-22) () noexcept override const<br> |
| virtual void | [**remove\_offset**](classfalcon__core_1_1generic_1_1FArray.md#function-remove_offset) (const T & offset) override<br>_Remove the offset from the data._  |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**reshape**](classfalcon__core_1_1generic_1_1FArray.md#function-reshape) (const std::vector&lt; size\_t &gt; & shape) const<br>_Return a new Array with the given shape._  |
| virtual const xt::dynamic\_shape&lt; size\_t &gt; & | [**shape**](classfalcon__core_1_1generic_1_1FArray.md#function-shape) () noexcept override const<br> |
| virtual size\_t | [**size**](classfalcon__core_1_1generic_1_1FArray.md#function-size) () noexcept override const<br> |
| virtual T | [**sum**](classfalcon__core_1_1generic_1_1FArray.md#function-sum) () override const<br>_Return the sum of the data._  |
|  decltype(auto) | [**view**](classfalcon__core_1_1generic_1_1FArray.md#function-view-12) (Args &&... args) <br> |
|  decltype(auto) | [**view**](classfalcon__core_1_1generic_1_1FArray.md#function-view-22) (Args &&... args) const<br> |
| virtual ListSP&lt; [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; size\_t &gt; &gt; | [**where**](classfalcon__core_1_1generic_1_1FArray.md#function-where) (const T & value) override const<br>_Return the indices of the data where the value is._  |


## Public Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  void | [**serialize**](classfalcon__core_1_1generic_1_1Song.md#function-serialize) (Archive &) <br>_cereal serialization interface. Override in derived classes._  |
|  std::string | [**to\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-to_json_string) () const<br>_Serialize this object to a JSON string._  |
| virtual  | [**~Song**](classfalcon__core_1_1generic_1_1Song.md#function-song) () = default<br> |


## Public Functions inherited from falcon_core::generic::IFArray

See [falcon\_core::generic::IFArray](classfalcon__core_1_1generic_1_1IFArray.md)

| Type | Name |
| ---: | :--- |
| virtual array\_type::iterator | [**begin**](classfalcon__core_1_1generic_1_1IFArray.md#function-begin) () noexcept = 0<br> |
| virtual array\_type::const\_iterator | [**cbegin**](classfalcon__core_1_1generic_1_1IFArray.md#function-cbegin) () noexcept const = 0<br> |
| virtual array\_type::const\_iterator | [**cend**](classfalcon__core_1_1generic_1_1IFArray.md#function-cend) () noexcept const = 0<br> |
| virtual array\_type & | [**data**](classfalcon__core_1_1generic_1_1IFArray.md#function-data-12) () noexcept = 0<br> |
| virtual const array\_type & | [**data**](classfalcon__core_1_1generic_1_1IFArray.md#function-data-22) () noexcept const = 0<br> |
| virtual size\_t | [**dimension**](classfalcon__core_1_1generic_1_1IFArray.md#function-dimension) () noexcept const = 0<br> |
| virtual array\_type::iterator | [**end**](classfalcon__core_1_1generic_1_1IFArray.md#function-end) () noexcept = 0<br> |
| virtual T | [**max**](classfalcon__core_1_1generic_1_1IFArray.md#function-max) () const = 0<br> |
| virtual T | [**min**](classfalcon__core_1_1generic_1_1IFArray.md#function-min) () const = 0<br> |
| virtual  | [**operator array\_type &**](classfalcon__core_1_1generic_1_1IFArray.md#function-operator-array_type-&) () = 0<br> |
| virtual  | [**operator const array\_type &**](classfalcon__core_1_1generic_1_1IFArray.md#function-operator-const-array_type-&) () const = 0<br> |
| virtual reference | [**operator()**](classfalcon__core_1_1generic_1_1IFArray.md#function-operator) (size\_t i) = 0<br> |
| virtual const\_reference | [**operator()**](classfalcon__core_1_1generic_1_1IFArray.md#function-operator_1) (size\_t i) const = 0<br> |
| virtual bool | [**operator&lt;**](classfalcon__core_1_1generic_1_1IFArray.md#function-operator_2) (const T & value) const = 0<br> |
| virtual bool | [**operator&gt;**](classfalcon__core_1_1generic_1_1IFArray.md#function-operator_3) (const T & value) const = 0<br> |
| virtual T \* | [**raw\_data**](classfalcon__core_1_1generic_1_1IFArray.md#function-raw_data-12) () noexcept = 0<br> |
| virtual const T \* | [**raw\_data**](classfalcon__core_1_1generic_1_1IFArray.md#function-raw_data-22) () noexcept const = 0<br> |
| virtual void | [**remove\_offset**](classfalcon__core_1_1generic_1_1IFArray.md#function-remove_offset) (const T & offset) = 0<br> |
| virtual const xt::dynamic\_shape&lt; size\_t &gt; & | [**shape**](classfalcon__core_1_1generic_1_1IFArray.md#function-shape) () noexcept const = 0<br> |
| virtual size\_t | [**size**](classfalcon__core_1_1generic_1_1IFArray.md#function-size) () noexcept const = 0<br> |
| virtual T | [**sum**](classfalcon__core_1_1generic_1_1IFArray.md#function-sum) () const = 0<br> |
| virtual ListSP&lt; [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; size\_t &gt; &gt; | [**where**](classfalcon__core_1_1generic_1_1IFArray.md#function-where) (const T & value) const = 0<br> |
| virtual  | [**~IFArray**](classfalcon__core_1_1generic_1_1IFArray.md#function-ifarray) () = default<br> |


## Public Functions inherited from falcon_core::math::arrays::Is1D

See [falcon\_core::math::arrays::Is1D](classfalcon__core_1_1math_1_1arrays_1_1Is1D.md)

| Type | Name |
| ---: | :--- |
|  generic::FArraySP&lt; T &gt; | [**as\_1D**](classfalcon__core_1_1math_1_1arrays_1_1Is1D.md#function-as_1d) () const<br>_Return the data as a 1D array._  |
|  generic::ListSP&lt; [**generic::FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**even\_divisions**](classfalcon__core_1_1math_1_1arrays_1_1Is1D.md#function-even_divisions) (size\_t divisions) const<br>_Splits the array into even divisions if possible._  |
|  size\_t | [**get\_closest\_index**](classfalcon__core_1_1math_1_1arrays_1_1Is1D.md#function-get_closest_index) (double value) const<br>_Get the index of the closest element to the given value._  |
|  T | [**get\_distance**](classfalcon__core_1_1math_1_1arrays_1_1Is1D.md#function-get_distance) () const<br>_Get the distance between the first and last element of the 1D array._  |
|  T | [**get\_end**](classfalcon__core_1_1math_1_1arrays_1_1Is1D.md#function-get_end) () const<br>_Get the last element of the 1D array._  |
|  double | [**get\_mean**](classfalcon__core_1_1math_1_1arrays_1_1Is1D.md#function-get_mean) () const<br>_Get the mean of the 1D array._  |
|  T | [**get\_start**](classfalcon__core_1_1math_1_1arrays_1_1Is1D.md#function-get_start) () const<br>_Get the first element of the 1D array._  |
|  double | [**get\_std**](classfalcon__core_1_1math_1_1arrays_1_1Is1D.md#function-get_std) () const<br>_Get the standard deviation of the 1D array._  |
|  bool | [**is\_1D**](classfalcon__core_1_1math_1_1arrays_1_1Is1D.md#function-is_1d) () const<br>_Check if the array is 1D._  |
|  bool | [**is\_decreasing**](classfalcon__core_1_1math_1_1arrays_1_1Is1D.md#function-is_decreasing) () const<br>_Check if the array is decreasing._  |
|  bool | [**is\_increasing**](classfalcon__core_1_1math_1_1arrays_1_1Is1D.md#function-is_increasing) () const<br>_Check if the array is increasing._  |
|  void | [**reverse**](classfalcon__core_1_1math_1_1arrays_1_1Is1D.md#function-reverse) () <br>_Reverse the 1D array._  |


## Public Functions inherited from falcon_core::generic::IFArray

See [falcon\_core::generic::IFArray](classfalcon__core_1_1generic_1_1IFArray.md)

| Type | Name |
| ---: | :--- |
| virtual array\_type::iterator | [**begin**](classfalcon__core_1_1generic_1_1IFArray.md#function-begin) () noexcept = 0<br> |
| virtual array\_type::const\_iterator | [**cbegin**](classfalcon__core_1_1generic_1_1IFArray.md#function-cbegin) () noexcept const = 0<br> |
| virtual array\_type::const\_iterator | [**cend**](classfalcon__core_1_1generic_1_1IFArray.md#function-cend) () noexcept const = 0<br> |
| virtual array\_type & | [**data**](classfalcon__core_1_1generic_1_1IFArray.md#function-data-12) () noexcept = 0<br> |
| virtual const array\_type & | [**data**](classfalcon__core_1_1generic_1_1IFArray.md#function-data-22) () noexcept const = 0<br> |
| virtual size\_t | [**dimension**](classfalcon__core_1_1generic_1_1IFArray.md#function-dimension) () noexcept const = 0<br> |
| virtual array\_type::iterator | [**end**](classfalcon__core_1_1generic_1_1IFArray.md#function-end) () noexcept = 0<br> |
| virtual T | [**max**](classfalcon__core_1_1generic_1_1IFArray.md#function-max) () const = 0<br> |
| virtual T | [**min**](classfalcon__core_1_1generic_1_1IFArray.md#function-min) () const = 0<br> |
| virtual  | [**operator array\_type &**](classfalcon__core_1_1generic_1_1IFArray.md#function-operator-array_type-&) () = 0<br> |
| virtual  | [**operator const array\_type &**](classfalcon__core_1_1generic_1_1IFArray.md#function-operator-const-array_type-&) () const = 0<br> |
| virtual reference | [**operator()**](classfalcon__core_1_1generic_1_1IFArray.md#function-operator) (size\_t i) = 0<br> |
| virtual const\_reference | [**operator()**](classfalcon__core_1_1generic_1_1IFArray.md#function-operator_1) (size\_t i) const = 0<br> |
| virtual bool | [**operator&lt;**](classfalcon__core_1_1generic_1_1IFArray.md#function-operator_2) (const T & value) const = 0<br> |
| virtual bool | [**operator&gt;**](classfalcon__core_1_1generic_1_1IFArray.md#function-operator_3) (const T & value) const = 0<br> |
| virtual T \* | [**raw\_data**](classfalcon__core_1_1generic_1_1IFArray.md#function-raw_data-12) () noexcept = 0<br> |
| virtual const T \* | [**raw\_data**](classfalcon__core_1_1generic_1_1IFArray.md#function-raw_data-22) () noexcept const = 0<br> |
| virtual void | [**remove\_offset**](classfalcon__core_1_1generic_1_1IFArray.md#function-remove_offset) (const T & offset) = 0<br> |
| virtual const xt::dynamic\_shape&lt; size\_t &gt; & | [**shape**](classfalcon__core_1_1generic_1_1IFArray.md#function-shape) () noexcept const = 0<br> |
| virtual size\_t | [**size**](classfalcon__core_1_1generic_1_1IFArray.md#function-size) () noexcept const = 0<br> |
| virtual T | [**sum**](classfalcon__core_1_1generic_1_1IFArray.md#function-sum) () const = 0<br> |
| virtual ListSP&lt; [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; size\_t &gt; &gt; | [**where**](classfalcon__core_1_1generic_1_1IFArray.md#function-where) (const T & value) const = 0<br> |
| virtual  | [**~IFArray**](classfalcon__core_1_1generic_1_1IFArray.md#function-ifarray) () = default<br> |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; MeasuredArray1D &gt; | [**empty**](#function-empty) (const std::vector&lt; size\_t &gt; & shape) <br> |
|  std::shared\_ptr&lt; MeasuredArray1D &gt; | [**zeros**](#function-zeros) (const std::vector&lt; size\_t &gt; & shape) <br> |




## Public Static Functions inherited from falcon_core::generic::FArray

See [falcon\_core::generic::FArray](classfalcon__core_1_1generic_1_1FArray.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**empty**](classfalcon__core_1_1generic_1_1FArray.md#function-empty) (const std::vector&lt; size\_t &gt; & shape) <br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**zeros**](classfalcon__core_1_1generic_1_1FArray.md#function-zeros) (const std::vector&lt; size\_t &gt; & shape) <br> |


## Public Static Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; T &gt; | [**from\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-from_json_string) (const std::string & json) <br>_Deserialize an object from a JSON string._  |




















































































































































## Protected Functions

| Type | Name |
| ---: | :--- |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |


## Protected Functions inherited from falcon_core::math::arrays::MeasuredArray

See [falcon\_core::math::arrays::MeasuredArray](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md)

| Type | Name |
| ---: | :--- |
|   | [**MeasuredArray**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-measuredarray-15) () <br> |
|  void | [**serialize**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-serialize) (Archive & ar) <br> |


## Protected Functions inherited from falcon_core::generic::FArray

See [falcon\_core::generic::FArray](classfalcon__core_1_1generic_1_1FArray.md)

| Type | Name |
| ---: | :--- |
|  void | [**serialize**](classfalcon__core_1_1generic_1_1FArray.md#function-serialize) (Archive & ar) <br> |
























## Public Types Documentation




### typedef value\_type 

```C++
using falcon_core::math::arrays::MeasuredArray1D::value_type =  double;
```




<hr>
## Public Functions Documentation




### function MeasuredArray1D [1/5]

```C++
falcon_core::math::arrays::MeasuredArray1D::MeasuredArray1D () 
```




<hr>



### function MeasuredArray1D [2/5]

```C++
falcon_core::math::arrays::MeasuredArray1D::MeasuredArray1D (
    const generic::FArraySP< double > & arr
) 
```




<hr>



### function MeasuredArray1D [3/5]

```C++
falcon_core::math::arrays::MeasuredArray1D::MeasuredArray1D (
    const MeasuredArraySP & arr
) 
```




<hr>



### function MeasuredArray1D [4/5]

```C++
falcon_core::math::arrays::MeasuredArray1D::MeasuredArray1D (
    const xt::xarray< double > & arr
) 
```




<hr>



### function MeasuredArray1D [5/5]

```C++
falcon_core::math::arrays::MeasuredArray1D::MeasuredArray1D (
    xt::xarray< double > && arr
) noexcept
```




<hr>



### function abs 

```C++
std::shared_ptr< MeasuredArray1D > falcon_core::math::arrays::MeasuredArray1D::abs () const
```




<hr>



### function flip 

_Flip the data along the given axis._ 
```C++
std::shared_ptr< MeasuredArray1D > falcon_core::math::arrays::MeasuredArray1D::flip (
    size_t axis
) const
```





**Parameters:**


* `axis` The axis to flip. 



**Returns:**

A flipped [**MeasuredArray1D**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray1D.md). 





        

<hr>



### function gradient [1/2]

_Return the gradient of the data along a given axis._ 
```C++
generic::FArraySP< double > falcon_core::math::arrays::MeasuredArray1D::gradient (
    size_t axis
) const
```



Computes the gradient along the specified axis using finite differences:
* For interior points, uses central difference: (f(x+1) - f(x-1)) / 2
* For boundary points, uses forward (first element) or backward (last element) difference.






**Parameters:**


* `axis` The axis to compute the gradient. 



**Returns:**

The gradient FArray. 





        

<hr>



### function gradient [2/2]

_Return the gradient of the data along all axes._ 
```C++
generic::ListSP< generic::FArray < double > > falcon_core::math::arrays::MeasuredArray1D::gradient () const
```



Computes the gradient for each axis of the array using finite differences:
* For interior points, uses central difference: (f(x+1) - f(x-1)) / 2
* For boundary points, uses forward (first element) or backward (last element) difference.






**Returns:**

A vector of FArray gradients (one for each axis). 





        

<hr>



### function max [1/3]

_Return the maximum value of the array._ 
```C++
virtual double falcon_core::math::arrays::MeasuredArray1D::max () const
```



Implements [*falcon\_core::math::arrays::MeasuredArray::max*](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-max-13)


<hr>



### function max [2/3]

```C++
std::shared_ptr< MeasuredArray1D > falcon_core::math::arrays::MeasuredArray1D::max (
    const std::shared_ptr< MeasuredArray1D > & other
) const
```




<hr>



### function max [3/3]

```C++
std::shared_ptr< MeasuredArray1D > falcon_core::math::arrays::MeasuredArray1D::max (
    const std::shared_ptr< FArray< double > > & other
) const
```




<hr>



### function min [1/3]

_Return the minimum value of the array._ 
```C++
virtual double falcon_core::math::arrays::MeasuredArray1D::min () const
```



Implements [*falcon\_core::math::arrays::MeasuredArray::min*](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md#function-min-13)


<hr>



### function min [2/3]

```C++
std::shared_ptr< MeasuredArray1D > falcon_core::math::arrays::MeasuredArray1D::min (
    const std::shared_ptr< MeasuredArray1D > & other
) const
```




<hr>



### function min [3/3]

```C++
std::shared_ptr< MeasuredArray1D > falcon_core::math::arrays::MeasuredArray1D::min (
    const std::shared_ptr< FArray< double > > & other
) const
```




<hr>



### function operator\* 

```C++
std::shared_ptr< MeasuredArray1D > falcon_core::math::arrays::MeasuredArray1D::operator* (
    const double other
) const
```




<hr>



### function operator\* 

```C++
std::shared_ptr< MeasuredArray1D > falcon_core::math::arrays::MeasuredArray1D::operator* (
    const int other
) const
```




<hr>



### function operator\* 

```C++
std::shared_ptr< MeasuredArray1D > falcon_core::math::arrays::MeasuredArray1D::operator* (
    const std::shared_ptr< MeasuredArray1D > & other
) const
```




<hr>



### function operator\* 

```C++
std::shared_ptr< MeasuredArray1D > falcon_core::math::arrays::MeasuredArray1D::operator* (
    const std::shared_ptr< FArray< double > > & other
) const
```




<hr>



### function operator+ 

```C++
std::shared_ptr< MeasuredArray1D > falcon_core::math::arrays::MeasuredArray1D::operator+ (
    const double other
) const
```




<hr>



### function operator+ 

```C++
std::shared_ptr< MeasuredArray1D > falcon_core::math::arrays::MeasuredArray1D::operator+ (
    const int other
) const
```




<hr>



### function operator+ 

```C++
std::shared_ptr< MeasuredArray1D > falcon_core::math::arrays::MeasuredArray1D::operator+ (
    const std::shared_ptr< MeasuredArray1D > & other
) const
```




<hr>



### function operator+ 

```C++
std::shared_ptr< MeasuredArray1D > falcon_core::math::arrays::MeasuredArray1D::operator+ (
    const std::shared_ptr< FArray > & other
) const
```




<hr>



### function operator- 

```C++
std::shared_ptr< MeasuredArray1D > falcon_core::math::arrays::MeasuredArray1D::operator- (
    const double other
) const
```




<hr>



### function operator- 

```C++
std::shared_ptr< MeasuredArray1D > falcon_core::math::arrays::MeasuredArray1D::operator- (
    const int other
) const
```




<hr>



### function operator- 

```C++
std::shared_ptr< MeasuredArray1D > falcon_core::math::arrays::MeasuredArray1D::operator- (
    const std::shared_ptr< MeasuredArray1D > & other
) const
```




<hr>



### function operator- 

```C++
std::shared_ptr< MeasuredArray1D > falcon_core::math::arrays::MeasuredArray1D::operator- (
    const std::shared_ptr< FArray< double > > & other
) const
```




<hr>



### function operator- 

```C++
std::shared_ptr< MeasuredArray1D > falcon_core::math::arrays::MeasuredArray1D::operator- () const
```




<hr>



### function operator/ 

```C++
std::shared_ptr< MeasuredArray1D > falcon_core::math::arrays::MeasuredArray1D::operator/ (
    const double other
) const
```




<hr>



### function operator/ 

```C++
std::shared_ptr< MeasuredArray1D > falcon_core::math::arrays::MeasuredArray1D::operator/ (
    const int other
) const
```




<hr>



### function operator/ 

```C++
std::shared_ptr< MeasuredArray1D > falcon_core::math::arrays::MeasuredArray1D::operator/ (
    const std::shared_ptr< MeasuredArray1D > & other
) const
```




<hr>



### function operator/ 

```C++
std::shared_ptr< MeasuredArray1D > falcon_core::math::arrays::MeasuredArray1D::operator/ (
    const std::shared_ptr< FArray< double > > & other
) const
```




<hr>



### function operator^ 

```C++
std::shared_ptr< MeasuredArray1D > falcon_core::math::arrays::MeasuredArray1D::operator^ (
    const double other
) const
```




<hr>



### function reshape 

_Return a new Array with the given shape._ 
```C++
std::shared_ptr< MeasuredArray1D > falcon_core::math::arrays::MeasuredArray1D::reshape (
    const std::vector< size_t > & shape
) const
```





**Parameters:**


* `shape` The new shape. 



**Returns:**

A reshaped [**MeasuredArray1D**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray1D.md). 





        

<hr>
## Public Static Functions Documentation




### function empty 

```C++
static inline std::shared_ptr< MeasuredArray1D > falcon_core::math::arrays::MeasuredArray1D::empty (
    const std::vector< size_t > & shape
) 
```




<hr>



### function zeros 

```C++
static inline std::shared_ptr< MeasuredArray1D > falcon_core::math::arrays::MeasuredArray1D::zeros (
    const std::vector< size_t > & shape
) 
```




<hr>
## Protected Functions Documentation




### function serialize 

```C++
template<class Archive>
inline void falcon_core::math::arrays::MeasuredArray1D::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::math::arrays::MeasuredArray1D::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/math/arrays/MeasuredArray1D.hpp`

