

# Class falcon\_core::physics::config::core::Config



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**physics**](namespacefalcon__core_1_1physics.md) **>** [**config**](namespacefalcon__core_1_1physics_1_1config.md) **>** [**core**](namespacefalcon__core_1_1physics_1_1config_1_1core.md) **>** [**Config**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Config.md)



_The imported config file for falcon use._ 

* `#include <Config.hpp>`



Inherits the following classes: [falcon\_core::physics::config::core::StandardConfigConnections](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Config**](#function-config-13) (const [**Config**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Config.md) & other) <br> |
|   | [**Config**](#function-config-23) (const device\_structures::ConnectionsSP & screening\_gates, const device\_structures::ConnectionsSP & plunger\_gates, const device\_structures::ConnectionsSP & ohmics, const device\_structures::ConnectionsSP & barrier\_gates, const device\_structures::ConnectionsSP & reservoir\_gates, const generic::MapSP&lt; [**autotuner\_interfaces::names::Gname**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Gname.md), [**Group**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Group.md) &gt; groups, const device\_structures::ImpedancesSP & wiring\_DC, const VoltageConstraintsSP & constriants) <br>_Constructs a new_ [_**Config**_](classfalcon__core_1_1physics_1_1config_1_1core_1_1Config.md) _object for falcon use._ |
|  autotuner\_interfaces::names::ChannelsSP | [**channels**](#function-channels) () const<br>_Returns the channels of the config._  |
|  void | [**check\_group\_consistency**](#function-check_group_consistency) () const<br>_Check that all groups are consistent._  |
|  void | [**check\_impedance\_consistency**](#function-check_impedance_consistency) () const<br>_Check that all impedances are consistent._  |
|  void | [**compile\_channels**](#function-compile_channels) () const<br>_Searches through all_ [_**Group**_](classfalcon__core_1_1physics_1_1config_1_1core_1_1Group.md) _and collects all of the Channel._ |
|  device\_structures::GateRelationsSP | [**generate\_gate\_relations**](#function-generate_gate_relations) () const<br>_Returns the gate relations in the config._  |
|  generic::ListSP&lt; [**autotuner\_interfaces::names::Gname**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Gname.md) &gt; | [**get\_all\_gnames**](#function-get_all_gnames) () const<br>_Returns all of the group names._  |
|  generic::ListSP&lt; [**Group**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Group.md) &gt; | [**get\_all\_groups**](#function-get_all_groups) () const<br>_Returns all of the groups._  |
|  device\_structures::ConnectionSP | [**get\_associated\_ohmic**](#function-get_associated_ohmic) (const device\_structures::ConnectionSP & reservoir\_gate) const<br>_Every reservoir gate has an associated ohmic._  |
|  generic::MapSP&lt; [**autotuner\_interfaces::names::Channel**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Channel.md), [**device\_structures::Connections**](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) &gt; | [**get\_barrier\_gate\_dict**](#function-get_barrier_gate_dict) () const<br>_Returns barrier gates indexed by channel._  |
|  device\_structures::ConnectionsSP | [**get\_channel\_barrier\_gates**](#function-get_channel_barrier_gates) (const autotuner\_interfaces::names::ChannelSP & channel) const<br>_Gets all of the barrier gates assocated with the selected current channel from the config._  |
|  device\_structures::ConnectionsSP | [**get\_channel\_dot\_gates**](#function-get_channel_dot_gates) (const autotuner\_interfaces::names::ChannelSP & channel) const<br>_Gets all of the dot gates assocated with the selected current channel from the config._  |
|  device\_structures::ConnectionsSP | [**get\_channel\_gates**](#function-get_channel_gates) (const autotuner\_interfaces::names::ChannelSP & channel) const<br>_Gets all of the gates assocated with the selected current channel from the config._  |
|  device\_structures::ConnectionsSP | [**get\_channel\_ohmics**](#function-get_channel_ohmics) (const autotuner\_interfaces::names::ChannelSP & channel) const<br>_Gets all of the ohmics assocated with the selected current channel._  |
|  device\_structures::ConnectionsSP | [**get\_channel\_order\_no\_ohmics**](#function-get_channel_order_no_ohmics) (const autotuner\_interfaces::names::ChannelSP & channel) const<br>_Gets all of the gates in the order at the selected channel from the config with no ohmics._  |
|  device\_structures::ConnectionsSP | [**get\_channel\_plunger\_gates**](#function-get_channel_plunger_gates) (const autotuner\_interfaces::names::ChannelSP & channel) const<br>_Gets all of the plunger gates assocated with the selected current channel from the config._  |
|  device\_structures::ConnectionsSP | [**get\_channel\_reservoir\_gates**](#function-get_channel_reservoir_gates) (const autotuner\_interfaces::names::ChannelSP & channel) const<br>_Gets all of the reservoir gates assocated with the selected current channel from the config._  |
|  device\_structures::ConnectionsSP | [**get\_channel\_screening\_gates**](#function-get_channel_screening_gates) (const autotuner\_interfaces::names::ChannelSP & channel) const<br>_Gets all of the screening gates assocated with the selected current channel from the config._  |
|  generic::ListSP&lt; [**autotuner\_interfaces::names::Gname**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Gname.md) &gt; | [**get\_charge\_sense\_groups**](#function-get_charge_sense_groups) () const<br>_Finds all of the arrays of dots that are charge sensors, i.e. only one quantum dot per channel._  |
|  autotuner\_interfaces::names::ChannelsSP | [**get\_current\_channels**](#function-get_current_channels) () const<br>_Gets all of the current channels from the config._  |
|  std::pair&lt; device\_structures::ConnectionSP, device\_structures::ConnectionSP &gt; | [**get\_dot\_channel\_neighbors**](#function-get_dot_channel_neighbors) (const device\_structures::ConnectionSP & dotgate) const<br>_Gets the nearby neighbors of the selected gate in the dot channel._  |
|  generic::MapSP&lt; [**autotuner\_interfaces::names::Channel**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Channel.md), [**device\_structures::Connections**](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) &gt; | [**get\_dot\_gate\_dict**](#function-get_dot_gate_dict) () const<br>_Returns dot gates indexed by channel._  |
|  int | [**get\_dot\_number**](#function-get_dot_number) (const autotuner\_interfaces::names::ChannelSP & channel) const<br>_Finds the number of dots associated with a current channel from the config._  |
|  generic::MapSP&lt; [**autotuner\_interfaces::names::Channel**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Channel.md), [**device\_structures::Connections**](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) &gt; | [**get\_gate\_dict**](#function-get_gate_dict) () const<br>_Returns gates indexed by channel._  |
|  autotuner\_interfaces::names::GnameSP | [**get\_gname**](#function-get_gname) (const autotuner\_interfaces::names::ChannelSP & channel) const<br>_Gets the associated Gname with a Channel if it exists._  |
|  device\_structures::ConnectionsSP | [**get\_group\_barrier\_gates**](#function-get_group_barrier_gates) (const autotuner\_interfaces::names::GnameSP & gname) const<br>_Gets all of the barrier gates assocated with the selected group from the config._  |
|  device\_structures::ConnectionsSP | [**get\_group\_dot\_gates**](#function-get_group_dot_gates) (const autotuner\_interfaces::names::GnameSP & gname) const<br>_Gets all of the dot gates assocated with the selected group from the config._  |
|  device\_structures::ConnectionsSP | [**get\_group\_gates**](#function-get_group_gates) (const autotuner\_interfaces::names::GnameSP & gname) const<br>_Gets all of the gates assocated with the selected group from the config._  |
|  device\_structures::ConnectionsSP | [**get\_group\_plunger\_gates**](#function-get_group_plunger_gates) (const autotuner\_interfaces::names::GnameSP & gname) const<br>_Gets all of the plunger gates assocated with the selected group from the config._  |
|  device\_structures::ConnectionsSP | [**get\_group\_reservoir\_gates**](#function-get_group_reservoir_gates) (const autotuner\_interfaces::names::GnameSP & gname) const<br>_Gets all of the reservoir gates assocated with the selected group from the config._  |
|  device\_structures::ConnectionsSP | [**get\_group\_screening\_gates**](#function-get_group_screening_gates) (const autotuner\_interfaces::names::GnameSP & gname) const<br>_Gets all of the screening gates assocated with the selected group from the config._  |
|  device\_structures::ImpedanceSP | [**get\_impedance**](#function-get_impedance) (const device\_structures::ConnectionSP & connection) const<br>_Returns the impedance matching the connection in teh dcwiring._  |
|  device\_structures::ConnectionsSP | [**get\_isolated\_barrier\_gates**](#function-get_isolated_barrier_gates) () const<br>_Task to find isolated barrier gates stored in the config._  |
|  generic::MapSP&lt; [**autotuner\_interfaces::names::Channel**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Channel.md), [**device\_structures::Connections**](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) &gt; | [**get\_isolated\_barrier\_gates\_by\_channel**](#function-get_isolated_barrier_gates_by_channel) () const<br>_Returns barrier gates indexed by channel which are unshared._  |
|  device\_structures::ConnectionsSP | [**get\_isolated\_channel\_barrier\_gates**](#function-get_isolated_channel_barrier_gates) (const autotuner\_interfaces::names::ChannelSP & channel) const<br>_Finds the isolated barrier gates in the selected channel._  |
|  device\_structures::ConnectionsSP | [**get\_isolated\_channel\_dot\_gates**](#function-get_isolated_channel_dot_gates) (const autotuner\_interfaces::names::ChannelSP & channel) const<br>_Finds the isolated dot gates in the selected channel._  |
|  device\_structures::ConnectionsSP | [**get\_isolated\_channel\_gates**](#function-get_isolated_channel_gates) (const autotuner\_interfaces::names::ChannelSP & channel) const<br>_Finds the isolated gates in the selected channel._  |
|  device\_structures::ConnectionsSP | [**get\_isolated\_channel\_plunger\_gates**](#function-get_isolated_channel_plunger_gates) (const autotuner\_interfaces::names::ChannelSP & channel) const<br>_Finds the isolated plunger gates in the selected channel._  |
|  device\_structures::ConnectionsSP | [**get\_isolated\_channel\_reservoir\_gates**](#function-get_isolated_channel_reservoir_gates) (const autotuner\_interfaces::names::ChannelSP & channel) const<br>_Finds the isolated reservoir gates in the selected channel._  |
|  device\_structures::ConnectionsSP | [**get\_isolated\_channel\_screening\_gates**](#function-get_isolated_channel_screening_gates) (const autotuner\_interfaces::names::ChannelSP & channel) const<br>_Finds the isolated screening gates in the selected channel._  |
|  device\_structures::ConnectionsSP | [**get\_isolated\_dot\_gates**](#function-get_isolated_dot_gates) () const<br>_Task to find isolated dot gates stored in the config._  |
|  generic::MapSP&lt; [**autotuner\_interfaces::names::Channel**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Channel.md), [**device\_structures::Connections**](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) &gt; | [**get\_isolated\_dot\_gates\_by\_channel**](#function-get_isolated_dot_gates_by_channel) () const<br>_Returns dot gates indexed by channel which are unshared._  |
|  device\_structures::ConnectionsSP | [**get\_isolated\_gates**](#function-get_isolated_gates) () const<br>_Task to find isolated gates stored in the config._  |
|  generic::MapSP&lt; [**autotuner\_interfaces::names::Channel**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Channel.md), [**device\_structures::Connections**](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) &gt; | [**get\_isolated\_gates\_by\_channel**](#function-get_isolated_gates_by_channel) () const<br>_Returns gates indexed by channel which are unshared._  |
|  device\_structures::ConnectionsSP | [**get\_isolated\_plunger\_gates**](#function-get_isolated_plunger_gates) () const<br>_Task to find isolated plunger gates stored in the config._  |
|  generic::MapSP&lt; [**autotuner\_interfaces::names::Channel**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Channel.md), [**device\_structures::Connections**](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) &gt; | [**get\_isolated\_plunger\_gates\_by\_channel**](#function-get_isolated_plunger_gates_by_channel) () const<br>_Returns plunger gates indexed by channel which are unshared._  |
|  device\_structures::ConnectionsSP | [**get\_isolated\_reservoir\_gates**](#function-get_isolated_reservoir_gates) () const<br>_Task to find isolated reservoir gates stored in the config._  |
|  generic::MapSP&lt; [**autotuner\_interfaces::names::Channel**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Channel.md), [**device\_structures::Connections**](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) &gt; | [**get\_isolated\_reservoir\_gates\_by\_channel**](#function-get_isolated_reservoir_gates_by_channel) () const<br>_Returns reservoir gates indexed by channel which are unshared._  |
|  device\_structures::ConnectionsSP | [**get\_isolated\_screening\_gates**](#function-get_isolated_screening_gates) () const<br>_Task to find isolated screening gates stored in the config._  |
|  generic::MapSP&lt; [**autotuner\_interfaces::names::Channel**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Channel.md), [**device\_structures::Connections**](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) &gt; | [**get\_isolated\_screening\_gates\_by\_channel**](#function-get_isolated_screening_gates_by_channel) () const<br>_Returns screening gates indexed by channel which are unshared._  |
|  int | [**get\_num\_unique\_channels**](#function-get_num_unique_channels) () const<br>_Returns the number of unique channels associated with the current sample._  |
|  generic::MapSP&lt; [**autotuner\_interfaces::names::Channel**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Channel.md), [**device\_structures::Connections**](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) &gt; | [**get\_plunger\_gate\_dict**](#function-get_plunger_gate_dict) () const<br>_Returns plunger gates indexed by channel._  |
|  generic::MapSP&lt; [**autotuner\_interfaces::names::Channel**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Channel.md), [**device\_structures::Connections**](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) &gt; | [**get\_reservoir\_gate\_dict**](#function-get_reservoir_gate_dict) () const<br>_Returns reservoir gates indexed by channel._  |
|  generic::MapSP&lt; [**autotuner\_interfaces::names::Channel**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Channel.md), [**device\_structures::Connections**](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) &gt; | [**get\_screening\_gate\_dict**](#function-get_screening_gate_dict) () const<br>_Returns screening gates indexed by channel._  |
|  device\_structures::ConnectionsSP | [**get\_shared\_barrier\_gates**](#function-get_shared_barrier_gates) () const<br>_Task to find shared barrier gates stored in the config._  |
|  device\_structures::ConnectionsSP | [**get\_shared\_channel\_barrier\_gates**](#function-get_shared_channel_barrier_gates) (const autotuner\_interfaces::names::ChannelSP & channel) const<br>_Finds the shared barrier gates in the selected channel._  |
|  device\_structures::ConnectionsSP | [**get\_shared\_channel\_dot\_gates**](#function-get_shared_channel_dot_gates) (const autotuner\_interfaces::names::ChannelSP & channel) const<br>_Finds the shared dot gates of the gatetype in the selected channel._  |
|  device\_structures::ConnectionsSP | [**get\_shared\_channel\_gates**](#function-get_shared_channel_gates) (const autotuner\_interfaces::names::ChannelSP & channel) const<br>_Finds the shared gates in the selected channel._  |
|  device\_structures::ConnectionsSP | [**get\_shared\_channel\_plunger\_gates**](#function-get_shared_channel_plunger_gates) (const autotuner\_interfaces::names::ChannelSP & channel) const<br>_Finds the shared plunger gates in the selected channel._  |
|  device\_structures::ConnectionsSP | [**get\_shared\_channel\_reservoir\_gates**](#function-get_shared_channel_reservoir_gates) (const autotuner\_interfaces::names::ChannelSP & channel) const<br>_Finds the shared reservoir gates in the selected channel._  |
|  device\_structures::ConnectionsSP | [**get\_shared\_channel\_screening\_gates**](#function-get_shared_channel_screening_gates) (const autotuner\_interfaces::names::ChannelSP & channel) const<br>_Finds the shared screening gates in the selected channel._  |
|  device\_structures::ConnectionsSP | [**get\_shared\_dot\_gates**](#function-get_shared_dot_gates) () const<br>_Task to find shared dot gates stored in the config._  |
|  device\_structures::ConnectionsSP | [**get\_shared\_gates**](#function-get_shared_gates) () const<br>_Task to find shared gates stored in the config._  |
|  device\_structures::ConnectionsSP | [**get\_shared\_plunger\_gates**](#function-get_shared_plunger_gates) () const<br>_Task to find shared plunger gates stored in the config._  |
|  device\_structures::ConnectionsSP | [**get\_shared\_reservoir\_gates**](#function-get_shared_reservoir_gates) () const<br>_Task to find shared reservoir gates stored in the config._  |
|  device\_structures::ConnectionsSP | [**get\_shared\_screening\_gates**](#function-get_shared_screening_gates) () const<br>_Task to find shared screening gates stored in the config._  |
|  generic::MapSP&lt; [**autotuner\_interfaces::names::Gname**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Gname.md), [**Group**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Group.md) &gt; | [**groups**](#function-groups) () const<br>_Return the DC wiring impedances for the physical layout._  |
|  bool | [**has\_channel**](#function-has_channel) (const autotuner\_interfaces::names::ChannelSP & channel) const<br>_Validates if this is a proper Channel name in the set of all device Channels._  |
|  bool | [**has\_gname**](#function-has_gname) (const autotuner\_interfaces::names::GnameSP & gname) const<br>_Validates if this is a proper gatename._  |
|  int | [**num\_unique\_channels**](#function-num_unique_channels) () const<br>_Returns the number of unique channels associated with the current sample._  |
|  bool | [**ohmic\_in\_channel**](#function-ohmic_in_channel) (const device\_structures::ConnectionSP & ohmic, const autotuner\_interfaces::names::ChannelSP &) const<br>_Checks if the ohmic is connected to a channel._  |
|  bool | [**ohmic\_in\_charge\_sensor**](#function-ohmic_in_charge_sensor) (const device\_structures::ConnectionSP & ohmic) const<br>_If the ohmic is inside of a charge sensor channel._  |
|  bool | [**operator!=**](#function-operator) (const [**Config**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Config.md) & other) const<br> |
|  [**Config**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Config.md) & | [**operator=**](#function-operator_1) (const [**Config**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Config.md) & other) <br> |
|  bool | [**operator==**](#function-operator_2) (const [**Config**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Config.md) & other) const<br> |
|  autotuner\_interfaces::names::ChannelSP | [**return\_channel\_from\_gate**](#function-return_channel_from_gate) (const device\_structures::ConnectionSP & gate) const<br>_Returns the channel a given gate belongs to. If the gate is in multiple channels, if will return the first channel if finds._  |
|  autotuner\_interfaces::names::ChannelsSP | [**return\_channels\_from\_gate**](#function-return_channels_from_gate) (const device\_structures::ConnectionSP & gate) const<br>_Returns all of the channels associated with a gate._  |
|  GroupSP | [**select\_group**](#function-select_group) (const autotuner\_interfaces::names::GnameSP & gname) const<br>_Finds a group from the name and returns it._  |
|  VoltageConstraintsSP | [**voltage\_constraints**](#function-voltage_constraints) () const<br>_Return the voltage constraints for the physical layout._  |
|  device\_structures::ImpedancesSP | [**wiring\_DC**](#function-wiring_dc) () const<br>_Returns the wiring impedances of the config._  |


## Public Functions inherited from falcon_core::physics::config::core::StandardConfigConnections

See [falcon\_core::physics::config::core::StandardConfigConnections](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md)

| Type | Name |
| ---: | :--- |
|   | [**StandardConfigConnections**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-standardconfigconnections-13) (const [**StandardConfigConnections**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md) & other) <br> |
|   | [**StandardConfigConnections**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-standardconfigconnections-23) (const device\_structures::ConnectionsSP & screening\_gates, const device\_structures::ConnectionsSP & reservoir\_gates, const device\_structures::ConnectionsSP & plunger\_gates, const device\_structures::ConnectionsSP & barrier\_gates, const device\_structures::ConnectionsSP & ohmics) <br>_Constructs the differet gate types holders._  |
|  const device\_structures::ConnectionsSP & | [**barrier\_gates**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-barrier_gates) () const<br>_The barrier gates from the config._  |
|  const device\_structures::ConnectionsSP | [**dot\_gates**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-dot_gates) () const<br>_Gets the connections of type as supplied._  |
|  const device\_structures::ConnectionsSP | [**get\_all\_connections**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-get_all_connections) () const<br>_Gets all of the connections for this collection from the config._  |
|  const device\_structures::ConnectionsSP | [**get\_all\_gates**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-get_all_gates) () const<br>_Gets all of the gates for this collection from the config._  |
|  const device\_structures::ConnectionSP | [**get\_barrier\_gate**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-get_barrier_gate) () const<br>_Gets the first barrier gate connection._  |
|  const device\_structures::ConnectionSP | [**get\_dot\_gate**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-get_dot_gate) () const<br>_Gets the first dot gate connection._  |
|  const device\_structures::ConnectionSP | [**get\_gate**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-get_gate) () const<br>_Gets the first gate connection._  |
|  const device\_structures::ConnectionSP | [**get\_ohmic**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-get_ohmic) () const<br>_Gets the first ohmic connection._  |
|  const device\_structures::ConnectionSP | [**get\_plunger\_gate**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-get_plunger_gate) () const<br>_Gets the first plunger gate connection._  |
|  const device\_structures::ConnectionSP | [**get\_reservoir\_gate**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-get_reservoir_gate) () const<br>_Gets the first reservoir gate connection.._  |
|  const device\_structures::ConnectionSP | [**get\_screening\_gate**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-get_screening_gate) () const<br>_Gets the first screening gate connection._  |
|  bool | [**has\_barrier\_gate**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-has_barrier_gate) (const device\_structures::ConnectionSP & gate) const<br>_If this gate is a barriergate of this group or not._  |
|  bool | [**has\_gate**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-has_gate) (const device\_structures::ConnectionSP & gate) const<br>_If this gate is a member of this group or not._  |
|  bool | [**has\_ohmic**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-has_ohmic) (const device\_structures::ConnectionSP & ohmic) const<br>_If this ohmic is a member of this group or not._  |
|  bool | [**has\_plunger\_gate**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-has_plunger_gate) (const device\_structures::ConnectionSP & gate) const<br>_If this gate is a plungergate of this group or not._  |
|  bool | [**has\_reservoir\_gate**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-has_reservoir_gate) (const device\_structures::ConnectionSP & gate) const<br>_If this gate is a reservoirgate of this group or not._  |
|  bool | [**has\_screening\_gate**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-has_screening_gate) (const device\_structures::ConnectionSP & gate) const<br>_If this gate is a screeninggate of this group or not._  |
|  const device\_structures::ConnectionsSP & | [**ohmics**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-ohmics) () const<br>_The ohmics from the config._  |
|  bool | [**operator!=**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-operator) (const [**StandardConfigConnections**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md) & other) const<br> |
|  [**StandardConfigConnections**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md) & | [**operator=**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-operator_1) (const [**StandardConfigConnections**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md) & other) <br> |
|  bool | [**operator==**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-operator_2) (const [**StandardConfigConnections**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md) & other) const<br> |
|  const device\_structures::ConnectionsSP & | [**plunger\_gates**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-plunger_gates) () const<br>_The plunger gates from the config._  |
|  const device\_structures::ConnectionsSP & | [**reservoir\_gates**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-reservoir_gates) () const<br>_The reservoir gates from the config._  |
|  const device\_structures::ConnectionsSP & | [**screening\_gates**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-screening_gates) () const<br>_The screening gates from the config._  |


## Public Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  void | [**serialize**](classfalcon__core_1_1generic_1_1Song.md#function-serialize) (Archive &) <br>_cereal serialization interface. Override in derived classes._  |
|  std::string | [**to\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-to_json_string) () const<br>_Serialize this object to a JSON string._  |
| virtual  | [**~Song**](classfalcon__core_1_1generic_1_1Song.md#function-song) () = default<br> |






## Public Static Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; T &gt; | [**from\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-from_json_string) (const std::string & json) <br>_Deserialize an object from a JSON string._  |






























































## Protected Functions

| Type | Name |
| ---: | :--- |
|   | [**Config**](#function-config-33) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |


## Protected Functions inherited from falcon_core::physics::config::core::StandardConfigConnections

See [falcon\_core::physics::config::core::StandardConfigConnections](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md)

| Type | Name |
| ---: | :--- |
|   | [**StandardConfigConnections**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-standardconfigconnections-33) () <br> |
|  void | [**serialize**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-serialize) (Archive & ar) <br> |










## Public Functions Documentation




### function Config [1/3]

```C++
falcon_core::physics::config::core::Config::Config (
    const Config & other
) 
```




<hr>



### function Config [2/3]

_Constructs a new_ [_**Config**_](classfalcon__core_1_1physics_1_1config_1_1core_1_1Config.md) _object for falcon use._
```C++
falcon_core::physics::config::core::Config::Config (
    const device_structures::ConnectionsSP & screening_gates,
    const device_structures::ConnectionsSP & plunger_gates,
    const device_structures::ConnectionsSP & ohmics,
    const device_structures::ConnectionsSP & barrier_gates,
    const device_structures::ConnectionsSP & reservoir_gates,
    const generic::MapSP< autotuner_interfaces::names::Gname , Group > groups,
    const device_structures::ImpedancesSP & wiring_DC,
    const VoltageConstraintsSP & constriants
) 
```





**Parameters:**


* `screening_gates` The screening gates configuration. 
* `plunger_gates` The plunger gates configuration. 
* `ohmics` The ohmic contacts configuration. 
* `barrier_gates` The barrier gates configuration. 
* `reservoir_gates` The reservoir gates configuration. 
* `groups` A map of group names to [**Group**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Group.md) objects. 
* `wiring_DC` The DC wiring impedances. 
* `constriants` The voltage constraints configuration. 




        

<hr>



### function channels 

_Returns the channels of the config._ 
```C++
autotuner_interfaces::names::ChannelsSP falcon_core::physics::config::core::Config::channels () const
```




<hr>



### function check\_group\_consistency 

_Check that all groups are consistent._ 
```C++
void falcon_core::physics::config::core::Config::check_group_consistency () const
```



None of the gates or ohmics should be missing from the groups.




**Exception:**


* `std::runtime_error` if any of the groups are inconsistent. 




        

<hr>



### function check\_impedance\_consistency 

_Check that all impedances are consistent._ 
```C++
void falcon_core::physics::config::core::Config::check_impedance_consistency () const
```



None of the gates or ohmics should be missing from the impedances. 

**Exception:**


* `std::runtime_error` if any of the impedances are inconsistent. 




        

<hr>



### function compile\_channels 

_Searches through all_ [_**Group**_](classfalcon__core_1_1physics_1_1config_1_1core_1_1Group.md) _and collects all of the Channel._
```C++
void falcon_core::physics::config::core::Config::compile_channels () const
```




<hr>



### function generate\_gate\_relations 

_Returns the gate relations in the config._ 
```C++
device_structures::GateRelationsSP falcon_core::physics::config::core::Config::generate_gate_relations () const
```




<hr>



### function get\_all\_gnames 

_Returns all of the group names._ 
```C++
generic::ListSP< autotuner_interfaces::names::Gname > falcon_core::physics::config::core::Config::get_all_gnames () const
```




<hr>



### function get\_all\_groups 

_Returns all of the groups._ 
```C++
generic::ListSP< Group > falcon_core::physics::config::core::Config::get_all_groups () const
```




<hr>



### function get\_associated\_ohmic 

_Every reservoir gate has an associated ohmic._ 
```C++
device_structures::ConnectionSP falcon_core::physics::config::core::Config::get_associated_ohmic (
    const device_structures::ConnectionSP & reservoir_gate
) const
```



This pulls the associated ohmic from the config. 

**Parameters:**


* `reservoir_gate` The reservoir gate to find the associated ohmic for. 



**Returns:**

The ohmic associated with the reservoir gate. A nullptr if no match 





        

<hr>



### function get\_barrier\_gate\_dict 

_Returns barrier gates indexed by channel._ 
```C++
generic::MapSP< autotuner_interfaces::names::Channel , device_structures::Connections > falcon_core::physics::config::core::Config::get_barrier_gate_dict () const
```




<hr>



### function get\_channel\_barrier\_gates 

_Gets all of the barrier gates assocated with the selected current channel from the config._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_channel_barrier_gates (
    const autotuner_interfaces::names::ChannelSP & channel
) const
```





**Parameters:**


* `channel` The channel to find the gates for. 



**Returns:**

All of the gates of a gatetype assocated with the selected channel. Otherwise a nullptr if no match is found. 





        

<hr>



### function get\_channel\_dot\_gates 

_Gets all of the dot gates assocated with the selected current channel from the config._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_channel_dot_gates (
    const autotuner_interfaces::names::ChannelSP & channel
) const
```





**Parameters:**


* `channel` The channel to find the gates for. 



**Returns:**

All of the gates of a gatetype assocated with the selected channel. Otherwise a nullptr if no match is found. 





        

<hr>



### function get\_channel\_gates 

_Gets all of the gates assocated with the selected current channel from the config._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_channel_gates (
    const autotuner_interfaces::names::ChannelSP & channel
) const
```





**Parameters:**


* `channel` The channel to find the gates for. 
* `type` The gate type to find the gates for. 



**Returns:**

All of the gates of a gatetype assocated with the selected channel. Otherwise a nullptr if no match is found. 





        

<hr>



### function get\_channel\_ohmics 

_Gets all of the ohmics assocated with the selected current channel._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_channel_ohmics (
    const autotuner_interfaces::names::ChannelSP & channel
) const
```





**Parameters:**


* `channel` The channel to find the ohmics for. 



**Returns:**

All of the ohmics assocated with the selected channel. Otherwise a nullptr if no match is found. 





        

<hr>



### function get\_channel\_order\_no\_ohmics 

_Gets all of the gates in the order at the selected channel from the config with no ohmics._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_channel_order_no_ohmics (
    const autotuner_interfaces::names::ChannelSP & channel
) const
```





**Parameters:**


* `channel` The channel to find the gates for. 



**Returns:**

All of the gates in the order at the selected channel. Otherwise a nullptr 





        

<hr>



### function get\_channel\_plunger\_gates 

_Gets all of the plunger gates assocated with the selected current channel from the config._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_channel_plunger_gates (
    const autotuner_interfaces::names::ChannelSP & channel
) const
```





**Parameters:**


* `channel` The channel to find the gates for. 



**Returns:**

All of the gates of a gatetype assocated with the selected channel. Otherwise a nullptr if no match is found. 





        

<hr>



### function get\_channel\_reservoir\_gates 

_Gets all of the reservoir gates assocated with the selected current channel from the config._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_channel_reservoir_gates (
    const autotuner_interfaces::names::ChannelSP & channel
) const
```





**Parameters:**


* `channel` The channel to find the gates for. channel. Otherwise a nullptr if no match is found. 




        

<hr>



### function get\_channel\_screening\_gates 

_Gets all of the screening gates assocated with the selected current channel from the config._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_channel_screening_gates (
    const autotuner_interfaces::names::ChannelSP & channel
) const
```





**Parameters:**


* `channel` The channel to find the gates for. 



**Returns:**

All of the gates of a gatetype assocated with the selected channel. Otherwise a nullptr if no match is found. 





        

<hr>



### function get\_charge\_sense\_groups 

_Finds all of the arrays of dots that are charge sensors, i.e. only one quantum dot per channel._ 
```C++
generic::ListSP< autotuner_interfaces::names::Gname > falcon_core::physics::config::core::Config::get_charge_sense_groups () const
```





**Returns:**

A vector of gnames that are charge sensors. 





        

<hr>



### function get\_current\_channels 

_Gets all of the current channels from the config._ 
```C++
autotuner_interfaces::names::ChannelsSP falcon_core::physics::config::core::Config::get_current_channels () const
```





**Returns:**

All of the current channels from the config. 





        

<hr>



### function get\_dot\_channel\_neighbors 

_Gets the nearby neighbors of the selected gate in the dot channel._ 
```C++
std::pair< device_structures::ConnectionSP, device_structures::ConnectionSP > falcon_core::physics::config::core::Config::get_dot_channel_neighbors (
    const device_structures::ConnectionSP & dotgate
) const
```





**Parameters:**


* `dotgate` The gate of interest (must be in dot channel) 



**Returns:**

A pair of GateSP (left, right) if found, nullptr otherwise. 





        

<hr>



### function get\_dot\_gate\_dict 

_Returns dot gates indexed by channel._ 
```C++
generic::MapSP< autotuner_interfaces::names::Channel , device_structures::Connections > falcon_core::physics::config::core::Config::get_dot_gate_dict () const
```




<hr>



### function get\_dot\_number 

_Finds the number of dots associated with a current channel from the config._ 
```C++
int falcon_core::physics::config::core::Config::get_dot_number (
    const autotuner_interfaces::names::ChannelSP & channel
) const
```





**Parameters:**


* `channel` The channel to find the number of dots for. 



**Returns:**

The number of dots associated with the channel. A 0 if there is no match. 





        

<hr>



### function get\_gate\_dict 

_Returns gates indexed by channel._ 
```C++
generic::MapSP< autotuner_interfaces::names::Channel , device_structures::Connections > falcon_core::physics::config::core::Config::get_gate_dict () const
```




<hr>



### function get\_gname 

_Gets the associated Gname with a Channel if it exists._ 
```C++
autotuner_interfaces::names::GnameSP falcon_core::physics::config::core::Config::get_gname (
    const autotuner_interfaces::names::ChannelSP & channel
) const
```





**Parameters:**


* `channel` The channel to find the associated Gname for. 



**Returns:**

The Gname associated with the Channel. A nullptr if no match is found. 





        

<hr>



### function get\_group\_barrier\_gates 

_Gets all of the barrier gates assocated with the selected group from the config._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_group_barrier_gates (
    const autotuner_interfaces::names::GnameSP & gname
) const
```





**Parameters:**


* `gname` The group name to find the gates for. 



**Returns:**

All of the gates of a gatetype assocated with the selected group. Otherwise a nullptr if no match is found. 





        

<hr>



### function get\_group\_dot\_gates 

_Gets all of the dot gates assocated with the selected group from the config._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_group_dot_gates (
    const autotuner_interfaces::names::GnameSP & gname
) const
```





**Parameters:**


* `gname` The group name to find the gates for. 



**Returns:**

All of the gates of a gatetype assocated with the selected group. Otherwise a nullptr if no match is found. 





        

<hr>



### function get\_group\_gates 

_Gets all of the gates assocated with the selected group from the config._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_group_gates (
    const autotuner_interfaces::names::GnameSP & gname
) const
```





**Parameters:**


* `gname` The group name to find the gates for. 



**Returns:**

All of the gates of a gatetype assocated with the selected group. Otherwise a nullptr if no match is found. 





        

<hr>



### function get\_group\_plunger\_gates 

_Gets all of the plunger gates assocated with the selected group from the config._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_group_plunger_gates (
    const autotuner_interfaces::names::GnameSP & gname
) const
```





**Parameters:**


* `gname` The group name to find the gates for. 



**Returns:**

All of the gates of a gatetype assocated with the selected group. Otherwise a nullptr if no match is found. 





        

<hr>



### function get\_group\_reservoir\_gates 

_Gets all of the reservoir gates assocated with the selected group from the config._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_group_reservoir_gates (
    const autotuner_interfaces::names::GnameSP & gname
) const
```





**Parameters:**


* `gname` The group name to find the gates for. 



**Returns:**

All of the gates of a gatetype assocated with the selected group. Otherwise a nullptr if no match is found. 





        

<hr>



### function get\_group\_screening\_gates 

_Gets all of the screening gates assocated with the selected group from the config._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_group_screening_gates (
    const autotuner_interfaces::names::GnameSP & gname
) const
```





**Parameters:**


* `gname` The group name to find the gates for. 



**Returns:**

All of the gates of a gatetype assocated with the selected group. Otherwise a nullptr if no match is found. 





        

<hr>



### function get\_impedance 

_Returns the impedance matching the connection in teh dcwiring._ 
```C++
device_structures::ImpedanceSP falcon_core::physics::config::core::Config::get_impedance (
    const device_structures::ConnectionSP & connection
) const
```





**Returns:**

The impedance matching the connection in teh dcwiring. A nullptr if no match is found. 





        

<hr>



### function get\_isolated\_barrier\_gates 

_Task to find isolated barrier gates stored in the config._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_isolated_barrier_gates () const
```




<hr>



### function get\_isolated\_barrier\_gates\_by\_channel 

_Returns barrier gates indexed by channel which are unshared._ 
```C++
generic::MapSP< autotuner_interfaces::names::Channel , device_structures::Connections > falcon_core::physics::config::core::Config::get_isolated_barrier_gates_by_channel () const
```




<hr>



### function get\_isolated\_channel\_barrier\_gates 

_Finds the isolated barrier gates in the selected channel._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_isolated_channel_barrier_gates (
    const autotuner_interfaces::names::ChannelSP & channel
) const
```





**Parameters:**


* `channel` The channel of the device of interest. 



**Returns:**

ConnectionsSP list of all gates of the gatetype that are isolated in the selected channel. 





        

<hr>



### function get\_isolated\_channel\_dot\_gates 

_Finds the isolated dot gates in the selected channel._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_isolated_channel_dot_gates (
    const autotuner_interfaces::names::ChannelSP & channel
) const
```





**Parameters:**


* `channel` The channel of the device of interest. 



**Returns:**

DotGatesSP list of all gates of the gatetype that are isolated in the selected channel. 





        

<hr>



### function get\_isolated\_channel\_gates 

_Finds the isolated gates in the selected channel._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_isolated_channel_gates (
    const autotuner_interfaces::names::ChannelSP & channel
) const
```





**Parameters:**


* `channel` The channel of the device of interest. 



**Returns:**

GatesSP&lt;Gate&gt; list of all gates of the gatetype that are isolated in the selected channel. 





        

<hr>



### function get\_isolated\_channel\_plunger\_gates 

_Finds the isolated plunger gates in the selected channel._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_isolated_channel_plunger_gates (
    const autotuner_interfaces::names::ChannelSP & channel
) const
```





**Parameters:**


* `channel` The channel of the device of interest. 



**Returns:**

ConnectionsSP list of all gates of the gatetype that are isolated in the selected channel. 





        

<hr>



### function get\_isolated\_channel\_reservoir\_gates 

_Finds the isolated reservoir gates in the selected channel._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_isolated_channel_reservoir_gates (
    const autotuner_interfaces::names::ChannelSP & channel
) const
```





**Parameters:**


* `channel` The channel of the device of interest. 



**Returns:**

ConnectionsSP list of all gates of the gatetype that are isolated in the selected channel. 





        

<hr>



### function get\_isolated\_channel\_screening\_gates 

_Finds the isolated screening gates in the selected channel._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_isolated_channel_screening_gates (
    const autotuner_interfaces::names::ChannelSP & channel
) const
```





**Parameters:**


* `channel` The channel of the device of interest. 



**Returns:**

ConnectionsSP list of all gates of the gatetype that are isolated in the selected channel. 





        

<hr>



### function get\_isolated\_dot\_gates 

_Task to find isolated dot gates stored in the config._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_isolated_dot_gates () const
```




<hr>



### function get\_isolated\_dot\_gates\_by\_channel 

_Returns dot gates indexed by channel which are unshared._ 
```C++
generic::MapSP< autotuner_interfaces::names::Channel , device_structures::Connections > falcon_core::physics::config::core::Config::get_isolated_dot_gates_by_channel () const
```




<hr>



### function get\_isolated\_gates 

_Task to find isolated gates stored in the config._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_isolated_gates () const
```




<hr>



### function get\_isolated\_gates\_by\_channel 

_Returns gates indexed by channel which are unshared._ 
```C++
generic::MapSP< autotuner_interfaces::names::Channel , device_structures::Connections > falcon_core::physics::config::core::Config::get_isolated_gates_by_channel () const
```




<hr>



### function get\_isolated\_plunger\_gates 

_Task to find isolated plunger gates stored in the config._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_isolated_plunger_gates () const
```




<hr>



### function get\_isolated\_plunger\_gates\_by\_channel 

_Returns plunger gates indexed by channel which are unshared._ 
```C++
generic::MapSP< autotuner_interfaces::names::Channel , device_structures::Connections > falcon_core::physics::config::core::Config::get_isolated_plunger_gates_by_channel () const
```




<hr>



### function get\_isolated\_reservoir\_gates 

_Task to find isolated reservoir gates stored in the config._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_isolated_reservoir_gates () const
```




<hr>



### function get\_isolated\_reservoir\_gates\_by\_channel 

_Returns reservoir gates indexed by channel which are unshared._ 
```C++
generic::MapSP< autotuner_interfaces::names::Channel , device_structures::Connections > falcon_core::physics::config::core::Config::get_isolated_reservoir_gates_by_channel () const
```




<hr>



### function get\_isolated\_screening\_gates 

_Task to find isolated screening gates stored in the config._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_isolated_screening_gates () const
```




<hr>



### function get\_isolated\_screening\_gates\_by\_channel 

_Returns screening gates indexed by channel which are unshared._ 
```C++
generic::MapSP< autotuner_interfaces::names::Channel , device_structures::Connections > falcon_core::physics::config::core::Config::get_isolated_screening_gates_by_channel () const
```




<hr>



### function get\_num\_unique\_channels 

_Returns the number of unique channels associated with the current sample._ 
```C++
int falcon_core::physics::config::core::Config::get_num_unique_channels () const
```




<hr>



### function get\_plunger\_gate\_dict 

_Returns plunger gates indexed by channel._ 
```C++
generic::MapSP< autotuner_interfaces::names::Channel , device_structures::Connections > falcon_core::physics::config::core::Config::get_plunger_gate_dict () const
```




<hr>



### function get\_reservoir\_gate\_dict 

_Returns reservoir gates indexed by channel._ 
```C++
generic::MapSP< autotuner_interfaces::names::Channel , device_structures::Connections > falcon_core::physics::config::core::Config::get_reservoir_gate_dict () const
```




<hr>



### function get\_screening\_gate\_dict 

_Returns screening gates indexed by channel._ 
```C++
generic::MapSP< autotuner_interfaces::names::Channel , device_structures::Connections > falcon_core::physics::config::core::Config::get_screening_gate_dict () const
```




<hr>



### function get\_shared\_barrier\_gates 

_Task to find shared barrier gates stored in the config._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_shared_barrier_gates () const
```




<hr>



### function get\_shared\_channel\_barrier\_gates 

_Finds the shared barrier gates in the selected channel._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_shared_channel_barrier_gates (
    const autotuner_interfaces::names::ChannelSP & channel
) const
```





**Parameters:**


* `channel` The channel of the device of interest. 



**Returns:**

ConnectionsSP list of all gates of the gateytpe that are shared in the selected channel. 





        

<hr>



### function get\_shared\_channel\_dot\_gates 

_Finds the shared dot gates of the gatetype in the selected channel._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_shared_channel_dot_gates (
    const autotuner_interfaces::names::ChannelSP & channel
) const
```





**Parameters:**


* `channel` The channel of the device of interest. 



**Returns:**

DotGatesSP list of all gates of the gateytpe that are shared in the selected channel. 





        

<hr>



### function get\_shared\_channel\_gates 

_Finds the shared gates in the selected channel._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_shared_channel_gates (
    const autotuner_interfaces::names::ChannelSP & channel
) const
```





**Parameters:**


* `channel` The channel of the device of interest. 



**Returns:**

GatesSP&lt;Gate&gt; list of all gates of the gateytpe that are shared in the selected channel. 





        

<hr>



### function get\_shared\_channel\_plunger\_gates 

_Finds the shared plunger gates in the selected channel._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_shared_channel_plunger_gates (
    const autotuner_interfaces::names::ChannelSP & channel
) const
```





**Parameters:**


* `channel` The channel of the device of interest. 



**Returns:**

ConnectionsSP list of all gates of the gateytpe that are shared in the selected channel. 





        

<hr>



### function get\_shared\_channel\_reservoir\_gates 

_Finds the shared reservoir gates in the selected channel._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_shared_channel_reservoir_gates (
    const autotuner_interfaces::names::ChannelSP & channel
) const
```





**Parameters:**


* `channel` The channel of the device of interest. 



**Returns:**

ConnectionsSP list of all gates of the gateytpe that are shared in the selected channel. 





        

<hr>



### function get\_shared\_channel\_screening\_gates 

_Finds the shared screening gates in the selected channel._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_shared_channel_screening_gates (
    const autotuner_interfaces::names::ChannelSP & channel
) const
```





**Parameters:**


* `channel` The channel of the device of interest. 



**Returns:**

ConnectionsSP list of all gates of the gateytpe that are shared in the selected channel. 





        

<hr>



### function get\_shared\_dot\_gates 

_Task to find shared dot gates stored in the config._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_shared_dot_gates () const
```




<hr>



### function get\_shared\_gates 

_Task to find shared gates stored in the config._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_shared_gates () const
```




<hr>



### function get\_shared\_plunger\_gates 

_Task to find shared plunger gates stored in the config._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_shared_plunger_gates () const
```




<hr>



### function get\_shared\_reservoir\_gates 

_Task to find shared reservoir gates stored in the config._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_shared_reservoir_gates () const
```




<hr>



### function get\_shared\_screening\_gates 

_Task to find shared screening gates stored in the config._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Config::get_shared_screening_gates () const
```




<hr>



### function groups 

_Return the DC wiring impedances for the physical layout._ 
```C++
generic::MapSP< autotuner_interfaces::names::Gname , Group > falcon_core::physics::config::core::Config::groups () const
```




<hr>



### function has\_channel 

_Validates if this is a proper Channel name in the set of all device Channels._ 
```C++
bool falcon_core::physics::config::core::Config::has_channel (
    const autotuner_interfaces::names::ChannelSP & channel
) const
```





**Parameters:**


* `channel` The channel to validate. 



**Returns:**

true if the channel exists, false otherwise. 





        

<hr>



### function has\_gname 

_Validates if this is a proper gatename._ 
```C++
bool falcon_core::physics::config::core::Config::has_gname (
    const autotuner_interfaces::names::GnameSP & gname
) const
```





**Parameters:**


* `gname` The gname to validate. 



**Returns:**

true if the gname exists, false otherwise. 





        

<hr>



### function num\_unique\_channels 

_Returns the number of unique channels associated with the current sample._ 
```C++
int falcon_core::physics::config::core::Config::num_unique_channels () const
```




<hr>



### function ohmic\_in\_channel 

_Checks if the ohmic is connected to a channel._ 
```C++
bool falcon_core::physics::config::core::Config::ohmic_in_channel (
    const device_structures::ConnectionSP & ohmic,
    const autotuner_interfaces::names::ChannelSP &
) const
```





**Parameters:**


* `ohmic` The ohmic to diagnose. 
* `channel` The channel to check the ohmic against. 



**Returns:**

true if the ohmic is connected to the channel, false otherwise. 





        

<hr>



### function ohmic\_in\_charge\_sensor 

_If the ohmic is inside of a charge sensor channel._ 
```C++
bool falcon_core::physics::config::core::Config::ohmic_in_charge_sensor (
    const device_structures::ConnectionSP & ohmic
) const
```





**Parameters:**


* `ohmic` The ohmic to check 



**Returns:**

true if the ohmic is inside a charge sensor channel 





        

<hr>



### function operator!= 

```C++
bool falcon_core::physics::config::core::Config::operator!= (
    const Config & other
) const
```




<hr>



### function operator= 

```C++
Config & falcon_core::physics::config::core::Config::operator= (
    const Config & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::physics::config::core::Config::operator== (
    const Config & other
) const
```




<hr>



### function return\_channel\_from\_gate 

_Returns the channel a given gate belongs to. If the gate is in multiple channels, if will return the first channel if finds._ 
```C++
autotuner_interfaces::names::ChannelSP falcon_core::physics::config::core::Config::return_channel_from_gate (
    const device_structures::ConnectionSP & gate
) const
```





**Parameters:**


* `gate` The gate to find the channel for. 



**Returns:**

The channel the gate belongs to. A nullptr if no match is found. 





        

<hr>



### function return\_channels\_from\_gate 

_Returns all of the channels associated with a gate._ 
```C++
autotuner_interfaces::names::ChannelsSP falcon_core::physics::config::core::Config::return_channels_from_gate (
    const device_structures::ConnectionSP & gate
) const
```





**Parameters:**


* `gate` The gate to find the channels for. 



**Returns:**

All of the channels associated with a gate. Otherwise a nullptr if no match is found. 





        

<hr>



### function select\_group 

_Finds a group from the name and returns it._ 
```C++
GroupSP falcon_core::physics::config::core::Config::select_group (
    const autotuner_interfaces::names::GnameSP & gname
) const
```





**Parameters:**


* `gname` The name of the group to find. 



**Returns:**

The group matching the name. A nullptr if no match is found. 





        

<hr>



### function voltage\_constraints 

_Return the voltage constraints for the physical layout._ 
```C++
VoltageConstraintsSP falcon_core::physics::config::core::Config::voltage_constraints () const
```




<hr>



### function wiring\_DC 

_Returns the wiring impedances of the config._ 
```C++
device_structures::ImpedancesSP falcon_core::physics::config::core::Config::wiring_DC () const
```




<hr>
## Protected Functions Documentation




### function Config [3/3]

```C++
falcon_core::physics::config::core::Config::Config () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::physics::config::core::Config::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::physics::config::core::Config::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/physics/config/core/Config.hpp`

