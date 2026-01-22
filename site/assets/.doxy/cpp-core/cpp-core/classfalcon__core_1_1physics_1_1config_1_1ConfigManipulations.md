

# Class falcon\_core::physics::config::ConfigManipulations



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**physics**](namespacefalcon__core_1_1physics.md) **>** [**config**](namespacefalcon__core_1_1physics_1_1config.md) **>** [**ConfigManipulations**](classfalcon__core_1_1physics_1_1config_1_1ConfigManipulations.md)



_A utility class for manipulating and extracting information from device configurations._ 

* `#include <ConfigManipulations.hpp>`





Inherited by the following classes: [falcon\_core::physics::config::Loader](classfalcon__core_1_1physics_1_1config_1_1Loader.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**ConfigManipulations**](#function-configmanipulations) () <br> |
|  core::AdjacencySP | [**\_extract\_adjacency**](#function-_extract_adjacency) (const YAML::Node & map, const device\_structures::ConnectionsSP & total\_gates) const<br>_given the available gates loaded from the config, lets generate the adjacency matrix for this device._  |
|  device\_structures::ConnectionsSP | [**\_extract\_barrier\_gates**](#function-_extract_barrier_gates) (const std::string raw) const<br>_Extract the barrier gates from the compressed ";" delimited string._  |
|  device\_structures::ImpedancesSP | [**\_extract\_dcwiring**](#function-_extract_dcwiring) (const YAML::Node & map, const device\_structures::ConnectionsSP & ohmics, const core::StandardConfigConnectionsSP & connections) const<br>_Extracts a dcwiring from a config dictionary._  |
|  device\_structures::ConnectionsSP | [**\_extract\_ohmics**](#function-_extract_ohmics) (const std::string raw) const<br>_Extract the ohmics from the compressed ";" delimited string._  |
|  device\_structures::ConnectionsSP | [**\_extract\_order**](#function-_extract_order) (const std::string raw, const core::StandardConfigConnectionsSP & connections) const<br>_Extracts the order from the compressed ";" delimited string._  |
|  device\_structures::ConnectionsSP | [**\_extract\_plunger\_gates**](#function-_extract_plunger_gates) (const std::string raw) const<br>_Extract the plunger gates from the compressed ";" delimited string._  |
|  device\_structures::ConnectionsSP | [**\_extract\_reservoir\_gates**](#function-_extract_reservoir_gates) (const std::string raw) const<br>_Extract the reservoir gates from the compressed ";" delimited string._  |
|  device\_structures::ConnectionsSP | [**\_extract\_screening\_gates**](#function-_extract_screening_gates) (const std::string raw) const<br>_Extract the screening gates from the compressed ";" delimited string._  |
|  core::StandardConfigConnectionsSP | [**\_extract\_standard\_config\_connections**](#function-_extract_standard_config_connections) (const YAML::Node & config) const<br>_Extracts the standard connections from a config dictonary._  |
|  core::StandardConfigConnectionsSP | [**\_extract\_standard\_group\_config\_connections**](#function-_extract_standard_group_config_connections) (const YAML::Node & config) const<br>_Extracts the standard connections from a config dictonary._  |
|  core::VoltageConstraintsSP | [**\_extract\_voltage\_constraints**](#function-_extract_voltage_constraints) (const YAML::Node & map, const device\_structures::ConnectionsSP & total\_gates) const<br>_Given the available gates and the config lets produce a voltage constraints._  |
|  core::ConfigSP | [**unpack\_device\_config**](#function-unpack_device_config) (const YAML::Node & config) const<br>_Unpacks a mapping into a Config object._  |




























## Public Functions Documentation




### function ConfigManipulations 

```C++
falcon_core::physics::config::ConfigManipulations::ConfigManipulations () 
```




<hr>



### function \_extract\_adjacency 

_given the available gates loaded from the config, lets generate the adjacency matrix for this device._ 
```C++
core::AdjacencySP falcon_core::physics::config::ConfigManipulations::_extract_adjacency (
    const YAML::Node & map,
    const device_structures::ConnectionsSP & total_gates
) const
```




<hr>



### function \_extract\_barrier\_gates 

_Extract the barrier gates from the compressed ";" delimited string._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::ConfigManipulations::_extract_barrier_gates (
    const std::string raw
) const
```




<hr>



### function \_extract\_dcwiring 

_Extracts a dcwiring from a config dictionary._ 
```C++
device_structures::ImpedancesSP falcon_core::physics::config::ConfigManipulations::_extract_dcwiring (
    const YAML::Node & map,
    const device_structures::ConnectionsSP & ohmics,
    const core::StandardConfigConnectionsSP & connections
) const
```





**Parameters:**


* `dict` A mapping containing dcwiring details. 
* `ohmics` The list of ohmics in the device. 
* `connections` The configuration of the device connections. 



**Returns:**

An impedances object representing the dcwiring. 




**Exception:**


* `std::runtime_error` if the dcwiring extraction fails. 




        

<hr>



### function \_extract\_ohmics 

_Extract the ohmics from the compressed ";" delimited string._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::ConfigManipulations::_extract_ohmics (
    const std::string raw
) const
```




<hr>



### function \_extract\_order 

_Extracts the order from the compressed ";" delimited string._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::ConfigManipulations::_extract_order (
    const std::string raw,
    const core::StandardConfigConnectionsSP & connections
) const
```




<hr>



### function \_extract\_plunger\_gates 

_Extract the plunger gates from the compressed ";" delimited string._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::ConfigManipulations::_extract_plunger_gates (
    const std::string raw
) const
```




<hr>



### function \_extract\_reservoir\_gates 

_Extract the reservoir gates from the compressed ";" delimited string._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::ConfigManipulations::_extract_reservoir_gates (
    const std::string raw
) const
```




<hr>



### function \_extract\_screening\_gates 

_Extract the screening gates from the compressed ";" delimited string._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::ConfigManipulations::_extract_screening_gates (
    const std::string raw
) const
```




<hr>



### function \_extract\_standard\_config\_connections 

_Extracts the standard connections from a config dictonary._ 
```C++
core::StandardConfigConnectionsSP falcon_core::physics::config::ConfigManipulations::_extract_standard_config_connections (
    const YAML::Node & config
) const
```





**Parameters:**


* `config` The dictionary with keys that are gate types and values which are ";" delimtted strings of gates. 



**Returns:**

a collection of standard connections. 





        

<hr>



### function \_extract\_standard\_group\_config\_connections 

_Extracts the standard connections from a config dictonary._ 
```C++
core::StandardConfigConnectionsSP falcon_core::physics::config::ConfigManipulations::_extract_standard_group_config_connections (
    const YAML::Node & config
) const
```





**Parameters:**


* `config` The dictionary with keys that are gate types and values which are ";" delimtted strings of gates. This version does not include ohmics. 



**Returns:**

a collection of standard connections. 





        

<hr>



### function \_extract\_voltage\_constraints 

_Given the available gates and the config lets produce a voltage constraints._ 
```C++
core::VoltageConstraintsSP falcon_core::physics::config::ConfigManipulations::_extract_voltage_constraints (
    const YAML::Node & map,
    const device_structures::ConnectionsSP & total_gates
) const
```




<hr>



### function unpack\_device\_config 

_Unpacks a mapping into a Config object._ 
```C++
core::ConfigSP falcon_core::physics::config::ConfigManipulations::unpack_device_config (
    const YAML::Node & config
) const
```





**Parameters:**


* `config` A mapping containing configuration details. 



**Returns:**

A Config object populated with the provided details. 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/physics/config/ConfigManipulations.hpp`

