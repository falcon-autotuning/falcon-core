
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <falcon_core/physics/device_structures/Connection.hpp>

namespace py = pybind11;
using namespace falcon_core::physics::device_structures;

PYBIND11_MODULE(connection_pybind, m) {
  py::class_<Connection, std::shared_ptr<Connection>>(m, "Connection")
      .def("is_barrier_gate", &Connection::is_barrier_gate)
      .def("is_plunger_gate", &Connection::is_plunger_gate)
      .def("is_reservoir_gate", &Connection::is_reservoir_gate)
      .def("is_screening_gate", &Connection::is_screening_gate)
      .def("is_ohmic", &Connection::is_ohmic)
      .def("is_dot_gate", &Connection::is_dot_gate)
      .def("is_gate", &Connection::is_gate)
      .def_property_readonly("name", &Connection::name)
      .def_property_readonly("type", &Connection::type)
      .def("to_json_string",
           [](const Connection& self) { return self.to_json_string(); })
      .def(
          "__eq__",
          [](const Connection& self, const std::shared_ptr<Connection>& other) {
            return self == *other;
          })
      .def(
          "__ne__",
          [](const Connection& self, const std::shared_ptr<Connection>& other) {
            return self != *other;
          })
      .def_static("from_json_string", [](const std::string& json) {
        return Connection::from_json_string<Connection>(json);
      });
}
