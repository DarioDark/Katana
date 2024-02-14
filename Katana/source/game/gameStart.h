#include <iostream>
#include <string>
#include <vector>



#ifndef GAMESTART_H
#define GAMESTART_H

int getNbrPlayers();
std::vector<std::string> createRoles();
std::vector<Player> createPlayers();
void attributeRoles(std::vector<Player>& players);
void displayPlayerInfos(std::vector<Player> players);
void moveShogunToFirst(std::vector<Player>& players);
void displayPlayerRoles(std::vector<Player>& players);
void distributeCharacter(std::vector<Player>& players);
void gameStartMain();

#endif