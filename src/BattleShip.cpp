#include "BattleShip.h"

BattleShip::BattleShip()
{
    //ctor
    m_isDead = false;
}

BattleShip::~BattleShip()
{
    //dtor
}

void BattleShip::SetLocation(location_t location)
{
    m_location = location;
}

E_BATTLE_STATUS BattleShip::CheckYourself(position_t guess)
{
    E_BATTLE_STATUS result = MISS;
    for(int i=0; i<3; i++)
    {
        if(guess.x == m_location.positions[i].x && guess.y == m_location.positions[i].y)
        {
            if(!m_location.positions[i].isHit)
            {
                m_location.positions[i].isHit = true;
                result = HIT;
            }
            break;
        }
    }
    bool isKill = true;
    for(int i=0; i<3; i++)
    {
        if(!m_location.positions[i].isHit)
        {
            isKill = false;
            break;
        }
    }
    if(isKill)
    {
        result = KILL;
        m_isDead = true;
    }
    return result;
}
