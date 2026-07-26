import random

ACHIEVEMENTS = [
    "Crafting Genius",
    "Strategist",
    "Collector Supreme",
    "Treasure Hunter",
    "Sharp Mind",
    "First Steps",
    "Master Explorer",
    "World Savior",
    "Unstoppable",
    "Survivor",
    "Boss Slayer",
    "Untouchable",
    "Hidden Path Finder",
    "Speed Runner"
]


def gen_player_achievements() -> set[str]:
    count = random.randint(5, 9)
    picked = random.sample(ACHIEVEMENTS, count)
    return set(picked)


if __name__ == "__main__":
    print("=== Achievement Tracker System ===")
    print()

    players = {
        "Alice": gen_player_achievements(),
        "Bob": gen_player_achievements(),
        "Charlie": gen_player_achievements(),
        "Dylan": gen_player_achievements(),
    }

    sets = list(players.values())
    for name, achvs in players.items():
        print(f"Player {name}: {achvs}")
    print()

    print(f"All distinct achievements: {sets[0].union(*players.values())}")
    print()

    print(f"Common achievements: {sets[0].intersection(*players.values())}")
    print()

    alice = players["Alice"]
    bob = players["Bob"]
    charlie = players["Charlie"]
    dylan = players["Dylan"]
    print(f"Only Alice has: {alice.difference(bob, charlie, dylan)}")
    print(f"Only Bob has: {bob.difference(alice, charlie, dylan)}")
    print(f"Only Charlie has: {charlie.difference(alice, bob, dylan)}")
    print(f"Only Dylan has: {dylan.difference(alice, bob, charlie)}")
    print()

    for name, achvs in players.items():
        missing = set(ACHIEVEMENTS) - achvs
        print(f"{name} is missing: {missing}")
