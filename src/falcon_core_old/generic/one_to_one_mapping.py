"""A mapping that enforces a one-to-one relationship between keys and values."""

from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from .typing import Iterator


class OneToOneMapping[K, V]:
    """A mapping that enforces a one-to-one relationship between keys and values."""

    def __init__(
        self,
        initial: list[tuple[K, V]] = [],
    ):
        """A mapping that enforces a one-to-one relationship between keys and values."""
        self._items: list[tuple[K, V]] = initial if initial else []

    def __setitem__(self, key: K, value: V) -> None:
        """Set a key-value pair."""
        self._remove_by_key(key)
        self._remove_by_value(value)
        self._items.append((key, value))

    def __getitem__(self, key: K) -> V:
        """Get the value corresponding to a key."""
        for k, v in self._items:
            if k == key:
                return v
        raise KeyError(key)

    def __delitem__(self, key: K) -> None:
        """Delete a key-value pair."""
        self._remove_by_key(key)

    def __len__(self) -> int:
        """Get the number of key-value pairs."""
        return len(self._items)

    def __iter__(self) -> "Iterator[K]":
        """Iterate over the keys."""
        return (k for k, v in self._items)

    def values(self) -> "Iterator[V]":
        """Return an iterator over the values."""
        return (v for k, v in self._items)

    def items(self) -> "Iterator[tuple[K, V]]":
        """Iterate over the key-value pairs."""
        return iter(self._items)

    def invert(self) -> "OneToOneMapping[V, K]":
        """Invert the mapping."""
        inverted_items = [(v, k) for k, v in self._items]
        return OneToOneMapping[V, K](inverted_items)

    def __contains__(self, key: K) -> bool:
        """Check if a key is in the mapping."""
        return any(k == key for k, v in self._items)

    def get(self, key: K, default: V | None = None) -> V | None:
        """Get the value corresponding to a key, or a default value if the key is not present."""
        for k, v in self._items:
            if k == key:
                return v
        return default

    def _remove_by_key(self, key: K) -> None:
        """Remove a key-value pair by key."""
        self._items = [(k, v) for k, v in self._items if k != key]

    def _remove_by_value(self, value: V) -> None:
        """Remove a key-value pair by value."""
        self._items = [(k, v) for k, v in self._items if v != value]
