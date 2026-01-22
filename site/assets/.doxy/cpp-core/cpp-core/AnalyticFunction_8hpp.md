

# File AnalyticFunction.hpp



[**FileList**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**math**](dir_deeec2dd49335e06d18546a1be264a01.md) **>** [**AnalyticFunction.hpp**](AnalyticFunction_8hpp.md)

[Go to the source code of this file](AnalyticFunction_8hpp_source.md)

_A class for a gunction that can be used to describe analytic time domain shaped._ [More...](#detailed-description)

* `#include "falcon_core/generic/FArray.hpp"`
* `#include "falcon_core/generic/List.hpp"`
* `#include "falcon_core/generic/Map.hpp"`













## Namespaces

| Type | Name |
| ---: | :--- |
| namespace | [**falcon\_core**](namespacefalcon__core.md) <br>_A transform that maps a port to a time domain analytic function._  |
| namespace | [**math**](namespacefalcon__core_1_1math.md) <br> |


## Classes

| Type | Name |
| ---: | :--- |
| class | [**AnalyticFunction**](classfalcon__core_1_1math_1_1AnalyticFunction.md) <br> |


















































## Detailed Description


This supports functions of the form x[0]\*t^2 + x[1] where the values that can be set are elements of the x vector, and it can be evaluated as a function of time at a later date. For time evaluation, it is assumed that this function should be evaluated at t=0.


Not that this vector should always start from 0, and you should not skip any indexes.


There are builtin labels, such that the arbitrary vector indexes can be turned into human readable labels. 


    

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/math/AnalyticFunction.hpp`

