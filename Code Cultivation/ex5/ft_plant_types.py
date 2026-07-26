#!/usr/bin/python3


class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self._height = height
        self._days = age

    def show(self) -> None:
        print(f"{self.name}: {str(round(self._height, 1))}cm,"
              f" {str(self._days)} days old")

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._days

    def set_height(self, height: int) -> None:
        if height < 0:
            print("Error, height can’t be negative")
        else:
            self._height = height

    def set_age(self, age: int) -> None:
        if age < 0:
            print("Error, age can’t be negative")
        else:
            self._days = age

    def grow(self) -> None:
        self._height = self._height + 2.1

    def age(self) -> None:
        self._days = self._days + 1


class Tree(Plant):
    def __init__(self, name: str, height: float,
                 age: int, trunk_diameter: float) -> None:
        super().__init__(name, height, age)
        self._trunk_diameter = trunk_diameter

    def produce_shade(self) -> None:
        print(f"Tree {self.name} now produces a shade of {str(self._height)}cm"
              f" long and {str(self._trunk_diameter)}cm wide.")

    def show(self) -> None:
        super().show()
        print("Trunk diameter: " + str(self._trunk_diameter) + "cm")


class Flower(Plant):
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age)
        self._color = color
        self._bloomed = False

    def bloom(self) -> None:
        self._bloomed = True

    def show(self) -> None:
        super().show()
        print("Color: " + self._color)
        if not self._bloomed:
            print(self.name + " has not bloomed yet")
        else:
            print(self.name + " is blooming beautifully!")


class Vegetable(Plant):
    def __init__(self, name: str, height: float,
                 age: int, harvest_season: str) -> None:
        super().__init__(name, height, age)
        self._harvest_season = harvest_season
        self._nutrition_value = 0

    def show(self) -> None:
        super().show()
        print("Harvest season: " + self._harvest_season)
        print("Nutritional value: " + str(self._nutrition_value))

    def grow(self) -> None:
        super().grow()

    def age(self) -> None:
        super().age()
        self._nutrition_value += 1


if __name__ == "__main__":
    print("=== Garden Plant Types ===")
    print("=== Flower")
    plant1 = Flower("Rose", 15.0, 10, "red")
    plant1.show()
    print("[asking the rose to bloom]")
    plant1.bloom()
    plant1.show()

    print("")
    print("=== Tree")
    plant2 = Tree("Oak", 200.0, 365, 5.0)
    plant2.show()
    print("[asking the oak to produce shade]")
    plant2.produce_shade()

    print("")
    print("=== Vegetable")
    plant3 = Vegetable("Tomato", 5.0, 10, "April")
    plant3.show()
    print("[make tomato grow and age for 20 days]")
    for i in range(20):
        plant3.age()
        plant3.grow()
    plant3.show()
