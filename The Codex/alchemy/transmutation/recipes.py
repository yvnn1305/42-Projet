from ..elements import create_air
from ..potions import strength_potion
import elements as elem

def lead_to_gold() -> str:
    return (
        f"Recipe transmuting Lead to Gold: brew {create_air()!r} "
        f"and {strength_potion()!r} mixed with {elem.create_fire()!r}"
    )