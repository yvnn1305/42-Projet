from pydantic import BaseModel, Field, ValidationError, model_validator
from datetime import datetime
from typing import Annotated, Optional
from enum import Enum

class ContactType(Enum):
    RADIO = "radio"
    VISUAL = "visual"
    PHYSICAL = "physical"
    TELEPATHIC = "telepathic"

class AlienContact(BaseModel):
    contact_id: Annotated[str, Field(min_length=5, max_length=15)]
    timestamp: datetime
    location: Annotated[str, Field(min_length=3, max_length=100)]
    contact_type: ContactType
    signal_strength: Annotated[float, Field(ge=0.0, le=10.0)]
    duration_minutes: Annotated[int, Field(ge=1, le=1440)]
    witness_count: Annotated[int, Field(ge=1, le=100)]
    message_received: Annotated[Optional[str], Field(max_length=500)] = None
    is_verified: bool = False

    @model_validator(mode="after")
    def check(self) -> "AlienContact":
        if not self.contact_id.startswith("AC"):
            raise ValueError("Contact ID must start with 'AC'")

        if self.contact_type == ContactType.PHYSICAL and not self.is_verified:
            raise ValueError("Physical contact needs to be verified")

        if self.contact_type == ContactType.TELEPATHIC and self.witness_count < 3:
            raise ValueError("Telepathic contact requires at least 3 witnesses")

        if self.signal_strength > 7.0 and self.message_received is None:
            raise ValueError("A message is required when the signal is above 7.0")

        return self

def main() -> None:
    print("Alien Contact Log Validation")
    print("======================================")
    print("Valid contact report:")

    contact = AlienContact(
        contact_id="AC_2024_001",
        timestamp=datetime(2026, 3, 15, 14, 30, 0),
        location="Area 51, Nevada",
        contact_type= ContactType.RADIO,
        signal_strength=8.5,
        duration_minutes=45,
        witness_count=5,
        message_received="Greetings from Zeta Reticuli",
    )

    print(f"ID: {contact.contact_id}")
    print(f"Type: {contact.contact_type.value}")
    print(f"Location: {contact.location}")
    print(f"Signal: {contact.signal_strength}/10")
    print(f"Duration: {contact.duration_minutes} minutes")
    print(f"Witnesses: {contact.witness_count}")
    print(f"Message: {contact.message_received}")
    print()

    print("======================================")
    print("Expected validation error:")

    try:
        contact = AlienContact(
            contact_id="AC_2024_001",
            timestamp=datetime(2026, 3, 15, 14, 30, 0),
            location="Area 51, Nevada",
            contact_type=ContactType.TELEPATHIC,
            signal_strength=8.5,
            duration_minutes=45,
            witness_count=2,
            message_received="Greetings from Zeta Reticuli",
        )
    except ValidationError as e:
        error = e.errors()[0]['msg'].removeprefix("Value error, ")
        print(f"{error}")

if __name__ == "__main__":
    main()
