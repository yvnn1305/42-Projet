def input_temperature(temp_str: str) -> int:
    return (int(temp_str))


if __name__ == "__main__":
    print("=== Garden Temperature ===")
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
    print("All tests completed - program didn't crash!")
