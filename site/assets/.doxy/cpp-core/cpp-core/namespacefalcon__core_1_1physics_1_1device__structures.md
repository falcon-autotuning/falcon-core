

# Namespace falcon\_core::physics::device\_structures



[**Namespace List**](namespaces.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**physics**](namespacefalcon__core_1_1physics.md) **>** [**device\_structures**](namespacefalcon__core_1_1physics_1_1device__structures.md)




















## Classes

| Type | Name |
| ---: | :--- |
| class | [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md) <br> |
| class | [**Connections**](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) <br>_A serializable vector of_ [_**Connection**_](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md) _pointers, also a Song._ |
| class | [**GateRelations**](classfalcon__core_1_1physics_1_1device__structures_1_1GateRelations.md) <br>_Holds the relations between gates and their neighbors._  |
| class | [**Impedance**](classfalcon__core_1_1physics_1_1device__structures_1_1Impedance.md) <br> |
| class | [**Impedances**](classfalcon__core_1_1physics_1_1device__structures_1_1Impedances.md) <br>_A collection of_ [_**Impedances**_](classfalcon__core_1_1physics_1_1device__structures_1_1Impedances.md) _._ |


## Public Types

| Type | Name |
| ---: | :--- |
| typedef std::shared\_ptr&lt; [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md) &gt; | [**ConnectionSP**](#typedef-connectionsp)  <br> |
| typedef std::shared\_ptr&lt; [**Connections**](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) &gt; | [**ConnectionsSP**](#typedef-connectionssp)  <br> |
| enum  | [**DeviceFeature**](#enum-devicefeature)  <br> |
| typedef std::shared\_ptr&lt; [**GateRelations**](classfalcon__core_1_1physics_1_1device__structures_1_1GateRelations.md) &gt; | [**GateRelationsSP**](#typedef-gaterelationssp)  <br> |
| typedef std::shared\_ptr&lt; [**Impedance**](classfalcon__core_1_1physics_1_1device__structures_1_1Impedance.md) &gt; | [**ImpedanceSP**](#typedef-impedancesp)  <br> |
| typedef std::shared\_ptr&lt; [**Impedances**](classfalcon__core_1_1physics_1_1device__structures_1_1Impedances.md) &gt; | [**ImpedancesSP**](#typedef-impedancessp)  <br> |






## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  const std::map&lt; DeviceFeature, std::string &gt; | [**DeviceFeatureNames**](#variable-devicefeaturenames)   = `/* multi line expression */`<br> |










































## Public Types Documentation




### typedef ConnectionSP 

```C++
using falcon_core::physics::device_structures::ConnectionSP =  std::shared_ptr<Connection>;
```




<hr>



### typedef ConnectionsSP 

```C++
using falcon_core::physics::device_structures::ConnectionsSP =  std::shared_ptr<Connections>;
```




<hr>



### enum DeviceFeature 

```C++
enum falcon_core::physics::device_structures::DeviceFeature {
    BarrierGate,
    PlungerGate,
    ReservoirGate,
    ScreeningGate,
    Ohmic
};
```




<hr>



### typedef GateRelationsSP 

```C++
using falcon_core::physics::device_structures::GateRelationsSP =  std::shared_ptr<GateRelations>;
```




<hr>



### typedef ImpedanceSP 

```C++
using falcon_core::physics::device_structures::ImpedanceSP =  std::shared_ptr<Impedance>;
```




<hr>



### typedef ImpedancesSP 

```C++
using falcon_core::physics::device_structures::ImpedancesSP =  std::shared_ptr<Impedances>;
```




<hr>
## Public Static Attributes Documentation




### variable DeviceFeatureNames 

```C++
const std::map<DeviceFeature, std::string> falcon_core::physics::device_structures::DeviceFeatureNames;
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/physics/device_structures/Connection.hpp`

