#include <iostream>
#include <string>

#include "../Card/Card.h"
#include "../Character/Character.h"


#ifndef JOUEUR_H
#define JOUEUR_H

class Player
{
public:
    std::string name;
    std::string role; //Shogun, Samurai, Ninja, Ronin
    int HealthPoints;
    int HonorPoints;
    Character character;


    // Character special abilities
    int additionalWeaponDiffiulty = 0; // Benkei -> 1
    bool onlyAffectedByWeapon = false; // Chiyome -> true
    int damageMitigation = 0; // Ginchiyo -> 1
    bool additionalWeaponCard = false; // Goemon -> true
    bool weaponCardParry = false; // Hanzo -> true
    int cardDrawNumber = 2; // Hideyoshi -> 3
    bool drawDiscardDeck = false; // Ieyasu -> true
    bool attackAnyCharacter = false; // Kojiro
    int additionalWeaponDamage = 0; // Musashi -> 1
    bool healthPointSacrificeDraw = false; // Nobunaga -> true
    bool damageOtherPlayerDraw = false; // Tomoe -> true
    bool healthDropDraw = false; // Ushiwaka -> true


    //constructeur
    Player(const std::string& name);

    // Method to get Character
    std::string getCharacter() const {
		return character.getName();
	}

    // Method to set HealthPoints
    void setHealthPoints(int healthPoints) {
        HealthPoints = healthPoints;
    }

    // Method to set HonnorPoints
    void setHonnorPoints(int honorPoints) {
        HonorPoints = honorPoints;
    }

    // Method to set Role
    void setRole(const std::string& role) {
		this->role = role;
	}

    // Method to get Role
    std::string getRole() const {
        return role;
    }

    void setCharacter(const Character& character);

    void displayPlayerInfo() const;
};

#endif