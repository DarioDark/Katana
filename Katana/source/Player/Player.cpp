#include <iostream>

#include "Player.h"
#include "../Character/Character.h"

Player::Player(const std::string& Playername) :
    name(Playername), HealthPoints(0) {};


void Player::setCharacter(const Character& character) 
{
    this->character = character;
    HealthPoints = character.getHealthPoints();
    additionalWeaponDiffiulty = character.getAdditionalWeaponDiffiulty();
    onlyAffectedByWeapon = character.getOnlyAffectedByWeapon();
    damageMitigation= character.getDamageMitigation();
    additionalWeaponCard = character.getAdditionalWeaponCard();
    weaponCardParry = character.getWeaponCardParry();
    cardDrawNumber = character.getCardDrawNumber();
    drawDiscardDeck = character.getDrawDiscardDeck();
    attackAnyCharacter = character.getAttackAnyCharacter();
    additionalWeaponDamage = character.getAdditionalWeaponDamage();
    healthPointSacrificeDraw = character.getHealthPointSacrificeDraw();
    damageOtherPlayerDraw = character.getDamageOtherPlayerDraw();
    healthDropDraw = character.getHealthDropDraw();

}

// Implémentation de la méthode pour afficher les informations du joueur
void Player::displayPlayerInfo() const {
std::cout << "Nom du joueur : " << name << std::endl;
std::cout << "Rôle du joueur : " << role << std::endl;
std::cout << "Personnage du joueur : " << character.getName() << std::endl;
std::cout << "Points de vie du joueur : " << HealthPoints << std::endl;
std::cout << "Points d'honneur du joueur : " << HonorPoints << std::endl;
std::cout << "difficulté d'arme supplémentaire : " << additionalWeaponDiffiulty << std::endl;
std::cout << "Seul affecté par l'arme : " << onlyAffectedByWeapon << std::endl;
std::cout << "Mitigation des dégâts : " << damageMitigation << std::endl;
std::cout << "Carte d'arme supplémentaire : " << additionalWeaponCard << std::endl;
std::cout << "Carte de parade d'arme : " << weaponCardParry << std::endl;
std::cout << "Nombre de carte à piocher : " << cardDrawNumber << std::endl;
std::cout << "Piocher dans la défausse : " << drawDiscardDeck << std::endl;
std::cout << "Attaquer n'importe quel personnage : " << attackAnyCharacter << std::endl;
std::cout << "Dégâts supplémentaires de l'arme : " << additionalWeaponDamage << std::endl;
std::cout << "Sacrifice de points de vie pour piocher : " << healthPointSacrificeDraw << std::endl;
std::cout << "Dégâts sur un autre joueur pour piocher : " << damageOtherPlayerDraw << std::endl;
std::cout << "Perte de points de vie pour piocher : " << healthDropDraw << std::endl;

}