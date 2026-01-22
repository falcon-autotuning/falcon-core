

# Struct falcon\_core::generic::category::determine\_bool\_tag

**template &lt;typename T&gt;**



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**generic**](namespacefalcon__core_1_1generic.md) **>** [**category**](namespacefalcon__core_1_1generic_1_1category.md) **>** [**determine\_bool\_tag**](structfalcon__core_1_1generic_1_1category_1_1determine__bool__tag.md)






















## Public Types

| Type | Name |
| ---: | :--- |
| typedef std::conditional\_t&lt; std::is\_same&lt; T, bool &gt;::value, [**bool\_tag**](structfalcon__core_1_1generic_1_1category_1_1bool__tag.md), [**other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md) &gt; | [**type**](#typedef-type)  <br> |
















































## Public Types Documentation




### typedef type 

```C++
using falcon_core::generic::category::determine_bool_tag< T >::type = 
      std::conditional_t<std::is_same<T, bool>::value, bool_tag, other_tag>;
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/generic/CategoryTags.hpp`

