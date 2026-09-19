from pydantic import BaseModel, Field, ValidationError
from datetime import datetime
from typing import Annotated, Optional


class SpaceStation(BaseModel):

    station_id: Annotated[str, Field(min_length=3, max_length=10)]
    name: Annotated[str, Field(min_length=1, max_length=50)]
    crew_size: Annotated[int, Field(ge=1, le=20)]
    power_level: Annotated[float, Field(ge=0.0, le=100.0)]
    oxygen_level: Annotated[float, Field(ge=0.0, le=100.0)]
    last_maintenance: datetime
    is_operational: bool = True
    notes: Annotated[Optional[str], Field(max_length=200)] = None


def main() -> None:
    print("Space Station Data Validation")
    print("========================================")
    print("Valid station created:")

    station = SpaceStation(
        station_id="ISS001",
        name="Internation Space Station",
        crew_size=6,
        power_level=85.5,
        oxygen_level=92.3,
        last_maintenance=datetime(2026, 3, 15, 14, 30, 0),
        is_operational=True,
    )

    print(f"ID: {station.station_id}")
    print(f"Name: {station.name}")
    print(f"Crew: {station.crew_size} people")
    print(f"Power: {station.power_level}%")
    print(f"Oxygen: {station.oxygen_level}%")
    if station.is_operational:
        print("Status: Operational")
    else:
        print("Not Operational")
    print()

    print("========================================")
    print("Expected validation error:")

    try:
        station = SpaceStation(
            station_id="ISS001",
            name="Internation Space Station",
            crew_size=32,
            power_level=85.5,
            oxygen_level=92.3,
            last_maintenance=datetime(2026, 3, 15, 14, 30, 0),
            is_operational=True,
        )
    except ValidationError as e:
        print(f"{e.errors()[0]['msg']}")


if __name__ == "__main__":
    main()
