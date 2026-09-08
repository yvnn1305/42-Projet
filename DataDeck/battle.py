from ex0 import AquaFactory, CreatureFactory, FlameFactory

def test_factory(factory: CreatureFactory) -> None:
    base = factory.create_base()
    print(base.describe())
    print(base.attack())
    evolved = factory.create_evolved()
    print(evolved.describe())
    print(evolved.attack())

def battle(factory0: CreatureFactory, factory1: CreatureFactory) -> None:
    fighter0 = factory0.create_base()
    fighter1 = factory1.create_base()
    print(fighter0.describe())
    print("vs.")
    print(fighter1.describe())
    print("fight!")
    print(fighter0.attack())
    print(fighter1.attack())

print("Testing factory")
test_factory(FlameFactory())
print()

print("Testing factory")
test_factory(AquaFactory())
print()

print("Testing battle")
battle(FlameFactory(), AquaFactory())