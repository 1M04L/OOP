#include <iostream>
#include "BoolVector.h"
#include "BoolMatrix.h"

int main() {
    BoolVector bv1("101010");
    std::cout << "BoolVector bv1: " << bv1 << std::endl;

    bv1.invertAll();
    std::cout << "Inverted bv1: " << bv1 << std::endl;

    BoolVector bv2(10, true);
    std::cout << "BoolVector bv2: " << bv2 << std::endl;

    BoolVector bv3 = bv1 & bv2;
    std::cout << "bv1 & bv2: " << bv3 << std::endl;

    std::vector<std::string> strMatrix = {
        "101010",
        "110011",
        "111100"
    };
    BoolMatrix bm(strMatrix);
    std::cout << "BoolMatrix: \n" << bm << std::endl;

    std::cout << "Weight of BoolMatrix: " << bm.getWeight() << std::endl;
    std::cout << "Conjunction of BoolMatrix: " << bm.conjunction() << std::endl;

    return 0;
    
    
    
    
    
}
