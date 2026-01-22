

# Namespace falcon\_core::generic::category



[**Namespace List**](namespaces.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**generic**](namespacefalcon__core_1_1generic.md) **>** [**category**](namespacefalcon__core_1_1generic_1_1category.md)




















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**bool\_tag**](structfalcon__core_1_1generic_1_1category_1_1bool__tag.md) <br> |
| struct | [**determine\_bool\_tag**](structfalcon__core_1_1generic_1_1category_1_1determine__bool__tag.md) &lt;typename T&gt;<br> |
| struct | [**determine\_tag**](structfalcon__core_1_1generic_1_1category_1_1determine__tag.md) &lt;typename T&gt;<br> |
| struct | [**is\_shared\_ptr**](structfalcon__core_1_1generic_1_1category_1_1is__shared__ptr.md) &lt;typename T&gt;<br> |
| struct | [**is\_shared\_ptr&lt; std::shared\_ptr&lt; T &gt; &gt;**](structfalcon__core_1_1generic_1_1category_1_1is__shared__ptr_3_01std_1_1shared__ptr_3_01T_01_4_01_4.md) &lt;typename T&gt;<br> |
| struct | [**other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md) <br> |
| struct | [**primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md) <br> |
| struct | [**song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md) <br> |






















## Public Functions

| Type | Name |
| ---: | :--- |
|  bool | [**compare\_value**](#function-compare_value) (const T & a, const T & b, std::true\_type) <br> |
|  bool | [**compare\_value**](#function-compare_value) (const T & a, const T & b, std::false\_type) <br> |




























## Public Functions Documentation




### function compare\_value 

```C++
template<typename T>
bool falcon_core::generic::category::compare_value (
    const T & a,
    const T & b,
    std::true_type
) 
```




<hr>



### function compare\_value 

```C++
template<typename T>
bool falcon_core::generic::category::compare_value (
    const T & a,
    const T & b,
    std::false_type
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/generic/CategoryTags.hpp`

