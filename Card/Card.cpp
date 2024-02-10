#include <iostream>
#include <string>

#include "Card.h"

// Constructor
Card::Card(CardName name) : name(name) {}

// Getter
CardName Card::get_name()
{
    return name;
}

std::string Card::print_name() {
    switch (name) {
        case CardName::CEREMONIE_DU_THE:
            return "Ceremonie du The";
        case CardName::CRI_DE_GUERRE:
            return "Cri de Guerre";
        case CardName::DAIMYO:
            return "Daimyo";
        case CardName::DIVERSION:
            return "Diversion";
        case CardName::GEISHA:
            return "Geisha";
        case CardName::MEDITATION:
            return "Meditation";
        case CardName::JUJITSU:
            return "Jujitsu";
        case CardName::PARADE:
            return "Parade";
        case CardName::ATTAQUE_RAPIDE:
            return "Attaque Rapide";
        case CardName::CONCENTRATION:
            return "Concentration";
        case CardName::CODE_DU_BUSHIDO:
            return "Code du Bushido";
        case CardName::ARMURE:
            return "Armure";
        case CardName::NODACHI:
            return "Nodachi";
        case CardName::NAGINATA:
            return "Naginata";
        case CardName::NAGAYARI:
            return "Nagayari";
        case CardName::TANEGASHIMA:
            return "Tanegashima";
        case CardName::DAIKYU:
            return "Daikyu";
        case CardName::BO:
            return "Bo";
        case CardName::KUSARIGAMA:
            return "Kusarigama";
        case CardName::KATANA:
            return "Katana";
        case CardName::SHURIKEN:
            return "Shuriken";
        case CardName::KANABO:
            return "Kanabo";
        case CardName::BOKKEN:
            return "Bokken";
        case CardName::KISERU:
            return "Kiseru";
        case CardName::WAKIZASHI:
            return "Wakizashi";
    }
    return "Unknown";
}

// Constructors
ActionCard::ActionCard(CardName name) : Card(name) {}

PermanentCard::PermanentCard(CardName name) : Card(name) {}

WeaponCard::WeaponCard(CardName name, int difficulty, int damage) : Card(name), difficulty(difficulty), damage(damage) {}

// Getters
int WeaponCard::get_difficulty()
{
    return difficulty;
}

int WeaponCard::get_damage()
{
    return damage;
}