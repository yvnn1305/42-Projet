from pydantic import BaseModel, Field, model_validator, ValidationError
from datetime import datetime
from typing import Annotated
from enum import Enum


class Rank(Enum):
    CADET = "cadet"
    OFFICER = "officer"
    LIEUTENANT = "lieutenant"
    CAPTAIN = "captain"
    COMMANDER = "commander"


class CrewMember(BaseModel):
    member_id: Annotated[str, Field(min_length=3, max_length=10)]
    name: Annotated[str, Field(min_length=2, max_length=50)]
    rank: Rank
    age: Annotated[int, Field(ge=18, le=80)]
    specialization: Annotated[str, Field(min_length=3, max_length=30)]
    years_experience: Annotated[int, Field(ge=0, le=50)]
    is_active: bool = True


class SpaceMission(BaseModel):
    mission_id: Annotated[str, Field(min_length=5, max_length=15)]
    mission_name: Annotated[str, Field(min_length=3, max_length=100)]
    destination: Annotated[str, Field(min_length=3, max_length=50)]
    launch_date: datetime
    duration_days: Annotated[int, Field(ge=1, le=3650)]
    crew: Annotated[list[CrewMember], Field(min_length=1, max_length=12)]
    mission_status: str = "planned"
    budget_millions: Annotated[float, Field(ge=1.0, le=10000.0)]

    @model_validator(mode="after")
    def check(self) -> "SpaceMission":
        if not self.mission_id.startswith("M"):
            raise ValueError("Mission ID must start with 'M'")

        is_here: bool = False
        for member in self.crew:
            if member.rank == Rank.COMMANDER or member.rank == Rank.CAPTAIN:
                is_here = True
        if not is_here:
            raise ValueError("Mission must have at least one"
                             " Commander or Captain")

        if self.duration_days > 365:
            p: int = 0
            for member in self.crew:
                if member.years_experience >= 5:
                    p += 1
            per = (p / len(self.crew)) * 100
            if per < 50:
                raise ValueError("At least 50% of the crew needs to "
                                 "have 5+ years experiences for mission"
                                 " longer than 365 days.")

        for member in self.crew:
            if not member.is_active:
                raise ValueError("All the crew members must be active.")

        return self


def main() -> None:
    print("Space Mission Crew Validation")
    print("======================================")
    print("Valid mission created:")

    member0 = CrewMember(
        member_id="SC01",
        name="Sarah Connor",
        rank=Rank.COMMANDER,
        age=24,
        specialization="Mission Command",
        years_experience=6,
        is_active=True,
    )

    member1 = CrewMember(
        member_id="JS02",
        name="John Smith",
        rank=Rank.LIEUTENANT,
        age=36,
        specialization="Navigation",
        years_experience=10,
        is_active=True,
    )

    member2 = CrewMember(
        member_id="AJ03",
        name="Alice Johnson",
        rank=Rank.OFFICER,
        age=29,
        specialization="Engineering",
        years_experience=3,
        is_active=True,
    )

    mission0 = SpaceMission(
        mission_id="M2024_MARS",
        mission_name="Mars Colony Establishment",
        destination="Mars",
        launch_date=datetime.now(),
        duration_days=900,
        crew=[member0, member1, member2],
        budget_millions=2500.0,
    )

    crew_size = len(mission0.crew)

    print(f"Mission: {mission0.mission_name}")
    print(f"ID: {mission0.mission_id}")
    print(f"Destination: {mission0.destination}")
    print(f"Duration: {mission0.duration_days}")
    print(f"Budget: ${mission0.budget_millions}M")
    print(f"Crew size: {crew_size}")
    print("Crew members")
    for member in mission0.crew:
        print(f"- {member.name} ({member.rank.value})"
              f" - {member.specialization}")
    print()

    print("======================================")
    print("Expected validaion error:")

    try:
        SpaceMission(
            mission_id="M2024_MARS",
            mission_name="Mars Colony Establishment",
            destination="Mars",
            launch_date=datetime.now(),
            duration_days=900,
            crew=[member1, member2],
            budget_millions=2500.0,
        )
    except ValidationError as e:
        error = e.errors()[0]['msg'].removeprefix("Value error, ")
        print(f"{error}")


if __name__ == "__main__":
    main()
