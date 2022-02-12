#ifndef SIMPLEGAME_H
#define SIMPLEGAME_H
#include <string>
#include "SimpleHelper.h"

class SimpleGame
{
    public:
        SimpleGame();
        virtual ~SimpleGame();

        void RunGame();

    protected:

    private:
        SimpleHelper m_helper;
};

#endif // SIMPLEGAME_H
