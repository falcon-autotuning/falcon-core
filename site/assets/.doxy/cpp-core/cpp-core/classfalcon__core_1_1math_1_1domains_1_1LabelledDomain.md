

# Class falcon\_core::math::domains::LabelledDomain



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**math**](namespacefalcon__core_1_1math.md) **>** [**domains**](namespacefalcon__core_1_1math_1_1domains.md) **>** [**LabelledDomain**](classfalcon__core_1_1math_1_1domains_1_1LabelledDomain.md)



[_**Domain**_](classfalcon__core_1_1math_1_1domains_1_1Domain.md) _with an associated label with the instrument associated._

* `#include <LabelledDomain.hpp>`



Inherits the following classes: [falcon\_core::math::domains::Domain](classfalcon__core_1_1math_1_1domains_1_1Domain.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**LabelledDomain**](#function-labelleddomain-13) (const LabelledDomain & other) <br> |
|   | [**LabelledDomain**](#function-labelleddomain-23) (const std::string & default\_name, const std::pair&lt; double, double &gt; & bounds, const physics::device\_structures::ConnectionSP & psuedo\_name, const instrument\_interfaces::names::Instrument & instrument\_type, bool lesser\_bound\_contained, bool greater\_bound\_contained, const physics::units::SymbolUnitSP & units, const std::string & description, const instrument\_interfaces::names::PortType type=instrument\_interfaces::names::PortType::Knob) <br>_Construct a labelled domain. @default\_name The default\_name for the instrument. @bounds The bounds on the domain. @psuedo\_name The name of the connection on the instrument if available. @instrument\_type The type of instrument connected to @lesser\_bound\_contained If the lesser\_bound is contained in the domain. @greater\_bound\_contained If the greater\_bound is contained in the domain. @units The units of the instrument. @description The description of the instrument._  |
|  std::shared\_ptr&lt; Domain &gt; | [**domain**](#function-domain) () const<br>_Gets the domain associated with the port._  |
|  bool | [**matching\_port**](#function-matching_port) (const instrument\_interfaces::names::InstrumentPortSP & port) const<br>_Checks if the port matches the given port._  |
|  bool | [**operator!=**](#function-operator) (const LabelledDomain & other) const<br> |
|  LabelledDomain & | [**operator=**](#function-operator_1) (const LabelledDomain & other) <br> |
|  bool | [**operator==**](#function-operator_2) (const LabelledDomain & other) const<br> |
|  const instrument\_interfaces::names::InstrumentPortSP & | [**port**](#function-port) () const<br>_Get the port._  |


## Public Functions inherited from falcon_core::math::domains::Domain

See [falcon\_core::math::domains::Domain](classfalcon__core_1_1math_1_1domains_1_1Domain.md)

| Type | Name |
| ---: | :--- |
|   | [**Domain**](classfalcon__core_1_1math_1_1domains_1_1Domain.md#function-domain-14) (const Domain & other) <br> |
|   | [**Domain**](classfalcon__core_1_1math_1_1domains_1_1Domain.md#function-domain-24) (double min\_val, double max\_val, bool lesser\_bound\_contained=true, bool greater\_bound\_contained=true) <br>_Construct a_ [_**Domain**_](classfalcon__core_1_1math_1_1domains_1_1Domain.md) _._ |
|   | [**Domain**](classfalcon__core_1_1math_1_1domains_1_1Domain.md#function-domain-34) (std::pair&lt; double, double &gt; bounds, bool lesser\_bound\_contained=true, bool greater\_bound\_contained=true) <br>_Construct a_ [_**Domain**_](classfalcon__core_1_1math_1_1domains_1_1Domain.md) _from a pair of bounds._ |
|  const std::pair&lt; double, double &gt; | [**bounds**](classfalcon__core_1_1math_1_1domains_1_1Domain.md#function-bounds) () const<br>_Get the bounds of the domain as a pair._  |
|  const std::pair&lt; double, double &gt; | [**calculate\_transform**](classfalcon__core_1_1math_1_1domains_1_1Domain.md#function-calculate_transform) (const std::shared\_ptr&lt; Domain &gt; & other) const<br>_Calculate the linear transformation parameters to map this domain to another domain._  |
|  const bool | [**contains\_domain**](classfalcon__core_1_1math_1_1domains_1_1Domain.md#function-contains_domain) (const std::shared\_ptr&lt; Domain &gt; & other) const<br>_Check if this domain completely contains another domain._  |
|  const double | [**get\_center**](classfalcon__core_1_1math_1_1domains_1_1Domain.md#function-get_center) () const<br>_Get the center of the domain._  |
|  const double | [**greater\_bound**](classfalcon__core_1_1math_1_1domains_1_1Domain.md#function-greater_bound) () const<br>_Get the greater bound of the domain._  |
|  const bool | [**greater\_bound\_contained**](classfalcon__core_1_1math_1_1domains_1_1Domain.md#function-greater_bound_contained) () const<br>_Check if the greater bound is contained in the domain._  |
|  const bool | [**in**](classfalcon__core_1_1math_1_1domains_1_1Domain.md#function-in) (double value) const<br>_Check if a value is in the domain._  |
|  const bool | [**is\_empty**](classfalcon__core_1_1math_1_1domains_1_1Domain.md#function-is_empty) () const<br>_Check if the domain is empty._  |
|  const double | [**lesser\_bound**](classfalcon__core_1_1math_1_1domains_1_1Domain.md#function-lesser_bound) () const<br>_Get the lesser bound of the domain._  |
|  const bool | [**lesser\_bound\_contained**](classfalcon__core_1_1math_1_1domains_1_1Domain.md#function-lesser_bound_contained) () const<br>_Check if the lesser bound is contained in the domain._  |
|  bool | [**operator!=**](classfalcon__core_1_1math_1_1domains_1_1Domain.md#function-operator) (const Domain & other) const<br> |
|  const std::shared\_ptr&lt; Domain &gt; | [**operator&**](classfalcon__core_1_1math_1_1domains_1_1Domain.md#function-operator_1) (const std::shared\_ptr&lt; Domain &gt; & other) const<br>_Get the intersection of this domain with another domain._  |
|  Domain & | [**operator=**](classfalcon__core_1_1math_1_1domains_1_1Domain.md#function-operator_2) (const Domain & other) <br> |
|  bool | [**operator==**](classfalcon__core_1_1math_1_1domains_1_1Domain.md#function-operator_3) (const Domain & other) const<br> |
|  const std::shared\_ptr&lt; Domain &gt; | [**operator\|**](classfalcon__core_1_1math_1_1domains_1_1Domain.md#function-operator_4) (const std::shared\_ptr&lt; Domain &gt; & other) const<br>_Get the union of this domain with another domain._  |
|  const double | [**range**](classfalcon__core_1_1math_1_1domains_1_1Domain.md#function-range) () const<br>_Get the size of the domain._  |
|  const std::shared\_ptr&lt; Domain &gt; | [**scale**](classfalcon__core_1_1math_1_1domains_1_1Domain.md#function-scale) (double factor) const<br>_Scale the domain by a factor._  |
|  const std::shared\_ptr&lt; Domain &gt; | [**shift**](classfalcon__core_1_1math_1_1domains_1_1Domain.md#function-shift) (double offset) const<br>_Shift the domain by an offset._  |
|  const double | [**transform**](classfalcon__core_1_1math_1_1domains_1_1Domain.md#function-transform) (const std::shared\_ptr&lt; Domain &gt; & other, double value) const<br>_Transform a value from this domain to another domain._  |


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
|  const std::shared\_ptr&lt; LabelledDomain &gt; | [**from\_domain**](#function-from_domain) (const DomainSP & domain, const std::string & default\_name, const physics::device\_structures::ConnectionSP & pseudo\_name, const instrument\_interfaces::names::Instrument & instrument\_type, const physics::units::SymbolUnitSP & units=[**physics::units::SymbolUnit::Volt**](classfalcon__core_1_1physics_1_1units_1_1SymbolUnit.md#function-volt)(), const std::string & description="") <br>_Create a_ [_**LabelledDomain**_](classfalcon__core_1_1math_1_1domains_1_1LabelledDomain.md) _from an existing domain._ |
|  const std::shared\_ptr&lt; LabelledDomain &gt; | [**from\_port**](#function-from_port) (const std::pair&lt; double, double &gt; & bounds, const instrument\_interfaces::names::InstrumentPortSP & port, const bool & lesser\_bound\_contained=true, const bool & greater\_bound\_contained=true) <br>_Construct a labelled domain._  |
|  const std::shared\_ptr&lt; LabelledDomain &gt; | [**from\_port\_and\_domain**](#function-from_port_and_domain) (const instrument\_interfaces::names::InstrumentPortSP & port, const DomainSP & domain) <br>_Create a_ [_**LabelledDomain**_](classfalcon__core_1_1math_1_1domains_1_1LabelledDomain.md) _from an existing knob and domain._ |




## Public Static Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; T &gt; | [**from\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-from_json_string) (const std::string & json) <br>_Deserialize an object from a JSON string._  |






























































## Protected Functions

| Type | Name |
| ---: | :--- |
|   | [**LabelledDomain**](#function-labelleddomain-33) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |


## Protected Functions inherited from falcon_core::math::domains::Domain

See [falcon\_core::math::domains::Domain](classfalcon__core_1_1math_1_1domains_1_1Domain.md)

| Type | Name |
| ---: | :--- |
|   | [**Domain**](classfalcon__core_1_1math_1_1domains_1_1Domain.md#function-domain-44) () <br> |
|  void | [**serialize**](classfalcon__core_1_1math_1_1domains_1_1Domain.md#function-serialize) (Archive & ar) <br> |










## Public Functions Documentation




### function LabelledDomain [1/3]

```C++
falcon_core::math::domains::LabelledDomain::LabelledDomain (
    const LabelledDomain & other
) 
```




<hr>



### function LabelledDomain [2/3]

_Construct a labelled domain. @default\_name The default\_name for the instrument. @bounds The bounds on the domain. @psuedo\_name The name of the connection on the instrument if available. @instrument\_type The type of instrument connected to @lesser\_bound\_contained If the lesser\_bound is contained in the domain. @greater\_bound\_contained If the greater\_bound is contained in the domain. @units The units of the instrument. @description The description of the instrument._ 
```C++
falcon_core::math::domains::LabelledDomain::LabelledDomain (
    const std::string & default_name,
    const std::pair< double, double > & bounds,
    const physics::device_structures::ConnectionSP & psuedo_name,
    const instrument_interfaces::names::Instrument & instrument_type,
    bool lesser_bound_contained,
    bool greater_bound_contained,
    const physics::units::SymbolUnitSP & units,
    const std::string & description,
    const instrument_interfaces::names::PortType type=instrument_interfaces::names::PortType::Knob
) 
```




<hr>



### function domain 

_Gets the domain associated with the port._ 
```C++
std::shared_ptr< Domain > falcon_core::math::domains::LabelledDomain::domain () const
```




<hr>



### function matching\_port 

_Checks if the port matches the given port._ 
```C++
bool falcon_core::math::domains::LabelledDomain::matching_port (
    const instrument_interfaces::names::InstrumentPortSP & port
) const
```





**Parameters:**


* `port` The port to compare with. 



**Returns:**

True if the ports match, false otherwise. 





        

<hr>



### function operator!= 

```C++
bool falcon_core::math::domains::LabelledDomain::operator!= (
    const LabelledDomain & other
) const
```




<hr>



### function operator= 

```C++
LabelledDomain & falcon_core::math::domains::LabelledDomain::operator= (
    const LabelledDomain & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::math::domains::LabelledDomain::operator== (
    const LabelledDomain & other
) const
```




<hr>



### function port 

_Get the port._ 
```C++
const instrument_interfaces::names::InstrumentPortSP & falcon_core::math::domains::LabelledDomain::port () const
```





**Returns:**

Shared pointer to the port. 





        

<hr>
## Public Static Functions Documentation




### function from\_domain 

_Create a_ [_**LabelledDomain**_](classfalcon__core_1_1math_1_1domains_1_1LabelledDomain.md) _from an existing domain._
```C++
static const std::shared_ptr< LabelledDomain > falcon_core::math::domains::LabelledDomain::from_domain (
    const DomainSP & domain,
    const std::string & default_name,
    const physics::device_structures::ConnectionSP & pseudo_name,
    const instrument_interfaces::names::Instrument & instrument_type,
    const physics::units::SymbolUnitSP & units=physics::units::SymbolUnit::Volt (),
    const std::string & description=""
) 
```





**Parameters:**


* `domain` The domain to associate with the knob. 
* `default_name` The default name of the knob. 
* `pseudo_name` The optional colloquial name of the knob. 
* `instrument_type` The type of instrument the knob belongs to. 
* `units` the units of the knob's domain. 
* `description` A description of the knob. 



**Returns:**

A created [**LabelledDomain**](classfalcon__core_1_1math_1_1domains_1_1LabelledDomain.md). 





        

<hr>



### function from\_port 

_Construct a labelled domain._ 
```C++
static const std::shared_ptr< LabelledDomain > falcon_core::math::domains::LabelledDomain::from_port (
    const std::pair< double, double > & bounds,
    const instrument_interfaces::names::InstrumentPortSP & port,
    const bool & lesser_bound_contained=true,
    const bool & greater_bound_contained=true
) 
```





**Parameters:**


* `bounds` Minimum, Maximum pair of the domain. 
* `port` Shared pointer to the port. 




        

<hr>



### function from\_port\_and\_domain 

_Create a_ [_**LabelledDomain**_](classfalcon__core_1_1math_1_1domains_1_1LabelledDomain.md) _from an existing knob and domain._
```C++
static const std::shared_ptr< LabelledDomain > falcon_core::math::domains::LabelledDomain::from_port_and_domain (
    const instrument_interfaces::names::InstrumentPortSP & port,
    const DomainSP & domain
) 
```





**Parameters:**


* `knob` The knob to associate with the domain. 
* `domain` The domain to associate with the knob. 



**Returns:**

A created [**LabelledDomain**](classfalcon__core_1_1math_1_1domains_1_1LabelledDomain.md). 





        

<hr>
## Protected Functions Documentation




### function LabelledDomain [3/3]

```C++
falcon_core::math::domains::LabelledDomain::LabelledDomain () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::math::domains::LabelledDomain::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::math::domains::LabelledDomain::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/math/domains/LabelledDomain.hpp`

