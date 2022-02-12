#ifndef SIMPLEHELPER_H
#define SIMPLEHELPER_H
#include <string>

class SimpleHelper
{
    public:
        SimpleHelper();
        virtual ~SimpleHelper();

        std::string GetUserInput(std::string prompt);
        int GetRandomNumber(int maxNum);

    protected:

    private:
};

#endif // SIMPLEHELPER_H
