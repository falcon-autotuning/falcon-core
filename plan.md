# C++ Porting and Binding Generation Plan

This document outlines a detailed, iterative plan to refactor the `falcon-core` Python library into a core C++ library with Python and Go bindings generated via SWIG. The goal is to maintain the existing Python API's behavior while providing a high-performance C++ backend.

## Guiding Principles

1.  **Iterative Porting:** The project is broken down into logical phases, porting a small group of related classes at a time.
2.  **Test at Every Stage:** Each C++ component will be unit-tested using Google Test before bindings are created. Bindings will be tested in Python and Go to ensure correctness.
3.  **Dependency-First:** The plan proceeds from the most fundamental, low-dependency classes to the most complex, high-level ones.
4.  **Consistent Tooling:** All C++ development will use a unified build system (e.g., CMake) to manage compilation, testing, and binding generation.

---

## Detailed SWIG Strategy

SWIG will be the bridge between C++ and the target languages. Our strategy will involve:

*   **Modular Interface Files:** We will create multiple SWIG interface files (`.i`), grouping related classes (e.g., `units.i`, `math.i`, `devices.i`). This keeps the declarations manageable.
*   **Python Package Structure:** The Python package structure (e.g., `falcon_core.generic`, `falcon_core.physics.units`) will be created directly by the SWIG-generated module at import time. We will use the `%pythoncode` directive in the main `falcon_core.i` file to create submodule objects and attach the wrapped C++ classes to them. This approach eliminates the need for Python `__init__.py` files to construct the package, allowing a single compiled extension to provide the entire package hierarchy.
*   **Polymorphism with Directors:** For C++ base classes that are designed to be subclassed in Python (e.g., `Jsonable`, `PortTransform`, `AnalyticFunction`), we will enable SWIG's "director" feature (`%feature("director") ClassName;`). This allows virtual method calls from C++ to be correctly dispatched to overriding methods in Python subclasses, preserving the original polymorphic behavior.
*   **Template Instantiation:** C++ templates will be exposed to Python and Go by creating explicit instantiations in SWIG using the `%template` directive. For example: `%template(QuantityDouble) Quantity<double>;` will create a Python class `QuantityDouble`.
*   **STL and Smart Pointer Support:** We will heavily use SWIG's standard library support for `std::vector`, `std::map`, `std::string`, and `std::shared_ptr`. This provides natural conversions (e.g., `std::vector` to Python list) and robust memory management. `std::shared_ptr` is critical for managing object lifetimes across the C++/Python boundary.
*   **NumPy Integration with Typemaps:** To ensure seamless NumPy compatibility, we will use SWIG typemaps to convert between C++ `Eigen` types (matrices, vectors) and NumPy arrays. This will likely involve using a community-provided interface file like `eigen.i` to handle the conversions automatically, ensuring both performance and API parity.

---

## Phase 0: Project Setup and Foundation (Completed)

**Goal:** Establish the core C++ project structure, build system, and port the most basic utilities.

1.  **Repository and Build System Setup: (Completed)**
    *   Create a C++ project structure (`include/falcon_core`, `src/`, `tests/`, `swig/`).
    *   Set up a CMake build system.
    *   Integrate Google Test for C++ unit testing.
    *   Integrate a C++ JSON library (e.g., nlohmann/json).
    *   Integrate `xtensor` and `xtensor-python` for NumPy compatibility.
    *   Configure CMake to run SWIG for Python and Go.

2.  **Port Core Utilities: (Completed)**
    *   **C++:** Port `constants.py` to a C++ header with `constexpr` values. Port the `Time` class.
    *   **C++ Test:** Write tests for the `Time` class.
    *   **SWIG:** Expose constants and the `Time` class. In `falcon_core.i`, use `%pythoncode` to place `Time` into the `falcon_core.communications` submodule.

3.  **Port `Jsonable` Base Class: (Completed)**
    *   **C++:** Create a `Jsonable` base class in C++ with virtual methods for serialization. Replicate the logic for handling metadata keys (`__class__`, etc.) within the C++ implementation.
    *   **C++ Test:** Write tests to confirm serialization/deserialization with metadata works correctly.
    *   **SWIG:** In `falcon_core.i`, include `Jsonable.hpp`, enable the director feature (`%feature("director") Jsonable;`), and use `%pythoncode` to place the `Jsonable` class into the `falcon_core.generic` submodule.
    *   **Binding Test:** Write a simple Python test to subclass `Jsonable` and verify that serialization and director functionality work.

---

## Phase 1: Core Physics Units and Primitives (Completed)

**Goal:** Port the fundamental classes related to physical units. These are self-contained and widely used.

1.  **Port `Dimension`, `Prefix`, `Unit`, `SymbolUnit`, `Sign`: (Completed)**
    *   **C++:** Implement these classes in C++. Use `std::map` or `std::unordered_map` for internal lookups. Replicate the logic for unit conversion and compatibility.
    *   **C++ Test:** Write Google Test cases for unit conversions, prefix math, and compatibility checks.
    *   **SWIG:** Add these classes to a `units.i` file. In `falcon_core.i`, include `units.i` and use `%pythoncode` to move the wrapped classes into the `falcon_core.physics.units` submodule.
    *   **Binding Test:** Write Python/Go tests to create units, perform conversions, and check compatibility.

---

## Phase 2: Mathematical Structures (Completed)

**Goal:** Port the core mathematical data structures.

1.  **Port Generic Containers and Domains: (Completed)**
    *   **C++:** Implement `Domain` and its subclasses (`LabelledDomain`, `CoupledLabelledDomain`). Implement `OneToOneMapping<K, V>`. Implement `Quantity<T>`.
    *   **C++ Test:** Test `Domain` operations, `Quantity` conversions, and `OneToOneMapping` constraints. (Completed)
    *   **SWIG:** Add classes to `math.i`. Use `%template` to instantiate concrete types needed (e.g., `Quantity<double>`).
    *   **Binding Test:** Verify functionality in the target languages.

2.  **Port Array Classes: (Completed)**
    *   **C++:** Create `BaseArray<T>` wrapping an `Eigen` type (e.g., `Eigen::MatrixXd`). Implement `Is1D` logic. Implement subclasses `ControlArray`, `MeasuredArray`, `BaseLabelledArrays`, and `IncreasingAlignment`.
    *   **C++ Test:** Test basic array operations and the specific functionality of each type using `Eigen`. (Completed)
    *   **SWIG:** Use `Eigen` typemaps for automatic NumPy conversion. Instantiate required array templates.
    *   **Binding Test:** Test creating arrays in Python (from NumPy), passing them to C++, performing operations, and getting them back.

3.  **Port `Axes`: (Completed)**
    *   **C++:** Implement `Axes<T>` as a template class wrapping a `std::vector` of shared pointers.
    *   **C++ Test:** Test indexing and other container operations. (Completed)
    *   **SWIG:** Use `std_vector.i` and `std_shared_ptr.i` and instantiate `Axes` for required types (e.g., `Axes<MeasurementContext>`).
    *   **Binding Test:** Test `Axes` functionality from Python/Go.

---

## Phase 3: Device and Configuration Structures (Completed)

**Goal:** Port the classes that define the physical device layout and configuration.

1.  **Port Naming and Connection Primitives: (Completed)**
    *   **C++:** Implement `NameBase<T>`, `Channel`. Implement the class hierarchy `BaseConnection`, `Gate`, `Ohmic`, and their subclasses. Use `std::shared_ptr` for ownership.
    *   **C++ Test:** Test object creation, property access, and inheritance structure. (Completed)
    *   **SWIG:** Expose the class hierarchy in a `devices.i` file. Use directors for base classes if they are meant to be extended.
    *   **Binding Test:** Create instances of gates in Python/Go and verify their types and properties.

2.  **Port Collections and Relations: (Completed)**
    *   **C++:** Implement template containers (`BaseConnections<T>`, `Ports<T>`) wrapping `std::vector<std::shared_ptr<T>>`. Implement `Impedances` and `GateRelations`.
    *   **C++ Test:** Test adding, removing, indexing, and relation lookups. (Completed)
    *   **SWIG:** Use `%template` to instantiate each collection type (e.g., `%template(Gates) BaseConnections<Gate>`).
    *   **Binding Test:** Test collection and relation manipulation from Python/Go.

3.  **Port `InstrumentPort`, `StandardConfigConnections`, `Loader`: (Completed)**
    *   **C++:** Implement `InstrumentPort`. Implement `StandardConfigConnections` to hold the device structure. Implement `Loader` to populate the config from JSON.
    *   **C++ Test:** Verify port properties and test loading a full configuration. (Completed)
    *   **SWIG:** Expose these higher-level classes.
    *   **Binding Test:** Test loading a JSON config and querying it via a `Loader` instance.

---

## Phase 4: Measurement Contexts and Interpretations (Completed)

**Goal:** Port the high-level classes that describe the context of a measurement.

1.  **Port `AcquisitionContext` and `InterpretationContext`: (Completed)**
    *   **C++:** Implement these classes. They will contain instances of the already-ported `InstrumentPort` and `Connection` types.
    *   **C++ Test:** Test context creation and matching logic. (Completed)
    *   **SWIG:** Expose the classes in a `contexts.i` file.
    *   **Binding Test:** Create contexts and test matching from Python/Go.

2.  **Port `InterpretationContainer`: (Completed)**
    *   **C++:** Implement the generic `InterpretationContainer<T>` as a C++ template class, wrapping a `std::map` from `InterpretationContext` to `T`.
    *   **C++ Test:** Test adding contexts and selecting by connection.
    *   **SWIG:** Expose `InterpretationContext`. Use `%template` to instantiate `InterpretationContainer` for the types it will hold.
    *   **Binding Test:** Test creating and querying interpretation containers.

---

## Phase 5: Waveforms, Transforms, and Final Integration (Completed)

**Goal:** Port the final application-level components and assemble the complete library.

1.  **Port `AnalyticFunction` and `PortTransform` Hierarchies: (Completed)**
    *   **C++:** Implement the `AnalyticFunction` and `PortTransform` base classes and their children. Implement the `PortTransforms` collection class.
    *   **C++ Test:** Test each function and transform implementation. (Completed)
    *   **SWIG:** Expose the hierarchies. Enable directors on base classes (`%feature("director") AnalyticFunction;`).
    *   **Binding Test:** Create functions and transforms, test their application, and test subclassing them in Python.

2.  **Port Discretizers, Spaces, and Waveforms: (Completed)**
    *   **C++:** Implement `BaseDiscretizer` hierarchy. Implement `Spaces` and `Waveform` classes, which compose many previously ported components.
    *   **C++ Test:** Test waveform creation and data generation. (Completed)
    *   **SWIG:** Expose these final high-level classes.
    *   **Binding Test:** Perform end-to-end tests creating a full waveform object from Python/Go.

---

## Phase 6: Finalizing Completeness (Completed)

**Goal:** Port all remaining classes and subclasses to ensure 100% API coverage.

1.  **Port Domain Subclasses: (Completed)**
    *   **C++:** Implement `LabelledDomain<T>` and `CoupledLabelledDomain<T>` inheriting from `Domain`.
    *   **C++ Test:** Test label functionality and coupling logic. (Completed)
    *   **SWIG:** Expose these classes and instantiate necessary templates in `math.i`.
    *   **Binding Test:** Verify functionality from Python.

2.  **Port Labelled Array Classes: (Completed)**
    *   **C++:** Implement `BaseLabelledArrays<T>` and the logic from `IsLabelled1D`.
    *   **C++ Test:** Test array labelling and 1D-specific features. (Completed)
    *   **SWIG:** Expose these classes in `math.i`.
    *   **Binding Test:** Verify functionality from Python.

3.  **Port Remaining Math and Array Classes: (Completed)**
    *   **C++:** Implement `IncreasingAlignment` and `ControlArray1D`.
    *   **C++ Test:** Test the specific logic of these classes. (Completed)
    *   **SWIG:** Expose these classes in `math.i`.
    *   **Binding Test:** Verify functionality from Python.

4.  **Port Concrete Analytic Functions: (Completed)**
    *   **C++:** Implement `ConstantFunction` and `Identity` as subclasses of `AnalyticFunction`.
    *   **C++ Test:** Test the specific evaluation logic of these functions. (Completed)
    *   **SWIG:** Expose these classes in `transforms.i`.
    *   **Binding Test:** Verify functionality from Python.

5.  **Port Remaining Collection and Utility Classes: (Completed)**
    *   **C++:** Implement `Channels` as a collection for `Channel` objects (e.g., inheriting from `BaseConnections<Channel>`). Implement the `Units` utility class with static methods to retrieve common units.
    *   **C++ Test:** Test collection management and unit retrieval. (Completed)
    *   **SWIG:** Expose `Channels` in `devices.i` and `Units` in `units.i`.
    *   **Binding Test:** Verify functionality from Python.

6.  **Port Concrete Discretizers and Transforms: (Completed)**
    *   **C++:** Implement `CartesianDiscretizer` as a subclass of `BaseDiscretizer`. Implement `IdentityTransform` as a subclass of `PortTransform`.
    *   **C++ Test:** Test the specific logic of these classes. (Completed)
    *   **SWIG:** Expose these classes in `waveforms.i` and `transforms.i` respectively.
    *   **Binding Test:** Verify functionality from Python.

---

## Phase 7: Packaging and Deployment

**Goal:** Package the bindings for distribution.

1.  **Python Packaging:**
    *   Create a `setup.py` or `pyproject.toml` that uses CMake/scikit-build to build the C++ core, run SWIG, and compile the final Python C-extension module.
    *   Ensure the final package structure (`falcon_core`) matches the original so that user import statements do not break.

2.  **Go Packaging:**
    *   Provide scripts and documentation (likely using `go generate` and CMake) to build the shared C++ library and the Go wrapper package.
    *   Write example Go applications to demonstrate usage.

3.  **Final Validation:**
    *   Run the complete, original Python test suite against the new C++/Python bindings to ensure API and behavioral parity.

---

## Post-Porting Tasks

*   **HDF5 Serialization:** Investigate and implement HDF5 serialization/deserialization as a parallel mechanism to JSON, if required. This would involve a C++ HDF5 library and extending `Jsonable` or creating a new `HDF5Serializable` interface.
*   **Performance Profiling:** Profile and optimize hot spots in the C++ code and the binding layer.
