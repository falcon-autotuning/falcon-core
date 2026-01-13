

# Class falcon\_core::physics::units::Prefix



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**physics**](namespacefalcon__core_1_1physics.md) **>** [**units**](namespacefalcon__core_1_1physics_1_1units.md) **>** [**Prefix**](classfalcon__core_1_1physics_1_1units_1_1Prefix.md)












































## Public Static Functions

| Type | Name |
| ---: | :--- |
|  const std::map&lt; int, std::string &gt; & | [**get\_power\_to\_symbol\_map**](#function-get_power_to_symbol_map) () <br>_Get the power to symbol map._  |
|  std::string | [**get\_symbol**](#function-get_symbol) (int prefix\_value) <br>_Get the symbol for a prefix value._  |
|  const std::map&lt; std::string, int &gt; & | [**get\_symbol\_to\_power\_map**](#function-get_symbol_to_power_map) () <br>_Get the symbol to power map._  |
|  int | [**get\_value**](#function-get_value) (std::string prefix\_symbol) <br>_Get the exponent value for a prefix symbol._  |
|  bool | [**is\_valid**](#function-is_valid) (std::string prefix\_symbol) <br>_Check if a prefix symbol is valid._  |
|  std::pair&lt; double, std::string &gt; | [**prefix\_multiplication**](#function-prefix_multiplication) (std::string first\_prefix, std::string second\_prefix, double scale\_factor) <br>_Multiply two prefixes together._  |


























## Public Static Functions Documentation




### function get\_power\_to\_symbol\_map 

_Get the power to symbol map._ 
```C++
static const std::map< int, std::string > & falcon_core::physics::units::Prefix::get_power_to_symbol_map () 
```





**Returns:**

A constant reference to the power to symbol map. 





        

<hr>



### function get\_symbol 

_Get the symbol for a prefix value._ 
```C++
static std::string falcon_core::physics::units::Prefix::get_symbol (
    int prefix_value
) 
```





**Parameters:**


* `prefix_value` The exponent value of the prefix. 



**Returns:**

The symbol corresponding to the prefix value. 





        

<hr>



### function get\_symbol\_to\_power\_map 

_Get the symbol to power map._ 
```C++
static const std::map< std::string, int > & falcon_core::physics::units::Prefix::get_symbol_to_power_map () 
```





**Returns:**

A constant reference to the symbol to power map. 





        

<hr>



### function get\_value 

_Get the exponent value for a prefix symbol._ 
```C++
static int falcon_core::physics::units::Prefix::get_value (
    std::string prefix_symbol
) 
```





**Parameters:**


* `prefix_symbol` The symbol of the prefix. 



**Returns:**

The exponent value corresponding to the prefix symbol. 





        

<hr>



### function is\_valid 

_Check if a prefix symbol is valid._ 
```C++
static bool falcon_core::physics::units::Prefix::is_valid (
    std::string prefix_symbol
) 
```





**Parameters:**


* `prefix_symbol` The symbol of the prefix. 



**Returns:**

True if the prefix is valid 





        

<hr>



### function prefix\_multiplication 

_Multiply two prefixes together._ 
```C++
static std::pair< double, std::string > falcon_core::physics::units::Prefix::prefix_multiplication (
    std::string first_prefix,
    std::string second_prefix,
    double scale_factor
) 
```





**Parameters:**


* `first_prefix` The first prefix symbol. 
* `second_prefix` The second prefix symbol. 
* `scale_factor` The scale factor to apply. 



**Returns:**

A pair containing the resulting prefix symbol and scale factor. 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/physics/units/Prefix.hpp`

