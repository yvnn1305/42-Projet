import elements as elem
from . import elements


def healing_potion() -> str:
    return (
        f"Healing potion brewed with {elements.create_earth()!r}"
        f" and {elements.create_air()!r}"
    )


def strength_potion() -> str:
    return (
        f"Strength potion brewed with {elem.create_fire()!r} and"
        f" {elem.create_water()!r}"
    )
