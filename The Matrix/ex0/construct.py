import os
import site
import sys

in_venv: bool = sys.prefix != sys.base_prefix

pyth = sys.executable
venv = os.path.basename(sys.prefix)
path = sys.prefix
inst_path = site.getsitepackages()[0]

if in_venv:
    print("MATRIX STATUS: Welcome to the construct")
    print()

    print(f"Current Python: {pyth}")
    print(f"Virtual Environment: {venv}")
    print(f"Environment Path: {path}")
    print()

    print("SUCCESS: You're in a isolated environment!")
    print("Safe to install packages without affecting")
    print("the global system.")
    print()

    print("Package installation path:")
    print(f"{inst_path}")
else:
    print("MATRIX STATUS: You're still plugged in")
    print()

    print(f"Current Python: {pyth}")
    print("Virtual Environment: None detected")
    print()

    print("WARNING: You're in the global environment!")
    print("The machines can see everything you install.")
    print()

    print("To enter the construct, run:")
    print("python -m venv matrix_env")
    print("source matrix_env/bin/activate # On Unix")
    print("matrix_env\\Scripts\\activate # On Windows")
    print()

    print("Then run this program again.")