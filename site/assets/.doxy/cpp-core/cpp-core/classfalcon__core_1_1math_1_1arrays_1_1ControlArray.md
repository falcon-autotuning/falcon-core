

# Class falcon\_core::math::arrays::ControlArray



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**math**](namespacefalcon__core_1_1math.md) **>** [**arrays**](namespacefalcon__core_1_1math_1_1arrays.md) **>** [**ControlArray**](classfalcon__core_1_1math_1_1arrays_1_1ControlArray.md)



_Array type for control independant axis data._ 

* `#include <ControlArray.hpp>`



Inherits the following classes: [falcon\_core::generic::FArray](classfalcon__core_1_1generic_1_1FArray.md),  [falcon\_core::math::arrays::IsControl](classfalcon__core_1_1math_1_1arrays_1_1IsControl.md)


Inherited by the following classes: [falcon\_core::math::arrays::ControlArray1D](classfalcon__core_1_1math_1_1arrays_1_1ControlArray1D.md),  [falcon\_core::math::arrays::LabelledControlArray](classfalcon__core_1_1math_1_1arrays_1_1LabelledControlArray.md)














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
|   | [**ControlArray**](#function-controlarray-25) (const ControlArray & other) <br> |
|   | [**ControlArray**](#function-controlarray-35) (const xt::xarray&lt; double &gt; & arr) <br> |
|   | [**ControlArray**](#function-controlarray-45) (const generic::FArraySP&lt; double &gt; & arr) <br> |
|   | [**ControlArray**](#function-controlarray-55) (xt::xarray&lt; double &gt; && arr) noexcept<br> |
|  std::shared\_ptr&lt; ControlArray &gt; | [**abs**](#function-abs) () const<br> |
|  std::shared\_ptr&lt; ControlArray &gt; | [**flip**](#function-flip) (size\_t axis) const<br>_Flip the data along the given axis._  |
| virtual generic::FArraySP&lt; double &gt; | [**gradient**](#function-gradient-12) (size\_t axis) override const<br>_Return the gradient of the data along a given axis._  |
|  generic::ListSP&lt; [**generic::FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; double &gt; &gt; | [**gradient**](#function-gradient-22) () override const<br>_Return the gradient of the data along all axes._  |
| virtual double | [**max**](#function-max-13) () override const<br>_Return the maximum value of the array._  |
|  std::shared\_ptr&lt; ControlArray &gt; | [**max**](#function-max-23) (const std::shared\_ptr&lt; ControlArray &gt; & other) const<br> |
|  std::shared\_ptr&lt; ControlArray &gt; | [**max**](#function-max-33) (const std::shared\_ptr&lt; FArray&lt; double &gt; &gt; & other) const<br> |
| virtual double | [**min**](#function-min-13) () override const<br>_Return the minimum value of the array._  |
|  std::shared\_ptr&lt; ControlArray &gt; | [**min**](#function-min-23) (const std::shared\_ptr&lt; ControlArray &gt; & other) const<br> |
|  std::shared\_ptr&lt; ControlArray &gt; | [**min**](#function-min-33) (const std::shared\_ptr&lt; FArray&lt; double &gt; &gt; & other) const<br> |
|  std::shared\_ptr&lt; ControlArray &gt; | [**operator\***](#function-operator) (const double other) const<br> |
|  std::shared\_ptr&lt; ControlArray &gt; | [**operator\***](#function-operator_1) (const int other) const<br> |
|  std::shared\_ptr&lt; ControlArray &gt; | [**operator+**](#function-operator_2) (const double other) const<br> |
|  std::shared\_ptr&lt; ControlArray &gt; | [**operator+**](#function-operator_3) (const int other) const<br> |
|  std::shared\_ptr&lt; ControlArray &gt; | [**operator+**](#function-operator_4) (const std::shared\_ptr&lt; ControlArray &gt; & other) const<br> |
|  std::shared\_ptr&lt; ControlArray &gt; | [**operator+**](#function-operator_5) (const std::shared\_ptr&lt; FArray &gt; & other) const<br> |
|  std::shared\_ptr&lt; ControlArray &gt; | [**operator-**](#function-operator-) (const double other) const<br> |
|  std::shared\_ptr&lt; ControlArray &gt; | [**operator-**](#function-operator-_1) (const int other) const<br> |
|  std::shared\_ptr&lt; ControlArray &gt; | [**operator-**](#function-operator-_2) (const std::shared\_ptr&lt; ControlArray &gt; & other) const<br> |
|  std::shared\_ptr&lt; ControlArray &gt; | [**operator-**](#function-operator-_3) (const std::shared\_ptr&lt; FArray&lt; double &gt; &gt; & other) const<br> |
|  std::shared\_ptr&lt; ControlArray &gt; | [**operator-**](#function-operator-_4) () const<br> |
|  std::shared\_ptr&lt; ControlArray &gt; | [**operator/**](#function-operator_6) (const double other) const<br> |
|  std::shared\_ptr&lt; ControlArray &gt; | [**operator/**](#function-operator_7) (const int other) const<br> |
|  ControlArray & | [**operator=**](#function-operator_8) (const ControlArray & other) <br> |
|  std::shared\_ptr&lt; ControlArray &gt; | [**operator^**](#function-operator_9) (const double other) const<br> |
|  std::shared\_ptr&lt; ControlArray &gt; | [**reshape**](#function-reshape) (const std::vector&lt; size\_t &gt; & shape) const<br>_Return a new Array with the given shape._  |


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


## Public Functions inherited from falcon_core::math::arrays::IsControl

See [falcon\_core::math::arrays::IsControl](classfalcon__core_1_1math_1_1arrays_1_1IsControl.md)

| Type | Name |
| ---: | :--- |
|  IncreasingAlignmentSP | [**\_determine\_alignments**](classfalcon__core_1_1math_1_1arrays_1_1IsControl.md#function-_determine_alignments) () <br>_Determine the alignment for each dimension of the array. for each dimension checks if the values are increasing, decreasing, or not changing._  |
|  IncreasingAlignmentSP | [**alignment**](classfalcon__core_1_1math_1_1arrays_1_1IsControl.md#function-alignment) () const<br>_Return the increasing alignments for each dimension._  |
| virtual generic::FArraySP&lt; T &gt; | [**gradient**](classfalcon__core_1_1math_1_1arrays_1_1IsControl.md#function-gradient-12) (size\_t axis) const = 0<br> |
| virtual generic::ListSP&lt; [**generic::FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**gradient**](classfalcon__core_1_1math_1_1arrays_1_1IsControl.md#function-gradient-22) () const = 0<br> |
|  int | [**principle\_dimension**](classfalcon__core_1_1math_1_1arrays_1_1IsControl.md#function-principle_dimension) () const<br>_Return the principle dimension of the array._  |
|  void | [**update\_alignments**](classfalcon__core_1_1math_1_1arrays_1_1IsControl.md#function-update_alignments) () <br>_Recalculates the alignments zmerinobased on current data._  |


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








































## Protected Attributes inherited from falcon_core::math::arrays::IsControl

See [falcon\_core::math::arrays::IsControl](classfalcon__core_1_1math_1_1arrays_1_1IsControl.md)

| Type | Name |
| ---: | :--- |
|  IncreasingAlignmentSP | [**\_alignment**](classfalcon__core_1_1math_1_1arrays_1_1IsControl.md#variable-_alignment)  <br> |
|  std::shared\_timed\_mutex | [**\_mu\_alignment**](classfalcon__core_1_1math_1_1arrays_1_1IsControl.md#variable-_mu_alignment)  <br> |
|  std::shared\_timed\_mutex | [**\_mu\_principle\_dimension**](classfalcon__core_1_1math_1_1arrays_1_1IsControl.md#variable-_mu_principle_dimension)  <br> |
|  int | [**\_principle\_dimension**](classfalcon__core_1_1math_1_1arrays_1_1IsControl.md#variable-_principle_dimension)  <br> |
























































































## Protected Functions

| Type | Name |
| ---: | :--- |
|   | [**ControlArray**](#function-controlarray-15) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |


## Protected Functions inherited from falcon_core::generic::FArray

See [falcon\_core::generic::FArray](classfalcon__core_1_1generic_1_1FArray.md)

| Type | Name |
| ---: | :--- |
|  void | [**serialize**](classfalcon__core_1_1generic_1_1FArray.md#function-serialize) (Archive & ar) <br> |






















## Public Functions Documentation




### function ControlArray [2/5]

```C++
falcon_core::math::arrays::ControlArray::ControlArray (
    const ControlArray & other
) 
```




<hr>



### function ControlArray [3/5]

```C++
falcon_core::math::arrays::ControlArray::ControlArray (
    const xt::xarray< double > & arr
) 
```




<hr>



### function ControlArray [4/5]

```C++
falcon_core::math::arrays::ControlArray::ControlArray (
    const generic::FArraySP< double > & arr
) 
```




<hr>



### function ControlArray [5/5]

```C++
falcon_core::math::arrays::ControlArray::ControlArray (
    xt::xarray< double > && arr
) noexcept
```




<hr>



### function abs 

```C++
std::shared_ptr< ControlArray > falcon_core::math::arrays::ControlArray::abs () const
```




<hr>



### function flip 

_Flip the data along the given axis._ 
```C++
std::shared_ptr< ControlArray > falcon_core::math::arrays::ControlArray::flip (
    size_t axis
) const
```





**Parameters:**


* `axis` The axis to flip. 



**Returns:**

A flipped [**ControlArray**](classfalcon__core_1_1math_1_1arrays_1_1ControlArray.md). 





        

<hr>



### function gradient [1/2]

_Return the gradient of the data along a given axis._ 
```C++
virtual generic::FArraySP< double > falcon_core::math::arrays::ControlArray::gradient (
    size_t axis
) override const
```



Computes the gradient along the specified axis using finite differences:
* For interior points, uses central difference: (f(x+1) - f(x-1)) / 2
* For boundary points, uses forward (first element) or backward (last element) difference.






**Parameters:**


* `axis` The axis to compute the gradient. 



**Returns:**

The gradient FArray. 





        
Implements [*falcon\_core::math::arrays::IsControl::gradient*](classfalcon__core_1_1math_1_1arrays_1_1IsControl.md#function-gradient-12)


<hr>



### function gradient [2/2]

_Return the gradient of the data along all axes._ 
```C++
generic::ListSP< generic::FArray < double > > falcon_core::math::arrays::ControlArray::gradient () override const
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
virtual double falcon_core::math::arrays::ControlArray::max () override const
```



Implements [*falcon\_core::generic::IFArray::max*](classfalcon__core_1_1generic_1_1IFArray.md#function-max)


<hr>



### function max [2/3]

```C++
std::shared_ptr< ControlArray > falcon_core::math::arrays::ControlArray::max (
    const std::shared_ptr< ControlArray > & other
) const
```




<hr>



### function max [3/3]

```C++
std::shared_ptr< ControlArray > falcon_core::math::arrays::ControlArray::max (
    const std::shared_ptr< FArray< double > > & other
) const
```




<hr>



### function min [1/3]

_Return the minimum value of the array._ 
```C++
virtual double falcon_core::math::arrays::ControlArray::min () override const
```



Implements [*falcon\_core::generic::IFArray::min*](classfalcon__core_1_1generic_1_1IFArray.md#function-min)


<hr>



### function min [2/3]

```C++
std::shared_ptr< ControlArray > falcon_core::math::arrays::ControlArray::min (
    const std::shared_ptr< ControlArray > & other
) const
```




<hr>



### function min [3/3]

```C++
std::shared_ptr< ControlArray > falcon_core::math::arrays::ControlArray::min (
    const std::shared_ptr< FArray< double > > & other
) const
```




<hr>



### function operator\* 

```C++
std::shared_ptr< ControlArray > falcon_core::math::arrays::ControlArray::operator* (
    const double other
) const
```




<hr>



### function operator\* 

```C++
std::shared_ptr< ControlArray > falcon_core::math::arrays::ControlArray::operator* (
    const int other
) const
```




<hr>



### function operator+ 

```C++
std::shared_ptr< ControlArray > falcon_core::math::arrays::ControlArray::operator+ (
    const double other
) const
```




<hr>



### function operator+ 

```C++
std::shared_ptr< ControlArray > falcon_core::math::arrays::ControlArray::operator+ (
    const int other
) const
```




<hr>



### function operator+ 

```C++
std::shared_ptr< ControlArray > falcon_core::math::arrays::ControlArray::operator+ (
    const std::shared_ptr< ControlArray > & other
) const
```




<hr>



### function operator+ 

```C++
std::shared_ptr< ControlArray > falcon_core::math::arrays::ControlArray::operator+ (
    const std::shared_ptr< FArray > & other
) const
```




<hr>



### function operator- 

```C++
std::shared_ptr< ControlArray > falcon_core::math::arrays::ControlArray::operator- (
    const double other
) const
```




<hr>



### function operator- 

```C++
std::shared_ptr< ControlArray > falcon_core::math::arrays::ControlArray::operator- (
    const int other
) const
```




<hr>



### function operator- 

```C++
std::shared_ptr< ControlArray > falcon_core::math::arrays::ControlArray::operator- (
    const std::shared_ptr< ControlArray > & other
) const
```




<hr>



### function operator- 

```C++
std::shared_ptr< ControlArray > falcon_core::math::arrays::ControlArray::operator- (
    const std::shared_ptr< FArray< double > > & other
) const
```




<hr>



### function operator- 

```C++
std::shared_ptr< ControlArray > falcon_core::math::arrays::ControlArray::operator- () const
```




<hr>



### function operator/ 

```C++
std::shared_ptr< ControlArray > falcon_core::math::arrays::ControlArray::operator/ (
    const double other
) const
```




<hr>



### function operator/ 

```C++
std::shared_ptr< ControlArray > falcon_core::math::arrays::ControlArray::operator/ (
    const int other
) const
```




<hr>



### function operator= 

```C++
ControlArray & falcon_core::math::arrays::ControlArray::operator= (
    const ControlArray & other
) 
```




<hr>



### function operator^ 

```C++
std::shared_ptr< ControlArray > falcon_core::math::arrays::ControlArray::operator^ (
    const double other
) const
```




<hr>



### function reshape 

_Return a new Array with the given shape._ 
```C++
std::shared_ptr< ControlArray > falcon_core::math::arrays::ControlArray::reshape (
    const std::vector< size_t > & shape
) const
```





**Parameters:**


* `shape` The new shape. 



**Returns:**

A reshaped [**ControlArray**](classfalcon__core_1_1math_1_1arrays_1_1ControlArray.md). 





        

<hr>
## Protected Functions Documentation




### function ControlArray [1/5]

```C++
falcon_core::math::arrays::ControlArray::ControlArray () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::math::arrays::ControlArray::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::math::arrays::ControlArray::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/math/arrays/ControlArray.hpp`

