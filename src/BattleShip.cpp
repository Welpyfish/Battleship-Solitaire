#include "BattleShip.h"

BattleShip::BattleShip()
{
    //ctor
    m_isHit = false;
}

BattleShip::~BattleShip()
{
    //dtor
}

void BattleShip::SetLocation(location_t location)
{
    m_location = location;
}
