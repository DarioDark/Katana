#include <string>
#include <vector>

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
    protected:
        CardName name;
    public:
        Card(CardName name) : name(name) {}
        CardName get_name();
        std::string print_name();
};

class ActionCard : public Card {
    public:
        ActionCard(CardName name);
};

class PermanentCard : public Card {
    public:
        PermanentCard(CardName name);
};

class WeaponCard : public Card {
    private:
        int difficulty;
        int damage;
    public:
        WeaponCard(CardName name, int difficulty, int damage) : Card(name), difficulty(difficulty), damage(damage) {}
        int get_difficulty();
        int get_damage();
};

std::vector<ActionCard> actionCardsVector = {
    ActionCard(CardName::CEREMONIE_DU_THE),
    ActionCard(CardName::CRI_DE_GUERRE),
    ActionCard(CardName::DAIMYO),
    ActionCard(CardName::DIVERSION),
    ActionCard(CardName::GEISHA),
    ActionCard(CardName::MEDITATION),
    ActionCard(CardName::JUJITSU),
    ActionCard(CardName::PARADE)
};

std::vector<PermanentCard> permanentCardsVector = {
    PermanentCard(CardName::ATTAQUE_RAPIDE),
    PermanentCard(CardName::CONCENTRATION),
    PermanentCard(CardName::CODE_DU_BUSHIDO),
    PermanentCard(CardName::ARMURE)
};

std::vector<WeaponCard> weaponCardsVector = {
    WeaponCard(CardName::NODACHI, 3, 3),
    WeaponCard(CardName::NAGINATA, 4, 1),
    WeaponCard(CardName::NAGAYARI, 4, 2),
    WeaponCard(CardName::TANEGASHIMA, 5, 1),
    WeaponCard(CardName::DAIKYU, 5, 2),
    WeaponCard(CardName::BO, 2, 1),
    WeaponCard(CardName::KUSARIGAMA, 2, 2),
    WeaponCard(CardName::KATANA, 2, 3),
    WeaponCard(CardName::SHURIKEN, 3, 1),
    WeaponCard(CardName::KANABO, 3, 2),
    WeaponCard(CardName::BOKKEN, 1, 1),
    WeaponCard(CardName::KISERU, 1, 2),
    WeaponCard(CardName::WAKIZASHI, 1, 3)
};

#endif