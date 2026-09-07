def validate_ingredients(ingredients: str) -> str:
    from .light_spellbook import light_spell_allowed_ingredients
    spells = light_spell_allowed_ingredients()
    ingre = ingredients.lower()
    for spell in spells:
        if spell in ingre:
            return f"{ingredients} - VALID"
    return f"{ingredients} - INVALID"