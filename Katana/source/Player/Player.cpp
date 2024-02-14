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

// Impl�mentation de la m�thode pour afficher les informations du joueur
void Player::displayPlayerInfo() const {
std::cout << "Nom du joueur : " << name << std::endl;
std::cout << "R�le du joueur : " << role << std::endl;
std::cout << "Personnage du joueur : " << character.getName() << std::endl;
std::cout << "Points de vie du joueur : " << HealthPoints << std::endl;
std::cout << "Points d'honneur du joueur : " << HonorPoints << std::endl;
std::cout << "difficult� d'arme suppl�mentaire : " << additionalWeaponDiffiulty << std::endl;
std::cout << "Seul affect� par l'arme : " << onlyAffectedByWeapon << std::endl;
std::cout << "Mitigation des d�g�ts : " << damageMitigation << std::endl;
std::cout << "Carte d'arme suppl�mentaire : " << additionalWeaponCard << std::endl;
std::cout << "Carte de parade d'arme : " << weaponCardParry << std::endl;
std::cout << "Nombre de carte � piocher : " << cardDrawNumber << std::endl;
std::cout << "Piocher dans la d�fausse : " << drawDiscardDeck << std::endl;
std::cout << "Attaquer n'importe quel personnage : " << attackAnyCharacter << std::endl;
std::cout << "D�g�ts suppl�mentaires de l'arme : " << additionalWeaponDamage << std::endl;
std::cout << "Sacrifice de points de vie pour piocher : " << healthPointSacrificeDraw << std::endl;
std::cout << "D�g�ts sur un autre joueur pour piocher : " << damageOtherPlayerDraw << std::endl;
std::cout << "Perte de points de vie pour piocher : " << healthDropDraw << std::endl;

}