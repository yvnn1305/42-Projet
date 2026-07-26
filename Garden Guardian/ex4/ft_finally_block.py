class GardenError(Exception):
    pass


class PlantError(GardenError):
    def __init__(self, message: str = "Unknown plant error"):
        super().__init__(message)


class WaterError(GardenError):
    def __init__(self, message: str = "Unknown water error"):
        super().__init__(message)


def water_plant(plant_name: str) -> None:
    if plant_name == plant_name.capitalize():
        print(f"Watering {plant_name}: [OK]")
    else:
        raise PlantError(f"Invalid plant name to water: '{plant_name}'")


def test_watering_system() -> None:
    print("Testing valid plants...")
    print("Opening watering system")
    try:
        water_plant("Tomato")
        water_plant("Lettuce")
        water_plant("Carrots")
    except PlantError as e:
        print(f"Caught {e.__class__.__name__}: {e}")
        print(".. ending tests and returning to main")
        return
    finally:
        print("Closing watering system")
    print("")

    print("Testing invalid plants...")
    print("Opening watering system")
    try:
        water_plant("Tomato")
        water_plant("lettuce")
    except PlantError as e:
        print(f"Caught {e.__class__.__name__}: {e}")
        print(".. ending tests and returning to main")
        return
    finally:
        print("Closing watering system")


if __name__ == "__main__":
    print("=== Garden Watering System ===")

    print("")
    test_watering_system()

    print("")
    print("Cleanup always happens, even with errors!")
