#include <iostream>
#include <string>
#include "Character.h"

Character::Character() : name(CharacterName::BENKEI), HP(4) {}
Character::Character(CharacterName name, int HP) : name(name), HP(HP) {}

CharacterName Character::get_name() {
    return name;
}

std::string Character::print_name() {
    switch (name) {
        case CharacterName::BENKEI:
            return "Benkei";
        case CharacterName::CHIYOME:
            return "Chiyome";
        case CharacterName::GINCHIYO:
            return "Ginchiyo";
        case CharacterName::GOEMON:
            return "Goemon";
        case CharacterName::HANZO:
            return "Hanzo";
        case CharacterName::HIDEYOSHI:
            return "Hideyoshi";
        case CharacterName::IEYASU:
            return "Ieyasu";
        case CharacterName::MUSASHI:
            return "Musashi";
        case CharacterName::NOBUNAGA:
            return "Nobunaga";
        case CharacterName::TOMOE:
            return "Tomoe";
        case CharacterName::USHIWAKA:
            return "Ushiwaka";
    }
}

int Character::getHP() {
    return HP;
}

void Character::print() {
    std::cout << "Name: " << static_cast<int>(name) << std::endl;
    std::cout << "HP: " << HP << std::endl;
}