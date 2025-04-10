"""A mixin for 1D labelled arrays."""

from typing import TYPE_CHECKING

from .dependancies import Is1D, Protocol, cast, runtime_checkable, wraps

if TYPE_CHECKING:
    from ...typing import Any, Callable, array1D


@runtime_checkable
class HasArray(Protocol):
    """Protocol defining required attributes for IsLabelled1D mixin."""

    @property
    def array(self) -> "array1D": ...


def requires_1d_array(method: "Callable") -> "Callable":
    """Decorator to ensure the method is called on a class with a 1D array property."""

    @wraps(method)
    def wrapper(self: "Any", *args: "Any", **kwargs: "Any") -> "Any":
        if not isinstance(self, HasArray) or not isinstance(self.array, Is1D):
            msg = "Class inheriting from IsLabelled1D must have an array property with Is1D methods"
            raise TypeError(msg)
        return method(self, *args, **kwargs)

    return wrapper


class IsLabelled1D:
    """A mixin that provides 1D-specific functionality to labelled array classes.

    The class that inherits from this must provide:
    - array property returning an array that implements Is1D mixin
    """

    @property
    def array(self) -> "Any":
        """This property must be implemented by classes that inherit from IsLabelled1D.

        This declaration is for type checking only and will not be called at runtime.
        """
        msg = "Classes inheriting from IsLabelled1D must implement array property"
        raise NotImplementedError(msg)

    @property
    def _1d_array(self) -> Is1D:
        """Get the array cast to Is1D type.

        This avoids repetitive casting in all methods.
        """
        return cast(Is1D, self.array)

    @requires_1d_array
    def get_start(self) -> float:
        """Get the first element of the 1D array."""
        return self._1d_array.get_start()

    @requires_1d_array
    def get_end(self) -> float:
        """Get the last element of the 1D array."""
        return self._1d_array.get_end()

    @requires_1d_array
    def get_min(self) -> float:
        """Get the minimum value in the 1D array."""
        return self._1d_array.get_min()

    @requires_1d_array
    def get_max(self) -> float:
        """Get the maximum value in the 1D array."""
        return self._1d_array.get_max()

    @requires_1d_array
    def is_decreasing(self) -> bool:
        """Check if the array is decreasing."""
        return self._1d_array.is_decreasing()

    @requires_1d_array
    def is_increasing(self) -> bool:
        """Check if the array is increasing."""
        return self._1d_array.is_increasing()

    @requires_1d_array
    def get_distance(self) -> float:
        """Get the distance between the first and last element."""
        return self._1d_array.get_distance()

    @requires_1d_array
    def get_std(self) -> float:
        """Get the standard deviation of the 1D array."""
        return self._1d_array.get_std()

    @requires_1d_array
    def get_mean(self) -> float:
        """Get the mean of the 1D array."""
        return self._1d_array.get_mean()

    @requires_1d_array
    def get_closest_index(self, value: float) -> int:
        """Get the index of the closest element to the given value."""
        return self._1d_array.get_closest_index(value)

    @requires_1d_array
    def reverse(self) -> None:
        """Reverse the 1D array."""
        self._1d_array.reverse()
