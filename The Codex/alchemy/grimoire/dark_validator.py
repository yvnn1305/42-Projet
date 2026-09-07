from .dark_spellbook import dark_spell_allowed_ingredients

def validate_ingredients(ingredients: str) -> str:
    spells = dark_spell_allowed_ingredients()
    ingre = ingredients.lower()
    for spell in spells:
        if spell in ingre:
            return f"{ingredients} - VALID"
    return f"{ingredients} - INVALID"