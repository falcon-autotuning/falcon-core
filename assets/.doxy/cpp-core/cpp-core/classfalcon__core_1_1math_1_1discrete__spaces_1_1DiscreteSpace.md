

# Class falcon\_core::math::discrete\_spaces::DiscreteSpace



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**math**](namespacefalcon__core_1_1math.md) **>** [**discrete\_spaces**](namespacefalcon__core_1_1math_1_1discrete__spaces.md) **>** [**DiscreteSpace**](classfalcon__core_1_1math_1_1discrete__spaces_1_1DiscreteSpace.md)








Inherits the following classes: [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**DiscreteSpace**](#function-discretespace-13) (const [**DiscreteSpace**](classfalcon__core_1_1math_1_1discrete__spaces_1_1DiscreteSpace.md) & other) <br> |
|   | [**DiscreteSpace**](#function-discretespace-23) (const UnitSpaceSP & space, const AxesSP&lt; [**domains::CoupledLabelledDomain**](classfalcon__core_1_1math_1_1domains_1_1CoupledLabelledDomain.md) &gt; & axes, const AxesSP&lt; [**generic::Map**](classfalcon__core_1_1generic_1_1Map.md)&lt; std::string, bool &gt; &gt; & increasing) <br>_Initialize the_ [_**DiscreteSpace**_](classfalcon__core_1_1math_1_1discrete__spaces_1_1DiscreteSpace.md) _. The order of the Knobs in teh axes are defined to line up with the space._ |
|  const AxesSP&lt; [**domains::CoupledLabelledDomain**](classfalcon__core_1_1math_1_1domains_1_1CoupledLabelledDomain.md) &gt; & | [**axes**](#function-axes) () const<br>_Return the stored axes._  |
|  const int | [**get\_axis**](#function-get_axis) (const instrument\_interfaces::names::InstrumentPortSP & knob) const<br>_Return the index of the axis containing the given knob._  |
|  const domains::DomainSP | [**get\_domain**](#function-get_domain) (const instrument\_interfaces::names::InstrumentPortSP & knob) const<br>_Return the domain of the given knob._  |
|  const AxesSP&lt; [**arrays::LabelledControlArray**](classfalcon__core_1_1math_1_1arrays_1_1LabelledControlArray.md) &gt; | [**get\_projection**](#function-get_projection) (const AxesSP&lt; [**instrument\_interfaces::names::InstrumentPort**](classfalcon__core_1_1instrument__interfaces_1_1names_1_1InstrumentPort.md) &gt; & projection) const<br>_Return the projection of the unit space onto the given axes._  |
|  const AxesSP&lt; [**generic::Map**](classfalcon__core_1_1generic_1_1Map.md)&lt; std::string, bool &gt; &gt; & | [**increasing**](#function-increasing) () const<br>_Return the increasing properties._  |
|  const instrument\_interfaces::names::PortsSP | [**knobs**](#function-knobs) () const<br>_Return the knobs._  |
|  bool | [**operator!=**](#function-operator) (const [**DiscreteSpace**](classfalcon__core_1_1math_1_1discrete__spaces_1_1DiscreteSpace.md) & other) const<br> |
|  [**DiscreteSpace**](classfalcon__core_1_1math_1_1discrete__spaces_1_1DiscreteSpace.md) & | [**operator=**](#function-operator_1) (const [**DiscreteSpace**](classfalcon__core_1_1math_1_1discrete__spaces_1_1DiscreteSpace.md) & other) <br> |
|  bool | [**operator==**](#function-operator_2) (const [**DiscreteSpace**](classfalcon__core_1_1math_1_1discrete__spaces_1_1DiscreteSpace.md) & other) const<br> |
|  const UnitSpaceSP & | [**space**](#function-space) () const<br>_Return the stored_ [_**UnitSpace**_](classfalcon__core_1_1math_1_1UnitSpace.md) _._ |
|  void | [**validate\_knob\_uniqueness**](#function-validate_knob_uniqueness) () const<br>_Validate that the knobs are unique._  |
|  void | [**validate\_unit\_space\_dimensionality\_matches\_knobs**](#function-validate_unit_space_dimensionality_matches_knobs) () const<br>_Validate that the unit space dimensionality matches the number of knobs._  |


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
|  std::shared\_ptr&lt; [**DiscreteSpace**](classfalcon__core_1_1math_1_1discrete__spaces_1_1DiscreteSpace.md) &gt; | [**CartesianDiscreteSpace**](#function-cartesiandiscretespace) (const AxesSP&lt; int &gt; & divisions, const AxesSP&lt; [**domains::CoupledLabelledDomain**](classfalcon__core_1_1math_1_1domains_1_1CoupledLabelledDomain.md) &gt; & axes, const AxesSP&lt; [**generic::Map**](classfalcon__core_1_1generic_1_1Map.md)&lt; std::string, bool &gt; &gt; & increasing, const domains::DomainSP & domain=std::make\_shared&lt; [**domains::Domain**](classfalcon__core_1_1math_1_1domains_1_1Domain.md) &gt;(std::pair&lt; double, double &gt;(0, 1))) <br>_Create a ND cartesian discrete space._  |
|  std::shared\_ptr&lt; [**DiscreteSpace**](classfalcon__core_1_1math_1_1discrete__spaces_1_1DiscreteSpace.md) &gt; | [**CartesianDiscreteSpace1D**](#function-cartesiandiscretespace1d) (const int & division, const domains::CoupledLabelledDomainSP & shared\_domain, const generic::MapSP&lt; std::string, bool &gt; & increasing, const domains::DomainSP & domain=std::make\_shared&lt; [**domains::Domain**](classfalcon__core_1_1math_1_1domains_1_1Domain.md) &gt;(std::pair&lt; double, double &gt;(0, 1))) <br>_Create a ND cartesian discrete space._  |


## Public Static Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; T &gt; | [**from\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-from_json_string) (const std::string & json) <br>_Deserialize an object from a JSON string._  |










































## Protected Functions

| Type | Name |
| ---: | :--- |
|   | [**DiscreteSpace**](#function-discretespace-33) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |








## Public Functions Documentation




### function DiscreteSpace [1/3]

```C++
falcon_core::math::discrete_spaces::DiscreteSpace::DiscreteSpace (
    const DiscreteSpace & other
) 
```




<hr>



### function DiscreteSpace [2/3]

_Initialize the_ [_**DiscreteSpace**_](classfalcon__core_1_1math_1_1discrete__spaces_1_1DiscreteSpace.md) _. The order of the Knobs in teh axes are defined to line up with the space._
```C++
falcon_core::math::discrete_spaces::DiscreteSpace::DiscreteSpace (
    const UnitSpaceSP & space,
    const AxesSP< domains::CoupledLabelledDomain > & axes,
    const AxesSP< generic::Map < std::string, bool > > & increasing
) 
```





**Parameters:**


* `space` the space taht the decirete values fill 
* `axes` the axes containing the discrete values. 
* `increasing` True if the axes are decreasing with the direction of the domain or against. 




        

<hr>



### function axes 

_Return the stored axes._ 
```C++
const AxesSP< domains::CoupledLabelledDomain > & falcon_core::math::discrete_spaces::DiscreteSpace::axes () const
```




<hr>



### function get\_axis 

_Return the index of the axis containing the given knob._ 
```C++
const int falcon_core::math::discrete_spaces::DiscreteSpace::get_axis (
    const instrument_interfaces::names::InstrumentPortSP & knob
) const
```





**Parameters:**


* `knob` The knob to search for. 



**Returns:**

The index of the axis containing the knob. 




**Exception:**


* `std::runtime_error` if the knob is not found. 




        

<hr>



### function get\_domain 

_Return the domain of the given knob._ 
```C++
const domains::DomainSP falcon_core::math::discrete_spaces::DiscreteSpace::get_domain (
    const instrument_interfaces::names::InstrumentPortSP & knob
) const
```





**Parameters:**


* `knob` The knob to search for. 



**Returns:**

The domain of the knob. 





        

<hr>



### function get\_projection 

_Return the projection of the unit space onto the given axes._ 
```C++
const AxesSP< arrays::LabelledControlArray > falcon_core::math::discrete_spaces::DiscreteSpace::get_projection (
    const AxesSP< instrument_interfaces::names::InstrumentPort > & projection
) const
```





**Parameters:**


* `projection` The axes to project onto. 



**Returns:**

The projection of th espace onto the given axes. 





        

<hr>



### function increasing 

_Return the increasing properties._ 
```C++
const AxesSP< generic::Map < std::string, bool > > & falcon_core::math::discrete_spaces::DiscreteSpace::increasing () const
```




<hr>



### function knobs 

_Return the knobs._ 
```C++
const instrument_interfaces::names::PortsSP falcon_core::math::discrete_spaces::DiscreteSpace::knobs () const
```




<hr>



### function operator!= 

```C++
bool falcon_core::math::discrete_spaces::DiscreteSpace::operator!= (
    const DiscreteSpace & other
) const
```




<hr>



### function operator= 

```C++
DiscreteSpace & falcon_core::math::discrete_spaces::DiscreteSpace::operator= (
    const DiscreteSpace & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::math::discrete_spaces::DiscreteSpace::operator== (
    const DiscreteSpace & other
) const
```




<hr>



### function space 

_Return the stored_ [_**UnitSpace**_](classfalcon__core_1_1math_1_1UnitSpace.md) _._
```C++
const UnitSpaceSP & falcon_core::math::discrete_spaces::DiscreteSpace::space () const
```




<hr>



### function validate\_knob\_uniqueness 

_Validate that the knobs are unique._ 
```C++
void falcon_core::math::discrete_spaces::DiscreteSpace::validate_knob_uniqueness () const
```




<hr>



### function validate\_unit\_space\_dimensionality\_matches\_knobs 

_Validate that the unit space dimensionality matches the number of knobs._ 
```C++
void falcon_core::math::discrete_spaces::DiscreteSpace::validate_unit_space_dimensionality_matches_knobs () const
```




<hr>
## Public Static Functions Documentation




### function CartesianDiscreteSpace 

_Create a ND cartesian discrete space._ 
```C++
static std::shared_ptr< DiscreteSpace > falcon_core::math::discrete_spaces::DiscreteSpace::CartesianDiscreteSpace (
    const AxesSP< int > & divisions,
    const AxesSP< domains::CoupledLabelledDomain > & axes,
    const AxesSP< generic::Map < std::string, bool > > & increasing,
    const domains::DomainSP & domain=std::make_shared< domains::Domain >(std::pair< double, double >(0, 1))
) 
```





**Parameters:**


* `divisions` the number of divisions for each axis. 
* `axes` the domains for each axis. 
* `increasing` if each dimension is increasing with time or not. 
* `domain` the domain of the space. 




        

<hr>



### function CartesianDiscreteSpace1D 

_Create a ND cartesian discrete space._ 
```C++
static std::shared_ptr< DiscreteSpace > falcon_core::math::discrete_spaces::DiscreteSpace::CartesianDiscreteSpace1D (
    const int & division,
    const domains::CoupledLabelledDomainSP & shared_domain,
    const generic::MapSP< std::string, bool > & increasing,
    const domains::DomainSP & domain=std::make_shared< domains::Domain >(std::pair< double, double >(0, 1))
) 
```





**Parameters:**


* `divisions` the number of divisions for each axis. 
* `axes` the domains for each axis. 
* `increasing` if each dimension is increasing with time or not. 
* `domain` the domain of the space. 




        

<hr>
## Protected Functions Documentation




### function DiscreteSpace [3/3]

```C++
falcon_core::math::discrete_spaces::DiscreteSpace::DiscreteSpace () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::math::discrete_spaces::DiscreteSpace::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::math::discrete_spaces::DiscreteSpace::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/math/discrete_spaces/DiscreteSpace.hpp`

