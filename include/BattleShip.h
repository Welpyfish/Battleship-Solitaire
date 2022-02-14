#ifndef BATTLESHIP_H
#define BATTLESHIP_H


struct position_t {
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

    protected:

    private:
        location_t m_location;
        bool m_isHit;
};

#endif // BATTLESHIP_H
