#ifndef SIMPLESHIP_H
#define SIMPLESHIP_H
#include <string>

class SimpleShip
{
    public:
        SimpleShip();
        virtual ~SimpleShip();

        void SetLocationCells(int * pLocations, int numOfLocations);
        std::string CheckYourself(std::string stringGuess);

    protected:

    private:
        int * m_pLocationCells;
        int m_numOfCells;
        int m_numOfHits;
};

#endif // SIMPLESHIP_H
