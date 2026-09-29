from functools import reduce, partial, lru_cache, singledispatch
from typing import Any
from collections.abc import Callable
import operator


def spell_reducer(spells: list[int], operation: str) -> int:
    if not spells:
        return 0
    ops = {
        "add": operator.add,
        "multiply": operator.mul,
        "max": lambda a, b: a if a > b else b,
        "min": lambda a, b: a if a < b else b,
    }
    fonction = ops.get(operation)
    if fonction is None:
        raise ValueError("Enter a good operation type.")
    return reduce(fonction, spells)


def base_enchantment(power: int, element: str, target: str) -> str:
    return (
        f"{element} enchantment (power {power}) on {target}"
    )


def partial_enchanter(base_enchantment: Callable) -> dict[str, Callable]:
    fire = partial(base_enchantment, power=50, element="Fire")
    water = partial(base_enchantment, power=50, element="Water")
    frost = partial(base_enchantment, power=50, element="Frost")
    return {"Fire": fire, "Water": water, "Frost": frost}


@lru_cache
def memoized_fibonacci(n: int) -> int:
    if n < 2:
        return n
    return memoized_fibonacci(n - 1) + memoized_fibonacci(n - 2)


def spell_dispatcher() -> Callable[[Any], str]:
    @singledispatch
    def cast(spell: Any) -> str:
        return "Unknown spell type"

    @cast.register
    def cast_int(spell: int) -> str:
        return f"{spell} damage"

    @cast.register
    def cast_str(spell: str) -> str:
        return spell

    @cast.register
    def cast_list(spell: list) -> str:
        return f"{len(spell)} spells"
    return cast


if __name__ == "__main__":
    print("Testing spell reducer...")
    print(f"Sum: {spell_reducer([10, 20, 30, 40], 'add')}")
    print(f"Product: {spell_reducer([10, 20, 30, 40], 'multiply')}")
    print(f"Max: {spell_reducer([10, 20, 30, 40], 'max')}")
    print()

    print("Testing partial enchanter...")
    enchant = partial_enchanter(base_enchantment)
    fire = enchant["Fire"]
    water = enchant["Water"]
    frost = enchant["Frost"]
    print(fire(target="Dragon"))
    print(water(target="Fish"))
    print(frost(target="Bear"))
    print()

    print("Testing memoized fibonacci...")
    print(memoized_fibonacci(0))    # 0
    print(memoized_fibonacci(1))    # 1
    print(memoized_fibonacci(10))   # 55
    print(memoized_fibonacci(15))   # 610
#   print(memoized_fibonacci.cache_info())   # look at hits/misses !
    print()

    print("Testing spell dispatcher...")
    cast = spell_dispatcher()
    print(f"Damage spell: {cast(42)}")
    print(f"Enchantment: {cast('fireball')}")
    print(f"Multi-cast: {cast([1, 2, 3])}")
    print(cast(3.14))
