#include <iostream>
#include "SimpleGame.h"
#include "SimpleShip.h"
#include <random>

SimpleGame::SimpleGame()
{

}

SimpleGame::~SimpleGame()
{
    //dtor
}

void SimpleGame::RunGame()
{
    int numOfGuesses = 0;
    SimpleShip ship = SimpleShip();
    int randomNum = m_helper.GetRandomNumber(5);
    int locations[] = {randomNum, randomNum + 1, randomNum + 2};
    ship.SetLocationCells(locations, 3);
    bool isAlive = true;

    while (isAlive){
        std::string guess = m_helper.GetUserInput("Enter a number");
        std::string result = ship.CheckYourself(guess);
        numOfGuesses++;
        if(result == "kill"){
            isAlive = false;
            std::cout << "You took " + std::to_string(numOfGuesses) + " guesses";
            break;
        }
    }
}
