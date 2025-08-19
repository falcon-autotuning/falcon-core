# Constants used for core compilation
from typing import TYPE_CHECKING

from .dependancies import (
    BarrierGate,
    Ohmic,
    PlungerGate,
    ReservoirGate,
    ScreeningGate,
)

if TYPE_CHECKING:
    from .typing import (
        Connection,
    )

CONNECTION_TO_ATTRIBUTE_NAME: dict[type["Connection"], str] = {
    BarrierGate: "barrier_gates",
    PlungerGate: "plunger_gates",
    ReservoirGate: "reservoir_gates",
    ScreeningGate: "screening_gates",
    Ohmic: "ohmics",
}
