#include <iostream>
#include <string>
#include <vector>
#include "Player/Player.h"
#include "Card/Card.h"
#include "Deck/Deck.h"
#include "Character/Character.h"


#ifndef GAME_H
#define GAME_H

class Game 
{
    private:
        std::vector<Player> players;
        Deck deck;
        Deck discard_pile;

    public:
        // Constructor
        Game(std::vector<Player> players);

        // Methods
        void start_game();
        void end_game();
        void draw_starting_hand();
        void draw_card(Player &player);
        void draw_card_discard_pile(Player &player);
        void discard(Player &player, Card card);
        void play_card(Player &player, Card card);
        void attack(Player &attacker, Player &target, Card card);
        void shuffle_deck(); 
        void print();

};

#endif