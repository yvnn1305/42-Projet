import sys

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: ft_ancien_text.py <file>")
    else:
        print("=== Cyber Archives Recovery & Preservation ===")
        print(f"Accessing file {sys.argv[1]!r}")
        try:
            f = open(sys.argv[1])
            print("---")
            print()
            print(f.read())
            print()
            print("---")
            f.close()
            print(f"File {sys.argv[1]!r} closed")
        except (FileNotFoundError, PermissionError) as e:
            print(f"Error opening file {sys.argv[1]!r}: {str(e)}")
