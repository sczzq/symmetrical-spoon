#include <iostream>
#include <string>
#include <vector>

#include "chap7.h"

using namespace std;

int main()
{
    double rate = Chap7::rate;
    int vecSize = Chap7::vecSize;
    vector<double> vec(vecSize) = Chap7::vec;

    std::cout << rate << std::endl;

    return 0;
}

