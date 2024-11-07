#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include "BoolVector.h"

int main()
{
    srand(time(0));
    // PrintVolunteersOrder(17, {});
    BoolVector bv(12);
    //BoolVector bv2 = (bv1 + bv3);
    bv.setBitValue(1, true);
    bv.setBitValue(6, true);
    bv[2] = bv[1];
    for (int i = 0 ; i < bv.length(); ++i)
    {
        std::cout << bv[i];
    }
    return 0;
}
