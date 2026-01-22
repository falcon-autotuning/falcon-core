

# Class falcon\_core::autotuner\_interfaces::interpretations::InterpretationContext



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**autotuner\_interfaces**](namespacefalcon__core_1_1autotuner__interfaces.md) **>** [**interpretations**](namespacefalcon__core_1_1autotuner__interfaces_1_1interpretations.md) **>** [**InterpretationContext**](classfalcon__core_1_1autotuner__interfaces_1_1interpretations_1_1InterpretationContext.md)



_A context that describes measurement variables._ [More...](#detailed-description)

* `#include <InterpretationContext.hpp>`



Inherits the following classes: [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**InterpretationContext**](#function-interpretationcontext-13) (const InterpretationContext & other) <br> |
|   | [**InterpretationContext**](#function-interpretationcontext-23) (const math::AxesSP&lt; [**autotuner\_interfaces::contexts::MeasurementContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1MeasurementContext.md) &gt; & independent\_variables, const generic::ListSP&lt; [**autotuner\_interfaces::contexts::MeasurementContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1MeasurementContext.md) &gt; & dependent\_variables, const physics::units::SymbolUnitSP & unit) <br>_Creates the_ [_**InterpretationContext**_](classfalcon__core_1_1autotuner__interfaces_1_1interpretations_1_1InterpretationContext.md) _._ |
|  void | [**add\_dependent\_variable**](#function-add_dependent_variable) (const autotuner\_interfaces::contexts::MeasurementContextSP & variable) <br>_Add a dependant variable to the measurement context._  |
|  const generic::ListSP&lt; [**autotuner\_interfaces::contexts::MeasurementContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1MeasurementContext.md) &gt; | [**dependent\_variables**](#function-dependent_variables) () const<br>_Return the dependent variables (measured parameters)._  |
|  const int | [**dimension**](#function-dimension) () const<br>_Return the dimensionality of the measurement (number of independent variables)._  |
|  const contexts::MeasurementContextSP | [**get\_independent\_variable**](#function-get_independent_variable) (int index) const<br>_Get an independant variable by index._  |
|  const math::AxesSP&lt; [**autotuner\_interfaces::contexts::MeasurementContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1MeasurementContext.md) &gt; | [**independent\_variables**](#function-independent_variables) () const<br>_Return the independent variables (sweep parameters)._  |
|  bool | [**operator!=**](#function-operator) (const InterpretationContext & other) const<br> |
|  InterpretationContext & | [**operator=**](#function-operator_1) (const InterpretationContext & other) <br> |
|  bool | [**operator==**](#function-operator_2) (const InterpretationContext & other) const<br> |
|  void | [**replace\_dependent\_variable**](#function-replace_dependent_variable) (int index, const autotuner\_interfaces::contexts::MeasurementContextSP & variable) <br>_Replace a dependent variable at the specified index._  |
|  const physics::units::SymbolUnitSP | [**unit**](#function-unit) () const<br>_Return the unit for interpreting the values._  |
|  const std::shared\_ptr&lt; InterpretationContext &gt; | [**with\_unit**](#function-with_unit) (physics::units::SymbolUnitSP unit) const<br>_Create a new interpretation context with the given unit._  |


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
|   | [**InterpretationContext**](#function-interpretationcontext-33) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |








## Detailed Description


Contains an Axes of MeasurementContext for independent variables (sweep parameters), a list of MeasurementContext for dependent variables (measured parameters), and a unit for interpreting the values. 


    
## Public Functions Documentation




### function InterpretationContext [1/3]

```C++
falcon_core::autotuner_interfaces::interpretations::InterpretationContext::InterpretationContext (
    const InterpretationContext & other
) 
```




<hr>



### function InterpretationContext [2/3]

_Creates the_ [_**InterpretationContext**_](classfalcon__core_1_1autotuner__interfaces_1_1interpretations_1_1InterpretationContext.md) _._
```C++
falcon_core::autotuner_interfaces::interpretations::InterpretationContext::InterpretationContext (
    const math::AxesSP< autotuner_interfaces::contexts::MeasurementContext > & independent_variables,
    const generic::ListSP< autotuner_interfaces::contexts::MeasurementContext > & dependent_variables,
    const physics::units::SymbolUnitSP & unit
) 
```





**Parameters:**


* `independent_variables` The independent variables (sweep parameters). 
* `depedant_variables` The dependent variables (measured parameters). 
* `unit` The unit for interpreting the values. 




        

<hr>



### function add\_dependent\_variable 

_Add a dependant variable to the measurement context._ 
```C++
void falcon_core::autotuner_interfaces::interpretations::InterpretationContext::add_dependent_variable (
    const autotuner_interfaces::contexts::MeasurementContextSP & variable
) 
```





**Parameters:**


* `variable` The dependent variable to add. 




        

<hr>



### function dependent\_variables 

_Return the dependent variables (measured parameters)._ 
```C++
const generic::ListSP< autotuner_interfaces::contexts::MeasurementContext > falcon_core::autotuner_interfaces::interpretations::InterpretationContext::dependent_variables () const
```




<hr>



### function dimension 

_Return the dimensionality of the measurement (number of independent variables)._ 
```C++
const int falcon_core::autotuner_interfaces::interpretations::InterpretationContext::dimension () const
```




<hr>



### function get\_independent\_variable 

_Get an independant variable by index._ 
```C++
const contexts::MeasurementContextSP falcon_core::autotuner_interfaces::interpretations::InterpretationContext::get_independent_variable (
    int index
) const
```





**Parameters:**


* `index` The count corresponding to the location of the variable to collect. 




        

<hr>



### function independent\_variables 

_Return the independent variables (sweep parameters)._ 
```C++
const math::AxesSP< autotuner_interfaces::contexts::MeasurementContext > falcon_core::autotuner_interfaces::interpretations::InterpretationContext::independent_variables () const
```




<hr>



### function operator!= 

```C++
bool falcon_core::autotuner_interfaces::interpretations::InterpretationContext::operator!= (
    const InterpretationContext & other
) const
```




<hr>



### function operator= 

```C++
InterpretationContext & falcon_core::autotuner_interfaces::interpretations::InterpretationContext::operator= (
    const InterpretationContext & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::autotuner_interfaces::interpretations::InterpretationContext::operator== (
    const InterpretationContext & other
) const
```




<hr>



### function replace\_dependent\_variable 

_Replace a dependent variable at the specified index._ 
```C++
void falcon_core::autotuner_interfaces::interpretations::InterpretationContext::replace_dependent_variable (
    int index,
    const autotuner_interfaces::contexts::MeasurementContextSP & variable
) 
```





**Parameters:**


* `index` The count corresponding to the location of the variable to replace. 
* `variable` The varaible that is to be stored at the location. 




        

<hr>



### function unit 

_Return the unit for interpreting the values._ 
```C++
const physics::units::SymbolUnitSP falcon_core::autotuner_interfaces::interpretations::InterpretationContext::unit () const
```




<hr>



### function with\_unit 

_Create a new interpretation context with the given unit._ 
```C++
const std::shared_ptr< InterpretationContext > falcon_core::autotuner_interfaces::interpretations::InterpretationContext::with_unit (
    physics::units::SymbolUnitSP unit
) const
```





**Parameters:**


* `unit` The physical unit to use 



**Returns:**

A new interpretation context with the same variables but a different unit. 





        

<hr>
## Protected Functions Documentation




### function InterpretationContext [3/3]

```C++
falcon_core::autotuner_interfaces::interpretations::InterpretationContext::InterpretationContext () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::autotuner_interfaces::interpretations::InterpretationContext::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::autotuner_interfaces::interpretations::InterpretationContext::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp`

