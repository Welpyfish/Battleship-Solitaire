#include <stdio.h>
#include <string.h>
#include <iostream>
#include <random>
#include "ShipGame2D.h"
#include "BattleShip.h"

ShipGame2D::ShipGame2D(int numOfShips)
{
    //cto
    memset(m_allocatedLocations, 0, sizeof(m_allocatedLocations));
    SetupMap();
    SetupShip(numOfShips);
}

ShipGame2D::~ShipGame2D()
{
    //dtor
    for(int i=0; i<m_maxNumOfShips; i++)
    {
        delete m_pShips[i];
    }
}

void ShipGame2D::SetupShip(int numOfShips)
{
    m_maxNumOfShips = numOfShips;

    for(int i=0; i<m_maxNumOfShips; i++)
    {
        BattleShip *pShip = new BattleShip();

        location_t location = GetLocation();
        pShip->SetLocation(location);

        m_pShips[i] = pShip;
    }
}

void ShipGame2D::SetupMap()
{
    int shipMap[8][3][2] =
    {
    {{1,1},{2,1},{3,1}},
    {{1,2},{2,2},{3,2}},
    {{1,3},{1,4},{1,5}},
    {{2,3},{2,4},{2,5}},
    {{3,4},{4,4},{5,4}},
    {{3,5},{4,5},{5,5}},
    {{4,1},{4,2},{4,3}},
    {{5,1},{5,2},{5,3}}
    };

    for(int i=0; i<8; i++)
    {
        for(int j=0; j<3; j++)
        {
            m_map[i].positions[j].x = shipMap[i][j][0];
            m_map[i].positions[j].y = shipMap[i][j][1];
            m_map[i].positions[j].isHit = false;
        }
    }

}


void ShipGame2D::RunGame()
{
    int numOfGuesses = 0;
    bool gamePlaying = 1;
    while (gamePlaying)
    {
        position_t guess;
        guess.x = std::stoi(m_helper.GetUserInput("Enter an x coord from 1-5"));
        guess.y = std::stoi(m_helper.GetUserInput("Enter a y coord from 1-5"));
        numOfGuesses++;
        bool gameOver = true;
        std::string message = "Miss";
        for(int i=0; i<m_maxNumOfShips; i++)
        {
            if(!m_pShips[i]->m_isDead)
            {
                E_BATTLE_STATUS status = m_pShips[i]->CheckYourself(guess);
                if(status == HIT)
                {gameOver = false;
                    message = "Hit";
                }
                else if(status == KILL)
                {
                    message = "Kill";
                }
            }
            if(!m_pShips[i]->m_isDead)
            {
                gameOver = false;
                break;
            }
        }
        std::cout << message << std::endl;
        if(gameOver)
        {
            gamePlaying = false;
            std::cout << "You win!" << std::endl;
            std::cout << "You took " + std::to_string(numOfGuesses) + " guesses" << std::endl;
            break;
        }
    }
}

location_t ShipGame2D::GetLocation()
{
    bool isPlaced = false;
    int randomNum = 1;
    while(isPlaced == false)
    {
        randomNum = m_helper.GetRandomNumber(8); // generate random num of location 0 - 7
        if(m_allocatedLocations[randomNum] == 0)
        {
        m_allocatedLocations[randomNum] = 1;
        isPlaced = true;
        }
    }
    //std::cout << randomNum << std::endl;
    return m_map[randomNum];
}
