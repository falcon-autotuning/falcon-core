
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <falcon_core/generic/Song.hpp>

namespace py = pybind11;
using namespace falcon_core::generic;

PYBIND11_MODULE(falcon_core, m) {
  py::module_ generic = m.def_submodule("generic");

  py::class_<Song, std::shared_ptr<Song>>(generic, "Song")
      .def("to_json_string", &Song::to_json_string)
      .def_static("from_json_string",
                  [](const std::string& json) {
                    return Song::from_json_string<Song>(json);
                  })
      .def("__eq__", &Song::operator==)
      .def("__ne__", &Song::operator!=);
}
