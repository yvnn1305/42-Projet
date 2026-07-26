import sys


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: ft_archive_creation.py <file>")
    else:
        print("=== Cyber Archives Recovery & Preservation ===")
        print(f"Accessing file {sys.argv[1]!r}")
        try:
            f = open(sys.argv[1])
            print("---")
            print()
            content = f.read()
            print(content)
            print()
            print("---")
            lines = content.splitlines()
            f.close()
            print(f"File {sys.argv[1]!r} closed.")
            print()
            print("Transform data:")
            print("---")
            print()
            liness = [line + "#" for line in lines]
            edited = "\n".join(liness)
            print(edited)
            print()
            print("---")
            file = input("Enter new file name (or empty): ")
            if not file:
                print("Not saving data.")
            else:
                f = open(file, "x")
                f.write(edited)
                print(f"Saving data to {file!r}")
                print(f"Data saved in file {file!r}.")
        except (FileNotFoundError, PermissionError) as e:
            print(f"Error opening file {sys.argv[1]!r}: {str(e)}")
