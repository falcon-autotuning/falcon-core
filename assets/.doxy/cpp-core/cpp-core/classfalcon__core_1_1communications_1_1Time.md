

# Class falcon\_core::communications::Time



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**communications**](namespacefalcon__core_1_1communications.md) **>** [**Time**](classfalcon__core_1_1communications_1_1Time.md)



_Represents a point in time with microsecond precision._ 

* `#include <Time.hpp>`



Inherits the following classes: [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Time**](#function-time-13) (const [**Time**](classfalcon__core_1_1communications_1_1Time.md) & other) <br> |
|   | [**Time**](#function-time-23) () <br>_Construct a Tiem object at the current time._  |
|   | [**Time**](#function-time-33) (long long micro\_seconds\_since\_epoch) <br>_Construct a_ [_**Time**_](classfalcon__core_1_1communications_1_1Time.md) _object at a specific time._ |
|  const long long | [**micro\_seconds\_since\_epoch**](#function-micro_seconds_since_epoch) () const<br>_Get the time in microseconds since epoch._  |
|  bool | [**operator!=**](#function-operator) (const [**Time**](classfalcon__core_1_1communications_1_1Time.md) & other) <br> |
|  [**Time**](classfalcon__core_1_1communications_1_1Time.md) & | [**operator=**](#function-operator_1) (const [**Time**](classfalcon__core_1_1communications_1_1Time.md) & other) <br> |
|  bool | [**operator==**](#function-operator_2) (const [**Time**](classfalcon__core_1_1communications_1_1Time.md) & other) <br> |
|  const long long | [**time**](#function-time) () const<br>_Get the time in seconds since epoch._  |
|  const std::string | [**to\_string**](#function-to_string) () const<br>_Convert the_ [_**Time**_](classfalcon__core_1_1communications_1_1Time.md) _to a human-readable string._ |


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




### function Time [1/3]

```C++
falcon_core::communications::Time::Time (
    const Time & other
) 
```




<hr>



### function Time [2/3]

_Construct a Tiem object at the current time._ 
```C++
falcon_core::communications::Time::Time () 
```




<hr>



### function Time [3/3]

_Construct a_ [_**Time**_](classfalcon__core_1_1communications_1_1Time.md) _object at a specific time._
```C++
falcon_core::communications::Time::Time (
    long long micro_seconds_since_epoch
) 
```





**Parameters:**


* `micro_seconds_since_epoch` The time in microseconds since the epoch. 




        

<hr>



### function micro\_seconds\_since\_epoch 

_Get the time in microseconds since epoch._ 
```C++
const long long falcon_core::communications::Time::micro_seconds_since_epoch () const
```





**Returns:**

The time in microseconds since epoch. 





        

<hr>



### function operator!= 

```C++
bool falcon_core::communications::Time::operator!= (
    const Time & other
) 
```




<hr>



### function operator= 

```C++
Time & falcon_core::communications::Time::operator= (
    const Time & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::communications::Time::operator== (
    const Time & other
) 
```




<hr>



### function time 

_Get the time in seconds since epoch._ 
```C++
const long long falcon_core::communications::Time::time () const
```





**Returns:**

The time in seconds since epoch. 





        

<hr>



### function to\_string 

_Convert the_ [_**Time**_](classfalcon__core_1_1communications_1_1Time.md) _to a human-readable string._
```C++
const std::string falcon_core::communications::Time::to_string () const
```





**Returns:**

A string representation of the [**Time**](classfalcon__core_1_1communications_1_1Time.md). 





        

<hr>
## Protected Functions Documentation




### function serialize 

```C++
template<class Archive>
inline void falcon_core::communications::Time::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::communications::Time::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/communications/Time.hpp`

