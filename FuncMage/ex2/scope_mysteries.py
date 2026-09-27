from collections.abc import Callable


def mage_counter() -> Callable:
    count = 0

    def counter() -> int:
        nonlocal count
        count += 1
        return count
    return counter


def spell_accumulator(initial_power: int) -> Callable:
    total = initial_power

    def accummulate(amount: int) -> int:
        nonlocal total
        total = total + amount
        return total
    return accummulate


def enchantment_factory(enchantment_type: str) -> Callable:
    def enchant(item_name: str) -> str:
        return f"{enchantment_type} {item_name}"
    return enchant


def memory_vault() -> dict[str, Callable]:
    storage = {}

    def store(key: str, value) -> None:
        storage[key] = value

    def recall(key: str):
        return storage.get(key, "Memory not found")
    return {'store': store, 'recall': recall}


if __name__ == "__main__":
    print("Testing mage counter...")
    a = mage_counter()
    b = mage_counter()
    print(f"counter_a call 1: {a()}")
    print(f"counter_a call 2: {a()}")
    print(f"counter_b call 1: {b()}")
    print()

    print("Testing spell accumulator...")
    acc = spell_accumulator(100)
    print(f"Base 100, add 20: {acc(20)}")
    print(f"Base 100, add 30: {acc(30)}")
    print()

    print("Testing enchantment factory...")
    enc1 = enchantment_factory("Flaming")
    enc2 = enchantment_factory("Frozen")
    print(enc1("Sword"))
    print(enc2("Shield"))
    print()

    print("Testing memory vault...")
    vault = memory_vault()
    vault['store']('secret', 42)
    print("Store 'secret' = 42")
    print(f"Recall 'secret': {vault['recall']('secret')}")
    print(f"Recall 'unknown': {vault['recall']('unknown')}")
