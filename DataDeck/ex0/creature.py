from abc import ABC, abstractmethod


class Creature(ABC):
    def __init__(self, name: str, creature_type: str) -> None:
        self._name: str = name
        self._creature_type: str = creature_type

    @abstractmethod
    def attack(self) -> str:
        ...

    def describe(self) -> str:
        return (f"{self._name} is a {self._creature_type} type Creature")


class Flameling(Creature):
    def __init__(self) -> None:
        super().__init__("Flameling", "Fire")

    def attack(self) -> str:
        return "Flameling uses Ember!"


class Pyrodon(Creature):
    def __init__(self) -> None:
        super().__init__("Pyrodon", "Fire/Flying")

    def attack(self) -> str:
        return "Pyrodon uses Flamethrower!"


class Aquabub(Creature):
    def __init__(self) -> None:
        super().__init__("Aquabub", "Water")

    def attack(self) -> str:
        return "Aquabub uses Water Gun!"


class Torragon(Creature):
    def __init__(self) -> None:
        super().__init__("Torragon", "Water")

    def attack(self) -> str:
        return "Torragon uses Hydro Pump!"


if __name__ == "__main__":
    f = Flameling()
    g = Pyrodon()
    h = Aquabub()
    i = Torragon()
    print(f.describe())
    print(g.describe())
    print(h.describe())
    print(i.describe())
