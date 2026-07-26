def input_temperature(temp_str: str) -> str:
    value = int(temp_str)
    if value > 40:
        raise ValueError(str(value) + "°C is too hot for plants (max 40°C)")
    elif value < 0:
        raise ValueError(str(value) + "°C is too cold for plants (min 0°C)")
    return temp_str


if __name__ == "__main__":
    print("=== Garden Temperature Checker ===")
    print("")
    try:
        print("Input data is '25'")
        tmp = input_temperature("25")
        print("Temperature is now 25°C")
    except ValueError as e:
        print("Caught input_temperature error: " + str(e))

    print("")
    try:
        print("Input data is 'abc'")
        tmp = input_temperature("abc")
        print("Temperature is now 'abc'")
    except ValueError as e:
        print("Caught input_temperature error: " + str(e))

    print("")
    try:
        print("Input data is '100'")
        tmp = input_temperature("100")
        print("Temperature is now 100°C")
    except ValueError as e:
        print("Caught input_temperature error: " + str(e))

    print("")
    try:
        print("Input data is '-50'")
        tmp = input_temperature("-50")
        print("Temperature is now -50°C")
    except ValueError as e:
        print("Caught input_temperature error: " + str(e))

    print("")
    print("All tests completed - program didn't crash!")
