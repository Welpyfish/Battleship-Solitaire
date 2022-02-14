#include <iostream>
#include "SimpleShip.h"

SimpleShip::SimpleShip()
{
    //ctor
    m_numOfHits = 0;
}

SimpleShip::~SimpleShip()
{
    //dtor
}

void SimpleShip::SetLocationCells(int * pLocations, int numOfCells)
{
    m_pLocationCells = pLocations;
    m_numOfCells = numOfCells;
}

std::string SimpleShip::CheckYourself(std::string stringGuess)
{
    std::string result = "miss";
    int guess = std::stoi(stringGuess);
    for(int i=0; i< m_numOfCells; i++)
    {
        if (*(m_pLocationCells+i) != -1 && *(m_pLocationCells+i) == guess)
        {
            result = "hit";
            m_numOfHits++;
            *(m_pLocationCells+i) = -1;
            break;
        }
    }

    if(m_numOfHits == m_numOfCells){
        result = "kill";
    }
    std::cout << result << std::endl;
    return result;
}
