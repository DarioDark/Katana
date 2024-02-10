#include "../Card/Card.h"
#include <algorithm>
#include <random>

struct Deck {
    std::vector<Card> cards;
    // Constructor
    Deck();

    // Methods
    void init();
    void initWeaponCards();
    void initActionCards();
    void initPermanentCards();
    void shuffle();
};