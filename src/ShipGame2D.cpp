#include <iostream>
#include <random>
#include "ShipGame2D.h"
#include "BattleShip.h"

ShipGame2D::ShipGame2D(int numOfShips)
{
    //cto
    memset(m_allocatedLocations, -1, sizeof(m_allocatedLocations));
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
    m_map[0].positions[0].x = 1;
    m_map[0].positions[0].y = 1;
    m_map[0].positions[1].x = 2;
    m_map[0].positions[1].y = 1;
    m_map[0].positions[2].x = 3;
    m_map[0].positions[2].y = 1;

    m_map[1].positions[0].x = 1;
    m_map[1].positions[0].y = 1;
    m_map[1].positions[1].x = 2;
    m_map[1].positions[1].y = 1;
    m_map[1].positions[2].x = 3;
    m_map[1].positions[2].y = 1;

}


void ShipGame2D::RunGame()
{
}

location_t ShipGame2D::GetLocation()
{
    int loc = 5; // generate random num of location 0 - 7
    // check m_allocatedLocations[i] == loc
    // set m_allocatedLocations[i] = loc
    return m_map[loc];
}
