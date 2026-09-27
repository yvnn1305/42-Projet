from collections.abc import Callable


def fireball(target: str, power: int) -> str:
    return f"Fireball hits {target}"


def heal(target: str, power: int) -> str:
    return f"Heals {target}"


def shield(target: str, power: int) -> str:
    return f"Shield protects {target} with {power} points"


def frostbolt(target: str, power: int) -> str:
    return f"Frostbolt freezes {target} for {power} damage"


def lightning(target: str, power: int) -> str:
    return f"Lightning strikes {target} for {power} damage"


def spell_combiner(spell1: Callable, spell2: Callable) -> Callable:
    def combined(target: str, power: int) -> tuple:
        return (spell1(target, power), spell2(target, power))
    return combined


def power_amplifier(base_spell: Callable, multiplier: int) -> Callable:
    def amplified(target: str, power: int) -> str:
        return (base_spell(target, power * multiplier))
    return amplified


def conditional_caster(condition: Callable, spell: Callable) -> Callable:
    def cast(target: str, power: int) -> str:
        if condition(target, power):
            return spell(target, power)
        return "Spell fizzled"
    return cast


def spell_sequence(spells: list[Callable]) -> Callable:
    def cast_all(target: str, power: int) -> list:
        return [spell(target, power) for spell in spells]
    return cast_all


def main() -> None:
    print("Testing spell combiner...")
    combined = spell_combiner(fireball, heal)   # ← fonctions nues, sans ()
    result = combined("Dragon", 50)
    res = ", ".join(result)
    print(f"Combined spell result: {res}")
    print()

    print("Testing power amplifier...")
    power = 3
    multiplier = 10
    mega = power_amplifier(frostbolt, multiplier)
    print(f"{mega("Dragon", power)}")
    print(f"Original: {power}, Amplified: {power * multiplier}")
    print()

    risky = conditional_caster(lambda target, power: power >= 20, fireball)
    print("Testing with conditional_caster...")
    print(f"True: {risky('Dragon', 50)}")
    print(f"False: {risky('Dragon', 4)}")
    print()

    print("Testing with spell sequence...")
    combo = spell_sequence([lightning, shield, heal])
    results = combo("Dragon", 30)
    print(results)


if __name__ == "__main__":
    main()
