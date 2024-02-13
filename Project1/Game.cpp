#include <random>
#include <algorithm>
#include <iostream>

#include "Game.h"

// Constructor
Game::Game() {
    start_game();
};

// Methods
void Game::start_game()
{
    createPlayers(); // Create players
    attributeRoles(); // Create and attribute roles to players
    distribute_characters(); // Distribute characters to players
    display_players_infos(); // Display players infos

    // Init deck and shuffle it
    deck.init();

    // Draw starting hand
    draw_starting_hand();
    //display_players_infos();
    for (Player player : players) {
		player_play_turn(player);
        system("cls");
	}

}

int Game::getNbrPlayers() {
    int nbrPlayers;

    do {
        std::cout << "Combien y a-t-il de joueurs ? ";
        std::cin >> nbrPlayers;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Veuillez entrer un nombre entier entre 4 et 7." << std::endl;
        }
        else if (nbrPlayers < 4 || nbrPlayers > 7) {
            std::cout << "Veuillez entrer un nombre entier entre 4 et 7." << std::endl;
        }
        else {
            std::cout << "Bien, nous jouerons donc à " << nbrPlayers << " joueurs !" << std::endl;
            // Effacer l'écran
            system("cls");
            return nbrPlayers;
        }

    } while (true);

    return nbrPlayers;
}

std::vector<std::string> Game::createRoles() {
    int nbrPlayers = this->players.size();
    std::vector<std::string> roles = { "Shogun", "Samourai", "Ninja", "Ninja" };

    // Pour chaque joueur en plus, on ajoute un rôle
    if (nbrPlayers >= 5) {
        roles.push_back("Ronin");
    }
    if (nbrPlayers >= 6) {
        roles.push_back("Ninja");
    }
    if (nbrPlayers >= 7) {
        roles.push_back("Samourai");
    }

    // Initialisation du générateur de nombres aléatoires avec une graine
    std::random_device rd;
    std::mt19937 generator(rd());

    // Mélange des rôles
    std::shuffle(roles.begin(), roles.end(), generator);

    // Affichage du vecteur mélangé
    std::cout << "Cartes mélangées : ";
    for (const auto& role : roles) {
        std::cout << role << " ";
    }
    std::cout << std::endl;
    // Effacer l'écran
    system("cls");

    // Retourne le vecteur mélangé des rôles
    return roles;
}

std::vector<Player> Game::createPlayers() {
    int nbrPlayers = getNbrPlayers();
    std::string name;

    for (int i = 0; i < nbrPlayers; i++) {
        std::cout << "Joueur " << i + 1 << ", quel est votre nom ? ";
        std::cin >> name;

        Player player(name);
        players.push_back(player);
    }
    return players;
}

void Game::move_shogun_to_first() {
    while (!players.empty() && players[0].get_role() != "Shogun") {
        // Déplacer le joueur à l'index 0 à la fin du vecteur
        std::rotate(players.begin(), players.begin() + 1, players.end());
    }
}

void Game::attributeRoles() {
    std::vector<std::string> roles = createRoles();
    // Vérifier que les deux vecteurs ont la même taille
    if (roles.size() == players.size()) {
        // Attribution des rôles aux joueurs
        for (size_t i = 0; i < players.size(); ++i) {
            players[i].set_role(roles[i]);
        }
    }
    else {
        std::cout << "Les vecteurs n'ont pas la même taille." << std::endl;
    }
    move_shogun_to_first();
}

void Game::distribute_characters() {
    // Initialisation du générateur de nombres aléatoires avec une graine
    std::random_device rd;
    std::mt19937 generator(rd());

    // Mélange des personnages
    std::shuffle(characterVector.begin(), characterVector.end(), generator);

    // On attribue personnages aux joueurs
    for (size_t i = 0; i < players.size(); ++i) {
        players[i].set_character(characterVector[i]);
    }
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
        }
        else {
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
        }
        // Draw the cards
        player.draw(deck, nbr_of_draw);
    }
}

void Game::display_players_infos() {
    for (Card card : deck.cards) {
        std::cout << card.print_name() << std::endl;
    }
    for (Player player : players) {
        std::cout << "Affichage des infos" << std::endl;
        std::cout << "Joueur : " << player.get_name() << ", Rôle : " << player.get_role() << ", Personnage : " << player.print_character() << std::endl;
        player.print_hand();
    }
}



void Game::clear_console()
{
	// Effacer l'écran
    std::cout << "Press enter to continue...";
    std::cin.get();
    system("cls");
}

void Game::draw_card(Player& player)
{
    player.draw(deck);
}

void Game::draw_card_discard_pile(Player& player)
{
    player.draw(discard_pile);
}

void Game::discard(Player& player, int cardIndex)
{
    Card discarded_card = player.discard(cardIndex);
    this->discard_pile.cards.push_back(discarded_card);
}

void Game::play_card(Player& player, int cardIndex) {
    CharacterName character_of_player = player.get_character();
    Card card = player.get_hand()[cardIndex];
    std::vector<Player> other_players;
    // On créer un vecteur avec tous les joueurs sauf le joueur actuel
    for (Player player : this->players) {
        if (player.get_character() != character_of_player) {
            other_players.push_back(player);
        }
    }
    switch (card.get_name()) {
    case CardName::CEREMONIE_DU_THE:
        // TODO
        break;
    case CardName::CRI_DE_GUERRE:
        // TODO
        break;
    case CardName::DAIMYO:
        // TODO
        break;
    case CardName::DIVERSION:
        // TODO
        break;
    case CardName::GEISHA:
        // TODO
        break;
    case CardName::MEDITATION:
        // TODO
        break;
    case CardName::JUJITSU:
        for (Player player : other_players) {
            std::cout << "Joueur " << player.get_name();
            player.get_Jujitsued();
        }
        break;
    case CardName::PARADE:
        // TODO
        break;
    default:
        std::cout << "Carte non reconnue" << std::endl;
        break;
    }
    discard(player, cardIndex);
}

void Game::attack(Player& player, Player& target, Card card) {
    // TODO
}

void Game::player_play_turn(Player& player) {
    player.recover_HP_phase();
    player.draw_phase(this->deck);

    // Play card phase
    int cardIndex = player.play_card_phase();
    if (cardIndex == -1) { // Si le joueur ne joue pas de carte
		std::cout << "Le joueur " << player.get_name() << " a arrêté son tour." << std::endl;
	}
    while (cardIndex != -1) { // Tant que le joueur joue des cartes
        int cardIndex = player.play_card_phase();
        play_card(player, cardIndex);
	}

    // Discard phase
    std::vector<Card> discarded_cards = player.discard_phase();
    this->discard_pile.cards.insert(discard_pile.cards.end(), discarded_cards.begin(), discarded_cards.end()); // On met d'un coup toutes les cartes défaussées dans la pile de défausse
    std::cout << "Pile de défausse : ";
    for (Card card : this->discard_pile.cards) {
        std::cout << card.print_name() << std::endl;
    }
}

void Game::shuffle_deck()
{
    this->deck.shuffle();
}

void Game::print() {
    // TODO
}

void Game::end_game()
{
    // TODO
}