import sys


def parse_scores(args: list[str]) -> tuple[list[int], list[str]]:
    valid = []
    invalid = []
    for arg in args:
        try:
            valid.append(int(arg))
        except ValueError:
            invalid.append(arg)
    return valid, invalid


def display(score: list[int]) -> None:
    print(f"Score processed: {score}")
    print(f"Total players: {len(score)}")
    print(f"Total score: {sum(score)}")
    average = sum(score) / len(score)
    print(f"Average score: {average:.1f}")
    print(f"High score: {max(score)}")
    print(f"Low score: {min(score)}")
    print(f"Score range: {max(score) - min(score)}")


if __name__ == "__main__":
    print("=== Player Score Analytics ===")
    valid, invalid = parse_scores(sys.argv[1:])
    for arg in invalid:
        print(f"Invalid parameter: {arg!r}")
    if not valid:
        print("No scores provided. Usage: python3", end="")
        print(" ft_score_analytics.py <score1> <score2> ...")
    else:
        display(valid)
