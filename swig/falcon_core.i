%{
#include "falcon_core/Time.hpp"
#include "falcon_core/Jsonable.hpp"
#include <string>
#include <cstddef>
#include <stdexcept>
%}

// Include standard library support
// %include "std_except.i"



// Process the header files
%include "falcon_core/Jsonable.hpp"
%include "falcon_core/Time.hpp"

// Include the new units definitions
%include "units.i"

// Typemap for nlohmann::json to a Python string.
// The user code in python will be responsible for json.loads()
%typemap(out) nlohmann::json {
  $result = PyUnicode_FromString($1.dump().c_str());
}

// Enable directors for Jsonable to allow subclassing in Python
%feature("director") falcon_core::Jsonable;

// Add python-like special methods
%extend falcon_core::Jsonable {
    std::string __str__() {
        return self->to_json_string();
    }
    size_t __hash__() {
        return self->hash();
    }
}

// C++ helper function to test directors.
// It takes a Jsonable object and calls a virtual method on it.
%inline %{
std::string test_director_call(falcon_core::Jsonable* obj) {
    if (!obj) return "null";
    // Because to_json returns nlohmann::json, we call dump() to get a string
    // SWIG's typemap would have done this automatically if we returned nlohmann::json,
    // but returning std::string here is simpler.
    return obj->to_json().dump();
}
%}
