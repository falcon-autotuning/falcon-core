

# Namespace falcon\_core::physics::config::core



[**Namespace List**](namespaces.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**physics**](namespacefalcon__core_1_1physics.md) **>** [**config**](namespacefalcon__core_1_1physics_1_1config.md) **>** [**core**](namespacefalcon__core_1_1physics_1_1config_1_1core.md)




















## Classes

| Type | Name |
| ---: | :--- |
| class | [**Adjacency**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Adjacency.md) <br>_This a graph representation of the connections between gates in a quantum dot device._  |
| class | [**Config**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Config.md) <br>_The imported config file for falcon use._  |
| class | [**Group**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Group.md) <br>_Elements of the config that pertain to an individual group of gates._  |
| class | [**StandardConfigConnections**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md) <br>_Base config functionality for core config classes._  |
| class | [**VoltageConstraints**](classfalcon__core_1_1physics_1_1config_1_1core_1_1VoltageConstraints.md) <br>_Contains a ready to use voltage constrains matrix and matching limits for each constraint._  |


## Public Types

| Type | Name |
| ---: | :--- |
| typedef std::shared\_ptr&lt; [**Adjacency**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Adjacency.md) &gt; | [**AdjacencySP**](#typedef-adjacencysp)  <br> |
| typedef std::shared\_ptr&lt; [**Config**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Config.md) &gt; | [**ConfigSP**](#typedef-configsp)  <br> |
| typedef std::shared\_ptr&lt; [**Group**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Group.md) &gt; | [**GroupSP**](#typedef-groupsp)  <br> |
| typedef std::shared\_ptr&lt; [**StandardConfigConnections**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md) &gt; | [**StandardConfigConnectionsSP**](#typedef-standardconfigconnectionssp)  <br> |
| typedef std::shared\_ptr&lt; [**VoltageConstraints**](classfalcon__core_1_1physics_1_1config_1_1core_1_1VoltageConstraints.md) &gt; | [**VoltageConstraintsSP**](#typedef-voltageconstraintssp)  <br> |
















































## Public Types Documentation




### typedef AdjacencySP 

```C++
using falcon_core::physics::config::core::AdjacencySP = typedef std::shared_ptr<Adjacency>;
```




<hr>



### typedef ConfigSP 

```C++
using falcon_core::physics::config::core::ConfigSP = typedef std::shared_ptr<Config>;
```




<hr>



### typedef GroupSP 

```C++
using falcon_core::physics::config::core::GroupSP = typedef std::shared_ptr<Group>;
```




<hr>



### typedef StandardConfigConnectionsSP 

```C++
using falcon_core::physics::config::core::StandardConfigConnectionsSP = typedef std::shared_ptr<StandardConfigConnections>;
```




<hr>



### typedef VoltageConstraintsSP 

```C++
using falcon_core::physics::config::core::VoltageConstraintsSP = typedef std::shared_ptr<VoltageConstraints>;
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/physics/config/core/Adjacency.hpp`

