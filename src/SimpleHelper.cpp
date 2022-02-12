#include "SimpleHelper.h"
#include "iostream"

SimpleHelper::SimpleHelper()
{
    //ctor
}

SimpleHelper::~SimpleHelper()
{
    //dtor
}

std::string SimpleHelper::GetUserInput(std::string prompt)
{
    std::string result;
    std::cout << prompt << std::endl;
    std::cin >> result;
    return result;
}

int SimpleHelper::GetRandomNumber(int maxNum)
{
    int result;
    double u;
    srand( unsigned(time(0)));
    for(int i = 0;i< 10 ; i++)
    {
        u=(double)rand()/(RAND_MAX)+1 +(rand()%9);
    }
    result = (int)(u * maxNum / 10);
    return result;
}
