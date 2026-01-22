

# Class falcon\_core::math::AnalyticFunction



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**math**](namespacefalcon__core_1_1math.md) **>** [**AnalyticFunction**](classfalcon__core_1_1math_1_1AnalyticFunction.md)








Inherits the following classes: [falcon\_core::generic::List](classfalcon__core_1_1generic_1_1List.md)


Inherited by the following classes: [falcon\_core::instrument\_interfaces::port\_transforms::PortTransform](classfalcon__core_1_1instrument__interfaces_1_1port__transforms_1_1PortTransform.md)














## Public Types inherited from falcon_core::generic::List

See [falcon\_core::generic::List](classfalcon__core_1_1generic_1_1List.md)

| Type | Name |
| ---: | :--- |
| typedef typename Container::const\_iterator | [**const\_iterator**](classfalcon__core_1_1generic_1_1List.md#typedef-const_iterator)  <br> |
| typedef typename Container::iterator | [**iterator**](classfalcon__core_1_1generic_1_1List.md#typedef-iterator)  <br> |


























































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**AnalyticFunction**](#function-analyticfunction-13) (const AnalyticFunction & other) <br> |
|   | [**AnalyticFunction**](#function-analyticfunction-23) (const generic::ListSP&lt; VariableName &gt; & labels, const std::string & expression) <br>_Construct an_ [_**AnalyticFunction**_](classfalcon__core_1_1math_1_1AnalyticFunction.md) _with a mapping of the function's arguments to their names._ |
|  double | [**evaluate**](#function-evaluate-12) (const generic::MapSP&lt; VariableName, double &gt; & args, const double & time) const<br>_Returns the evaluated analytic function._  |
|  generic::FArraySP&lt; double &gt; | [**evaluate**](#function-evaluate-22) (const generic::MapSP&lt; VariableName, double &gt; & args, const double & deltaT, const double & maxTime) const<br>_Returns the evaluated analytic function._  |
|  const generic::ListSP&lt; VariableName &gt; | [**labels**](#function-labels) () const<br>_Return the set of labels in proper order of the function's arguments to their names._  |
|  bool | [**operator!=**](#function-operator) (const AnalyticFunction & other) const<br> |
|  AnalyticFunction & | [**operator=**](#function-operator_1) (const AnalyticFunction & other) <br> |
|  bool | [**operator==**](#function-operator_2) (const AnalyticFunction & other) const<br> |


## Public Functions inherited from falcon_core::generic::List

See [falcon\_core::generic::List](classfalcon__core_1_1generic_1_1List.md)

| Type | Name |
| ---: | :--- |
|   | [**List**](classfalcon__core_1_1generic_1_1List.md#function-list-16) (const List&lt; Value &gt; & other) <br> |
|   | [**List**](classfalcon__core_1_1generic_1_1List.md#function-list-26) (iterator begin, iterator end) <br> |
|   | [**List**](classfalcon__core_1_1generic_1_1List.md#function-list-36) () <br>[_**List**_](classfalcon__core_1_1generic_1_1List.md) _can be constructed in 5 different ways:_ |
|   | [**List**](classfalcon__core_1_1generic_1_1List.md#function-list-46) (size\_t count) <br> |
|   | [**List**](classfalcon__core_1_1generic_1_1List.md#function-list-56) (size\_t count, const StoredValue & value) <br> |
|   | [**List**](classfalcon__core_1_1generic_1_1List.md#function-list-66) (const Container & init) <br> |
|  std::conditional\_t&lt; std::is\_same&lt; typename [**category::determine\_bool\_tag**](structfalcon__core_1_1generic_1_1category_1_1determine__bool__tag.md)&lt; Value &gt;::type, [**category::bool\_tag**](structfalcon__core_1_1generic_1_1category_1_1bool__tag.md) &gt;::value, StoredValue, const StoredValue & &gt; | [**at**](classfalcon__core_1_1generic_1_1List.md#function-at-12) (const size\_t idx) const<br> |
|  std::conditional\_t&lt; std::is\_same&lt; typename [**category::determine\_bool\_tag**](structfalcon__core_1_1generic_1_1category_1_1determine__bool__tag.md)&lt; Value &gt;::type, [**category::bool\_tag**](structfalcon__core_1_1generic_1_1category_1_1bool__tag.md) &gt;::value, StoredValue, StoredValue & &gt; | [**at**](classfalcon__core_1_1generic_1_1List.md#function-at-22) (const size\_t idx) <br> |
|  StoredValue | [**back**](classfalcon__core_1_1generic_1_1List.md#function-back-12) () <br>_Return the last element of a list._  |
|  const StoredValue & | [**back**](classfalcon__core_1_1generic_1_1List.md#function-back-22) () const<br>_Return the last element of a list._  |
|  iterator | [**begin**](classfalcon__core_1_1generic_1_1List.md#function-begin-12) () <br> |
|  const\_iterator | [**begin**](classfalcon__core_1_1generic_1_1List.md#function-begin-22) () const<br> |
|  void | [**clear**](classfalcon__core_1_1generic_1_1List.md#function-clear) () <br>_clears to contents of the list._  |
|  bool | [**contains**](classfalcon__core_1_1generic_1_1List.md#function-contains) (const StoredValue & value) const<br> |
|  bool | [**empty**](classfalcon__core_1_1generic_1_1List.md#function-empty) () const<br> |
|  iterator | [**end**](classfalcon__core_1_1generic_1_1List.md#function-end-12) () <br> |
|  const\_iterator | [**end**](classfalcon__core_1_1generic_1_1List.md#function-end-22) () const<br> |
|  void | [**erase\_at**](classfalcon__core_1_1generic_1_1List.md#function-erase_at) (size\_t idx) <br>_Allows for targetted eraseall of elements at an index._  |
|  size\_t | [**index**](classfalcon__core_1_1generic_1_1List.md#function-index) (const StoredValue & value) const<br> |
|  void | [**insert**](classfalcon__core_1_1generic_1_1List.md#function-insert) (iterator pos, const\_iterator first, const\_iterator last) <br> |
|  std::shared\_ptr&lt; List&lt; Value &gt; &gt; | [**intersection**](classfalcon__core_1_1generic_1_1List.md#function-intersection) (const std::shared\_ptr&lt; List&lt; Value &gt; &gt; & other) const<br>_Finds the intersection between this list and another._  |
|  const Container | [**items**](classfalcon__core_1_1generic_1_1List.md#function-items-12) () const<br> |
|  Container | [**items**](classfalcon__core_1_1generic_1_1List.md#function-items-22) () <br> |
|  bool | [**operator!=**](classfalcon__core_1_1generic_1_1List.md#function-operator) (const List&lt; Value &gt; & other) const<br> |
|  List | [**operator=**](classfalcon__core_1_1generic_1_1List.md#function-operator_1) (const List&lt; Value &gt; & other) <br> |
|  bool | [**operator==**](classfalcon__core_1_1generic_1_1List.md#function-operator_2) (const List&lt; Value &gt; & other) const<br> |
|  StoredValue | [**operator[]**](classfalcon__core_1_1generic_1_1List.md#function-operator_3) (const size\_t idx) <br> |
|  const StoredValue & | [**operator[]**](classfalcon__core_1_1generic_1_1List.md#function-operator_4) (const size\_t idx) const<br> |
|  void | [**push\_back**](classfalcon__core_1_1generic_1_1List.md#function-push_back) (const StoredValue & item) <br> |
|  void | [**replace\_at**](classfalcon__core_1_1generic_1_1List.md#function-replace_at) (size\_t idx, const StoredValue & value) <br> |
|  void | [**serialize**](classfalcon__core_1_1generic_1_1List.md#function-serialize) (Archive & ar) <br> |
|  size\_t | [**size**](classfalcon__core_1_1generic_1_1List.md#function-size) () const<br> |


## Public Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  void | [**serialize**](classfalcon__core_1_1generic_1_1Song.md#function-serialize) (Archive &) <br>_cereal serialization interface. Override in derived classes._  |
|  std::string | [**to\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-to_json_string) () const<br>_Serialize this object to a JSON string._  |
| virtual  | [**~Song**](classfalcon__core_1_1generic_1_1Song.md#function-song) () = default<br> |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; AnalyticFunction &gt; | [**Constant**](#function-constant) (const double & value) <br>_Construct an constant function. The equation is : const where const is supplied here on construction._  |
|  std::shared\_ptr&lt; AnalyticFunction &gt; | [**Identity**](#function-identity) () <br>_Construct an identity. The equation is : x[0] where x[0] is some supplied quantity._  |


## Public Static Functions inherited from falcon_core::generic::List

See [falcon\_core::generic::List](classfalcon__core_1_1generic_1_1List.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; List&lt; Value &gt; &gt; | [**allocate**](classfalcon__core_1_1generic_1_1List.md#function-allocate) (size\_t count) <br> |
|  std::shared\_ptr&lt; List&lt; Value &gt; &gt; | [**create**](classfalcon__core_1_1generic_1_1List.md#function-create) (const Container & init) <br> |
|  std::shared\_ptr&lt; List&lt; Value &gt; &gt; | [**create\_empty**](classfalcon__core_1_1generic_1_1List.md#function-create_empty) () <br> |
|  std::shared\_ptr&lt; List&lt; Value &gt; &gt; | [**fill\_value**](classfalcon__core_1_1generic_1_1List.md#function-fill_value) (size\_t count, const StoredValue & value) <br> |


## Public Static Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; T &gt; | [**from\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-from_json_string) (const std::string & json) <br>_Deserialize an object from a JSON string._  |




## Protected Types inherited from falcon_core::generic::List

See [falcon\_core::generic::List](classfalcon__core_1_1generic_1_1List.md)

| Type | Name |
| ---: | :--- |
| typedef std::vector&lt; StoredValue &gt; | [**Container**](classfalcon__core_1_1generic_1_1List.md#typedef-container)  <br> |
| typedef typename std::conditional&lt; std::is\_base\_of&lt; [**Song**](classfalcon__core_1_1generic_1_1Song.md), Value &gt;::value, std::shared\_ptr&lt; Value &gt;, Value &gt;::type | [**StoredValue**](classfalcon__core_1_1generic_1_1List.md#typedef-storedvalue)  <br> |


























































## Protected Functions

| Type | Name |
| ---: | :--- |
|   | [**AnalyticFunction**](#function-analyticfunction-33) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |


## Protected Functions inherited from falcon_core::generic::List

See [falcon\_core::generic::List](classfalcon__core_1_1generic_1_1List.md)

| Type | Name |
| ---: | :--- |
|  StoredValue & | [**at\_impl**](classfalcon__core_1_1generic_1_1List.md#function-at_impl-14) (size\_t idx, [**category::other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md)) <br> |
|  const StoredValue & | [**at\_impl**](classfalcon__core_1_1generic_1_1List.md#function-at_impl-24) (size\_t idx, [**category::other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md)) const<br> |
|  StoredValue | [**at\_impl**](classfalcon__core_1_1generic_1_1List.md#function-at_impl-34) (size\_t idx, [**category::bool\_tag**](structfalcon__core_1_1generic_1_1category_1_1bool__tag.md)) <br> |
|  const StoredValue | [**at\_impl**](classfalcon__core_1_1generic_1_1List.md#function-at_impl-44) (size\_t idx, [**category::bool\_tag**](structfalcon__core_1_1generic_1_1category_1_1bool__tag.md)) const<br> |
|  bool | [**contains\_impl**](classfalcon__core_1_1generic_1_1List.md#function-contains_impl-13) (const std::shared\_ptr&lt; T &gt; & value, [**category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md)) const<br> |
|  bool | [**contains\_impl**](classfalcon__core_1_1generic_1_1List.md#function-contains_impl-23) (const T & value, [**category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md)) const<br> |
|  bool | [**contains\_impl**](classfalcon__core_1_1generic_1_1List.md#function-contains_impl-33) (const T & value, [**category::other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md)) const<br> |
|  void | [**copy\_items\_impl**](classfalcon__core_1_1generic_1_1List.md#function-copy_items_impl-13) (const Container & src, [**category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md)) <br> |
|  void | [**copy\_items\_impl**](classfalcon__core_1_1generic_1_1List.md#function-copy_items_impl-23) (const Container & src, [**category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md)) <br> |
|  void | [**copy\_items\_impl**](classfalcon__core_1_1generic_1_1List.md#function-copy_items_impl-33) (const Container &, [**category::other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md)) <br> |
|  void | [**create\_duplicates\_impl**](classfalcon__core_1_1generic_1_1List.md#function-create_duplicates_impl-13) (size\_t count, const std::shared\_ptr&lt; T &gt; & item, [**category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md)) <br> |
|  void | [**create\_duplicates\_impl**](classfalcon__core_1_1generic_1_1List.md#function-create_duplicates_impl-23) (size\_t count, const T & item, [**category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md)) <br> |
|  void | [**create\_duplicates\_impl**](classfalcon__core_1_1generic_1_1List.md#function-create_duplicates_impl-33) (size\_t count, const T & item, [**category::other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md)) <br> |
|  size\_t | [**index\_impl**](classfalcon__core_1_1generic_1_1List.md#function-index_impl-13) (const std::shared\_ptr&lt; T &gt; & value, [**category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md)) const<br> |
|  size\_t | [**index\_impl**](classfalcon__core_1_1generic_1_1List.md#function-index_impl-23) (const T & value, [**category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md)) const<br> |
|  size\_t | [**index\_impl**](classfalcon__core_1_1generic_1_1List.md#function-index_impl-33) (const T & value, [**category::other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md)) const<br> |
|  bool | [**operator\_equal\_impl**](classfalcon__core_1_1generic_1_1List.md#function-operator_equal_impl-13) (const List&lt; Value &gt; & other, [**category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md)) const<br> |
|  bool | [**operator\_equal\_impl**](classfalcon__core_1_1generic_1_1List.md#function-operator_equal_impl-23) (const List&lt; Value &gt; & other, [**category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md)) const<br> |
|  bool | [**operator\_equal\_impl**](classfalcon__core_1_1generic_1_1List.md#function-operator_equal_impl-33) (const List&lt; Value &gt; & other, [**category::other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md)) const<br> |
|  void | [**push\_back\_impl**](classfalcon__core_1_1generic_1_1List.md#function-push_back_impl-13) (const std::shared\_ptr&lt; T &gt; & item, [**category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md)) <br> |
|  void | [**push\_back\_impl**](classfalcon__core_1_1generic_1_1List.md#function-push_back_impl-23) (const T & item, [**category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md)) <br> |
|  void | [**push\_back\_impl**](classfalcon__core_1_1generic_1_1List.md#function-push_back_impl-33) (const T & item, [**category::other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md)) <br> |










## Public Functions Documentation




### function AnalyticFunction [1/3]

```C++
falcon_core::math::AnalyticFunction::AnalyticFunction (
    const AnalyticFunction & other
) 
```




<hr>



### function AnalyticFunction [2/3]

_Construct an_ [_**AnalyticFunction**_](classfalcon__core_1_1math_1_1AnalyticFunction.md) _with a mapping of the function's arguments to their names._
```C++
falcon_core::math::AnalyticFunction::AnalyticFunction (
    const generic::ListSP< VariableName > & labels,
    const std::string & expression
) 
```





**Parameters:**


* `labels` The label for each element of the vector 
* `expression` The mathematical expression to be evaluated 




        

<hr>



### function evaluate [1/2]

_Returns the evaluated analytic function._ 
```C++
double falcon_core::math::AnalyticFunction::evaluate (
    const generic::MapSP< VariableName, double > & args,
    const double & time
) const
```





**Parameters:**


* `args` The vector arguments supplied with human readable names 
* `time` The time to evaluate the function at.. 




        

<hr>



### function evaluate [2/2]

_Returns the evaluated analytic function._ 
```C++
generic::FArraySP< double > falcon_core::math::AnalyticFunction::evaluate (
    const generic::MapSP< VariableName, double > & args,
    const double & deltaT,
    const double & maxTime
) const
```





**Parameters:**


* `args` The vector arguments supplied with human readable names 
* `deltaT` The different between calculated datapoints 
* `maxTime` The total time to expend running the calculation. 




        

<hr>



### function labels 

_Return the set of labels in proper order of the function's arguments to their names._ 
```C++
const generic::ListSP< VariableName > falcon_core::math::AnalyticFunction::labels () const
```




<hr>



### function operator!= 

```C++
bool falcon_core::math::AnalyticFunction::operator!= (
    const AnalyticFunction & other
) const
```




<hr>



### function operator= 

```C++
AnalyticFunction & falcon_core::math::AnalyticFunction::operator= (
    const AnalyticFunction & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::math::AnalyticFunction::operator== (
    const AnalyticFunction & other
) const
```




<hr>
## Public Static Functions Documentation




### function Constant 

_Construct an constant function. The equation is : const where const is supplied here on construction._ 
```C++
static std::shared_ptr< AnalyticFunction > falcon_core::math::AnalyticFunction::Constant (
    const double & value
) 
```




<hr>



### function Identity 

_Construct an identity. The equation is : x[0] where x[0] is some supplied quantity._ 
```C++
static std::shared_ptr< AnalyticFunction > falcon_core::math::AnalyticFunction::Identity () 
```




<hr>
## Protected Functions Documentation




### function AnalyticFunction [3/3]

```C++
falcon_core::math::AnalyticFunction::AnalyticFunction () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::math::AnalyticFunction::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::math::AnalyticFunction::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/math/AnalyticFunction.hpp`

