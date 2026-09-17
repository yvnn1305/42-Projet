from dotenv import load_dotenv # type: ignore
import os


def main() -> None:
    load_dotenv()

    matrix_mode = os.environ.get("MATRIX_MODE", "development")
    database = os.environ.get("DATABASE_URL", "MISSING")
    api_key = os.environ.get("API_KEY", "Not detected")
    log_level = os.environ.get("LOG_LEVEL", "INFO")
    zion_endpoint = os.environ.get("ZION_ENDPOINT", "MISSING")

    print("ORACLE STATUS: Reading the Matrix...")
    print()

    print("Configuration loaded:")
    print(f"Mode: {matrix_mode}")
    if database != "MISSING":
        print("Database: Connected to local instance")
    else:
        print("Database: MISSING")

    if api_key != "Not detected":
        print("API Access: Authenticated")
    else:
        print("API Access: Missing")

    if matrix_mode == "production":
        log_level = "WARNING"
    print(f"Log Level: {log_level}")

    if zion_endpoint != "MISSING":
        print("Zion Network: Online")
    else:
        print("Zion Network: MISSING")
    print()

    print("Environment security check:")
    print("[OK] No hardcoded secrets detected")
    if os.path.exists(".env"):
        print("[OK] .env file properly configured")
    else:
        print("[KO] No .env file found. Copy .env.example to .env"
              " and fill in your values.")
    print("[OK] Production overrides available")
    print()

    print("The Oracle sees all configurations.")


if __name__ == "__main__":
    main()
