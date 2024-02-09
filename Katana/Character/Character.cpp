#include <iostream>
#include <vector> 
#include "Character.h"


std::vector<Character> characters;

Character::Character(CharacterName name, int HP) {
    this->name = name;
    this->HP = HP;
}


CharacterName Character::getName() {
    return name;
}


void Character::print() {
    std::cout << "Name: " << static_cast<int>(name) << std::endl;
    std::cout << "HP: " << HP << std::endl;
}


void setHP() {
    for (int i = 0; i < 12; i++) { 
        if (i <= 4) {
            characters.push_back(Character(static_cast<CharacterName>(i), 4)); 
        } else {
            characters.push_back(Character(static_cast<CharacterName>(i), 5)); 
        }
    }
}
