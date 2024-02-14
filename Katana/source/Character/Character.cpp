#include "Character.h"

Character::Character() :
    Card("Default Character Card"),  // Vous pouvez définir un nom par défaut si nécessaire
    HealthPoints(100) {  // Valeur par défaut pour les points de vie
    // Initialisez les autres membres de la classe avec des valeurs par défaut si nécessaire
}


Character::Character(
    std::string cardName,
    int healthPoints,
    int additionalWeaponDiffiulty,
    bool onlyAffectedByWeapon,
    int damageMitigation,
    bool additionalWeaponCard,
    bool weaponCardParry,
    int cardDrawNumber,
    bool drawDiscardDeck,
    bool attackAnyCharacter,
    int additionalWeaponDamage,
    bool healthPointSacrificeDraw,
    bool damageOtherPlayerDraw,
    bool healthDropDraw) :
    Card(cardName),
    HealthPoints(healthPoints),
    additionalWeaponDiffiulty(additionalWeaponDiffiulty),
    onlyAffectedByWeapon(onlyAffectedByWeapon),
    damageMitigation(damageMitigation),
    additionalWeaponCard(additionalWeaponCard),
    weaponCardParry(weaponCardParry),
    cardDrawNumber(cardDrawNumber),
    drawDiscardDeck(drawDiscardDeck),
    attackAnyCharacter(attackAnyCharacter),
    additionalWeaponDamage(additionalWeaponDamage),
    healthPointSacrificeDraw(healthPointSacrificeDraw),
    damageOtherPlayerDraw(damageOtherPlayerDraw),
    healthDropDraw(healthDropDraw) {};


