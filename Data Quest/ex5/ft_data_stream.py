import random
import typing

PLAYERS = [
    "alice",
    "bob",
    "charlie",
    "dylan",
]

ACTIONS = [
    "run",
    "sleep",
    "eat",
    "move",
    "swim",
    "release",
    "grab",
    "climb",
    "use",
]

Event = tuple[str, str]


def gen_event() -> typing.Generator[Event, None, None]:
    while True:
        yield random.choice(PLAYERS), random.choice(ACTIONS)


def consume_event(event: list[Event]) -> typing.Generator[Event, None, None]:
    while event:
        picked = random.randrange(len(event))
        rand = event.pop(picked)
        yield rand


if __name__ == "__main__":
    print("=== Game Data Stream Processor ===")
    gen = gen_event()
    for i in range(1000):
        event = next(gen)
        name, action = event
        print(f"Event {i}: Player {name} did action {action}")
    lst = []
    print("Built list of 10 events: ", end="")
    for i in range(10):
        event = next(gen)
        lst.append(event)
    print(lst)
    for event in consume_event(lst):
        print(f"Got event from list: {event}")
        print(f"Remains in list: {lst}")
