import sys


def parse(args: list[str]) -> dict[str, int]:
    inventory: dict[str, int] = {}
    for arg in args:
        parts = arg.split(":")
        if len(parts) != 2:
            print(f"Error - invalid parameter {arg!r}")
            continue
        name, qty = parts
        if name in inventory:
            print(f"Redundant item {name!r} - discarding")
            continue
        try:
            number = int(qty)
        except ValueError as e:
            print(f"Quantity error for {name!r}: {e}")
            continue
        inventory[name] = number
    return inventory


if __name__ == "__main__":
    print("=== Inventory System Analysis ===")
    inventory = parse(sys.argv[1:])
    total = sum(inventory.values())
    print(f"Got inventory: {inventory}")
    print(f"Item list: {list(inventory.keys())}")
    print(f"Total quantity of the {len(inventory)}"
          f" items: {total}")
    for key, value in inventory.items():
        percent = value / total * 100
        print(f"Item {key} represents {round(percent, 1)}%")
    if not inventory:
        print("No items in the inventory. Usage: python3"
              " ft_inventory_system.py <item:qty> <item:qty> ...")
    else:
        best_name = list(inventory.keys())[0]
        best_qty = list(inventory.values())[0]
        for key, value in inventory.items():
            if value > best_qty:
                best_name = key
                best_qty = value
        print(f"Item most abundant: {best_name} with quantity {best_qty}")
        minus_name = list(inventory.keys())[0]
        minus_qty = list(inventory.values())[0]
        for key, value in inventory.items():
            if value < minus_qty:
                minus_name = key
                minus_qty = value
        print(f"Item least abundant: {minus_name} with quantity {minus_qty}")
    inventory["magic_item"] = 1
    print(f"Updated inventory: {inventory}")
