"""Creation of default names for structures within FAlCon."""

from .dependancies import Generic, TypeVar

T = TypeVar("T", bound="NameBase")


class NameBase(Generic[T]):
    """Base class for ordering name types.

    Index string can be set for different children to act differently.
    """

    value: str | int
    name: str  # pattern=r"group\d+"
    num: int = 0

    index_string: str = ""

    def __init__(self, value: str | int):
        if isinstance(value, int):
            self.value = value
            self.name = self.index_string + str(self.value)
            self.num = self.value
        elif isinstance(value, str):
            self.value = value
            self.name = self.value
            self.num = int(self.value[len(self.index_string) :])
        else:
            msg = "Value must be an int or str"
            raise TypeError(msg)

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
