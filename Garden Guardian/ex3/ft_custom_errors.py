class GardenError(Exception):
    pass


class PlantError(GardenError):
    def __init__(self, message: str = "Unknown plant error") -> None:
        super().__init__(message)


class WaterError(GardenError):
    def __init__(self, message: str = "Unknown water error") -> None:
        super().__init__(message)


def test_custom_error() -> None:
    print("Testing PlantError")
    try:
        raise PlantError("The tomato is wilting!")
    except PlantError as e:
        print(f"Caught {e.__class__.__name__}: {e}")
    print("")

    print("Testing WaterError...")
    try:
        raise WaterError("Not enough water in the tank!")
    except WaterError as e:
        print(f"Caught {e.__class__.__name__}: {e}")
    print("")

    print("Testing catching all garden errors...")
    try:
        raise PlantError("The tomato is wilting!")
    except GardenError as e:
        print(f"Caught {PlantError.__bases__[0].__name__}: {e}")

    try:
        raise WaterError("Not enough water in the tank!")
    except GardenError as e:
        print(f"Caught {WaterError.__bases__[0].__name__}: {e}")
    print("")
    print("All custom error types work correctly!")


if __name__ == "__main__":
    print("=== Custom Garden Errors Demo ===")
    print("")
    test_custom_error()
