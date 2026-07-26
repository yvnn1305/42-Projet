import random

PLAYERS = [
    "Alice",
    "bob",
    "Charlie",
    "dylan",
    "Emma",
    "Gregory",
    "john",
    "kevin",
    "Liam",
]


if __name__ == "__main__":
    print("=== Game Data Alchemist ===")
    print()

    all_caps = [name.capitalize() for name in PLAYERS]
    only_caps = [name for name in PLAYERS if name == name.capitalize()]
    scores = {name: random.randint(0, 1000) for name in all_caps}
    average = sum(scores.values()) / len(scores)
    highest_score = {
        key: value
        for key, value in scores.items()
        if value > average
    }

    print(f"Initial list of players: {PLAYERS}")
    print(f"New list with all names capitalized: {all_caps}")
    print(f"New list of capitalized names only: {only_caps}")
    print()

    print(f"Score dict: {scores}")
    print(f"Score average is {round(average, 2)}")
    print(f"High scores: {highest_score}")
