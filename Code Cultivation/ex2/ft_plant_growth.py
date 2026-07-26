#!/usr/bin/python3

class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.days = age

    def show(self) -> None:
        print(f"{self.name}: {str(round(self.height, 1))}cm, "
              f"{str(self.days)} days old")

    def grow(self) -> None:
        self.height = self.height + 0.8

    def age(self) -> None:
        self.days = self.days + 1


if __name__ == "__main__":
    plant1 = Plant("Rose", 25.0, 30)
    initial_height = plant1.height
    print("=== Garden Plant Growth ===")
    plant1.show()
    for i in range(1, 7 + 1):
        print("=== Day " + str(i) + " ===")
        plant1.grow()
        plant1.age()
        plant1.show()
    print("Growth this week: "
          f"{str(round(plant1.height - initial_height, 1))}cm")
