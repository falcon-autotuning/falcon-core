

# Struct falcon\_core::generic::category::determine\_tag

**template &lt;typename T&gt;**



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**generic**](namespacefalcon__core_1_1generic.md) **>** [**category**](namespacefalcon__core_1_1generic_1_1category.md) **>** [**determine\_tag**](structfalcon__core_1_1generic_1_1category_1_1determine__tag.md)






















## Public Types

| Type | Name |
| ---: | :--- |
| typedef std::conditional\_t&lt; std::is\_base\_of&lt; [**Song**](classfalcon__core_1_1generic_1_1Song.md), T &gt;::value &&![**is\_primitive**](structfalcon__core_1_1generic_1_1is__primitive.md)&lt; T &gt;::value, [**song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md), std::conditional\_t&lt; [**is\_primitive**](structfalcon__core_1_1generic_1_1is__primitive.md)&lt; T &gt;::value, [**primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md), [**other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md) &gt; &gt; | [**type**](#typedef-type)  <br> |
















































## Public Types Documentation




### typedef type 

```C++
using falcon_core::generic::category::determine_tag< T >::type =  std::conditional_t< std::is_base_of<Song, T>::value && !is_primitive<T>::value, song_tag, std::conditional_t<is_primitive<T>::value, primitive_tag, other_tag> >;
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/generic/CategoryTags.hpp`

