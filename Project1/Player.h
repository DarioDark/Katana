#include <string>
#include <vector>

#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"
#include "Character.h"

class Player
{
private:
    // Basics attributes
    int HP;
    int HonorPoints;
    std::string name;
    std::string role;
    std::vector<Card> hand;
    std::vector<Card> permanent_card_played;

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
    std::string get_name() const;
    std::string get_role() const;
    std::vector<Card> get_hand();

    int get_additional_difficulty(); // Benkei
    int get_damage_mitigation(); // Ginchyo
    int get_additional_weapon(); // Goemon
    int get_additional_draw(); // Hideyoshi
    int get_additional_damage(); // Musashi
    CharacterName get_character();
    std::string print_character();

    // Setters
    void set_role(std::string role);
    void set_character(Character character);

    // Constructor
    Player(std::string name);

    // Methods
    void draw(Deck& deck, int nbr_of_draw = -1);
    Card discard(int cardIndex, std::string list_of_cards = "hand");

    //void play_action_card(ActionCard card);
    void play_permanent_card(int cardIndex);
    void discard_permanent_card(int cardIndex);
    void attack(Player& target, Card card);

    void recover_HP_phase();
    void draw_phase(Deck& deck);
    int play_card_phase();
    std::vector<Card> discard_phase();
    std::vector<Card> play_turn(Deck& deck);

    void get_Jujitsued();

    void print_hand();
    void displayInfos();
    void game_phase();
};

#endif