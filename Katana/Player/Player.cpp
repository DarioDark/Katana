#include <iostream>
#include "Player.h"
#include "../Character/Character.h"

// Getters
int Player::get_HP()
{
    return HP;
}

int Player::get_HonorPoints()
{
    return HonorPoints;
}

std::string Player::get_name()
{
    return name;
}

std::string Player::get_role()
{
    return role;
}

std::vector<Card> Player::get_hand()
{
    return hand;
}

int Player::get_additional_difficulty()
{
    return additional_difficulty;
}

int Player::get_additional_weapon()
{
    return additional_weapon;
}

int Player::get_damage_mitigation()
{
    return damage_mitigation;
}

int Player::get_additional_draw()
{
    return additional_draw;
}

int Player::get_additional_damage()
{
    return additional_damage;
}

CharacterName Player::get_character()
{
    return this->character.getName();
}

// Setters
void Player::set_character(Character character)
{
    this->character = character;
    this->HP = character.getHP();
    CharacterName name = character.getName();
    switch(name) {
        case CharacterName::BENKEI:
            this->additional_difficulty = 1;
        case CharacterName::GINCHIYO:
            this->damage_mitigation = 1;
        case CharacterName::GOEMON:
            this->additional_weapon = 1;
        case CharacterName::HIDEYOSHI:
            this->additional_draw = 1;
        case CharacterName::MUSASHI:
            this->additional_damage = 1;
    }
}

// Constructor
Player::Player(std::string name)
{
    this->name = name;
    this->additional_difficulty = 0;
    this->additional_weapon = 0;
    this->damage_mitigation = 0;
    this->additional_draw = 0;
    this->additional_damage = 0;
}

// Methods
void Player::draw(std::vector<Card> deck)
{
    if (deck.size() == 0)
    {
        std::cout << "Deck is empty" << std::endl;
        return;
    }
    this->hand.push_back(deck.back());
    deck.pop_back();
}
