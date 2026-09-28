from functools import reduce
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

if __name__ == "__main__":
    print(spell_reducer([10, 20, 30, 40], "add"))
    print(spell_reducer([10, 20, 30, 40], "multiply"))
    print(spell_reducer([10, 20, 30, 40], "max"))
    print(spell_reducer([], "add"))
    print(spell_reducer([10, 20], "divide"))