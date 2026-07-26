#!/usr/bin/python3

class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self._height = height
        self._days = age

    def show(self) -> None:
        print(f"Plant created: {self.name}: "
              f"{str(round(self._height, 1))}cm, {str(self._days)} days old")

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._days

    def set_height(self, height: float) -> None:
        if height < 0:
            print(f"{self.name}: Error, height can’t be negative")
            print("Height updated rejected")
        else:
            self._height = height
            print(f"Height updated: {self._height}cm")

    def set_age(self, age: int) -> None:
        if age < 0:
            print(f"{self.name}: Error, age can’t be negative")
            print("Age update rejected")
        else:
            self._days = age
            print(f"Age updated: {self._days} days")


if __name__ == "__main__":
    print("=== Garden Security System ===")
    plant1 = Plant("Rose", 15.0, 10)
    plant1.show()
    print()
    plant1.set_height(25)
    plant1.set_age(30)
    print()
    plant1.set_height(-244)
    plant1.set_age(-436)
    print()
    print("Current state: ", end="")
    plant1.show()
