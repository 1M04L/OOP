#pragma once
#include <iostream>
#include <vector>
#include <string>

class BoolVector {
private:
    std::vector<bool> bits;

public:
    BoolVector();
    BoolVector(size_t size, bool value = false);
    BoolVector(const std::string& bitString);
    BoolVector(const BoolVector& other);
    ~BoolVector();

    size_t length() const;
    void invertAll();
    bool bitValue(size_t index) const;
    BoolVector& operator=(const BoolVector& other);
    BoolVector operator&(const BoolVector& other) const;
    BoolVector& operator&=(const BoolVector& other);
    BoolVector operator|(const BoolVector& other) const;
    BoolVector& operator|=(const BoolVector& other);
    bool operator[](int index) const;
    std::_Bit_reference operator[](int index);
    friend std::ostream& operator<<(std::ostream& os, const BoolVector& bv);
    friend std::istream& operator>>(std::istream& is, BoolVector& bv);
};

