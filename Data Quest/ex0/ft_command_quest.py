import sys

if __name__ == "__main__":
    print("=== Command Quest ===")
    print(f"Program name: {sys.argv[0]}")
    if len(sys.argv) < 2:
        print("No arguments provided!")
    else:
        print(f"Arguments received: {len(sys.argv) - 1}")
        for i in range(1, len(sys.argv)):
            print(f"Argument {str(i)}: {sys.argv[i]}")
        print(f"Total arguments: {len(sys.argv)}")
