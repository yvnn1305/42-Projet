def garden_operations(operation_number: int) -> None:
    if operation_number == 0:
        int("abc")
    elif operation_number == 1:
        10 / 0
    elif operation_number == 2:
        open("42.txt")
    elif operation_number == 3:
        "abc" + 22
    return


def test_errors_types() -> None:
    for i in range(5):
        print("Testing operation " + str(i) + "...")
        try:
            garden_operations(i)
        except (ValueError, ZeroDivisionError,
                TypeError, FileNotFoundError) as e:
            print("Caught " + e.__class__.__name__ + ": " + str(e))
        else:
            print("Operation completed successfully!")


if __name__ == "__main__":
    print("=== Garden Error Types Demo ===")
    test_errors_types()
    print("")
    print("All error types tested successfully!")
