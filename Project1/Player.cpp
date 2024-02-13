#include <iostream>
#include "Player.h"
#include "Character.h"

// Constructor
Player::Player(std::string name)
{
    this->HP = 0;
    this->HonorPoints = 0;
    this->name = name;
    this->additional_difficulty = 0;
    this->additional_weapon = 0;
    this->damage_mitigation = 0;
    this->additional_draw = 0;
    this->additional_damage = 0;
}

// Getters
int Player::get_HP()
{
    return HP;
}

int Player::get_HonorPoints()
{
    return HonorPoints;
}

std::string Player::get_name() const
{
    return name;
}

std::string Player::get_role() const
{
    return role;
}

std::vector<Card> Player::get_hand()
{
    return hand;
}

int Player::get_additional_difficulty()
{
    return additional_difficulty;
}

int Player::get_additional_weapon()
{
    return additional_weapon;
}

int Player::get_damage_mitigation()
{
    return damage_mitigation;
}

int Player::get_additional_draw()
{
    return additional_draw;
}

int Player::get_additional_damage()
{
    return additional_damage;
}

CharacterName Player::get_character()
{
    return this->character.get_name();
}

std::string Player::print_character()
{
    return this->character.print_name();
}

// Setters
void Player::set_role(std::string role)
{
    this->role = role;
}

void Player::set_character(Character character)
{
    this->character = character;
    this->HP = character.getHP();
    CharacterName name = character.get_name();
    switch (name) {
    case CharacterName::BENKEI:
        this->additional_difficulty += 1;
    case CharacterName::GINCHIYO:
        this->damage_mitigation += 1;
    case CharacterName::GOEMON:
        this->additional_weapon += 1;
    case CharacterName::HIDEYOSHI:
        this->additional_draw += 1;
    case CharacterName::MUSASHI:
        this->additional_damage += 1;
    }
}

// Methods
void Player::draw(Deck& deck, int nbr_of_draw)
{
    int usual_draw = 8;
    if (nbr_of_draw == -1) { // Si aucune valeur n'est sp�cifi�e -> c'est une pioche classique de d�but de tour

        for (int i = 0; i < usual_draw + additional_draw; i++) {
            if (deck.cards.size() == 0) {
                std::cout << "Deck is empty" << std::endl;
            }
            else {
                this->hand.push_back(deck.cards.back());
                deck.cards.pop_back();
            }
        }
    }
    else { // Si une valeur est sp�cifi�e -> c'est une pioche avec une carte action, donc un montant sp�cifique
        for (int i = 0; i < nbr_of_draw; i++) {
            this->hand.push_back(deck.cards.back());
            deck.cards.pop_back();
        }
    }
}

Card Player::discard(int cardIndex, std::string list_of_cards) {
    // SI c'est une d�fausse classique -> depuis la main
    if (list_of_cards == "hand") {
        if (cardIndex < 0 || cardIndex >= this->hand.size()) {
            throw std::out_of_range("Card index out of range");
        }
        Card discarded_card = this->hand[cardIndex];
        this->hand.erase(this->hand.begin() + cardIndex);
        return discarded_card;
    }
    // SI c'est une d�fausse de carte permanente -> suite � une carte action
    else {
        if (cardIndex < 0 || cardIndex >= this->hand.size()) {
            throw std::out_of_range("Card index out of range");
        }
        Card discarded_card = this->permanent_card_played[cardIndex];
        this->permanent_card_played.erase(this->permanent_card_played.begin() + cardIndex);
        return discarded_card;
    }
}


void Player::play_permanent_card(int cardIndex)
{
    Card played_card = hand[cardIndex];
    CardName name = played_card.get_name();
    switch (name) {
    case CardName::ARMURE:
        this->additional_difficulty += 1;
    case CardName::CONCENTRATION:
        this->additional_weapon += 1;
    case CardName::ATTAQUE_RAPIDE:
        this->additional_damage += 1;
    default:
        std::cout << "Unknown card" << std::endl;
    }
    this->hand.erase(this->hand.begin() + cardIndex);
    this->permanent_card_played.push_back(played_card);
}

void Player::discard_permanent_card(int cardIndex) 
{
    Card discarded_card = hand[cardIndex];
    CardName name = discarded_card.get_name();
    switch (name) {
    case CardName::ARMURE:
        this->additional_difficulty -= 1;
    case CardName::CONCENTRATION:
        this->additional_weapon -= 1;
    case CardName::ATTAQUE_RAPIDE:
        this->additional_damage -= 1;
    default:
        std::cout << "Unknown card" << std::endl;
    }
    discard(cardIndex, "permanent_card_played"); // On d�fausse depuis les cartes permanentes d�j� jou�es
}

void Player::attack(Player& target, Card card)
{
    // TODO
}

void Player::recover_HP_phase() {
    if (HP < 1) {
        HP = character.getHP();
    }
}

void Player::draw_phase(Deck& deck) {
    draw(deck);
}

int Player::play_card_phase() {
    std::cout << "Voici votre main : " << std::endl;
    print_hand();
    std::cout << "Entrez le num�ro d'une carte pour la jouer, ou rien si vous avez fini / passez votre tour : " << std::endl;
    int response;
    std::cin >> response;
    if (std::cin.fail() || response < 0 || response > hand.size()-1) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore le reste de la ligne
		return -1;
	}
    std::cout << "Vous avez jou� : " << hand[response].print_name() << std::endl;
	return response;
}

std::vector<Card> Player::discard_phase() {
    std::vector<Card> discarded_cards_vector;
    while (hand.size() > 7) {
        int element_index_to_discard;
        std::cout << "Votre main est pleine veuillez d�fausser une carte." << std::endl;
        print_hand();
        std::cout << "Veuillez entrer un nombre entre 0 et " << hand.size() - 1 << " : ";
        std::cin >> element_index_to_discard;
        while (std::cin.fail() || element_index_to_discard > hand.size()-1) {
            std::cout << "Ce n'est pas un nombre valide" << std::endl;
            std::cout << "Veuillez entrer un nombre entre 0 et " << hand.size()-1 << " : ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore le reste de la ligne
            std::cin >> element_index_to_discard;
        }
        discarded_cards_vector.push_back(discard(element_index_to_discard));
    }
    if (discarded_cards_vector.size() > 0) { // Si des cartes ont �t�s d�fauss�es on affiche le r�sum�
        std::cout << "Vous avez d�fauss� : " << std::endl;
        for (Card card : discarded_cards_vector) {
            std::cout << card.print_name() << std::endl;
        }
    }
    return discarded_cards_vector;
}

std::vector<Card> Player::play_turn(Deck& deck) {
    recover_HP_phase();
    draw_phase(deck);
    play_card_phase();
    return discard_phase(); // discarded_cards
}

void Player::print_hand()
{
    for (size_t i = 0; i < hand.size(); ++i) {
        std::cout << i << "." << hand[i].print_name() << std::endl;
    }
}



void Player::displayInfos()
{
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Role: " << this->role << std::endl;
    std::cout << "HP: " << this->HP << std::endl;
    std::cout << "Honor Points: " << this->HonorPoints << std::endl;
    std::cout << "Hand: " << std::endl;
    for (Card card : this->hand)
    {
        std::cout << card.print_name() << std::endl;
    }
    std::cout << "Additional difficulty: " << this->additional_difficulty << std::endl;
    std::cout << "Additional weapon: " << this->additional_weapon << std::endl;
    std::cout << "Damage mitigation: " << this->damage_mitigation << std::endl;
    std::cout << "Additional draw: " << this->additional_draw << std::endl;
    std::cout << "Additional damage: " << this->additional_damage << std::endl;
    std::cout << "Character: " << this->character.print_name() << std::endl;
}





void Player::get_Jujitsued() {
    std::vector<Card> weapon_cards_in_hand;
    for (Card card : hand) {
        if (card.get_type() == CardType::WEAPON) {
            weapon_cards_in_hand.push_back(card);
        }
    }
    std::cout << " vous avez �t� affect� par la carte Jujitsu" << std::endl; // le formatage �trange de la ligne est volontaire
    // SI le joueur a des cartes armes en main
    if (weapon_cards_in_hand.size() > 0) {
        std::cout << "Vous possedez des armes dans votre main :" << std::endl;
        for (size_t i = 0; i < weapon_cards_in_hand.size(); ++i) {
            std::cout << i << "." << weapon_cards_in_hand[i].print_name() << std::endl;
        }
        std::cout << "Vous devez en d�fausser une ou perdre un point de vie." << std::endl;
        std::cout << "Que souhaitez vous faire ? (entrez un index pour d�fausser la carte en question, ou -1 pour perdre un point de vie) : " << std::endl;
        int response;
        std::cin >> response;
        while (std::cin.fail() || response < -1 || response > hand.size()-1) {
            std::cout << "R�ponse invalide" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore le reste de la ligne
            std::cout << "Que souhaitez vous faire ? (entrez un index pour d�fausser la carte en question, ou -1 pour perdre un point de vie) : " << std::endl;
            std::cin >> response;
        }
        if (response == -1) {
            this->HP -= 1;
        }
        else {
            discard(response);
        }
        system("cls");
    }
    // SI le joueur n'a pas de cartes arme en main
    else {
        std::cout << "Vous ne possedez pas de cartes armes, par cons�quent vous �tes forc� de perdre un point de vie" << std::endl;
        this->HP -= 1;
        std::cout << "Press enter to continue...";
        std::cin.get();
        system("cls");
    }
}

/*
void Player::game_phase()
{
    bool play = true;
    while (play && HP > 0) {
        std::cout << "=== Votre tour ===" << std::endl;
        print_hand();
        std::cout << "Choisissez une carte � jouer (entrez l'index de la carte) :";
        int cardIndex;
        std::cin >> cardIndex;
        if (cardIndex < 0 || cardIndex >= hand.size()) {
            std::cout << "Index de la carte invalide, veuillez entrer un index valide" << std::endl;
            continue;
        }
        Card card = hand[cardIndex];
        if (card.get_cost() > HP) {
            std::cout << "Vous n'avez pas assez d'HP pour jouer cette carte, choisissez en une autre" << std::endl;
            continue;
        }
        if (card.is_permanent_card()) {
            play_permanent_card(card.get_permanent_card());
        }
        else {
            // TODO faut impl�menter la fonction attack

        }
        HP -= card.get_HP();
        hand.erase(hand.begin() + cardIndex);
        std::cout << "Carte jou�e " << card.print_name() << std::endl;
    }
    if (HP <= 0) {
        std::cout << "perdu looser bozo" << std::endl;
    }
}
*/