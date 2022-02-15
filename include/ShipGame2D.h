#ifndef SHIPGAME2D_H
#define SHIPGAME2D_H
#include <string>
#include "SimpleHelper.h"
#include "BattleShip.h"

class ShipGame2D
{
    public:
        ShipGame2D(int numOfShips);
        virtual ~ShipGame2D();
        void RunGame();

    protected:
        void SetupMap();
        void SetupShip(int numOfShips);
        location_t GetLocation();

    private:
        SimpleHelper m_helper;
        BattleShip * m_pShips[10];
        int m_maxNumOfShips;
        location_t m_map[8];
        int m_allocatedLocations[10];

};

#endif // SHIPGAME2D_H
