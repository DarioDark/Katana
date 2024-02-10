#include <string>
#include <vector>
#include "../Character/Character.h"
#include "../Card/Card.h"
#include "../Deck/Deck.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player 
{
    private:
        // Basics attributes
        int HP;
        int HonorPoints;
        std::string name;
        std::string role;
        std::vector<Card> hand;

        // Special attributes
        int additional_difficulty; // Benkei et Armure (permanent card)
        int additional_weapon; // Ginchiyo et Concentration (permanent card)
        int damage_mitigation; // Goemon
        int additional_draw; // Hideyoshi
        int additional_damage; // Musashi et Attaque Rapide (permanent card)
        Character character;

    public:
        // Getters
        int get_HP();
        int get_HonorPoints();
        std::string get_name();
        std::string get_role();
        std::vector<Card> get_hand();

        int get_additional_difficulty(); // Benkei
        int get_damage_mitigation(); // Ginchyo
        int get_additional_weapon(); // Goemon
        int get_additional_draw(); // Hideyoshi
        int get_additional_damage(); // Musashi
        CharacterName get_character();

        // Setters
        void set_character(Character character);

        // Constructor
        Player(std::string name);

        // Methods
        void draw(Deck deck, bool mainDeck = true);
        void play_action_card(ActionCard card);
        void play_permanent_card(PermanentCard card);
        void attack(Player &target, Card card);
        void displayInfos();
};

#endif