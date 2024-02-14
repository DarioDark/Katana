#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

#include "../game/gameStart.h"
#include "../Player/Player.h"


int getNbrPlayers() {
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

std::vector<std::string> createRoles() {
    int nbrPlayers = getNbrPlayers();
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

std::vector<Player> createPlayers() {
    std::vector<Player> players;
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

void attributeRoles(std::vector<Player>& players) {
    std::vector<std::string> roles = createRoles();
    // Vérifier que les deux vecteurs ont la même taille
    if (roles.size() == players.size()) {
        // Attribution des rôles aux joueurs
        for (size_t i = 0; i < players.size(); ++i) {
            players[i].setRole(roles[i]);
        }

        // Afficher les rôles attribués
        for (const auto& player : players) {
            std::cout << "Joueur : " << player.name << ", Rôle : " << player.getRole() << std::endl;
        }
    }
    
    else {
        std::cout << "Les vecteurs n'ont pas la même taille." << std::endl;
    }
    moveShogunToFirst(players);
}

void displayPlayerInfos(std::vector<Player> players) {
    std::vector<Player> playerList = players;
    // Afficher les rôles attribués
    for (const auto& player : playerList) {
        player.displayPlayerInfo();

        // Attendre une pression sur une touche
        std::cout << "Appuyez sur une touche pour continuer...";
        system("pause");

        // Effacer l'écran
        system("cls");
    }
}

void moveShogunToFirst(std::vector<Player>& players) {
    while (!players.empty() && players[0].getRole() != "Shogun") {
        // Déplacer le joueur à l'index 0 à la fin du vecteur
        std::rotate(players.begin(), players.begin() + 1, players.end());
    }
}

void displayPlayerRoles(std::vector<Player>& players) {
	// Afficher les rôles attribués
	for (const auto& player : players) {
		std::cout << "Joueur : " << player.name << ", Rôle : " << player.getRole() << std::endl;
	}
}

void distributeCharacter(std::vector<Player>& players) {
    Character Benkei = Character("Benkei", 5, 1, false, 0, false, false, 0, false, false, 0, false, false, false);
    Character Chiyome = Character("Chiyome", 4, 0, true, 0, false, false, 0, false, false, 0, false, false, false);
    Character Ginchiyo = Character("Ginchiyo", 4, 0, false, 1, false, false, 0, false, false, 0, false, false, false);
    Character Goemon = Character("Goemon", 4, 0, false, 0, true, false, 0, false, false, 0, false, false, false);
    Character Hanzõ = Character("Hanzõ", 4, 0, false, 0, false, true, 0, false, false, 0, false, false, false);
    Character Hideyoshi = Character("Hideyoshi", 4, 0, false, 0, false, false, 1, false, false, 0, false, false, false);
    Character Ieyasu = Character("Ieyasu", 5, 0, false, 0, false, false, 0, true, false, 0, false, false, false);
    Character Kojirõ = Character("Kojirõ", 5, 0, false, 0, false, false, 0, false, true, 0, false, false, false);
    Character Musashi = Character("Musashi", 5, 0, false, 0, false, false, 0, false, false, 1, false, false, false);
    Character Nobunaga = Character("Nobunaga", 5, 0, false, 0, false, false, 0, false, false, 0, true, false, false);
    Character Tomoe = Character("Tomoe", 5, 0, false, 0, false, 0, false, false, false, 0, false, true, false);
    Character Ushiwaka = Character("Ushiwaka", 4, 0, false, 0, false, false, 0, false, false, 0, false, false, true);

    std::vector<Character> characterList = { Benkei, Chiyome, Ginchiyo, Goemon, Hanzõ, Hideyoshi, Ieyasu, Kojirõ, Musashi, Nobunaga, Tomoe, Ushiwaka };

    // Initialisation du générateur de nombres aléatoires avec une graine
    std::random_device rd;
    std::mt19937 generator(rd());

    // Mélange des cartes personnages
    std::shuffle(characterList.begin(), characterList.end(), generator);

	// Distribuer les cartes de personnages
	for (size_t i = 0; i < players.size(); ++i) {
		// Distribuer les cartes de personnages
		players[i].setCharacter(characterList[i]);
	}

	// Afficher les cartes de personnages distribuées
	for (const auto& player : players) {
		std::cout << "Joueur : " << player.name << ", Carte de personnage : " << player.getCharacter() << std::endl;
	}
}

void gameStartMain() {
    std::vector<Player> players = createPlayers();
    attributeRoles(players);
    distributeCharacter(players);
    displayPlayerInfos(players);
    return players;
}