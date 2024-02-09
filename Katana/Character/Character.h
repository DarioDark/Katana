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
    USHIWAKA
};

class Character 
{
    private:
        CharacterName name;
        int HP;

    public:
        // Constructor
        Character(); // Default constructor
        Character(CharacterName name, int HP);

        // Getters
        CharacterName getName();
        int getHP();
        void print();
};

#endif