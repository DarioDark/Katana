#include <string>
#include <vector>

#ifndef CARD_H
#define CARD_H

enum class CardType {
    ACTION,
    PERMANENT,
    WEAPON,
    PROGRAMM
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
    WAKIZASHI,

    // Programm
    ENDTURN
};

class Card {
protected:
    CardName name;
    CardType type;
public:
    bool operator==(const Card& other) const {
        // Compare the cards based on their properties
        return name == other.name && type == other.type;
    }
    Card(CardName name, CardType type);
    CardName get_name() const;
    std::string print_name();
    CardType get_type();
    std::string print_type();
};

class ActionCard : public Card {
public:
    CardType type;
    ActionCard(CardName name);
};

class PermanentCard : public Card {
public:
    CardType type;
    PermanentCard(CardName name);
};

class WeaponCard : public Card {
public:
    int difficulty;
    int damage;
    CardType type;

    WeaponCard(CardName name, int difficulty, int damage);
};

extern std::vector<ActionCard> actionCardsVector;

extern std::vector<PermanentCard> permanentCardsVector;

extern std::vector<WeaponCard> weaponCardsVector;


#endif