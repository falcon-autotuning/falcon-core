

# Namespace falcon\_core::physics::config::geometries



[**Namespace List**](namespaces.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**physics**](namespacefalcon__core_1_1physics.md) **>** [**config**](namespacefalcon__core_1_1physics_1_1config.md) **>** [**geometries**](namespacefalcon__core_1_1physics_1_1config_1_1geometries.md)




















## Classes

| Type | Name |
| ---: | :--- |
| class | [**DotGateWithNeighbors**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1DotGateWithNeighbors.md) <br> |
| class | [**DotGatesWithNeighbors**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1DotGatesWithNeighbors.md) <br>_A serializable vector of_ [_**DotGateWithNeighbors**_](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1DotGateWithNeighbors.md) _pointers, also a Song._ |
| class | [**GateGeometryArray1D**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1GateGeometryArray1D.md) <br>_A 1D array of quantum dots with left and right reservoirs, barrier gates, plunger gates, ohmics, and screening gates. This contains the geometry of the 1D array._  |
| class | [**HasImplantedOhmic**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasImplantedOhmic.md) <br>_A gate with an ohmic below it._  |
| class | [**HasLeftNeighbor**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasLeftNeighbor.md) <br>_A gate with a left neighbor._  |
| class | [**HasRightNeighbor**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasRightNeighbor.md) <br>_A gate with a right neighbor._  |
| class | [**LeftReservoirWithImplantedOhmic**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1LeftReservoirWithImplantedOhmic.md) <br>_A special reservoir geometry that has an implanted ohmic contact and the rest of the channel extending to the right._  |
| class | [**RightReservoirWithImplantedOhmic**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1RightReservoirWithImplantedOhmic.md) <br>_A special reservoir geometry that has an implanted ohmic contact and the rest of the channel extending to the left._  |


## Public Types

| Type | Name |
| ---: | :--- |
| typedef std::shared\_ptr&lt; [**DotGateWithNeighbors**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1DotGateWithNeighbors.md) &gt; | [**DotGateWithNeighborsSP**](#typedef-dotgatewithneighborssp)  <br> |
| typedef std::shared\_ptr&lt; [**DotGatesWithNeighbors**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1DotGatesWithNeighbors.md) &gt; | [**DotGatesWithNeighborsSP**](#typedef-dotgateswithneighborssp)  <br> |
| typedef std::shared\_ptr&lt; [**GateGeometryArray1D**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1GateGeometryArray1D.md) &gt; | [**GateGeometryArray1DSP**](#typedef-gategeometryarray1dsp)  <br> |
| typedef std::shared\_ptr&lt; [**HasImplantedOhmic**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasImplantedOhmic.md) &gt; | [**HasImplantedOhmicSP**](#typedef-hasimplantedohmicsp)  <br> |
| typedef std::shared\_ptr&lt; [**HasLeftNeighbor**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasLeftNeighbor.md) &gt; | [**HasLeftNeighborSP**](#typedef-hasleftneighborsp)  <br> |
| typedef std::shared\_ptr&lt; [**HasRightNeighbor**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasRightNeighbor.md) &gt; | [**HasRightNeighborSP**](#typedef-hasrightneighborsp)  <br> |
| typedef std::shared\_ptr&lt; [**LeftReservoirWithImplantedOhmic**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1LeftReservoirWithImplantedOhmic.md) &gt; | [**LeftReservoirWithImplantedOhmicSP**](#typedef-leftreservoirwithimplantedohmicsp)  <br> |
| typedef std::shared\_ptr&lt; [**RightReservoirWithImplantedOhmic**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1RightReservoirWithImplantedOhmic.md) &gt; | [**RightReservoirWithImplantedOhmicSP**](#typedef-rightreservoirwithimplantedohmicsp)  <br> |
















































## Public Types Documentation




### typedef DotGateWithNeighborsSP 

```C++
using falcon_core::physics::config::geometries::DotGateWithNeighborsSP = typedef std::shared_ptr<DotGateWithNeighbors>;
```




<hr>



### typedef DotGatesWithNeighborsSP 

```C++
using falcon_core::physics::config::geometries::DotGatesWithNeighborsSP = typedef std::shared_ptr<DotGatesWithNeighbors>;
```




<hr>



### typedef GateGeometryArray1DSP 

```C++
using falcon_core::physics::config::geometries::GateGeometryArray1DSP = typedef std::shared_ptr<GateGeometryArray1D>;
```




<hr>



### typedef HasImplantedOhmicSP 

```C++
using falcon_core::physics::config::geometries::HasImplantedOhmicSP = typedef std::shared_ptr<HasImplantedOhmic>;
```




<hr>



### typedef HasLeftNeighborSP 

```C++
using falcon_core::physics::config::geometries::HasLeftNeighborSP = typedef std::shared_ptr<HasLeftNeighbor>;
```




<hr>



### typedef HasRightNeighborSP 

```C++
using falcon_core::physics::config::geometries::HasRightNeighborSP = typedef std::shared_ptr<HasRightNeighbor>;
```




<hr>



### typedef LeftReservoirWithImplantedOhmicSP 

```C++
using falcon_core::physics::config::geometries::LeftReservoirWithImplantedOhmicSP = typedef std::shared_ptr<LeftReservoirWithImplantedOhmic>;
```




<hr>



### typedef RightReservoirWithImplantedOhmicSP 

```C++
using falcon_core::physics::config::geometries::RightReservoirWithImplantedOhmicSP = typedef std::shared_ptr<RightReservoirWithImplantedOhmic>;
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/physics/config/geometries/DotGatesWithNeighbors.hpp`

