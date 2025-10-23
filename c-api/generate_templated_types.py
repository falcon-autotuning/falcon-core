#!/usr/bin/env python3
import argparse
from enum import Enum
from pathlib import Path

parser = argparse.ArgumentParser()
parser.add_argument("--manifest", default="generated_template_manifest.txt")
args = parser.parse_args()
generated_file_manifest = Path.cwd() / str(args.manifest)


class Template(Enum):
    """This is a generic type of cpp object that has functions to bind it to C"""

    List = 4
    Map = 9
    Pair = 7
    FArray = 3


class HeaderContext:
    """Starts up the context for a header file.
    temp is the template that the header is based on.
    name is the name mangling add-on for the name to be unique in teh c-api
    path is the path from /c-api/falcon_core to the spot where the header will be created
    header_includes are any additional includes necessary for c imports.
    """

    def __init__(
        self,
        temp: Template,
        name: str,
        path: Path,
        header_includes: list[str],
    ):
        self.path = path
        self.temp = temp
        self.name = name
        self.header_includes = header_includes

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
        temp: Template,
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
    implementation_includes: Any additional dependancies that must be included at the top of the implementation for Cpp to load all the types. This is everythign after the "#include "
    file_path: The path to the header file from /c-api/falcon_core
    """

    temp: Template
    combo: list[str]
    header_includes: list[str]
    implementation_includes: list[str]
    header_path: Path
    implementation_path: Path

    def __init__(
        self,
        temp: Template,
        combo: list[str],
        header_includes: list[str],
        implementation_includes: list[str],
        file_path: Path,
    ):
        self.temp = temp
        self.combo = combo
        self.header_includes = header_includes
        self.implementation_includes = implementation_includes
        self.header_path = (
            "include/falcon_core" / file_path / str(self.mangled_name() + "_c_api.h")
        )
        self.implementation_path = (
            "src/falcon_core" / file_path / str(self.mangled_name() + "_c_api.cpp")
        )
        if len(combo) != temp.value:
            raise ValueError(
                f"Template of {temp.name} expected {temp.value} items but got {len(combo)} instead."
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
        match self.temp:
            case Template.List:
                self.generate_list_header()
            case Template.Map:
                self.generate_map_header()
            case Template.Pair:
                self.generate_pair_header()
            case Template.FArray:
                self.generate_farray_header()
            case _:
                raise ValueError("Bad template")

    def generate_implementation(self):
        match self.temp:
            case Template.List:
                self.generate_list_implementation()
            case Template.Map:
                self.generate_map_implementation()
            case Template.Pair:
                self.generate_pair_implementation()
            case Template.FArray:
                self.generate_farray_implementation()
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
bool {self.mangled_name()}_not_equal({self.chandle()} a, {self.chandle()} b);""")

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
        # TODO: view and operator() and xtensor are not wrapped
        with self.edit_header() as f:
            f.write(f"""
{self.chandle()} {self.mangled_name()}_create_empty();
{self.chandle()} {self.mangled_name()}_from_shape(const size_t* shape, size_t ndim);
{self.chandle()} {self.mangled_name()}_from_data(const {c_type}* data, const size_t* shape, size_t ndim);
void {self.mangled_name()}_destroy({self.chandle()} handle);
size_t {self.mangled_name()}_size({self.chandle()} handle);
size_t {self.mangled_name()}_dimension({self.chandle()} handle);
const size_t* {self.mangled_name()}_shape({self.chandle()} handle);
{c_type}* {self.mangled_name()}_data({self.chandle()} handle);
{self.chandle()} {self.mangled_name()}_plusequals_farray({self.chandle()} handle, {self.chandle()} other);
{self.chandle()} {self.mangled_name()}_plusequals_double({self.chandle()} handle, const double other);
{self.chandle()} {self.mangled_name()}_plusequals_int({self.chandle()} handle, const int other);
{self.chandle()} {self.mangled_name()}_plus_farray({self.chandle()} handle, {self.chandle()} other);
{self.chandle()} {self.mangled_name()}_plus_double({self.chandle()} handle, const double other);
{self.chandle()} {self.mangled_name()}_plus_int({self.chandle()} handle, const int other);
{self.chandle()} {self.mangled_name()}_minusequals_farray({self.chandle()} handle, {self.chandle()} other);
{self.chandle()} {self.mangled_name()}_minusequals_double({self.chandle()} handle, const double other);
{self.chandle()} {self.mangled_name()}_minusequals_int({self.chandle()} handle, const int other);
{self.chandle()} {self.mangled_name()}_minus_farray({self.chandle()} handle, {self.chandle()} other);
{self.chandle()} {self.mangled_name()}_minus_double({self.chandle()} handle, const double other);
{self.chandle()} {self.mangled_name()}_minus_int({self.chandle()} handle, const int other);
{self.chandle()} {self.mangled_name()}_negation({self.chandle()} handle);
{self.chandle()} {self.mangled_name()}_timesequals_farray({self.chandle()} handle, {self.chandle()} other);
{self.chandle()} {self.mangled_name()}_timesequals_double({self.chandle()} handle, const double other);
{self.chandle()} {self.mangled_name()}_timesequals_int({self.chandle()} handle, const int other);
{self.chandle()} {self.mangled_name()}_times_farray({self.chandle()} handle, {self.chandle()} other);
{self.chandle()} {self.mangled_name()}_times_double({self.chandle()} handle, const double other);
{self.chandle()} {self.mangled_name()}_times_int({self.chandle()} handle, const int other);
{self.chandle()} {self.mangled_name()}_dividesequals_farray({self.chandle()} handle, {self.chandle()} other);
{self.chandle()} {self.mangled_name()}_dividesequals_double({self.chandle()} handle, const double other);
{self.chandle()} {self.mangled_name()}_dividesequals_int({self.chandle()} handle, const int other);
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
ListFArray{c_type}Handle {self.mangled_name()}_full_gradient({self.chandle()} handle);
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
        is_primitive = "Handle" not in c_type
        with self.edit_implementation() as f:
            f.write(f"""
{self.chandle()} {self.mangled_name()}_create_empty() {{
    return new falcon_core::generic::List<{cpp_real}>(
        falcon_core::generic::List<{cpp_real}>());
}}

{self.chandle()} {self.mangled_name()}_allocate(size_t count) {{
    return new falcon_core::generic::List<{cpp_real}>(
        falcon_core::generic::List<{cpp_real}>(count));
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

bool {self.mangled_name()}_equal({self.chandle()} a, {self.chandle()} b) {{
    auto& listA = *static_cast<std::shared_ptr<falcon_core::generic::List<{cpp_real}>>*>(a);
    auto& listB = *static_cast<std::shared_ptr<falcon_core::generic::List<{cpp_real}>>*>(b);
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
""")
            if is_primitive:
                # Primitive type implementation
                f.write(f"""
{self.chandle()} {self.mangled_name()}_fill_value(size_t count, {c_type} value) {{
    return new falcon_core::generic::List<{cpp_real}>(
        falcon_core::generic::List<{cpp_real}>(count, value));
}}

{self.chandle()} {self.mangled_name()}_create(const {c_type}* data, size_t count) {{
    std::vector<{cpp_stored}> vec(data, data + count);
    return new falcon_core::generic::List<{cpp_real}>(
        falcon_core::generic::List<{cpp_real}>(vec));
}}

void {self.mangled_name()}_push_back({self.chandle()} handle, {c_type} value) {{
    static_cast<falcon_core::generic::List<{cpp_real}>*>(handle)->push_back(value);
}}

{c_type} {self.mangled_name()}_at({self.chandle()} handle, size_t idx) {{
    return static_cast<falcon_core::generic::List<{cpp_real}>*>(handle)->at(idx);
}}

size_t {self.mangled_name()}_items({self.chandle()} handle, {c_type}* out_buffer, size_t buffer_size) {{
    auto list = static_cast<falcon_core::generic::List<{cpp_real}>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    std::copy_n(list->items().begin(), n, out_buffer);
    return n;
}}

bool {self.mangled_name()}_contains({self.chandle()} handle, {c_type} value) {{
    return static_cast<falcon_core::generic::List<{cpp_real}>*>(handle)->contains(value);
}}

size_t {self.mangled_name()}_index({self.chandle()} handle, {c_type} value) {{
    return static_cast<falcon_core::generic::List<{cpp_real}>*>(handle)->index(value);
}}
""")
            else:
                f.write(f"""
{self.chandle()} {self.mangled_name()}_fill_value(size_t count, {c_type} value) {{
    auto stored_obj = std::shared_ptr<{cpp_real}>(static_cast<{cpp_real}*>(value), []({cpp_real}*) {{}} );
    return new falcon_core::generic::List<{cpp_real}>(
        falcon_core::generic::List<{cpp_real}>(count, stored_obj));
}}

{self.chandle()} {self.mangled_name()}_create(const {c_type}* data, size_t count) {{
    std::vector<{cpp_stored}> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {{
        vec.push_back(std::shared_ptr<{cpp_real}>(static_cast<{cpp_real}*>(data[i]), []({cpp_real}*) {{}} ));
    }}
    return new falcon_core::generic::List<{cpp_real}>(
        falcon_core::generic::List<{cpp_real}>(vec));
}}

void {self.mangled_name()}_push_back({self.chandle()} handle, {c_type} value) {{
    auto stored_obj = std::shared_ptr<{cpp_real}>(static_cast<{cpp_real}*>(value), []({cpp_real}*) {{}} );
    static_cast<falcon_core::generic::List<{cpp_real}>*>(handle)->push_back(stored_obj);
}}

{c_type} {self.mangled_name()}_at({self.chandle()} handle, size_t idx) {{
    auto obj = static_cast<falcon_core::generic::List<{cpp_real}>*>(handle)->at(idx);
    return new {cpp_real}(*obj);
}}

size_t {self.mangled_name()}_items({self.chandle()} handle, {c_type}* out_buffer, size_t buffer_size) {{
    auto list = static_cast<falcon_core::generic::List<{cpp_real}>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    for (size_t i = 0; i < n; ++i) {{
        out_buffer[i] = new {cpp_real}(*list->items()[i]);
    }}
    return n;
}}

bool {self.mangled_name()}_contains({self.chandle()} handle, {c_type} value) {{
    auto stored_obj = std::shared_ptr<{cpp_real}>(static_cast<{cpp_real}*>(value), []({cpp_real}*) {{}} );
    return static_cast<falcon_core::generic::List<{cpp_real}>*>(handle)->contains(stored_obj);
}}

size_t {self.mangled_name()}_index({self.chandle()} handle, {c_type} value) {{
    auto stored_obj = std::shared_ptr<{cpp_real}>(static_cast<{cpp_real}*>(value), []({cpp_real}*) {{}} );
    return static_cast<falcon_core::generic::List<{cpp_real}>*>(handle)->index(stored_obj);
}}
""")

    def generate_pair_implementation(self):
        c_type_1 = self.combo[0]
        cpp_real_1 = self.combo[1]
        cpp_stored_1 = self.combo[2]
        c_type_2 = self.combo[3]
        cpp_real_2 = self.combo[4]
        cpp_stored_2 = self.combo[5]
        is_primitive_1 = c_type_1 == cpp_real_1
        is_primitive_2 = c_type_2 == cpp_real_2
        with self.edit_implementation() as f:
            if is_primitive_1 and is_primitive_2:
                # Both primitive
                create_body = f"return new falcon_core::generic::Pair<{cpp_real_1}, {cpp_real_2}>(first, second);"
            elif is_primitive_1 and not is_primitive_2:
                # First primitive, second complex
                create_body = f"""auto second_obj = std::shared_ptr<{cpp_real_2}>(static_cast<{cpp_real_2}*>(second),[]({cpp_real_2}*) {{}});
    return new falcon_core::generic::Pair<{cpp_real_1}, {cpp_real_2}>(first, second_obj);"""
            elif not is_primitive_1 and is_primitive_2:
                # First complex, second primitive
                create_body = f"""auto first_obj = std::shared_ptr<{cpp_real_1}>(static_cast<{cpp_real_1}*>(first),[]({cpp_real_1}*) {{}});
    return new falcon_core::generic::Pair<{cpp_real_1}, {cpp_real_2}>(first_obj, second);"""
            else:
                # Both complex
                create_body = f"""auto first_obj = std::shared_ptr<{cpp_real_1}>(static_cast<{cpp_real_1}*>(first),[]({cpp_real_1}*) {{}});
    auto second_obj = std::shared_ptr<{cpp_real_2}>(static_cast<{cpp_real_2}*>(second),[]({cpp_real_2}*) {{}});
    return new falcon_core::generic::Pair<{cpp_real_1}, {cpp_real_2}>(first_obj, second_obj);"""

            # Generate first() function
            if is_primitive_1:
                first_return = f"return static_cast<falcon_core::generic::Pair<{cpp_real_1}, {cpp_real_2}>*>(handle)->first();"
            else:
                first_return = f"""auto pair = static_cast<falcon_core::generic::Pair<{cpp_real_1}, {cpp_real_2}>*>(handle);
    return new {cpp_real_1}(*pair->first());"""

            # Generate second() function
            if is_primitive_2:
                second_return = f"return static_cast<falcon_core::generic::Pair<{cpp_real_1}, {cpp_real_2}>*>(handle)->second();"
            else:
                second_return = f"""auto pair = static_cast<falcon_core::generic::Pair<{cpp_real_1}, {cpp_real_2}>*>(handle);
    return new {cpp_real_2}(*pair->second());"""

            # Write the complete implementation
            f.write(f"""
{self.chandle()} {self.mangled_name()}_create({c_type_1} first, {c_type_2} second) {{
    {create_body}
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
        is_primitive_key = cpp_key_type == c_key_type
        is_primitive_value = cpp_value_type == c_value_type
        with self.edit_implementation() as f:
            if not is_primitive_key:
                correct_key = f"""auto temp_key = *static_cast<{cpp_key_type}*>(key);
auto correct_key = std::make_shared<{cpp_key_type}>(temp_key);"""
            else:
                correct_key = """auto correct_key = key;"""
            if not is_primitive_value:
                correct_value = f"""auto temp_value = *static_cast<{cpp_value_type}*>(value);
auto correct_value = std::make_shared<{cpp_value_type}>(temp_value);"""
            else:
                correct_value = """auto correct_value = value;"""
            f.write(f"""
{self.chandle()} {self.mangled_name()}_create_empty() {{
    return new std::shared_ptr<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>>(
            std::make_shared<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>>());
}}

{self.chandle()} {self.mangled_name()}_create(const Pair{name}Handle* data, size_t count) {{
    std::vector<falcon_core::generic::PairSP<{cpp_key_type},{cpp_value_type}>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {{
        vec.push_back(*reinterpret_cast<
                    std::shared_ptr<falcon_core::generic::Pair<{cpp_key_type},{cpp_value_type}>>*>(
            data[i]));
    }}
    return new std::shared_ptr<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>>(
            std::make_shared<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>>(vec));
}}

void {self.mangled_name()}_destroy({self.chandle()} handle) {{
    delete static_cast<std::shared_ptr<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>>*>(handle);
}}

void {self.mangled_name()}_insert_or_assign({self.chandle()} handle, const {c_key_type} key, const {c_value_type} value) {{
    {correct_key}
    {correct_value}
    (*static_cast<std::shared_ptr<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>>*>(handle))->insert_or_assign(correct_key,correct_value);
}}

void {self.mangled_name()}_insert({self.chandle()} handle, const {c_key_type} key, const {c_value_type} value) {{
    {correct_key}
    {correct_value}
    (*static_cast<std::shared_ptr<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>>*>(handle))->insert(correct_key,correct_value);
}}

{c_value_type} {self.mangled_name()}_at({self.chandle()} handle, const {c_key_type} key) {{
    {correct_key}
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>>*>(handle))->at(correct_key);
}}

void {self.mangled_name()}_erase({self.chandle()} handle, const {c_key_type} key) {{
    {correct_key}
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>>*>(handle))->erase(correct_key);
}}

size_t {self.mangled_name()}_size({self.chandle()} handle) {{
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>>*>(handle))->size();
}}

bool {self.mangled_name()}_empty({self.chandle()} handle) {{
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>>*>(handle))->empty();
}}


void {self.mangled_name()}_clear({self.chandle()} handle) {{
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>>*>(handle))->clear();
}}

bool {self.mangled_name()}_contains({self.chandle()} handle, {c_key_type} key) {{
    {correct_key}
    return (*static_cast<std::shared_ptr<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>>*>(handle))->contains(correct_key);
}}

List{key_name}Handle {self.mangled_name()}_keys({self.chandle()} handle) {{
    auto& map = *static_cast<std::shared_ptr<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>>*>(handle);
    auto keys_sp = map->keys(); // shared_ptr<falcon_core::generic::List<Key>>
    return new std::shared_ptr<falcon_core::generic::List<{cpp_key_type}>>(keys_sp);
}}

List{value_name}Handle {self.mangled_name()}_values({self.chandle()} handle) {{
    auto& map = *static_cast<std::shared_ptr<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>>*>(handle);
    auto values_sp = map->values(); // shared_ptr<falcon_core::generic::List<Value>>
    return new std::shared_ptr<falcon_core::generic::List<{cpp_value_type}>>(values_sp);
}}

ListPair{name}Handle {self.mangled_name()}_items({self.chandle()} handle) {{
    auto& map = *static_cast<std::shared_ptr<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>>*>(handle);
    falcon_core::generic::List<falcon_core::generic::Pair<{cpp_key_type},{cpp_value_type}>> items_sp = map->items(); // shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<Key,Value>>>
    return new std::shared_ptr<falcon_core::generic::List<falcon_core::generic::Pair<{cpp_key_type},{cpp_value_type}>>>(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<{cpp_key_type},{cpp_value_type}>>>(items_sp));
}}

bool {self.mangled_name()}_equal({self.chandle()} a, {self.chandle()} b) {{
    auto& listA = *static_cast<std::shared_ptr<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>>*>(a);
    auto& listB = *static_cast<std::shared_ptr<falcon_core::generic::Map<{cpp_key_type},{cpp_value_type}>>*>(b);
    return *listA == *listB;
}}

bool {self.mangled_name()}_not_equal({self.chandle()} a, {self.chandle()} b) {{
    return !{self.mangled_name()}_equal(a, b);
}}
""")

    def generate_farray_implementation(self):
        c_type = self.combo[0]
        cpp_type = self.combo[1]
        with self.edit_implementation() as f:
            # TODO: do implementation
            pass


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
        Template.List,
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
        Template.List,
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
    "ConnectionList": Entry(
        Template.List,
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
        Template.List,
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
        Template.List,
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
    "LabelledDomainList": Entry(
        Template.List,
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
    "ImpedanceList": Entry(
        Template.List,
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
    "ConnectionsList": Entry(
        Template.List,
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
    "PairIntIntList": Entry(
        Template.List,
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
        Template.List,
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
        Template.List,
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
        Template.List,
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
    "PairConnectionConnectionsList": Entry(
        Template.List,
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
    "IntIntPair": Entry(
        Template.Pair,
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
        Template.Pair,
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
    "IntFloatPair": Entry(
        Template.Pair,
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
        Template.Pair,
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
    "ConnectionConnectionPair": Entry(
        Template.Pair,
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
        Template.Pair,
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
    "IntIntMap": Entry(
        Template.Map,
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
        Template.Map,
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
        Template.Map,
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
}
entry_queue: list[str] = [
    "IntList",
    "FloatList",
    "IntIntPair",
    "FloatFloatPair",
    "IntFloatPair",
    "ConnectionFloatPair",
    "ConnectionConnectionPair",
    "ConnectionList",
    "ChannelList",
    "LabelledDomainList",
    "InstrumentPortList",
    "ConnectionsList",
    "ImpedanceList",
    "ConnectionConnectionsPair",
    "PairIntIntList",
    "PairFloatFloatList",
    "PairIntFloatList",
    "PairConnectionFloatList",
    "PairConnectionConnectionsList",
    "IntIntMap",
    "FloatFloatMap",
    "ConnectionFloatMap",
]


if __name__ == "__main__":
    if len(entry_queue) != len(registry):
        raise RuntimeError(
            f"Invalid number of items in the entry_queue. Expected {len(registry)} but got {len(entry_queue)}"
        )
    for name in entry_queue:
        if name not in registry.keys():
            raise ValueError(
                f"Invalid name {name} used that was not present in the registry. Skipping..."
            )
        entry = registry[name]
        entry.generate_header()
        entry.generate_implementation()
        print(f"Generated {entry.header_path}")
        print(f"Generated {entry.implementation_path}")
        add_to_manifest(
            generated_file_manifest, entry.header_path, entry.implementation_path
        )
