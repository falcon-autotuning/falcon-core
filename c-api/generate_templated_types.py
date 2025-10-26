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
// Serialization (from Song)
StringHandle      {self.mangled_name()}_to_json_string({self.chandle()} handle);
{self.chandle()} {self.mangled_name()}_from_json_string(StringHandle json);
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
        with self.edit_header() as f:
            f.write(f"""
{self.chandle()} {self.mangled_name()}_create_empty();
{self.chandle()} {self.mangled_name()}_allocate(size_t count);
{self.chandle()} {self.mangled_name()}_fill_value(size_t count, {c_type} value);
{self.chandle()} {self.mangled_name()}_create(const {c_type}* data, size_t count);
void {self.mangled_name()}_destroy({self.chandle()} handle);
void {self.mangled_name()}_push_back({self.chandle()} handle, {c_type} value);
size_t {self.mangled_name()}_size({self.chandle()} handle);
bool {self.mangled_name()}_empty({self.chandle()} handle);
void {self.mangled_name()}_erase_at({self.chandle()} handle, size_t idx);
void {self.mangled_name()}_clear({self.chandle()} handle);
{c_type} {self.mangled_name()}_at({self.chandle()} handle, size_t idx);
size_t {self.mangled_name()}_items({self.chandle()} handle, {c_type}* out_buffer, size_t buffer_size);
bool {self.mangled_name()}_contains({self.chandle()} handle, {c_type} value);
size_t {self.mangled_name()}_index({self.chandle()} handle, {c_type} value);
{self.chandle()} {self.mangled_name()}_intersection({self.chandle()} handle, {self.chandle()} other);
bool {self.mangled_name()}_equal({self.chandle()} a, {self.chandle()} b);
bool {self.mangled_name()}_not_equal({self.chandle()} a, {self.chandle()} b);
""")

    def generate_axes_header(self):
        c_type = self.combo[0]
        with self.edit_header() as f:
            f.write(f"""
{self.chandle()} {self.mangled_name()}_create_empty();
{self.chandle()} {self.mangled_name()}_create_raw(const {c_type}* data, size_t count);
{self.chandle()} {self.mangled_name()}_create(List{self.name()}Handle data);
void {self.mangled_name()}_destroy({self.chandle()} handle);
void {self.mangled_name()}_push_back({self.chandle()} handle, {c_type} value);
size_t {self.mangled_name()}_size({self.chandle()} handle);
bool {self.mangled_name()}_empty({self.chandle()} handle);
void {self.mangled_name()}_erase_at({self.chandle()} handle, size_t idx);
void {self.mangled_name()}_clear({self.chandle()} handle);
{c_type} {self.mangled_name()}_at({self.chandle()} handle, size_t idx);
size_t {self.mangled_name()}_items({self.chandle()} handle, {c_type}* out_buffer, size_t buffer_size);
bool {self.mangled_name()}_contains({self.chandle()} handle, {c_type} value);
size_t {self.mangled_name()}_index({self.chandle()} handle, {c_type} value);
{self.chandle()} {self.mangled_name()}_intersection({self.chandle()} handle, {self.chandle()} other);
bool {self.mangled_name()}_equal({self.chandle()} a, {self.chandle()} b);
bool {self.mangled_name()}_not_equal({self.chandle()} a, {self.chandle()} b);
""")

    def generate_pair_header(self):
        c_type_1 = self.combo[0]
        c_type_2 = self.combo[3]
        with self.edit_header() as f:
            f.write(f"""
{self.chandle()} {self.mangled_name()}_create({c_type_1} first, {c_type_2} second);
void {self.mangled_name()}_destroy({self.chandle()} handle);
{c_type_1} {self.mangled_name()}_first({self.chandle()} handle);
{c_type_2} {self.mangled_name()}_second({self.chandle()} handle);
bool {self.mangled_name()}_equal({self.chandle()} a, {self.chandle()} b);""")

    def generate_farray_header(self):
        c_type = self.combo[0]
        # TODO: view and operator() are not wrapped
        with self.edit_header() as f:
            f.write(f"""
{self.chandle()} {self.mangled_name()}_create_empty();
{self.chandle()} {self.mangled_name()}_create_zeros();
{self.chandle()} {self.mangled_name()}_from_shape(const size_t* shape, size_t ndim);
{self.chandle()} {self.mangled_name()}_from_data(const {c_type}* data, const size_t* shape, size_t ndim);
void {self.mangled_name()}_destroy({self.chandle()} handle);
size_t {self.mangled_name()}_size({self.chandle()} handle);
size_t {self.mangled_name()}_dimension({self.chandle()} handle);
size_t {self.mangled_name()}_shape({self.chandle()} handle, size_t* out_buffer, size_t ndim);
size_t {self.mangled_name()}_data({self.chandle()} handle, {c_type}* out_buffer, size_t numdata);
void {self.mangled_name()}_plusequals_farray({self.chandle()} handle, {self.chandle()} other);
void {self.mangled_name()}_plusequals_double({self.chandle()} handle, const double other);
void {self.mangled_name()}_plusequals_int({self.chandle()} handle, const int other);
{self.chandle()} {self.mangled_name()}_plus_farray({self.chandle()} handle, {self.chandle()} other);
{self.chandle()} {self.mangled_name()}_plus_double({self.chandle()} handle, const double other);
{self.chandle()} {self.mangled_name()}_plus_int({self.chandle()} handle, const int other);
void {self.mangled_name()}_minusequals_farray({self.chandle()} handle, {self.chandle()} other);
void {self.mangled_name()}_minusequals_double({self.chandle()} handle, const double other);
void {self.mangled_name()}_minusequals_int({self.chandle()} handle, const int other);
{self.chandle()} {self.mangled_name()}_minus_farray({self.chandle()} handle, {self.chandle()} other);
{self.chandle()} {self.mangled_name()}_minus_double({self.chandle()} handle, const double other);
{self.chandle()} {self.mangled_name()}_minus_int({self.chandle()} handle, const int other);
{self.chandle()} {self.mangled_name()}_negation({self.chandle()} handle);
void {self.mangled_name()}_timesequals_farray({self.chandle()} handle, {self.chandle()} other);
void {self.mangled_name()}_timesequals_double({self.chandle()} handle, const double other);
void {self.mangled_name()}_timesequals_int({self.chandle()} handle, const int other);
{self.chandle()} {self.mangled_name()}_times_farray({self.chandle()} handle, {self.chandle()} other);
{self.chandle()} {self.mangled_name()}_times_double({self.chandle()} handle, const double other);
{self.chandle()} {self.mangled_name()}_times_int({self.chandle()} handle, const int other);
void {self.mangled_name()}_dividesequals_farray({self.chandle()} handle, {self.chandle()} other);
void {self.mangled_name()}_dividesequals_double({self.chandle()} handle, const double other);
void {self.mangled_name()}_dividesequals_int({self.chandle()} handle, const int other);
{self.chandle()} {self.mangled_name()}_divides_farray({self.chandle()} handle, {self.chandle()} other);
{self.chandle()} {self.mangled_name()}_divides_double({self.chandle()} handle, const double other);
{self.chandle()} {self.mangled_name()}_divides_int({self.chandle()} handle, const int other);
{self.chandle()} {self.mangled_name()}_pow({self.chandle()} handle, const double other);
{self.chandle()} {self.mangled_name()}_abs({self.chandle()} handle);
{self.chandle()} {self.mangled_name()}_min({self.chandle()} handle);
{self.chandle()} {self.mangled_name()}_min_arraywise({self.chandle()} handle, {self.chandle()} other);
{self.chandle()} {self.mangled_name()}_max({self.chandle()} handle);
{self.chandle()} {self.mangled_name()}_max_arraywise({self.chandle()} handle, {self.chandle()} other);
bool {self.mangled_name()}_equality({self.chandle()} handle, {self.chandle()} other);
bool {self.mangled_name()}_notequality({self.chandle()} handle, {self.chandle()} other);
bool {self.mangled_name()}_greaterthan({self.chandle()} handle, const {c_type} value);
bool {self.mangled_name()}_lessthan({self.chandle()} handle, const {c_type} value);
void {self.mangled_name()}_remove_offset({self.chandle()} handle, const {c_type} offset);
{c_type} {self.mangled_name()}_sum({self.chandle()} handle);
{self.chandle()} {self.mangled_name()}_reshape({self.chandle()} handle, const size_t* shape, size_t ndims);
ListListSizeTHandle {self.mangled_name()}_where({self.chandle()} handle, const {c_type} value);
{self.chandle()} {self.mangled_name()}_flip({self.chandle()} handle, size_t axis);
size_t {self.mangled_name()}_full_gradient({self.chandle()} handle, {self.chandle()}* out_buffer, size_t buffer_size);
{self.chandle()} {self.mangled_name()}_gradient({self.chandle()} handle, size_t axis);
double {self.mangled_name()}_get_sum_of_squares({self.chandle()} handle);
double {self.mangled_name()}_get_summed_diff_int_of_squares({self.chandle()} handle, const int other);
double {self.mangled_name()}_get_summed_diff_double_of_squares({self.chandle()} handle, const double other);
double {self.mangled_name()}_get_summed_diff_array_of_squares({self.chandle()} handle, {self.chandle()} other);""")

    def generate_map_header(self):
        c_key_type = self.combo[0]
        c_value_type = self.combo[3]
        key_name = self.combo[6]
        value_name = self.combo[7]
        name = self.combo[8]
        with self.edit_header() as f:
            f.write(f"""
{self.chandle()} {self.mangled_name()}_create_empty();
{self.chandle()} {self.mangled_name()}_create(const Pair{name}Handle* data, size_t count);
void {self.mangled_name()}_destroy({self.chandle()} handle);
void {self.mangled_name()}_insert_or_assign({self.chandle()} handle, const {c_key_type} key, const {c_value_type} value);
void {self.mangled_name()}_insert({self.chandle()} handle, const {c_key_type} key, const {c_value_type} value);
{c_value_type} {self.mangled_name()}_at({self.chandle()} handle, const {c_key_type} key);
void {self.mangled_name()}_erase({self.chandle()} handle, const {c_key_type} key);
size_t {self.mangled_name()}_size({self.chandle()} handle);
bool {self.mangled_name()}_empty({self.chandle()} handle);
void {self.mangled_name()}_clear({self.chandle()} handle);
bool {self.mangled_name()}_contains({self.chandle()} handle, const {c_key_type} key);
List{key_name}Handle {self.mangled_name()}_keys({self.chandle()} handle);
List{value_name}Handle {self.mangled_name()}_values({self.chandle()} handle);
ListPair{name}Handle {self.mangled_name()}_items({self.chandle()} handle);
bool {self.mangled_name()}_equal({self.chandle()} a, {self.chandle()} b);
bool {self.mangled_name()}_not_equal({self.chandle()} a, {self.chandle()} b);""")

    def generate_list_implementation(self):
        c_type = self.combo[0]
        cpp_real = self.combo[1]
        cpp_stored = self.combo[2]
        is_primitive = c_type in c_primitives
        if c_type == "StringHandle":
            stored_fill_value = self.from_cstring("value", "stored_obj")
            copy_to_out_buffer = """
    for (size_t i = 0; i < n; ++i) {
        auto str      = list->items()[i];
        out_buffer[i] = String_create(str.data(), str.size());
    }
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
        else:
            stored_fill_value = f"auto stored_obj = std::shared_ptr<{cpp_real}>(static_cast<{cpp_real}*>(value), []({cpp_real}*) {{}} );"
            copy_to_out_buffer = f"""
for (size_t i = 0; i < n; ++i) {{
    out_buffer[i] = new {cpp_real}(*list->items()[i]);
}}"""
            stored_out_value = f"return new {cpp_real}(*obj);"
            create_allocation = f"""    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {{
        vec.push_back(std::shared_ptr<{cpp_real}>(static_cast<{cpp_real}*>(data[i]), []({cpp_real}*) {{}} ));
    }}
"""
        with self.edit_implementation() as f:
            f.write(f"""
{self.chandle()} {self.mangled_name()}_create_empty() {{
    return new falcon_core::generic::List<{cpp_real}>(
        falcon_core::generic::List<{cpp_real}>());
}}

{self.chandle()} {self.mangled_name()}_fill_value(size_t count, {c_type} value) {{
    {stored_fill_value}
    return new falcon_core::generic::List<{cpp_real}>(
        falcon_core::generic::List<{cpp_real}>(count, stored_obj));
}}

{self.chandle()} {self.mangled_name()}_allocate(size_t count) {{
    return new falcon_core::generic::List<{cpp_real}>(
        falcon_core::generic::List<{cpp_real}>(count));
}}

{self.chandle()} {self.mangled_name()}_create({c_type}* data, size_t count) {{
    std::vector<{cpp_stored}> vec;
    {create_allocation}
    return new falcon_core::generic::List<{cpp_real}>(
        falcon_core::generic::List<{cpp_real}>(vec));
}}

void {self.mangled_name()}_destroy({self.chandle()} handle) {{
    delete static_cast<falcon_core::generic::List<{cpp_real}>*>(handle);
}}

size_t {self.mangled_name()}_size({self.chandle()} handle) {{
    return static_cast<falcon_core::generic::List<{cpp_real}>*>(handle)->size();
}}

bool {self.mangled_name()}_empty({self.chandle()} handle) {{
    return static_cast<falcon_core::generic::List<{cpp_real}>*>(handle)->empty();
}}

void {self.mangled_name()}_erase_at({self.chandle()} handle, size_t idx) {{
    static_cast<falcon_core::generic::List<{cpp_real}>*>(handle)->erase_at(idx);
}}

void {self.mangled_name()}_clear({self.chandle()} handle) {{
    static_cast<falcon_core::generic::List<{cpp_real}>*>(handle)->clear();
}}

void {self.mangled_name()}_push_back({self.chandle()} handle, {c_type} value) {{
    {stored_fill_value}
    static_cast<falcon_core::generic::List<{cpp_real}>*>(handle)->push_back(stored_obj);
}}

bool {self.mangled_name()}_contains({self.chandle()} handle, {c_type} value) {{
    {stored_fill_value}
    return static_cast<falcon_core::generic::List<{cpp_real}>*>(handle)->contains(stored_obj);
}}

size_t {self.mangled_name()}_index({self.chandle()} handle, {c_type} value) {{
    {stored_fill_value}
    return static_cast<falcon_core::generic::List<{cpp_real}>*>(handle)->index(stored_obj);
}}

size_t {self.mangled_name()}_items({self.chandle()} handle, {c_type}* out_buffer, size_t buffer_size) {{
    auto list = static_cast<falcon_core::generic::List<{cpp_real}>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    {copy_to_out_buffer}
    return n;
}}

{c_type} {self.mangled_name()}_at({self.chandle()} handle, size_t idx) {{
    auto obj = static_cast<falcon_core::generic::List<{cpp_real}>*>(handle)->at(idx);
    {stored_out_value}
}}

bool {self.mangled_name()}_equal({self.chandle()} a, {self.chandle()} b) {{
    auto listA = static_cast<falcon_core::generic::List<{cpp_real}>*>(a);
    auto listB = static_cast<falcon_core::generic::List<{cpp_real}>*>(b);
    return *listA == *listB;
}}

bool {self.mangled_name()}_not_equal({self.chandle()} a, {self.chandle()} b) {{
    return !{self.mangled_name()}_equal(a, b);
}}

{self.chandle()} {self.mangled_name()}_intersection({self.chandle()} handle, {self.chandle()} other) {{
    auto listA = static_cast<falcon_core::generic::List<{cpp_real}>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<{cpp_real}>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<{cpp_real}>>(*listB));
    return new falcon_core::generic::List<{cpp_real}>(*result);
}}

StringHandle      {self.mangled_name()}_to_json_string({self.chandle()} handle) {{
    std::string json = static_cast<falcon_core::generic::List<{cpp_real}>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}}
{self.chandle()} {self.mangled_name()}_from_json_string(StringHandle json) {{
  auto ptr = falcon_core::generic::List<{cpp_real}>::from_json_string<falcon_core::generic::List<{cpp_real}>>(json->raw);
  return new falcon_core::generic::List<{cpp_real}>(*ptr);
}}
""")

    def generate_axes_implementation(self):
        c_type = self.combo[0]
        cpp_real = self.combo[1]
        cpp_stored = self.combo[2]
        is_primitive = c_type in c_primitives
        if c_type == "StringHandle":
            stored_fill_value = self.from_cstring("value", "stored_obj")
            copy_to_out_buffer = """
    for (size_t i = 0; i < n; ++i) {
        auto str      = list->items()[i];
        out_buffer[i] = String_create(str.data(), str.size());
    }
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
        else:
            stored_fill_value = f"auto stored_obj = std::shared_ptr<{cpp_real}>(static_cast<{cpp_real}*>(value), []({cpp_real}*) {{}} );"
            copy_to_out_buffer = f"""
for (size_t i = 0; i < n; ++i) {{
    out_buffer[i] = new {cpp_real}(*list->items()[i]);
}}"""
            stored_out_value = f"return new {cpp_real}(*obj);"
            create_allocation = f"""    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {{
        vec.push_back(std::shared_ptr<{cpp_real}>(static_cast<{cpp_real}*>(data[i]), []({cpp_real}*) {{}} ));
    }}
"""
        with self.edit_implementation() as f:
            f.write(f"""
{self.chandle()} {self.mangled_name()}_create_empty() {{
    return new falcon_core::math::Axes<{cpp_real}>(
        falcon_core::math::Axes<{cpp_real}>());
}}

{self.chandle()} {self.mangled_name()}_create_raw(const {c_type}* data, size_t count) {{
    std::vector<{cpp_stored}> vec;
    {create_allocation}
    return new falcon_core::math::Axes<{cpp_real}>(
        falcon_core::math::Axes<{cpp_real}>(vec));
}}

{self.chandle()} {self.mangled_name()}_create(List{self.name()}Handle data) {{
    auto list = static_cast<falcon_core::generic::List<{cpp_real}>*>(data);
    return new falcon_core::math::Axes<{cpp_real}>(
            std::shared_ptr<falcon_core::generic::List<{cpp_real}>>(list));
}}

void {self.mangled_name()}_destroy({self.chandle()} handle) {{
    delete static_cast<falcon_core::math::Axes<{cpp_real}>*>(handle);
}}

size_t {self.mangled_name()}_size({self.chandle()} handle) {{
    return static_cast<falcon_core::math::Axes<{cpp_real}>*>(handle)->size();
}}

bool {self.mangled_name()}_empty({self.chandle()} handle) {{
    return static_cast<falcon_core::math::Axes<{cpp_real}>*>(handle)->empty();
}}

void {self.mangled_name()}_erase_at({self.chandle()} handle, size_t idx) {{
    static_cast<falcon_core::math::Axes<{cpp_real}>*>(handle)->erase_at(idx);
}}

void {self.mangled_name()}_clear({self.chandle()} handle) {{
    static_cast<falcon_core::math::Axes<{cpp_real}>*>(handle)->clear();
}}

void {self.mangled_name()}_push_back({self.chandle()} handle, {c_type} value) {{
    {stored_fill_value}
    static_cast<falcon_core::math::Axes<{cpp_real}>*>(handle)->push_back(stored_obj);
}}

bool {self.mangled_name()}_contains({self.chandle()} handle, {c_type} value) {{
    {stored_fill_value}
    return static_cast<falcon_core::math::Axes<{cpp_real}>*>(handle)->contains(stored_obj);
}}

size_t {self.mangled_name()}_index({self.chandle()} handle, {c_type} value) {{
    {stored_fill_value}
    return static_cast<falcon_core::math::Axes<{cpp_real}>*>(handle)->index(stored_obj);
}}

size_t {self.mangled_name()}_items({self.chandle()} handle, {c_type}* out_buffer, size_t buffer_size) {{
    auto list = static_cast<falcon_core::math::Axes<{cpp_real}>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    {copy_to_out_buffer}
    return n;
}}

{c_type} {self.mangled_name()}_at({self.chandle()} handle, size_t idx) {{
    auto obj = static_cast<falcon_core::math::Axes<{cpp_real}>*>(handle)->at(idx);
    {stored_out_value}
}}

bool {self.mangled_name()}_equal({self.chandle()} a, {self.chandle()} b) {{
    auto listA = static_cast<falcon_core::math::Axes<{cpp_real}>*>(a);
    auto listB = static_cast<falcon_core::math::Axes<{cpp_real}>*>(b);
    return *listA == *listB;
}}

bool {self.mangled_name()}_not_equal({self.chandle()} a, {self.chandle()} b) {{
    return !{self.mangled_name()}_equal(a, b);
}}

{self.chandle()} {self.mangled_name()}_intersection({self.chandle()} handle, {self.chandle()} other) {{
    auto listA = static_cast<falcon_core::math::Axes<{cpp_real}>*>(handle);
    auto listB = static_cast<falcon_core::math::Axes<{cpp_real}>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::math::Axes<{cpp_real}>>(*listB));
    return new falcon_core::math::Axes<{cpp_real}>(result);
}}

StringHandle      {self.mangled_name()}_to_json_string({self.chandle()} handle) {{
    std::string json = static_cast<falcon_core::math::Axes<{cpp_real}>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}}
{self.chandle()} {self.mangled_name()}_from_json_string(StringHandle json) {{
  auto ptr = falcon_core::math::Axes<{cpp_real}>::from_json_string<falcon_core::math::Axes<{cpp_real}>>(json->raw);
  return new falcon_core::math::Axes<{cpp_real}>(*ptr);
}}
""")

    def generate_pair_implementation(self):
        c_type_1 = self.combo[0]
        cpp_real_1 = self.combo[1]
        cpp_stored_1 = self.combo[2]
        c_type_2 = self.combo[3]
        cpp_real_2 = self.combo[4]
        cpp_stored_2 = self.combo[5]
        is_primitive_1 = c_type_1 in c_primitives
        is_primitive_2 = c_type_2 in c_primitives
        with self.edit_implementation() as f:
            if c_type_1 == "StringHandle":
                first_create_adjustment = self.from_cstring("first", "first_obj")
            elif is_primitive_1:
                first_create_adjustment = "auto first_obj = first;"
            else:
                first_create_adjustment = f"auto first_obj= std::shared_ptr<{cpp_real_1}>(static_cast<{cpp_real_1}*>(first),[]({cpp_real_1}*) {{}});"
            if c_type_2 == "StringHandle":
                second_create_adjustment = self.from_cstring("second", "second_obj")
            elif is_primitive_2:
                second_create_adjustment = "auto second_obj = second;"
            else:
                second_create_adjustment = f"auto second_obj= std::shared_ptr<{cpp_real_2}>(static_cast<{cpp_real_2}*>(second),[]({cpp_real_2}*) {{}});"
            # Generate first() function
            if c_type_1 == "StringHandle":
                first_return = f"""
std::string cppstring = static_cast<falcon_core::generic::Pair<{cpp_real_1}, {cpp_real_2}>*>(handle)->first();
{self.to_cstring("cstr", "cppstring")}
return cstr;"""
            elif is_primitive_1:
                first_return = f"return static_cast<falcon_core::generic::Pair<{cpp_real_1}, {cpp_real_2}>*>(handle)->first();"
            else:
                first_return = f"""auto pair = static_cast<falcon_core::generic::Pair<{cpp_real_1}, {cpp_real_2}>*>(handle);
    return new {cpp_real_1}(*pair->first());"""

            # Generate second() function
            if c_type_2 == "StringHandle":
                second_return = f"""
std::string cppstring = static_cast<falcon_core::generic::Pair<{cpp_real_1}, {cpp_real_2}>*>(handle)->second();
{self.to_cstring("cstr", "cppstring")}
return cstr;"""
            elif is_primitive_2:
                second_return = f"return static_cast<falcon_core::generic::Pair<{cpp_real_1}, {cpp_real_2}>*>(handle)->second();"
            else:
                second_return = f"""auto pair = static_cast<falcon_core::generic::Pair<{cpp_real_1}, {cpp_real_2}>*>(handle);
    return new {cpp_real_2}(*pair->second());"""

            # Write the complete implementation
            f.write(f"""
{self.chandle()} {self.mangled_name()}_create({c_type_1} first, {c_type_2} second) {{
    {first_create_adjustment}
    {second_create_adjustment}
    return new falcon_core::generic::Pair<{cpp_real_1}, {cpp_real_2}>(first_obj, second_obj);
}}

void {self.mangled_name()}_destroy({self.chandle()} handle) {{
    delete static_cast<falcon_core::generic::Pair<{cpp_real_1}, {cpp_real_2}>*>(handle);
}}

{c_type_1} {self.mangled_name()}_first({self.chandle()} handle) {{
    {first_return}
}}

{c_type_2} {self.mangled_name()}_second({self.chandle()} handle) {{
    {second_return}
}}

bool {self.mangled_name()}_equal({self.chandle()} a, {self.chandle()} b) {{
    auto pair_a = static_cast<falcon_core::generic::Pair<{cpp_real_1}, {cpp_real_2}>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<{cpp_real_1}, {cpp_real_2}>*>(b);
    return *pair_a == *pair_b;
}}

StringHandle      {self.mangled_name()}_to_json_string({self.chandle()} handle) {{
std::string json = static_cast<falcon_core::generic::Pair<{cpp_real_1},{cpp_real_2}>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}}
{self.chandle()} {self.mangled_name()}_from_json_string(StringHandle json) {{
  auto ptr = falcon_core::generic::Pair<{cpp_real_1},{cpp_real_2}>::from_json_string<falcon_core::generic::Pair<{cpp_real_1},{cpp_real_2}>>(json->raw);
  return new falcon_core::generic::Pair<{cpp_real_1},{cpp_real_2}>(*ptr);
}}
""")

    def generate_map_implementation(self):
        c_key_type = self.combo[0]
        cpp_key_type = self.combo[1]
        cpp_stored_key_type = self.combo[2]
        c_value_type = self.combo[3]
        cpp_value_type = self.combo[4]
        cpp_stored_value_type = self.combo[5]
        key_name = self.combo[6]
        value_name = self.combo[7]
        name = self.combo[8]
        is_primitive_key = c_key_type in c_primitives
        is_primitive_value = c_value_type in c_primitives
        if c_key_type == "StringHandle":
            correct_key = "auto correct_key = std::string(key->raw, key->length);"
        elif not is_primitive_key:
            correct_key = f"""auto temp_key = *static_cast<{cpp_key_type}*>(key);
auto correct_key = std::make_shared<{cpp_key_type}>(temp_key);"""
        else:
            correct_key = """auto correct_key = key;"""
        if c_value_type == "StringHandle":
            correct_value = (
                "auto correct_value = std::string(value->raw, value->length);"
            )
            at_return = "return String_wrap(static_cast<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>*>(handle)->at(correct_key)"
        elif not is_primitive_value:
            correct_value = f"""auto temp_value = *static_cast<{cpp_value_type}*>(value);
auto correct_value = std::make_shared<{cpp_value_type}>(temp_value);"""
            at_return = f"""return new {cpp_value_type}(*static_cast<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>*>(handle)->at(correct_key));"""
        else:
            correct_value = """auto correct_value = value;"""
            at_return = f"""return static_cast<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>*>(handle)->at(correct_key);"""
        with self.edit_implementation() as f:
            f.write(f"""
{self.chandle()} {self.mangled_name()}_create_empty() {{
    return new falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>(
            falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>());
}}

{self.chandle()} {self.mangled_name()}_create(const Pair{name}Handle* data, size_t count) {{
    std::vector<falcon_core::generic::PairSP<{cpp_key_type},{cpp_value_type}>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {{
        vec.push_back(*reinterpret_cast<
                    std::shared_ptr<falcon_core::generic::Pair<{cpp_key_type},{cpp_value_type}>>*>(
            data[i]));
    }}
    return new falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>(
            falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>(vec));
}}

void {self.mangled_name()}_destroy({self.chandle()} handle) {{
    delete static_cast<falcon_core::generic::Map<{cpp_key_type}, {cpp_value_type}>*>(handle);
}}

void {self.mangled_name()}_insert_or_assign({self.chandle()} handle, const {c_key_type} key, const {c_value_type} value) {{
    {correct_key}
    {correct_value}
    static_cast<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>*>(handle)->insert_or_assign(correct_key,correct_value);
}}

void {self.mangled_name()}_insert({self.chandle()} handle, const {c_key_type} key, const {c_value_type} value) {{
    {correct_key}
    {correct_value}
    static_cast<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>*>(handle)->insert(correct_key,correct_value);
}}

{c_value_type} {self.mangled_name()}_at({self.chandle()} handle, const {c_key_type} key) {{
    {correct_key}
    {at_return}
}}

void {self.mangled_name()}_erase({self.chandle()} handle, const {c_key_type} key) {{
    {correct_key}
    return static_cast<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>*>(handle)->erase(correct_key);
}}

size_t {self.mangled_name()}_size({self.chandle()} handle) {{
    return static_cast<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>*>(handle)->size();
}}

bool {self.mangled_name()}_empty({self.chandle()} handle) {{
    return static_cast<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>*>(handle)->empty();
}}


void {self.mangled_name()}_clear({self.chandle()} handle) {{
    return static_cast<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>*>(handle)->clear();
}}

bool {self.mangled_name()}_contains({self.chandle()} handle, {c_key_type} key) {{
    {correct_key}
    return static_cast<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>*>(handle)->contains(correct_key);
}}

List{key_name}Handle {self.mangled_name()}_keys({self.chandle()} handle) {{
    auto map = static_cast<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>*>(handle);
    auto keys_sp = map->keys(); // shared_ptr<falcon_core::generic::List<Key>>
    return new falcon_core::generic::List<{cpp_key_type}>(*keys_sp);
}}

List{value_name}Handle {self.mangled_name()}_values({self.chandle()} handle) {{
    auto map = static_cast<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>*>(handle);
    auto values_sp = map->values(); // shared_ptr<falcon_core::generic::List<Value>>
    return new falcon_core::generic::List<{cpp_value_type}>(*values_sp);
}}

ListPair{name}Handle {self.mangled_name()}_items({self.chandle()} handle) {{
    auto map = static_cast<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>*>(handle);
    falcon_core::generic::List<falcon_core::generic::Pair<{cpp_key_type},{cpp_value_type}>> items_sp = map->items(); 
    return new falcon_core::generic::List<falcon_core::generic::Pair<{cpp_key_type},{cpp_value_type}>>(items_sp);
}}

bool {self.mangled_name()}_equal({self.chandle()} a, {self.chandle()} b) {{
    auto listA = static_cast<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>*>(a);
    auto listB = static_cast<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>*>(b);
    return *listA == *listB;
}}

bool {self.mangled_name()}_not_equal({self.chandle()} a, {self.chandle()} b) {{
    return !{self.mangled_name()}_equal(a, b);
}}

StringHandle      {self.mangled_name()}_to_json_string({self.chandle()} handle) {{
std::string json = static_cast<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}}
{self.chandle()} {self.mangled_name()}_from_json_string(StringHandle json) {{
  auto ptr = falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>::from_json_string<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>>(json->raw);
  return new falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>(*ptr);
}}
""")

    def generate_farray_implementation(self):
        c_type = self.combo[0]
        cpp_type = self.combo[1]
        with self.edit_implementation() as f:
            f.write(f"""
{self.chandle()} {self.mangled_name()}_create_empty() {{
    return new falcon_core::generic::FArray<{cpp_type}>(falcon_core::generic::FArray<{cpp_type}>());
}}

{self.chandle()} {self.mangled_name()}_create_zeros(const size_t* shape, size_t ndim) {{
    std::vector<size_t> vec;
    for (size_t i =0; i < ndim; ++i) {{
        vec.push_back(shape[i]);
    }}
    return new falcon_core::generic::FArray<{cpp_type}>(*falcon_core::generic::FArray<{cpp_type}>::zeros(vec));
}}

{self.chandle()} {self.mangled_name()}_from_shape(const size_t* shape, size_t ndim) {{
    std::vector<size_t> vec;
    for (size_t i =0; i < ndim; ++i) {{
        vec.push_back(shape[i]);
    }}
    return new falcon_core::generic::FArray<{cpp_type}>(falcon_core::generic::FArray<{cpp_type}>(vec));
}}

{self.chandle()} {self.mangled_name()}_from_data(const {c_type}* data, const size_t* shape, size_t ndim) {{
  std::vector<std::vector<{cpp_type}>::size_type> shapeVec;
  size_t                                      total_size = 1;
  for (size_t i = 0; i < ndim; ++i) {{
    shapeVec.push_back(shape[i]);
    total_size *= shape[i];
  }}
  xt::xarray<{cpp_type}> arr =
      xt::adapt(data, total_size, xt::no_ownership(), shapeVec);
  return new falcon_core::generic::FArray<{cpp_type}>(
      falcon_core::generic::FArray<{cpp_type}>(arr));
}}
void {self.mangled_name()}_destroy({self.chandle()} handle) {{
    delete static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
}}
size_t {self.mangled_name()}_size({self.chandle()} handle) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    return farray->size();
}}
size_t {self.mangled_name()}_dimension({self.chandle()} handle) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    return farray->dimension();
}}
size_t {self.mangled_name()}_shape({self.chandle()} handle, size_t* out_buffer, size_t ndim) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    auto shape = farray->shape();
    size_t count   = shape.size();
    size_t to_copy = (ndim < count) ? ndim : count;
    for (size_t i = 0; i < to_copy; ++i) {{
        out_buffer[i] = shape[i];
    }}
    return to_copy;
}}
size_t {self.mangled_name()}_data({self.chandle()} handle, {c_type}* out_buffer, size_t numdata) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    if (farray->size() > numdata) {{
        throw std::runtime_error("Trying to store more datapoints than buffer allocated.");
    }}
    out_buffer = farray->xtensor().data();
    return farray->size();
}}
void {self.mangled_name()}_plusequals_farray({self.chandle()} handle, {self.chandle()} other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<{cpp_type}>*>(other);
    *farray += *oarray;
}}
void {self.mangled_name()}_plusequals_double({self.chandle()} handle, const double other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    *farray += other;
}}
void {self.mangled_name()}_plusequals_int({self.chandle()} handle, const int other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    *farray += other;
}}
{self.chandle()} {self.mangled_name()}_plus_farray({self.chandle()} handle, {self.chandle()} other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<{cpp_type}>*>(other);
    return new falcon_core::generic::FArray<{cpp_type}>(
        *(*farray +
            std::make_shared<falcon_core::generic::FArray<{cpp_type}>>(*oarray)));
}}
{self.chandle()} {self.mangled_name()}_plus_double({self.chandle()} handle, const double other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArray<{cpp_type}>(*(*farray + other));
}}
{self.chandle()} {self.mangled_name()}_plus_int({self.chandle()} handle, const int other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArray<{cpp_type}>(*(*farray + other));
}}
void {self.mangled_name()}_minusequals_farray({self.chandle()} handle, {self.chandle()} other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<{cpp_type}>*>(other);
    *farray -= *oarray;
}}
void {self.mangled_name()}_minusequals_double({self.chandle()} handle, const double other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    *farray -= other;
}}
void {self.mangled_name()}_minusequals_int({self.chandle()} handle, const int other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    *farray -= other;
}}
{self.chandle()} {self.mangled_name()}_minus_farray({self.chandle()} handle, {self.chandle()} other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<{cpp_type}>*>(other);
    return new falcon_core::generic::FArray<{cpp_type}>(
        *(*farray -
            std::make_shared<falcon_core::generic::FArray<{cpp_type}>>(*oarray)));
}}
{self.chandle()} {self.mangled_name()}_minus_double({self.chandle()} handle, const double other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArray<{cpp_type}>(*(*farray - other));
}}
{self.chandle()} {self.mangled_name()}_minus_int({self.chandle()} handle, const int other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArray<{cpp_type}>(*(*farray - other));
}}
{self.chandle()} {self.mangled_name()}_negation({self.chandle()} handle) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArray<{cpp_type}>(*(-*farray));
}}
void {self.mangled_name()}_timesequals_farray({self.chandle()} handle, {self.chandle()} other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<{cpp_type}>*>(other);
    *farray *= *oarray;
}}
void {self.mangled_name()}_timesequals_double({self.chandle()} handle, const double other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    *farray *= other;
}}
void {self.mangled_name()}_timesequals_int({self.chandle()} handle, const int other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    *farray *= other;
}}
{self.chandle()} {self.mangled_name()}_times_farray({self.chandle()} handle, {self.chandle()} other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<{cpp_type}>*>(other);
    return new falcon_core::generic::FArray<{cpp_type}>(
        *(*farray *
            std::make_shared<falcon_core::generic::FArray<{cpp_type}>>(*oarray)));
}}
{self.chandle()} {self.mangled_name()}_times_double({self.chandle()} handle, const double other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArray<{cpp_type}>(*(*farray * other));
}}
{self.chandle()} {self.mangled_name()}_times_int({self.chandle()} handle, const int other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArray<{cpp_type}>(*(*farray * other));
}}
void {self.mangled_name()}_dividesequals_farray({self.chandle()} handle, {self.chandle()} other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<{cpp_type}>*>(other);
    *farray /= *oarray;
}}
void {self.mangled_name()}_dividesequals_double({self.chandle()} handle, const double other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    *farray /= other;
}}
void {self.mangled_name()}_dividesequals_int({self.chandle()} handle, const int other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    *farray /= other;
}}
{self.chandle()} {self.mangled_name()}_divides_farray({self.chandle()} handle, {self.chandle()} other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<{cpp_type}>*>(other);
    return new falcon_core::generic::FArray<{cpp_type}>(
        *(*farray /
            std::make_shared<falcon_core::generic::FArray<{cpp_type}>>(*oarray)));
}}
{self.chandle()} {self.mangled_name()}_divides_double({self.chandle()} handle, const double other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArray<{cpp_type}>(*(*farray / other));
}}
{self.chandle()} {self.mangled_name()}_divides_int({self.chandle()} handle, const int other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArray<{cpp_type}>(*(*farray / other));
}}
{self.chandle()} {self.mangled_name()}_pow({self.chandle()} handle, const double other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArray<{cpp_type}>(*farray ^ other);
}}
{self.chandle()} {self.mangled_name()}_abs({self.chandle()} handle) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArray<{cpp_type}>(*farray->abs());
}}
{self.chandle()} {self.mangled_name()}_min({self.chandle()} handle) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArray<{cpp_type}>(farray->min());
}}
{self.chandle()} {self.mangled_name()}_min_arraywise({self.chandle()} handle, {self.chandle()} other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<{cpp_type}>*>(other);
    return new falcon_core::generic::FArray<{cpp_type}>(
        *farray->min(std::shared_ptr<falcon_core::generic::FArray<{cpp_type}>>(oarray)));
}}
bool {self.mangled_name()}_equality({self.chandle()} handle, {self.chandle()} other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<{cpp_type}>*>(other);
    return *farray == *oarray;
}}
bool {self.mangled_name()}_notequality({self.chandle()} handle, {self.chandle()} other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<{cpp_type}>*>(other);
    return *farray != *oarray;
}}
bool {self.mangled_name()}_greaterthan({self.chandle()} handle, const {c_type} value) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    return *farray > value;
}}
bool {self.mangled_name()}_lessthan({self.chandle()} handle, const {c_type} value) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    return *farray < value;
}}
void {self.mangled_name()}_remove_offset({self.chandle()} handle, const {c_type} offset) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    farray->remove_offset(offset);
}}
{c_type} {self.mangled_name()}_sum({self.chandle()} handle) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    return farray->sum();
}}
{self.chandle()} {self.mangled_name()}_reshape({self.chandle()} handle, const size_t* shape, size_t ndims) {{
    std::vector<size_t> vec;
    for (size_t i =0; i < ndims; ++i) {{
        vec.push_back(shape[i]);
    }}
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArray<{cpp_type}>(*farray->reshape(vec));
}}
ListListSizeTHandle {self.mangled_name()}_where({self.chandle()} handle, const {c_type} value) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    return new falcon_core::generic::List<falcon_core::generic::List<size_t>>(*farray->where(value));
}}
{self.chandle()} {self.mangled_name()}_flip({self.chandle()} handle, size_t axis) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArray<{cpp_type}>(*farray->flip(axis));
}}
size_t {self.mangled_name()}_full_gradient({self.chandle()} handle, {self.chandle()}* out_buffer, size_t buffer_size) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    auto many_gradients = farray->gradient();
    if (many_gradients->size() > buffer_size) {{
        throw std::runtime_error("Trying to store more gradients than buffer allocated.");
    }}
    for (size_t i = 0; i < many_gradients->size(); ++i) {{
        out_buffer[i] = many_gradients->items()[i].get();
    }}
    return many_gradients->size();
}}
{self.chandle()} {self.mangled_name()}_gradient({self.chandle()} handle, size_t axis) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    return new falcon_core::generic::FArray<{cpp_type}>(*farray->gradient(axis));
}}
double {self.mangled_name()}_get_sum_of_squares({self.chandle()} handle) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    return farray->get_sum_of_squares();
}}
double {self.mangled_name()}_get_summed_diff_int_of_squares({self.chandle()} handle, const int other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    return farray->get_sum_of_squares(other);
}}

double {self.mangled_name()}_get_summed_diff_double_of_squares({self.chandle()} handle, const double other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    return farray->get_sum_of_squares(other);
}}
double {self.mangled_name()}_get_summed_diff_array_of_squares({self.chandle()} handle, {self.chandle()} other) {{
    auto farray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(handle);
    auto oarray = static_cast<falcon_core::generic::FArray<{cpp_type}>*>(other);
    return farray->get_sum_of_squares(std::make_shared<falcon_core::generic::FArray<{cpp_type}>>(*oarray));
}}
StringHandle      {self.mangled_name()}_to_json_string({self.chandle()} handle) {{
  std::string json = static_cast<falcon_core::generic::FArray<{c_type}>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}}
{self.chandle()} {self.mangled_name()}_from_json_string(StringHandle json) {{
  auto ptr = falcon_core::generic::FArray<{cpp_type}>::from_json_string<falcon_core::generic::FArray<{cpp_type}>>(json->raw);
  return new falcon_core::generic::FArray<{cpp_type}>(*ptr);
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
        ["<cstddef>"],
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
        ["<cstddef>"],
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
        ["<cstddef>"],
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
            "<falcon_core/physics/device_structures/Connection.hpp>",
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
            "<cstddef>",
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
            "<cstddef>",
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
        [],
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
        [],
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
        [],
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
        [],
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
        ['"falcon_core/physics/device_structures/Connection_c_api.h"'],
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
        ['"falcon_core/physics/device_structures/Connection_c_api.h"'],
        ["<falcon_core/physics/device_structures/Connection.hpp>"],
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
        ['"falcon_core/math/Quantity_c_api.h"'],
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
        ],
        [
            "<falcon_core/math/arrays/ControlArray.hpp>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
        ],
        [
            "<falcon_core/autotuner_interfaces/contexts/MeasurementContext.hpp>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
        ],
        [
            "<falcon_core/generic/Pair.hpp>",
            "<falcon_core/instrument_interfaces/names/InstrumentPort.hpp>",
            "<falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
        ['"falcon_core/physics/device_structures/Connection_c_api.h"'],
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
        ['"falcon_core/physics/device_structures/Connections_c_api.h"'],
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
        ],
        [
            "<falcon_core/physics/device_structures/Connections.hpp>",
            "<falcon_core/autotuner_interfaces/names/Channel.hpp>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
            '"falcon_core/generic/ListListSizeT_c_api.h"',
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
        ],
        [
            "<falcon_core/generic/List.hpp>",
            "<falcon_core/math/arrays/ControlArray.hpp>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
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
            "<cstddef>",
        ],
        [
            "<falcon_core/generic/List.hpp>",
            "<falcon_core/generic/Map.hpp>",
        ],
        Path("math"),
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
