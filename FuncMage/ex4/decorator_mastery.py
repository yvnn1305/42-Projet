import time
from functools import wraps
from collections.abc import Callable


def spell_timer(func: Callable) -> Callable:
    @wraps(func)
    def wrapper(*args, **kwargs):
        print(f"Casting {func.__name__}...")
        start = time.time()
        result = func(*args, **kwargs)
        end = time.time()
        duration = end - start
        print(f"Spell completed in {duration:.3f} seconds")
        return result
    return wrapper


@spell_timer
def fireball(target: str, power: int) -> str:
    time.sleep(0.1)
    return "Fireball cast!"


def power_validator(min_power: int) -> Callable:
    def decorator(func: Callable) -> Callable:
        @wraps(func)
        def wrapper(*args, **kwargs):
            power = args[0]
            if power >= min_power:
                return func(*args, **kwargs)
            return "Insufficient power for this spell"
        return wrapper
    return decorator


@power_validator(10)
def cast(power: int, name: str) -> str:
    return f"{name} cast with {power} power"


def retry_spell(max_attempts: int) -> Callable:
    def decorator(func: Callable) -> Callable:
        @wraps(func)
        def wrapper(*args, **kwargs):
            for i in range(max_attempts):
                try:
                    result = func(*args, **kwargs)
                    return result
                except Exception:
                    print("Spell failed, retrying... (attempt "
                          f"{i + 1}/{max_attempts})")
            return f"Spell casting failed after {max_attempts} attempts"
        return wrapper
    return decorator


@retry_spell(3)
def unstable_spell(target: str, power: int) -> str:
    raise ValueError("fizzled")


@retry_spell(5)
def stable_spell(target: str, power: int) -> str:
    return f"{target} hit for {power}"


class MageGuild:
    @staticmethod
    def validate_mage_name(name: str) -> bool:
        repl = name.replace(" ", "")
        if len(name) >= 3 and repl.isalpha():
            return True
        else:
            return False

    def cast_spell(self, spell_name: str, power: int) -> str:
        @power_validator(10)
        def _do_cast(power: int, spell_name: str) -> str:
            return f"Successfully cast {spell_name} with {power} power"
        return _do_cast(power, spell_name)


if __name__ == "__main__":
    print("Testing spell timer...")
    print(fireball("Dragon", 50))
    print()

    print("Testing power validator...")
    print(cast(15, "Lightning"))
    print(cast(5, "Spark"))
    print()

    print("Testing retry spell...")
    print(unstable_spell("Dragon", 50))
    print(stable_spell("Dragon", 50))
    print()

    print("Testing MageGuild...")
    guild = MageGuild()
    print(MageGuild.validate_mage_name("Y ann"))
    print(MageGuild.validate_mage_name("Yan/n"))
    print(guild.cast_spell("Lightning", 15))
    print(guild.cast_spell("Spark", 5))
