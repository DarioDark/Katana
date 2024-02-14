#include <vector>

#include "Card.h"

// Card constructor
Card::Card(std::string cardName) : name(cardName) {};

// Weapon Card Constructor
WeaponCard::WeaponCard(std::string cardName, int Precision, int Damage) : Card(cardName), precision(Precision), damage(Damage) {};

// Create WeaponCard objects
/*
std::vector<WeaponCard*> weaponCards;

weaponCards.push_back(new WeaponCard("Arc Long", 4, 2));
weaponCards.push_back(new WeaponCard("Arc Court", 3, 1));
weaponCards.push_back(new WeaponCard("Bo", 2, 1));
weaponCards.push_back(new WeaponCard("Chevalet", 3, 2));
weaponCards.push_back(new WeaponCard("Echelle", 2, 1));
weaponCards.push_back(new WeaponCard("Épée", 4, 3));
weaponCards.push_back(new WeaponCard("Étoile de Jet", 3, 2));
weaponCards.push_back(new WeaponCard("Étrier", 3, 1));
weaponCards.push_back(new WeaponCard("Éventail", 2, 1));
weaponCards.push_back(new WeaponCard("Fléau", 2, 2));
weaponCards.push_back(new WeaponCard("Gourdin", 2, 2));
weaponCards.push_back(new WeaponCard("Griffe", 3, 2));
weaponCards.push_back(new WeaponCard("Hallebarde", 4, 3));
weaponCards.push_back(new WeaponCard("Harpon", 4, 2));
weaponCards.push_back(new WeaponCard("Katana", 5, 4));
weaponCards.push_back(new WeaponCard("Kusarigama", 4, 3));
weaponCards.push_back(new WeaponCard("Lance", 4, 3));
weaponCards.push_back(new WeaponCard("Machette", 3, 2));
weaponCards.push_back(new WeaponCard("Masse", 3, 2));
weaponCards.push_back(new WeaponCard("Nunchaku", 4, 3));
weaponCards.push_back(new WeaponCard("Saut de Vent", 3, 1));
weaponCards.push_back(new WeaponCard("Serpent", 2, 1));
weaponCards.push_back(new WeaponCard("Shuriken", 3, 2));
weaponCards.push_back(new WeaponCard("Torche", 2, 1));
weaponCards.push_back(new WeaponCard("Tonfa", 3, 2));
weaponCards.push_back(new WeaponCard("Tsuba", 2, 1));
weaponCards.push_back(new WeaponCard("Uchigatana", 5, 4));
weaponCards.push_back(new WeaponCard("Wakizashi", 4, 3));
weaponCards.push_back(new WeaponCard("Boomerang", 3, 2));
weaponCards.push_back(new WeaponCard("Corde", 2, 1));
weaponCards.push_back(new WeaponCard("Dague", 4, 2));
weaponCards.push_back(new WeaponCard("Echasse", 3, 1));
*/

Action::Action(ActionType actionType)
    : Card(CardType::ACTION), actionType(actionType){
}

ActionType Action::getActionType() const {
    return this->actionType;
}

int Action::getIndex(){
    return static_cast<int>(this->actionType)
}