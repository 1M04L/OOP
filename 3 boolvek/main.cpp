#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include "BoolVector.h"

void PrintVolunteersOrder(int count, const std::vector<int>& excluded = {})
{
    std::vector<int> values(count);
    for (int i = 0; i < values.size(); ++i)
    {
        values[i] = i + 1;
    }
    
    for (int number : excluded)
    {
        auto it = std::find(values.begin(), values.end(), number);
        if (it != values.end())
        {
            values.erase(it);
        }
    }
    
    while (!values.empty())
    {
        int i = rand() % values.size();
        std::cout << values[i] << ' ';
        values.erase(values.begin() + i);
    }
}

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
        //01000010000000
    }
    return 0;
}
