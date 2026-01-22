

# Namespace falcon\_core::autotuner\_interfaces::interpretations



[**Namespace List**](namespaces.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**autotuner\_interfaces**](namespacefalcon__core_1_1autotuner__interfaces.md) **>** [**interpretations**](namespacefalcon__core_1_1autotuner__interfaces_1_1interpretations.md)




















## Classes

| Type | Name |
| ---: | :--- |
| class | [**InterpretationContainer**](classfalcon__core_1_1autotuner__interfaces_1_1interpretations_1_1InterpretationContainer.md) &lt;typename Value&gt;<br> |
| class | [**InterpretationContext**](classfalcon__core_1_1autotuner__interfaces_1_1interpretations_1_1InterpretationContext.md) <br>_A context that describes measurement variables._  |


## Public Types

| Type | Name |
| ---: | :--- |
| typedef std::shared\_ptr&lt; [**InterpretationContainer**](classfalcon__core_1_1autotuner__interfaces_1_1interpretations_1_1InterpretationContainer.md)&lt; Value &gt; &gt; | [**InterpretationContainerSP**](#typedef-interpretationcontainersp)  <br> |
| typedef std::shared\_ptr&lt; [**InterpretationContext**](classfalcon__core_1_1autotuner__interfaces_1_1interpretations_1_1InterpretationContext.md) &gt; | [**InterpretationContextSP**](#typedef-interpretationcontextsp)  <br> |
















































## Public Types Documentation




### typedef InterpretationContainerSP 

```C++
using falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP = 
    std::shared_ptr<InterpretationContainer<Value>>;
```




<hr>



### typedef InterpretationContextSP 

```C++
using falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP =  std::shared_ptr<InterpretationContext>;
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/autotuner_interfaces/interpretations/InterpretationContainer.hpp`

