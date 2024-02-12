#include "Game.h"

// Constructor
Game::Game(std::vector<Player> players) : players(players) {}

// Methods
void Game::start_game()
{
    // Init deck and shuffle it
    deck.init();

}

void Game::draw_starting_hand()
{
    // Define the number of cards to draw for each player
    for (size_t i = 0; i < players.size(); ++i) {
        Player& player = players[i];
        int nbr_of_draw;
        // Shogun always draw 4 cards
        if (player.get_role() == "Shogun") {
            nbr_of_draw = 4;
        } else {
            // Otherwise the number of cards to draw depends on the number of players
            switch (i) {
                case 4:
                case 5:
                    nbr_of_draw = 6;
                    break;
                case 6:
                case 7:
                    nbr_of_draw = 7;
                    break;
                default:
                    nbr_of_draw = 6;  // Default number of cards to draw (error case)
                    break;
            }
            
            // Draw the cards
            for (int j = 0; j < nbr_of_draw; ++j) {
                player.draw(deck);
            }
        }
    }
}

void Game::end_game()
{
    // TODO
}

void Game::draw_card(Player &player)
{
    player.draw(deck);
}

void Game::shuffle_deck()
{
    this->deck.shuffle();
}