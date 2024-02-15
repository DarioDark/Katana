#include <random>
#include <algorithm>
#include <iostream>
#include <vector>

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
    //display_players_infos(); // Display players infos

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
        system("cls");
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
            case 1:
            case 2:
				nbr_of_draw = 5;
				break;
            case 3:
            case 4:
                nbr_of_draw = 6;
                break;
            case 5:
            case 6:
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

void Game::print_players() {
    for (size_t i = 0; i < players.size(); ++i) {
        std::cout << i << "." << players[i].get_name() << " Cartes permanentes jouées : ";
        if (players[i].get_permanent_card_played().empty()) {
            std::cout << "Aucune";
        }
        else {
            for (Card card : players[i].get_permanent_card_played()) {
                std::cout << card.print_name() << " / ";
            }
        }
        std::cout << std::endl;  // Print a newline character after each player
    }
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
    std::cout << "Joueur " << player.get_name() << " a joué la carte " << card.print_type() << " " << card.print_name() << std::endl;
    switch (card.get_type()) {
        case CardType::WEAPON:
        {
            std::cout << "Choisissez une cible : " << std::endl;
            print_players_difficulty(player);
            std::cout << "Votre arme à une précision de " << card.get_difficulty() << std::endl;
            int target = player.select_target(this->players.size());
            while (card.get_difficulty() < player_get_difficulty(player, target)) {
				std::cout << "La précision de l'arme est insuffisante pour toucher la cible." << std::endl;
                print_players_difficulty(player);
				target = player.select_target(this->players.size());
			}
		    attack(player, target, card);
			break;
		}
        case CardType::PERMANENT:
		    player.play_permanent_card(cardIndex);
            return;
        case CardType::ACTION:    
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
                {
                    print_players();
                    rsize_t target = player.select_target(this->players.size());
                    Player playerTarget = this->players[target];
                    int geishaMode = player.select_geihsha_mode(playerTarget);
                    playerTarget.get_geishaed(geishaMode);
                    break;
                }
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
    }
    discard(player, cardIndex);
    return;
}

void Game::attack(Player& player, int& target, Card card) 
{
    this->players[target].get_attacked(player, card);
}

int Game::player_get_difficulty(Player player, int targetIndex) {
    auto indexFinder = std::find(this->players.begin(), this->players.end(), player);
    int playerIndex = std::distance(this->players.begin(), indexFinder);

    // Calculer la distance dans le sens direct
    int distance1 = (targetIndex >= playerIndex) ? targetIndex - playerIndex : targetIndex - playerIndex + players.size();

    // Calculer la distance dans le sens inverse
    int distance2 = (targetIndex >= playerIndex) ? playerIndex - targetIndex + players.size() : playerIndex - targetIndex;

    // On prend la distance la plus courte
    int distance = std::min(distance1, distance2);

    return distance + this->players[targetIndex].get_additional_difficulty();
}


void Game::print_players_difficulty(Player player) {
    auto indexFinder = std::find(this->players.begin(), this->players.end(), player);
    int playerIndex = std::distance(this->players.begin(), indexFinder);
    for (Player target : players) {
        if (player == target) {
			continue;
		}
        auto targetIndexFinder = std::find(this->players.begin(), this->players.end(), target);
        int targetIndex = std::distance(this->players.begin(), targetIndexFinder);

        int difficulty = player_get_difficulty(player, targetIndex);
        if (this->players[targetIndex].get_character() == CharacterName::BENKEI) {
            std::cout << targetIndex << ".Joueur " << target.get_name() << " a une difficulté de " << difficulty << " : Benkei" << std::endl;
		}
		else {
            std::cout << targetIndex << ".Joueur " << target.get_name() << " a une difficulté de " << difficulty << std::endl;
	    }
	}
    return;
} 

void Game::player_play_turn(Player& player) {
    player.recover_HP_phase();
    player.draw_phase(this->deck);

    // Play card phase
    while (true) { // Tant que le joueur joue des cartes
        int cardIndex = player.play_card_phase();
        if (cardIndex < 0) { // Si le joueur ne joue pas de carte
            system("cls");
            std::cout << "Joueur " << player.get_name() << ", vous avez arrêté votre tour." << std::endl;
            break;
        }
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

void Game::end_game()
{
    // TODO
}