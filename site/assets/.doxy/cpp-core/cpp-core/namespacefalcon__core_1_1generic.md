

# Namespace falcon\_core::generic



[**Namespace List**](namespaces.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**generic**](namespacefalcon__core_1_1generic.md)


















## Namespaces

| Type | Name |
| ---: | :--- |
| namespace | [**category**](namespacefalcon__core_1_1generic_1_1category.md) <br> |


## Classes

| Type | Name |
| ---: | :--- |
| class | [**FArray**](classfalcon__core_1_1generic_1_1FArray.md) &lt;typename T&gt;<br> |
| class | [**IFArray**](classfalcon__core_1_1generic_1_1IFArray.md) &lt;typename T&gt;<br> |
| class | [**List**](classfalcon__core_1_1generic_1_1List.md) &lt;typename Value&gt;<br> |
| class | [**Map**](classfalcon__core_1_1generic_1_1Map.md) &lt;typename Key, typename Value&gt;<br> |
| class | [**Pair**](classfalcon__core_1_1generic_1_1Pair.md) &lt;typename T1, typename T2&gt;<br> |
| class | [**Song**](classfalcon__core_1_1generic_1_1Song.md) <br>_Abstract base for all serializable_ [_**Song**_](classfalcon__core_1_1generic_1_1Song.md) _objects._ |
| struct | [**is\_primitive**](structfalcon__core_1_1generic_1_1is__primitive.md) &lt;typename T&gt;<br> |


## Public Types

| Type | Name |
| ---: | :--- |
| typedef std::shared\_ptr&lt; [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**FArraySP**](#typedef-farraysp)  <br> |
| typedef std::shared\_ptr&lt; [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt; &gt; | [**ListSP**](#typedef-listsp)  <br> |
| typedef std::shared\_ptr&lt; [**Map**](classfalcon__core_1_1generic_1_1Map.md)&lt; Key, Value &gt; &gt; | [**MapSP**](#typedef-mapsp)  <br> |
| typedef std::shared\_ptr&lt; [**Pair**](classfalcon__core_1_1generic_1_1Pair.md)&lt; T1, T2 &gt; &gt; | [**PairSP**](#typedef-pairsp)  <br> |
| typedef std::shared\_ptr&lt; [**Song**](classfalcon__core_1_1generic_1_1Song.md) &gt; | [**SongSP**](#typedef-songsp)  <br> |
















































## Public Types Documentation




### typedef FArraySP 

```C++
using falcon_core::generic::FArraySP =  std::shared_ptr<FArray<T>>;
```




<hr>



### typedef ListSP 

```C++
using falcon_core::generic::ListSP =  std::shared_ptr<List<Value>>;
```




<hr>



### typedef MapSP 

```C++
using falcon_core::generic::MapSP =  std::shared_ptr<Map<Key, Value>>;
```




<hr>



### typedef PairSP 

```C++
using falcon_core::generic::PairSP =  std::shared_ptr<Pair<T1, T2>>;
```




<hr>



### typedef SongSP 

```C++
using falcon_core::generic::SongSP =  std::shared_ptr<Song>;
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/generic/CategoryTags.hpp`

