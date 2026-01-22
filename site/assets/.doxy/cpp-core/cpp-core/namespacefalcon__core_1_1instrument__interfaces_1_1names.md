

# Namespace falcon\_core::instrument\_interfaces::names



[**Namespace List**](namespaces.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**instrument\_interfaces**](namespacefalcon__core_1_1instrument__interfaces.md) **>** [**names**](namespacefalcon__core_1_1instrument__interfaces_1_1names.md)




















## Classes

| Type | Name |
| ---: | :--- |
| class | [**InstrumentPort**](classfalcon__core_1_1instrument__interfaces_1_1names_1_1InstrumentPort.md) <br> |
| struct | [**InstrumentTypes**](structfalcon__core_1_1instrument__interfaces_1_1names_1_1InstrumentTypes.md) <br> |
| class | [**Ports**](classfalcon__core_1_1instrument__interfaces_1_1names_1_1Ports.md) <br> |


## Public Types

| Type | Name |
| ---: | :--- |
| typedef std::string | [**Instrument**](#typedef-instrument)  <br> |
| typedef std::shared\_ptr&lt; [**InstrumentPort**](classfalcon__core_1_1instrument__interfaces_1_1names_1_1InstrumentPort.md) &gt; | [**InstrumentPortSP**](#typedef-instrumentportsp)  <br> |
| enum  | [**PortType**](#enum-porttype)  <br> |
| typedef std::shared\_ptr&lt; [**Ports**](classfalcon__core_1_1instrument__interfaces_1_1names_1_1Ports.md) &gt; | [**PortsSP**](#typedef-portssp)  <br> |
















































## Public Types Documentation




### typedef Instrument 

```C++
using falcon_core::instrument_interfaces::names::Instrument =  std::string;
```




<hr>



### typedef InstrumentPortSP 

```C++
using falcon_core::instrument_interfaces::names::InstrumentPortSP =  std::shared_ptr<InstrumentPort>;
```




<hr>



### enum PortType 

```C++
enum falcon_core::instrument_interfaces::names::PortType {
    Knob,
    Meter,
    InstrumentPort
};
```




<hr>



### typedef PortsSP 

```C++
using falcon_core::instrument_interfaces::names::PortsSP =  std::shared_ptr<Ports>;
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/instrument_interfaces/names/Instrument.hpp`

