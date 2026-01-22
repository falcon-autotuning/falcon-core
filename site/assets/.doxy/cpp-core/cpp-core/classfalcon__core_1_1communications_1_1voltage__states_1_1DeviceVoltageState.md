

# Class falcon\_core::communications::voltage\_states::DeviceVoltageState



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**communications**](namespacefalcon__core_1_1communications.md) **>** [**voltage\_states**](namespacefalcon__core_1_1communications_1_1voltage__states.md) **>** [**DeviceVoltageState**](classfalcon__core_1_1communications_1_1voltage__states_1_1DeviceVoltageState.md)








Inherits the following classes: [falcon\_core::math::Quantity](classfalcon__core_1_1math_1_1Quantity.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**DeviceVoltageState**](#function-devicevoltagestate-13) (const DeviceVoltageState & other) <br> |
|   | [**DeviceVoltageState**](#function-devicevoltagestate-23) (const physics::device\_structures::ConnectionSP & connection, const double & voltage, const physics::units::SymbolUnitSP & unit) <br> |
|  const physics::device\_structures::ConnectionSP & | [**connection**](#function-connection) () const<br> |
|  bool | [**operator!=**](#function-operator) (const DeviceVoltageState & other) const<br> |
|  DeviceVoltageState & | [**operator=**](#function-operator_1) (const DeviceVoltageState & other) <br> |
|  bool | [**operator==**](#function-operator_2) (const DeviceVoltageState & other) const<br> |
|  double | [**voltage**](#function-voltage) () const<br> |


## Public Functions inherited from falcon_core::math::Quantity

See [falcon\_core::math::Quantity](classfalcon__core_1_1math_1_1Quantity.md)

| Type | Name |
| ---: | :--- |
|   | [**Quantity**](classfalcon__core_1_1math_1_1Quantity.md#function-quantity-13) (const Quantity & other) <br> |
|   | [**Quantity**](classfalcon__core_1_1math_1_1Quantity.md#function-quantity-23) (double value, physics::units::SymbolUnitSP unit=[**physics::units::SymbolUnit::Volt**](classfalcon__core_1_1physics_1_1units_1_1SymbolUnit.md#function-volt)()) <br>_Initialize a_ [_**Quantity**_](classfalcon__core_1_1math_1_1Quantity.md) _, which is a float with a unit._ |
|  std::shared\_ptr&lt; Quantity &gt; | [**abs**](classfalcon__core_1_1math_1_1Quantity.md#function-abs) () const<br> |
|  void | [**convert\_to**](classfalcon__core_1_1math_1_1Quantity.md#function-convert_to) (physics::units::SymbolUnitSP target\_unit) <br>_Convert the quantity to a different unit._  |
|  bool | [**operator!=**](classfalcon__core_1_1math_1_1Quantity.md#function-operator) (const Quantity & other) const<br> |
|  std::shared\_ptr&lt; Quantity &gt; | [**operator\***](classfalcon__core_1_1math_1_1Quantity.md#function-operator_1) (const int & other) const<br> |
|  std::shared\_ptr&lt; Quantity &gt; | [**operator\***](classfalcon__core_1_1math_1_1Quantity.md#function-operator_2) (const double & other) const<br> |
|  std::shared\_ptr&lt; Quantity &gt; | [**operator\***](classfalcon__core_1_1math_1_1Quantity.md#function-operator_3) (const std::shared\_ptr&lt; Quantity &gt; & other) const<br> |
|  Quantity & | [**operator\*=**](classfalcon__core_1_1math_1_1Quantity.md#function-operator_4) (const int & other) <br> |
|  Quantity & | [**operator\*=**](classfalcon__core_1_1math_1_1Quantity.md#function-operator_5) (const double & other) <br> |
|  Quantity & | [**operator\*=**](classfalcon__core_1_1math_1_1Quantity.md#function-operator_6) (const std::shared\_ptr&lt; Quantity &gt; & other) <br> |
|  std::shared\_ptr&lt; Quantity &gt; | [**operator+**](classfalcon__core_1_1math_1_1Quantity.md#function-operator_7) (const int & other) const<br> |
|  std::shared\_ptr&lt; Quantity &gt; | [**operator+**](classfalcon__core_1_1math_1_1Quantity.md#function-operator_8) (const double & other) const<br> |
|  std::shared\_ptr&lt; Quantity &gt; | [**operator+**](classfalcon__core_1_1math_1_1Quantity.md#function-operator_9) (const std::shared\_ptr&lt; Quantity &gt; & other) const<br> |
|  Quantity & | [**operator+=**](classfalcon__core_1_1math_1_1Quantity.md#function-operator_10) (const int & other) <br> |
|  Quantity & | [**operator+=**](classfalcon__core_1_1math_1_1Quantity.md#function-operator_11) (const double & other) <br> |
|  Quantity & | [**operator+=**](classfalcon__core_1_1math_1_1Quantity.md#function-operator_12) (const std::shared\_ptr&lt; Quantity &gt; & other) <br> |
|  std::shared\_ptr&lt; Quantity &gt; | [**operator-**](classfalcon__core_1_1math_1_1Quantity.md#function-operator-) () const<br> |
|  std::shared\_ptr&lt; Quantity &gt; | [**operator-**](classfalcon__core_1_1math_1_1Quantity.md#function-operator-_1) (const int & other) const<br> |
|  std::shared\_ptr&lt; Quantity &gt; | [**operator-**](classfalcon__core_1_1math_1_1Quantity.md#function-operator-_2) (const double & other) const<br> |
|  std::shared\_ptr&lt; Quantity &gt; | [**operator-**](classfalcon__core_1_1math_1_1Quantity.md#function-operator-_3) (const std::shared\_ptr&lt; Quantity &gt; & other) const<br> |
|  Quantity & | [**operator-=**](classfalcon__core_1_1math_1_1Quantity.md#function-operator-_4) (const int & other) <br> |
|  Quantity & | [**operator-=**](classfalcon__core_1_1math_1_1Quantity.md#function-operator-_5) (const double & other) <br> |
|  Quantity & | [**operator-=**](classfalcon__core_1_1math_1_1Quantity.md#function-operator-_6) (const std::shared\_ptr&lt; Quantity &gt; & other) <br> |
|  std::shared\_ptr&lt; Quantity &gt; | [**operator/**](classfalcon__core_1_1math_1_1Quantity.md#function-operator_13) (const int & other) const<br> |
|  std::shared\_ptr&lt; Quantity &gt; | [**operator/**](classfalcon__core_1_1math_1_1Quantity.md#function-operator_14) (const double & other) const<br> |
|  std::shared\_ptr&lt; Quantity &gt; | [**operator/**](classfalcon__core_1_1math_1_1Quantity.md#function-operator_15) (const std::shared\_ptr&lt; Quantity &gt; & other) const<br> |
|  Quantity & | [**operator/=**](classfalcon__core_1_1math_1_1Quantity.md#function-operator_16) (const int & other) <br> |
|  Quantity & | [**operator/=**](classfalcon__core_1_1math_1_1Quantity.md#function-operator_17) (const double & other) <br> |
|  Quantity & | [**operator/=**](classfalcon__core_1_1math_1_1Quantity.md#function-operator_18) (const std::shared\_ptr&lt; Quantity &gt; & other) <br> |
|  Quantity & | [**operator=**](classfalcon__core_1_1math_1_1Quantity.md#function-operator_19) (const Quantity & other) <br> |
|  bool | [**operator==**](classfalcon__core_1_1math_1_1Quantity.md#function-operator_20) (const Quantity & other) const<br> |
|  std::shared\_ptr&lt; Quantity &gt; | [**operator^**](classfalcon__core_1_1math_1_1Quantity.md#function-operator_21) (const int & other) const<br> |
|  physics::units::SymbolUnitSP | [**unit**](classfalcon__core_1_1math_1_1Quantity.md#function-unit) () const<br>_Return the unit of the quantity._  |
|  double | [**value**](classfalcon__core_1_1math_1_1Quantity.md#function-value) () const<br>_Return the value of the quantity._  |


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
|   | [**DeviceVoltageState**](#function-devicevoltagestate-33) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |


## Protected Functions inherited from falcon_core::math::Quantity

See [falcon\_core::math::Quantity](classfalcon__core_1_1math_1_1Quantity.md)

| Type | Name |
| ---: | :--- |
|   | [**Quantity**](classfalcon__core_1_1math_1_1Quantity.md#function-quantity-33) () <br> |
|  void | [**serialize**](classfalcon__core_1_1math_1_1Quantity.md#function-serialize) (Archive & ar) <br> |










## Public Functions Documentation




### function DeviceVoltageState [1/3]

```C++
falcon_core::communications::voltage_states::DeviceVoltageState::DeviceVoltageState (
    const DeviceVoltageState & other
) 
```




<hr>



### function DeviceVoltageState [2/3]

```C++
falcon_core::communications::voltage_states::DeviceVoltageState::DeviceVoltageState (
    const physics::device_structures::ConnectionSP & connection,
    const double & voltage,
    const physics::units::SymbolUnitSP & unit
) 
```




<hr>



### function connection 

```C++
const physics::device_structures::ConnectionSP & falcon_core::communications::voltage_states::DeviceVoltageState::connection () const
```




<hr>



### function operator!= 

```C++
bool falcon_core::communications::voltage_states::DeviceVoltageState::operator!= (
    const DeviceVoltageState & other
) const
```




<hr>



### function operator= 

```C++
DeviceVoltageState & falcon_core::communications::voltage_states::DeviceVoltageState::operator= (
    const DeviceVoltageState & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::communications::voltage_states::DeviceVoltageState::operator== (
    const DeviceVoltageState & other
) const
```




<hr>



### function voltage 

```C++
double falcon_core::communications::voltage_states::DeviceVoltageState::voltage () const
```




<hr>
## Protected Functions Documentation




### function DeviceVoltageState [3/3]

```C++
falcon_core::communications::voltage_states::DeviceVoltageState::DeviceVoltageState () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::communications::voltage_states::DeviceVoltageState::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::communications::voltage_states::DeviceVoltageState::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/communications/voltage_states/DeviceVoltageState.hpp`

