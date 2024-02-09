#include <iostream>
#include "Character.h"

Character::Character(CharacterName name, int HP) : name(name), HP(HP) {}

CharacterName Character::getName() {
    return name;
}

int Character::getHP() {
    return HP;
}

void Character::print() {
    std::cout << "Name: " << static_cast<int>(name) << std::endl;
    std::cout << "HP: " << HP << std::endl;
}