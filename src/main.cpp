#include <iostream>
#include "SimpleGame.h"

using namespace std;

void PlayGame()
{
    SimpleGame game = SimpleGame();
    game.RunGame();
}

int main()
{
    std::cout << "*********************************" << std::endl;
    std::cout << "* Battleship (1 dimensional)    *" << std::endl;
    std::cout << "*                               *" << std::endl;
    std::cout << "* Goal is to sink the ship by   *" << std::endl;
    std::cout << "* guessing its location         *" << std::endl;
    std::cout << "* (number from 1-7)             *" << std::endl;
    std::cout << "*********************************" << std::endl;
    int isPlaying = 1;
    do{
        PlayGame();
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



