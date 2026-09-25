from typing import Any

def artifact_sorter(artifacts: list[dict[str, Any]]) -> list[dict[str, Any]]:
    sort = sorted(artifacts, key=lambda x: x['power'], reverse=True)
    return sort


def power_filter(mages: list[dict[str, Any]], min_power: int) -> list[dict[str, Any]]:
    filt = filter(lambda x: x['power'] > min_power or
                  x['power'] == min_power, mages)
    return list(filt)


def spell_transformer(spells: list[str]) -> list[str]:
    mapped = map(lambda x: f"* {x} *", spells)
    return list(mapped)


def mage_stats(mags: list[dict[str, Any]]) -> dict[str, Any]:
    power_lst = list(map(lambda x: x['power'], mags))
    avg = round((sum(power_lst) / len(power_lst)), 2)
    mini = min(mags, key=lambda x: x['power'])['power']
    maxi = max(mags, key=lambda x: x['power'])['power']
    return {'max_power': maxi, 'min_power': mini, 'avg_power': avg}


if __name__ == "__main__":
    dic = [
        {'name': 'Yann', 'power': 5, 'type': 'Humain'},
        {'name': 'Yasser', 'power': 2, 'type': 'Humain'},
        {'name': 'Remy', 'power': 7, 'type': 'Humain'},
        {'name': 'Florian', 'power': 11, 'type': 'Humain'},
    ]

    spells = ["fireball", "heal", "shield", "frostbolt", "lightning"]

    print("Testing artifact_sorter...")
    atifact = artifact_sorter(dic)
    print(f"{atifact[0]['name']} ({atifact[0]['power']} power) comes before"
          f" {atifact[1]['name']} ({atifact[1]['power']} power)")
    print()
    power = power_filter(dic, 3)
    filt = [f"{mage['name']} ({mage['power']})" for mage in power]
    ligne = ", ".join(filt)
    print("Testing power filter...")
    print(f"Mages with power >= 3: {ligne}")
    print()
    spell = spell_transformer(spells)
    corr = " ".join(spell)
    print("Testing spell_transformer...")
    print(f"{corr}")
    print()
    print("Testing mage_stats...")
    print(f"{mage_stats(dic)}")
