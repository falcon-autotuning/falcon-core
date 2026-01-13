

# Class falcon\_core::math::arrays::IncreasingAlignment



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**math**](namespacefalcon__core_1_1math.md) **>** [**arrays**](namespacefalcon__core_1_1math_1_1arrays.md) **>** [**IncreasingAlignment**](classfalcon__core_1_1math_1_1arrays_1_1IncreasingAlignment.md)



_A three state system. The three states are 1, -1, and 0. 0 implies no trend in the domain._ 

* `#include <IncreasingAlignment.hpp>`



Inherits the following classes: [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**IncreasingAlignment**](#function-increasingalignment-13) (const [**IncreasingAlignment**](classfalcon__core_1_1math_1_1arrays_1_1IncreasingAlignment.md) & other) <br> |
|   | [**IncreasingAlignment**](#function-increasingalignment-23) () <br> |
|   | [**IncreasingAlignment**](#function-increasingalignment-33) (const bool alignment) <br> |
|  int | [**alignment**](#function-alignment) () const<br>_Return the alignment of the domain._  |
|  bool | [**operator!=**](#function-operator) (const [**IncreasingAlignment**](classfalcon__core_1_1math_1_1arrays_1_1IncreasingAlignment.md) & other) const<br> |
|  [**IncreasingAlignment**](classfalcon__core_1_1math_1_1arrays_1_1IncreasingAlignment.md) & | [**operator=**](#function-operator_1) (const [**IncreasingAlignment**](classfalcon__core_1_1math_1_1arrays_1_1IncreasingAlignment.md) & other) <br> |
|  bool | [**operator==**](#function-operator_2) (const [**IncreasingAlignment**](classfalcon__core_1_1math_1_1arrays_1_1IncreasingAlignment.md) & other) const<br> |


## Public Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  void | [**serialize**](classfalcon__core_1_1generic_1_1Song.md#function-serialize) (Archive &) <br>_cereal serialization interface. Override in derived classes._  |
|  std::string | [**to\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-to_json_string) () const<br>_Serialize this object to a JSON string._  |
| virtual  | [**~Song**](classfalcon__core_1_1generic_1_1Song.md#function-song) () = default<br> |




## Public Static Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; T &gt; | [**from\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-from_json_string) (const std::string & json) <br>_Deserialize an object from a JSON string._  |










































## Protected Functions

| Type | Name |
| ---: | :--- |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |








## Public Functions Documentation




### function IncreasingAlignment [1/3]

```C++
falcon_core::math::arrays::IncreasingAlignment::IncreasingAlignment (
    const IncreasingAlignment & other
) 
```




<hr>



### function IncreasingAlignment [2/3]

```C++
falcon_core::math::arrays::IncreasingAlignment::IncreasingAlignment () 
```




<hr>



### function IncreasingAlignment [3/3]

```C++
falcon_core::math::arrays::IncreasingAlignment::IncreasingAlignment (
    const bool alignment
) 
```




<hr>



### function alignment 

_Return the alignment of the domain._ 
```C++
int falcon_core::math::arrays::IncreasingAlignment::alignment () const
```




<hr>



### function operator!= 

```C++
bool falcon_core::math::arrays::IncreasingAlignment::operator!= (
    const IncreasingAlignment & other
) const
```




<hr>



### function operator= 

```C++
IncreasingAlignment & falcon_core::math::arrays::IncreasingAlignment::operator= (
    const IncreasingAlignment & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::math::arrays::IncreasingAlignment::operator== (
    const IncreasingAlignment & other
) const
```




<hr>
## Protected Functions Documentation




### function serialize 

```C++
template<class Archive>
inline void falcon_core::math::arrays::IncreasingAlignment::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::math::arrays::IncreasingAlignment::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/math/arrays/IncreasingAlignment.hpp`

