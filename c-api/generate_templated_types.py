#!/usr/bin/env python3
import argparse
from enum import Enum
from pathlib import Path

parser = argparse.ArgumentParser()
parser.add_argument("--manifest", default="generated_template_manifest.txt")
args = parser.parse_args()
generated_file_manifest = Path.cwd() / str(args.manifest)
c_primitives = [
    "int",
    "float",
    "double",
    "bool",
    "char",
    "size_t",
    "StringHandle",
]


class Template:
    """Stores the information about the template like the name of the template,
    and the number of arguments that need to be supplied for templating."""

    name: str
    arguments: int

    def __init__(self, name: str, arguments: int):
        self.name = name
        self.arguments = arguments


class Options(Enum):
    """This is a generic type of cpp object that has functions to bind it to C"""

    List = Template("List", 4)
    Map = Template("Map", 9)
    Pair = Template("Pair", 7)
    FArray = Template("FArray", 3)
    Axes = Template("Axes", 4)
    LabelledArrays = Template("LabelledArrays", 4)
    InterpretationContainer = Template("InterpretationContainer", 4)


class HeaderContext:
    """Starts up the context for a header file.
    temp is the template that the header is based on.
    name is the name mangling add-on for the name to be unique in teh c-api
    path is the path from /c-api/falcon_core to the spot where the header will be created
    header_includes are any additional includes necessary for c imports.
    """

    def __init__(
        self,
        temp: Options,
        name: str,
        path: Path,
        header_includes: list[str],
    ):
        self.path = path
        self.temp = temp
        self.name = name
        self.header_includes = header_includes

    def mangled_name(self):
        """The template name mixed with the mangling string"""
        return self.temp.name + self.name

    def chandle(self):
        """The c handle for the mangled template class"""
        return self.mangled_name() + "Handle"

    def __enter__(self):
        self.file = open(self.path, "w")
        self.file.write('#pragma once\n#ifdef __cplusplus\n    extern "C" {\n#endif\n')
        for header in self.header_includes:
            self.file.write(f"#include {header}\n")
        self.file.write(
            f"\n// Forward declarations for opaque handles\n"
            f"typedef void* {self.temp.name}{self.name}Handle;\n"
            "// Function declarations\n"
        )
        return self.file

    def __exit__(self, exc_type, exc_val, exc_tb):
        self.file.write(f"""
// @category:read
FALCON_CORE_C_API StringHandle      {self.mangled_name()}_to_json_string({self.chandle()} handle);
// @category:allocation
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_from_json_string(StringHandle json);
""")
        self.file.write("\n#ifdef __cplusplus\n}\n#endif")
        self.file.close()


class ImplementationContext:
    """Starts up the context for a implementation file.
    temp is the template that the header is based on.
    name is the name mangling add-on for the name to be unique in teh c-api
    path is the path from /c-api/falcon_core to the spot where the header will be created
    impl_includes are any additional includes necessary for c imports.
    """

    def __init__(
        self,
        temp: Options,
        name: str,
        path: Path,
        header_path: Path,
        impl_includes: list[str],
    ):
        self.path = path
        self.header_path = header_path
        self.temp = temp
        self.name = name
        self.impl_includes = impl_includes

    def mangled_name(self):
        """The template name mixed with the mangling string"""
        return self.temp.name + self.name

    def chandle(self):
        """The c handle for the mangled template class"""
        return self.mangled_name() + "Handle"

    def remove_leftmost(self, path: Path):
        parts = Path(path).parts
        return Path(*parts[1:])

    def __enter__(self):
        self.file = open(self.path, "w")
        self.file.write(
            f"#include <{self.remove_leftmost(self.path).parent}/{self.temp.name}.hpp>\n"
            f'#include "{self.remove_leftmost(self.header_path)}"\n'
            f'#include "falcon_core/Precompiled_c_api.h"\n'
            f'#include "falcon_core/export_c_api.h"\n'
        )
        for header in self.impl_includes:
            self.file.write(f"#include {header}\n")
        return self.file

    def __exit__(self, exc_type, exc_val, exc_tb):
        self.file.close()


class Entry:
    """A single entry that will become a pair of header and implementation files for the C-api. All fields need to be filled out.
    temp: The type of template we are evaluating
    combo: All the strings necessary to fill out the template
    header_includes: Any additional dependancies that must be included at the top of the header for C to load all the types
    implementation_includes: Any addtional dependancies that must be included at the top of the implementation for Cpp to load all the types. This is everythign after the "#include "
    file_path: The path to the header file from /c-api/falcon_core
    """

    temp: Options
    combo: list[str]
    header_includes: list[str]
    implementation_includes: list[str]
    header_path: Path
    implementation_path: Path

    def __init__(
        self,
        temp: Options,
        combo: list[str],
        header_includes: list[str],
        implementation_includes: list[str],
        file_path: Path,
    ):
        self.temp = temp
        self.combo = combo
        self.header_includes = header_includes
        self.header_includes.append('"falcon_core/generic/String_c_api.h"')
        self.implementation_includes = implementation_includes
        self.implementation_includes.append(
            '"falcon_core/generic/ErrorHandling_c_api.h"'
        )
        self.header_path = (
            "include/falcon_core" / file_path / str(self.mangled_name() + "_c_api.h")
        )
        self.implementation_path = (
            "src/falcon_core" / file_path / str(self.mangled_name() + "_c_api.cpp")
        )
        if len(combo) != temp.value.arguments:
            raise ValueError(
                f"Template of {temp.name} expected {temp.value.name} items but got {len(combo)} instead."
            )

    def name(self):
        """The mangling string for the name"""
        return self.combo[-1]

    def mangled_name(self):
        """The template name mixed with the mangling string"""
        return self.temp.name + self.name()

    def chandle(self):
        """The c handle for the mangled template class"""
        return self.mangled_name() + "Handle"

    def generate_header(self):
        match self.temp.name:
            case Options.List.name:
                self.generate_list_header()
            case Options.Map.name:
                self.generate_map_header()
            case Options.Pair.name:
                self.generate_pair_header()
            case Options.FArray.name:
                self.generate_farray_header()
            case Options.Axes.name:
                self.generate_axes_header()
            case Options.LabelledArrays.name:
                self.generate_labelled_arrays_header()
            case Options.InterpretationContainer.name:
                self.generate_interpretation_container_header()
            case _:
                raise ValueError("Bad template")

    def generate_implementation(self):
        match self.temp.name:
            case Options.List.name:
                self.generate_list_implementation()
            case Options.Map.name:
                self.generate_map_implementation()
            case Options.Pair.name:
                self.generate_pair_implementation()
            case Options.FArray.name:
                self.generate_farray_implementation()
            case Options.Axes.name:
                self.generate_axes_implementation()
            case Options.LabelledArrays.name:
                self.generate_labelled_arrays_implementation()
            case Options.InterpretationContainer.name:
                self.generate_interpretation_container_implementation()
            case _:
                raise ValueError("Bad template")

    def edit_header(self):
        """Opens context manager for header"""
        return HeaderContext(
            self.temp,
            self.name(),
            self.header_path,
            self.header_includes,
        )

    def edit_implementation(self):
        """Opens context manager for implementation"""
        return ImplementationContext(
            self.temp,
            self.name(),
            self.implementation_path,
            self.header_path,
            self.implementation_includes,
        )

    def from_cstring(self, cstr: str, cppstr: str) -> str:
        """Converts a cstring to a cpp string."""
        return f"std::string {cppstr}({cstr}->raw, {cstr}->length);"

    def to_cstring(self, cstr: str, cppstr: str) -> str:
        """Converts a cpp string to a cstring."""
        return f"StringHandle {cstr} = String_create({cppstr}.data(), {cppstr}.size());"

    def generate_list_header(self):
        c_type = self.combo[0]
        if c_type == "StringHandle" or (c_type in c_primitives):
            allocate_signature = f"""// @category:allocation
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_allocate(size_t count);"""
        else:
            allocate_signature = ""
        with self.edit_header() as f:
            f.write(f"""
// @category:allocation
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_create_empty();
// @category:allocation
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_copy({self.chandle()} handle);
{allocate_signature}
// @category:allocation
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_fill_value(size_t count, {c_type} value);
// @category:allocation
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_create({c_type}* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void {self.mangled_name()}_destroy({self.chandle()} handle);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_push_back({self.chandle()} handle, {c_type} value);
// @category:read
FALCON_CORE_C_API size_t {self.mangled_name()}_size({self.chandle()} handle);
// @category:read
FALCON_CORE_C_API bool {self.mangled_name()}_empty({self.chandle()} handle);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_erase_at({self.chandle()} handle, size_t idx);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_clear({self.chandle()} handle);
// @category:read
FALCON_CORE_C_API {c_type} {self.mangled_name()}_at({self.chandle()} handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t {self.mangled_name()}_items({self.chandle()} handle, {c_type}* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool {self.mangled_name()}_contains({self.chandle()} handle, {c_type} value);
// @category:read
FALCON_CORE_C_API size_t {self.mangled_name()}_index({self.chandle()} handle, {c_type} value);
// @category:read
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_intersection({self.chandle()} handle, {self.chandle()} other);
// @category:read
FALCON_CORE_C_API bool {self.mangled_name()}_equal({self.chandle()} handle, {self.chandle()} other);
// @category:read
FALCON_CORE_C_API bool {self.mangled_name()}_not_equal({self.chandle()} handle, {self.chandle()} other);
""")

    def generate_labelled_arrays_header(self):
        c_type = self.combo[0]
        # cpp_type = self.combo[1]
        with self.edit_header() as f:
            f.write(f"""
// @category:allocation
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_create(
    List{c_type} arrays);
// @category:allocation
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_copy({self.chandle()} handle);
// @category:deallocation
FALCON_CORE_C_API void {self.mangled_name()}_destroy(
    {self.chandle()} handle);
// @category:read
FALCON_CORE_C_API List{c_type} {self.mangled_name()}_arrays(
    {self.chandle()} handle);
// @category:read
FALCON_CORE_C_API ListAcquisitionContextHandle {self.mangled_name()}_labels(
    {self.chandle()} handle);
// @category:read
FALCON_CORE_C_API bool {self.mangled_name()}_is_control_arrays(
    {self.chandle()} handle);
// @category:read
FALCON_CORE_C_API bool {self.mangled_name()}_is_measured_arrays(
    {self.chandle()} handle);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_push_back(
    {self.chandle()} handle,
    {c_type} value);
// @category:read
FALCON_CORE_C_API size_t {self.mangled_name()}_size(
    {self.chandle()} handle);
// @category:read
FALCON_CORE_C_API bool {self.mangled_name()}_empty(
    {self.chandle()} handle);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_erase_at(
    {self.chandle()} handle, size_t idx);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_clear(
    {self.chandle()} handle);
// @category:read
FALCON_CORE_C_API {c_type} {self.mangled_name()}_at(
    {self.chandle()} handle, size_t idx);
// @category:read
FALCON_CORE_C_API bool {self.mangled_name()}_contains(
    {self.chandle()} handle,
    {c_type} value);
// @category:read
FALCON_CORE_C_API size_t {self.mangled_name()}_index(
    {self.chandle()} handle,
    {c_type} value);
// @category:read
FALCON_CORE_C_API {self.chandle()}
{self.mangled_name()}_intersection(
    {self.chandle()} handle,
    {self.chandle()} other);
// @category:read
FALCON_CORE_C_API bool {self.mangled_name()}_equal(
    {self.chandle()} handle,
    {self.chandle()} other);
// @category:read
FALCON_CORE_C_API bool {self.mangled_name()}_not_equal(
    {self.chandle()} handle,
    {self.chandle()} other);
""")

    def generate_interpretation_container_header(self):
        c_value_type = self.combo[0]
        # value_name = self.combo[2]
        with self.edit_header() as f:
            f.write(f"""
// @category:allocation
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_create(MapInterpretationContext{self.name()}Handle contextDoubleMap);
// @category:allocation
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_copy({self.chandle()} handle);
// @category:deallocation
FALCON_CORE_C_API void {self.mangled_name()}_destroy({self.chandle()} handle);
// @category:read
FALCON_CORE_C_API SymbolUnitHandle {self.mangled_name()}_unit(
     {self.chandle()} handle);
// @category:read
FALCON_CORE_C_API ListInterpretationContextHandle {self.mangled_name()}_select_by_connection(
    {self.chandle()} handle, ConnectionHandle connection);
// @category:read
FALCON_CORE_C_API ListInterpretationContextHandle {self.mangled_name()}_select_by_connections(
                    {self.chandle()} handle, ConnectionsHandle connections);
// @category:read
FALCON_CORE_C_API ListInterpretationContextHandle {self.mangled_name()}_select_by_independent_connection(
                    {self.chandle()} handle, ConnectionHandle connection);
// @category:read
FALCON_CORE_C_API ListInterpretationContextHandle {self.mangled_name()}_select_by_dependent_connection(
                    {self.chandle()} handle, ConnectionHandle connection);
// @category:read
FALCON_CORE_C_API ListInterpretationContextHandle {self.mangled_name()}_select_contexts(
    {self.chandle()} handle,
    ListConnectionHandle                independent_connections,
    ListConnectionHandle                dependent_connections);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_insert_or_assign({self.chandle()} handle,
     InterpretationContextHandle   key,
     {c_value_type} value);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_insert(
    {self.chandle()} handle,
     InterpretationContextHandle   key,
     {c_value_type} value);
// @category:read
FALCON_CORE_C_API {c_value_type} {self.mangled_name()}_at({self.chandle()} handle,
     InterpretationContextHandle   key);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_erase({self.chandle()} handle,
     InterpretationContextHandle   key);
// @category:read
FALCON_CORE_C_API size_t {self.mangled_name()}_size({self.chandle()} handle);
// @category:read
FALCON_CORE_C_API bool {self.mangled_name()}_empty({self.chandle()} handle);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_clear({self.chandle()} handle);
// @category:read
FALCON_CORE_C_API bool {self.mangled_name()}_contains({self.chandle()} handle,
     InterpretationContextHandle   key);
// @category:read
FALCON_CORE_C_API ListInterpretationContextHandle {self.mangled_name()}_keys(
                    {self.chandle()} handle);
// @category:read
FALCON_CORE_C_API List{self.name()}Handle {self.mangled_name()}_values({self.chandle()} handle);
// @category:read
FALCON_CORE_C_API ListPairInterpretationContext{self.name()}Handle {self.mangled_name()}_items(
                    {self.chandle()} handle);
// @category:read
FALCON_CORE_C_API bool {self.mangled_name()}_equal({self.chandle()} handle,{self.chandle()} other);
// @category:read
FALCON_CORE_C_API bool {self.mangled_name()}_not_equal({self.chandle()} handle,{self.chandle()} other);
""")

    def generate_axes_header(self):
        c_type = self.combo[0]
        with self.edit_header() as f:
            f.write(f"""
// @category:allocation
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_create_empty();
// @category:allocation
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_copy({self.chandle()} handle);
// @category:allocation
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_create(List{self.name()}Handle data);
// @category:deallocation
FALCON_CORE_C_API void {self.mangled_name()}_destroy({self.chandle()} handle);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_push_back({self.chandle()} handle, {c_type} value);
// @category:read
FALCON_CORE_C_API size_t {self.mangled_name()}_size({self.chandle()} handle);
// @category:read
FALCON_CORE_C_API bool {self.mangled_name()}_empty({self.chandle()} handle);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_erase_at({self.chandle()} handle, size_t idx);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_clear({self.chandle()} handle);
// @category:read
FALCON_CORE_C_API {c_type} {self.mangled_name()}_at({self.chandle()} handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t {self.mangled_name()}_items({self.chandle()} handle, {c_type}* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool {self.mangled_name()}_contains({self.chandle()} handle, {c_type} value);
// @category:read
FALCON_CORE_C_API size_t {self.mangled_name()}_index({self.chandle()} handle, {c_type} value);
// @category:read
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_intersection({self.chandle()} handle, {self.chandle()} other);
// @category:read
FALCON_CORE_C_API bool {self.mangled_name()}_equal({self.chandle()} handle, {self.chandle()} other);
// @category:read
FALCON_CORE_C_API bool {self.mangled_name()}_not_equal({self.chandle()} handle, {self.chandle()} other);
""")

    def generate_pair_header(self):
        c_type_1 = self.combo[0]
        c_type_2 = self.combo[3]
        with self.edit_header() as f:
            f.write(f"""
// @category:allocation
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_create({c_type_1} first, {c_type_2} second);
// @category:allocation
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_copy({self.chandle()} handle);
// @category:deallocation
FALCON_CORE_C_API void {self.mangled_name()}_destroy({self.chandle()} handle);
// @category:read
FALCON_CORE_C_API {c_type_1} {self.mangled_name()}_first({self.chandle()} handle);
// @category:read
FALCON_CORE_C_API {c_type_2} {self.mangled_name()}_second({self.chandle()} handle);
// @category:read
FALCON_CORE_C_API bool {self.mangled_name()}_equal({self.chandle()} handle, {self.chandle()} other);
// @category:read
FALCON_CORE_C_API bool {self.mangled_name()}_not_equal({self.chandle()} handle, {self.chandle()} other);""")

    def generate_farray_header(self):
        c_type = self.combo[0]
        # TODO: view and operator() are not wrapped
        with self.edit_header() as f:
            f.write(f"""
// @category:allocation
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_create_empty(const size_t* shape, size_t ndim);
// @category:allocation
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_copy({self.chandle()} handle);
// @category:allocation
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_create_zeros(const size_t* shape, size_t ndim);
// @category:allocation
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_from_shape(const size_t* shape, size_t ndim);
// @category:allocation
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_from_data(const {c_type}* data, const size_t* shape, size_t ndim);
// @category:deallocation
FALCON_CORE_C_API void {self.mangled_name()}_destroy({self.chandle()} handle);
// @category:read
FALCON_CORE_C_API size_t {self.mangled_name()}_size({self.chandle()} handle);
// @category:read
FALCON_CORE_C_API size_t {self.mangled_name()}_dimension({self.chandle()} handle);
// @category:read
FALCON_CORE_C_API size_t {self.mangled_name()}_shape({self.chandle()} handle,size_t* out_buffer, size_t ndim);
// @category:read
FALCON_CORE_C_API size_t {self.mangled_name()}_data({self.chandle()} handle, {c_type}* out_buffer, size_t numdata);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_plus_equals_farray({self.chandle()} handle, {self.chandle()} other);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_plus_equals_double({self.chandle()} handle, double other);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_plus_equals_int({self.chandle()} handle, int other);
// @category:read
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_plus_farray({self.chandle()} handle, {self.chandle()} other);
// @category:read
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_plus_double({self.chandle()} handle,  double other);
// @category:read
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_plus_int({self.chandle()} handle,  int other);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_minus_equals_farray({self.chandle()} handle, {self.chandle()} other);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_minus_equals_double({self.chandle()} handle,  double other);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_minus_equals_int({self.chandle()} handle,  int other);
// @category:read
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_minus_farray({self.chandle()} handle, {self.chandle()} other);
// @category:read
FALCON_CORE_C_API  {self.chandle()} {self.mangled_name()}_minus_double({self.chandle()} handle,  double other);
// @category:read
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_minus_int({self.chandle()} handle,  int other);
// @category:read
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_negation({self.chandle()} handle);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_times_equals_farray({self.chandle()} handle, {self.chandle()} other);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_times_equals_double({self.chandle()} handle,  double other);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_times_equals_int({self.chandle()} handle,  int other);
// @category:read
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_times_farray({self.chandle()} handle, {self.chandle()} other);
// @category:read
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_times_double({self.chandle()} handle,  double other);
// @category:read
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_times_int({self.chandle()} handle,  int other);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_divides_equals_farray({self.chandle()} handle, {self.chandle()} other);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_divides_equals_double({self.chandle()} handle,  double other);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_divides_equals_int({self.chandle()} handle,  int other);
// @category:read
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_divides_farray({self.chandle()} handle, {self.chandle()} other);
// @category:read
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_divides_double({self.chandle()} handle,  double other);
// @category:read
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_divides_int({self.chandle()} handle,  int other);
// @category:read
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_pow({self.chandle()} handle,  {c_type} other);
// @category:read
FALCON_CORE_C_API FArrayDoubleHandle {self.mangled_name()}_double_pow({self.chandle()} handle,  double other);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_pow_inplace({self.chandle()} handle,  {c_type} other);
// @category:read
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_abs({self.chandle()} handle);
// @category:read
FALCON_CORE_C_API {c_type} {self.mangled_name()}_min({self.chandle()} handle);
// @category:read
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_min_arraywise({self.chandle()} handle, {self.chandle()} other);
// @category:read
FALCON_CORE_C_API {c_type} {self.mangled_name()}_max({self.chandle()} handle);
// @category:read
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_max_arraywise({self.chandle()} handle, {self.chandle()} other);
// @category:read
FALCON_CORE_C_API bool {self.mangled_name()}_equal({self.chandle()} handle, {self.chandle()} other);
// @category:read
FALCON_CORE_C_API bool {self.mangled_name()}_not_equal({self.chandle()} handle, {self.chandle()} other);
// @category:read
FALCON_CORE_C_API bool {self.mangled_name()}_greater_than({self.chandle()} handle,  {c_type} value);
// @category:read
FALCON_CORE_C_API bool {self.mangled_name()}_less_than({self.chandle()} handle,  {c_type} value);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_remove_offset({self.chandle()} handle,  {c_type} offset);
// @category:read
FALCON_CORE_C_API {c_type} {self.mangled_name()}_sum({self.chandle()} handle);
// @category:read
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_reshape({self.chandle()} handle, const size_t* shape, size_t ndims);
// @category:read
FALCON_CORE_C_API ListListSizeTHandle {self.mangled_name()}_where({self.chandle()} handle,  {c_type} value);
// @category:read
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_flip({self.chandle()} handle, size_t axis);
// @category:read
FALCON_CORE_C_API size_t {self.mangled_name()}_full_gradient({self.chandle()} handle, {self.chandle()}* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_gradient({self.chandle()} handle, size_t axis);
// @category:read
FALCON_CORE_C_API double {self.mangled_name()}_get_sum_of_squares({self.chandle()} handle);
// @category:read
FALCON_CORE_C_API double {self.mangled_name()}_get_summed_diff_int_of_squares({self.chandle()} handle,  int other);
// @category:read
FALCON_CORE_C_API double {self.mangled_name()}_get_summed_diff_double_of_squares({self.chandle()} handle,  double other);
// @category:read
FALCON_CORE_C_API double {self.mangled_name()}_get_summed_diff_array_of_squares({self.chandle()} handle, {self.chandle()} other);""")

    def generate_map_header(self):
        c_key_type = self.combo[0]
        c_value_type = self.combo[3]
        key_name = self.combo[6]
        value_name = self.combo[7]
        name = self.combo[8]
        with self.edit_header() as f:
            f.write(f"""
// @category:allocation
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_create_empty();
// @category:allocation
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_copy({self.chandle()} handle);
// @category:allocation
FALCON_CORE_C_API {self.chandle()} {self.mangled_name()}_create(Pair{name}Handle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void {self.mangled_name()}_destroy({self.chandle()} handle);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_insert_or_assign({self.chandle()} handle, {c_key_type} key, {c_value_type} value);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_insert({self.chandle()} handle, {c_key_type} key, {c_value_type} value);
// @category:read
FALCON_CORE_C_API {c_value_type} {self.mangled_name()}_at({self.chandle()} handle, {c_key_type} key);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_erase({self.chandle()} handle, {c_key_type} key);
// @category:read
FALCON_CORE_C_API size_t {self.mangled_name()}_size({self.chandle()} handle);
// @category:read
FALCON_CORE_C_API bool {self.mangled_name()}_empty({self.chandle()} handle);
// @category:write
FALCON_CORE_C_API void {self.mangled_name()}_clear({self.chandle()} handle);
// @category:read
FALCON_CORE_C_API bool {self.mangled_name()}_contains({self.chandle()} handle, {c_key_type} key);
// @category:read
FALCON_CORE_C_API List{key_name}Handle {self.mangled_name()}_keys({self.chandle()} handle);
// @category:read
FALCON_CORE_C_API List{value_name}Handle {self.mangled_name()}_values({self.chandle()} handle);
// @category:read
FALCON_CORE_C_API  ListPair{name}Handle {self.mangled_name()}_items({self.chandle()} handle);
// @category:read
FALCON_CORE_C_API bool {self.mangled_name()}_equal({self.chandle()} handle, {self.chandle()} other);
// @category:read
FALCON_CORE_C_API bool {self.mangled_name()}_not_equal({self.chandle()} handle, {self.chandle()} other);""")

    def error_type_handling(self, type: str) -> str:
        if type == "bool":
            return "false"
        elif type == "size_t":
            return "0"
        elif type == "int":
            return "0"
        elif type == "float":
            return "0.0"
        elif type == "double":
            return "0.0"
        else:
            return "nullptr"

    def generate_list_implementation(self):
        c_type = self.combo[0]
        cpp_real = self.combo[1]
        cpp_stored = self.combo[2]
        is_primitive = c_type in c_primitives
        if c_type == "StringHandle":
            stored_fill_value = f"""
    if (!value) {{
    throw std::invalid_argument("Null string handle passed to {self.mangled_name()}_fill_value");
    }}
    {self.from_cstring("value", "stored_obj")}"""
            copy_to_out_buffer = """
    for (size_t i = 0; i < n; ++i) {
        auto str      = list->items()[i];
        out_buffer[i] = String_create(str.data(), str.size());
    }
"""
            from_allocate = f"""{self.chandle()} {self.mangled_name()}_allocate(size_t count) {{
    return new falcon_core::generic::ListSP<{cpp_real}>(std::make_shared<falcon_core::generic::List<{cpp_real}>>(count));
}}
"""
            stored_out_value = "return String_create(obj.data(), obj.size());"
            create_allocation = """
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(data[i]->raw);
    }
"""
        elif is_primitive:
            stored_fill_value = "auto stored_obj = value;"
            copy_to_out_buffer = "std::copy_n(list->items().begin(), n, out_buffer);"
            stored_out_value = "return obj;"
            create_allocation = "vec.insert(vec.end(), data, data + count);"
            from_allocate = f"""{self.chandle()} {self.mangled_name()}_allocate(size_t count) {{
    return new falcon_core::generic::ListSP<{cpp_real}>(std::make_shared<falcon_core::generic::List<{cpp_real}>>(count));
}}
"""
        else:
            from_allocate = ""
            stored_fill_value = f"""
    if (!value) {{
    throw std::invalid_argument("Null value passed to {self.mangled_name()}_fill_value");
    }}
    auto stored_obj = *static_cast<std::shared_ptr<{cpp_real}>*>(value);
    """
            copy_to_out_buffer = f"""
for (size_t i = 0; i < n; ++i) {{
    out_buffer[i] = new std::shared_ptr<{cpp_real}>(list->items()[i]);
}}"""
            stored_out_value = f"return new std::shared_ptr<{cpp_real}>(obj);"
            create_allocation = f"""    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {{
        vec.push_back(*static_cast<std::shared_ptr<{cpp_real}>*>(data[i])); 
    }}
"""
        with self.edit_implementation() as f:
            f.write(f"""
extern "C" {{
using MACROList{c_type}= falcon_core::generic::List<{cpp_real}>;
DEFINE_C_API_COPY_TEMPLATE({self.mangled_name()}, MACROList{c_type})
DEFINE_C_API_DESTROY_TEMPLATE({self.mangled_name()}, MACROList{c_type});
DEFINE_C_API_EQUAL_TEMPLATE({self.mangled_name()}, MACROList{c_type});
DEFINE_C_API_NOT_EQUAL_TEMPLATE({self.mangled_name()}, MACROList{c_type});
DEFINE_C_API_TO_JSON_TEMPLATE({self.mangled_name()}, MACROList{c_type});
DEFINE_C_API_FROM_JSON_TEMPLATE({self.mangled_name()}, MACROList{c_type});
{self.chandle()} {self.mangled_name()}_create_empty() {{
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<{cpp_real}>(std::make_shared<falcon_core::generic::List<{cpp_real}>>());
    FALCON_C_API_END(nullptr)
}}

{self.chandle()} {self.mangled_name()}_fill_value(size_t count, {c_type} value) {{
    FALCON_C_API_BEGIN
    {stored_fill_value}
    return new falcon_core::generic::ListSP<{cpp_real}>(
        std::make_shared<falcon_core::generic::List<{cpp_real}>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}}
 {from_allocate}

{self.chandle()} {self.mangled_name()}_create({c_type}* data, size_t count) {{
    FALCON_C_API_BEGIN
if (!data) {{
throw std::invalid_argument("Null data handle passed to {self.mangled_name()}_create");
}}
    std::vector<{cpp_stored}> vec;
    {create_allocation}
    return new falcon_core::generic::ListSP<{cpp_real}>(
        std::make_shared<falcon_core::generic::List<{cpp_real}>>(vec));
    FALCON_C_API_END(nullptr)
}}

size_t {self.mangled_name()}_size({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_size");
}}
    return (*static_cast<falcon_core::generic::ListSP<{cpp_real}>*>(handle))->size();
    FALCON_C_API_END(0)
}}

bool {self.mangled_name()}_empty({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_empty");
}}
    return (*static_cast<falcon_core::generic::ListSP<{cpp_real}>*>(handle))->empty();
    FALCON_C_API_END(false)
}}

void {self.mangled_name()}_erase_at({self.chandle()} handle, size_t idx) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_erase_at");
}}
    (*static_cast<falcon_core::generic::ListSP<{cpp_real}>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}}

void {self.mangled_name()}_clear({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_clear");
}}
    (*static_cast<falcon_core::generic::ListSP<{cpp_real}>*>(handle))->clear();
    FALCON_C_API_END()
}}

void {self.mangled_name()}_push_back({self.chandle()} handle, {c_type} value) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_push_back");
}}
    {stored_fill_value}
    (*static_cast<falcon_core::generic::ListSP<{cpp_real}>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}}

bool {self.mangled_name()}_contains({self.chandle()} handle, {c_type} value) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_contains");
}}
    {stored_fill_value}
    return (*static_cast<falcon_core::generic::ListSP<{cpp_real}>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}}

size_t {self.mangled_name()}_index({self.chandle()} handle, {c_type} value) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_index");
}}
    {stored_fill_value}
    return (*static_cast<falcon_core::generic::ListSP<{cpp_real}>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}}

size_t {self.mangled_name()}_items({self.chandle()} handle, {c_type}* out_buffer, size_t buffer_size) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_items");
}}
if (!out_buffer) {{
throw std::invalid_argument("Null output buffer passed to {self.mangled_name()}_items");
}}
    auto list = *static_cast<falcon_core::generic::ListSP<{cpp_real}>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    {copy_to_out_buffer}
    return n;
    FALCON_C_API_END(0)
}}

{c_type} {self.mangled_name()}_at({self.chandle()} handle, size_t idx) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_at");
}}
    auto obj = (*static_cast<falcon_core::generic::ListSP<{cpp_real}>*>(handle))->at(idx);
    {stored_out_value}
    FALCON_C_API_END({self.error_type_handling(c_type)})
}}

{self.chandle()} {self.mangled_name()}_intersection({self.chandle()} handle, {self.chandle()} other) {{
    FALCON_C_API_BEGIN
if (!handle || !other) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_intersection");
}}
    auto listA = *static_cast<falcon_core::generic::ListSP<{cpp_real}>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<{cpp_real}>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<{cpp_real}>(result);
    FALCON_C_API_END(nullptr)
}}
}}
""")

    def generate_labelled_arrays_implementation(self):
        c_type = self.combo[0]
        cpp_type = self.combo[1]
        with self.edit_implementation() as f:
            f.write(f"""
extern "C" {{
using MACROLabelledArrays{c_type}= falcon_core::math::arrays::LabelledArrays<{cpp_type}>;
DEFINE_C_API_COPY_TEMPLATE({self.mangled_name()}, MACROLabelledArrays{c_type})
DEFINE_C_API_DESTROY_TEMPLATE({self.mangled_name()}, MACROLabelledArrays{c_type});
DEFINE_C_API_EQUAL_TEMPLATE({self.mangled_name()}, MACROLabelledArrays{c_type});
DEFINE_C_API_NOT_EQUAL_TEMPLATE({self.mangled_name()}, MACROLabelledArrays{c_type});
DEFINE_C_API_TO_JSON_TEMPLATE({self.mangled_name()}, MACROLabelledArrays{c_type});
DEFINE_C_API_FROM_JSON_TEMPLATE({self.mangled_name()}, MACROLabelledArrays{c_type});

{self.chandle()} {self.mangled_name()}_create(
    List{c_type} arrays) {{
    FALCON_C_API_BEGIN
    if (!arrays) {{
    throw std::invalid_argument("Null arrays handle passed to {self.mangled_name()}_create");
    }}
    auto list = *static_cast<falcon_core::generic::ListSP<{cpp_type}>*>(arrays);
    return new falcon_core::math::arrays::LabelledArraysSP<{cpp_type}>(
        std::make_shared<falcon_core::math::arrays::LabelledArrays<{cpp_type}>>(list->items()));
    FALCON_C_API_END(nullptr)
}}

List{c_type} {self.mangled_name()}_arrays(
    {self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_arrays");
}}
    return new falcon_core::generic::ListSP<{cpp_type}>(
        std::make_shared<falcon_core::generic::List<{cpp_type}>>(
            (*static_cast<falcon_core::math::arrays::LabelledArraysSP<{cpp_type}>*>(
                handle))->items()));
    FALCON_C_API_END(nullptr)
}}

ListAcquisitionContextHandle {self.mangled_name()}_labels(
    {self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_labels");
}}
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>((*static_cast<falcon_core::math::arrays::LabelledArraysSP<{cpp_type}>*>(handle))->labels());
    FALCON_C_API_END(nullptr)
}}

bool {self.mangled_name()}_is_control_arrays(
    {self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_is_control_arrays");
}}
    return (*static_cast<falcon_core::math::arrays::LabelledArraysSP<{cpp_type}>*>(handle))->is_control_arrays();
    FALCON_C_API_END(false)
}}

bool {self.mangled_name()}_is_measured_arrays(
    {self.chandle()} handle) {{
    FALCON_C_API_BEGIN
    if (!handle) {{
    throw std::invalid_argument("Null handle passed to {self.mangled_name()}_is_measured_arrays");
    }}
    return (*static_cast<falcon_core::math::arrays::LabelledArraysSP<{cpp_type}>*>(handle))->is_measured_arrays();
    FALCON_C_API_END(false)
}}

{c_type} {self.mangled_name()}_at({self.chandle()} handle, size_t idx) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_at");
}}
    auto obj = (*static_cast<falcon_core::math::arrays::LabelledArraysSP<{cpp_type}>*>(handle))->at(idx);
    return new std::shared_ptr<{cpp_type}>(obj);
    FALCON_C_API_END({self.error_type_handling(c_type)})
}}

{self.chandle()} {self.mangled_name()}_intersection({self.chandle()} handle, {self.chandle()} other) {{
    FALCON_C_API_BEGIN
if (!handle || !other) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_intersection");
}}
    auto listA = *static_cast<falcon_core::math::arrays::LabelledArraysSP<{cpp_type}>*>(handle);
    auto listB = *static_cast<falcon_core::math::arrays::LabelledArraysSP<{cpp_type}>*>(other);
    falcon_core::generic::ListSP<{cpp_type}> result = listA->intersection(listB);
    return new falcon_core::math::arrays::LabelledArraysSP<{cpp_type}>(
        std::make_shared<falcon_core::math::arrays::LabelledArrays<{cpp_type}>>(
            result->items()));
    FALCON_C_API_END(nullptr)
}}

size_t {self.mangled_name()}_size({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_size");
}}
    return (*static_cast<falcon_core::math::arrays::LabelledArraysSP<{cpp_type}>*>(handle))->size();
    FALCON_C_API_END(0)
}}

bool {self.mangled_name()}_empty({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_empty");
}}
    return (*static_cast<falcon_core::math::arrays::LabelledArraysSP<{cpp_type}>*>(handle))->empty();
    FALCON_C_API_END(false)
}}

void {self.mangled_name()}_erase_at({self.chandle()} handle, size_t idx) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_erase_at");
}}
    (*static_cast<falcon_core::math::arrays::LabelledArraysSP<{cpp_type}>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}}

void {self.mangled_name()}_clear({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_clear");
}}
    (*static_cast<falcon_core::math::arrays::LabelledArraysSP<{cpp_type}>*>(handle))->clear();
    FALCON_C_API_END()
}}

void {self.mangled_name()}_push_back({self.chandle()} handle, {c_type} value) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_push_back");
}}
if (!value) {{
throw std::invalid_argument("Null value passed to {self.mangled_name()}_push_back");
}}
    auto stored_obj = {cpp_type}SP(*static_cast<{cpp_type}SP*>(value));
    (*static_cast<falcon_core::math::arrays::LabelledArraysSP<{cpp_type}>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}}

bool {self.mangled_name()}_contains({self.chandle()} handle, {c_type} value) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_contains");
}}
if (!value) {{
throw std::invalid_argument("Null value passed to {self.mangled_name()}_contains");
}}
    auto stored_obj = {cpp_type}SP(*static_cast<{cpp_type}SP*>(value));
    return (*static_cast<falcon_core::math::arrays::LabelledArraysSP<{cpp_type}>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}}

size_t {self.mangled_name()}_index({self.chandle()} handle, {c_type} value) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_index");
}}
if (!value) {{
throw std::invalid_argument("Null value passed to {self.mangled_name()}_index");
}}
    auto stored_obj = {cpp_type}SP(*static_cast<{cpp_type}SP*>(value));
    return (*static_cast<falcon_core::math::arrays::LabelledArraysSP<{cpp_type}>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}}
}}
""")

    def generate_axes_implementation(self):
        c_type = self.combo[0]
        cpp_real = self.combo[1]
        cpp_stored = self.combo[2]
        is_primitive = c_type in c_primitives
        if c_type == "StringHandle":
            stored_fill_value = f"""
            if (!value) {{
            throw std::invalid_argument("Null string handle passed to {self.mangled_name()}_fill_value");
            }}
            {self.from_cstring("value", "stored_obj")}"""
            copy_to_out_buffer = """
    for (size_t i = 0; i < n; ++i) {
        auto str      = list->items()[i];
        out_buffer[i] = String_create(str.data(), str.size());
    }
"""
            stored_out_value = "return String_create(obj.data(), obj.size());"
        elif is_primitive:
            stored_fill_value = "auto stored_obj = value;"
            copy_to_out_buffer = "std::copy_n(list->items().begin(), n, out_buffer);"
            stored_out_value = "return obj;"
        else:
            stored_fill_value = f"""
            if (!value) {{
            throw std::invalid_argument("Null value passed to {self.mangled_name()}_fill_value");
            }}
            auto stored_obj = *static_cast<std::shared_ptr<{cpp_real}>*>(value);"""
            copy_to_out_buffer = f"""
for (size_t i = 0; i < n; ++i) {{
    out_buffer[i] = new std::shared_ptr<{cpp_real}>(list->items()[i]);
}}"""
            stored_out_value = f"return new std::shared_ptr<{cpp_real}>(obj);"
        with self.edit_implementation() as f:
            f.write(f"""
extern "C" {{
using MACROAxes{c_type}= falcon_core::math::Axes<{cpp_real}>;
DEFINE_C_API_COPY_TEMPLATE({self.mangled_name()}, MACROAxes{c_type})
DEFINE_C_API_DESTROY_TEMPLATE({self.mangled_name()}, MACROAxes{c_type});
DEFINE_C_API_EQUAL_TEMPLATE({self.mangled_name()}, MACROAxes{c_type});
DEFINE_C_API_NOT_EQUAL_TEMPLATE({self.mangled_name()}, MACROAxes{c_type});
DEFINE_C_API_TO_JSON_TEMPLATE({self.mangled_name()}, MACROAxes{c_type});
DEFINE_C_API_FROM_JSON_TEMPLATE({self.mangled_name()}, MACROAxes{c_type});
{self.chandle()} {self.mangled_name()}_create_empty() {{
    FALCON_C_API_BEGIN
    return new falcon_core::math::AxesSP<{cpp_real}>(
        std::make_shared<falcon_core::math::Axes<{cpp_real}>>());
    FALCON_C_API_END(nullptr)
}}

{self.chandle()} {self.mangled_name()}_create(List{self.name()}Handle data) {{
    FALCON_C_API_BEGIN
if (!data) {{
throw std::invalid_argument("Null data handle passed to {self.mangled_name()}_create");
}}
    auto list = *static_cast<falcon_core::generic::ListSP<{cpp_real}>*>(data);
    return new falcon_core::math::AxesSP<{cpp_real}>(
            std::make_shared<falcon_core::math::Axes<{cpp_real}>>(list));
    FALCON_C_API_END(nullptr)
}}

size_t {self.mangled_name()}_size({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_size");
}}
    return (*static_cast<falcon_core::math::AxesSP<{cpp_real}>*>(handle))->size();
    FALCON_C_API_END(0)
}}

bool {self.mangled_name()}_empty({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_empty");
}}
    return (*static_cast<falcon_core::math::AxesSP<{cpp_real}>*>(handle))->empty();
    FALCON_C_API_END(false)
}}

void {self.mangled_name()}_erase_at({self.chandle()} handle, size_t idx) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_erase_at");
}}
    (*static_cast<falcon_core::math::AxesSP<{cpp_real}>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}}

void {self.mangled_name()}_clear({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_clear");
}}
    (*static_cast<falcon_core::math::AxesSP<{cpp_real}>*>(handle))->clear();
    FALCON_C_API_END()
}}

void {self.mangled_name()}_push_back({self.chandle()} handle, {c_type} value) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_push_back");
}}
    {stored_fill_value}
    (*static_cast<falcon_core::math::AxesSP<{cpp_real}>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}}

bool {self.mangled_name()}_contains({self.chandle()} handle, {c_type} value) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_contains");
}}
    {stored_fill_value}
    return (*static_cast<falcon_core::math::AxesSP<{cpp_real}>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}}

size_t {self.mangled_name()}_index({self.chandle()} handle, {c_type} value) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_index");
}}
    {stored_fill_value}
    return (*static_cast<falcon_core::math::AxesSP<{cpp_real}>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}}

size_t {self.mangled_name()}_items({self.chandle()} handle, {c_type}* out_buffer, size_t buffer_size) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_items");
}}
if (!out_buffer) {{
throw std::invalid_argument("Null output buffer passed to {self.mangled_name()}_items");
}}
    auto list = *static_cast<falcon_core::math::AxesSP<{cpp_real}>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    {copy_to_out_buffer}
    return n;
    FALCON_C_API_END(0)
}}

{c_type} {self.mangled_name()}_at({self.chandle()} handle, size_t idx) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_at");
}}
    auto obj = (*static_cast<falcon_core::math::AxesSP<{cpp_real}>*>(handle))->at(idx);
    {stored_out_value}
    FALCON_C_API_END({self.error_type_handling(c_type)})
}}

{self.chandle()} {self.mangled_name()}_intersection({self.chandle()} handle, {self.chandle()} other) {{
    FALCON_C_API_BEGIN
if (!handle || !other) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_intersection");
}}
    auto listA = *static_cast<falcon_core::math::AxesSP<{cpp_real}>*>(handle);
    auto listB = *static_cast<falcon_core::math::AxesSP<{cpp_real}>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::math::AxesSP<{cpp_real}>(std::make_shared<falcon_core::math::Axes<{cpp_real}>>(result));
    FALCON_C_API_END(nullptr)
}}
}}
""")

    def generate_pair_implementation(self):
        c_type_1 = self.combo[0]
        cpp_real_1 = self.combo[1]
        # cpp_stored_1 = self.combo[2]
        c_type_2 = self.combo[3]
        cpp_real_2 = self.combo[4]
        # cpp_stored_2 = self.combo[5]
        is_primitive_1 = c_type_1 in c_primitives
        is_primitive_2 = c_type_2 in c_primitives
        with self.edit_implementation() as f:
            if c_type_1 == "StringHandle":
                first_create_adjustment = f"""
                if (!first) {{
                throw std::invalid_argument("Null string handle passed to {self.mangled_name()}_create");
                }}
                {self.from_cstring("first", "first_obj")}"""
            elif is_primitive_1:
                first_create_adjustment = "auto first_obj = first;"
            else:
                first_create_adjustment = f"""
                if (!first) {{
                throw std::invalid_argument("Null value passed to {self.mangled_name()}_create");
                }}
                auto first_obj= *static_cast<std::shared_ptr<{cpp_real_1}>*>(first);"""
            if c_type_2 == "StringHandle":
                second_create_adjustment = f"""
                if (!second) {{
                throw std::invalid_argument("Null string handle passed to {self.mangled_name()}_create");
                }}
                {self.from_cstring("second", "second_obj")}"""
            elif is_primitive_2:
                second_create_adjustment = "auto second_obj = second;"
            else:
                second_create_adjustment = f"""
                if (!second) {{
                throw std::invalid_argument("Null value passed to {self.mangled_name()}_create");
                }}
                auto second_obj= *static_cast<std::shared_ptr<{cpp_real_2}>*>(second);"""
            # Generate first() function
            if c_type_1 == "StringHandle":
                first_return = f"""
std::string cppstring = (*static_cast<falcon_core::generic::PairSP<{cpp_real_1}, {cpp_real_2}>*>(handle))->first();
{self.to_cstring("cstr", "cppstring")}
return cstr;"""
            elif is_primitive_1:
                first_return = f"return (*static_cast<falcon_core::generic::PairSP<{cpp_real_1}, {cpp_real_2}>*>(handle))->first();"
            else:
                first_return = f"""auto pair = *static_cast<falcon_core::generic::PairSP<{cpp_real_1}, {cpp_real_2}>*>(handle);
    return new std::shared_ptr<{cpp_real_1}>(pair->first());"""

            # Generate second() function
            if c_type_2 == "StringHandle":
                second_return = f"""
std::string cppstring = (*static_cast<falcon_core::generic::PairSP<{cpp_real_1}, {cpp_real_2}>*>(handle))->second();
{self.to_cstring("cstr", "cppstring")}
return cstr;"""
            elif is_primitive_2:
                second_return = f"return (*static_cast<falcon_core::generic::PairSP<{cpp_real_1}, {cpp_real_2}>*>(handle))->second();"
            else:
                second_return = f"""auto pair = *static_cast<falcon_core::generic::PairSP<{cpp_real_1}, {cpp_real_2}>*>(handle);
    return new std::shared_ptr<{cpp_real_2}>(pair->second());"""

            # Write the complete implementation
            f.write(f"""
extern "C" {{
using MACROPair{c_type_1}{c_type_2} = falcon_core::generic::Pair<{cpp_real_1}, {cpp_real_2}>;
DEFINE_C_API_COPY_TEMPLATE({self.mangled_name()}, MACROPair{c_type_1}{c_type_2})
DEFINE_C_API_DESTROY_TEMPLATE({self.mangled_name()}, MACROPair{c_type_1}{c_type_2});
DEFINE_C_API_EQUAL_TEMPLATE({self.mangled_name()}, MACROPair{c_type_1}{c_type_2});
DEFINE_C_API_NOT_EQUAL_TEMPLATE({self.mangled_name()}, MACROPair{c_type_1}{c_type_2});
DEFINE_C_API_TO_JSON_TEMPLATE({self.mangled_name()}, MACROPair{c_type_1}{c_type_2});
DEFINE_C_API_FROM_JSON_TEMPLATE({self.mangled_name()}, MACROPair{c_type_1}{c_type_2});
{self.chandle()} {self.mangled_name()}_create({c_type_1} first, {c_type_2} second) {{
    FALCON_C_API_BEGIN
    {first_create_adjustment}
    {second_create_adjustment}
    return new falcon_core::generic::PairSP<{cpp_real_1}, {cpp_real_2}>(
        std::make_shared<falcon_core::generic::Pair<{cpp_real_1}, {cpp_real_2}>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}}

{c_type_1} {self.mangled_name()}_first({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_first");
}}
    {first_return}
    FALCON_C_API_END({self.error_type_handling(c_type_1)})
}}

{c_type_2} {self.mangled_name()}_second({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_second");
}}
    {second_return}
    FALCON_C_API_END({self.error_type_handling(c_type_2)})
}}
}}
""")

    def generate_interpretation_container_implementation(self):
        c_value_type = self.combo[0]
        cpp_value_type = self.combo[1]
        # value_name = self.combo[2]
        is_primitive = c_value_type in c_primitives
        if c_value_type == "StringHandle":
            set_proper_value = f"""
            if (!value) {{
            throw std::invalid_argument("Null string handle passed to {self.mangled_name()}_create");
                                        }}
            auto value_obj= std::string(value->raw, value->length);"""
            return_out_value = "return String_create(out.data(), out.size());"
        elif not is_primitive:
            set_proper_value = f"""
            if (!value) {{
            throw std::invalid_argument("Null value passed to {self.mangled_name()}_create");
            }}
            auto value_obj = *static_cast<{cpp_value_type}SP*>(value);"""
            return_out_value = f"""return new {cpp_value_type}SP(out);"""
        else:
            set_proper_value = """auto value_obj= value;"""
            return_out_value = "return out;"
        with self.edit_implementation() as f:
            f.write(f"""
extern "C" {{
using MACROInterpretationContainer{c_value_type}= falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<{cpp_value_type}>;
DEFINE_C_API_COPY_TEMPLATE({self.mangled_name()}, MACROInterpretationContainer{c_value_type})
DEFINE_C_API_DESTROY_TEMPLATE({self.mangled_name()}, MACROInterpretationContainer{c_value_type});
DEFINE_C_API_EQUAL_TEMPLATE({self.mangled_name()}, MACROInterpretationContainer{c_value_type});
DEFINE_C_API_NOT_EQUAL_TEMPLATE({self.mangled_name()}, MACROInterpretationContainer{c_value_type});
DEFINE_C_API_TO_JSON_TEMPLATE({self.mangled_name()}, MACROInterpretationContainer{c_value_type});
DEFINE_C_API_FROM_JSON_TEMPLATE({self.mangled_name()}, MACROInterpretationContainer{c_value_type});
{self.chandle()} {self.mangled_name()}_create(MapInterpretationContext{self.name()}Handle map) {{
    FALCON_C_API_BEGIN
if (!map) {{
throw std::invalid_argument("Null map handle passed to {self.mangled_name()}_create");
}}
    auto real_map = *static_cast<falcon_core::generic::MapSP<
        falcon_core::autotuner_interfaces::interpretations::InterpretationContext, {cpp_value_type}>*>(map);
    return new falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<{cpp_value_type}>(
        std::make_shared<falcon_core::autotuner_interfaces::interpretations::InterpretationContainer<{cpp_value_type}>>(real_map));
    FALCON_C_API_END(nullptr)
}}

SymbolUnitHandle {self.mangled_name()}_unit(
     {self.chandle()} handle) {{
    FALCON_C_API_BEGIN
     if (!handle) {{
     throw std::invalid_argument("Null handle passed to {self.mangled_name()}_unit");
     }}
    auto that= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<{cpp_value_type}>*>(handle);
    return new falcon_core::physics::units::SymbolUnitSP(that->unit());
    FALCON_C_API_END(nullptr)
}}

ListInterpretationContextHandle {self.mangled_name()}_select_by_connection(
    {self.chandle()} handle, ConnectionHandle connection) {{
    FALCON_C_API_BEGIN
    if (!handle) {{
    throw std::invalid_argument("Null handle passed to {self.mangled_name()}_select_by_connection");
    }}
    if (!connection) {{
    throw std::invalid_argument("Null connection handle passed to {self.mangled_name()}_select_by_connection");
    }}
    auto that= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<{cpp_value_type}>*>(handle);
    auto conn = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(connection);
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(that->select_by_connection(conn));
    FALCON_C_API_END(nullptr)
}}

ListInterpretationContextHandle {self.mangled_name()}_select_by_connections(
                    {self.chandle()} handle, ConnectionsHandle connections) {{
    FALCON_C_API_BEGIN
                    if (!handle) {{
                    throw std::invalid_argument("Null handle passed to {self.mangled_name()}_select_by_connections");
                    }}
                    if (!connections) {{
                    throw std::invalid_argument("Null connections handle passed to {self.mangled_name()}_select_by_connections");
                    }}
    auto that= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<{cpp_value_type}>*>(handle);
    auto conns = *static_cast<falcon_core::physics::device_structures::ConnectionsSP*>(connections);
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(that->select_by_connections(conns->items()));
    FALCON_C_API_END(nullptr)
}}

ListInterpretationContextHandle {self.mangled_name()}_select_by_independent_connection(
    {self.chandle()} handle, ConnectionHandle connection) {{
    FALCON_C_API_BEGIN
    if (!handle) {{
    throw std::invalid_argument("Null handle passed to {self.mangled_name()}_select_by_independent_connection");
    }}
    if (!connection) {{
    throw std::invalid_argument("Null connection handle passed to {self.mangled_name()}_select_by_independent_connection");
    }}
    auto that= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<{cpp_value_type}>*>(handle);
    auto conn = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(connection);
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(that->select_by_independent_connection(conn));
    FALCON_C_API_END(nullptr)
}}

ListInterpretationContextHandle {self.mangled_name()}_select_by_dependent_connection(
    {self.chandle()} handle, ConnectionHandle connection) {{
    FALCON_C_API_BEGIN
    if (!handle) {{
    throw std::invalid_argument("Null handle passed to {self.mangled_name()}_select_by_dependent_connection");
    }}
    if (!connection) {{
    throw std::invalid_argument("Null connection handle passed to {self.mangled_name()}_select_by_dependent_connection");
    }}
    auto that= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<{cpp_value_type}>*>(handle);
    auto conn = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(connection);
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(that->select_by_dependent_connection(conn));
    FALCON_C_API_END(nullptr)
}}

ListInterpretationContextHandle {self.mangled_name()}_select_contexts(
    {self.chandle()} handle,
    ListConnectionHandle                independent_connections,
    ListConnectionHandle                dependent_connections) {{
    FALCON_C_API_BEGIN
    if (!handle) {{
    throw std::invalid_argument("Null handle passed to {self.mangled_name()}_select_contexts");
    }}
    if (!independent_connections) {{
    throw std::invalid_argument("Null independent connections handle passed to {self.mangled_name()}_select_contexts");
    }}
    if (!dependent_connections) {{
    throw std::invalid_argument("Null dependent connections handle passed to {self.mangled_name()}_select_contexts");
    }}
    auto that= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<{cpp_value_type}>*>(handle);
    auto independents = *static_cast<falcon_core::generic::ListSP<
        falcon_core::physics::device_structures::Connection>*>(independent_connections);
    auto dependents = *static_cast<falcon_core::generic::ListSP<
        falcon_core::physics::device_structures::Connection>*>(dependent_connections);
    return new falcon_core::generic::ListSP<
        falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(
        that->select_contexts(independents, dependents));
    FALCON_C_API_END(nullptr)
}}

void {self.mangled_name()}_insert_or_assign({self.chandle()} handle,
     InterpretationContextHandle   key,
     {c_value_type} value) {{
    FALCON_C_API_BEGIN
    if (!handle) {{
    throw std::invalid_argument("Null handle passed to {self.mangled_name()}_insert_or_assign");
    }}
    if (!key) {{
    throw std::invalid_argument("Null key passed to {self.mangled_name()}_insert_or_assign");
    }}
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<{cpp_value_type}>*>(handle);
    auto context= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key); 
    {set_proper_value}
    that->insert_or_assign(context, value_obj);
    FALCON_C_API_END()
}}

void {self.mangled_name()}_insert(
    {self.chandle()} handle,
     InterpretationContextHandle   key,
     {c_value_type} value) {{
    FALCON_C_API_BEGIN
    if (!handle) {{
    throw std::invalid_argument("Null handle passed to {self.mangled_name()}_insert");
    }}
    if (!key) {{
    throw std::invalid_argument("Null key passed to {self.mangled_name()}_insert");
    }}
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<{cpp_value_type}>*>(handle);
    auto context= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key); 
    {set_proper_value}
    that->insert_or_assign(context, value_obj);
    FALCON_C_API_END()
}}

{c_value_type} {self.mangled_name()}_at({self.chandle()} handle,
     InterpretationContextHandle   key) {{
    FALCON_C_API_BEGIN
    if (!handle) {{
    throw std::invalid_argument("Null handle passed to {self.mangled_name()}_at");
    }}
    if (!key) {{
    throw std::invalid_argument("Null key passed to {self.mangled_name()}_at");
    }}
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<{cpp_value_type}>*>(handle);
    auto context= *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key); 
    auto out = that->at(context);
    {return_out_value}
    FALCON_C_API_END({self.error_type_handling(c_value_type)})
}}

void {self.mangled_name()}_erase({self.chandle()} handle,
     InterpretationContextHandle   key) {{
    FALCON_C_API_BEGIN
    if (!handle) {{
    throw std::invalid_argument("Null handle passed to {self.mangled_name()}_erase");
    }}
    if (!key) {{
    throw std::invalid_argument("Null key passed to {self.mangled_name()}_erase");
    }}
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<{cpp_value_type}>*>(handle);
    auto context = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key); 
    return that->erase(context);
    FALCON_C_API_END()
}}

size_t {self.mangled_name()}_size({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_size");
}}
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<{cpp_value_type}>*>(handle);
    return that->size();
    FALCON_C_API_END(0)
}}

bool {self.mangled_name()}_empty({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_empty");
}}
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<{cpp_value_type}>*>(handle);
    return that->empty();
    FALCON_C_API_END(false)
}}

void {self.mangled_name()}_clear({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_clear");
}}
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<{cpp_value_type}>*>(handle);
    that->clear();
    FALCON_C_API_END()
}}

bool {self.mangled_name()}_contains({self.chandle()} handle,
     InterpretationContextHandle   key) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_contains");
}}
if (!key) {{
throw std::invalid_argument("Null key passed to {self.mangled_name()}_contains");
}}
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<{cpp_value_type}>*>(handle);
    auto context = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key); 
    return that->contains(context);
    FALCON_C_API_END(false)
}}

ListInterpretationContextHandle {self.mangled_name()}_keys(
                    {self.chandle()} handle) {{
    FALCON_C_API_BEGIN
                    if (!handle) {{
                    throw std::invalid_argument("Null handle passed to {self.mangled_name()}_keys");
                    }}
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<{cpp_value_type}>*>(handle);
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(that->keys());
    FALCON_C_API_END(nullptr)
}}

List{self.name()}Handle {self.mangled_name()}_values({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_values");
}}
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<{cpp_value_type}>*>(handle);
    return new falcon_core::generic::ListSP<{cpp_value_type}>(that->values());
    FALCON_C_API_END(nullptr)
}}

ListPairInterpretationContext{self.name()}Handle {self.mangled_name()}_items(
                    {self.chandle()} handle) {{
    FALCON_C_API_BEGIN
                    if (!handle) {{
                    throw std::invalid_argument("Null handle passed to {self.mangled_name()}_items");
                    }}
    auto that = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContainerSP<{cpp_value_type}>*>(handle);
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,{cpp_value_type}>>(that->items());
    FALCON_C_API_END(nullptr)
}}
}}
""")

    def generate_map_implementation(self):
        c_key_type = self.combo[0]
        cpp_key_type = self.combo[1]
        # cpp_stored_key_type = self.combo[2]
        c_value_type = self.combo[3]
        cpp_value_type = self.combo[4]
        # cpp_stored_value_type = self.combo[5]
        key_name = self.combo[6]
        value_name = self.combo[7]
        name = self.combo[8]
        is_primitive_key = c_key_type in c_primitives
        is_primitive_value = c_value_type in c_primitives
        if c_key_type == "StringHandle":
            correct_key = f"""
            if (!key) {{
            throw std::invalid_argument("Null string handle passed to {self.mangled_name()}_at");
                                           }}
            auto correct_key = std::string(key->raw, key->length);"""
        elif not is_primitive_key:
            correct_key = f"""
            if (!key) {{
            throw std::invalid_argument("Null key passed to {self.mangled_name()}_at");
            }}
            auto correct_key = *static_cast<{cpp_key_type}SP*>(key);"""
        else:
            correct_key = """auto correct_key = key;"""
        if c_value_type == "StringHandle":
            correct_value = f"""
                if (!value) {{
                throw std::invalid_argument("Null string handle passed to {self.mangled_name()}_at");
                }}
                auto correct_value = std::string(value->raw, value->length);"""
            at_return = f"""
  auto string =
      (*static_cast<falcon_core::generic::MapSP<{cpp_key_type}, {cpp_value_type}>*>(handle))->at(correct_key);
  return String_create(string.data(), string.size());
            """
        elif not is_primitive_value:
            correct_value = f"""
            if (!value) {{
            throw std::invalid_argument("Null value passed to {self.mangled_name()}_at");
            }}
            auto correct_value = *static_cast<{cpp_value_type}SP*>(value);"""
            at_return = f"""return new {cpp_value_type}SP((*static_cast<falcon_core::generic::MapSP<{cpp_key_type},{cpp_value_type}>*>(handle))->at(correct_key));"""
        else:
            correct_value = """auto correct_value = value;"""
            at_return = f"""return (*static_cast<falcon_core::generic::MapSP<{cpp_key_type},{cpp_value_type}>*>(handle))->at(correct_key);"""
        with self.edit_implementation() as f:
            f.write(f"""
extern "C" {{
using MACROMap{c_key_type}{c_value_type} = falcon_core::generic::Map<{cpp_key_type}, {cpp_value_type}>;
DEFINE_C_API_COPY_TEMPLATE({self.mangled_name()}, MACROMap{c_key_type}{c_value_type})
DEFINE_C_API_DESTROY_TEMPLATE({self.mangled_name()}, MACROMap{c_key_type}{c_value_type});
DEFINE_C_API_EQUAL_TEMPLATE({self.mangled_name()}, MACROMap{c_key_type}{c_value_type});
DEFINE_C_API_NOT_EQUAL_TEMPLATE({self.mangled_name()}, MACROMap{c_key_type}{c_value_type});
DEFINE_C_API_TO_JSON_TEMPLATE({self.mangled_name()}, MACROMap{c_key_type}{c_value_type});
DEFINE_C_API_FROM_JSON_TEMPLATE({self.mangled_name()}, MACROMap{c_key_type}{c_value_type});

{self.chandle()} {self.mangled_name()}_create_empty() {{
    FALCON_C_API_BEGIN
    return new falcon_core::generic::MapSP<{cpp_key_type},{cpp_value_type}>(std::make_shared<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>>()); 
    FALCON_C_API_END(nullptr)
}}

{self.chandle()} {self.mangled_name()}_create( Pair{name}Handle* data, size_t count) {{
    FALCON_C_API_BEGIN
if (!data) {{
throw std::invalid_argument("Null data pointer passed to {self.mangled_name()}_create");
}}
    std::vector<falcon_core::generic::PairSP<{cpp_key_type},{cpp_value_type}>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {{
        vec.push_back(*static_cast<falcon_core::generic::PairSP<{cpp_key_type},{cpp_value_type}>*>(data[i]));
    }}
    return new falcon_core::generic::MapSP<{cpp_key_type}, {cpp_value_type}>(
        std::make_shared<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>>(vec));
    FALCON_C_API_END(nullptr)
}}

void {self.mangled_name()}_insert_or_assign({self.chandle()} handle,  {c_key_type} key,  {c_value_type} value) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_insert_or_assign");
}}
    {correct_key}
    {correct_value}
    (*static_cast<falcon_core::generic::MapSP<{cpp_key_type},{cpp_value_type}>*>(handle))->
        insert_or_assign(correct_key,correct_value);
    FALCON_C_API_END()
}}

void {self.mangled_name()}_insert({self.chandle()} handle,  {c_key_type} key,  {c_value_type} value) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_insert");
}}
    {correct_key}
    {correct_value}
    (*static_cast<falcon_core::generic::MapSP<{cpp_key_type},{cpp_value_type}>*>(handle))->
        insert(correct_key,correct_value);
    FALCON_C_API_END()
}}

{c_value_type} {self.mangled_name()}_at({self.chandle()} handle,  {c_key_type} key) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_at");
}}
    {correct_key}
    {at_return}
    FALCON_C_API_END({self.error_type_handling(c_value_type)})
}}

void {self.mangled_name()}_erase({self.chandle()} handle,  {c_key_type} key) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_erase");
}}
    {correct_key}
    return (*static_cast<falcon_core::generic::MapSP<{cpp_key_type},{cpp_value_type}>*>(handle))->
        erase(correct_key);
    FALCON_C_API_END()
}}

size_t {self.mangled_name()}_size({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_size");
}}
    return (*static_cast<falcon_core::generic::MapSP<{cpp_key_type},{cpp_value_type}>*>(handle))->
        size();
    FALCON_C_API_END(0)
}}

bool {self.mangled_name()}_empty({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_empty");
}}
    return (*static_cast<falcon_core::generic::MapSP<{cpp_key_type},{cpp_value_type}>*>(handle))->
        empty();
    FALCON_C_API_END(false)
}}

void {self.mangled_name()}_clear({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_clear");
}}
    return (*static_cast<falcon_core::generic::MapSP<{cpp_key_type},{cpp_value_type}>*>(handle))->
        clear();
    FALCON_C_API_END()
}}

bool {self.mangled_name()}_contains({self.chandle()} handle, {c_key_type} key) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_contains");
}}
    {correct_key}
    return (*static_cast<falcon_core::generic::MapSP<{cpp_key_type},{cpp_value_type}>*>(handle))->
        contains(correct_key);
    FALCON_C_API_END(false)
}}

List{key_name}Handle {self.mangled_name()}_keys({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_keys");
}}
    auto map = *static_cast<falcon_core::generic::MapSP<{cpp_key_type},{cpp_value_type}>*>(handle);
    return new falcon_core::generic::ListSP<{cpp_key_type}>(map->keys());
    FALCON_C_API_END(nullptr)
}}

List{value_name}Handle {self.mangled_name()}_values({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_values");
}}
    auto map = *static_cast<falcon_core::generic::MapSP<{cpp_key_type},{cpp_value_type}>*>(handle);
    return new falcon_core::generic::ListSP<{cpp_value_type}>(map->values());
    FALCON_C_API_END(nullptr)
}}

ListPair{name}Handle {self.mangled_name()}_items({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_items");
}}
    auto map = *static_cast<falcon_core::generic::MapSP<{cpp_key_type},{cpp_value_type}>*>(handle);
    falcon_core::generic::ListSP<falcon_core::generic::Pair<{cpp_key_type},{cpp_value_type}>> items_sp = map->items(); 
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<{cpp_key_type},{cpp_value_type}>>(items_sp);
    FALCON_C_API_END(nullptr)
}}
}}
""")

    def generate_farray_implementation(self):
        c_type = self.combo[0]
        cpp_type = self.combo[1]
        with self.edit_implementation() as f:
            f.write(f"""
extern "C" {{
using MACROFArray{c_type}= falcon_core::generic::FArray<{cpp_type}>;
DEFINE_C_API_COPY_TEMPLATE({self.mangled_name()}, MACROFArray{c_type})
DEFINE_C_API_DESTROY_TEMPLATE({self.mangled_name()}, MACROFArray{c_type});
DEFINE_C_API_EQUAL_TEMPLATE({self.mangled_name()}, MACROFArray{c_type});
DEFINE_C_API_NOT_EQUAL_TEMPLATE({self.mangled_name()}, MACROFArray{c_type});
DEFINE_C_API_TO_JSON_TEMPLATE({self.mangled_name()}, MACROFArray{c_type});
DEFINE_C_API_FROM_JSON_TEMPLATE({self.mangled_name()}, MACROFArray{c_type});
{self.chandle()} {self.mangled_name()}_create_empty(const size_t* shape, size_t ndim) {{
    FALCON_C_API_BEGIN
if (!shape) {{
throw std::invalid_argument("Null shape passed to {self.mangled_name()}_create_empty");
}}
    std::vector<size_t> vec;
    for (size_t i =0; i < ndim; ++i) {{
        vec.push_back(shape[i]);
    }}
    return new falcon_core::generic::FArraySP<{cpp_type}>(falcon_core::generic::FArray<{cpp_type}>::empty(vec));
    FALCON_C_API_END(nullptr)
}}

{self.chandle()} {self.mangled_name()}_create_zeros(const size_t* shape, size_t ndim) {{
    FALCON_C_API_BEGIN
if (!shape) {{
throw std::invalid_argument("Null shape passed to {self.mangled_name()}_create_zeros");
}}
    std::vector<size_t> vec;
    for (size_t i =0; i < ndim; ++i) {{
        vec.push_back(shape[i]);
    }}
    return new falcon_core::generic::FArraySP<{cpp_type}>(falcon_core::generic::FArray<{cpp_type}>::zeros(vec));
    FALCON_C_API_END(nullptr)
}}

{self.chandle()} {self.mangled_name()}_from_shape(const size_t* shape, size_t ndim) {{
    FALCON_C_API_BEGIN
if (!shape) {{
throw std::invalid_argument("Null shape passed to {self.mangled_name()}_from_shape");
}}
    std::vector<size_t> vec;
    for (size_t i =0; i < ndim; ++i) {{
        vec.push_back(shape[i]);
    }}
    return new falcon_core::generic::FArraySP<{cpp_type}>(std::make_shared<falcon_core::generic::FArray<{cpp_type}>>(vec));
    FALCON_C_API_END(nullptr)
}}

{self.chandle()} {self.mangled_name()}_from_data(const {c_type}* data, const size_t* shape, size_t ndim) {{
    FALCON_C_API_BEGIN
if (!data) {{
throw std::invalid_argument("Null data passed to {self.mangled_name()}_from_data");
}}
if (!shape) {{
throw std::invalid_argument("Null shape passed to {self.mangled_name()}_from_data");
}}
  std::vector<std::vector<{cpp_type}>::size_type> shapeVec;
  size_t                                      total_size = 1;
  for (size_t i = 0; i < ndim; ++i) {{
    shapeVec.push_back(shape[i]);
    total_size *= shape[i];
  }}
  xt::xarray<{cpp_type}> arr =
      xt::adapt(data, total_size, xt::no_ownership(), shapeVec);
    return new falcon_core::generic::FArraySP<{cpp_type}>(std::make_shared<falcon_core::generic::FArray<{cpp_type}>>(arr));
    FALCON_C_API_END(nullptr)
}}

size_t {self.mangled_name()}_size({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_size");
}}
    auto farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    return farray->size();
    FALCON_C_API_END(0)
}}

size_t {self.mangled_name()}_dimension({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_dimension");
}}
    auto farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    return farray->dimension();
    FALCON_C_API_END(0)
}}

size_t {self.mangled_name()}_shape({self.chandle()} handle, size_t* out_buffer, size_t ndim) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_shape");
}}
if (!out_buffer) {{
throw std::invalid_argument("Null out_buffer passed to {self.mangled_name()}_shape");
}}
    auto farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    auto shape = farray->shape();
    size_t count   = shape.size();
    size_t to_copy = (ndim < count) ? ndim : count;
    for (size_t i = 0; i < to_copy; ++i) {{
        out_buffer[i] = shape[i];
    }}
    return to_copy;
    FALCON_C_API_END(0)
}}

size_t {self.mangled_name()}_data({self.chandle()} handle, {c_type}* out_buffer, size_t numdata) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_data");
}}
if (!out_buffer) {{
throw std::invalid_argument("Null out_buffer passed to {self.mangled_name()}_shape");
}}
    auto farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    if (farray->size() > numdata) {{
    throw std::runtime_error(
        std::string("Trying to store more datapoints than buffer allocated.") +
        "The buffer has " + std::to_string(numdata) +
        " elements, but the FArray has " + std::to_string(farray->size()) +
        " elements.");
    }}
    memcpy(out_buffer, farray->raw_data(), farray->size() * sizeof({c_type}));
    return farray->size();
    FALCON_C_API_END(0)
}}
 
void {self.mangled_name()}_plus_equals_farray({self.chandle()} handle, {self.chandle()} other) {{
    FALCON_C_API_BEGIN
if (!handle || !other) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_plus_equals_farray");
}}
    auto farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    auto oarray= *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(other);
    *farray += *oarray;
    FALCON_C_API_END()
}}

void {self.mangled_name()}_plus_equals_double({self.chandle()} handle,  double other) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_plus_equals_double");
}}
    auto farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    *farray += other;
    FALCON_C_API_END()
}}

void {self.mangled_name()}_plus_equals_int({self.chandle()} handle,  int other) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_plus_equals_int");
}}
    auto farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    *farray += other;
    FALCON_C_API_END()
}}

{self.chandle()} {self.mangled_name()}_plus_farray({self.chandle()} handle, {self.chandle()} other) {{
    FALCON_C_API_BEGIN
if (!handle || !other) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_plus_farray");
}}
    auto farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    auto oarray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(other);
    return new falcon_core::generic::FArraySP<{cpp_type}>(*farray + oarray);
    FALCON_C_API_END(nullptr)
}}

{self.chandle()} {self.mangled_name()}_plus_double({self.chandle()} handle,  double other) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_plus_double");
}}
    auto farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArraySP<{cpp_type}>(*farray + other);
    FALCON_C_API_END(nullptr)
}}

{self.chandle()} {self.mangled_name()}_plus_int({self.chandle()} handle,  int other) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_plus_int");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArraySP<{cpp_type}>(*farray + other);
    FALCON_C_API_END(nullptr)
}}

void {self.mangled_name()}_minus_equals_farray({self.chandle()} handle, {self.chandle()} other) {{
    FALCON_C_API_BEGIN
if (!handle || !other) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_minus_equals_farray");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    auto oarray= *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(other);
    *farray -= *oarray;
    FALCON_C_API_END()
}}

void {self.mangled_name()}_minus_equals_double({self.chandle()} handle,  double other) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_minus_equals_double");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    *farray -= other;
    FALCON_C_API_END()
}}

void {self.mangled_name()}_minus_equals_int({self.chandle()} handle,  int other) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_minus_equals_int");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    *farray -= other;
    FALCON_C_API_END()
}}

{self.chandle()} {self.mangled_name()}_minus_farray({self.chandle()} handle, {self.chandle()} other) {{
    FALCON_C_API_BEGIN
if (!handle || !other) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_minus_farray");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    auto oarray= *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(other);
    return new falcon_core::generic::FArraySP<{cpp_type}>(*farray - oarray);
    FALCON_C_API_END(nullptr)
}}

{self.chandle()} {self.mangled_name()}_minus_double({self.chandle()} handle,  double other) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_minus_double");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArraySP<{cpp_type}>(*farray - other);
    FALCON_C_API_END(nullptr)
}}

{self.chandle()} {self.mangled_name()}_minus_int({self.chandle()} handle,  int other) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_minus_int");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArraySP<{cpp_type}>(*farray - other);
    FALCON_C_API_END(nullptr)
}}

{self.chandle()} {self.mangled_name()}_negation({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_negation");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArraySP<{cpp_type}>(-*farray);
    FALCON_C_API_END(nullptr)
}}

void {self.mangled_name()}_times_equals_farray({self.chandle()} handle, {self.chandle()} other) {{
    FALCON_C_API_BEGIN
if (!handle || !other) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_times_equals_farray");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    auto oarray= *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(other);
    *farray *= *oarray;
    FALCON_C_API_END()
}}

void {self.mangled_name()}_times_equals_double({self.chandle()} handle,  double other) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_times_equals_double");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    *farray *= other;
    FALCON_C_API_END()
}}

void {self.mangled_name()}_times_equals_int({self.chandle()} handle,  int other) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_times_equals_int");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    *farray *= other;
    FALCON_C_API_END()
}}

{self.chandle()} {self.mangled_name()}_times_farray({self.chandle()} handle, {self.chandle()} other) {{
    FALCON_C_API_BEGIN
if (!handle || !other) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_times_farray");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    auto oarray= *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(other);
    return new falcon_core::generic::FArraySP<{cpp_type}>(*farray * oarray);
    FALCON_C_API_END(nullptr)
}}

{self.chandle()} {self.mangled_name()}_times_double({self.chandle()} handle,  double other) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_times_double");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArraySP<{cpp_type}>(*farray * other);
    FALCON_C_API_END(nullptr)
}}

{self.chandle()} {self.mangled_name()}_times_int({self.chandle()} handle,  int other) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_times_int");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArraySP<{cpp_type}>(*farray * other);
    FALCON_C_API_END(nullptr)
}}

void {self.mangled_name()}_divides_equals_farray({self.chandle()} handle, {self.chandle()} other) {{
    FALCON_C_API_BEGIN
if (!handle || !other) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_divides_equals_farray");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    auto oarray= *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(other);
    *farray /= *oarray;
    FALCON_C_API_END()
}}

void {self.mangled_name()}_divides_equals_double({self.chandle()} handle,  double other) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_divides_equals_double");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    *farray /= other;
    FALCON_C_API_END()
}}

void {self.mangled_name()}_divides_equals_int({self.chandle()} handle,  int other) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_divides_equals_int");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    *farray /= other;
    FALCON_C_API_END()
}}

{self.chandle()} {self.mangled_name()}_divides_farray({self.chandle()} handle, {self.chandle()} other) {{
    FALCON_C_API_BEGIN
if (!handle || !other) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_divides_farray");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    auto oarray= *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(other);
    return new falcon_core::generic::FArraySP<{cpp_type}>(*farray / oarray);
    FALCON_C_API_END(nullptr)
}}

{self.chandle()} {self.mangled_name()}_divides_double({self.chandle()} handle,  double other) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_divides_double");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArraySP<{cpp_type}>(*farray / other);
    FALCON_C_API_END(nullptr)
}}

{self.chandle()} {self.mangled_name()}_divides_int({self.chandle()} handle,  int other) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_divides_int");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArraySP<{cpp_type}>(*farray / other);
    FALCON_C_API_END(nullptr)
}}

{self.chandle()} {self.mangled_name()}_pow({self.chandle()} handle,  {c_type} other) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_pow");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArraySP<{cpp_type}>(*farray ^ other);
    FALCON_C_API_END(nullptr)
}}

FArrayDoubleHandle {self.mangled_name()}_double_pow({self.chandle()} handle,  double other) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_pow");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArraySP<double>(*farray ^ other);
    FALCON_C_API_END(nullptr)
}}

void {self.mangled_name()}_pow_inplace({self.chandle()} handle,  {c_type} other) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_pow");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    farray->pow_inplace(other);
    FALCON_C_API_END()
}}

{self.chandle()} {self.mangled_name()}_abs({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_abs");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArraySP<{cpp_type}>(farray->abs());
    FALCON_C_API_END(nullptr)
}}

{c_type} {self.mangled_name()}_min({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_min");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    return farray->min();
    FALCON_C_API_END({self.error_type_handling(c_type)})
}}

{self.chandle()} {self.mangled_name()}_min_arraywise({self.chandle()} handle, {self.chandle()} other) {{
    FALCON_C_API_BEGIN
if (!handle || !other) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_min_arraywise");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    auto oarray= *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(other);
    return new falcon_core::generic::FArraySP<{cpp_type}>(farray->min(oarray));
    FALCON_C_API_END(nullptr)
}}

{c_type} {self.mangled_name()}_max({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_max");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    return farray->max();
    FALCON_C_API_END({self.error_type_handling(c_type)})
}}

{self.chandle()} {self.mangled_name()}_max_arraywise({self.chandle()} handle, {self.chandle()} other) {{
    FALCON_C_API_BEGIN
if (!handle || !other) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_max_arraywise");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    auto oarray= *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(other);
    return new falcon_core::generic::FArraySP<{cpp_type}>(farray->max(oarray));
    FALCON_C_API_END(nullptr)
}}

bool {self.mangled_name()}_greater_than({self.chandle()} handle,  {c_type} value) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_greater_than");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    return *farray > value;
    FALCON_C_API_END(false)
}}

bool {self.mangled_name()}_less_than({self.chandle()} handle,  {c_type} value) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_less_than");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    return *farray < value;
    FALCON_C_API_END(false)
}}

void {self.mangled_name()}_remove_offset({self.chandle()} handle,  {c_type} offset) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_remove_offset");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    farray->remove_offset(offset);
    FALCON_C_API_END()
}}

{c_type} {self.mangled_name()}_sum({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_sum");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    return farray->sum();
    FALCON_C_API_END({self.error_type_handling(c_type)})
}}

{self.chandle()} {self.mangled_name()}_reshape({self.chandle()} handle, const size_t* shape, size_t ndims) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_reshape");
}}
    std::vector<size_t> vec;
    for (size_t i =0; i < ndims; ++i) {{
        vec.push_back(shape[i]);
    }}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArraySP<{cpp_type}>(farray->reshape(vec));
    FALCON_C_API_END(nullptr)
}}

ListListSizeTHandle {self.mangled_name()}_where({self.chandle()} handle,  {c_type} value) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_where");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    return new falcon_core::generic::ListSP<falcon_core::generic::List<size_t>>(farray->where(value));
    FALCON_C_API_END(nullptr)
}}

{self.chandle()} {self.mangled_name()}_flip({self.chandle()} handle, size_t axis) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_flip");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArraySP<{cpp_type}>(farray->flip(axis));
    FALCON_C_API_END(nullptr)
}}

size_t {self.mangled_name()}_full_gradient({self.chandle()} handle, {self.chandle()}* out_buffer, size_t buffer_size) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_full_gradient");
}}
if (!out_buffer) {{
throw std::invalid_argument("Null out_buffer passed to {self.mangled_name()}_full_gradient");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    auto many_gradients = farray->gradient();
    if (many_gradients->size() > buffer_size) {{
        throw std::runtime_error("Trying to store more {cpp_type} gradients than buffer allocated.");
    }}
    for (size_t i = 0; i < many_gradients->size(); ++i) {{
        out_buffer[i] = new falcon_core::generic::FArraySP<{cpp_type}>(many_gradients->items()[i]);
    }}
    return many_gradients->size();
    FALCON_C_API_END(0)
}}

{self.chandle()} {self.mangled_name()}_gradient({self.chandle()} handle, size_t axis) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_gradient");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArraySP<{cpp_type}>(farray->gradient(axis));
    FALCON_C_API_END(nullptr)
}}

double {self.mangled_name()}_get_sum_of_squares({self.chandle()} handle) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_get_sum_of_squares");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    return farray->get_sum_of_squares();
    FALCON_C_API_END(0.0)
}}

double {self.mangled_name()}_get_summed_diff_int_of_squares({self.chandle()} handle,  int other) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_get_summed_diff_int_of_squares");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    return farray->get_sum_of_squares(other);
    FALCON_C_API_END(0.0)
}}

double {self.mangled_name()}_get_summed_diff_double_of_squares({self.chandle()} handle,  double other) {{
    FALCON_C_API_BEGIN
if (!handle) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_get_summed_diff_double_of_squares");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    return farray->get_sum_of_squares(other);
    FALCON_C_API_END(0.0)
}}

double {self.mangled_name()}_get_summed_diff_array_of_squares({self.chandle()} handle, {self.chandle()} other) {{
    FALCON_C_API_BEGIN
if (!handle || !other) {{
throw std::invalid_argument("Null handle passed to {self.mangled_name()}_get_summed_diff_array_of_squares");
}}
    falcon_core::generic::FArraySP<{cpp_type}> farray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(handle);
    auto oarray = *static_cast<falcon_core::generic::FArraySP<{cpp_type}>*>(other);
    return farray->get_sum_of_squares(oarray);
    FALCON_C_API_END(0.0)
}}
}}
""")


def add_to_manifest(manifest_path, header_path, implementation_path):
    from pathlib import Path

    manifest_path = Path(manifest_path)
    if manifest_path.exists():
        with open(manifest_path, "r") as manifest:
            lines = set(line.strip() for line in manifest)
    else:
        lines = set()
    to_write = []
    if header_path not in lines:
        to_write.append(f"{header_path}\n")
    if implementation_path not in lines:
        to_write.append(f"{implementation_path}\n")
    if to_write:
        with open(manifest_path, "a") as manifest:
            manifest.writelines(to_write)


registry: dict[str, Entry] = {
    "IntList": Entry(
        Options.List,
        [
            "int",
            "int",
            "int",
            "Int",
        ],
        ["<stddef.h>", "<stdbool.h>"],
        [],
        Path("generic"),
    ),
    "FloatList": Entry(
        Options.List,
        [
            "float",
            "float",
            "float",
            "Float",
        ],
        ["<stddef.h>", "<stdbool.h>"],
        [],
        Path("generic"),
    ),
    "DoubleList": Entry(
        Options.List,
        [
            "double",
            "double",
            "double",
            "Double",
        ],
        ["<stddef.h>", "<stdbool.h>"],
        [],
        Path("generic"),
    ),
    "ConnectionList": Entry(
        Options.List,
        [
            "ConnectionHandle",
            "falcon_core::physics::device_structures::Connection",
            "falcon_core::physics::device_structures::ConnectionSP",
            "Connection",
        ],
        [
            '"falcon_core/physics/device_structures/Connection_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        ["<falcon_core/physics/device_structures/Connection.hpp>"],
        Path("generic"),
    ),
    "ChannelList": Entry(
        Options.List,
        [
            "ChannelHandle",
            "falcon_core::autotuner_interfaces::names::Channel",
            "falcon_core::autotuner_interfaces::names::ChannelSP",
            "Channel",
        ],
        [
            '"falcon_core/autotuner_interfaces/names/Channel_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        ["<falcon_core/autotuner_interfaces/names/Channel.hpp>"],
        Path("generic"),
    ),
    "InstrumentPortList": Entry(
        Options.List,
        [
            "InstrumentPortHandle",
            "falcon_core::instrument_interfaces::names::InstrumentPort",
            "falcon_core::instrument_interfaces::names::InstrumentPortSP",
            "InstrumentPort",
        ],
        [
            '"falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        ["<falcon_core/instrument_interfaces/names/InstrumentPort.hpp>"],
        Path("generic"),
    ),
    "PortTransformList": Entry(
        Options.List,
        [
            "PortTransformHandle",
            "falcon_core::instrument_interfaces::port_transforms::PortTransform",
            "falcon_core::instrument_interfaces::port_transforms::PortTransformSP",
            "PortTransform",
        ],
        [
            '"falcon_core/instrument_interfaces/port_transforms/PortTransform_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        ["<falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp>"],
        Path("generic"),
    ),
    "LabelledDomainList": Entry(
        Options.List,
        [
            "LabelledDomainHandle",
            "falcon_core::math::domains::LabelledDomain",
            "falcon_core::math::domains::LabelledDomainSP",
            "LabelledDomain",
        ],
        [
            '"falcon_core/math/domains/LabelledDomain_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        ["<falcon_core/math/domains/LabelledDomain.hpp>"],
        Path("generic"),
    ),
    "QuantityList": Entry(
        Options.List,
        [
            "QuantityHandle",
            "falcon_core::math::Quantity",
            "falcon_core::math::QuantitySP",
            "Quantity",
        ],
        [
            '"falcon_core/math/Quantity_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        ["<falcon_core/math/Quantity.hpp>"],
        Path("generic"),
    ),
    "SizeTList": Entry(
        Options.List,
        [
            "size_t",
            "size_t",
            "size_t",
            "SizeT",
        ],
        [
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [],
        Path("generic"),
    ),
    "ListSizeTList": Entry(
        Options.List,
        [
            "ListSizeTHandle",
            "falcon_core::generic::List<size_t>",
            "falcon_core::generic::ListSP<size_t>",
            "ListSizeT",
        ],
        [
            '"falcon_core/generic/ListSizeT_c_api.h"',
        ],
        [],
        Path("generic"),
    ),
    "ImpedanceList": Entry(
        Options.List,
        [
            "ImpedanceHandle",
            "falcon_core::physics::device_structures::Impedance",
            "falcon_core::physics::device_structures::ImpedanceSP",
            "Impedance",
        ],
        [
            '"falcon_core/physics/device_structures/Impedance_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        ["<falcon_core/physics/device_structures/Impedance.hpp>"],
        Path("generic"),
    ),
    "DeviceVoltageStateList": Entry(
        Options.List,
        [
            "DeviceVoltageStateHandle",
            "falcon_core::communications::voltage_states::DeviceVoltageState",
            "falcon_core::communications::voltage_states::DeviceVoltageStateSP",
            "DeviceVoltageState",
        ],
        [
            '"falcon_core/communications/voltage_states/DeviceVoltageState_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        ["<falcon_core/communications/voltage_states/DeviceVoltageState.hpp>"],
        Path("generic"),
    ),
    "StringList": Entry(
        Options.List,
        [
            "StringHandle",
            "std::string",
            "std::string",
            "String",
        ],
        [
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [],
        Path("generic"),
    ),
    "ConnectionsList": Entry(
        Options.List,
        [
            "ConnectionsHandle",
            "falcon_core::physics::device_structures::Connections",
            "falcon_core::physics::device_structures::ConnectionsSP",
            "Connections",
        ],
        [
            '"falcon_core/physics/device_structures/Connections_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        ["<falcon_core/physics/device_structures/Connections.hpp>"],
        Path("generic"),
    ),
    "BoolList": Entry(
        Options.List,
        [
            "bool",
            "bool",
            "bool",
            "Bool",
        ],
        [
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [],
        Path("generic"),
    ),
    "PairIntIntList": Entry(
        Options.List,
        [
            "PairIntIntHandle",
            "falcon_core::generic::Pair<int, int>",
            "falcon_core::generic::PairSP<int, int>",
            "PairIntInt",
        ],
        [
            '"falcon_core/generic/PairIntInt_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        ["<falcon_core/generic/Pair.hpp>"],
        Path("generic"),
    ),
    "PairFloatFloatList": Entry(
        Options.List,
        [
            "PairFloatFloatHandle",
            "falcon_core::generic::Pair<float, float>",
            "falcon_core::generic::PairSP<float, float>",
            "PairFloatFloat",
        ],
        [
            '"falcon_core/generic/PairFloatFloat_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        ["<falcon_core/generic/Pair.hpp>"],
        Path("generic"),
    ),
    "PairIntFloatList": Entry(
        Options.List,
        [
            "PairIntFloatHandle",
            "falcon_core::generic::Pair<int, float>",
            "falcon_core::generic::PairSP<int, float>",
            "PairIntFloat",
        ],
        [
            '"falcon_core/generic/PairIntFloat_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        ["<falcon_core/generic/Pair.hpp>"],
        Path("generic"),
    ),
    "PairConnectionFloatList": Entry(
        Options.List,
        [
            "PairConnectionFloatHandle",
            "falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, float>",
            "falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, float>",
            "PairConnectionFloat",
        ],
        [
            '"falcon_core/generic/PairConnectionFloat_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
            "<falcon_core/physics/device_structures/Connection.hpp>",
        ],
        Path("generic"),
    ),
    "PairConnectionDoubleList": Entry(
        Options.List,
        [
            "PairConnectionDoubleHandle",
            "falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>",
            "falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, double>",
            "PairConnectionDouble",
        ],
        [
            '"falcon_core/generic/PairConnectionDouble_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
            "<falcon_core/physics/device_structures/Connection.hpp>",
        ],
        Path("generic"),
    ),
    "PairInterpretationContextDoubleList": Entry(
        Options.List,
        [
            "PairInterpretationContextDoubleHandle",
            "falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>",
            "falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>",
            "PairInterpretationContextDouble",
        ],
        [
            '"falcon_core/generic/PairInterpretationContextDouble_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
            "<falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>",
        ],
        Path("generic"),
    ),
    "PairInterpretationContextStringList": Entry(
        Options.List,
        [
            "PairInterpretationContextStringHandle",
            "falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>",
            "falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, std::string>",
            "PairInterpretationContextString",
        ],
        [
            '"falcon_core/generic/PairInterpretationContextString_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
            "<falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>",
        ],
        Path("generic"),
    ),
    "PairInterpretationContextQuantityList": Entry(
        Options.List,
        [
            "PairInterpretationContextQuantityHandle",
            "falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>",
            "falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>",
            "PairInterpretationContextQuantity",
        ],
        [
            '"falcon_core/generic/PairInterpretationContextQuantity_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
            "<falcon_core/generic/List.hpp>",
            "<falcon_core/math/Quantity.hpp>",
            "<falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>",
        ],
        Path("generic"),
    ),
    "PairConnectionConnectionsList": Entry(
        Options.List,
        [
            "PairConnectionConnectionsHandle",
            "falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>",
            "falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>",
            "PairConnectionConnections",
        ],
        [
            '"falcon_core/generic/PairConnectionConnections_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
            "<falcon_core/physics/device_structures/Connections.hpp>",
        ],
        Path("generic"),
    ),
    "PairConnectionQuantityList": Entry(
        Options.List,
        [
            "PairConnectionQuantityHandle",
            "falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>",
            "falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::math::Quantity>",
            "PairConnectionQuantity",
        ],
        [
            '"falcon_core/generic/PairConnectionQuantity_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
            "<falcon_core/math/Quantity.hpp>",
            "<falcon_core/physics/device_structures/Connection.hpp>",
        ],
        Path("generic"),
    ),
    "IntIntPair": Entry(
        Options.Pair,
        [
            "int",
            "int",
            "int",
            "int",
            "int",
            "int",
            "IntInt",
        ],
        ["<stdbool.h>"],
        [],
        Path("generic"),
    ),
    "FloatFloatPair": Entry(
        Options.Pair,
        [
            "float",
            "float",
            "float",
            "float",
            "float",
            "float",
            "FloatFloat",
        ],
        ["<stdbool.h>"],
        [],
        Path("generic"),
    ),
    "DoubleDoublePair": Entry(
        Options.Pair,
        [
            "double",
            "double",
            "double",
            "double",
            "double",
            "double",
            "DoubleDouble",
        ],
        ["<stdbool.h>"],
        [],
        Path("generic"),
    ),
    "IntFloatPair": Entry(
        Options.Pair,
        [
            "int",
            "int",
            "int",
            "float",
            "float",
            "float",
            "IntFloat",
        ],
        ["<stdbool.h>"],
        [],
        Path("generic"),
    ),
    "ConnectionFloatPair": Entry(
        Options.Pair,
        [
            "ConnectionHandle",
            "falcon_core::physics::device_structures::Connection",
            "falcon_core::physics::device_structures::ConnectionSP",
            "float",
            "float",
            "float",
            "ConnectionFloat",
        ],
        [
            '"falcon_core/physics/device_structures/Connection_c_api.h"',
            "<stdbool.h>",
        ],
        ["<falcon_core/physics/device_structures/Connection.hpp>"],
        Path("generic"),
    ),
    "ConnectionDoublePair": Entry(
        Options.Pair,
        [
            "ConnectionHandle",
            "falcon_core::physics::device_structures::Connection",
            "falcon_core::physics::device_structures::ConnectionSP",
            "double",
            "double",
            "double",
            "ConnectionDouble",
        ],
        [
            '"falcon_core/physics/device_structures/Connection_c_api.h"',
            "<stdbool.h>",
        ],
        ["<falcon_core/physics/device_structures/Connection.hpp>"],
        Path("generic"),
    ),
    "InterpretationContextDoublePair": Entry(
        Options.Pair,
        [
            "InterpretationContextHandle",
            "falcon_core::autotuner_interfaces::interpretations::InterpretationContext",
            "falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP",
            "double",
            "double",
            "double",
            "InterpretationContextDouble",
        ],
        [
            '"falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"',
            "<stdbool.h>",
        ],
        [
            "<falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>",
        ],
        Path("generic"),
    ),
    "InterpretationContextStringPair": Entry(
        Options.Pair,
        [
            "InterpretationContextHandle",
            "falcon_core::autotuner_interfaces::interpretations::InterpretationContext",
            "falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP",
            "StringHandle",
            "std::string",
            "std::string",
            "InterpretationContextString",
        ],
        [
            '"falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"',
            "<stdbool.h>",
        ],
        [
            "<falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>",
        ],
        Path("generic"),
    ),
    "InterpretationContextQuantityPair": Entry(
        Options.Pair,
        [
            "InterpretationContextHandle",
            "falcon_core::autotuner_interfaces::interpretations::InterpretationContext",
            "falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP",
            "QuantityHandle",
            "falcon_core::math::Quantity",
            "falcon_core::math::QuantitySP",
            "InterpretationContextQuantity",
        ],
        [
            '"falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"',
            '"falcon_core/math/Quantity_c_api.h"',
            "<stdbool.h>",
        ],
        [
            "<falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>",
            "<falcon_core/math/Quantity.hpp>",
        ],
        Path("generic"),
    ),
    "QuantityQuantityPair": Entry(
        Options.Pair,
        [
            "QuantityHandle",
            "falcon_core::math::Quantity",
            "falcon_core::math::QuantitySP",
            "QuantityHandle",
            "falcon_core::math::Quantity",
            "falcon_core::math::QuantitySP",
            "QuantityQuantity",
        ],
        [
            '"falcon_core/math/Quantity_c_api.h"',
            "<stdbool.h>",
        ],
        ["<falcon_core/math/Quantity.hpp>"],
        Path("generic"),
    ),
    "ConnectionQuantityPair": Entry(
        Options.Pair,
        [
            "ConnectionHandle",
            "falcon_core::physics::device_structures::Connection",
            "falcon_core::physics::device_structures::ConnectionSP",
            "QuantityHandle",
            "falcon_core::math::Quantity",
            "falcon_core::math::QuantitySP",
            "ConnectionQuantity",
        ],
        [
            '"falcon_core/math/Quantity_c_api.h"',
            '"falcon_core/physics/device_structures/Connection_c_api.h"',
            "<stdbool.h>",
        ],
        [
            "<falcon_core/math/Quantity.hpp>",
            "<falcon_core/physics/device_structures/Connection.hpp>",
        ],
        Path("generic"),
    ),
    "PairQuantityQuantityList": Entry(
        Options.List,
        [
            "PairQuantityQuantityHandle",
            "falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>",
            "falcon_core::generic::PairSP<falcon_core::math::Quantity, falcon_core::math::Quantity>",
            "PairQuantityQuantity",
        ],
        [
            '"falcon_core/generic/PairQuantityQuantity_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
            "<falcon_core/math/Quantity.hpp>",
        ],
        Path("generic"),
    ),
    "PairChannelConnectionsList": Entry(
        Options.List,
        [
            "PairChannelConnectionsHandle",
            "falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>",
            "falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>",
            "PairChannelConnections",
        ],
        [
            '"falcon_core/generic/PairChannelConnections_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
            "<falcon_core/autotuner_interfaces/names/Channel.hpp>",
            "<falcon_core/physics/device_structures/Connections.hpp>",
        ],
        Path("generic"),
    ),
    "PairGnameGroupList": Entry(
        Options.List,
        [
            "PairGnameGroupHandle",
            "falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>",
            "falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>",
            "PairGnameGroup",
        ],
        [
            '"falcon_core/generic/PairGnameGroup_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
            "<falcon_core/autotuner_interfaces/names/Gname.hpp>",
            "<falcon_core/physics/config/core/Group.hpp>",
        ],
        Path("generic"),
    ),
    "PairStringDoubleList": Entry(
        Options.List,
        [
            "PairStringDoubleHandle",
            "falcon_core::generic::Pair<std::string, double>",
            "falcon_core::generic::PairSP<std::string, double>",
            "PairStringDouble",
        ],
        [
            '"falcon_core/generic/PairStringDouble_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
        ],
        Path("generic"),
    ),
    "PairStringBoolList": Entry(
        Options.List,
        [
            "PairStringBoolHandle",
            "falcon_core::generic::Pair<std::string, bool>",
            "falcon_core::generic::PairSP<std::string, bool>",
            "PairStringBool",
        ],
        [
            '"falcon_core/generic/PairStringBool_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
        ],
        Path("generic"),
    ),
    "PairSizeTSizeTList": Entry(
        Options.List,
        [
            "PairSizeTSizeTHandle",
            "falcon_core::generic::Pair<size_t, size_t>",
            "falcon_core::generic::PairSP<size_t, size_t>",
            "PairSizeTSizeT",
        ],
        [
            '"falcon_core/generic/PairSizeTSizeT_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
        ],
        Path("generic"),
    ),
    "FArrayDoubleList": Entry(
        Options.List,
        [
            "FArrayDoubleHandle",
            "falcon_core::generic::FArray<double>",
            "falcon_core::generic::FArraySP<double>",
            "FArrayDouble",
        ],
        [
            '"falcon_core/generic/FArrayDouble_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/FArray.hpp>",
        ],
        Path("generic"),
    ),
    "ControlArrayList": Entry(
        Options.List,
        [
            "ControlArrayHandle",
            "falcon_core::math::arrays::ControlArray",
            "falcon_core::math::arrays::ControlArraySP",
            "ControlArray",
        ],
        [
            '"falcon_core/math/arrays/ControlArray_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/math/arrays/ControlArray.hpp>",
        ],
        Path("generic"),
    ),
    "LabelledControlArrayList": Entry(
        Options.List,
        [
            "LabelledControlArrayHandle",
            "falcon_core::math::arrays::LabelledControlArray",
            "falcon_core::math::arrays::LabelledControlArraySP",
            "LabelledControlArray",
        ],
        [
            '"falcon_core/math/arrays/LabelledControlArray_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/math/arrays/LabelledControlArray.hpp>",
        ],
        Path("generic"),
    ),
    "LabelledControlArray1DList": Entry(
        Options.List,
        [
            "LabelledControlArray1DHandle",
            "falcon_core::math::arrays::LabelledControlArray1D",
            "falcon_core::math::arrays::LabelledControlArray1DSP",
            "LabelledControlArray1D",
        ],
        [
            '"falcon_core/math/arrays/LabelledControlArray1D_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/math/arrays/LabelledControlArray1D.hpp>",
        ],
        Path("generic"),
    ),
    "LabelledMeasuredArrayList": Entry(
        Options.List,
        [
            "LabelledMeasuredArrayHandle",
            "falcon_core::math::arrays::LabelledMeasuredArray",
            "falcon_core::math::arrays::LabelledMeasuredArraySP",
            "LabelledMeasuredArray",
        ],
        [
            '"falcon_core/math/arrays/LabelledMeasuredArray_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/math/arrays/LabelledMeasuredArray.hpp>",
        ],
        Path("generic"),
    ),
    "LabelledMeasuredArray1DList": Entry(
        Options.List,
        [
            "LabelledMeasuredArray1DHandle",
            "falcon_core::math::arrays::LabelledMeasuredArray1D",
            "falcon_core::math::arrays::LabelledMeasuredArray1DSP",
            "LabelledMeasuredArray1D",
        ],
        [
            '"falcon_core/math/arrays/LabelledMeasuredArray1D_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/math/arrays/LabelledMeasuredArray1D.hpp>",
        ],
        Path("generic"),
    ),
    "DotGateWithNeighborsList": Entry(
        Options.List,
        [
            "DotGateWithNeighborsHandle",
            "falcon_core::physics::config::geometries::DotGateWithNeighbors",
            "falcon_core::physics::config::geometries::DotGateWithNeighborsSP",
            "DotGateWithNeighbors",
        ],
        [
            '"falcon_core/physics/config/geometries/DotGateWithNeighbors_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/physics/config/geometries/DotGateWithNeighbors.hpp>",
        ],
        Path("generic"),
    ),
    "ControlArray1DList": Entry(
        Options.List,
        [
            "ControlArray1DHandle",
            "falcon_core::math::arrays::ControlArray1D",
            "falcon_core::math::arrays::ControlArray1DSP",
            "ControlArray1D",
        ],
        [
            '"falcon_core/math/arrays/ControlArray1D_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/math/arrays/ControlArray1D.hpp>",
        ],
        Path("generic"),
    ),
    "CoupledLabelledDomainList": Entry(
        Options.List,
        [
            "CoupledLabelledDomainHandle",
            "falcon_core::math::domains::CoupledLabelledDomain",
            "falcon_core::math::domains::CoupledLabelledDomainSP",
            "CoupledLabelledDomain",
        ],
        [
            '"falcon_core/math/domains/CoupledLabelledDomain_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/math/domains/CoupledLabelledDomain.hpp>",
        ],
        Path("generic"),
    ),
    "MeasurementContextList": Entry(
        Options.List,
        [
            "MeasurementContextHandle",
            "falcon_core::autotuner_interfaces::contexts::MeasurementContext",
            "falcon_core::autotuner_interfaces::contexts::MeasurementContextSP",
            "MeasurementContext",
        ],
        [
            '"falcon_core/autotuner_interfaces/contexts/MeasurementContext_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/autotuner_interfaces/contexts/MeasurementContext.hpp>",
        ],
        Path("generic"),
    ),
    "InterpretationContextList": Entry(
        Options.List,
        [
            "InterpretationContextHandle",
            "falcon_core::autotuner_interfaces::interpretations::InterpretationContext",
            "falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP",
            "InterpretationContext",
        ],
        [
            '"falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>",
        ],
        Path("generic"),
    ),
    "AcquisitionContextList": Entry(
        Options.List,
        [
            "AcquisitionContextHandle",
            "falcon_core::autotuner_interfaces::contexts::AcquisitionContext",
            "falcon_core::autotuner_interfaces::contexts::AcquisitionContextSP",
            "AcquisitionContext",
        ],
        [
            '"falcon_core/autotuner_interfaces/contexts/AcquisitionContext_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp>",
        ],
        Path("generic"),
    ),
    "WaveformList": Entry(
        Options.List,
        [
            "WaveformHandle",
            "falcon_core::instrument_interfaces::Waveform",
            "falcon_core::instrument_interfaces::WaveformSP",
            "Waveform",
        ],
        [
            '"falcon_core/instrument_interfaces/Waveform_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/instrument_interfaces/Waveform.hpp>",
        ],
        Path("generic"),
    ),
    "MapStringBoolList": Entry(
        Options.List,
        [
            "MapStringBoolHandle",
            "falcon_core::generic::Map<std::string, bool>",
            "falcon_core::generic::MapSP<std::string, bool>",
            "MapStringBool",
        ],
        [
            '"falcon_core/generic/MapStringBool_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/Map.hpp>",
        ],
        Path("generic"),
    ),
    "PairConnectionPairQuantityQuantityList": Entry(
        Options.List,
        [
            "PairConnectionPairQuantityQuantityHandle",
            "falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>",
            "falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>>",
            "PairConnectionPairQuantityQuantity",
        ],
        [
            '"falcon_core/generic/PairConnectionPairQuantityQuantity_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
            "<falcon_core/physics/device_structures/Connection.hpp>",
            "<falcon_core/math/Quantity.hpp>",
        ],
        Path("generic"),
    ),
    "PairInstrumentPortPortTransformList": Entry(
        Options.List,
        [
            "PairInstrumentPortPortTransformHandle",
            "falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>",
            "falcon_core::generic::PairSP<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>",
            "PairInstrumentPortPortTransform",
        ],
        [
            '"falcon_core/generic/PairInstrumentPortPortTransform_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
            "<falcon_core/instrument_interfaces/names/InstrumentPort.hpp>",
            "<falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp>",
        ],
        Path("generic"),
    ),
    "PairStringStringList": Entry(
        Options.List,
        [
            "PairStringStringHandle",
            "falcon_core::generic::Pair<std::string, std::string>",
            "falcon_core::generic::PairSP<std::string, std::string>",
            "PairStringString",
        ],
        [
            '"falcon_core/generic/PairStringString_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
        ],
        Path("generic"),
    ),
    "StringDoublePair": Entry(
        Options.Pair,
        [
            "StringHandle",
            "std::string",
            "std::string",
            "double",
            "double",
            "double",
            "StringDouble",
        ],
        [
            "<stddef.h>",
            "<stdbool.h>",
            '"falcon_core/generic/String_c_api.h"',
        ],
        [],
        Path("generic"),
    ),
    "StringStringPair": Entry(
        Options.Pair,
        [
            "StringHandle",
            "std::string",
            "std::string",
            "StringHandle",
            "std::string",
            "std::string",
            "StringString",
        ],
        [
            "<stddef.h>",
            "<stdbool.h>",
            '"falcon_core/generic/String_c_api.h"',
        ],
        [],
        Path("generic"),
    ),
    "StringBoolPair": Entry(
        Options.Pair,
        [
            "StringHandle",
            "std::string",
            "std::string",
            "bool",
            "bool",
            "bool",
            "StringBool",
        ],
        [
            "<stddef.h>",
            "<stdbool.h>",
            '"falcon_core/generic/String_c_api.h"',
        ],
        [],
        Path("generic"),
    ),
    "SizeTSizeTPair": Entry(
        Options.Pair,
        [
            "size_t",
            "size_t",
            "size_t",
            "size_t",
            "size_t",
            "size_t",
            "SizeTSizeT",
        ],
        [
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [],
        Path("generic"),
    ),
    "ConnectionConnectionPair": Entry(
        Options.Pair,
        [
            "ConnectionHandle",
            "falcon_core::physics::device_structures::Connection",
            "falcon_core::physics::device_structures::ConnectionSP",
            "ConnectionHandle",
            "falcon_core::physics::device_structures::Connection",
            "falcon_core::physics::device_structures::ConnectionSP",
            "ConnectionConnection",
        ],
        [
            '"falcon_core/physics/device_structures/Connection_c_api.h"',
            "<stdbool.h>",
        ],
        ["<falcon_core/physics/device_structures/Connection.hpp>"],
        Path("generic"),
    ),
    "ConnectionConnectionsPair": Entry(
        Options.Pair,
        [
            "ConnectionHandle",
            "falcon_core::physics::device_structures::Connection",
            "falcon_core::physics::device_structures::ConnectionSP",
            "ConnectionsHandle",
            "falcon_core::physics::device_structures::Connections",
            "falcon_core::physics::device_structures::ConnectionsSP",
            "ConnectionConnections",
        ],
        [
            '"falcon_core/physics/device_structures/Connections_c_api.h"',
            "<stdbool.h>",
        ],
        ["<falcon_core/physics/device_structures/Connections.hpp>"],
        Path("generic"),
    ),
    "ChannelConnectionsPair": Entry(
        Options.Pair,
        [
            "ChannelHandle",
            "falcon_core::autotuner_interfaces::names::Channel",
            "falcon_core::autotuner_interfaces::names::ChannelSP",
            "ConnectionsHandle",
            "falcon_core::physics::device_structures::Connections",
            "falcon_core::physics::device_structures::ConnectionsSP",
            "ChannelConnections",
        ],
        [
            '"falcon_core/autotuner_interfaces/names/Channel_c_api.h"',
            '"falcon_core/physics/device_structures/Connections_c_api.h"',
            "<stdbool.h>",
        ],
        [
            "<falcon_core/physics/device_structures/Connections.hpp>",
            "<falcon_core/autotuner_interfaces/names/Channel.hpp>",
        ],
        Path("generic"),
    ),
    "MeasurementResponseMeasurementRequestPair": Entry(
        Options.Pair,
        [
            "MeasurementResponseHandle",
            "falcon_core::communications::messages::MeasurementResponse",
            "falcon_core::communications::messages::MeasurementResponseSP",
            "MeasurementRequestHandle",
            "falcon_core::communications::messages::MeasurementRequest",
            "falcon_core::communications::messages::MeasurementRequestSP",
            "MeasurementResponseMeasurementRequest",
        ],
        [
            '"falcon_core/communications/messages/MeasurementResponse_c_api.h"',
            '"falcon_core/communications/messages/MeasurementRequest_c_api.h"',
            "<stdbool.h>",
        ],
        [
            "<falcon_core/communications/messages/MeasurementResponse.hpp>",
            "<falcon_core/communications/messages/MeasurementRequest.hpp>",
        ],
        Path("generic"),
    ),
    "InstrumentPortPortTransformPair": Entry(
        Options.Pair,
        [
            "InstrumentPortHandle",
            "falcon_core::instrument_interfaces::names::InstrumentPort",
            "falcon_core::instrument_interfaces::names::InstrumentPortSP",
            "PortTransformHandle",
            "falcon_core::instrument_interfaces::port_transforms::PortTransform",
            "falcon_core::instrument_interfaces::port_transforms::PortTransformSP",
            "InstrumentPortPortTransform",
        ],
        [
            '"falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"',
            '"falcon_core/instrument_interfaces/port_transforms/PortTransform_c_api.h"',
            "<stdbool.h>",
        ],
        [
            "<falcon_core/instrument_interfaces/names/InstrumentPort.hpp>",
            "<falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp>",
        ],
        Path("generic"),
    ),
    "GnameGroupPair": Entry(
        Options.Pair,
        [
            "GnameHandle",
            "falcon_core::autotuner_interfaces::names::Gname",
            "falcon_core::autotuner_interfaces::names::GnameSP",
            "GroupHandle",
            "falcon_core::physics::config::core::Group",
            "falcon_core::physics::config::core::GroupSP",
            "GnameGroup",
        ],
        [
            '"falcon_core/autotuner_interfaces/names/Gname_c_api.h"',
            '"falcon_core/physics/config/core/Group_c_api.h"',
            "<stdbool.h>",
        ],
        [
            "<falcon_core/autotuner_interfaces/names/Gname.hpp>",
            "<falcon_core/physics/config/core/Group.hpp>",
        ],
        Path("generic"),
    ),
    "ConnectionPairQuantityQuantityPair": Entry(
        Options.Pair,
        [
            "ConnectionHandle",
            "falcon_core::physics::device_structures::Connection",
            "falcon_core::physics::device_structures::ConnectionSP",
            "PairQuantityQuantityHandle",
            "falcon_core::generic::Pair<falcon_core::math::Quantity, falcon_core::math::Quantity>",
            "falcon_core::generic::PairSP<falcon_core::math::Quantity, falcon_core::math::Quantity>",
            "ConnectionPairQuantityQuantity",
        ],
        [
            '"falcon_core/physics/device_structures/Connection_c_api.h"',
            '"falcon_core/generic/PairQuantityQuantity_c_api.h"',
            "<stdbool.h>",
        ],
        [
            "<falcon_core/physics/device_structures/Connection.hpp>",
            "<falcon_core/math/Quantity.hpp>",
        ],
        Path("generic"),
    ),
    "IntIntMap": Entry(
        Options.Map,
        [
            "int",
            "int",
            "int",
            "int",
            "int",
            "int",
            "Int",
            "Int",
            "IntInt",
        ],
        [
            '"falcon_core/generic/PairIntInt_c_api.h"',
            '"falcon_core/generic/ListInt_c_api.h"',
            '"falcon_core/generic/ListPairIntInt_c_api.h"',
        ],
        ["<falcon_core/generic/Pair.hpp>"],
        Path("generic"),
    ),
    "FloatFloatMap": Entry(
        Options.Map,
        [
            "float",
            "float",
            "float",
            "float",
            "float",
            "float",
            "Float",
            "Float",
            "FloatFloat",
        ],
        [
            '"falcon_core/generic/PairFloatFloat_c_api.h"',
            '"falcon_core/generic/ListFloat_c_api.h"',
            '"falcon_core/generic/ListPairFloatFloat_c_api.h"',
        ],
        ["<falcon_core/generic/Pair.hpp>"],
        Path("generic"),
    ),
    "ConnectionFloatMap": Entry(
        Options.Map,
        [
            "ConnectionHandle",
            "falcon_core::physics::device_structures::Connection",
            "falcon_core::physics::device_structures::ConnectionSP",
            "float",
            "float",
            "float",
            "Connection",
            "Float",
            "ConnectionFloat",
        ],
        [
            '"falcon_core/generic/PairConnectionFloat_c_api.h"',
            '"falcon_core/generic/ListFloat_c_api.h"',
            '"falcon_core/generic/ListConnection_c_api.h"',
            '"falcon_core/generic/ListPairConnectionFloat_c_api.h"',
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
            "<falcon_core/physics/device_structures/Connection.hpp>",
        ],
        Path("generic"),
    ),
    "ConnectionDoubleMap": Entry(
        Options.Map,
        [
            "ConnectionHandle",
            "falcon_core::physics::device_structures::Connection",
            "falcon_core::physics::device_structures::ConnectionSP",
            "double",
            "double",
            "double",
            "Connection",
            "Double",
            "ConnectionDouble",
        ],
        [
            '"falcon_core/generic/PairConnectionDouble_c_api.h"',
            '"falcon_core/generic/ListDouble_c_api.h"',
            '"falcon_core/generic/ListConnection_c_api.h"',
            '"falcon_core/generic/ListPairConnectionDouble_c_api.h"',
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
            "<falcon_core/physics/device_structures/Connection.hpp>",
        ],
        Path("generic"),
    ),
    "InterpretationContextDoubleMap": Entry(
        Options.Map,
        [
            "InterpretationContextHandle",
            "falcon_core::autotuner_interfaces::interpretations::InterpretationContext",
            "falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP",
            "double",
            "double",
            "double",
            "InterpretationContext",
            "Double",
            "InterpretationContextDouble",
        ],
        [
            '"falcon_core/generic/PairInterpretationContextDouble_c_api.h"',
            '"falcon_core/generic/ListDouble_c_api.h"',
            '"falcon_core/generic/ListInterpretationContext_c_api.h"',
            '"falcon_core/generic/ListPairInterpretationContextDouble_c_api.h"',
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
            "<falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>",
        ],
        Path("generic"),
    ),
    "ConnectionQuantityMap": Entry(
        Options.Map,
        [
            "ConnectionHandle",
            "falcon_core::physics::device_structures::Connection",
            "falcon_core::physics::device_structures::ConnectionSP",
            "QuantityHandle",
            "falcon_core::math::Quantity",
            "falcon_core::math::QuantitySP",
            "Connection",
            "Quantity",
            "ConnectionQuantity",
        ],
        [
            '"falcon_core/generic/PairConnectionQuantity_c_api.h"',
            '"falcon_core/generic/ListQuantity_c_api.h"',
            '"falcon_core/generic/ListConnection_c_api.h"',
            '"falcon_core/generic/ListPairConnectionQuantity_c_api.h"',
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
            "<falcon_core/math/Quantity.hpp>",
            "<falcon_core/physics/device_structures/Connection.hpp>",
        ],
        Path("generic"),
    ),
    "InterpretationContextQuantityMap": Entry(
        Options.Map,
        [
            "InterpretationContextHandle",
            "falcon_core::autotuner_interfaces::interpretations::InterpretationContext",
            "falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP",
            "QuantityHandle",
            "falcon_core::math::Quantity",
            "falcon_core::math::QuantitySP",
            "InterpretationContext",
            "Quantity",
            "InterpretationContextQuantity",
        ],
        [
            '"falcon_core/generic/PairInterpretationContextQuantity_c_api.h"',
            '"falcon_core/generic/ListQuantity_c_api.h"',
            '"falcon_core/generic/ListInterpretationContext_c_api.h"',
            '"falcon_core/generic/ListPairInterpretationContextQuantity_c_api.h"',
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
            "<falcon_core/math/Quantity.hpp>",
            "<falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>",
        ],
        Path("generic"),
    ),
    "InterpretationContextStringMap": Entry(
        Options.Map,
        [
            "InterpretationContextHandle",
            "falcon_core::autotuner_interfaces::interpretations::InterpretationContext",
            "falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP",
            "StringHandle",
            "std::string",
            "std::string",
            "InterpretationContext",
            "String",
            "InterpretationContextString",
        ],
        [
            '"falcon_core/generic/PairInterpretationContextString_c_api.h"',
            '"falcon_core/generic/ListString_c_api.h"',
            '"falcon_core/generic/ListInterpretationContext_c_api.h"',
            '"falcon_core/generic/ListPairInterpretationContextString_c_api.h"',
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
            "<falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>",
        ],
        Path("generic"),
    ),
    "ChannelConnectionsMap": Entry(
        Options.Map,
        [
            "ChannelHandle",
            "falcon_core::autotuner_interfaces::names::Channel",
            "falcon_core::autotuner_interfaces::names::ChannelSP",
            "ConnectionsHandle",
            "falcon_core::physics::device_structures::Connections",
            "falcon_core::physics::device_structures::ConnectionsSP",
            "Channel",
            "Connections",
            "ChannelConnections",
        ],
        [
            '"falcon_core/generic/PairChannelConnections_c_api.h"',
            '"falcon_core/generic/ListChannel_c_api.h"',
            '"falcon_core/generic/ListConnections_c_api.h"',
            '"falcon_core/generic/ListPairChannelConnections_c_api.h"',
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
            "<falcon_core/autotuner_interfaces/names/Channel.hpp>",
            "<falcon_core/physics/device_structures/Connections.hpp>",
        ],
        Path("generic"),
    ),
    "InstrumentPortPortTransformMap": Entry(
        Options.Map,
        [
            "InstrumentPortHandle",
            "falcon_core::instrument_interfaces::names::InstrumentPort",
            "falcon_core::instrument_interfaces::names::InstrumentPortSP",
            "PortTransformHandle",
            "falcon_core::instrument_interfaces::port_transforms::PortTransform",
            "falcon_core::instrument_interfaces::port_transforms::PortTransformSP",
            "InstrumentPort",
            "PortTransform",
            "InstrumentPortPortTransform",
        ],
        [
            '"falcon_core/generic/PairInstrumentPortPortTransform_c_api.h"',
            '"falcon_core/generic/ListInstrumentPort_c_api.h"',
            '"falcon_core/generic/ListPortTransform_c_api.h"',
            '"falcon_core/generic/ListPairInstrumentPortPortTransform_c_api.h"',
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
            "<falcon_core/instrument_interfaces/names/InstrumentPort.hpp>",
            "<falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp>",
        ],
        Path("generic"),
    ),
    "GnameGroupMap": Entry(
        Options.Map,
        [
            "GnameHandle",
            "falcon_core::autotuner_interfaces::names::Gname",
            "falcon_core::autotuner_interfaces::names::GnameSP",
            "GroupHandle",
            "falcon_core::physics::config::core::Group",
            "falcon_core::physics::config::core::GroupSP",
            "Gname",
            "Group",
            "GnameGroup",
        ],
        [
            '"falcon_core/generic/PairGnameGroup_c_api.h"',
            '"falcon_core/generic/ListGname_c_api.h"',
            '"falcon_core/generic/ListGroup_c_api.h"',
            '"falcon_core/generic/ListPairGnameGroup_c_api.h"',
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
            "<falcon_core/autotuner_interfaces/names/Gname.hpp>",
            "<falcon_core/physics/config/core/Group.hpp>",
        ],
        Path("generic"),
    ),
    "StringDoubleMap": Entry(
        Options.Map,
        [
            "StringHandle",
            "std::string",
            "std::string",
            "double",
            "double",
            "double",
            "String",
            "Double",
            "StringDouble",
        ],
        [
            '"falcon_core/generic/ListPairStringDouble_c_api.h"',
            '"falcon_core/generic/ListString_c_api.h"',
            '"falcon_core/generic/ListDouble_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
        ],
        Path("generic"),
    ),
    "StringStringMap": Entry(
        Options.Map,
        [
            "StringHandle",
            "std::string",
            "std::string",
            "StringHandle",
            "std::string",
            "std::string",
            "String",
            "String",
            "StringString",
        ],
        [
            '"falcon_core/generic/ListPairStringString_c_api.h"',
            '"falcon_core/generic/ListString_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
        ],
        Path("generic"),
    ),
    "StringBoolMap": Entry(
        Options.Map,
        [
            "StringHandle",
            "std::string",
            "std::string",
            "bool",
            "bool",
            "bool",
            "String",
            "Bool",
            "StringBool",
        ],
        [
            '"falcon_core/generic/ListPairStringBool_c_api.h"',
            '"falcon_core/generic/ListString_c_api.h"',
            '"falcon_core/generic/ListBool_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
        ],
        Path("generic"),
    ),
    "DoubleFArray": Entry(
        Options.FArray,
        [
            "double",
            "double",
            "Double",
        ],
        [
            "<stddef.h>",
            "<stdbool.h>",
            '"falcon_core/generic/ListListSizeT_c_api.h"',
        ],
        [
            "<falcon_core/generic/FArray.hpp>",
            "<xtensor/xadapt.hpp>",
        ],
        Path("generic"),
    ),
    "IntFArray": Entry(
        Options.FArray,
        [
            "int",
            "int",
            "Int",
        ],
        [
            "<stddef.h>",
            "<stdbool.h>",
            '"falcon_core/generic/ListListSizeT_c_api.h"',
            '"falcon_core/generic/FArrayDouble_c_api.h"',
        ],
        [
            "<falcon_core/generic/FArray.hpp>",
            "<xtensor/xadapt.hpp>",
        ],
        Path("generic"),
    ),
    "DiscretizerList": Entry(
        Options.List,
        [
            "DiscretizerHandle",
            "falcon_core::math::discrete_spaces::Discretizer",
            "falcon_core::math::discrete_spaces::DiscretizerSP",
            "Discretizer",
        ],
        [
            '"falcon_core/math/discrete_spaces/Discretizer_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/math/discrete_spaces/Discretizer.hpp>",
        ],
        Path("generic"),
    ),
    "GnameList": Entry(
        Options.List,
        [
            "GnameHandle",
            "falcon_core::autotuner_interfaces::names::Gname",
            "falcon_core::autotuner_interfaces::names::GnameSP",
            "Gname",
        ],
        [
            '"falcon_core/autotuner_interfaces/names/Gname_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/autotuner_interfaces/names/Gname.hpp>",
        ],
        Path("generic"),
    ),
    "GroupList": Entry(
        Options.List,
        [
            "GroupHandle",
            "falcon_core::physics::config::core::Group",
            "falcon_core::physics::config::core::GroupSP",
            "Group",
        ],
        [
            '"falcon_core/physics/config/core/Group_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/physics/config/core/Group.hpp>",
        ],
        Path("generic"),
    ),
    "DoubleAxes": Entry(
        Options.Axes,
        [
            "double",
            "double",
            "double",
            "Double",
        ],
        [
            '"falcon_core/generic/ListDouble_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/List.hpp>",
        ],
        Path("math"),
    ),
    "IntAxes": Entry(
        Options.Axes,
        [
            "int",
            "int",
            "int",
            "Int",
        ],
        [
            '"falcon_core/generic/ListInt_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/List.hpp>",
        ],
        Path("math"),
    ),
    "DiscretizerAxes": Entry(
        Options.Axes,
        [
            "DiscretizerHandle",
            "falcon_core::math::discrete_spaces::Discretizer",
            "falcon_core::math::discrete_spaces::DiscretizerSP",
            "Discretizer",
        ],
        [
            '"falcon_core/math/discrete_spaces/Discretizer_c_api.h"',
            '"falcon_core/generic/ListDiscretizer_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/List.hpp>",
            "<falcon_core/math/discrete_spaces/Discretizer.hpp>",
        ],
        Path("math"),
    ),
    "ControlArrayAxes": Entry(
        Options.Axes,
        [
            "ControlArrayHandle",
            "falcon_core::math::arrays::ControlArray",
            "falcon_core::math::arrays::ControlArraySP",
            "ControlArray",
        ],
        [
            '"falcon_core/math/arrays/ControlArray_c_api.h"',
            '"falcon_core/generic/ListControlArray_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/List.hpp>",
            "<falcon_core/math/arrays/ControlArray.hpp>",
        ],
        Path("math"),
    ),
    "LabelledControlArrayAxes": Entry(
        Options.Axes,
        [
            "LabelledControlArrayHandle",
            "falcon_core::math::arrays::LabelledControlArray",
            "falcon_core::math::arrays::LabelledControlArraySP",
            "LabelledControlArray",
        ],
        [
            '"falcon_core/math/arrays/LabelledControlArray_c_api.h"',
            '"falcon_core/generic/ListLabelledControlArray_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/List.hpp>",
            "<falcon_core/math/arrays/LabelledControlArray.hpp>",
        ],
        Path("math"),
    ),
    "LabelledControlArray1DAxes": Entry(
        Options.Axes,
        [
            "LabelledControlArray1DHandle",
            "falcon_core::math::arrays::LabelledControlArray1D",
            "falcon_core::math::arrays::LabelledControlArray1DSP",
            "LabelledControlArray1D",
        ],
        [
            '"falcon_core/math/arrays/LabelledControlArray1D_c_api.h"',
            '"falcon_core/generic/ListLabelledControlArray1D_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/List.hpp>",
            "<falcon_core/math/arrays/LabelledControlArray1D.hpp>",
        ],
        Path("math"),
    ),
    "LabelledMeasuredArrayAxes": Entry(
        Options.Axes,
        [
            "LabelledMeasuredArrayHandle",
            "falcon_core::math::arrays::LabelledMeasuredArray",
            "falcon_core::math::arrays::LabelledMeasuredArraySP",
            "LabelledMeasuredArray",
        ],
        [
            '"falcon_core/math/arrays/LabelledMeasuredArray_c_api.h"',
            '"falcon_core/generic/ListLabelledMeasuredArray_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/List.hpp>",
            "<falcon_core/math/arrays/LabelledMeasuredArray.hpp>",
        ],
        Path("math"),
    ),
    "LabelledMeasuredArray1DAxes": Entry(
        Options.Axes,
        [
            "LabelledMeasuredArray1DHandle",
            "falcon_core::math::arrays::LabelledMeasuredArray1D",
            "falcon_core::math::arrays::LabelledMeasuredArray1DSP",
            "LabelledMeasuredArray1D",
        ],
        [
            '"falcon_core/math/arrays/LabelledMeasuredArray1D_c_api.h"',
            '"falcon_core/generic/ListLabelledMeasuredArray1D_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/List.hpp>",
            "<falcon_core/math/arrays/LabelledMeasuredArray1D.hpp>",
        ],
        Path("math"),
    ),
    "ControlArray1DAxes": Entry(
        Options.Axes,
        [
            "ControlArray1DHandle",
            "falcon_core::math::arrays::ControlArray1D",
            "falcon_core::math::arrays::ControlArray1DSP",
            "ControlArray1D",
        ],
        [
            '"falcon_core/math/arrays/ControlArray1D_c_api.h"',
            '"falcon_core/generic/ListControlArray1D_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/List.hpp>",
            "<falcon_core/math/arrays/ControlArray1D.hpp>",
        ],
        Path("math"),
    ),
    "InstrumentPortAxes": Entry(
        Options.Axes,
        [
            "InstrumentPortHandle",
            "falcon_core::instrument_interfaces::names::InstrumentPort",
            "falcon_core::instrument_interfaces::names::InstrumentPortSP",
            "InstrumentPort",
        ],
        [
            '"falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"',
            '"falcon_core/generic/ListInstrumentPort_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/List.hpp>",
            "<falcon_core/instrument_interfaces/names/InstrumentPort.hpp>",
        ],
        Path("math"),
    ),
    "CoupledLabelledDomainAxes": Entry(
        Options.Axes,
        [
            "CoupledLabelledDomainHandle",
            "falcon_core::math::domains::CoupledLabelledDomain",
            "falcon_core::math::domains::CoupledLabelledDomainSP",
            "CoupledLabelledDomain",
        ],
        [
            '"falcon_core/math/domains/CoupledLabelledDomain_c_api.h"',
            '"falcon_core/generic/ListCoupledLabelledDomain_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/List.hpp>",
            "<falcon_core/math/domains/CoupledLabelledDomain.hpp>",
        ],
        Path("math"),
    ),
    "MeasurementContextAxes": Entry(
        Options.Axes,
        [
            "MeasurementContextHandle",
            "falcon_core::autotuner_interfaces::contexts::MeasurementContext",
            "falcon_core::autotuner_interfaces::contexts::MeasurementContextSP",
            "MeasurementContext",
        ],
        [
            '"falcon_core/autotuner_interfaces/contexts/MeasurementContext_c_api.h"',
            '"falcon_core/generic/ListMeasurementContext_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/List.hpp>",
            "<falcon_core/autotuner_interfaces/contexts/MeasurementContext.hpp>",
        ],
        Path("math"),
    ),
    "MapStringBoolAxes": Entry(
        Options.Axes,
        [
            "MapStringBoolHandle",
            "falcon_core::generic::Map<std::string, bool>",
            "falcon_core::generic::MapSP<std::string, bool>",
            "MapStringBool",
        ],
        [
            '"falcon_core/generic/ListMapStringBool_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/List.hpp>",
            "<falcon_core/generic/Map.hpp>",
        ],
        Path("math"),
    ),
    "LabelledControlArrayLabelledArrays": Entry(
        Options.LabelledArrays,
        [
            "LabelledControlArrayHandle",
            "falcon_core::math::arrays::LabelledControlArray",
            "falcon_core::math::arrays::LabelledControlArraySP",
            "LabelledControlArray",
        ],
        [
            '"falcon_core/generic/ListLabelledControlArray_c_api.h"',
            '"falcon_core/generic/ListAcquisitionContext_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/List.hpp>",
            "<falcon_core/math/arrays/LabelledArrays.hpp>",
            "<falcon_core/math/arrays/LabelledControlArray.hpp>",
        ],
        Path("math/arrays"),
    ),
    "LabelledControlArray1DLabelledArrays": Entry(
        Options.LabelledArrays,
        [
            "LabelledControlArray1DHandle",
            "falcon_core::math::arrays::LabelledControlArray1D",
            "falcon_core::math::arrays::LabelledControlArray1DSP",
            "LabelledControlArray1D",
        ],
        [
            '"falcon_core/generic/ListLabelledControlArray1D_c_api.h"',
            '"falcon_core/generic/ListAcquisitionContext_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/List.hpp>",
            "<falcon_core/math/arrays/LabelledArrays.hpp>",
            "<falcon_core/math/arrays/LabelledControlArray1D.hpp>",
        ],
        Path("math/arrays"),
    ),
    "LabelledMeasuredArrayLabelledArrays": Entry(
        Options.LabelledArrays,
        [
            "LabelledMeasuredArrayHandle",
            "falcon_core::math::arrays::LabelledMeasuredArray",
            "falcon_core::math::arrays::LabelledMeasuredArraySP",
            "LabelledMeasuredArray",
        ],
        [
            '"falcon_core/generic/ListLabelledMeasuredArray_c_api.h"',
            '"falcon_core/generic/ListAcquisitionContext_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/List.hpp>",
            "<falcon_core/math/arrays/LabelledArrays.hpp>",
            "<falcon_core/math/arrays/LabelledMeasuredArray.hpp>",
        ],
        Path("math/arrays"),
    ),
    "LabelledMeasuredArray1DLabelledArrays": Entry(
        Options.LabelledArrays,
        [
            "LabelledMeasuredArray1DHandle",
            "falcon_core::math::arrays::LabelledMeasuredArray1D",
            "falcon_core::math::arrays::LabelledMeasuredArray1DSP",
            "LabelledMeasuredArray1D",
        ],
        [
            '"falcon_core/generic/ListLabelledMeasuredArray1D_c_api.h"',
            '"falcon_core/generic/ListAcquisitionContext_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/List.hpp>",
            "<falcon_core/math/arrays/LabelledArrays.hpp>",
            "<falcon_core/math/arrays/LabelledMeasuredArray1D.hpp>",
        ],
        Path("math/arrays"),
    ),
    "DoubleInterpretationContainer": Entry(
        Options.InterpretationContainer,
        [
            "double",
            "double",
            "double",
            "Double",
        ],
        [
            '"falcon_core/generic/ListConnection_c_api.h"',
            '"falcon_core/physics/units/SymbolUnit_c_api.h"',
            '"falcon_core/physics/device_structures/Connections_c_api.h"',
            '"falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"',
            '"falcon_core/generic/ListInterpretationContext_c_api.h"',
            '"falcon_core/generic/ListDouble_c_api.h"',
            '"falcon_core/generic/ListPairInterpretationContextDouble_c_api.h"',
            '"falcon_core/generic/MapInterpretationContextDouble_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/List.hpp>",
            "<falcon_core/generic/Pair.hpp>",
            "<falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp>",
            "<falcon_core/physics/device_structures/Connections.hpp>",
            "<falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>",
        ],
        Path("autotuner_interfaces/interpretations"),
    ),
    "StringInterpretationContainer": Entry(
        Options.InterpretationContainer,
        [
            "StringHandle",
            "std::string",
            "std::string",
            "String",
        ],
        [
            '"falcon_core/generic/ListConnection_c_api.h"',
            '"falcon_core/physics/units/SymbolUnit_c_api.h"',
            '"falcon_core/physics/device_structures/Connections_c_api.h"',
            '"falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"',
            '"falcon_core/generic/ListInterpretationContext_c_api.h"',
            '"falcon_core/generic/ListString_c_api.h"',
            '"falcon_core/generic/ListPairInterpretationContextString_c_api.h"',
            '"falcon_core/generic/MapInterpretationContextString_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/List.hpp>",
            "<falcon_core/generic/Pair.hpp>",
            "<falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp>",
            "<falcon_core/physics/device_structures/Connections.hpp>",
            "<falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>",
        ],
        Path("autotuner_interfaces/interpretations"),
    ),
    "QuantityInterpretationContainer": Entry(
        Options.InterpretationContainer,
        [
            "QuantityHandle",
            "falcon_core::math::Quantity",
            "falcon_core::math::QuantitySP",
            "Quantity",
        ],
        [
            '"falcon_core/generic/ListConnection_c_api.h"',
            '"falcon_core/physics/units/SymbolUnit_c_api.h"',
            '"falcon_core/physics/device_structures/Connections_c_api.h"',
            '"falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"',
            '"falcon_core/generic/ListInterpretationContext_c_api.h"',
            '"falcon_core/generic/ListQuantity_c_api.h"',
            '"falcon_core/generic/ListPairInterpretationContextQuantity_c_api.h"',
            '"falcon_core/generic/MapInterpretationContextQuantity_c_api.h"',
            "<stddef.h>",
            "<stdbool.h>",
        ],
        [
            "<falcon_core/generic/List.hpp>",
            "<falcon_core/generic/Pair.hpp>",
            "<falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp>",
            "<falcon_core/physics/device_structures/Connections.hpp>",
            "<falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>",
            "<falcon_core/math/Quantity.hpp>",
        ],
        Path("autotuner_interfaces/interpretations"),
    ),
}
entry_queue: list[str] = [
    "SizeTList",
    "StringList",
    "BoolList",
    "StringDoublePair",
    "StringBoolPair",
    "SizeTSizeTPair",
    "PairSizeTSizeTList",
    "PairStringDoubleList",
    "ListSizeTList",
    "DoubleFArray",
    "FArrayDoubleList",
    "IntFArray",
    "IntList",
    "FloatList",
    "DoubleList",
    "IntIntPair",
    "FloatFloatPair",
    "DoubleDoublePair",
    "IntFloatPair",
    "QuantityQuantityPair",
    "PairQuantityQuantityList",
    "ConnectionFloatPair",
    "ConnectionDoublePair",
    "ConnectionConnectionPair",
    "ConnectionList",
    "ChannelList",
    "QuantityList",
    "DeviceVoltageStateList",
    "LabelledDomainList",
    "InstrumentPortList",
    "ConnectionsList",
    "ImpedanceList",
    "ConnectionConnectionsPair",
    "PairIntIntList",
    "PairFloatFloatList",
    "PairIntFloatList",
    "PairConnectionFloatList",
    "PairConnectionDoubleList",
    "PairConnectionConnectionsList",
    "StringDoubleMap",
    "IntIntMap",
    "FloatFloatMap",
    "ConnectionFloatMap",
    "ConnectionDoubleMap",
    "ConnectionQuantityPair",
    "PairConnectionQuantityList",
    "ConnectionQuantityMap",
    "ConnectionPairQuantityQuantityPair",
    "PairConnectionPairQuantityQuantityList",
    "DiscretizerList",
    "DoubleAxes",
    "IntAxes",
    "DiscretizerAxes",
    "ControlArrayList",
    "ControlArrayAxes",
    "ControlArray1DList",
    "ControlArray1DAxes",
    "CoupledLabelledDomainList",
    "CoupledLabelledDomainAxes",
    "PairStringBoolList",
    "StringBoolMap",
    "InstrumentPortAxes",
    "MapStringBoolList",
    "MapStringBoolAxes",
    "DotGateWithNeighborsList",
    "GroupList",
    "GnameList",
    "ChannelConnectionsPair",
    "PairChannelConnectionsList",
    "ChannelConnectionsMap",
    "GnameGroupPair",
    "PairGnameGroupList",
    "GnameGroupMap",
    "MeasurementContextList",
    "MeasurementContextAxes",
    "PortTransformList",
    "WaveformList",
    "InstrumentPortPortTransformPair",
    "PairInstrumentPortPortTransformList",
    "InstrumentPortPortTransformMap",
    "LabelledControlArrayList",
    "LabelledControlArrayAxes",
    "AcquisitionContextList",
    "LabelledControlArrayLabelledArrays",
    "LabelledControlArray1DList",
    "LabelledControlArray1DAxes",
    "LabelledControlArray1DLabelledArrays",
    "LabelledMeasuredArrayList",
    "LabelledMeasuredArrayAxes",
    "LabelledMeasuredArrayLabelledArrays",
    "LabelledMeasuredArray1DList",
    "LabelledMeasuredArray1DAxes",
    "LabelledMeasuredArray1DLabelledArrays",
    "StringStringPair",
    "PairStringStringList",
    "StringStringMap",
    "MeasurementResponseMeasurementRequestPair",
    "InterpretationContextList",
    "InterpretationContextDoublePair",
    "PairInterpretationContextDoubleList",
    "InterpretationContextDoubleMap",
    "DoubleInterpretationContainer",
    "InterpretationContextStringPair",
    "InterpretationContextStringMap",
    "PairInterpretationContextStringList",
    "StringInterpretationContainer",
    "InterpretationContextQuantityPair",
    "PairInterpretationContextQuantityList",
    "InterpretationContextQuantityMap",
    "QuantityInterpretationContainer",
]


if __name__ == "__main__":
    if len(entry_queue) != len(registry):
        raise RuntimeError(
            f"Invalid number of items in the entry_queue. Expected {len(registry)} but got {len(entry_queue)}"
        )
    for name in entry_queue:
        if name not in registry.keys():
            raise ValueError(
                f"Invalid name {name} used that was not present in the registry."
            )
        entry = registry[name]
        print(f"Working on {entry.temp.name} for {entry.name()}")
        entry.generate_header()
        entry.generate_implementation()
        print(f"Generated {entry.header_path}")
        print(f"Generated {entry.implementation_path}")
        add_to_manifest(
            generated_file_manifest, entry.header_path, entry.implementation_path
        )
