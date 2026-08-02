import sys


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: ft_stream_management.py <file>")
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
            transformed = [line + "#" for line in lines]
            edited = "\n".join(transformed)
            print(edited)
            print()
            print("---")
            print("Enter new file name (or empty): ", end="")
            sys.stdout.flush()
            file = sys.stdin.readline().strip()
            if not file:
                print("Not saving data.")
            else:
                try:
                    f = open(file, "w")
                    print(f"Saving data to {file!r}")
                    f.write(edited)
                    f.close()
                    print(f"Data saved in file {file!r}.")
                except (FileNotFoundError, PermissionError) as e:
                    print(f"[STDERR] Error opening file {file!r}: {e}",
                          file=sys.stderr)
                    print("Data not saved.")
        except (FileNotFoundError, PermissionError) as e:
            print(f"[STDERR] Error opening file {sys.argv[1]!r}: {str(e)}",
                  file=sys.stderr)
