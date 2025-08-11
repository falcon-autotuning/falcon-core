# C++ Porting and Binding Generation Plan

This document outlines a detailed, iterative plan to refactor the `falcon-core` Python library into a core C++ library with Python and Go bindings generated via SWIG. The goal is to maintain the existing Python API's behavior while providing a high-performance C++ backend.

## Guiding Principles

1.  **Iterative Porting:** The project is broken down into logical phases, porting a small group of related classes at a time.
2.  **Test at Every Stage:** Each C++ component will be unit-tested using Google Test before bindings are created. Bindings will be tested in Python and Go to ensure correctness.
3.  **Dependency-First:** The plan proceeds from the most fundamental, low-dependency classes to the most complex, high-level ones.
4.  **Consistent Tooling:** All C++ development will use a unified build system (e.g., CMake) to manage compilation, testing, and binding generation.

---

## Phase 0: Project Setup and Foundation

**Goal:** Establish the core C++ project structure, build system, and port the most basic utilities.

1.  **Repository and Build System Setup:**
    *   Create a C++ project structure (`include/`, `src/`, `tests/`, `swig/`).
    *   Set up a CMake build system.
    *   Integrate Google Test for C++ unit testing.
    *   Integrate a C++ JSON library (e.g., nlohmann/json).
    *   Integrate a C++ numerical array library (e.g., `xtensor` with `xtensor-python` for NumPy compatibility).
    *   Configure CMake to run SWIG for Python and Go.

2.  **Port `Jsonable` Base Class:**
    *   **C++:** Create a `Jsonable` base class in C++ with virtual methods for serialization/deserialization.
    *   **C++ Test:** Write tests to confirm the base serialization logic works.
    *   **SWIG:** Create the initial SWIG interface file (`.i`). Define the `Jsonable` class and enable the "director" feature (`%feature("director") Jsonable;`) to allow Python classes to inherit from it.
    *   **Binding Test:** Write a simple Python test to subclass `Jsonable` and verify that the director functionality works.

---

## Phase 1: Core Physics Units and Primitives

**Goal:** Port the fundamental classes related to physical units. These are self-contained and widely used.

1.  **Port `Dimension`, `Prefix`, `Unit`, `SymbolUnit`:**
    *   **C++:** Implement these classes in C++. Use `std::map` or `std::unordered_map` for internal lookups. Replicate the logic for unit conversion and compatibility.
    *   **C++ Test:** Write Google Test cases for unit conversions, prefix math, and compatibility checks.
    *   **SWIG:** Add these classes to the SWIG interface. Expose methods and properties.
    *   **Binding Test:** Write Python/Go tests to create units, perform conversions, and check compatibility.

---

## Phase 2: Mathematical Structures

**Goal:** Port the core mathematical data structures, including domains, arrays, and quantities.

1.  **Port `Domain` and `Quantity`:**
    *   **C++:** Implement `Domain`. Port `Quantity<T>`, making it a C++ template class that holds a value and a `SymbolUnit`.
    *   **C++ Test:** Test `Domain` operations (intersect, union) and `Quantity` conversions.
    *   **SWIG:** Add `Domain`. Use `%template` to instantiate concrete `Quantity` types needed (e.g., `Quantity<double>`).
    *   **Binding Test:** Verify `Domain` and `Quantity` functionality in the target languages.

2.  **Port Base Array Classes (`BaseArray`, `Is1D`):**
    *   **C++:** Create a `BaseArray` template class wrapping an `xtensor` array. Implement methods like `min`, `abs`. Implement `Is1D` logic as a mixin or via static checks.
    *   **C++ Test:** Test basic array operations.
    *   **SWIG:** Expose `BaseArray`. Use `xtensor-python`'s SWIG support for automatic NumPy conversion.
    *   **Binding Test:** Test passing a NumPy array to C++ and receiving one back.

3.  **Port Concrete Array Classes (`ControlArray`, `MeasuredArray`, and 1D versions):**
    *   **C++:** Implement these classes inheriting from `BaseArray`.
    *   **C++ Test:** Test the specific functionality of each array type.
    *   **SWIG:** Instantiate the required templates (e.g., `%template(ControlArray1D) ControlArray<xt::xarray<double>>`).
    *   **Binding Test:** Verify these specific array types in Python and Go.

4.  **Port `Axes`:**
    *   **C++:** Implement `Axes<T>` as a template class wrapping a `std::vector` of shared pointers.
    *   **C++ Test:** Test indexing and other container operations.
    *   **SWIG:** Use `std_vector.i` and `std_shared_ptr.i` and instantiate `Axes` for required types.
    *   **Binding Test:** Test `Axes` functionality from Python/Go.

---

## Phase 3: Device and Configuration Structures

**Goal:** Port the classes that define the physical device layout and configuration.

1.  **Port Connection Primitives (`Channel`, `BaseConnection`, `Gate`, `Ohmic`, etc.):**
    *   **C++:** Implement the class hierarchy (`DotGate` -> `Gate` -> `BaseConnection`). Use smart pointers (`std::shared_ptr`) for object ownership.
    *   **C++ Test:** Test object creation, property access, and inheritance structure.
    *   **SWIG:** Expose the class hierarchy. Use directors for base classes if they are meant to be extended.
    *   **Binding Test:** Create instances of gates in Python/Go and verify their types and properties.

2.  **Port Connection Collections (`Gates`, `DotGates`, `Meters`, etc.):**
    *   **C++:** Implement these as template containers wrapping a `std::vector` of smart pointers (e.g., `std::vector<std::shared_ptr<T>>`).
    *   **C++ Test:** Test adding, removing, and indexing elements.
    *   **SWIG:** Use `%template` to instantiate each collection type (e.g., `%template(Gates) BaseConnections<Gate>`).
    *   **Binding Test:** Test collection manipulation from Python/Go.

3.  **Port `InstrumentPort` and `Ports`:**
    *   **C++:** Implement `InstrumentPort` using the already-ported `SymbolUnit` and device classes. `Ports` will be another template instantiation.
    *   **C++ Test:** Verify `InstrumentPort` properties.
    *   **SWIG:** Expose `InstrumentPort` and instantiate `Ports`.
    *   **Binding Test:** Verify creation and property access.

---

## Phase 4: Measurement Contexts and Interpretations

**Goal:** Port the high-level classes that describe the context of a measurement.

1.  **Port `AcquisitionContext`:**
    *   **C++:** Implement the class. It will contain instances of the already-ported `InstrumentPort` and `Connection` types.
    *   **C++ Test:** Test context creation and its methods.
    *   **SWIG:** Expose the class.
    *   **Binding Test:** Create contexts from Python/Go.

2.  **Port `InterpretationContext` and `InterpretationContainer`:**
    *   **C++:** Implement `InterpretationContext`. Implement the generic `InterpretationContainer<T>` as a C++ template class, wrapping a `std::map` from `InterpretationContext` to `T`.
    *   **C++ Test:** Test adding contexts and selecting by connection.
    *   **SWIG:** Expose `InterpretationContext`. Use `%template` to instantiate `InterpretationContainer` for the types it will hold.
    *   **Binding Test:** Test creating and querying interpretation containers.

---

## Phase 5: Waveforms, Transforms, and Final Integration

**Goal:** Port the final application-level components and assemble the complete library.

1.  **Port `PortTransform` Hierarchy (`IdentityTransform`, `ConstantTransform`):**
    *   **C++:** Implement the `PortTransform` base class and its children.
    *   **C++ Test:** Test each transform implementation.
    *   **SWIG:** Expose the hierarchy. Enable directors on `PortTransform` (`%feature("director") PortTransform;`).
    *   **Binding Test:** Create transforms and test their application.

2.  **Port `Spaces` and `Waveforms` (`UnitSpace`, `CartesianWaveform1D`, etc.):**
    *   **C++:** Implement the space and waveform classes. These will compose many of the previously ported components (Arrays, Transforms, Contexts).
    *   **C++ Test:** Test waveform creation and data generation.
    *   **SWIG:** Expose these final high-level classes.
    *   **Binding Test:** Perform end-to-end tests creating a full waveform object from Python/Go.

---

## Phase 6: Packaging and Deployment

**Goal:** Package the bindings for distribution.

1.  **Python Packaging:**
    *   Create a `setup.py` that uses CMake to build the C++ core, run SWIG, and compile the final Python C-extension module.
    *   Ensure the final package structure (`falcon_core`) matches the original so that user import statements do not break.

2.  **Go Packaging:**
    *   Provide scripts and documentation (likely using `go generate` and CMake) to build the shared C++ library and the Go wrapper package.
    *   Write example Go applications to demonstrate usage.

3.  **Final Validation:**
    *   Run the complete, original Python test suite against the new C++/Python bindings to ensure API and behavioral parity.
