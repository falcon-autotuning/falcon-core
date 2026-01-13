

# Class falcon\_core::communications::HDF5Data



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**communications**](namespacefalcon__core_1_1communications.md) **>** [**HDF5Data**](classfalcon__core_1_1communications_1_1HDF5Data.md)








Inherits the following classes: [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**HDF5Data**](#function-hdf5data-23) (const [**HDF5Data**](classfalcon__core_1_1communications_1_1HDF5Data.md) & other) <br> |
|   | [**HDF5Data**](#function-hdf5data-33) (const math::AxesSP&lt; int &gt; & shape, const math::AxesSP&lt; [**math::arrays::ControlArray**](classfalcon__core_1_1math_1_1arrays_1_1ControlArray.md) &gt; & unit\_domain, const math::AxesSP&lt; [**math::domains::CoupledLabelledDomain**](classfalcon__core_1_1math_1_1domains_1_1CoupledLabelledDomain.md) &gt; & domain\_labels, const math::arrays::LabelledArraysSP&lt; [**math::arrays::LabelledMeasuredArray**](classfalcon__core_1_1math_1_1arrays_1_1LabelledMeasuredArray.md) &gt; & ranges, const std::shared\_ptr&lt; Metadata &gt; & metadata, const std::string & measurement\_title, const int & unique\_id, const int & timestamp) <br>_Construct the protable data for database storage._  |
|  math::AxesSP&lt; [**math::domains::CoupledLabelledDomain**](classfalcon__core_1_1math_1_1domains_1_1CoupledLabelledDomain.md) &gt; | [**domain\_labels**](#function-domain_labels) () const<br>_Get the domain labels for each axis._  |
|  std::string | [**measurement\_title**](#function-measurement_title) () const<br>_Get the measurement title._  |
|  std::shared\_ptr&lt; Metadata &gt; | [**metadata**](#function-metadata) () const<br>_Get the metadata for the measurement._  |
|  bool | [**operator!=**](#function-operator) (const [**HDF5Data**](classfalcon__core_1_1communications_1_1HDF5Data.md) & other) <br> |
|  [**HDF5Data**](classfalcon__core_1_1communications_1_1HDF5Data.md) & | [**operator=**](#function-operator_1) (const [**HDF5Data**](classfalcon__core_1_1communications_1_1HDF5Data.md) & other) <br> |
|  bool | [**operator==**](#function-operator_2) (const [**HDF5Data**](classfalcon__core_1_1communications_1_1HDF5Data.md) & other) <br> |
|  math::arrays::LabelledArraysSP&lt; [**math::arrays::LabelledMeasuredArray**](classfalcon__core_1_1math_1_1arrays_1_1LabelledMeasuredArray.md) &gt; | [**ranges**](#function-ranges) () const<br>_Get the ranges for each axis._  |
|  math::AxesSP&lt; int &gt; | [**shape**](#function-shape) () const<br>_Get the shape of the data array._  |
|  int | [**timestamp**](#function-timestamp) () const<br>_Get the timestamp for the measurement._  |
|  const std::pair&lt; communications::messages::MeasurementResponseSP, communications::messages::MeasurementRequestSP &gt; | [**to\_communications**](#function-to_communications) () const<br>_Convert from an_ [_**HDF5Data**_](classfalcon__core_1_1communications_1_1HDF5Data.md) _object to a MeasurementResponse and a Metadata._ |
|  void | [**to\_file**](#function-to_file) (const std::string & path) const<br>_Convert from an_ [_**HDF5Data**_](classfalcon__core_1_1communications_1_1HDF5Data.md) _object to a file._ |
|  int | [**unique\_id**](#function-unique_id) () const<br>_Get the unique id for the measurement._  |
|  math::AxesSP&lt; [**math::arrays::ControlArray**](classfalcon__core_1_1math_1_1arrays_1_1ControlArray.md) &gt; | [**unit\_domain**](#function-unit_domain) () const<br>_Get the unit domain for each axis._  |


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
|  const std::shared\_ptr&lt; [**HDF5Data**](classfalcon__core_1_1communications_1_1HDF5Data.md) &gt; | [**from\_communications**](#function-from_communications) (const messages::MeasurementRequestSP & request, const messages::MeasurementResponseSP & response, const voltage\_states::DeviceVoltageStatesSP & device\_voltage\_states, const boost::uuids::uuid & session\_id, const std::string & measurement\_title, const int & unique\_id, const int & timestamp) <br>_Load the data from a MeasurementResponse and MeasurementResponse._  |
|  const std::shared\_ptr&lt; [**HDF5Data**](classfalcon__core_1_1communications_1_1HDF5Data.md) &gt; | [**from\_file**](#function-from_file) (const std::string & path) <br>_Convert from a file to an_ [_**HDF5Data**_](classfalcon__core_1_1communications_1_1HDF5Data.md) _object._ |


## Public Static Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; T &gt; | [**from\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-from_json_string) (const std::string & json) <br>_Deserialize an object from a JSON string._  |










































## Protected Functions

| Type | Name |
| ---: | :--- |
|   | [**HDF5Data**](#function-hdf5data-13) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |








## Public Functions Documentation




### function HDF5Data [2/3]

```C++
falcon_core::communications::HDF5Data::HDF5Data (
    const HDF5Data & other
) 
```




<hr>



### function HDF5Data [3/3]

_Construct the protable data for database storage._ 
```C++
falcon_core::communications::HDF5Data::HDF5Data (
    const math::AxesSP< int > & shape,
    const math::AxesSP< math::arrays::ControlArray > & unit_domain,
    const math::AxesSP< math::domains::CoupledLabelledDomain > & domain_labels,
    const math::arrays::LabelledArraysSP< math::arrays::LabelledMeasuredArray > & ranges,
    const std::shared_ptr< Metadata > & metadata,
    const std::string & measurement_title,
    const int & unique_id,
    const int & timestamp
) 
```





**Parameters:**


* `shape` The shape of the data array. 
* `unit_domain` The unit domain for each axis. 
* `domain_labels` The domain labels for each axis. 
* `ranges` The ranges for each axis. 
* `metadata` The metadata for the measurement. 
* `measurement_title` The title of the measurement. 
* `unique_id` A unique id for the measurement. 
* `timestamp` A timestamp for the measurement. 




        

<hr>



### function domain\_labels 

_Get the domain labels for each axis._ 
```C++
math::AxesSP< math::domains::CoupledLabelledDomain > falcon_core::communications::HDF5Data::domain_labels () const
```





**Returns:**

The domain labels for each axis. 





        

<hr>



### function measurement\_title 

_Get the measurement title._ 
```C++
std::string falcon_core::communications::HDF5Data::measurement_title () const
```





**Returns:**

The measurement title. 





        

<hr>



### function metadata 

_Get the metadata for the measurement._ 
```C++
std::shared_ptr< Metadata > falcon_core::communications::HDF5Data::metadata () const
```





**Returns:**

The metadata for the measurement. 





        

<hr>



### function operator!= 

```C++
bool falcon_core::communications::HDF5Data::operator!= (
    const HDF5Data & other
) 
```




<hr>



### function operator= 

```C++
HDF5Data & falcon_core::communications::HDF5Data::operator= (
    const HDF5Data & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::communications::HDF5Data::operator== (
    const HDF5Data & other
) 
```




<hr>



### function ranges 

_Get the ranges for each axis._ 
```C++
math::arrays::LabelledArraysSP< math::arrays::LabelledMeasuredArray > falcon_core::communications::HDF5Data::ranges () const
```





**Returns:**

The ranges for each axis. 





        

<hr>



### function shape 

_Get the shape of the data array._ 
```C++
math::AxesSP< int > falcon_core::communications::HDF5Data::shape () const
```





**Returns:**

The shape of the data array. 





        

<hr>



### function timestamp 

_Get the timestamp for the measurement._ 
```C++
int falcon_core::communications::HDF5Data::timestamp () const
```





**Returns:**

The timestamp for the measurement. 





        

<hr>



### function to\_communications 

_Convert from an_ [_**HDF5Data**_](classfalcon__core_1_1communications_1_1HDF5Data.md) _object to a MeasurementResponse and a Metadata._
```C++
const std::pair< communications::messages::MeasurementResponseSP, communications::messages::MeasurementRequestSP > falcon_core::communications::HDF5Data::to_communications () const
```





**Returns:**

A pair of MeasurementResponse and MeasurementRequest. 





        

<hr>



### function to\_file 

_Convert from an_ [_**HDF5Data**_](classfalcon__core_1_1communications_1_1HDF5Data.md) _object to a file._
```C++
void falcon_core::communications::HDF5Data::to_file (
    const std::string & path
) const
```





**Parameters:**


* `path` The path to write the HDF5 file at. 




        

<hr>



### function unique\_id 

_Get the unique id for the measurement._ 
```C++
int falcon_core::communications::HDF5Data::unique_id () const
```





**Returns:**

The unique id for the measurement. 





        

<hr>



### function unit\_domain 

_Get the unit domain for each axis._ 
```C++
math::AxesSP< math::arrays::ControlArray > falcon_core::communications::HDF5Data::unit_domain () const
```





**Returns:**

The unit domain for each axis. 





        

<hr>
## Public Static Functions Documentation




### function from\_communications 

_Load the data from a MeasurementResponse and MeasurementResponse._ 
```C++
static const std::shared_ptr< HDF5Data > falcon_core::communications::HDF5Data::from_communications (
    const messages::MeasurementRequestSP & request,
    const messages::MeasurementResponseSP & response,
    const voltage_states::DeviceVoltageStatesSP & device_voltage_states,
    const boost::uuids::uuid & session_id,
    const std::string & measurement_title,
    const int & unique_id,
    const int & timestamp
) 
```





**Parameters:**


* `request` The MeasurementRequest from falcon. 
* `response` The MeasurementResponse from the instrument server. 
* `device_votlage_states` The current state of the device voltages. 
* `session_id` The name of the session from the instrument server. 
* `measurement_title` The title of the measurement. 
* `unique_id` A unique id for the measurement. 
* `timestamp` The time the measurement was taken. 



**Returns:**

A [**HDF5Data**](classfalcon__core_1_1communications_1_1HDF5Data.md) object. 





        

<hr>



### function from\_file 

_Convert from a file to an_ [_**HDF5Data**_](classfalcon__core_1_1communications_1_1HDF5Data.md) _object._
```C++
static const std::shared_ptr< HDF5Data > falcon_core::communications::HDF5Data::from_file (
    const std::string & path
) 
```





**Parameters:**


* `path` The path to the HDF5 file. 



**Returns:**

A [**HDF5Data**](classfalcon__core_1_1communications_1_1HDF5Data.md) object. 





        

<hr>
## Protected Functions Documentation




### function HDF5Data [1/3]

```C++
falcon_core::communications::HDF5Data::HDF5Data () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::communications::HDF5Data::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::communications::HDF5Data::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/communications/HDF5Data.hpp`

