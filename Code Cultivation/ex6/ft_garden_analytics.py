#!/usr/bin/python3

class Plant:
    def __init__(self, name: str, height: float, age: float) -> None:
        self.name = name
        self._height = height
        self._days = age
        self._stats = self.Stats()
        self._growth_rate: float = 0.0
        self._height_rate: float = 0.0

    def show(self) -> None:
        print(f"{self.name}: {str(round(self._height, 1))}cm,"
              f" {str(self._days)} days old")
        self._stats._show += 1

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> float:
        return self._days

    def set_height(self, height: float) -> None:
        if height < 0:
            print("Error, height can’t be negative")
        else:
            self._height = height

    def set_age(self, age: float) -> None:
        if age < 0:
            print("Error, age can’t be negative")
        else:
            self._days = age

    def grow(self) -> None:
        self._height = self._height + self._growth_rate
        self._stats._grow += 1

    def age(self) -> None:
        self._days = self._days + self._height_rate
        self._stats._age += 1

    @staticmethod
    def is_older_than_year(age: int) -> bool:
        if age < 366:
            return False
        else:
            return True

    @classmethod
    def anonymous(cls) -> "Plant":
        return cls("Unknown plant", 0.0, 0)

    class Stats:
        def __init__(self) -> None:
            self._age: int = 0
            self._grow: int = 0
            self._show: int = 0

        def show(self) -> None:
            print(f"Stats: {str(self._grow)} grow,"
                  f" {str(self._age)} age, {str(self._show)} show")


class Tree(Plant):
    def __init__(self, name: str, height: float,
                 age: float, trunk_diameter: float) -> None:
        super().__init__(name, height, age)
        self._trunk_diameter = trunk_diameter
        self._stats: Tree.Stats = self.Stats()

    def produce_shade(self) -> None:
        print(f"Tree {self.name} now produces a shade of {str(self._height)}cm"
              f" long and {str(self._trunk_diameter)}cm wide.")
        self._stats._shade += 1

    def show(self) -> None:
        super().show()
        print("Trunk diameter: " + str(self._trunk_diameter) + "cm")

    class Stats(Plant.Stats):
        def __init__(self) -> None:
            super().__init__()
            self._shade: int = 0

        def show(self) -> None:
            super().show()
            print(str(self._shade) + " shade")


class Flower(Plant):
    def __init__(self, name: str, height: float,
                 age: float, color: str) -> None:
        super().__init__(name, height, age)
        self._color = color
        self._bloomed = False
        self._growth_rate = 8.0

    def bloom(self) -> None:
        self._bloomed = True

    def show(self) -> None:
        super().show()
        print("Color: " + self._color)
        if not self._bloomed:
            print(self.name + " has not bloomed yet")
        else:
            print(self.name + " is blooming beautifully!")


class Seed(Flower):
    def __init__(self, name: str, height: float,
                 age: float, color: str) -> None:
        super().__init__(name, height, age, color)
        self._seeds = 0
        self._growth_rate = 30.0
        self._height_rate = 20

    def bloom(self) -> None:
        super().bloom()
        self._seeds = 42

    def show(self) -> None:
        super().show()
        print("Seeds: " + str(self._seeds))


class Vegetable(Plant):
    def __init__(self, name: str, height: float,
                 age: float, harvest_season: str) -> None:
        super().__init__(name, height, age)
        self._harvest_season = harvest_season
        self._nutrition_value = 0

    def show(self) -> None:
        super().show()
        print("")
        print("Harvest season: " + self._harvest_season)
        print("Nutritional value: " + str(self._nutrition_value))

    def grow(self) -> None:
        super().grow()

    def age(self) -> None:
        super().age()
        self._nutrition_value += 1


def display_stats(plant: Plant) -> None:
    plant._stats.show()


if __name__ == "__main__":
    print("=== Garden statistics ===")
    print("=== Check year-old")

    print(f"Is 30 days more than a year? -> {Plant.is_older_than_year(30)}")
    print(f"Is 400 days more than a year? -> {Plant.is_older_than_year(400)}")
    print("")

    print("=== Flower")
    plant1 = Flower("Rose", 15.0, 10, "red")
    plant1.show()
    print("[statistics for Rose]")
    display_stats(plant1)
    print("[asking the rose to grow and bloom]")
    plant1.grow()
    plant1.bloom()
    plant1.show()
    print("[statistics for Rose]")
    display_stats(plant1)
    print("")

    print("=== Tree")
    plant2 = Tree("Oak", 200.0, 365, 5.0)
    plant2.show()
    print("[statistics for Oak]")
    display_stats(plant2)
    print("[asking the oak to produce shade]")
    plant2.produce_shade()
    print("[statistics for Oak]")
    display_stats(plant2)
    print("")

    print("=== Seed")
    plant3 = Seed("Sunflower", 80.0, 45, "yellow")
    plant3.show()
    print("[make sunflower grow, age and bloom]")
    plant3.grow()
    plant3.age()
    plant3.bloom()
    plant3.show()
    print("[statistics for Sunflower]")
    display_stats(plant3)
    print("")

    print("=== Anonymous")
    anonymous = Plant.anonymous()
    anonymous.show()
    print("[statistics for Unknown plant]")
    display_stats(anonymous)
