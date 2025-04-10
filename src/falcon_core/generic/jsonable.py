"""A Jsonable object is an object that can be converted to and from a dictionary."""

from typing import TYPE_CHECKING

from ..constants import (
    JSONABLE_ATTRIBUTE_INDICATOR,
    JSONABLE_BLOB,
    JSONABLE_CLASS_METADATA,
    JSONABLE_FUNCTION,
    JSONABLE_FUNCTION_DILL,
    JSONABLE_KEY,
    JSONABLE_METADATA,
    JSONABLE_MODULE_METADATA,
    JSONABLE_TYPE_VAR,
)
from .dependancies import (
    GenericAlias,
    JSONprimitives,
    b64decode,
    b64encode,
    deepcopy,
    dill,
    get_args,
    get_origin,
    json,
    np,
    pickle,
    sys,
)

if TYPE_CHECKING:
    from .typing import (
        Any,
        Callable,
        JsonableAttributeName,
        Self,
        TypeAlias,
    )


JSONable_type: "TypeAlias" = dict[str, "JSONprimitives | Jsonable"]
_jsonable_registry: dict[str, type["Jsonable"]] = {}


def register_jsonable(
    cls: "type[Jsonable]",
) -> type["Jsonable"]:
    """Register a Jsonable class for reconstruction from dictionaries.

    Args:
        cls: The Jsonable class to register

    Returns:
        The Jsonable class
    """
    _jsonable_registry[cls.__name__] = cls
    return cls


def collect_jsonable_class_from_registry(
    class_name: str,
):
    """Return the Jsonable class registry.

    Args:
        class_name: The name of the class to collect.

    Returns:
        The Jsonable class.

    Raises:
        ValueError: If the class name is not in the registry.
    """
    if class_name not in _jsonable_registry:
        msg = f"Unknown Jsonable class: {class_name}"
        raise ValueError(msg)

    return _jsonable_registry[class_name]


def remove_jsonable_metadata(
    dictionary: dict[str, str],
) -> dict[str, str]:
    """Remove metadata from the dictionary.

    Args:
        dictionary: The dictionary to remove metadata from.

    Returns:
        The dictionary with metadata removed.
    """
    return {k: v for k, v in dictionary.items() if k not in JSONABLE_METADATA}


def prepend_attribute_indicator(
    attribute_name: "JsonableAttributeName",
) -> str:
    """Prepend the attribute indicator to the attribute name.

    Args:
        attribute_name: The attribute name.

    Returns:
        The attribute name with the indicator prepended.
    """
    return f"{JSONABLE_ATTRIBUTE_INDICATOR}{attribute_name}"


def unpack_classname_metadata(
    dictionary: dict[str, str],
) -> str:
    """Return the class name from the dictionary.

    Args:
        dictionary: The dictionary to extract the class name from.

    Returns:
        The class name.
    """
    class_name = dictionary[JSONABLE_CLASS_METADATA]
    assert isinstance(class_name, str)
    return class_name


def assert_metadata_exists(
    dictionary: dict[str, str],
):
    """Assert that metadata exists in the dictionary.

    Args:
        dictionary: The dictionary to check.

    Raises:
        ValueError: If metadata does not exist.
    """
    print(dictionary)
    if JSONABLE_CLASS_METADATA not in list(dictionary.keys()):
        msg = f"Cannot create instance of abstract Jsonable class without {JSONABLE_CLASS_METADATA} information"
        raise ValueError(msg)


def check_jsonable_attribute(
    attribute_name: str,
) -> bool:
    """Check if the attribute is a jsonable attribute.

    Args:
        attribute_name: The name of the attribute.

    Returns:
        True if the attribute is a jsonable attribute, False otherwise.
    """
    return attribute_name[0] == JSONABLE_ATTRIBUTE_INDICATOR


def get_jsonable_attribute(
    attribute_name: str,
) -> "JsonableAttributeName":
    """Return the jsonable attribute.

    Args:
        attribute_name: The name of the attribute.

    Returns:
        The jsonable attribute.
    """
    return attribute_name[len(JSONABLE_ATTRIBUTE_INDICATOR) :]


def check_serializable(
    value: "Any",
):
    """Recursively check if all elements in the value are JSON serializable.

    Args:
        value: The value to check.

    Returns:
        True if all elements in the value are JSON serializable, False otherwise.
    """
    if (
        (callable(value) and not isinstance(value, type))
        or is_type_object(value)
        or isinstance(value, np.ndarray | JSONprimitives)
    ):
        return True
    if isinstance(value, Jsonable):
        throw_error_if_not_serializable(dictionary=value.to_dict())
        return True
    if isinstance(value, list):
        return all(check_serializable(item) for item in value)
    if isinstance(value, dict):
        return all(
            check_serializable(k) and check_serializable(v) for k, v in value.items()
        )
    return False


def throw_error_if_not_serializable(dictionary: dict[str, str]):
    """Throw an error if the value is not JSON serializable.

    Raises:
        TypeError: If the value is not JSON serializable.
    """
    for attribute_name, attribute_value in dictionary.items():
        if check_jsonable_attribute(attribute_name) and not check_serializable(
            attribute_value
        ):
            msg = f"""Value {attribute_name} of type {type(attribute_name)}
            is not JSON serializable."""
            raise TypeError(msg)


def parse_metadata_to_collect_class_type(
    dictionary: dict[str, str],
) -> type["Jsonable"]:
    """Parse metadata to collect the class.

    Args:
        dictionary: The dictionary to parse.

    Returns:
        The class.
    """
    class_name = unpack_classname_metadata(dictionary=dictionary)
    return collect_jsonable_class_from_registry(class_name=class_name)


def construct_dict_typed_attribute_from_raw(
    dictionary: "JSONable_type",
) -> "Any":
    """Construct a dictionary of typed attributes from raw values.

    Args:
        dictionary: The raw values.

    Returns:
        The dictionary of typed attributes.
    """
    regular_dict = construct_dict_attributes_from_raw(dictionary=dictionary)
    special_dict = construct_special_dict_attributes_from_raw(dictionary=dictionary)
    return {**regular_dict, **special_dict}


def construct_dict_attributes_from_raw(
    dictionary: "JSONable_type",
) -> "Any":
    """Construct a dictionary of attributes from raw values.

    Args:
        dictionary: The raw values.

    Returns:
        The dictionary of attributes.
    """
    regular_items = {
        k: v
        for k, v in dictionary.items()
        if not isinstance(k, str) or not k.startswith(JSONABLE_KEY)
    }
    return {k: construct_typed_attribute_from_raw(v) for k, v in regular_items.items()}


def construct_special_dict_attributes_from_raw(
    dictionary: "Any",
) -> "Any":
    """Construct a dictionary of attributes from raw values.

    These attributes are special Jsonable keys.

    Args:
        dictionary: The raw values.

    Returns:
        The dictionary of attributes.
    """
    special_items = {
        k[len(JSONABLE_KEY) :]: v
        for k, v in dictionary.items()
        if isinstance(k, str) and k.startswith(JSONABLE_KEY)
    }
    result = {}
    for key, entry in special_items.items():
        key_dict = entry["key"]
        value_raw = entry["value"]
        key_class = collect_jsonable_class_from_registry(class_name=key)
        key_obj = key_class.from_dict(key_dict)
        result[key_obj] = construct_typed_attribute_from_raw(value_raw)

    return result


def construct_typed_np_array_from_raw(
    dictionary: "dict[str, Any]",
) -> "np.ndarray":
    """Construct a typed np array from a raw value.

    Args:
        dictionary: The raw value.

    Returns:
        The typed np array.
    """
    binary_data = b64decode(dictionary["data"])
    return pickle.loads(binary_data)


def construct_typed_attribute_from_raw(value: "Any") -> "Any":
    """Construct a typed attribute from a raw value.

    Args:
        value: The raw value.

    Returns:
        The typed attribute.
    """
    if not isinstance(value, list | dict):
        return value
    if isinstance(value, list):
        return [construct_typed_attribute_from_raw(item) for item in value]
    if isinstance(value, dict) and value.get(JSONABLE_FUNCTION) is True:
        return construct_function_from_raw(value)
    if JSONABLE_TYPE_VAR in value:
        return construct_type_variable_from_raw(value)
    if JSONABLE_BLOB in value:
        return construct_typed_np_array_from_raw(dictionary=value)
    if JSONABLE_CLASS_METADATA in value:
        target_class = parse_metadata_to_collect_class_type(dictionary=value)
        return target_class.from_dict(value)

    return construct_dict_typed_attribute_from_raw(dictionary=value)


def construct_special_jsonable_key(
    key: "Jsonable",
) -> "str":
    """Construct a special Jsonable key.

    Args:
        key: The Jsonable key.

    Returns:
        The special Jsonable key.
    """
    return f"{JSONABLE_KEY}{key.__class__.__name__}"


def construct_raw_key_from_special_jsonable_key(
    key: "Jsonable",
    value: "Any",
) -> "dict[str, Any]":
    """Construct a raw key from a special Jsonable key.

    Use a special format to represent the Jsonable key
    Store it as JSONABLE_KEY: serialized_key, "value": serialized_value

    Args:
        key: The special Jsonable key.
        value: The value to be constructed from raw.

    Returns:
        The raw key.
    """
    return {
        "key": key.to_dict(),
        "value": construct_raw_from_typed_attribute(value),
    }


def construct_raw_array_from_typed_attribute(
    attribute_value: "np.ndarray",
) -> "Any":
    """Convert typed np array to raw values for JSON serialization.

    Args:
        attribute_value: The value to convert.

    Returns:
        The raw value suitable for JSON serialization.
    """
    return {
        JSONABLE_BLOB: True,
        "type": "numpy.ndarray",
        "data": b64encode(pickle.dumps(attribute_value)).decode("ascii"),
        "shape": attribute_value.shape,
        "dtype": str(attribute_value.dtype),
    }


def construct_raw_from_type_variable(type_var: "Any") -> "Any":
    """Serialize a type variable to a JSON-compatible format.

    Args:
        type_var: The type variable to serialize.

    Returns:
        A serialized representation of the type variable.

    Raises:
        TypeError: If the type variable cannot be serialized.
    """
    if isinstance(type_var, type):
        # Handle simple types
        return {
            JSONABLE_TYPE_VAR: True,
            "kind": "simple",
            JSONABLE_MODULE_METADATA: type_var.__module__,
            JSONABLE_CLASS_METADATA: type_var.__name__,
        }
    if hasattr(type_var, "__origin__"):
        # Handle generic types like List[int], Dict[str, int], etc.
        origin = get_origin(type_var)
        args = get_args(type_var)
        return {
            JSONABLE_TYPE_VAR: True,
            "kind": "generic",
            "origin": construct_raw_from_type_variable(origin),
            "args": [construct_raw_from_type_variable(arg) for arg in args],
        }
    if type_var is ...:
        # Handle Ellipsis
        return {JSONABLE_TYPE_VAR: True, "kind": "ellipsis"}
    if type_var is None:
        # Handle None
        return {JSONABLE_TYPE_VAR: True, "kind": "none"}
    # Handle other cases like Union, Optional, etc.
    try:
        return {JSONABLE_TYPE_VAR: True, "kind": "special", "repr": repr(type_var)}
    except Exception:
        msg = f"Cannot serialize type variable: {type_var}"
        raise TypeError(msg)


def construct_raw_from_function(
    func: "Callable",
) -> "dict[str, Any]":
    """Convert a function to a raw value for JSON serialization.

    Args:
        func: The function to convert.

    Returns:
        The raw value suitable for JSON serialization.

    Raises:
        ValueError: If the function cannot be serialized.
    """
    # First try to get the source code
    try:
        serialized = b64encode(dill.dumps(func)).decode("ascii")
        return {
            JSONABLE_FUNCTION: True,
            JSONABLE_FUNCTION_DILL: serialized,
        }
    except Exception as e:
        msg = f"Could not serialize function: {e}"
        raise ValueError(msg)


def construct_function_from_raw(data: "dict") -> "Callable":
    """Deserialize a function from a serialized format.

    Args:
        data: The serialized function data.

    Returns:
        The deserialized function.

    Raises:
        ValueError: If the function cannot be deserialized
    """
    if JSONABLE_FUNCTION_DILL in data:
        # Function was stored using dill serialization
        serialized = data[JSONABLE_FUNCTION_DILL]
        return dill.loads(b64decode(serialized))

    msg = "No valid function data found in serialized object"
    raise ValueError(msg)


def construct_type_variable_from_raw(data: "dict") -> "Any":
    """Deserialize a type variable from a serialized format.

    Args:
        data: The serialized type data.

    Returns:
        The deserialized type variable.

    Raises:
        ValueError: If the type variable cannot be deserialized
    """
    kind = data.get("kind")

    if kind == "simple":
        # Reconstruct a simple type
        module_name = data[JSONABLE_MODULE_METADATA]
        class_name = data[JSONABLE_CLASS_METADATA]

        # Try to import the module and get the class
        try:
            module = sys.modules.get(module_name) or __import__(module_name)
            return getattr(module, class_name)
        except (ImportError, AttributeError):
            # Fallback for builtin types
            if module_name == "builtins":
                return getattr(__builtins__, class_name)
            msg = f"Could not import type {module_name}.{class_name}"
            raise ValueError(msg)

    elif kind == "generic":
        # Reconstruct a generic type
        origin = construct_type_variable_from_raw(data["origin"])
        args = [construct_type_variable_from_raw(arg) for arg in data["args"]]

        # Handle special case for Python 3.9+
        if hasattr(origin, "__class_getitem__"):
            return origin.__class_getitem__(tuple(args))
        return origin[tuple(args) if len(args) > 1 else args[0]]

    elif kind == "ellipsis":
        return ...

    elif kind == "none":
        return None

    elif kind == "special":
        # This is a best-effort approach for complex types
        # It won't work for all cases but provides some debugging info
        return data["repr"]

    msg = f"Unknown type variable kind: {kind}"
    raise ValueError(msg)


def is_type_object(value: "Any") -> bool:
    """Check if the value is a type object.

    Args:
        value: The value to check.

    Returns:
        True if the value is a type object, False otherwise.
    """
    return (
        isinstance(value, type)
        or hasattr(value, "__origin__")
        or isinstance(value, GenericAlias)
    )


def construct_raw_from_typed_attribute(
    attribute_value: "Any",
) -> "Any":
    """Convert typed attributes to raw values for JSON serialization.

    Args:
        attribute_value: The value to convert.

    Returns:
        The raw value suitable for JSON serialization.
    """
    if callable(attribute_value) and not isinstance(attribute_value, type):
        return construct_raw_from_function(attribute_value)
    if is_type_object(attribute_value):
        return construct_raw_from_type_variable(attribute_value)
    if isinstance(attribute_value, np.ndarray):
        return construct_raw_array_from_typed_attribute(attribute_value)
    if isinstance(attribute_value, Jsonable):
        return attribute_value.to_dict()
    if isinstance(attribute_value, list):
        return [construct_raw_from_typed_attribute(item) for item in attribute_value]
    if not isinstance(attribute_value, dict):
        return attribute_value
    result = {}
    for key, value in attribute_value.items():
        # If the key is a Jsonable object, serialize it with a special marker
        if not isinstance(key, Jsonable):
            # Regular key handling
            result[key] = construct_raw_from_typed_attribute(value)
            continue

        jsonable_key = construct_raw_key_from_special_jsonable_key(
            key=key,
            value=value,
        )
        result[construct_special_jsonable_key(key=key)] = jsonable_key

    return result


def process_attributes(
    instance: "Jsonable",
    clean_data: dict[str, str],
):
    """Process attributes of a Jsonable object.

    Args:
        instance: The Jsonable object.
        clean_data: The clean data.
    """
    for key, value in clean_data.items():
        attr_value = construct_typed_attribute_from_raw(value)
        attr_name = prepend_attribute_indicator(attribute_name=key)
        setattr(instance, attr_name, attr_value)


def remove_non_jsonable_attributes(
    dictionary: "JSONable_type",
) -> "JSONable_type":
    """Remove non-jsonable attributes from the dictionary.

    Args:
        dictionary: The dictionary to remove attributes from.

    Returns:
        The dictionary with non-jsonable attributes removed.
    """
    return {
        attribute_name: value
        for attribute_name, value in dictionary.items()
        if check_jsonable_attribute(attribute_name)
    }


class Jsonable:
    """A Jsonable object is an object that can be converted to and from a dictionary.

    Implied syntax is that jsonable attributes begin with _
    """

    jsonable_attribute_indicator = JSONABLE_ATTRIBUTE_INDICATOR

    def __init_subclass__(cls, **kwargs):
        """Automatically register subclasses."""
        super().__init_subclass__(**kwargs)
        _jsonable_registry[cls.__name__] = cls

    @classmethod
    def from_dict(cls, data: "dict[str,str]") -> "Self":
        """Create a Jsonable object from a dictionary.

        Args:
            data: Dictionary containing object data

        Returns:
            Reconstructed Jsonable object
        """
        assert_metadata_exists(dictionary=data)
        target_class = parse_metadata_to_collect_class_type(dictionary=data)
        clean_data = remove_jsonable_metadata(dictionary=data)

        instance = target_class.__new__(target_class)
        process_attributes(instance=instance, clean_data=clean_data)
        return instance  # type: ignore  # noqa: PGH003

    @classmethod
    def from_json(cls, json_string: str) -> "Self":
        """Create a Jsonable object from a JSON string.

        Args:
            json_string: JSON string containing object data

        Returns:
            Reconstructed Jsonable object
        """
        data = json.loads(json_string)
        return cls.from_dict(data)

    def _prepare_metadata(self) -> "dict[str, str]":
        """Prepare metadata for the object.

        Returns:
            The metadata.
        """
        return {
            JSONABLE_CLASS_METADATA: self.__class__.__name__,
            JSONABLE_MODULE_METADATA: self.__class__.__module__,
        }

    def to_dict(self) -> "dict[str, str]":
        """Return a dictionary representation of the object."""
        throw_error_if_not_serializable(dictionary=self.__dict__)
        clean_data = remove_non_jsonable_attributes(self.__dict__)

        output = self._prepare_metadata()

        for attribute_name, attribute_value in clean_data.items():
            jsonable_attribute_name = get_jsonable_attribute(
                attribute_name=attribute_name
            )
            output[jsonable_attribute_name] = construct_raw_from_typed_attribute(
                attribute_value=attribute_value
            )
        return output

    def to_json(self) -> str:
        """Return a JSON string representation of the object."""
        out = self.to_dict()
        return json.dumps(out)

    def __repr__(self) -> str:
        """Return a string representation of the object."""
        return f"{self.__class__.__name__}({self.to_dict()})"

    def __str__(self) -> str:
        """Return a string representation of the object."""
        return str(self.to_dict())

    def __hash__(self) -> int:
        """Return the hash of the object."""

        def make_hashable(obj):
            """Convert a potentially unhashable object to a hashable one."""
            if isinstance(obj, dict):
                return tuple(sorted((k, make_hashable(v)) for k, v in obj.items()))
            if isinstance(obj, list):
                return tuple(make_hashable(item) for item in obj)
            return obj

        dict_items = self.to_dict().items()
        hashable_items = tuple(sorted((k, make_hashable(v)) for k, v in dict_items))
        return hash(hashable_items)

    def __eq__(self, other: object) -> bool:
        """Check if the object is equal to the other object.

        Args:
            other: The other object to compare to.

        Returns:
            True if the object is equal to the other object, False otherwise.
        """
        if isinstance(other, self.__class__):
            return self.to_dict() == other.to_dict()
        return False

    def deepcopy(self) -> "Self":
        """Create a deep copy of the instance.

        Returns:
            The deep copy of the instance.
        """
        return self.__class__.from_dict(deepcopy(self.to_dict()))
