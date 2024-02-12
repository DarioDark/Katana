#include <iostream>
#include "Player.h"
#include "../Character/Character.h"

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
    return this->character.get_name();
}

// Setters
void Player::set_character(Character character)
{
    this->character = character;
    this->HP = character.getHP();
    CharacterName name = character.get_name();
    switch(name) {
        case CharacterName::BENKEI:
            this->additional_difficulty += 1;
        case CharacterName::GINCHIYO:
            this->damage_mitigation += 1;
        case CharacterName::GOEMON:
            this->additional_weapon += 1;
        case CharacterName::HIDEYOSHI:
            this->additional_draw += 1;
        case CharacterName::MUSASHI:
            this->additional_damage += 1;
    }
}

// Methods
void Player::draw(Deck deck, int nbr_of_draw = -1)
{
    std::vector<Card> deckCards = deck.cards;
    if (nbr_of_draw == -1) { // Si aucune valeur n'est spécifiée -> c'est une pioche classique de début de tour
        
        for (int i = 0; i < additional_draw + 1; i++) {
            if (deckCards.size() == 0) {
                std::cout << "Deck is empty" << std::endl;
            }
            else {
                this->hand.push_back(deckCards.back());
                deckCards.pop_back();
            }
        }
    } else { // Si une valeur est spécifiée -> c'est une pioche avec une carte action, donc un montant spécifique
        for (int i = 0; i < nbr_of_draw; i++) {
            this->hand.push_back(deckCards.back());
            deckCards.pop_back();   
        }
    } 
}

Card Player::discard(Card card) {
    auto iterator = std::find(this->hand.begin(), this->hand.end(), card);

    if (iterator != this->hand.end()) {
        int index = std::distance(this->hand.begin(), iterator);
        Card discarded_card = *iterator;
        this->hand.erase(iterator);
        return discarded_card;
    }
}

void Player::play_permanent_card(PermanentCard card)
{
    CardName name = card.get_name();
    switch(name) {
        case CardName::ARMURE:
            this->additional_difficulty += 1;
        case CardName::CONCENTRATION:
            this->additional_weapon += 1;
        case CardName::ATTAQUE_RAPIDE:
            this->additional_damage += 1;
    }
}

void Player::attack(Player &target, Card card)
{
    // TODO
}

void Player::displayInfos()
{
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Role: " << this->role << std::endl;
    std::cout << "HP: " << this->HP << std::endl;
    std::cout << "Honor Points: " << this->HonorPoints << std::endl;
    std::cout << "Hand: " << std::endl;
    for (Card card : this->hand)
    {
        std::cout << card.print_name() << std::endl;
    }
    std::cout << "Additional difficulty: " << this->additional_difficulty << std::endl;
    std::cout << "Additional weapon: " << this->additional_weapon << std::endl;
    std::cout << "Damage mitigation: " << this->damage_mitigation << std::endl;
    std::cout << "Additional draw: " << this->additional_draw << std::endl;
    std::cout << "Additional damage: " << this->additional_damage << std::endl;
    std::cout << "Character: " << this->character.print_name() << std::endl;
}