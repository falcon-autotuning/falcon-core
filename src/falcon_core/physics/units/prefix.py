"""Prefixes for units (micro, milli, kilo, etc.)."""

from typing import TYPE_CHECKING

from .constants import (
    ALL_PREFIXES,
    ATTO_EXPONENT,
    ATTO_SYMBOL,
    CENTI_EXPONENT,
    CENTI_SYMBOL,
    DECA_EXPONENT,
    DECA_SYMBOL,
    DECI_EXPONENT,
    DECI_SYMBOL,
    EXA_EXPONENT,
    EXA_SYMBOL,
    FEMTO_EXPONENT,
    FEMTO_SYMBOL,
    GIGA_EXPONENT,
    GIGA_SYMBOL,
    HECTO_EXPONENT,
    HECTO_SYMBOL,
    KILO_EXPONENT,
    KILO_SYMBOL,
    MEGA_EXPONENT,
    MEGA_SYMBOL,
    MICRO_EXPONENT,
    MICRO_SYMBOL,
    MILLI_EXPONENT,
    MILLI_SYMBOL,
    NANO_EXPONENT,
    NANO_SYMBOL,
    PETA_EXPONENT,
    PETA_SYMBOL,
    PICO_EXPONENT,
    PICO_SYMBOL,
    TERA_EXPONENT,
    TERA_SYMBOL,
    UNIT_EXPONENT,
    UNIT_SYMBOL,
    YOCTO_EXPONENT,
    YOCTO_SYMBOL,
    YOTTA_EXPONENT,
    YOTTA_SYMBOL,
    ZEPTO_EXPONENT,
    ZEPTO_SYMBOL,
    ZETTA_EXPONENT,
    ZETTA_SYMBOL,
)
from .dependancies import log10

if TYPE_CHECKING:
    from .typing import ClassVar


class Prefix:
    """SI prefixes for units."""

    # SI prefixes - values
    YOCTO = YOCTO_EXPONENT
    ZEPTO = ZEPTO_EXPONENT
    ATTO = ATTO_EXPONENT
    FEMTO = FEMTO_EXPONENT
    PICO = PICO_EXPONENT
    NANO = NANO_EXPONENT
    MICRO = MICRO_EXPONENT
    MILLI = MILLI_EXPONENT
    CENTI = CENTI_EXPONENT
    DECI = DECI_EXPONENT
    NONE = UNIT_EXPONENT
    DECA = DECA_EXPONENT
    HECTO = HECTO_EXPONENT
    KILO = KILO_EXPONENT
    MEGA = MEGA_EXPONENT
    GIGA = GIGA_EXPONENT
    TERA = TERA_EXPONENT
    PETA = PETA_EXPONENT
    EXA = EXA_EXPONENT
    ZETTA = ZETTA_EXPONENT
    YOTTA = YOTTA_EXPONENT

    # SI prefix symbols
    _symbol_map: "ClassVar[dict[int, str]]" = {
        YOCTO: YOCTO_SYMBOL,
        ZEPTO: ZEPTO_SYMBOL,
        ATTO: ATTO_SYMBOL,
        FEMTO: FEMTO_SYMBOL,
        PICO: PICO_SYMBOL,
        NANO: NANO_SYMBOL,
        MICRO: MICRO_SYMBOL,
        MILLI: MILLI_SYMBOL,
        CENTI: CENTI_SYMBOL,
        DECI: DECI_SYMBOL,
        NONE: UNIT_SYMBOL,
        DECA: DECA_SYMBOL,
        HECTO: HECTO_SYMBOL,
        KILO: KILO_SYMBOL,
        MEGA: MEGA_SYMBOL,
        GIGA: GIGA_SYMBOL,
        TERA: TERA_SYMBOL,
        PETA: PETA_SYMBOL,
        EXA: EXA_SYMBOL,
        ZETTA: ZETTA_SYMBOL,
        YOTTA: YOTTA_SYMBOL,
    }

    # Reverse lookup for symbol to value
    _value_map: "ClassVar[dict[str, int]]" = {
        symbol: value for value, symbol in _symbol_map.items()
    }

    # List of all valid prefixes
    _ALL_PREFIXES = ALL_PREFIXES

    @classmethod
    def get_symbol(cls, prefix_value: int) -> str:
        """Get the symbol for a prefix value.

        Args:
            prefix_value: The prefix value.

        Returns:
            The symbol for the prefix.
        """
        return cls._symbol_map.get(prefix_value, "")

    @classmethod
    def get_value(cls, prefix_symbol: str) -> int:
        """Get the value for a prefix symbol.

        Args:
            prefix_symbol: The prefix symbol.

        Returns:
            The value of the prefix.

        Raises:
            ValueError: If the symbol is not a valid prefix.
        """
        if prefix_symbol not in cls._value_map:
            msg = f"Invalid prefix symbol: {prefix_symbol}"
            raise ValueError(msg)
        return cls._value_map[prefix_symbol]

    @classmethod
    def is_valid(cls, prefix: str) -> bool:
        """Check if a prefix is valid.

        Args:
            prefix: The prefix symbol to check.

        Returns:
            True if the prefix is valid.
        """
        return prefix in cls._ALL_PREFIXES

    @classmethod
    def prefix_multiplication(
        cls,
        first_prefix: str,
        second_prefix: str,
        scale_factor: float,
    ) -> tuple[float, str]:
        """Multiply two prefixes together.

        Args:
            first_prefix: The first prefix symbol.
            second_prefix: The second prefix symbol.

        Returns:
            The optional scaling and symbol of the new prefix.
        """
        first_value = cls.get_value(first_prefix)
        second_value = cls.get_value(second_prefix)
        scale_exponent = int(log10(abs(scale_factor))) * int(
            scale_factor / abs(scale_factor)
        )
        new_exponent = first_value + second_value + scale_exponent
        try:
            new_symbol = cls.get_symbol(new_exponent)
            return scale_factor * 10 ** (-scale_exponent), new_symbol
        except KeyError:
            pass
        try:
            new_symbol = cls.get_symbol(new_exponent - 1)
            return scale_factor * 10 ** (-scale_exponent + 1), new_symbol
        except KeyError:
            new_symbol = cls.get_symbol(new_exponent - 2)
            return scale_factor * 10 ** (-scale_exponent + 2), new_symbol
