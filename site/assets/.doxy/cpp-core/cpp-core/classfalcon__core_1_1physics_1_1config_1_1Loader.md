

# Class falcon\_core::physics::config::Loader



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**physics**](namespacefalcon__core_1_1physics.md) **>** [**config**](namespacefalcon__core_1_1physics_1_1config.md) **>** [**Loader**](classfalcon__core_1_1physics_1_1config_1_1Loader.md)








Inherits the following classes: [falcon\_core::physics::config::ConfigManipulations](classfalcon__core_1_1physics_1_1config_1_1ConfigManipulations.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Loader**](#function-loader-13) (const Loader & other) <br> |
|   | [**Loader**](#function-loader-23) (const boost::filesystem::path & config\_path) <br>_Constructor for config loading utility._  |
|   | [**Loader**](#function-loader-33) (const std::string config\_path) <br>_Constructor for config loading utility._  |
|  core::ConfigSP | [**\_load\_config**](#function-_load_config) () <br>_Loads the config file into nodes._  |
|  core::ConfigSP | [**config**](#function-config) () const<br>_Returns the config._  |
|  Loader & | [**operator=**](#function-operator) (const Loader & other) <br> |


## Public Functions inherited from falcon_core::physics::config::ConfigManipulations

See [falcon\_core::physics::config::ConfigManipulations](classfalcon__core_1_1physics_1_1config_1_1ConfigManipulations.md)

| Type | Name |
| ---: | :--- |
|   | [**ConfigManipulations**](classfalcon__core_1_1physics_1_1config_1_1ConfigManipulations.md#function-configmanipulations) () <br> |
|  core::AdjacencySP | [**\_extract\_adjacency**](classfalcon__core_1_1physics_1_1config_1_1ConfigManipulations.md#function-_extract_adjacency) (const YAML::Node & map, const device\_structures::ConnectionsSP & total\_gates) const<br>_given the available gates loaded from the config, lets generate the adjacency matrix for this device._  |
|  device\_structures::ConnectionsSP | [**\_extract\_barrier\_gates**](classfalcon__core_1_1physics_1_1config_1_1ConfigManipulations.md#function-_extract_barrier_gates) (const std::string raw) const<br>_Extract the barrier gates from the compressed ";" delimited string._  |
|  device\_structures::ImpedancesSP | [**\_extract\_dcwiring**](classfalcon__core_1_1physics_1_1config_1_1ConfigManipulations.md#function-_extract_dcwiring) (const YAML::Node & map, const device\_structures::ConnectionsSP & ohmics, const core::StandardConfigConnectionsSP & connections) const<br>_Extracts a dcwiring from a config dictionary._  |
|  device\_structures::ConnectionsSP | [**\_extract\_ohmics**](classfalcon__core_1_1physics_1_1config_1_1ConfigManipulations.md#function-_extract_ohmics) (const std::string raw) const<br>_Extract the ohmics from the compressed ";" delimited string._  |
|  device\_structures::ConnectionsSP | [**\_extract\_order**](classfalcon__core_1_1physics_1_1config_1_1ConfigManipulations.md#function-_extract_order) (const std::string raw, const core::StandardConfigConnectionsSP & connections) const<br>_Extracts the order from the compressed ";" delimited string._  |
|  device\_structures::ConnectionsSP | [**\_extract\_plunger\_gates**](classfalcon__core_1_1physics_1_1config_1_1ConfigManipulations.md#function-_extract_plunger_gates) (const std::string raw) const<br>_Extract the plunger gates from the compressed ";" delimited string._  |
|  device\_structures::ConnectionsSP | [**\_extract\_reservoir\_gates**](classfalcon__core_1_1physics_1_1config_1_1ConfigManipulations.md#function-_extract_reservoir_gates) (const std::string raw) const<br>_Extract the reservoir gates from the compressed ";" delimited string._  |
|  device\_structures::ConnectionsSP | [**\_extract\_screening\_gates**](classfalcon__core_1_1physics_1_1config_1_1ConfigManipulations.md#function-_extract_screening_gates) (const std::string raw) const<br>_Extract the screening gates from the compressed ";" delimited string._  |
|  core::StandardConfigConnectionsSP | [**\_extract\_standard\_config\_connections**](classfalcon__core_1_1physics_1_1config_1_1ConfigManipulations.md#function-_extract_standard_config_connections) (const YAML::Node & config) const<br>_Extracts the standard connections from a config dictonary._  |
|  core::StandardConfigConnectionsSP | [**\_extract\_standard\_group\_config\_connections**](classfalcon__core_1_1physics_1_1config_1_1ConfigManipulations.md#function-_extract_standard_group_config_connections) (const YAML::Node & config) const<br>_Extracts the standard connections from a config dictonary._  |
|  core::VoltageConstraintsSP | [**\_extract\_voltage\_constraints**](classfalcon__core_1_1physics_1_1config_1_1ConfigManipulations.md#function-_extract_voltage_constraints) (const YAML::Node & map, const device\_structures::ConnectionsSP & total\_gates) const<br>_Given the available gates and the config lets produce a voltage constraints._  |
|  core::ConfigSP | [**unpack\_device\_config**](classfalcon__core_1_1physics_1_1config_1_1ConfigManipulations.md#function-unpack_device_config) (const YAML::Node & config) const<br>_Unpacks a mapping into a Config object._  |






















































## Public Functions Documentation




### function Loader [1/3]

```C++
falcon_core::physics::config::Loader::Loader (
    const Loader & other
) 
```




<hr>



### function Loader [2/3]

_Constructor for config loading utility._ 
```C++
falcon_core::physics::config::Loader::Loader (
    const boost::filesystem::path & config_path
) 
```





**Parameters:**


* `config_path` Path to the configuration file. 




        

<hr>



### function Loader [3/3]

_Constructor for config loading utility._ 
```C++
falcon_core::physics::config::Loader::Loader (
    const std::string config_path
) 
```





**Parameters:**


* `config_path` Complete Path to the configuration file. 




        

<hr>



### function \_load\_config 

_Loads the config file into nodes._ 
```C++
core::ConfigSP falcon_core::physics::config::Loader::_load_config () 
```




<hr>



### function config 

_Returns the config._ 
```C++
core::ConfigSP falcon_core::physics::config::Loader::config () const
```




<hr>



### function operator= 

```C++
Loader & falcon_core::physics::config::Loader::operator= (
    const Loader & other
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/physics/config/Loader.hpp`

