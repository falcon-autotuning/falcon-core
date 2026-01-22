

# Namespace falcon\_core::math::arrays



[**Namespace List**](namespaces.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**math**](namespacefalcon__core_1_1math.md) **>** [**arrays**](namespacefalcon__core_1_1math_1_1arrays.md)




















## Classes

| Type | Name |
| ---: | :--- |
| class | [**ControlArray**](classfalcon__core_1_1math_1_1arrays_1_1ControlArray.md) <br>_Array type for control independant axis data._  |
| class | [**ControlArray1D**](classfalcon__core_1_1math_1_1arrays_1_1ControlArray1D.md) <br>_1D control array, enforces 1D shape at construction._  |
| class | [**IncreasingAlignment**](classfalcon__core_1_1math_1_1arrays_1_1IncreasingAlignment.md) <br>_A three state system. The three states are 1, -1, and 0. 0 implies no trend in the domain._  |
| class | [**Is1D**](classfalcon__core_1_1math_1_1arrays_1_1Is1D.md) &lt;typename T&gt;<br> |
| class | [**IsControl**](classfalcon__core_1_1math_1_1arrays_1_1IsControl.md) &lt;typename T&gt;<br> |
| class | [**IsLabelled**](classfalcon__core_1_1math_1_1arrays_1_1IsLabelled.md) &lt;typename T&gt;<br> |
| class | [**LabelledArrays**](classfalcon__core_1_1math_1_1arrays_1_1LabelledArrays.md) &lt;typename ArrayType&gt;<br>_Container for multiple labelled arrays._  |
| class | [**LabelledControlArray**](classfalcon__core_1_1math_1_1arrays_1_1LabelledControlArray.md) <br>_An array with a context label attached._  |
| class | [**LabelledControlArray1D**](classfalcon__core_1_1math_1_1arrays_1_1LabelledControlArray1D.md) <br>_1D control array with a label._  |
| class | [**LabelledMeasuredArray**](classfalcon__core_1_1math_1_1arrays_1_1LabelledMeasuredArray.md) <br>_An array with a context label attached._  |
| class | [**LabelledMeasuredArray1D**](classfalcon__core_1_1math_1_1arrays_1_1LabelledMeasuredArray1D.md) <br>_1D control array with a label._  |
| class | [**MeasuredArray**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md) <br>_Array type for measured data, derived from BaseArray._  |
| class | [**MeasuredArray1D**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray1D.md) <br>_Array type for measured data, derived from BaseArray._  |


## Public Types

| Type | Name |
| ---: | :--- |
| typedef std::shared\_ptr&lt; [**ControlArray1D**](classfalcon__core_1_1math_1_1arrays_1_1ControlArray1D.md) &gt; | [**ControlArray1DSP**](#typedef-controlarray1dsp)  <br> |
| typedef std::shared\_ptr&lt; [**ControlArray**](classfalcon__core_1_1math_1_1arrays_1_1ControlArray.md) &gt; | [**ControlArraySP**](#typedef-controlarraysp)  <br> |
| typedef std::shared\_ptr&lt; [**IncreasingAlignment**](classfalcon__core_1_1math_1_1arrays_1_1IncreasingAlignment.md) &gt; | [**IncreasingAlignmentSP**](#typedef-increasingalignmentsp)  <br> |
| typedef std::shared\_ptr&lt; [**LabelledArrays**](classfalcon__core_1_1math_1_1arrays_1_1LabelledArrays.md)&lt; T &gt; &gt; | [**LabelledArraysSP**](#typedef-labelledarrayssp)  <br> |
| typedef std::shared\_ptr&lt; [**LabelledControlArray1D**](classfalcon__core_1_1math_1_1arrays_1_1LabelledControlArray1D.md) &gt; | [**LabelledControlArray1DSP**](#typedef-labelledcontrolarray1dsp)  <br> |
| typedef std::shared\_ptr&lt; [**LabelledControlArray**](classfalcon__core_1_1math_1_1arrays_1_1LabelledControlArray.md) &gt; | [**LabelledControlArraySP**](#typedef-labelledcontrolarraysp)  <br> |
| typedef std::shared\_ptr&lt; [**LabelledMeasuredArray1D**](classfalcon__core_1_1math_1_1arrays_1_1LabelledMeasuredArray1D.md) &gt; | [**LabelledMeasuredArray1DSP**](#typedef-labelledmeasuredarray1dsp)  <br> |
| typedef std::shared\_ptr&lt; [**LabelledMeasuredArray**](classfalcon__core_1_1math_1_1arrays_1_1LabelledMeasuredArray.md) &gt; | [**LabelledMeasuredArraySP**](#typedef-labelledmeasuredarraysp)  <br> |
| typedef std::shared\_ptr&lt; [**MeasuredArray1D**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray1D.md) &gt; | [**MeasuredArray1DSP**](#typedef-measuredarray1dsp)  <br> |
| typedef std::shared\_ptr&lt; [**MeasuredArray**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md) &gt; | [**MeasuredArraySP**](#typedef-measuredarraysp)  <br> |
















































## Public Types Documentation




### typedef ControlArray1DSP 

```C++
using falcon_core::math::arrays::ControlArray1DSP =  std::shared_ptr<ControlArray1D>;
```




<hr>



### typedef ControlArraySP 

```C++
using falcon_core::math::arrays::ControlArraySP =  std::shared_ptr<ControlArray>;
```




<hr>



### typedef IncreasingAlignmentSP 

```C++
using falcon_core::math::arrays::IncreasingAlignmentSP =  std::shared_ptr<IncreasingAlignment>;
```




<hr>



### typedef LabelledArraysSP 

```C++
using falcon_core::math::arrays::LabelledArraysSP =  std::shared_ptr<LabelledArrays<T>>;
```




<hr>



### typedef LabelledControlArray1DSP 

```C++
using falcon_core::math::arrays::LabelledControlArray1DSP =  std::shared_ptr<LabelledControlArray1D>;
```




<hr>



### typedef LabelledControlArraySP 

```C++
using falcon_core::math::arrays::LabelledControlArraySP =  std::shared_ptr<LabelledControlArray>;
```




<hr>



### typedef LabelledMeasuredArray1DSP 

```C++
using falcon_core::math::arrays::LabelledMeasuredArray1DSP =  std::shared_ptr<LabelledMeasuredArray1D>;
```




<hr>



### typedef LabelledMeasuredArraySP 

```C++
using falcon_core::math::arrays::LabelledMeasuredArraySP =  std::shared_ptr<LabelledMeasuredArray>;
```




<hr>



### typedef MeasuredArray1DSP 

```C++
using falcon_core::math::arrays::MeasuredArray1DSP =  std::shared_ptr<MeasuredArray1D>;
```




<hr>



### typedef MeasuredArraySP 

```C++
using falcon_core::math::arrays::MeasuredArraySP =  std::shared_ptr<MeasuredArray>;
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/math/arrays/ControlArray.hpp`

