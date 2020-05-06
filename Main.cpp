#include "Game.hpp"
#include <iostream>

using namespace std;

int main()
{
    //cout << "testing...\n";
    Game* g = new Game();
    //cout << "Game was created.\n";
    g->playGame();
    return 0;
}