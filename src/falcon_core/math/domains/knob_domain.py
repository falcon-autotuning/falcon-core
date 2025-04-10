"""A domain for a knob to fall in a range."""

from typing import TYPE_CHECKING

from .constants import INSTRUMENT_TYPES
from .dependancies import Jsonable, Knob, Units
from .domain import Domain

if TYPE_CHECKING:
    from .typing import Connection, SymbolUnit


class KnobDomain(Knob, Domain, Jsonable):
    """A Knob with physical bounds."""

    def __init__(
        self,
        default_name: str,
        bounds: tuple[float, float],
        pseudo_name: "Connection | None" = None,
        instrument_type: str = INSTRUMENT_TYPES[0],
        lesser_bound_contained: bool = True,
        greater_bound_contained: bool = True,
        units: "SymbolUnit" = Units.VOLT,
        description: str = "",
    ) -> None:
        """Initialize the KnobDomain object.

        Args:
            default_name (str): The default name of the knob.
            bounds (tuple[float, float]): The bounds of the knob.
            pseudo_name (Connection | None): The pseudo name of the knob.
            instrument_type (type): The type of instrument.
            lesser_bound_contained (bool): Whether the lesser bound is contained.
            greater_bound_contained (bool): Whether the greater bound is contained.
            units (str): The units of the knob.
            description (str): The description of the knob.
        """
        Knob.__init__(
            self,
            default_name=default_name,
            pseudo_name=pseudo_name,
            instrument_type=instrument_type,
            units=units,
            description=description,
        )
        Domain.__init__(
            self,
            bounds=bounds,
            lesser_bound_contained=lesser_bound_contained,
            greater_bound_contained=greater_bound_contained,
        )

    @classmethod
    def from_knob_and_domain(
        cls,
        knob: Knob,
        domain: Domain,
    ) -> "KnobDomain":
        """Create a KnobDomain from a Knob and a Domain.

        Args:
            knob (Knob): The knob to create a domain from.
            domain (Domain): The domain to create a knob from.

        Returns:
            KnobDomain: The knob domain.
        """
        return cls(
            default_name=knob.default_name,
            bounds=domain.bounds,
            pseudo_name=knob.pseudo_name,
            instrument_type=knob.instrument_type,
            lesser_bound_contained=domain.lesser_bound_contained,
            greater_bound_contained=domain.greater_bound_contained,
            units=knob.units,
            description=knob.description,
        )

    @classmethod
    def from_domain(
        cls,
        domain: Domain,
        default_name: str,
        pseudo_name: "Connection | None" = None,
        instrument_type: str = INSTRUMENT_TYPES[0],
        units: "SymbolUnit" = Units.VOLT,
        description: str = "",
    ) -> "KnobDomain":
        """Create a KnobDomain from a Domain.

        Args:
            domain (Domain): The domain to create a knob from.
            default_name (str): The default name of the knob.
            pseudo_name (str): The pseudo name of the knob.
            instrument_type (type): The type of instrument.
            units (str): The units of the knob.
            description (str): The description of the knob.

        Returns:
            KnobDomain: The knob domain.
        """
        return cls(
            default_name=default_name,
            bounds=domain.bounds,
            pseudo_name=pseudo_name,
            instrument_type=instrument_type,
            lesser_bound_contained=domain.lesser_bound_contained,
            greater_bound_contained=domain.greater_bound_contained,
            units=units,
            description=description,
        )

    @classmethod
    def from_knob(
        cls,
        knob: Knob,
        bounds: tuple[float, float],
        lesser_bound_contained: bool = True,
        greater_bound_contained: bool = True,
    ) -> "KnobDomain":
        """Create a KnobDomain from a Knob.

        Args:
            knob (Knob): The knob to create a domain from.
            bounds (tuple[float, float]): The bounds of the knob.
            lesser_bound_contained (bool): Whether the lesser bound is contained.
            greater_bound_contained (bool): Whether the greater bound is contained.

        Returns:
            KnobDomain: The knob domain.
        """
        return cls(
            default_name=knob.default_name,
            bounds=bounds,
            pseudo_name=knob.pseudo_name,
            instrument_type=knob.instrument_type,
            lesser_bound_contained=lesser_bound_contained,
            greater_bound_contained=greater_bound_contained,
            units=knob.units,
            description=knob.description,
        )

    @property
    def knob(self) -> Knob:
        """Return the knob."""
        return Knob(
            default_name=self.default_name,
            pseudo_name=self.pseudo_name,
            instrument_type=self.instrument_type,
            units=self.units,
            description=self.description,
        )

    @property
    def domain(self) -> Domain:
        """Return the domain."""
        return Domain(
            bounds=self.bounds,
            lesser_bound_contained=self.lesser_bound_contained,
            greater_bound_contained=self.greater_bound_contained,
        )
