#include <iostream>
#include "SimpleGame.h"
#include "ShipGame2D.h"

using namespace std;

void PlayGame()
{
    SimpleGame game;
    game.RunGame();
}

void Intro1D()
{
    std::cout << "*********************************" << std::endl;
    std::cout << "* Battleship (1 dimensional)    *" << std::endl;
    std::cout << "*                               *" << std::endl;
    std::cout << "* Goal is to sink the ship by   *" << std::endl;
    std::cout << "* guessing its location         *" << std::endl;
    std::cout << "* (number from 1-7)             *" << std::endl;
    std::cout << "*********************************" << std::endl;
}

void Intro2D()
{
    std::cout << "*********************************" << std::endl;
    std::cout << "* Battleship (2 dimensional)    *" << std::endl;
    std::cout << "*                               *" << std::endl;
    std::cout << "* Goal is to sink the ships by  *" << std::endl;
    std::cout << "* guessing their locations      *" << std::endl;
    std::cout << "* (x, y) from 1-5               *" << std::endl;
    std::cout << "*********************************" << std::endl;
}

void PlayBattleShip()
{
    ShipGame2D game(3);
    game.RunGame();
}

int main()
{
    Intro2D();
    int isPlaying = 1;
    do{
        PlayBattleShip();
        char result;
        std::cout << "\nDo you want to play again?" << std::endl;
        std::cout << "Press y to play again\n" << std::endl;
        std::cin >> result;
        if(result != 'y'){
            isPlaying = 0;
            std::cout << "Game over" << std::endl;
        }
    } while (isPlaying);

    return 0;
}



