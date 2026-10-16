from ex1 import CreatureFactory, HealingCreatureFactory, TransformCreatureFactory, HealCapability, TransformCapability

def healing(factory: CreatureFactory) -> None:
    base = factory.create_base()
    print("base:")
    print(base.describe())
    print(base.attack())
    assert isinstance(base, HealCapability)
    print(base.heal())

    evolved = factory.create_evolved()
    print("evolved:")
    print(evolved.describe())
    print(evolved.attack())
    assert isinstance(evolved, HealCapability)
    print(evolved.heal())

def transform(factory: CreatureFactory) -> None:
    base = factory.create_base()
    print("base:")
    print(base.describe())
    print(base.attack())
    assert isinstance(base, TransformCapability)
    print(base.transform())
    print(base.attack())
    print(base.revert())

    evolved = factory.create_evolved()
    print("evolved:")
    print(evolved.describe())
    print(evolved.attack())
    assert isinstance(evolved, TransformCapability)
    print(evolved.transform())
    print(evolved.attack())
    print(evolved.revert())


if __name__ == "__main__":
    print("Testing Creature with healing capability")
    healing(HealingCreatureFactory())
    print()
    print("Testing Creature with transform capability")
    transform(TransformCreatureFactory())