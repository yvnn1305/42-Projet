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
            return "Insufficent power for this spell"
        return wrapper
    return decorator

@power_validator(10)
def cast(power: int, name: str) -> str:
    return f"{name} cast with {power} power"


if __name__ == "__main__":
    print("Testing spell timer...")
    print(fireball("Dragon", 50))
    print()

    print("Testing power validator...")
    print(cast(15, "Lightning"))
    print(cast(5, "Spark"))
