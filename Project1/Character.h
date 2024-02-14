#include <string>
#include <vector>

#ifndef CHARACTER_H
#define CHARACTER_H

enum class CharacterName {
    BENKEI,
    CHIYOME,
    GINCHIYO,
    GOEMON,
    HANZO,
    HIDEYOSHI,
    IEYASU,
    MUSASHI,
    NOBUNAGA,
    TOMOE,
    USHIWAKA,
    KOJIRO
};

class Character
{
private:
    CharacterName name;
    int HP;

public:
    // Constructor
    Character();
    Character(CharacterName name, int HP);

    // Getters
    CharacterName get_name();
    std::string print_name();
    int getHP();
    void print();
};


extern std::vector<Character> characterVector;


#endif