// Card.h

#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
    std::string name;

    // Constructeur par défaut
    Card() : name("") {}

    // Constructeur
    Card(std::string cardName);

    std::string getName() const {
        return name;
    }


};


class WeaponCard : public Card {
public:
    int precision;
    int damage;

    WeaponCard(std::string cardName, int precision, int damage);
};

enum class PermanentType {
    FAST_ATTACK,
    BUSHIDO_CODE,
    CONCENTRATION
};

enum class ActionType {
    WAR_CRY,
    DAIMYO,
    DIVERSION,
    GEISHA,
    MEDITATION,
    PARADE,
    CEREMONIE_DU_THE,
    JU_JITSU
};


class Permanent : public Card {
    private :
        PermanentType permanentType;
    public :
        Permanent(PermanentType permanentType);
        PermanentType getPermanentType() const;
        Int getIndex() override;
        
};


class Action : public Card {
    private :
        ActionType actionType;
    public : 
        Action(ActionType actionType);
        ActionType getActionType() const;
        int getIndex() override;

};

#endif
