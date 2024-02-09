#include <string>

#ifndef CARD_H
#define CARD_H

enum class CardType {
    ACTION,
    PERMANENT,
    WEAPON
};

enum class CardName {
    // Action
    CEREMONIE_DU_THE,
    CRI_DE_GUERRE,
    DAIMYO,
    DIVERSION,
    GEISHA,
    MEDITATION,
    JUJITSU,
    PARADE,

    // Permanent
    ATTAQUE_RAPIDE,
    CONCENTRATION,
    CODE_DU_BUSHIDO,
    ARMURE,

    // Weapon
    NODACHI,
    NAGINATA,
    NAGAYARI,
    TANEGASHIMA,
    DAIKYU,
    BO,
    KUSARIGAMA,
    KATANA,
    SHURIKEN,
    KANABO,
    BOKKEN,
    KISERU,
    WAKIZASHI
};

class Card {
    public:
        CardName name;
};

class ActionCard : public Card {};

class WeaponCard : public Card {
    public:
        int damage;
        int difficulty;
};

#endif