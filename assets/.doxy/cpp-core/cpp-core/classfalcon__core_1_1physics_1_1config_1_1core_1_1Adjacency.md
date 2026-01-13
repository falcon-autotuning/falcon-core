

# Class falcon\_core::physics::config::core::Adjacency



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**physics**](namespacefalcon__core_1_1physics.md) **>** [**config**](namespacefalcon__core_1_1physics_1_1config.md) **>** [**core**](namespacefalcon__core_1_1physics_1_1config_1_1core.md) **>** [**Adjacency**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Adjacency.md)



_This a graph representation of the connections between gates in a quantum dot device._ 

* `#include <Adjacency.hpp>`



Inherits the following classes: [falcon\_core::generic::FArray](classfalcon__core_1_1generic_1_1FArray.md)
















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










































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Adjacency**](#function-adjacency-13) (const [**Adjacency**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Adjacency.md) & other) <br> |
|   | [**Adjacency**](#function-adjacency-23) (const xt::xarray&lt; int &gt; & matrix, const Indexes indexes) <br> |
|  std::vector&lt; std::pair&lt; size\_t, size\_t &gt; &gt; | [**get\_true\_pairs**](#function-get_true_pairs) () const<br>_Returns the pairs of indexes where the adjacency matrix is true (1)_  |
|  Indexes | [**indexes**](#function-indexes) () const<br> |
|  bool | [**operator!=**](#function-operator) (const [**Adjacency**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Adjacency.md) & other) const<br> |
|  [**Adjacency**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Adjacency.md) & | [**operator=**](#function-operator_1) (const [**Adjacency**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Adjacency.md) & other) <br> |
|  bool | [**operator==**](#function-operator_2) (const [**Adjacency**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Adjacency.md) & other) const<br> |


## Public Functions inherited from falcon_core::generic::FArray

See [falcon\_core::generic::FArray](classfalcon__core_1_1generic_1_1FArray.md)

| Type | Name |
| ---: | :--- |
|   | [**FArray**](classfalcon__core_1_1generic_1_1FArray.md#function-farray-15) (const [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; & other) <br> |
|   | [**FArray**](classfalcon__core_1_1generic_1_1FArray.md#function-farray-25) () = default<br> |
|   | [**FArray**](classfalcon__core_1_1generic_1_1FArray.md#function-farray-35) (const array\_type & arr) <br> |
|   | [**FArray**](classfalcon__core_1_1generic_1_1FArray.md#function-farray-45) (array\_type && arr) noexcept<br> |
|   | [**FArray**](classfalcon__core_1_1generic_1_1FArray.md#function-farray-55) (const std::vector&lt; size\_t &gt; & shape) <br> |
|  std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**abs**](classfalcon__core_1_1generic_1_1FArray.md#function-abs) () const<br> |
| virtual array\_type::iterator | [**begin**](classfalcon__core_1_1generic_1_1FArray.md#function-begin) () noexcept override<br> |
| virtual array\_type::const\_iterator | [**cbegin**](classfalcon__core_1_1generic_1_1FArray.md#function-cbegin) () noexcept override const<br> |
| virtual array\_type::const\_iterator | [**cend**](classfalcon__core_1_1generic_1_1FArray.md#function-cend) () noexcept override const<br> |
| virtual array\_type & | [**data**](classfalcon__core_1_1generic_1_1FArray.md#function-data-12) () noexcept override<br> |
| virtual const array\_type & | [**data**](classfalcon__core_1_1generic_1_1FArray.md#function-data-22) () noexcept override const<br> |
| virtual size\_t | [**dimension**](classfalcon__core_1_1generic_1_1FArray.md#function-dimension) () noexcept override const<br> |
| virtual array\_type::iterator | [**end**](classfalcon__core_1_1generic_1_1FArray.md#function-end) () noexcept override<br> |
|  std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**flip**](classfalcon__core_1_1generic_1_1FArray.md#function-flip) (size\_t axis) const<br>_Flip the data along the given axis._  |
|  double | [**get\_sum\_of\_squares**](classfalcon__core_1_1generic_1_1FArray.md#function-get_sum_of_squares-14) () const<br> |
|  double | [**get\_sum\_of\_squares**](classfalcon__core_1_1generic_1_1FArray.md#function-get_sum_of_squares-24) (const int other) const<br> |
|  double | [**get\_sum\_of\_squares**](classfalcon__core_1_1generic_1_1FArray.md#function-get_sum_of_squares-34) (const double other) const<br> |
|  double | [**get\_sum\_of\_squares**](classfalcon__core_1_1generic_1_1FArray.md#function-get_sum_of_squares-44) (const std::shared\_ptr&lt; [**generic::FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; & other) const<br> |
|  ListSP&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**gradient**](classfalcon__core_1_1generic_1_1FArray.md#function-gradient-12) () const<br>_Return the gradient of the data along all axes._  |
|  std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**gradient**](classfalcon__core_1_1generic_1_1FArray.md#function-gradient-22) (size\_t axis) const<br>_Return the gradient of the data along a given axis._  |
| virtual T | [**max**](classfalcon__core_1_1generic_1_1FArray.md#function-max-12) () override const<br> |
|  std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**max**](classfalcon__core_1_1generic_1_1FArray.md#function-max-22) (const std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; other) const<br> |
| virtual T | [**min**](classfalcon__core_1_1generic_1_1FArray.md#function-min-12) () override const<br> |
|  std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**min**](classfalcon__core_1_1generic_1_1FArray.md#function-min-22) (const std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; other) const<br> |
| virtual  | [**operator array\_type &**](classfalcon__core_1_1generic_1_1FArray.md#function-operator-array_type-&) () override<br> |
| virtual  | [**operator const array\_type &**](classfalcon__core_1_1generic_1_1FArray.md#function-operator-const-array_type-&) () override const<br> |
|  bool | [**operator!=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator) (const [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; & other) const<br> |
|  decltype(auto) | [**operator()**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_1) (Args &&... args) <br> |
|  decltype(auto) | [**operator()**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_2) (Args &&... args) const<br> |
| virtual reference | [**operator()**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_3) (size\_t i) override<br> |
| virtual const\_reference | [**operator()**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_4) (size\_t i) override const<br> |
|  std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**operator\***](classfalcon__core_1_1generic_1_1FArray.md#function-operator_5) (const double other) const<br> |
|  std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**operator\***](classfalcon__core_1_1generic_1_1FArray.md#function-operator_6) (const int other) const<br> |
|  std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**operator\***](classfalcon__core_1_1generic_1_1FArray.md#function-operator_7) (const std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; & other) const<br> |
|  [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; & | [**operator\*=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_8) (const double other) <br> |
|  [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; & | [**operator\*=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_9) (const int other) <br> |
|  [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; & | [**operator\*=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_10) (const [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; & other) <br> |
|  std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**operator+**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_11) (const double other) const<br> |
|  std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**operator+**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_12) (const int other) const<br> |
|  std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**operator+**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_13) (const std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; & other) const<br> |
|  [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; & | [**operator+=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_14) (const [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; & other) <br> |
|  [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; & | [**operator+=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_15) (const double other) <br> |
|  [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; & | [**operator+=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_16) (const int other) <br> |
|  std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**operator-**](classfalcon__core_1_1generic_1_1FArray.md#function-operator-) () const<br> |
|  std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**operator-**](classfalcon__core_1_1generic_1_1FArray.md#function-operator-_1) () <br> |
|  std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**operator-**](classfalcon__core_1_1generic_1_1FArray.md#function-operator-_2) (const std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; & other) const<br> |
|  std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**operator-**](classfalcon__core_1_1generic_1_1FArray.md#function-operator-_3) (const double other) const<br> |
|  std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**operator-**](classfalcon__core_1_1generic_1_1FArray.md#function-operator-_4) (const int other) const<br> |
|  [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; & | [**operator-=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator-_5) (const [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; & other) <br> |
|  [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; & | [**operator-=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator-_6) (const double other) <br> |
|  [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; & | [**operator-=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator-_7) (const int other) <br> |
|  std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**operator/**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_17) (const double other) const<br> |
|  std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**operator/**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_18) (const int other) const<br> |
|  std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**operator/**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_19) (const std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; & other) const<br> |
|  [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; & | [**operator/=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_20) (const double other) <br> |
|  [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; & | [**operator/=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_21) (const int other) <br> |
|  [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; & | [**operator/=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_22) (const [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; & other) <br> |
| virtual bool | [**operator&lt;**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_23) (const T & value) override const<br>_Check if any of the data is less than the value._  |
|  [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; & | [**operator=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_24) (const [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; & other) <br> |
|  [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; & | [**operator=**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_25) (const array\_type & arr) <br> |
|  bool | [**operator==**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_26) (const [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; & other) const<br> |
| virtual bool | [**operator&gt;**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_27) (const T & value) override const<br>_Check if any of the data is greater than the value._  |
|  std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; double &gt; &gt; | [**operator^**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_28) (const double other) const<br> |
|  std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**operator^**](classfalcon__core_1_1generic_1_1FArray.md#function-operator_29) (const int other) const<br> |
|  void | [**pow\_inplace**](classfalcon__core_1_1generic_1_1FArray.md#function-pow_inplace) (const T other) <br> |
| virtual T \* | [**raw\_data**](classfalcon__core_1_1generic_1_1FArray.md#function-raw_data-12) () noexcept override<br> |
| virtual const T \* | [**raw\_data**](classfalcon__core_1_1generic_1_1FArray.md#function-raw_data-22) () noexcept override const<br> |
| virtual void | [**remove\_offset**](classfalcon__core_1_1generic_1_1FArray.md#function-remove_offset) (const T & offset) override<br>_Remove the offset from the data._  |
|  std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**reshape**](classfalcon__core_1_1generic_1_1FArray.md#function-reshape) (const std::vector&lt; size\_t &gt; & shape) const<br>_Return a new Array with the given shape._  |
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




## Public Static Functions inherited from falcon_core::generic::FArray

See [falcon\_core::generic::FArray](classfalcon__core_1_1generic_1_1FArray.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**empty**](classfalcon__core_1_1generic_1_1FArray.md#function-empty) (const std::vector&lt; size\_t &gt; & shape) <br> |
|  std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**zeros**](classfalcon__core_1_1generic_1_1FArray.md#function-zeros) (const std::vector&lt; size\_t &gt; & shape) <br> |


## Public Static Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; T &gt; | [**from\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-from_json_string) (const std::string & json) <br>_Deserialize an object from a JSON string._  |




















































































## Protected Functions

| Type | Name |
| ---: | :--- |
|   | [**Adjacency**](#function-adjacency-33) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |


## Protected Functions inherited from falcon_core::generic::FArray

See [falcon\_core::generic::FArray](classfalcon__core_1_1generic_1_1FArray.md)

| Type | Name |
| ---: | :--- |
|  void | [**serialize**](classfalcon__core_1_1generic_1_1FArray.md#function-serialize) (Archive & ar) <br> |














## Public Functions Documentation




### function Adjacency [1/3]

```C++
falcon_core::physics::config::core::Adjacency::Adjacency (
    const Adjacency & other
) 
```




<hr>



### function Adjacency [2/3]

```C++
falcon_core::physics::config::core::Adjacency::Adjacency (
    const xt::xarray< int > & matrix,
    const Indexes indexes
) 
```




<hr>



### function get\_true\_pairs 

_Returns the pairs of indexes where the adjacency matrix is true (1)_ 
```C++
std::vector< std::pair< size_t, size_t > > falcon_core::physics::config::core::Adjacency::get_true_pairs () const
```




<hr>



### function indexes 

```C++
Indexes falcon_core::physics::config::core::Adjacency::indexes () const
```



## @brief Returns the indexes of the gates in the order for the adjacency



matrix 



        

<hr>



### function operator!= 

```C++
bool falcon_core::physics::config::core::Adjacency::operator!= (
    const Adjacency & other
) const
```




<hr>



### function operator= 

```C++
Adjacency & falcon_core::physics::config::core::Adjacency::operator= (
    const Adjacency & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::physics::config::core::Adjacency::operator== (
    const Adjacency & other
) const
```




<hr>
## Protected Functions Documentation




### function Adjacency [3/3]

```C++
falcon_core::physics::config::core::Adjacency::Adjacency () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::physics::config::core::Adjacency::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::physics::config::core::Adjacency::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/physics/config/core/Adjacency.hpp`

