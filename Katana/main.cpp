#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

#include "source/Card/Card.h"
#include "source/Player/Player.h"
#include "source/game/gameStart.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(1252);
    gameStartMain();
    return 0;
}