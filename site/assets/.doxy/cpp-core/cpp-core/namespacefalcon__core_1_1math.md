

# Namespace falcon\_core::math



[**Namespace List**](namespaces.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**math**](namespacefalcon__core_1_1math.md)


















## Namespaces

| Type | Name |
| ---: | :--- |
| namespace | [**arrays**](namespacefalcon__core_1_1math_1_1arrays.md) <br> |
| namespace | [**discrete\_spaces**](namespacefalcon__core_1_1math_1_1discrete__spaces.md) <br> |
| namespace | [**domains**](namespacefalcon__core_1_1math_1_1domains.md) <br> |


## Classes

| Type | Name |
| ---: | :--- |
| class | [**AnalyticFunction**](classfalcon__core_1_1math_1_1AnalyticFunction.md) <br> |
| class | [**Axes**](classfalcon__core_1_1math_1_1Axes.md) &lt;typename Value&gt;<br>_Container for a collection of axis objects._  |
| class | [**Point**](classfalcon__core_1_1math_1_1Point.md) <br>_Represents a point in a multi-dimensional space, indexed by connections._  |
| class | [**Quantity**](classfalcon__core_1_1math_1_1Quantity.md) <br>_Represents a physical quantity with a value and unit._  |
| class | [**UnitSpace**](classfalcon__core_1_1math_1_1UnitSpace.md) <br>_Respresents a hypercube of measurement space. It is defined by a set of axes, each of which can be discretized._  |
| class | [**Vector**](classfalcon__core_1_1math_1_1Vector.md) <br>_Represents a vector in a multi-dimensional space, defined by start and end points._  |


## Public Types

| Type | Name |
| ---: | :--- |
| typedef std::shared\_ptr&lt; [**AnalyticFunction**](classfalcon__core_1_1math_1_1AnalyticFunction.md) &gt; | [**AnalyticFunctionSP**](#typedef-analyticfunctionsp)  <br> |
| typedef std::shared\_ptr&lt; [**Axes**](classfalcon__core_1_1math_1_1Axes.md)&lt; V &gt; &gt; | [**AxesSP**](#typedef-axessp)  <br> |
| typedef std::shared\_ptr&lt; [**Point**](classfalcon__core_1_1math_1_1Point.md) &gt; | [**PointSP**](#typedef-pointsp)  <br> |
| typedef std::shared\_ptr&lt; [**Quantity**](classfalcon__core_1_1math_1_1Quantity.md) &gt; | [**QuantitySP**](#typedef-quantitysp)  <br> |
| enum  | [**Sign**](#enum-sign)  <br>_Enum for mathematical sign._  |
| typedef std::shared\_ptr&lt; [**UnitSpace**](classfalcon__core_1_1math_1_1UnitSpace.md) &gt; | [**UnitSpaceSP**](#typedef-unitspacesp)  <br> |
| typedef std::string | [**VariableName**](#typedef-variablename)  <br> |
| typedef std::shared\_ptr&lt; [**Vector**](classfalcon__core_1_1math_1_1Vector.md) &gt; | [**VectorSP**](#typedef-vectorsp)  <br> |






















## Public Static Functions

| Type | Name |
| ---: | :--- |
|  const [**generic::List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt; & | [**list\_check\_and\_deref**](#function-list_check_and_deref) (const generic::ListSP&lt; Value &gt; & items) <br> |


























## Public Types Documentation




### typedef AnalyticFunctionSP 

```C++
using falcon_core::math::AnalyticFunctionSP =  std::shared_ptr<AnalyticFunction>;
```




<hr>



### typedef AxesSP 

```C++
using falcon_core::math::AxesSP =  std::shared_ptr<Axes<V>>;
```




<hr>



### typedef PointSP 

```C++
using falcon_core::math::PointSP =  std::shared_ptr<Point>;
```




<hr>



### typedef QuantitySP 

```C++
using falcon_core::math::QuantitySP =  std::shared_ptr<Quantity>;
```




<hr>



### enum Sign 

_Enum for mathematical sign._ 
```C++
enum falcon_core::math::Sign {
    POSITIVE = 1,
    NEGATIVE = -1
};
```




<hr>



### typedef UnitSpaceSP 

```C++
using falcon_core::math::UnitSpaceSP =  std::shared_ptr<UnitSpace>;
```




<hr>



### typedef VariableName 

```C++
using falcon_core::math::VariableName =  std::string;
```




<hr>



### typedef VectorSP 

```C++
using falcon_core::math::VectorSP =  std::shared_ptr<Vector>;
```




<hr>
## Public Static Functions Documentation




### function list\_check\_and\_deref 

```C++
template<typename Value>
static const generic::List < Value > & falcon_core::math::list_check_and_deref (
    const generic::ListSP< Value > & items
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/math/AnalyticFunction.hpp`

