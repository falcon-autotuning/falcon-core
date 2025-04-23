"""Tests for the Jsonable class.

Need to make sure they cna be transformed into and from json and dict.
"""

from falcon_core.dependancies import Enum, np
from falcon_core.generic import Jsonable
from falcon_core.typing import Any


class strjson(Jsonable):
    _value: str

    def __init__(self, value: str):
        self._value = value


class listjson(Jsonable):
    _value: list[str]

    def __init__(self, value: list[str]):
        self._value = value


class typejson(Jsonable):
    _simple_type: type
    _list_type: type[list[int]]
    _dict_type: type[dict[str, float]]
    _union_type: type[str | int]
    _nested_type: type[dict[str, list[tuple[int, str]]]]
    _any_type: type[Any]

    def __init__(
        self,
        simple_type: type,
        list_type: type[list[int]],
        dict_type: type[dict[str, float]],
        union_type: type[str] | type[int],
        nested_type: type[dict[str, list[tuple[int, str]]]],
        any_type: type[Any],
    ):
        self._simple_type = simple_type
        self._list_type = list_type
        self._dict_type = dict_type
        self._union_type = union_type
        self._nested_type = nested_type
        self._any_type = any_type


class numpyjson(Jsonable):
    _value: np.ndarray

    def __init__(self, value: np.ndarray):
        self._value = value


class enum(Enum):
    STUFF = "stuff"


class complexjson(Jsonable):
    _value: list[str | strjson]
    _other: enum

    def __init__(self, value: list[str | strjson], other: enum):
        self._other = other
        self._value = value


class the_destroyer(Jsonable):
    _value: dict[strjson, listjson]
    _numvalues: dict[str, numpyjson]
    _whee: dict[strjson, dict[strjson, list[numpyjson]]]
    _stuff: complexjson
    _args: list[str]
    _woah_types: dict[str, typejson]
    _others: dict[str, dict[strjson, listjson]]
    _even_more: list[complexjson]
    even_more: list[complexjson]

    def __init__(
        self,
        value: dict[strjson, listjson],
        numvalues: dict[str, numpyjson],
        whee: dict[strjson, dict[strjson, list[numpyjson]]],
        stuff: complexjson,
        args: list[str],
        woahtypes: dict[str, typejson],
        others: dict[str, dict[strjson, listjson]],
        even_more: list[complexjson],
    ):
        self._value = value
        self._numvalues = numvalues
        self._whee = whee
        self._stuff = stuff
        self._args = args
        self._woah_types = woahtypes
        self._others = others
        self._even_more = even_more


def test_strjsonable():
    x = strjson("hello")
    jsondict = x.to_dict()
    print(jsondict)
    newx = strjson.from_dict(jsondict)
    assert newx._value == "hello"


def test_listjsonable():
    x = listjson(["hello", "world"])
    jsondict = x.to_dict()
    print(jsondict)
    newx = listjson.from_dict(jsondict)
    assert newx._value == ["hello", "world"]


def test_numpyjsonable():
    x = numpyjson(np.array([1, 2, 3]))
    jsondict = x.to_dict()
    print(jsondict)
    newx = numpyjson.from_dict(jsondict)
    assert np.all(newx._value == np.array([1, 2, 3]))


def test_complexjsonable():
    x = complexjson(["hello", strjson("world")], enum.STUFF)
    jsondict = x.to_dict()
    print(jsondict)
    newx = complexjson.from_dict(jsondict)
    assert newx._value == ["hello", strjson("world")]


def test_destroyerjsonable():
    x = the_destroyer(
        {strjson("hello"): listjson(["world"])},
        {"hello": numpyjson(np.array([1, 2, 3]))},
        {strjson("hello"): {strjson("world"): [numpyjson(np.array([1, 2, 3]))]}},
        complexjson(["hello", strjson("world")], enum.STUFF),
        ["hello", "world"],
        {
            "hello": typejson(
                int,
                list[int],
                dict[str, float],
                str,
                dict[str, list[tuple[int, str]]],
                Any,  # type: ignore  # noqa: PGH003
            )
        },
        {"hello": {strjson("world"): listjson(["hello"])}},
        [complexjson(["hello", strjson("world")], enum.STUFF)],
    )
    jsondict = x.to_dict()
    print(jsondict)
    newx = the_destroyer.from_dict(jsondict)
    assert newx._value == {strjson("hello"): listjson(["world"])}
    assert newx._stuff._value == ["hello", strjson("world")]
    assert newx._args == ["hello", "world"]
    assert newx._woah_types["hello"]._simple_type is int
    assert newx._woah_types["hello"]._list_type == list[int]
    assert newx._woah_types["hello"]._dict_type == dict[str, float]
    assert newx._woah_types["hello"]._union_type is str
    assert newx._woah_types["hello"]._nested_type == dict[str, list[tuple[int, str]]]
    assert newx._woah_types["hello"]._any_type == Any
    assert newx._others == {"hello": {strjson("world"): listjson(["hello"])}}
    assert newx._even_more == [complexjson(["hello", strjson("world")], enum.STUFF)]


def test_typejsonable():
    x = typejson(
        simple_type=int,
        list_type=list[int],
        dict_type=dict[str, float],
        union_type=str,
        nested_type=dict[str, list[tuple[int, str]]],
        any_type=Any,  # type: ignore  # noqa: PGH003
    )

    # Convert to dictionary and back
    jsondict = x.to_dict()
    print(jsondict)
    newx = typejson.from_dict(jsondict)

    # Check that types were preserved
    assert newx._simple_type is int
    assert newx._list_type == list[int]
    assert newx._dict_type == dict[str, float]
    assert newx._union_type is str
    assert newx._nested_type == dict[str, list[tuple[int, str]]]
    assert newx._any_type == Any


def test_strjsonable_json():
    x = strjson("hello")
    jsondict = x.to_json()
    print(jsondict)
    newx = strjson.from_json(jsondict)
    assert newx._value == "hello"


def test_listjsonable_json():
    x = listjson(["hello", "world"])
    jsondict = x.to_json()
    print(jsondict)
    newx = listjson.from_json(jsondict)
    assert newx._value == ["hello", "world"]


def test_complexjsonable_json():
    x = complexjson(["hello", strjson("world")], enum.STUFF)
    jsondict = x.to_json()
    print(jsondict)
    newx = complexjson.from_json(jsondict)
    assert newx._value == ["hello", strjson("world")]


def test_destroyerjsonable_json():
    x = the_destroyer(
        {strjson("hello"): listjson(["world"])},
        {"hello": numpyjson(np.array([1, 2, 3]))},
        {strjson("hello"): {strjson("world"): [numpyjson(np.array([1, 2, 3]))]}},
        complexjson(["hello", strjson("world")], enum.STUFF),
        ["hello", "world"],
        {
            "hello": typejson(
                int,
                list[int],
                dict[str, float],
                str,
                dict[str, list[tuple[int, str]]],
                Any,  # type: ignore  # noqa: PGH003
            )
        },
        {"hello": {strjson("world"): listjson(["hello"])}},
        [complexjson(["hello", strjson("world")], enum.STUFF)],
    )
    jsondict = x.to_json()
    print(jsondict)
    newx = the_destroyer.from_json(jsondict)
    assert newx._value == {strjson("hello"): listjson(["world"])}
    assert newx._stuff._value == ["hello", strjson("world")]
    assert newx._args == ["hello", "world"]
    assert newx._woah_types["hello"]._simple_type is int
    assert newx._woah_types["hello"]._list_type == list[int]
    assert newx._woah_types["hello"]._dict_type == dict[str, float]
    assert newx._woah_types["hello"]._union_type is str
    assert newx._woah_types["hello"]._nested_type == dict[str, list[tuple[int, str]]]
    assert newx._woah_types["hello"]._any_type == Any
    assert newx._others == {"hello": {strjson("world"): listjson(["hello"])}}
    assert newx._even_more == [complexjson(["hello", strjson("world")], enum.STUFF)]
