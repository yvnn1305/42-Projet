import math


def get_player_pos() -> tuple[float, ...]:
    while True:
        valid = []
        res = input("Enter new coordinates as floats in format 'x,y,z': ")
        result = res.split(",")
        if len(result) != 3:
            print("Invalid syntax")
            continue

        try:
            for number in result:
                valid.append(float(number))
        except ValueError as e:
            print(f"Error on parameter {number!r}: {e}")
            continue
        return tuple(valid)


def distance(a: tuple[float, ...], b: tuple[float, ...]) -> float:
    return math.sqrt((b[0] - a[0])**2 + (b[1] - a[1])**2 + (b[2] - a[2])**2)


if __name__ == "__main__":
    print("=== Game Coordinate System ===")
    print()
    print("Get a first set of coordinates")
    first_value = get_player_pos()
    x, y, z = first_value
    print(f"Got a first tuple: {first_value}")
    print(f"It includes: X={x}, Y={y}, Z={z}")
    distance1 = distance((0, 0, 0), first_value)
    print(f"Distance to center: {round(distance1, 4)}")
    print()

    print("Get a second set of coordinates")
    second_value = get_player_pos()
    distance2 = distance(second_value, first_value)
    print(f"Distance between the 2 sets of coordinates: {round(distance2, 4)}")
