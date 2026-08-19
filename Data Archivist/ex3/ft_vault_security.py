def secure_archive(file: str, action: int = 1,
                   content: str = "") -> tuple[bool, str]:
    try:
        if action == 1:
            with open(file) as f:
                return (True, f.read())
        else:
            with open(file, "w") as f:
                f.write(content)
                return (True, "Content successfully written to file")
    except (FileNotFoundError, PermissionError) as e:
        return (False, str(e))


if __name__ == "__main__":
    print("=== Cyber Archives Security ===")
    print()

    print("Using 'secure_archive' to read from a nonexistent file:")
    print(secure_archive("output.txt", 1))
    print()

    print("Using 'secure_archive' to read from an inaccessible file:")
    print(secure_archive("/etc/master.passwd", 1))
    print()

    print("Using 'secure_archive' to read from a regular file:")
    print(secure_archive("text.txt", 1))
    print()

    print("Using 'secure_archive' to write previous content to a new file:")
    print(secure_archive("new_one.txt", 0, "hello world"))
