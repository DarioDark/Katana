#include <iostream>
#include <string>
#include <vector>

#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Card.h"
#include "Character.h"
#include "Deck.h"

class Game
{
private:
    std::vector<Player> players;
    Deck deck = Deck();
    Deck discard_pile = Deck();

public:
    // Constructor
    Game();

    // Methods
    void start_game();

    // Start methods (set up game)
    int getNbrPlayers();
    std::vector<std::string> createRoles();
    std::vector<Player> createPlayers();
    void move_shogun_to_first();
    void attributeRoles();
    void distribute_characters();
    void draw_starting_hand();
    void display_players_infos();

    void clear_console();
    void draw_card(Player& player);
    void draw_card_discard_pile(Player& player);
    void discard(Player& player, int cardIndex);
    void play_card(Player& player, int carxIndex);
    void attack(Player& player, Player& target, Card card);
    void player_play_turn(Player& player);
    void shuffle_deck();
    void print();


    void end_game();

};

#endif