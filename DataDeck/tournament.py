from ex0 import CreatureFactory, AquaFactory, FlameFactory
from ex1 import CreatureFactory, HealingCreatureFactory, TransformCreatureFactory
from ex2 import AgressiveStrategy, BattleStrategy, DefensiveStrategy, NormalStrategy, InvalidStrategyError

def tournament(opps: list[tuple[CreatureFactory, BattleStrategy]]) -> None:
    print("*** Tournament ***")
    print(f"{len(opps)} opponents involved")
    print()

    for i in range(len(opps)):
        for j in range(i + 1, len(opps)):
            print("* Battle *")
            factory_i, strategy_i = opps[i]
            factory_j, strategy_j = opps[j]

            opp_i = factory_i.create_base()
            opp_j = factory_j.create_base()

            print(opp_i.describe())
            print("vs.")
            print(opp_j.describe())
            print("now fight!")
            try:
                strategy_i.act(opp_i)
                strategy_j.act(opp_j)
            except InvalidStrategyError as e:
                print(f"Battle error, aborting tournament: {e}")
            print()


if __name__ == "__main__":
    tournament0 = [(FlameFactory(), NormalStrategy()), (HealingCreatureFactory(), DefensiveStrategy())]
    tournament1 = [(FlameFactory(), AgressiveStrategy()), (HealingCreatureFactory(), DefensiveStrategy())]
    tournament2 = [(AquaFactory(), NormalStrategy()), (HealingCreatureFactory(),
                    DefensiveStrategy()), (TransformCreatureFactory(), AgressiveStrategy())]

    print("Tournament 0 (basic)")
    print("[ (Flameling+Normal), (Healing+Defensive) ]")
    tournament(tournament0)
    print()
    print("Tournament 1 (error)")
    print("[ (Flameling+Aggressive), (Healing+Defensive) ]")
    tournament(tournament1)
    print()
    print("Tournament 2 (multiple)")
    print("[ (Aquabub+Normal), (Healing+Defensive), (Transform+Aggressive) ]")
    tournament(tournament2)
