"""Creation of default names for structures within FAlCon."""

from .dependancies import Generic, Jsonable, TypeVar

T = TypeVar("T", bound="NameBase")


class NameBase(Generic[T], Jsonable):
    """Base class for ordering name types.

    Index string can be set for different children to act differently.
    """

    _value: str | int
    _name: str  # pattern=r"group\d+"
    _num: int = 0

    _index_string: str = ""

    def __init__(self, value: str | int):
        if isinstance(value, int):
            self._value = value
            self._name = self.index_string + str(self.value)
            self._num = value
        elif isinstance(value, str):
            self._value = value
            self._name = value
            self._num = int(value[len(self.index_string) :])
        else:
            msg = "Value must be an int or str"
            raise TypeError(msg)

    @property
    def value(self) -> str | int:
        """The value of the name."""
        return self._value

    @property
    def name(self) -> str:
        """The name of hte object."""
        return self._name

    @property
    def num(self) -> int:
        """The number of the object."""
        return self._num

    @classmethod
    @property
    def index_string(cls) -> str:
        """The index string of the object."""
        return cls._index_string

    def __hash__(self):
        """Allows it to be a key in dictionaries."""
        return hash(self.num)

    def __eq__(self, other: object) -> bool:
        """Equality only supported between like objects, str, and int."""
        if isinstance(other, self.__class__):
            return other.num == self.num
        if isinstance(other, str):
            return other == self.name
        if isinstance(other, int):
            return other == self.num
        msg = f"Only supports comparisons with {self.__class__.__name__}, str, and int"
        raise TypeError(msg)

    def __add__(self: T, other: T) -> T:
        """Addition supported only between instances of the same class."""
        if isinstance(other, self.__class__):
            new = other.num + self.num
            return self.__class__(value=new)
        msg = f"Only supports addition with {self.__class__.__name__}"
        raise TypeError(msg)

    def __sub__(self: T, other: T) -> T:
        """Subtraction supported only between instances of the same class."""
        if isinstance(other, self.__class__):
            new = self.num - other.num
            return self.__class__(value=new)
        msg = f"Only supports subtraction with {self.__class__.__name__}"
        raise TypeError(msg)

    def __str__(self) -> str:
        """Allows conversion of this to a string."""
        return self.name
