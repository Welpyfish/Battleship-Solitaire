#ifndef BATTLESHIP_H
#define BATTLESHIP_H

enum E_BATTLE_STATUS { MISS, HIT, KILL };

struct position_t {
  bool isHit;
  int x;
  int y;
};

struct location_t {
    position_t positions[3];
};

class BattleShip
{
    public:
        BattleShip();
        virtual ~BattleShip();

        void SetLocation(location_t location);
        E_BATTLE_STATUS CheckYourself(position_t guess);
        bool m_isDead;

    protected:

    private:
        location_t m_location;
};

#endif // BATTLESHIP_H
