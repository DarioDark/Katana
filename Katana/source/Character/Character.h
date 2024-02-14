#include <iostream>
#include "../Card/Card.h"

#ifndef CHARACTER_H
#define CHARACTER_H

enum class CharaterName {
	BENKEI,
	CHIYOME,
	GINCHIYO,
	GOEMON,
	HANZO,
	HIDEYOSHI,
	IEYASU,
	KOJIRO,
	MUSASHI,
	NOBUNAGA,
	TOMOE,
	USHIWAKA
};

enum class chacterEffect {
	ADDITIONAL_WEAPON_DIFFICULTY,
	ONLY_AFFECTED_BY_WEAPON,
	DAMAGE_MITIGATION,
	ADDITIONAL_WEAPON_CARD,
	WEAPON_CARD_PARRY,
	CARD_DRAW_NUMBER,
	DRAW_DISCARD_DECK,
	ATTACK_ANY_CHARACTER,
	ADDITIONAL_WEAPON_DAMAGE,
	HEALTH_POINT_SACRIFICE_DRAW,
	DAMAGE_OTHER_PLAYER_DRAW,
	HEALTH_DROP_DRAW
};

class Character : public Card {
public:
    int HealthPoints;

    // Character special abilities
    int additionalWeaponDiffiulty = 0; // Benkei -> 1
    bool onlyAffectedByWeapon = false; // Chiyome -> true
    int damageMitigation = 0; // Ginchiyo -> 1
    bool additionalWeaponCard = false; // Goemon -> true
    bool weaponCardParry = false; // Hanzo -> true
    int cardDrawNumber = 2; // Hideyoshi -> 3
    bool drawDiscardDeck = false; // Ieyasu -> true
    bool attackAnyCharacter = false; // Kojiro
    int additionalWeaponDamage = 0; // Musashi -> 1
    bool healthPointSacrificeDraw = false; // Nobunaga -> true
    bool damageOtherPlayerDraw = false; // Tomoe -> true
    bool healthDropDraw = false; // Ushiwaka -> true

    // Constructeur par défaut
    Character();

    // Constructeur
    Character(
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
        bool healthDropDraw);

    int getHealthPoints() const {
        return HealthPoints;
    }

    int getAdditionalWeaponDiffiulty() const {
        return additionalWeaponDiffiulty;
    }

    bool getOnlyAffectedByWeapon() const {
        return onlyAffectedByWeapon;
    }

    int getDamageMitigation() const {
        return damageMitigation;
    }

    bool getAdditionalWeaponCard() const {
        return additionalWeaponCard;
    }

    bool getWeaponCardParry() const {
        return weaponCardParry;
    }

    int getCardDrawNumber() const {
        return cardDrawNumber;
    }

    bool getDrawDiscardDeck() const {
        return drawDiscardDeck;
    }

    bool getAttackAnyCharacter() const {
        return attackAnyCharacter;
    }

    int getAdditionalWeaponDamage() const {
        return additionalWeaponDamage;
    }

    bool getHealthPointSacrificeDraw() const {
        return healthPointSacrificeDraw;
    }

    bool getDamageOtherPlayerDraw() const {
        return damageOtherPlayerDraw;
    }

    bool getHealthDropDraw() const {
        return healthDropDraw;
    }
};




#endif