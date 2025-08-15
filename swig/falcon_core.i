%module(directors="1") falcon_core



%{
#include <string>
#include <cstddef>
#include <stdexcept>
#include <falcon_core/Constants.hpp>
using namespace falcon_core;
%}

// --- Exception Handling ---

// With modern SWIG, standard exceptions (std::exception) are handled by default.
// We only need to add handlers for special cases, like director exceptions.

// Handle exceptions that occur in Python director methods called from C++
%feature("director:except") {
  if ($error != NULL) {
    // An error occurred during a call to a Python method.
    // We need to translate this into a C++ exception to be handled by the %exception block below.
    throw Swig::DirectorMethodException();
  }
}

// Global exception handler for all wrapped C++ code.
// This catches director exceptions and propagates them correctly.
// Standard C++ exceptions are caught by SWIG's default handler.
%exception {
  try {
    $action
  } catch (const Swig::DirectorException& e) {
    // This catches exceptions thrown by director methods,
    // allowing the original Python exception to be propagated.
    SWIG_fail;
  }
}


// Include the Eigen typemaps for NumPy conversion
%include "eigen.i"

// Include the std::shared_ptr library for smart pointer support
%include "std_shared_ptr.i"

// Process the header files

%shared_ptr(falcon_core::communications::Time);
%include "generic/generic.i"

%include "physics/physics.i"





%pythoncode %{
# C++ classes are placed into their submodules using SWIG's %rename directive.
%}
