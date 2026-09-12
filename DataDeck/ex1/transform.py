from .capabilities import TransformCapability
from ex0 import Creature


class Shiftling(Creature, TransformCapability):
    def __init__(self) -> None:
        super().__init__("Shiftling", "Normal")
        self._is_transformed = False

    def attack(self) -> str:
        if self._is_transformed:
            return f"{self._name} performs a boosted strike!"
        return "Shiftling attacks normally."

    def transform(self) -> str:
        self._is_transformed = True
        return f"{self._name} shifts into a sharper form!"

    def revert(self) -> str:
        return f"{self._name} returns to normal."


class Morphagon(Creature, TransformCapability):
    def __init__(self) -> None:
        super().__init__("Morphagon", "Normal/Dragon")
        self._is_transformed = False

    def attack(self) -> str:
        if self._is_transformed:
            return f"{self._name} unleashes a devastating morph strike!"
        return f"{self._name} attacks normally."

    def transform(self) -> str:
        self._is_transformed = True
        return f"{self._name} morphs into a dragonic battle form!"

    def revert(self) -> str:
        return f"{self._name} stabilizes its form."
